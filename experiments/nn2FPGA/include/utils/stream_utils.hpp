#pragma once
#include "hls_stream.h"
#include "ap_int.h"
#include <array>
#include <cstddef>

template <typename T, size_t CH_PAR, size_t W_PAR, size_t DEPTH>
void mm2s(std::array<std::array<T, CH_PAR>, W_PAR> in_data[DEPTH],
          hls::stream<std::array<T, CH_PAR>> out_stream[W_PAR]) {
  for (size_t d = 0; d < DEPTH; d++) {
    for (size_t w = 0; w < W_PAR; w++) {
      out_stream[w].write(in_data[d][w]);
    }
  }
}

template <typename T, size_t CH_PAR, size_t W_PAR, size_t DEPTH>
void s2mm(hls::stream<std::array<T, CH_PAR>> in_stream[W_PAR],
          std::array<std::array<T, CH_PAR>, W_PAR> out_data[DEPTH]) {
  for (size_t d = 0; d < DEPTH; d++) {
    for (size_t w = 0; w < W_PAR; w++) {
      out_data[d][w] = in_stream[w].read();
    }
  }
}
