#include <cstdlib>
#include <hls_stream.h>

const int ARRAY_SIZE = 10000;

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int num_elements,
             int bypass_threshold) {
#pragma HLS INTERFACE ap_memory port = input
#pragma HLS INTERFACE ap_memory port = output
#pragma HLS INTERFACE s_axilite port = num_elements
#pragma HLS INTERFACE s_axilite port = bypass_threshold
#pragma HLS INTERFACE s_axilite port = return

  // 100 FIFOs: 50 ring nodes, 50 bypass channels
  hls::stream<int> ring_fifos[50];
  hls::stream<int> bypass_fifos[50];
#pragma HLS STREAM variable = ring_fifos depth = 2048
#pragma HLS STREAM variable = bypass_fifos depth = 2048

  // Inject into ring
  for (int i = 0; i < num_elements; i++) {
    int val = input[i];
    int node = i % 50;
    ring_fifos[node].write(val);
  }

  // Ring processing
  int output_count = 0;
  for (int iter = 0; iter < num_elements * 10 && output_count < num_elements;
       iter++) {
    for (int node = 0; node < 50; node++) {
      if (!ring_fifos[node].empty()) {
        int val = ring_fifos[node].read();

        if (val < bypass_threshold) {
          // Bypass ring - go directly to output
          bypass_fifos[node].write(val);
        } else {
          // Continue in ring
          val = val - bypass_threshold / 10;
          int next_node = (node + 1) % 50;

          // May create congestion at next node
          ring_fifos[next_node].write(val);
        }
      }
    }

    // Collect bypassed values
    for (int node = 0; node < 50; node++) {
      if (!bypass_fifos[node].empty() && output_count < ARRAY_SIZE) {
        output[output_count++] = bypass_fifos[node].read();
      }
    }
  }
}

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

  forward(input1, output1, 5000, 1000);
  forward(input2, output2, 5000, 1000);

  // Test 2 creates congestion as values circle the ring
  return 0;
}