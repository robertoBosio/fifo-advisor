#include "ap_int.h"
#include "hls_stream.h"
#include <array>

extern void resnet20(
    std::array<std::array<ap_int<8>, 1>, 1> in_data[3072],
    std::array<std::array<ap_int<8>, 1>, 1> out_data[10],
    ap_int<8> StreamingConv_0_weights[48][1][9],
    ap_int<14> StreamingConv_0_biases[16][1][1],
    ap_int<8> StreamingConv_1_weights[128][2][9],
    ap_int<16> StreamingConv_1_biases[8][2][1],
    ap_int<8> StreamingConv_2_weights[128][2][9],
    ap_int<15> StreamingConv_2_biases[16][1][1],
    ap_int<8> StreamingConv_3_weights[128][2][9],
    ap_int<15> StreamingConv_3_biases[8][2][1],
    ap_int<8> StreamingConv_4_weights[128][2][9],
    ap_int<14> StreamingConv_4_biases[16][1][1],
    ap_int<8> StreamingConv_5_weights[128][2][9],
    ap_int<15> StreamingConv_5_biases[8][2][1],
    ap_int<8> StreamingConv_6_weights[128][2][9],
    ap_int<13> StreamingConv_6_biases[16][1][1],
    ap_int<8> StreamingConv_8_weights[256][2][1],
    ap_int<13> StreamingConv_8_biases[16][2][1],
    ap_int<8> StreamingConv_7_weights[512][1][9],
    ap_int<17> StreamingConv_7_biases[32][1][1],
    ap_int<8> StreamingConv_9_weights[512][2][9],
    ap_int<15> StreamingConv_9_biases[16][2][1],
    ap_int<8> StreamingConv_10_weights[512][2][9],
    ap_int<16> StreamingConv_10_biases[32][1][1],
    ap_int<8> StreamingConv_11_weights[512][2][9],
    ap_int<15> StreamingConv_11_biases[16][2][1],
    ap_int<8> StreamingConv_12_weights[512][2][9],
    ap_int<16> StreamingConv_12_biases[32][1][1],
    ap_int<8> StreamingConv_13_weights[512][2][9],
    ap_int<14> StreamingConv_13_biases[16][2][1],
    ap_int<8> StreamingConv_15_weights[1024][2][1],
    ap_int<14> StreamingConv_15_biases[64][1][1],
    ap_int<8> StreamingConv_14_weights[512][4][9],
    ap_int<16> StreamingConv_14_biases[32][2][1],
    ap_int<8> StreamingConv_16_weights[2048][2][9],
    ap_int<15> StreamingConv_16_biases[64][1][1],
    ap_int<8> StreamingConv_17_weights[1024][4][9],
    ap_int<15> StreamingConv_17_biases[16][4][1],
    ap_int<8> StreamingConv_18_weights[1024][4][9],
    ap_int<15> StreamingConv_18_biases[64][1][1],
    ap_int<8> StreamingConv_19_weights[1024][4][9],
    ap_int<15> StreamingConv_19_biases[16][4][1],
    ap_int<8> StreamingConv_20_weights[1024][4][9],
    ap_int<15> StreamingConv_20_biases[64][1][1],
    ap_int<8> StreamingConv_21_weights[640][1][1],
    ap_int<2> StreamingConv_21_biases[10][1][1]
);

int main(int argc, char** argv)
{
    std::array<std::array<ap_int<8>, 1>, 1> in_data[3072];
    std::array<std::array<ap_int<8>, 1>, 1> out_data[10];
    ap_int<8> StreamingConv_0_weights[48][1][9];
    ap_int<14> StreamingConv_0_biases[16][1][1];
    ap_int<8> StreamingConv_1_weights[128][2][9];
    ap_int<16> StreamingConv_1_biases[8][2][1];
    ap_int<8> StreamingConv_2_weights[128][2][9];
    ap_int<15> StreamingConv_2_biases[16][1][1];
    ap_int<8> StreamingConv_3_weights[128][2][9];
    ap_int<15> StreamingConv_3_biases[8][2][1];
    ap_int<8> StreamingConv_4_weights[128][2][9];
    ap_int<14> StreamingConv_4_biases[16][1][1];
    ap_int<8> StreamingConv_5_weights[128][2][9];
    ap_int<15> StreamingConv_5_biases[8][2][1];
    ap_int<8> StreamingConv_6_weights[128][2][9];
    ap_int<13> StreamingConv_6_biases[16][1][1];
    ap_int<8> StreamingConv_8_weights[256][2][1];
    ap_int<13> StreamingConv_8_biases[16][2][1];
    ap_int<8> StreamingConv_7_weights[512][1][9];
    ap_int<17> StreamingConv_7_biases[32][1][1];
    ap_int<8> StreamingConv_9_weights[512][2][9];
    ap_int<15> StreamingConv_9_biases[16][2][1];
    ap_int<8> StreamingConv_10_weights[512][2][9];
    ap_int<16> StreamingConv_10_biases[32][1][1];
    ap_int<8> StreamingConv_11_weights[512][2][9];
    ap_int<15> StreamingConv_11_biases[16][2][1];
    ap_int<8> StreamingConv_12_weights[512][2][9];
    ap_int<16> StreamingConv_12_biases[32][1][1];
    ap_int<8> StreamingConv_13_weights[512][2][9];
    ap_int<14> StreamingConv_13_biases[16][2][1];
    ap_int<8> StreamingConv_15_weights[1024][2][1];
    ap_int<14> StreamingConv_15_biases[64][1][1];
    ap_int<8> StreamingConv_14_weights[512][4][9];
    ap_int<16> StreamingConv_14_biases[32][2][1];
    ap_int<8> StreamingConv_16_weights[2048][2][9];
    ap_int<15> StreamingConv_16_biases[64][1][1];
    ap_int<8> StreamingConv_17_weights[1024][4][9];
    ap_int<15> StreamingConv_17_biases[16][4][1];
    ap_int<8> StreamingConv_18_weights[1024][4][9];
    ap_int<15> StreamingConv_18_biases[64][1][1];
    ap_int<8> StreamingConv_19_weights[1024][4][9];
    ap_int<15> StreamingConv_19_biases[16][4][1];
    ap_int<8> StreamingConv_20_weights[1024][4][9];
    ap_int<15> StreamingConv_20_biases[64][1][1];
    ap_int<8> StreamingConv_21_weights[640][1][1];
    ap_int<2> StreamingConv_21_biases[10][1][1];

    resnet20(in_data, out_data, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_9_weights, StreamingConv_9_biases, StreamingConv_10_weights, StreamingConv_10_biases, StreamingConv_11_weights, StreamingConv_11_biases, StreamingConv_12_weights, StreamingConv_12_biases, StreamingConv_13_weights, StreamingConv_13_biases, StreamingConv_15_weights, StreamingConv_15_biases, StreamingConv_14_weights, StreamingConv_14_biases, StreamingConv_16_weights, StreamingConv_16_biases, StreamingConv_17_weights, StreamingConv_17_biases, StreamingConv_18_weights, StreamingConv_18_biases, StreamingConv_19_weights, StreamingConv_19_biases, StreamingConv_20_weights, StreamingConv_20_biases, StreamingConv_21_weights, StreamingConv_21_biases);
    return 0;
}
