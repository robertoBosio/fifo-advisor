#pragma once

#include "ap_int.h"
#include "hls_stream.h"
#include <cmath>
#include <vector>
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>

template <typename TAxi, typename TData, typename TDataNumpy>
void hls_stream_to_txt(const std::string &output_path,
                       hls::stream<TAxi> &stream, int data_per_word,
                       const std::vector<size_t> &shape) {
  std::vector<TDataNumpy> output_data;
  size_t bits_per_data = TData::width;
  while (!stream.empty()) {
    TAxi word = stream.read();
    for (int j = 0; j < data_per_word; j++) {
      TData hls_data =
          word.data.range((j + 1) * bits_per_data - 1, j * bits_per_data);
      TDataNumpy quant_data = static_cast<TDataNumpy>(hls_data);
      output_data.push_back(quant_data);
    }
  }

  // Save to .txt file
  std::ofstream file(output_path);
  for (const auto &value : output_data) {
    file << std::to_string(value) << std::endl;
  }
  file.close();
}

template <typename TAxi, typename TData, typename TDataNumpy>
void txt_to_hls_stream(const std::string &input_path, hls::stream<TAxi> &stream,
                       int data_per_word) {
  size_t bits_per_data = TData::width;

  // Load data from .txt file
  std::vector<TDataNumpy> input_data;
  std::ifstream file(input_path);
  TDataNumpy value;

  // Check file opening
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << input_path << std::endl;
    return;
  }

  // Read data from file discarding \n characters
  while (!file.eof()) {
    std::string line;
    std::getline(file, line);
    if (!line.empty()) {
      value = static_cast<TDataNumpy>(std::stod(line));
      input_data.push_back(value); 
    }
  }
  file.close();

  for (int i = 0; i < input_data.size(); i += data_per_word) {
    TAxi word;
    word.data = 0; // Initialize the data field to zero
    for (int j = 0; j < data_per_word; j++) {
      TData hls_data = static_cast<TData>(input_data[i + j]);
      word.data.range((j + 1) * bits_per_data - 1, j * bits_per_data) =
          hls_data;
    }
    word.last = (i + data_per_word >= input_data.size())
                    ? 1
                    : 0; // Set last bit if this is the last word
    word.keep = (1 << data_per_word) - 1; // Set keep bits
    word.strb = (1 << data_per_word) - 1; // Set strb bits
    stream.write(word);
  }
}