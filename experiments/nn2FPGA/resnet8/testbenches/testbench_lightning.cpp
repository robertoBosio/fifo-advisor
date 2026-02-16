#include "ap_int.h"
#include "hls_stream.h"
#include <array>

extern void resnet8(
    std::array<std::array<ap_int<8>, 3>, 4> in_data[256],
    std::array<std::array<ap_int<8>, 2>, 1> out_data[6],
    ap_int<8> StreamingConv_0_weights[48][1][9],
    ap_int<16> StreamingConv_0_biases[16][1][1],
    ap_int<8> StreamingConv_1_weights[64][4][9],
    ap_int<16> StreamingConv_1_biases[4][4][1],
    ap_int<8> StreamingConv_2_weights[64][4][9],
    ap_int<16> StreamingConv_2_biases[16][1][1],
    ap_int<8> StreamingConv_4_weights[256][2][1],
    ap_int<16> StreamingConv_4_biases[16][2][1],
    ap_int<8> StreamingConv_3_weights[256][2][9],
    ap_int<16> StreamingConv_3_biases[16][2][1],
    ap_int<8> StreamingConv_5_weights[256][4][9],
    ap_int<16> StreamingConv_5_biases[16][2][1],
    ap_int<8> StreamingConv_7_weights[512][4][1],
    ap_int<16> StreamingConv_7_biases[32][2][1],
    ap_int<8> StreamingConv_6_weights[512][4][9],
    ap_int<16> StreamingConv_6_biases[32][2][1],
    ap_int<8> StreamingConv_8_weights[1024][4][9],
    ap_int<16> StreamingConv_8_biases[32][2][1],
    ap_int<8> StreamingConv_9_weights[160][4][1],
    ap_int<16> StreamingConv_9_biases[5][2][1]
);

int main(int argc, char** argv)
{
    std::array<std::array<ap_int<8>, 3>, 4> in_data[256];
    std::array<std::array<ap_int<8>, 2>, 1> out_data[6];
    ap_int<8> StreamingConv_0_weights[48][1][9];
    ap_int<16> StreamingConv_0_biases[16][1][1];
    ap_int<8> StreamingConv_1_weights[64][4][9];
    ap_int<16> StreamingConv_1_biases[4][4][1];
    ap_int<8> StreamingConv_2_weights[64][4][9];
    ap_int<16> StreamingConv_2_biases[16][1][1];
    ap_int<8> StreamingConv_4_weights[256][2][1];
    ap_int<16> StreamingConv_4_biases[16][2][1];
    ap_int<8> StreamingConv_3_weights[256][2][9];
    ap_int<16> StreamingConv_3_biases[16][2][1];
    ap_int<8> StreamingConv_5_weights[256][4][9];
    ap_int<16> StreamingConv_5_biases[16][2][1];
    ap_int<8> StreamingConv_7_weights[512][4][1];
    ap_int<16> StreamingConv_7_biases[32][2][1];
    ap_int<8> StreamingConv_6_weights[512][4][9];
    ap_int<16> StreamingConv_6_biases[32][2][1];
    ap_int<8> StreamingConv_8_weights[1024][4][9];
    ap_int<16> StreamingConv_8_biases[32][2][1];
    ap_int<8> StreamingConv_9_weights[160][4][1];
    ap_int<16> StreamingConv_9_biases[5][2][1];

    resnet8(in_data, out_data, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_9_weights, StreamingConv_9_biases);
    return 0;
}
