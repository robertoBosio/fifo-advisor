#include <hls_stream.h>

const int ARRAY_SIZE = 10000;
const int NUM_NODES = 50;
const int MAX_ITERATIONS = 200;

// Input distribution process
void input_distributor(int input[ARRAY_SIZE], int num_elements,
                       hls::stream<int> &distributed_stream) {
  for (int i = 0; i < num_elements; i++) {
    // Pack node ID and value into single int
    int node_id = i % NUM_NODES;
    int packed_data = (node_id << 16) | (input[i] & 0xFFFF);
    distributed_stream.write(packed_data);
  }
  // Send termination marker
  distributed_stream.write(-1);
}

// Ring processor - simulates ring behavior in a single process
void ring_processor(hls::stream<int> &input_stream,
                    hls::stream<int> &output_stream, int bypass_threshold) {

  // Node states - each node can hold one value
  int node_states[NUM_NODES];
  bool node_occupied[NUM_NODES];
  int node_iterations[NUM_NODES];

  // Initialize nodes
  for (int i = 0; i < NUM_NODES; i++) {
#pragma HLS UNROLL
    node_states[i] = 0;
    node_occupied[i] = false;
    node_iterations[i] = 0;
  }

  bool input_done = false;
  int total_iterations = 0;

  while (total_iterations < MAX_ITERATIONS * NUM_NODES && !input_done) {
#pragma HLS PIPELINE II = 1

    // Try to read new input
    if (!input_stream.empty()) {
      int packed_data = input_stream.read();

      if (packed_data == -1) {
        input_done = true;
      } else {
        // Unpack data
        int node_id = (packed_data >> 16) & 0xFFFF;
        int value = packed_data & 0xFFFF;

        // If target node is free, place value there
        if (!node_occupied[node_id]) {
          node_states[node_id] = value;
          node_occupied[node_id] = true;
          node_iterations[node_id] = 0;
        }
      }
    }

    // Process all nodes in parallel
    for (int node = 0; node < NUM_NODES; node++) {
#pragma HLS UNROLL

      if (node_occupied[node]) {
        int val = node_states[node];

        if (val < bypass_threshold) {
          // Bypass - send to output
          output_stream.write(val);
          node_occupied[node] = false;
        } else {
          // Continue in ring
          val = val - bypass_threshold / 10;
          node_iterations[node]++;

          if (val <= 0 || node_iterations[node] >= MAX_ITERATIONS) {
            // Force bypass after max iterations or zero value
            output_stream.write(val);
            node_occupied[node] = false;
          } else {
            // Try to move to next node
            int next_node = (node + 1) % NUM_NODES;

            if (!node_occupied[next_node]) {
              // Move to next node
              node_states[next_node] = val;
              node_occupied[next_node] = true;
              node_iterations[next_node] = node_iterations[node];
              node_occupied[node] = false;
            }
            // If next node is occupied, stay in current node
            else {
              node_states[node] = val;
            }
          }
        }
      }
    }

    total_iterations++;
  }

  // Flush remaining values
  for (int node = 0; node < NUM_NODES; node++) {
    if (node_occupied[node]) {
      output_stream.write(node_states[node]);
    }
  }

  // Send termination marker
  output_stream.write(-1);
}

// Output collector process
void output_collector(hls::stream<int> &processed_stream,
                      int output[ARRAY_SIZE]) {
  int output_count = 0;

  while (output_count < ARRAY_SIZE) {
    if (!processed_stream.empty()) {
      int val = processed_stream.read();

      if (val == -1) {
        break; // Termination marker
      }

      if (output_count < ARRAY_SIZE) {
        output[output_count++] = val;
      }
    }
  }

  // Fill remaining output with zeros
  for (int i = output_count; i < ARRAY_SIZE; i++) {
    output[i] = 0;
  }
}

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int num_elements,
             int bypass_threshold) {
#pragma HLS DATAFLOW

  // Only two streams - each with exactly one producer and one consumer
  hls::stream<int> distributed_stream;
  hls::stream<int> processed_stream;

#pragma HLS STREAM variable = distributed_stream depth = 1024
#pragma HLS STREAM variable = processed_stream depth = 1024

  // Three-stage pipeline with proper dataflow
  input_distributor(input, num_elements, distributed_stream);
  ring_processor(distributed_stream, processed_stream, bypass_threshold);
  output_collector(processed_stream, output);
}

