#include <hls_stream.h>

const int INPUT_SIZE = 1000;
const int ARRAY_SIZE = 1000;

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int threshold,
             int num_elements, int &actual_output_count) {
#pragma HLS DATAFLOW

  // 100 FIFOs arranged in a 10x10 grid with cross-connections
  hls::stream<int> fifo[10][10];
#pragma HLS STREAM variable = fifo depth = 2048

  // Track data count per stage to ensure balanced processing
  hls::stream<int> stage_counts[10];
#pragma HLS STREAM variable = stage_counts depth = 10

  // Input stage - write array to streams
  int input_counts[10] = {0};
  for (int iter = 0; iter < num_elements; iter++) {
#pragma HLS PIPELINE II = 1
    int val = input[iter];
    int route = (val % 10);
    fifo[0][route].write(val);
    input_counts[route]++;
  }

  // Write initial counts
  for (int i = 0; i < 10; i++) {
    stage_counts[0].write(input_counts[i]);
  }

  // Processing stages with proper data tracking
  for (int stage = 1; stage < 9; stage++) {
    int next_counts[10] = {0};

    // Read expected counts for this stage
    int expected_counts[10];
    for (int i = 0; i < 10; i++) {
      expected_counts[i] = stage_counts[stage - 1].read();
    }

    // Process all data in this stage
    for (int lane = 0; lane < 10; lane++) {
      for (int cnt = 0; cnt < expected_counts[lane]; cnt++) {
        if (!fifo[stage - 1][lane].empty()) {
          int data = fifo[stage - 1][lane].read();

          if (data > threshold * stage) {
            // Only forward to next lane (remove cross-connection to avoid
            // amplification)
            int next_lane = (lane + 1) % 10;
            fifo[stage][next_lane].write(data);
            next_counts[next_lane]++;
          } else {
            // Forward to same lane without multiplication to avoid data growth
            fifo[stage][lane].write(data);
            next_counts[lane]++;
          }
        }
      }
    }

    // Write counts for next stage
    for (int i = 0; i < 10; i++) {
      stage_counts[stage].write(next_counts[i]);
    }
  }

  // Output stage: Collect all results
  int out_idx = 0;

  // Read final stage counts
  int final_counts[10];
  for (int i = 0; i < 10; i++) {
    final_counts[i] = stage_counts[8].read();
  }

  // Collect exactly the amount of data present
  for (int lane = 0; lane < 10; lane++) {
    for (int cnt = 0; cnt < final_counts[lane]; cnt++) {
      if (!fifo[8][lane].empty() && out_idx < ARRAY_SIZE) {
        output[out_idx++] = fifo[8][lane].read();
      }
    }
  }

  actual_output_count = out_idx;

  // Fill remaining output with zeros
  for (int i = out_idx; i < ARRAY_SIZE; i++) {
    output[i] = 0;
  }
}

// Updated testbench
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
      data[i] = burst_value + (burst_lane * 10);
    } else {
      data[i] = rand() % 100;
    }
  }
}

int main() {
  int input1[ARRAY_SIZE], input2[ARRAY_SIZE];
  int output1[ARRAY_SIZE], output2[ARRAY_SIZE];
  int output_count1, output_count2;

  generate_uniform_data(input1, 500, 0, 1000);
  generate_burst_data(input2, 500, 800, 5);

  std::cout << "Test 1: Uniform input with threshold=100\n";
  forward(input1, output1, 100, 500, output_count1);
  std::cout << "Output count: " << output_count1 << "\n";

  std::cout << "Test 2: Burst input with threshold=50\n";
  forward(input2, output2, 50, 500, output_count2);
  std::cout << "Output count: " << output_count2 << "\n";

  return 0;
}