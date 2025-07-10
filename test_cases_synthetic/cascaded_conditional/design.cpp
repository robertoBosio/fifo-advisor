#include <hls_stream.h>

const int INPUT_SIZE = 1000;
const int ARRAY_SIZE = 1000;

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int threshold,
             int num_elements) {

  // 100 FIFOs arranged in a 10x10 grid with cross-connections
  hls::stream<int> fifo[10][10];
#pragma HLS STREAM variable = fifo depth = 2048

  // Input stage - write array to streams
  for (int iter = 0; iter < num_elements; iter++) {
#pragma HLS PIPELINE II = 1
    int val = input[iter];

    // Stage 1: Initial distribution based on value properties
    int route = (val % 10);
    fifo[0][route].write(val);
  }

  // Processing stages
  for (int proc_iter = 0; proc_iter < num_elements; proc_iter++) {
    // Stages 2-9: Conditional processing with cross-connections
    for (int stage = 1; stage < 9; stage++) {
      for (int lane = 0; lane < 10; lane++) {
        if (!fifo[stage - 1][lane].empty()) {
          int data = fifo[stage - 1][lane].read();

          // Data-dependent routing decision
          if (data > threshold * stage) {
            // Cross-connection to adjacent lanes
            fifo[stage][(lane + 1) % 10].write(data);
            if (lane > 0 && stage < 8) {
              fifo[stage][lane - 1].write(data / 2);
            }
          } else {
            // Forward to same lane
            fifo[stage][lane].write(data * 2);
          }
        }
      }
    }
  }

  // Output stage: Collect results
  int out_idx = 0;
  for (int collect = 0; collect < num_elements * 2; collect++) {
    for (int lane = 0; lane < 10; lane++) {
      if (!fifo[8][lane].empty() && out_idx < ARRAY_SIZE) {
        output[out_idx++] = fifo[8][lane].read();
      }
    }
  }
}

// Testbench
#include <cstdlib>
#include <iostream>

void generate_uniform_data(int data[ARRAY_SIZE], int size, int min_val,
                           int max_val) {
  for (int i = 0; i < size; i++) {
    data[i] = min_val + (rand() % (max_val - min_val + 1));
  }
}

void generate_burst_data(int data[ARRAY_SIZE], int size, int burst_value,
                         int burst_lane) {
  for (int i = 0; i < size; i++) {
    if (i >= size / 3 && i < 2 * size / 3) {
      // Create burst in specific lane
      data[i] = burst_value + (burst_lane * 10);
    } else {
      data[i] = rand() % 100;
    }
  }
}

int main() {
  int input1[ARRAY_SIZE], input2[ARRAY_SIZE];
  int output1[ARRAY_SIZE], output2[ARRAY_SIZE];

  // Test case 1: Uniform distribution - works with small FIFOs
  generate_uniform_data(input1, 500, 0, 1000);

  // Test case 2: Burst pattern - creates congestion in specific lanes
  // This will deadlock with small FIFOs due to cross-connections
  generate_burst_data(input2, 500, 800, 5); // High values in lane 5

  std::cout << "Test 1: Uniform input with threshold=100\n";
  forward(input1, output1, 100, 500);

  std::cout << "Test 2: Burst input with threshold=50\n";
  // Lower threshold causes more cross-connections, potential deadlock
  forward(input2, output2, 50, 500);

  // With FIFO depth < 1024: Test 2 deadlocks due to burst + cross-connections
  // With FIFO depth > 2048: Both tests complete

  return 0;
}