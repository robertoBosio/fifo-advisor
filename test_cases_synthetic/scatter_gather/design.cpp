#include <hls_stream.h>

const int ARRAY_SIZE = 10000;

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int num_elements,
             int aggregate_threshold) {
#pragma HLS INTERFACE ap_memory port = input
#pragma HLS INTERFACE ap_memory port = output
#pragma HLS INTERFACE s_axilite port = num_elements
#pragma HLS INTERFACE s_axilite port = aggregate_threshold
#pragma HLS INTERFACE s_axilite port = return

  // 96 FIFOs: 16 scatter, 64 process, 16 gather
  hls::stream<int> scatter_fifos[16];
  hls::stream<int> process_fifos[64];
  hls::stream<int> gather_fifos[16];
#pragma HLS STREAM variable = scatter_fifos depth = 2048
#pragma HLS STREAM variable = process_fifos depth = 2048
#pragma HLS STREAM variable = gather_fifos depth = 2048

  // Scatter phase
  for (int i = 0; i < num_elements; i++) {
    int val = input[i];
    int target = (val / 256) % 16;
    scatter_fifos[target].write(val);
  }

  // Process with conditional aggregation
  for (int iter = 0; iter < num_elements; iter++) {
    for (int s = 0; s < 16; s++) {
      if (!scatter_fifos[s].empty()) {
        int val = scatter_fifos[s].read();

        if (val > aggregate_threshold) {
          // Scatter to multiple processors
          for (int p = 0; p < 4; p++) {
            process_fifos[s * 4 + p].write(val / 4);
          }
        } else {
          // Single processor
          process_fifos[s * 4].write(val);
        }
      }
    }
  }

  // Process
  for (int iter = 0; iter < num_elements * 4; iter++) {
    for (int p = 0; p < 64; p++) {
      if (!process_fifos[p].empty()) {
        int val = process_fifos[p].read();
        val = val * 2; // Simple processing
        gather_fifos[p / 4].write(val);
      }
    }
  }

  // Gather
  int out_idx = 0;
  for (int iter = 0; iter < num_elements * 4 && out_idx < ARRAY_SIZE; iter++) {
    for (int g = 0; g < 16; g++) {
      if (!gather_fifos[g].empty() && out_idx < ARRAY_SIZE) {
        output[out_idx++] = gather_fifos[g].read();
      }
    }
  }
}

// Testbench
int main() {
  int input1[ARRAY_SIZE], input2[ARRAY_SIZE];
  int output1[ARRAY_SIZE], output2[ARRAY_SIZE];

  // Test 1: Below threshold - no aggregation
  for (int i = 0; i < 5000; i++) {
    input1[i] = rand() % 500;
  }

  // Test 2: Burst of high values - creates 4x data expansion
  for (int i = 0; i < 5000; i++) {
    if (i >= 2000 && i < 3000) {
      input2[i] = 2000 + (i % 16) * 256; // High values per scatter channel
    } else {
      input2[i] = rand() % 500;
    }
  }

  forward(input1, output1, 5000, 1000);
  forward(input2, output2, 5000, 1000);

  // Test 2 creates 4x expansion in process_fifos
  return 0;
}