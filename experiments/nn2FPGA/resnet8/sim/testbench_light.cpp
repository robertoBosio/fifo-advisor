#include "ap_int.h"
#include "hls_stream.h"
#include <array>

extern void resnet8(
    std::array<std::array<ap_int<8>, 1>, 1> in_data[3072],
    std::array<std::array<ap_int<8>, 2>, 1> out_data[6],
    ap_int<8> node_StreamingConv_0_weights[48][1][9],
    ap_int<16> node_StreamingConv_0_biases[16][1][1],
    ap_int<8> node_StreamingConv_2_weights[128][2][9],
    ap_int<16> node_StreamingConv_2_biases[8][2][1],
    ap_int<8> node_StreamingConv_4_weights[128][2][9],
    ap_int<16> node_StreamingConv_4_biases[16][1][1],
    ap_int<8> node_StreamingConv_8_weights[512][1][1],
    ap_int<16> node_StreamingConv_8_biases[32][1][1],
    ap_int<8> node_StreamingConv_7_weights[512][1][9],
    ap_int<16> node_StreamingConv_7_biases[32][1][1],
    ap_int<8> node_StreamingConv_10_weights[512][2][9],
    ap_int<16> node_StreamingConv_10_biases[32][1][1],
    ap_int<8> node_StreamingConv_14_weights[2048][1][1],
    ap_int<16> node_StreamingConv_14_biases[64][1][1],
    ap_int<8> node_StreamingConv_13_weights[1024][2][9],
    ap_int<16> node_StreamingConv_13_biases[32][2][1],
    ap_int<8> node_StreamingConv_16_weights[2048][2][9],
    ap_int<16> node_StreamingConv_16_biases[64][1][1],
    ap_int<8> node_StreamingConv_20_weights[320][2][1],
    ap_int<16> node_StreamingConv_20_biases[5][2][1]
);

int main(int argc, char** argv)
{
    std::array<std::array<ap_int<8>, 1>, 1> in_data[3072];
    std::array<std::array<ap_int<8>, 2>, 1> out_data[6];
    ap_int<8> node_StreamingConv_0_weights[48][1][9];
    ap_int<16> node_StreamingConv_0_biases[16][1][1];
    ap_int<8> node_StreamingConv_2_weights[128][2][9];
    ap_int<16> node_StreamingConv_2_biases[8][2][1];
    ap_int<8> node_StreamingConv_4_weights[128][2][9];
    ap_int<16> node_StreamingConv_4_biases[16][1][1];
    ap_int<8> node_StreamingConv_8_weights[512][1][1];
    ap_int<16> node_StreamingConv_8_biases[32][1][1];
    ap_int<8> node_StreamingConv_7_weights[512][1][9];
    ap_int<16> node_StreamingConv_7_biases[32][1][1];
    ap_int<8> node_StreamingConv_10_weights[512][2][9];
    ap_int<16> node_StreamingConv_10_biases[32][1][1];
    ap_int<8> node_StreamingConv_14_weights[2048][1][1];
    ap_int<16> node_StreamingConv_14_biases[64][1][1];
    ap_int<8> node_StreamingConv_13_weights[1024][2][9];
    ap_int<16> node_StreamingConv_13_biases[32][2][1];
    ap_int<8> node_StreamingConv_16_weights[2048][2][9];
    ap_int<16> node_StreamingConv_16_biases[64][1][1];
    ap_int<8> node_StreamingConv_20_weights[320][2][1];
    ap_int<16> node_StreamingConv_20_biases[5][2][1];

    resnet8(in_data, out_data, node_StreamingConv_0_weights, node_StreamingConv_0_biases, node_StreamingConv_2_weights, node_StreamingConv_2_biases, node_StreamingConv_4_weights, node_StreamingConv_4_biases, node_StreamingConv_8_weights, node_StreamingConv_8_biases, node_StreamingConv_7_weights, node_StreamingConv_7_biases, node_StreamingConv_10_weights, node_StreamingConv_10_biases, node_StreamingConv_14_weights, node_StreamingConv_14_biases, node_StreamingConv_13_weights, node_StreamingConv_13_biases, node_StreamingConv_16_weights, node_StreamingConv_16_biases, node_StreamingConv_20_weights, node_StreamingConv_20_biases);
    return 0;
}