// // Alternative even simpler version for better performance
// void forward_simple(int input[ARRAY_SIZE], int output[ARRAY_SIZE],
//                    int num_elements, int bypass_threshold) {
// #pragma HLS DATAFLOW

//     hls::stream<int> stage1_stream;
//     hls::stream<int> stage2_stream;

// #pragma HLS STREAM variable=stage1_stream depth=512
// #pragma HLS STREAM variable=stage2_stream depth=512

//     // Stage 1: Input processing with node assignment
//     input_stage: {
//         for (int i = 0; i < num_elements; i++) {
// #pragma HLS PIPELINE II=1
//             int node_id = i % NUM_NODES;
//             int packed = (node_id << 16) | (input[i] & 0xFFFF);
//             stage1_stream.write(packed);
//         }
//         stage1_stream.write(-1); // Termination
//     }

//     // Stage 2: Ring processing simulation
//     process_stage: {
//         int processed_count = 0;

//         while (processed_count < num_elements) {
// #pragma HLS PIPELINE II=1

//             if (!stage1_stream.empty()) {
//                 int packed = stage1_stream.read();

//                 if (packed == -1) break;

//                 int node_id = (packed >> 16) & 0xFFFF;
//                 int value = packed & 0xFFFF;

//                 // Simulate ring processing
//                 if (value >= bypass_threshold) {
//                     // Simulate multiple ring iterations
//                     for (int iter = 0; iter < (node_id % 5) + 1; iter++) {
//                         value = value - bypass_threshold / 10;
//                         if (value < bypass_threshold) break;
//                     }
//                 }

//                 stage2_stream.write(value);
//                 processed_count++;
//             }
//         }
//         stage2_stream.write(-1); // Termination
//     }

//     // Stage 3: Output collection
//     output_stage: {
//         int output_count = 0;

//         while (output_count < ARRAY_SIZE) {
// #pragma HLS PIPELINE II=1

//             if (!stage2_stream.empty()) {
//                 int val = stage2_stream.read();

//                 if (val == -1) break;

//                 if (output_count < num_elements) {
//                     output[output_count] = val;
//                 }
//                 output_count++;
//             }
//         }

//         // Clear remaining output
//         for (int i = output_count; i < ARRAY_SIZE; i++) {
//             output[i] = 0;
//         }
//     }
// }

#include <cstdlib>
#include <iostream>

// Testbench
int main() {
  int input1[ARRAY_SIZE], input2[ARRAY_SIZE];
  int output1[ARRAY_SIZE], output2[ARRAY_SIZE];

  // Test 1: Mixed values - balanced ring usage
  for (int i = 0; i < 5000; i++) {
    input1[i] = rand() % 2000;
  }

  // Test 2: High values in sequential nodes - creates congestion
  for (int i = 0; i < 5000; i++) {
    if (i >= 1000 && i < 2000) {
      // Inject high values in nodes 0-19
      input2[i] = 5000 + (i % 20) * 100;
    } else {
      input2[i] = rand() % 500;
    }
  }

  std::cout << "Running forward function..." << std::endl;
  forward(input1, output1, 5000, 1000);
  forward(input2, output2, 5000, 1000);

  // std::cout << "Running simple forward function..." << std::endl;
  // forward_simple(input1, output1, 5000, 1000);
  // forward_simple(input2, output2, 5000, 1000);

  std::cout << "Tests completed successfully!" << std::endl;
  return 0;
}