#include <hls_stream.h>

const int ARRAY_SIZE = 10000;

void forward(int input[ARRAY_SIZE], int output[ARRAY_SIZE], int num_elements,
             int threshold) {

#pragma HLS DATAFLOW

  // 100 FIFOs: 20 splitters, 40 workers, 40 collectors
  hls::stream<int> split_fifos[20];
  hls::stream<int> work_fifos[40];
  hls::stream<int> collect_fifos[40];
#pragma HLS STREAM variable = split_fifos depth = 2048
#pragma HLS STREAM variable = work_fifos depth = 2048
#pragma HLS STREAM variable = collect_fifos depth = 2048

  // Fork stage - split input based on value
  for (int i = 0; i < num_elements; i++) {
    int val = input[i];
    int route = val % 20;
    split_fifos[route].write(val);
  }

  // Process stage with data-dependent fanout
  // Pre-calculate routing counts to avoid using .empty()
  int splitter_counts[20] = {0};
  for (int i = 0; i < num_elements; i++) {
    int route = input[i] % 20;
    splitter_counts[route]++;
  }

  int worker_counts[40] = {0};
  for (int s = 0; s < 20; s++) {
    // Process exact number of items in this splitter FIFO
    for (int i = 0; i < splitter_counts[s]; i++) {
      int val = split_fifos[s].read();

      if (val > threshold) {
        // High values fan out to multiple workers
        work_fifos[s * 2].write(val);
        work_fifos[s * 2 + 1].write(val / 2);
        worker_counts[s * 2]++;
        worker_counts[s * 2 + 1]++;
      } else {
        // Low values go to single worker
        work_fifos[s * 2].write(val);
        worker_counts[s * 2]++;
      }
    }
  }

  // Work stage
  for (int w = 0; w < 40; w++) {
    // Process exact number of items in this worker FIFO
    for (int i = 0; i < worker_counts[w]; i++) {
      int val = work_fifos[w].read();
      // Simple computation
      val = (val * 3) / 2;
      collect_fifos[w].write(val);
    }
  }

  // Join stage - collect results
  int out_idx = 0;
  for (int c = 0; c < 40; c++) {
    // Collect exact number of results from this collector FIFO
    for (int i = 0; i < worker_counts[c] && out_idx < ARRAY_SIZE; i++) {
      output[out_idx++] = collect_fifos[c].read();
    }
  }
}

#include <cstdlib>

// Testbench
int main() {
  int input1[ARRAY_SIZE], input2[ARRAY_SIZE];
  int output1[ARRAY_SIZE], output2[ARRAY_SIZE];

  // Test 1: Mostly low values - predictable data flow
  for (int i = 0; i < 5000; i++) {
    input1[i] = rand() % 100; // Below threshold
  }

  // Test 2: Burst of high values - creates data expansion
  for (int i = 0; i < 5000; i++) {
    if (i >= 1000 && i < 4000) {
      input2[i] = 1000 + (i % 20) * 100; // High values in specific routes
    } else {
      input2[i] = rand() % 100;
    }
  }

  forward(input1, output1, 5000, 500); // threshold = 500
  forward(input2, output2, 5000, 500);

  // Test 2 creates 2x data in work_fifos, needs larger FIFOs
  return 0;
}