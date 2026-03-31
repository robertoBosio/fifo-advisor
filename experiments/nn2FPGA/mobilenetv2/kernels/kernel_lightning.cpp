#include "utils/stream_utils.hpp"
/*
* This file was automatically generated using csnake v0.4.0.
*
* This file should not be edited directly, any changes will be
* overwritten next time the script is run.
*
* Source code for csnake is available at:
* https://gitlab.com/andrejr/csnake
*
* csnake is also available on PyPI, at :
* https://pypi.org/project/csnake
*/
#include "ap_int.h"
#include "hls_stream.h"
#include "hls_vector.h"
#include "ap_axi_sdata.h"
#include "StreamingUpsample.hpp"
#include "StreamingAveragePool.hpp"
#include "StreamingDepthwiseConv.hpp"
#include "StreamingPad.hpp"
#include "StreamingReshape.hpp"
#include "StreamingMaxPool.hpp"
#include "StreamingGlobalAveragePool.hpp"
#include "StreamingConv.hpp"
#include "StreamingMul.hpp"
#include "DequantQuant.hpp"
#include "TensorDuplicator.hpp"
#include "StreamingConcat.hpp"
#include "StreamingWindowSelector.hpp"
#include "StreamingLUT.hpp"
#include "StreamingSplit.hpp"
#include "StreamingReLU.hpp"
#include "StreamToNHWC.hpp"
#include "StreamingMemory.hpp"
#include "StreamingAdd.hpp"
#include "NHWCToStream.hpp"
#include "BandwidthAdjust.hpp"
void mobilenet_v2(
    std::array<std::array<ap_int<8>, 3>, 2> in_data[25088],
    std::array<std::array<ap_int<8>, 2>, 1> out_data[501],
    ap_int<8> StreamingConv_0_weights[32][3][9],
    ap_int<14> StreamingConv_0_biases[32][1][1],
    ap_int<8> StreamingDepthwiseConv_0_weights[32][1][9],
    ap_int<14> StreamingDepthwiseConv_0_biases[32][1][1],
    ap_int<8> StreamingConv_1_weights[32][16][1],
    ap_int<15> StreamingConv_1_biases[16][1][1],
    ap_int<8> StreamingConv_2_weights[32][48][1],
    ap_int<14> StreamingConv_2_biases[32][3][1],
    ap_int<8> StreamingDepthwiseConv_1_weights[32][3][9],
    ap_int<15> StreamingDepthwiseConv_1_biases[32][3][1],
    ap_int<8> StreamingConv_3_weights[256][9][1],
    ap_int<15> StreamingConv_3_biases[8][3][1],
    ap_int<8> StreamingConv_4_weights[216][16][1],
    ap_int<14> StreamingConv_4_biases[36][4][1],
    ap_int<8> StreamingDepthwiseConv_2_weights[144][1][9],
    ap_int<14> StreamingDepthwiseConv_2_biases[144][1][1],
    ap_int<8> StreamingConv_5_weights[216][16][1],
    ap_int<15> StreamingConv_5_biases[24][1][1],
    ap_int<8> StreamingConv_6_weights[216][16][1],
    ap_int<13> StreamingConv_6_biases[72][2][1],
    ap_int<8> StreamingDepthwiseConv_3_weights[72][2][9],
    ap_int<15> StreamingDepthwiseConv_3_biases[72][2][1],
    ap_int<8> StreamingConv_7_weights[512][9][1],
    ap_int<15> StreamingConv_7_biases[32][1][1],
    ap_int<8> StreamingConv_8_weights[512][12][1],
    ap_int<15> StreamingConv_8_biases[64][3][1],
    ap_int<8> StreamingDepthwiseConv_4_weights[192][1][9],
    ap_int<14> StreamingDepthwiseConv_4_biases[192][1][1],
    ap_int<8> StreamingConv_9_weights[512][12][1],
    ap_int<15> StreamingConv_9_biases[8][4][1],
    ap_int<8> StreamingConv_10_weights[512][12][1],
    ap_int<15> StreamingConv_10_biases[64][3][1],
    ap_int<8> StreamingDepthwiseConv_5_weights[192][1][9],
    ap_int<14> StreamingDepthwiseConv_5_biases[192][1][1],
    ap_int<8> StreamingConv_11_weights[512][12][1],
    ap_int<16> StreamingConv_11_biases[8][4][1],
    ap_int<8> StreamingConv_12_weights[512][12][1],
    ap_int<14> StreamingConv_12_biases[64][3][1],
    ap_int<8> StreamingDepthwiseConv_6_weights[192][1][9],
    ap_int<15> StreamingDepthwiseConv_6_biases[192][1][1],
    ap_int<8> StreamingConv_13_weights[1024][12][1],
    ap_int<16> StreamingConv_13_biases[16][4][1],
    ap_int<8> StreamingConv_14_weights[2048][12][1],
    ap_int<16> StreamingConv_14_biases[128][3][1],
    ap_int<8> StreamingDepthwiseConv_7_weights[384][1][9],
    ap_int<14> StreamingDepthwiseConv_7_biases[384][1][1],
    ap_int<8> StreamingConv_15_weights[2048][12][1],
    ap_int<16> StreamingConv_15_biases[16][4][1],
    ap_int<8> StreamingConv_16_weights[2048][12][1],
    ap_int<16> StreamingConv_16_biases[128][3][1],
    ap_int<8> StreamingDepthwiseConv_8_weights[384][1][9],
    ap_int<14> StreamingDepthwiseConv_8_biases[384][1][1],
    ap_int<8> StreamingConv_17_weights[2048][12][1],
    ap_int<15> StreamingConv_17_biases[16][4][1],
    ap_int<8> StreamingConv_18_weights[2048][12][1],
    ap_int<14> StreamingConv_18_biases[128][3][1],
    ap_int<8> StreamingDepthwiseConv_9_weights[384][1][9],
    ap_int<14> StreamingDepthwiseConv_9_biases[384][1][1],
    ap_int<8> StreamingConv_19_weights[2048][12][1],
    ap_int<15> StreamingConv_19_biases[16][4][1],
    ap_int<8> StreamingConv_20_weights[2048][12][1],
    ap_int<14> StreamingConv_20_biases[128][3][1],
    ap_int<8> StreamingDepthwiseConv_10_weights[384][1][9],
    ap_int<15> StreamingDepthwiseConv_10_biases[384][1][1],
    ap_int<8> StreamingConv_21_weights[2048][18][1],
    ap_int<16> StreamingConv_21_biases[32][3][1],
    ap_int<8> StreamingConv_22_weights[1536][36][1],
    ap_int<14> StreamingConv_22_biases[192][3][1],
    ap_int<8> StreamingDepthwiseConv_11_weights[576][1][9],
    ap_int<15> StreamingDepthwiseConv_11_biases[576][1][1],
    ap_int<8> StreamingConv_23_weights[2048][27][1],
    ap_int<15> StreamingConv_23_biases[32][3][1],
    ap_int<8> StreamingConv_24_weights[1536][36][1],
    ap_int<15> StreamingConv_24_biases[192][3][1],
    ap_int<8> StreamingDepthwiseConv_12_weights[576][1][9],
    ap_int<15> StreamingDepthwiseConv_12_biases[576][1][1],
    ap_int<8> StreamingConv_25_weights[2048][27][1],
    ap_int<15> StreamingConv_25_biases[32][3][1],
    ap_int<8> StreamingConv_26_weights[1536][36][1],
    ap_int<14> StreamingConv_26_biases[192][3][1],
    ap_int<8> StreamingDepthwiseConv_13_weights[576][1][9],
    ap_int<15> StreamingDepthwiseConv_13_biases[576][1][1],
    ap_int<8> StreamingConv_27_weights[2560][36][1],
    ap_int<15> StreamingConv_27_biases[40][4][1],
    ap_int<8> StreamingConv_28_weights[3840][40][1],
    ap_int<15> StreamingConv_28_biases[240][4][1],
    ap_int<8> StreamingDepthwiseConv_14_weights[960][1][9],
    ap_int<15> StreamingDepthwiseConv_14_biases[960][1][1],
    ap_int<8> StreamingConv_29_weights[3840][40][1],
    ap_int<16> StreamingConv_29_biases[40][4][1],
    ap_int<8> StreamingConv_30_weights[3840][40][1],
    ap_int<13> StreamingConv_30_biases[240][4][1],
    ap_int<8> StreamingDepthwiseConv_15_weights[960][1][9],
    ap_int<14> StreamingDepthwiseConv_15_biases[960][1][1],
    ap_int<8> StreamingConv_31_weights[3840][40][1],
    ap_int<15> StreamingConv_31_biases[80][2][1],
    ap_int<8> StreamingConv_32_weights[3840][40][1],
    ap_int<14> StreamingConv_32_biases[480][2][1],
    ap_int<8> StreamingDepthwiseConv_16_weights[960][1][9],
    ap_int<15> StreamingDepthwiseConv_16_biases[960][1][1],
    ap_int<8> StreamingConv_33_weights[2560][120][1],
    ap_int<15> StreamingConv_33_biases[80][4][1],
    ap_int<8> StreamingConv_34_weights[2560][160][1],
    ap_int<12> StreamingConv_34_biases[320][4][1],
    ap_int<8> StreamingConv_35_weights[128000][10][1],
    ap_int<9> StreamingConv_35_biases[500][2][1]
)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    hls::stream<std::array<ap_int<8>, 3>> NHWCToStream_0_out0_stream[2];
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[14] depth=4
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[0] depth=29
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[1] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[2] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[3] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[4] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[5] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[6] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[7] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[8] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[9] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[10] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[11] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[12] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[13] depth=31
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[14] depth=31
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[3] depth=112
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[4] depth=111
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[8] depth=112
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[9] depth=111
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[12] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[0] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[1] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[2] depth=37
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[4] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[6] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[8] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[10] depth=41
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[2] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[3] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[6] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[7] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[9] depth=33
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 16>> BandwidthAdjustIncreaseChannels_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> StreamingLineBuffer_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[0] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[1] depth=8
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustIncreaseChannels_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 16>> StreamingLineBuffer_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[14] depth=4
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[0] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[1] depth=99
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[4] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[5] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[6] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[7] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[8] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[9] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[10] depth=42
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[11] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[12] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[13] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[14] depth=44
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[3] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[4] depth=1729
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[6] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[7] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[8] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[9] depth=1729
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[12] depth=33
    hls::stream<std::array<ap_uint<8>, 3>> StreamingDepthwiseConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseStreams_0_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[1] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[2] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_5_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[0] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[1] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[2] depth=246
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[3] depth=246
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_3_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_0_out0_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[0] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[1] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[2] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[3] depth=7
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_0_out1_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[0] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[1] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[2] depth=7
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[3] depth=7
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_0_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[1] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[2] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_1_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[0] depth=458
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[1] depth=458
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[2] depth=458
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[3] depth=458
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_2_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_6_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[3] depth=10
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_4_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[0] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[1] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[2] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[3] depth=28
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_2_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[14] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[15] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[16] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[17] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[0] depth=291
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[1] depth=147
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[2] depth=2598
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[3] depth=2598
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[4] depth=149
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[6] depth=294
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[7] depth=149
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[8] depth=583
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[9] depth=583
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[10] depth=294
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[11] depth=151
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[12] depth=440
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[13] depth=296
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[14] depth=441
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[15] depth=441
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[16] depth=441
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[17] depth=297
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[0] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[1] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[2] depth=2017
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[3] depth=2017
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[4] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[5] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[6] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[7] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[8] depth=2017
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[9] depth=2017
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[10] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[11] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[12] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[13] depth=145
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_2_out0_stream[4];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 16>> BandwidthAdjustIncreaseChannels_3_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> StreamingLineBuffer_8_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[0] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[1] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[2] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[3] depth=16
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_5_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_0_out0_stream[4];
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 8>> BandwidthAdjustIncreaseChannels_4_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 8>> StreamingLineBuffer_9_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[0] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[1] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[2] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[3] depth=8
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_6_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[2] depth=74
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[3] depth=74
    hls::stream<std::array<ap_uint<8>, 2>> BandwidthAdjustDecreaseStreams_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[14] depth=4
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[0] depth=75
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[1] depth=219
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[3] depth=152
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[4] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[5] depth=76
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[6] depth=148
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[7] depth=76
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[8] depth=148
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[9] depth=76
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[10] depth=82
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[11] depth=83
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[12] depth=83
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[13] depth=84
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[14] depth=84
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[0] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[1] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[2] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[3] depth=1945
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[4] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[5] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[6] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[7] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[8] depth=1945
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[9] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[10] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[11] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[12] depth=73
    hls::stream<std::array<ap_uint<8>, 2>> StreamingDepthwiseConv_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[0] depth=37
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[1] depth=37
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[0] depth=124
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[1] depth=124
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_7_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_7_out0_stream[0] depth=138
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_7_out0_stream[1] depth=138
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[0] depth=12
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[1] depth=12
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[1] depth=44
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_4_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[0] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[1] depth=195
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[2] depth=197
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[4] depth=198
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[6] depth=198
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[8] depth=200
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[10] depth=201
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[4] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[8] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[9] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_8_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[0] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[1] depth=46
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[0] depth=8
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[1] depth=8
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_9_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_10_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_10_out0_stream[0] depth=138
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_10_out0_stream[1] depth=138
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[0] depth=12
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[1] depth=12
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[1] depth=44
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[0] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[1] depth=195
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[2] depth=197
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[4] depth=198
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[6] depth=198
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[8] depth=200
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[10] depth=201
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[4] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[8] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[9] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_11_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[0] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[1] depth=46
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[0] depth=12
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[1] depth=12
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[1] depth=44
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_7_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[14] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[0] depth=195
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[3] depth=392
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[4] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[5] depth=196
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[6] depth=388
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[7] depth=196
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[8] depth=388
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[9] depth=196
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[10] depth=202
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[11] depth=203
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[12] depth=203
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[13] depth=204
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[14] depth=204
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[2] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[4] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[6] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[7] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[8] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[9] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[10] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[11] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[12] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_6_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_6_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_12_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_12_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_12_out0_stream[1] depth=66
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustDecreaseStreams_1_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_1_out0_stream[0] depth=535
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_13_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_2_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[0] depth=179
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[1] depth=163
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[0] depth=28
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[1] depth=20
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[0] depth=86
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[1] depth=86
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_8_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[4] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[6] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[8] depth=392
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[10] depth=393
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_7_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_7_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_13_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[1] depth=110
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[1] depth=19
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_2_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_2_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_4_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_4_out0_stream[0] depth=163
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_4_out0_stream[1] depth=163
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[0] depth=21
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[1] depth=20
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_16_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[0] depth=86
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[1] depth=86
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_9_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[4] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[6] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[8] depth=392
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[10] depth=393
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_8_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_8_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_14_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_14_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[1] depth=110
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[1] depth=19
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_3_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_3_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_6_out0_stream[0] depth=163
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_6_out0_stream[1] depth=163
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[0] depth=21
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[1] depth=20
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[0] depth=86
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[1] depth=86
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_10_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[4] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[6] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[8] depth=392
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[10] depth=393
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_9_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_9_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_15_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_15_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_15_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_28_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[1] depth=110
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_29_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[0] depth=20
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[1] depth=20
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[0] depth=86
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[1] depth=86
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_11_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[4] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[6] depth=390
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[8] depth=392
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[10] depth=393
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_10_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_10_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 6>> BandwidthAdjustIncreaseChannels_16_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_16_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_16_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> StreamingLineBuffer_31_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[0] depth=58
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[1] depth=58
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_21_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[0] depth=323
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[1] depth=323
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_17_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_17_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_17_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_32_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[0] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[1] depth=13
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_12_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[0] depth=1155
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[2] depth=581
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[4] depth=582
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[6] depth=582
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[8] depth=584
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[10] depth=585
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[2] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[3] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[5] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[6] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[7] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[8] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[9] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_11_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_11_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_18_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_18_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_18_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_34_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[0] depth=52
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[1] depth=52
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[0] depth=323
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[1] depth=323
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_19_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_19_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_35_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[0] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[1] depth=13
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_24_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_13_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[0] depth=1155
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[2] depth=581
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[4] depth=582
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[6] depth=582
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[8] depth=584
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[10] depth=585
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[11] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[2] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[3] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[5] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[6] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[7] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[8] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[9] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_12_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingDepthwiseConv_12_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_20_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_20_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_20_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_37_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[0] depth=52
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[1] depth=52
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_21_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_21_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_21_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_38_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[0] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[1] depth=13
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_14_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[1] depth=578
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseStreams_4_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_4_out0_stream[0] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[0] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[1] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[5] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[6] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[8] depth=7
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[0] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[2] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[4] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[5] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[8] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[2] depth=6913
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[3] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[5] depth=6913
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[6] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[7] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_13_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_13_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_22_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_22_out0_stream[0] depth=132
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_27_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_27_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[0] depth=22
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[0] depth=483
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_15_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_15_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 10>> BandwidthAdjustIncreaseChannels_23_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_23_out0_stream[0] depth=53
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_28_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_28_out0_stream[0] depth=181
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_16_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_16_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[0] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[1] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[5] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[6] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[8] depth=7
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[2] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[5] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[8] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_14_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_14_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 10>> BandwidthAdjustIncreaseChannels_24_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_24_out0_stream[0] depth=78
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_29_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_29_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_8_out0_stream[1];
    #pragma HLS STREAM variable=StreamingAdd_8_out0_stream[0] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_9_out0_stream[0] depth=22
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_9_out1_stream[0] depth=22
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_17_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_17_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_18_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_18_out0_stream[0] depth=802
    hls::stream<std::array<ap_int<8>, 10>> BandwidthAdjustIncreaseChannels_25_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_25_out0_stream[0] depth=21
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_30_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_30_out0_stream[0] depth=181
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_19_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_19_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[0] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[1] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[5] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[6] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[8] depth=7
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[2] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[5] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[8] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_15_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_15_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 20>> BandwidthAdjustIncreaseChannels_26_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_26_out0_stream[0] depth=43
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_31_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_31_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> StreamingAdd_9_out0_stream[1];
    #pragma HLS STREAM variable=StreamingAdd_9_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 20>> BandwidthAdjustIncreaseChannels_27_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_27_out0_stream[0] depth=13
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_32_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_32_out0_stream[0] depth=241
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_20_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_20_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[0] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[1] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[5] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[6] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[7] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[8] depth=7
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[2] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[3] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[5] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[8] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_16_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_16_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 30>> BandwidthAdjustIncreaseChannels_28_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_28_out0_stream[0] depth=27
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_33_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_33_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 40>> BandwidthAdjustIncreaseChannels_29_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_29_out0_stream[0] depth=14
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_34_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_34_out0_stream[0] depth=241
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_21_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_21_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingGlobalAveragePool_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingGlobalAveragePool_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 5>> BandwidthAdjustIncreaseChannels_30_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_30_out0_stream[0] depth=259
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_35_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_35_out0_stream[0] depth=2
    mm2s<ap_int<8>, 3, 2, 25088>(in_data, NHWCToStream_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_0," << NHWCToStream_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_1," << NHWCToStream_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_0;
    StreamingLineBuffer_0_pixel_0.run<1>(NHWCToStream_0_out0_stream[1], StreamingLineBuffer_0_out0_stream_prepad[14], StreamingLineBuffer_0_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_14," << StreamingLineBuffer_0_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_0," << StreamingLineBuffer_0_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_1;
    StreamingLineBuffer_0_pixel_1.run<2>(NHWCToStream_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[13], StreamingLineBuffer_0_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_13," << StreamingLineBuffer_0_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_1," << StreamingLineBuffer_0_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_2;
    StreamingLineBuffer_0_pixel_2.run<3>(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[12], StreamingLineBuffer_0_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_12," << StreamingLineBuffer_0_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_2," << StreamingLineBuffer_0_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_3;
    StreamingLineBuffer_0_pixel_3.run<4>(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[11], StreamingLineBuffer_0_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_11," << StreamingLineBuffer_0_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_4," << StreamingLineBuffer_0_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_4;
    StreamingLineBuffer_0_pixel_4.run<5>(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[10], StreamingLineBuffer_0_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_10," << StreamingLineBuffer_0_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_3," << StreamingLineBuffer_0_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_6;
    StreamingLineBuffer_0_pixel_6.run<7>(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_8," << StreamingLineBuffer_0_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_6," << StreamingLineBuffer_0_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_5;
    StreamingLineBuffer_0_pixel_5.run<6>(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[9], StreamingLineBuffer_0_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_9," << StreamingLineBuffer_0_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_5," << StreamingLineBuffer_0_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_8;
    StreamingLineBuffer_0_pixel_8.run<9>(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_6," << StreamingLineBuffer_0_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_9," << StreamingLineBuffer_0_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_7;
    StreamingLineBuffer_0_pixel_7.run<8>(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_7," << StreamingLineBuffer_0_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_7," << StreamingLineBuffer_0_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_11;
    StreamingLineBuffer_0_pixel_11.run<12>(StreamingLineBuffer_0_buffer_stream[9], StreamingLineBuffer_0_out0_stream_prepad[3], StreamingLineBuffer_0_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_3," << StreamingLineBuffer_0_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_11," << StreamingLineBuffer_0_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_9;
    StreamingLineBuffer_0_pixel_9.run<10>(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_5," << StreamingLineBuffer_0_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_8," << StreamingLineBuffer_0_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_13;
    StreamingLineBuffer_0_pixel_13.run<14>(StreamingLineBuffer_0_buffer_stream[11], StreamingLineBuffer_0_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_1," << StreamingLineBuffer_0_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_10;
    StreamingLineBuffer_0_pixel_10.run<11>(StreamingLineBuffer_0_buffer_stream[8], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_4," << StreamingLineBuffer_0_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_10," << StreamingLineBuffer_0_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_12;
    StreamingLineBuffer_0_pixel_12.run<13>(StreamingLineBuffer_0_buffer_stream[10], StreamingLineBuffer_0_out0_stream_prepad[2], StreamingLineBuffer_0_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_2," << StreamingLineBuffer_0_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_12," << StreamingLineBuffer_0_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_14;
    StreamingLineBuffer_0_pixel_14.run<15>(StreamingLineBuffer_0_buffer_stream[12], StreamingLineBuffer_0_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_0," << StreamingLineBuffer_0_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 3>,  // TWord
        ap_int<8>,  // TData
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        3,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_0_pad;
    StreamingLineBuffer_0_pad.run<16>(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_0," << StreamingLineBuffer_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_1," << StreamingLineBuffer_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_2," << StreamingLineBuffer_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_3," << StreamingLineBuffer_0_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_4," << StreamingLineBuffer_0_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_5," << StreamingLineBuffer_0_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_6," << StreamingLineBuffer_0_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_7," << StreamingLineBuffer_0_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_8," << StreamingLineBuffer_0_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_9," << StreamingLineBuffer_0_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_10," << StreamingLineBuffer_0_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_11," << StreamingLineBuffer_0_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_12," << StreamingLineBuffer_0_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_13," << StreamingLineBuffer_0_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_14," << StreamingLineBuffer_0_out0_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 3>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 3>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<7, ap_int<22>, ap_uint<8>>,  // Quantizer
        32,  // OUT_CH
        3,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        3,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_0;
    StreamingConv_0.run<17>(StreamingLineBuffer_0_out0_stream, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_0," << StreamingConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_1," << StreamingConv_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_0;
    StreamingLineBuffer_1_pixel_0.run<18>(StreamingConv_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_11," << StreamingLineBuffer_1_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_0," << StreamingLineBuffer_1_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_1;
    StreamingLineBuffer_1_pixel_1.run<19>(StreamingConv_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_10," << StreamingLineBuffer_1_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_1," << StreamingLineBuffer_1_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_2;
    StreamingLineBuffer_1_pixel_2.run<20>(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_9," << StreamingLineBuffer_1_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_2," << StreamingLineBuffer_1_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_3;
    StreamingLineBuffer_1_pixel_3.run<21>(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_8," << StreamingLineBuffer_1_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_3," << StreamingLineBuffer_1_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_4;
    StreamingLineBuffer_1_pixel_4.run<22>(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_7," << StreamingLineBuffer_1_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_4," << StreamingLineBuffer_1_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_5;
    StreamingLineBuffer_1_pixel_5.run<23>(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_6," << StreamingLineBuffer_1_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_5," << StreamingLineBuffer_1_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_6;
    StreamingLineBuffer_1_pixel_6.run<24>(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_5," << StreamingLineBuffer_1_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_6," << StreamingLineBuffer_1_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_7;
    StreamingLineBuffer_1_pixel_7.run<25>(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_4," << StreamingLineBuffer_1_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_7," << StreamingLineBuffer_1_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_8;
    StreamingLineBuffer_1_pixel_8.run<26>(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[3], StreamingLineBuffer_1_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_3," << StreamingLineBuffer_1_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_8," << StreamingLineBuffer_1_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_9;
    StreamingLineBuffer_1_pixel_9.run<27>(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[2], StreamingLineBuffer_1_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_2," << StreamingLineBuffer_1_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_9," << StreamingLineBuffer_1_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_10;
    StreamingLineBuffer_1_pixel_10.run<28>(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_1," << StreamingLineBuffer_1_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_11;
    StreamingLineBuffer_1_pixel_11.run<29>(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_0," << StreamingLineBuffer_1_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_1_pad;
    StreamingLineBuffer_1_pad.run<30>(StreamingLineBuffer_1_out0_stream_prepad, StreamingLineBuffer_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_0," << StreamingLineBuffer_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_1," << StreamingLineBuffer_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_2," << StreamingLineBuffer_1_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_3," << StreamingLineBuffer_1_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_4," << StreamingLineBuffer_1_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_5," << StreamingLineBuffer_1_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_6," << StreamingLineBuffer_1_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_7," << StreamingLineBuffer_1_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_8," << StreamingLineBuffer_1_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_9," << StreamingLineBuffer_1_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_10," << StreamingLineBuffer_1_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_11," << StreamingLineBuffer_1_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_0;
    StreamingDepthwiseConv_0.run<31>(StreamingLineBuffer_1_out0_stream, StreamingDepthwiseConv_0_weights, StreamingDepthwiseConv_0_biases, StreamingDepthwiseConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_0," << StreamingDepthwiseConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_1," << StreamingDepthwiseConv_0_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 16>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_0;
    BandwidthAdjustIncreaseChannels_0.run<32>(StreamingDepthwiseConv_0_out0_stream, BandwidthAdjustIncreaseChannels_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_0," << BandwidthAdjustIncreaseChannels_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_1," << BandwidthAdjustIncreaseChannels_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_2_pixel_0;
    StreamingLineBuffer_2_pixel_0.run<33>(BandwidthAdjustIncreaseChannels_0_out0_stream[1], StreamingLineBuffer_2_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_1," << StreamingLineBuffer_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_2_pixel_1;
    StreamingLineBuffer_2_pixel_1.run<34>(BandwidthAdjustIncreaseChannels_0_out0_stream[0], StreamingLineBuffer_2_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_0," << StreamingLineBuffer_2_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 16>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        32,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_1;
    StreamingConv_1.run<35>(StreamingLineBuffer_2_out0_stream, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_0," << StreamingConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_1," << StreamingConv_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_1;
    BandwidthAdjustIncreaseChannels_1.run<36>(StreamingConv_1_out0_stream, BandwidthAdjustIncreaseChannels_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_0," << BandwidthAdjustIncreaseChannels_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_1," << BandwidthAdjustIncreaseChannels_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_3_pixel_0;
    StreamingLineBuffer_3_pixel_0.run<37>(BandwidthAdjustIncreaseChannels_1_out0_stream[1], StreamingLineBuffer_3_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_1," << StreamingLineBuffer_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_3_pixel_1;
    StreamingLineBuffer_3_pixel_1.run<38>(BandwidthAdjustIncreaseChannels_1_out0_stream[0], StreamingLineBuffer_3_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_0," << StreamingLineBuffer_3_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 48>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<6, ap_int<22>, ap_uint<8>>,  // Quantizer
        96,  // OUT_CH
        16,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_2;
    StreamingConv_2.run<39>(StreamingLineBuffer_3_out0_stream, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_0," << StreamingConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_1," << StreamingConv_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_0;
    StreamingLineBuffer_4_pixel_0.run<40>(StreamingConv_2_out0_stream[1], StreamingLineBuffer_4_out0_stream_prepad[14], StreamingLineBuffer_4_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_14," << StreamingLineBuffer_4_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_0," << StreamingLineBuffer_4_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_1;
    StreamingLineBuffer_4_pixel_1.run<41>(StreamingConv_2_out0_stream[0], StreamingLineBuffer_4_out0_stream_prepad[13], StreamingLineBuffer_4_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_13," << StreamingLineBuffer_4_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_1," << StreamingLineBuffer_4_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_2;
    StreamingLineBuffer_4_pixel_2.run<42>(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream_prepad[12], StreamingLineBuffer_4_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_12," << StreamingLineBuffer_4_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_2," << StreamingLineBuffer_4_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_3;
    StreamingLineBuffer_4_pixel_3.run<43>(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream_prepad[11], StreamingLineBuffer_4_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_11," << StreamingLineBuffer_4_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_4," << StreamingLineBuffer_4_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_4;
    StreamingLineBuffer_4_pixel_4.run<44>(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream_prepad[10], StreamingLineBuffer_4_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_10," << StreamingLineBuffer_4_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_3," << StreamingLineBuffer_4_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_6;
    StreamingLineBuffer_4_pixel_6.run<46>(StreamingLineBuffer_4_buffer_stream[4], StreamingLineBuffer_4_out0_stream_prepad[8], StreamingLineBuffer_4_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_8," << StreamingLineBuffer_4_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_6," << StreamingLineBuffer_4_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_5;
    StreamingLineBuffer_4_pixel_5.run<45>(StreamingLineBuffer_4_buffer_stream[3], StreamingLineBuffer_4_out0_stream_prepad[9], StreamingLineBuffer_4_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_9," << StreamingLineBuffer_4_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_5," << StreamingLineBuffer_4_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_8;
    StreamingLineBuffer_4_pixel_8.run<48>(StreamingLineBuffer_4_buffer_stream[6], StreamingLineBuffer_4_out0_stream_prepad[6], StreamingLineBuffer_4_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_6," << StreamingLineBuffer_4_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_9," << StreamingLineBuffer_4_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_7;
    StreamingLineBuffer_4_pixel_7.run<47>(StreamingLineBuffer_4_buffer_stream[5], StreamingLineBuffer_4_out0_stream_prepad[7], StreamingLineBuffer_4_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_7," << StreamingLineBuffer_4_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_7," << StreamingLineBuffer_4_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_11;
    StreamingLineBuffer_4_pixel_11.run<51>(StreamingLineBuffer_4_buffer_stream[9], StreamingLineBuffer_4_out0_stream_prepad[3], StreamingLineBuffer_4_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_3," << StreamingLineBuffer_4_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_11," << StreamingLineBuffer_4_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_9;
    StreamingLineBuffer_4_pixel_9.run<49>(StreamingLineBuffer_4_buffer_stream[7], StreamingLineBuffer_4_out0_stream_prepad[5], StreamingLineBuffer_4_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_5," << StreamingLineBuffer_4_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_8," << StreamingLineBuffer_4_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_13;
    StreamingLineBuffer_4_pixel_13.run<53>(StreamingLineBuffer_4_buffer_stream[11], StreamingLineBuffer_4_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_1," << StreamingLineBuffer_4_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_10;
    StreamingLineBuffer_4_pixel_10.run<50>(StreamingLineBuffer_4_buffer_stream[8], StreamingLineBuffer_4_out0_stream_prepad[4], StreamingLineBuffer_4_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_4," << StreamingLineBuffer_4_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_10," << StreamingLineBuffer_4_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_12;
    StreamingLineBuffer_4_pixel_12.run<52>(StreamingLineBuffer_4_buffer_stream[10], StreamingLineBuffer_4_out0_stream_prepad[2], StreamingLineBuffer_4_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_2," << StreamingLineBuffer_4_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_12," << StreamingLineBuffer_4_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_14;
    StreamingLineBuffer_4_pixel_14.run<54>(StreamingLineBuffer_4_buffer_stream[12], StreamingLineBuffer_4_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_0," << StreamingLineBuffer_4_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 3>,  // TWord
        ap_uint<8>,  // TData
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        3,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_4_pad;
    StreamingLineBuffer_4_pad.run<55>(StreamingLineBuffer_4_out0_stream_prepad, StreamingLineBuffer_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_0," << StreamingLineBuffer_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_1," << StreamingLineBuffer_4_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_2," << StreamingLineBuffer_4_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_3," << StreamingLineBuffer_4_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_4," << StreamingLineBuffer_4_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_5," << StreamingLineBuffer_4_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_6," << StreamingLineBuffer_4_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_7," << StreamingLineBuffer_4_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_8," << StreamingLineBuffer_4_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_9," << StreamingLineBuffer_4_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_10," << StreamingLineBuffer_4_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_11," << StreamingLineBuffer_4_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_12," << StreamingLineBuffer_4_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_13," << StreamingLineBuffer_4_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_14," << StreamingLineBuffer_4_out0_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 3>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        96,  // OUT_CH
        96,  // IN_CH
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        3,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_1;
    StreamingDepthwiseConv_1.run<56>(StreamingLineBuffer_4_out0_stream, StreamingDepthwiseConv_1_weights, StreamingDepthwiseConv_1_biases, StreamingDepthwiseConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_0," << StreamingDepthwiseConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_1," << StreamingDepthwiseConv_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_0;
    BandwidthAdjustIncreaseStreams_0.run<57>(StreamingDepthwiseConv_1_out0_stream, BandwidthAdjustIncreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_0," << BandwidthAdjustIncreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_1," << BandwidthAdjustIncreaseStreams_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_2," << BandwidthAdjustIncreaseStreams_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_3," << BandwidthAdjustIncreaseStreams_0_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_0;
    StreamingLineBuffer_5_pixel_0.run<58>(BandwidthAdjustIncreaseStreams_0_out0_stream[3], StreamingLineBuffer_5_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_3," << StreamingLineBuffer_5_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_1;
    StreamingLineBuffer_5_pixel_1.run<59>(BandwidthAdjustIncreaseStreams_0_out0_stream[2], StreamingLineBuffer_5_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_2," << StreamingLineBuffer_5_out0_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_2;
    StreamingLineBuffer_5_pixel_2.run<60>(BandwidthAdjustIncreaseStreams_0_out0_stream[1], StreamingLineBuffer_5_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_1," << StreamingLineBuffer_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_3;
    StreamingLineBuffer_5_pixel_3.run<61>(BandwidthAdjustIncreaseStreams_0_out0_stream[0], StreamingLineBuffer_5_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_0," << StreamingLineBuffer_5_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 9>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        96,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_3;
    StreamingConv_3.run<62>(StreamingLineBuffer_5_out0_stream, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_0," << StreamingConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_1," << StreamingConv_3_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_2," << StreamingConv_3_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_3," << StreamingConv_3_out0_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        3,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<63>(StreamingConv_3_out0_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_0," << TensorDuplicator_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_1," << TensorDuplicator_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_2," << TensorDuplicator_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_3," << TensorDuplicator_0_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_0," << TensorDuplicator_0_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_1," << TensorDuplicator_0_out1_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_2," << TensorDuplicator_0_out1_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_3," << TensorDuplicator_0_out1_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_0;
    BandwidthAdjustDecreaseChannels_0.run<64>(TensorDuplicator_0_out0_stream, BandwidthAdjustDecreaseChannels_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_0," << BandwidthAdjustDecreaseChannels_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_1," << BandwidthAdjustDecreaseChannels_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_2," << BandwidthAdjustDecreaseChannels_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_3," << BandwidthAdjustDecreaseChannels_0_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_1;
    BandwidthAdjustDecreaseChannels_1.run<65>(TensorDuplicator_0_out1_stream, BandwidthAdjustDecreaseChannels_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_0," << BandwidthAdjustDecreaseChannels_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_1," << BandwidthAdjustDecreaseChannels_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_2," << BandwidthAdjustDecreaseChannels_1_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_3," << BandwidthAdjustDecreaseChannels_1_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_2;
    BandwidthAdjustIncreaseChannels_2.run<66>(BandwidthAdjustDecreaseChannels_0_out0_stream, BandwidthAdjustIncreaseChannels_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_0," << BandwidthAdjustIncreaseChannels_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_1," << BandwidthAdjustIncreaseChannels_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_2," << BandwidthAdjustIncreaseChannels_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_3," << BandwidthAdjustIncreaseChannels_2_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_6_pixel_0;
    StreamingLineBuffer_6_pixel_0.run<67>(BandwidthAdjustIncreaseChannels_2_out0_stream[3], StreamingLineBuffer_6_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_3," << StreamingLineBuffer_6_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_6_pixel_1;
    StreamingLineBuffer_6_pixel_1.run<68>(BandwidthAdjustIncreaseChannels_2_out0_stream[2], StreamingLineBuffer_6_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_2," << StreamingLineBuffer_6_out0_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_6_pixel_2;
    StreamingLineBuffer_6_pixel_2.run<69>(BandwidthAdjustIncreaseChannels_2_out0_stream[1], StreamingLineBuffer_6_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_1," << StreamingLineBuffer_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_6_pixel_3;
    StreamingLineBuffer_6_pixel_3.run<70>(BandwidthAdjustIncreaseChannels_2_out0_stream[0], StreamingLineBuffer_6_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_0," << StreamingLineBuffer_6_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 4>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<7, ap_int<22>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        24,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_4;
    StreamingConv_4.run<71>(StreamingLineBuffer_6_out0_stream, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_0," << StreamingConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_1," << StreamingConv_4_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_2," << StreamingConv_4_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_3," << StreamingConv_4_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_2;
    BandwidthAdjustDecreaseChannels_2.run<72>(StreamingConv_4_out0_stream, BandwidthAdjustDecreaseChannels_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_0," << BandwidthAdjustDecreaseChannels_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_1," << BandwidthAdjustDecreaseChannels_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_2," << BandwidthAdjustDecreaseChannels_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_3," << BandwidthAdjustDecreaseChannels_2_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_0;
    StreamingLineBuffer_7_pixel_0.run<73>(BandwidthAdjustDecreaseChannels_2_out0_stream[0], StreamingLineBuffer_7_out0_stream_prepad[17], StreamingLineBuffer_7_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_17," << StreamingLineBuffer_7_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_0," << StreamingLineBuffer_7_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_1;
    StreamingLineBuffer_7_pixel_1.run<74>(BandwidthAdjustDecreaseChannels_2_out0_stream[3], StreamingLineBuffer_7_out0_stream_prepad[16], StreamingLineBuffer_7_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_16," << StreamingLineBuffer_7_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_1," << StreamingLineBuffer_7_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_2;
    StreamingLineBuffer_7_pixel_2.run<75>(BandwidthAdjustDecreaseChannels_2_out0_stream[2], StreamingLineBuffer_7_out0_stream_prepad[15], StreamingLineBuffer_7_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_15," << StreamingLineBuffer_7_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_4," << StreamingLineBuffer_7_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_3;
    StreamingLineBuffer_7_pixel_3.run<76>(BandwidthAdjustDecreaseChannels_2_out0_stream[1], StreamingLineBuffer_7_out0_stream_prepad[14], StreamingLineBuffer_7_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_14," << StreamingLineBuffer_7_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_5," << StreamingLineBuffer_7_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_4;
    StreamingLineBuffer_7_pixel_4.run<77>(StreamingLineBuffer_7_buffer_stream[0], StreamingLineBuffer_7_out0_stream_prepad[13], StreamingLineBuffer_7_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_13," << StreamingLineBuffer_7_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_2," << StreamingLineBuffer_7_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_5;
    StreamingLineBuffer_7_pixel_5.run<78>(StreamingLineBuffer_7_buffer_stream[1], StreamingLineBuffer_7_out0_stream_prepad[12], StreamingLineBuffer_7_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_12," << StreamingLineBuffer_7_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_3," << StreamingLineBuffer_7_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_8;
    StreamingLineBuffer_7_pixel_8.run<81>(StreamingLineBuffer_7_buffer_stream[4], StreamingLineBuffer_7_out0_stream_prepad[9], StreamingLineBuffer_7_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_9," << StreamingLineBuffer_7_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_10," << StreamingLineBuffer_7_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_9;
    StreamingLineBuffer_7_pixel_9.run<82>(StreamingLineBuffer_7_buffer_stream[5], StreamingLineBuffer_7_out0_stream_prepad[8], StreamingLineBuffer_7_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_8," << StreamingLineBuffer_7_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_11," << StreamingLineBuffer_7_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_6;
    StreamingLineBuffer_7_pixel_6.run<79>(StreamingLineBuffer_7_buffer_stream[2], StreamingLineBuffer_7_out0_stream_prepad[11], StreamingLineBuffer_7_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_11," << StreamingLineBuffer_7_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_6," << StreamingLineBuffer_7_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_7;
    StreamingLineBuffer_7_pixel_7.run<80>(StreamingLineBuffer_7_buffer_stream[3], StreamingLineBuffer_7_out0_stream_prepad[10], StreamingLineBuffer_7_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_10," << StreamingLineBuffer_7_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_7," << StreamingLineBuffer_7_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_14;
    StreamingLineBuffer_7_pixel_14.run<87>(StreamingLineBuffer_7_buffer_stream[10], StreamingLineBuffer_7_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_3," << StreamingLineBuffer_7_out0_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_15;
    StreamingLineBuffer_7_pixel_15.run<88>(StreamingLineBuffer_7_buffer_stream[11], StreamingLineBuffer_7_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_2," << StreamingLineBuffer_7_out0_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_10;
    StreamingLineBuffer_7_pixel_10.run<83>(StreamingLineBuffer_7_buffer_stream[6], StreamingLineBuffer_7_out0_stream_prepad[7], StreamingLineBuffer_7_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_7," << StreamingLineBuffer_7_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_8," << StreamingLineBuffer_7_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_11;
    StreamingLineBuffer_7_pixel_11.run<84>(StreamingLineBuffer_7_buffer_stream[7], StreamingLineBuffer_7_out0_stream_prepad[6], StreamingLineBuffer_7_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_6," << StreamingLineBuffer_7_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_9," << StreamingLineBuffer_7_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_12;
    StreamingLineBuffer_7_pixel_12.run<85>(StreamingLineBuffer_7_buffer_stream[8], StreamingLineBuffer_7_out0_stream_prepad[5], StreamingLineBuffer_7_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_5," << StreamingLineBuffer_7_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_12," << StreamingLineBuffer_7_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_13;
    StreamingLineBuffer_7_pixel_13.run<86>(StreamingLineBuffer_7_buffer_stream[9], StreamingLineBuffer_7_out0_stream_prepad[4], StreamingLineBuffer_7_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_4," << StreamingLineBuffer_7_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_13," << StreamingLineBuffer_7_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_16;
    StreamingLineBuffer_7_pixel_16.run<89>(StreamingLineBuffer_7_buffer_stream[12], StreamingLineBuffer_7_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_1," << StreamingLineBuffer_7_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_17;
    StreamingLineBuffer_7_pixel_17.run<90>(StreamingLineBuffer_7_buffer_stream[13], StreamingLineBuffer_7_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_0," << StreamingLineBuffer_7_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        4,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_7_pad;
    StreamingLineBuffer_7_pad.run<91>(StreamingLineBuffer_7_out0_stream_prepad, StreamingLineBuffer_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_0," << StreamingLineBuffer_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_1," << StreamingLineBuffer_7_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_2," << StreamingLineBuffer_7_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_3," << StreamingLineBuffer_7_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_4," << StreamingLineBuffer_7_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_5," << StreamingLineBuffer_7_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_6," << StreamingLineBuffer_7_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_7," << StreamingLineBuffer_7_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_8," << StreamingLineBuffer_7_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_9," << StreamingLineBuffer_7_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_10," << StreamingLineBuffer_7_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_11," << StreamingLineBuffer_7_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_12," << StreamingLineBuffer_7_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_13," << StreamingLineBuffer_7_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_14," << StreamingLineBuffer_7_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_15," << StreamingLineBuffer_7_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_16," << StreamingLineBuffer_7_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_17," << StreamingLineBuffer_7_out0_stream[17].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        144,  // IN_CH
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        4  // W_PAR
    > StreamingDepthwiseConv_2;
    StreamingDepthwiseConv_2.run<92>(StreamingLineBuffer_7_out0_stream, StreamingDepthwiseConv_2_weights, StreamingDepthwiseConv_2_biases, StreamingDepthwiseConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_0," << StreamingDepthwiseConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_1," << StreamingDepthwiseConv_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_2," << StreamingDepthwiseConv_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_3," << StreamingDepthwiseConv_2_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 16>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_3;
    BandwidthAdjustIncreaseChannels_3.run<93>(StreamingDepthwiseConv_2_out0_stream, BandwidthAdjustIncreaseChannels_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_0," << BandwidthAdjustIncreaseChannels_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_1," << BandwidthAdjustIncreaseChannels_3_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_2," << BandwidthAdjustIncreaseChannels_3_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_3," << BandwidthAdjustIncreaseChannels_3_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_8_pixel_0;
    StreamingLineBuffer_8_pixel_0.run<94>(BandwidthAdjustIncreaseChannels_3_out0_stream[3], StreamingLineBuffer_8_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_3," << StreamingLineBuffer_8_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_8_pixel_1;
    StreamingLineBuffer_8_pixel_1.run<95>(BandwidthAdjustIncreaseChannels_3_out0_stream[2], StreamingLineBuffer_8_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_2," << StreamingLineBuffer_8_out0_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_8_pixel_2;
    StreamingLineBuffer_8_pixel_2.run<96>(BandwidthAdjustIncreaseChannels_3_out0_stream[1], StreamingLineBuffer_8_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_1," << StreamingLineBuffer_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 16>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_8_pixel_3;
    StreamingLineBuffer_8_pixel_3.run<97>(BandwidthAdjustIncreaseChannels_3_out0_stream[0], StreamingLineBuffer_8_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_0," << StreamingLineBuffer_8_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 16>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        144,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_5;
    StreamingConv_5.run<98>(StreamingLineBuffer_8_out0_stream, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_0," << StreamingConv_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_1," << StreamingConv_5_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_2," << StreamingConv_5_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_3," << StreamingConv_5_out0_stream[3].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_0;
    StreamingAdd_0.run<99>(BandwidthAdjustDecreaseChannels_1_out0_stream, StreamingConv_5_out0_stream, StreamingAdd_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_0," << StreamingAdd_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_1," << StreamingAdd_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_2," << StreamingAdd_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_3," << StreamingAdd_0_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_4;
    BandwidthAdjustIncreaseChannels_4.run<100>(StreamingAdd_0_out0_stream, BandwidthAdjustIncreaseChannels_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_4_out0_stream_0," << BandwidthAdjustIncreaseChannels_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_4_out0_stream_1," << BandwidthAdjustIncreaseChannels_4_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_4_out0_stream_2," << BandwidthAdjustIncreaseChannels_4_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_4_out0_stream_3," << BandwidthAdjustIncreaseChannels_4_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_0;
    StreamingLineBuffer_9_pixel_0.run<101>(BandwidthAdjustIncreaseChannels_4_out0_stream[3], StreamingLineBuffer_9_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_3," << StreamingLineBuffer_9_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_1;
    StreamingLineBuffer_9_pixel_1.run<102>(BandwidthAdjustIncreaseChannels_4_out0_stream[2], StreamingLineBuffer_9_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_2," << StreamingLineBuffer_9_out0_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_2;
    StreamingLineBuffer_9_pixel_2.run<103>(BandwidthAdjustIncreaseChannels_4_out0_stream[1], StreamingLineBuffer_9_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_1," << StreamingLineBuffer_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_3;
    StreamingLineBuffer_9_pixel_3.run<104>(BandwidthAdjustIncreaseChannels_4_out0_stream[0], StreamingLineBuffer_9_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_0," << StreamingLineBuffer_9_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 8>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<6, ap_int<22>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        24,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_6;
    StreamingConv_6.run<105>(StreamingLineBuffer_9_out0_stream, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_0," << StreamingConv_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_1," << StreamingConv_6_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_2," << StreamingConv_6_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_3," << StreamingConv_6_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_0;
    BandwidthAdjustDecreaseStreams_0.run<106>(StreamingConv_6_out0_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_0," << BandwidthAdjustDecreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_1," << BandwidthAdjustDecreaseStreams_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_0;
    StreamingLineBuffer_10_pixel_0.run<107>(BandwidthAdjustDecreaseStreams_0_out0_stream[1], StreamingLineBuffer_10_out0_stream_prepad[14], StreamingLineBuffer_10_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_14," << StreamingLineBuffer_10_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_0," << StreamingLineBuffer_10_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_1;
    StreamingLineBuffer_10_pixel_1.run<108>(BandwidthAdjustDecreaseStreams_0_out0_stream[0], StreamingLineBuffer_10_out0_stream_prepad[13], StreamingLineBuffer_10_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_13," << StreamingLineBuffer_10_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_1," << StreamingLineBuffer_10_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_2;
    StreamingLineBuffer_10_pixel_2.run<109>(StreamingLineBuffer_10_buffer_stream[0], StreamingLineBuffer_10_out0_stream_prepad[12], StreamingLineBuffer_10_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_12," << StreamingLineBuffer_10_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_2," << StreamingLineBuffer_10_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_3;
    StreamingLineBuffer_10_pixel_3.run<110>(StreamingLineBuffer_10_buffer_stream[1], StreamingLineBuffer_10_out0_stream_prepad[11], StreamingLineBuffer_10_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_11," << StreamingLineBuffer_10_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_4," << StreamingLineBuffer_10_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_4;
    StreamingLineBuffer_10_pixel_4.run<111>(StreamingLineBuffer_10_buffer_stream[2], StreamingLineBuffer_10_out0_stream_prepad[10], StreamingLineBuffer_10_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_10," << StreamingLineBuffer_10_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_3," << StreamingLineBuffer_10_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_6;
    StreamingLineBuffer_10_pixel_6.run<113>(StreamingLineBuffer_10_buffer_stream[4], StreamingLineBuffer_10_out0_stream_prepad[8], StreamingLineBuffer_10_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_8," << StreamingLineBuffer_10_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_6," << StreamingLineBuffer_10_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_5;
    StreamingLineBuffer_10_pixel_5.run<112>(StreamingLineBuffer_10_buffer_stream[3], StreamingLineBuffer_10_out0_stream_prepad[9], StreamingLineBuffer_10_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_9," << StreamingLineBuffer_10_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_5," << StreamingLineBuffer_10_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_8;
    StreamingLineBuffer_10_pixel_8.run<115>(StreamingLineBuffer_10_buffer_stream[6], StreamingLineBuffer_10_out0_stream_prepad[6], StreamingLineBuffer_10_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_6," << StreamingLineBuffer_10_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_9," << StreamingLineBuffer_10_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_7;
    StreamingLineBuffer_10_pixel_7.run<114>(StreamingLineBuffer_10_buffer_stream[5], StreamingLineBuffer_10_out0_stream_prepad[7], StreamingLineBuffer_10_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_7," << StreamingLineBuffer_10_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_7," << StreamingLineBuffer_10_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_11;
    StreamingLineBuffer_10_pixel_11.run<118>(StreamingLineBuffer_10_buffer_stream[9], StreamingLineBuffer_10_out0_stream_prepad[3], StreamingLineBuffer_10_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_3," << StreamingLineBuffer_10_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_11," << StreamingLineBuffer_10_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_9;
    StreamingLineBuffer_10_pixel_9.run<116>(StreamingLineBuffer_10_buffer_stream[7], StreamingLineBuffer_10_out0_stream_prepad[5], StreamingLineBuffer_10_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_5," << StreamingLineBuffer_10_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_8," << StreamingLineBuffer_10_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_13;
    StreamingLineBuffer_10_pixel_13.run<120>(StreamingLineBuffer_10_buffer_stream[11], StreamingLineBuffer_10_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_1," << StreamingLineBuffer_10_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_10;
    StreamingLineBuffer_10_pixel_10.run<117>(StreamingLineBuffer_10_buffer_stream[8], StreamingLineBuffer_10_out0_stream_prepad[4], StreamingLineBuffer_10_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_4," << StreamingLineBuffer_10_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_10," << StreamingLineBuffer_10_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_12;
    StreamingLineBuffer_10_pixel_12.run<119>(StreamingLineBuffer_10_buffer_stream[10], StreamingLineBuffer_10_out0_stream_prepad[2], StreamingLineBuffer_10_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_2," << StreamingLineBuffer_10_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_12," << StreamingLineBuffer_10_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_14;
    StreamingLineBuffer_10_pixel_14.run<121>(StreamingLineBuffer_10_buffer_stream[12], StreamingLineBuffer_10_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_0," << StreamingLineBuffer_10_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_10_pad;
    StreamingLineBuffer_10_pad.run<122>(StreamingLineBuffer_10_out0_stream_prepad, StreamingLineBuffer_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_0," << StreamingLineBuffer_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_1," << StreamingLineBuffer_10_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_2," << StreamingLineBuffer_10_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_3," << StreamingLineBuffer_10_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_4," << StreamingLineBuffer_10_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_5," << StreamingLineBuffer_10_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_6," << StreamingLineBuffer_10_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_7," << StreamingLineBuffer_10_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_8," << StreamingLineBuffer_10_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_9," << StreamingLineBuffer_10_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_10," << StreamingLineBuffer_10_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_11," << StreamingLineBuffer_10_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_12," << StreamingLineBuffer_10_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_13," << StreamingLineBuffer_10_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_14," << StreamingLineBuffer_10_out0_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        144,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        2,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_3;
    StreamingDepthwiseConv_3.run<123>(StreamingLineBuffer_10_out0_stream, StreamingDepthwiseConv_3_weights, StreamingDepthwiseConv_3_biases, StreamingDepthwiseConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_0," << StreamingDepthwiseConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_1," << StreamingDepthwiseConv_3_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_3;
    BandwidthAdjustDecreaseChannels_3.run<124>(StreamingDepthwiseConv_3_out0_stream, BandwidthAdjustDecreaseChannels_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_0," << BandwidthAdjustDecreaseChannels_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_1," << BandwidthAdjustDecreaseChannels_3_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_5;
    BandwidthAdjustIncreaseChannels_5.run<125>(BandwidthAdjustDecreaseChannels_3_out0_stream, BandwidthAdjustIncreaseChannels_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_5_out0_stream_0," << BandwidthAdjustIncreaseChannels_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_5_out0_stream_1," << BandwidthAdjustIncreaseChannels_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_11_pixel_0;
    StreamingLineBuffer_11_pixel_0.run<126>(BandwidthAdjustIncreaseChannels_5_out0_stream[1], StreamingLineBuffer_11_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_1," << StreamingLineBuffer_11_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_11_pixel_1;
    StreamingLineBuffer_11_pixel_1.run<127>(BandwidthAdjustIncreaseChannels_5_out0_stream[0], StreamingLineBuffer_11_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_0," << StreamingLineBuffer_11_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 9>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        144,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_7;
    StreamingConv_7.run<128>(StreamingLineBuffer_11_out0_stream, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_0," << StreamingConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_1," << StreamingConv_7_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<129>(StreamingConv_7_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_0," << TensorDuplicator_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_1," << TensorDuplicator_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_0," << TensorDuplicator_1_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_1," << TensorDuplicator_1_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_6;
    BandwidthAdjustIncreaseChannels_6.run<130>(TensorDuplicator_1_out0_stream, BandwidthAdjustIncreaseChannels_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_6_out0_stream_0," << BandwidthAdjustIncreaseChannels_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_6_out0_stream_1," << BandwidthAdjustIncreaseChannels_6_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_7;
    BandwidthAdjustIncreaseChannels_7.run<131>(TensorDuplicator_1_out1_stream, BandwidthAdjustIncreaseChannels_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_7_out0_stream_0," << BandwidthAdjustIncreaseChannels_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_7_out0_stream_1," << BandwidthAdjustIncreaseChannels_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_12_pixel_0;
    StreamingLineBuffer_12_pixel_0.run<132>(BandwidthAdjustIncreaseChannels_6_out0_stream[1], StreamingLineBuffer_12_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_1," << StreamingLineBuffer_12_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_12_pixel_1;
    StreamingLineBuffer_12_pixel_1.run<133>(BandwidthAdjustIncreaseChannels_6_out0_stream[0], StreamingLineBuffer_12_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_0," << StreamingLineBuffer_12_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_8;
    StreamingConv_8.run<134>(StreamingLineBuffer_12_out0_stream, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_0," << StreamingConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_1," << StreamingConv_8_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_4;
    BandwidthAdjustDecreaseChannels_4.run<135>(StreamingConv_8_out0_stream, BandwidthAdjustDecreaseChannels_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_0," << BandwidthAdjustDecreaseChannels_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_1," << BandwidthAdjustDecreaseChannels_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_0;
    StreamingLineBuffer_13_pixel_0.run<136>(BandwidthAdjustDecreaseChannels_4_out0_stream[0], StreamingLineBuffer_13_out0_stream_prepad[11], StreamingLineBuffer_13_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_11," << StreamingLineBuffer_13_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_0," << StreamingLineBuffer_13_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_1;
    StreamingLineBuffer_13_pixel_1.run<137>(BandwidthAdjustDecreaseChannels_4_out0_stream[1], StreamingLineBuffer_13_out0_stream_prepad[10], StreamingLineBuffer_13_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_10," << StreamingLineBuffer_13_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_1," << StreamingLineBuffer_13_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_2;
    StreamingLineBuffer_13_pixel_2.run<138>(StreamingLineBuffer_13_buffer_stream[0], StreamingLineBuffer_13_out0_stream_prepad[9], StreamingLineBuffer_13_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_9," << StreamingLineBuffer_13_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_2," << StreamingLineBuffer_13_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_3;
    StreamingLineBuffer_13_pixel_3.run<139>(StreamingLineBuffer_13_buffer_stream[1], StreamingLineBuffer_13_out0_stream_prepad[8], StreamingLineBuffer_13_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_8," << StreamingLineBuffer_13_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_3," << StreamingLineBuffer_13_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_4;
    StreamingLineBuffer_13_pixel_4.run<140>(StreamingLineBuffer_13_buffer_stream[2], StreamingLineBuffer_13_out0_stream_prepad[7], StreamingLineBuffer_13_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_7," << StreamingLineBuffer_13_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_4," << StreamingLineBuffer_13_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_5;
    StreamingLineBuffer_13_pixel_5.run<141>(StreamingLineBuffer_13_buffer_stream[3], StreamingLineBuffer_13_out0_stream_prepad[6], StreamingLineBuffer_13_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_6," << StreamingLineBuffer_13_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_5," << StreamingLineBuffer_13_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_6;
    StreamingLineBuffer_13_pixel_6.run<142>(StreamingLineBuffer_13_buffer_stream[4], StreamingLineBuffer_13_out0_stream_prepad[5], StreamingLineBuffer_13_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_5," << StreamingLineBuffer_13_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_6," << StreamingLineBuffer_13_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_7;
    StreamingLineBuffer_13_pixel_7.run<143>(StreamingLineBuffer_13_buffer_stream[5], StreamingLineBuffer_13_out0_stream_prepad[4], StreamingLineBuffer_13_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_4," << StreamingLineBuffer_13_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_7," << StreamingLineBuffer_13_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_8;
    StreamingLineBuffer_13_pixel_8.run<144>(StreamingLineBuffer_13_buffer_stream[6], StreamingLineBuffer_13_out0_stream_prepad[3], StreamingLineBuffer_13_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_3," << StreamingLineBuffer_13_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_8," << StreamingLineBuffer_13_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_9;
    StreamingLineBuffer_13_pixel_9.run<145>(StreamingLineBuffer_13_buffer_stream[7], StreamingLineBuffer_13_out0_stream_prepad[2], StreamingLineBuffer_13_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_2," << StreamingLineBuffer_13_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_9," << StreamingLineBuffer_13_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_10;
    StreamingLineBuffer_13_pixel_10.run<146>(StreamingLineBuffer_13_buffer_stream[8], StreamingLineBuffer_13_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_1," << StreamingLineBuffer_13_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_11;
    StreamingLineBuffer_13_pixel_11.run<147>(StreamingLineBuffer_13_buffer_stream[9], StreamingLineBuffer_13_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_0," << StreamingLineBuffer_13_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_13_pad;
    StreamingLineBuffer_13_pad.run<148>(StreamingLineBuffer_13_out0_stream_prepad, StreamingLineBuffer_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_0," << StreamingLineBuffer_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_1," << StreamingLineBuffer_13_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_2," << StreamingLineBuffer_13_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_3," << StreamingLineBuffer_13_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_4," << StreamingLineBuffer_13_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_5," << StreamingLineBuffer_13_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_6," << StreamingLineBuffer_13_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_7," << StreamingLineBuffer_13_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_8," << StreamingLineBuffer_13_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_9," << StreamingLineBuffer_13_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_10," << StreamingLineBuffer_13_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_11," << StreamingLineBuffer_13_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_4;
    StreamingDepthwiseConv_4.run<149>(StreamingLineBuffer_13_out0_stream, StreamingDepthwiseConv_4_weights, StreamingDepthwiseConv_4_biases, StreamingDepthwiseConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_0," << StreamingDepthwiseConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_1," << StreamingDepthwiseConv_4_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_8;
    BandwidthAdjustIncreaseChannels_8.run<150>(StreamingDepthwiseConv_4_out0_stream, BandwidthAdjustIncreaseChannels_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_8_out0_stream_0," << BandwidthAdjustIncreaseChannels_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_8_out0_stream_1," << BandwidthAdjustIncreaseChannels_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_14_pixel_0;
    StreamingLineBuffer_14_pixel_0.run<151>(BandwidthAdjustIncreaseChannels_8_out0_stream[1], StreamingLineBuffer_14_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_1," << StreamingLineBuffer_14_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_14_pixel_1;
    StreamingLineBuffer_14_pixel_1.run<152>(BandwidthAdjustIncreaseChannels_8_out0_stream[0], StreamingLineBuffer_14_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_0," << StreamingLineBuffer_14_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_9;
    StreamingConv_9.run<153>(StreamingLineBuffer_14_out0_stream, StreamingConv_9_weights, StreamingConv_9_biases, StreamingConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_0," << StreamingConv_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_1," << StreamingConv_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_1;
    StreamingAdd_1.run<154>(BandwidthAdjustIncreaseChannels_7_out0_stream, StreamingConv_9_out0_stream, StreamingAdd_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_0," << StreamingAdd_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_1," << StreamingAdd_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_5;
    BandwidthAdjustDecreaseChannels_5.run<155>(StreamingAdd_1_out0_stream, BandwidthAdjustDecreaseChannels_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_0," << BandwidthAdjustDecreaseChannels_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_1," << BandwidthAdjustDecreaseChannels_5_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<156>(BandwidthAdjustDecreaseChannels_5_out0_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_0," << TensorDuplicator_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_1," << TensorDuplicator_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_0," << TensorDuplicator_2_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_1," << TensorDuplicator_2_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_9;
    BandwidthAdjustIncreaseChannels_9.run<157>(TensorDuplicator_2_out0_stream, BandwidthAdjustIncreaseChannels_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_9_out0_stream_0," << BandwidthAdjustIncreaseChannels_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_9_out0_stream_1," << BandwidthAdjustIncreaseChannels_9_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_10;
    BandwidthAdjustIncreaseChannels_10.run<158>(TensorDuplicator_2_out1_stream, BandwidthAdjustIncreaseChannels_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_10_out0_stream_0," << BandwidthAdjustIncreaseChannels_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_10_out0_stream_1," << BandwidthAdjustIncreaseChannels_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_15_pixel_0;
    StreamingLineBuffer_15_pixel_0.run<159>(BandwidthAdjustIncreaseChannels_9_out0_stream[1], StreamingLineBuffer_15_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_1," << StreamingLineBuffer_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_15_pixel_1;
    StreamingLineBuffer_15_pixel_1.run<160>(BandwidthAdjustIncreaseChannels_9_out0_stream[0], StreamingLineBuffer_15_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_0," << StreamingLineBuffer_15_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_10;
    StreamingConv_10.run<161>(StreamingLineBuffer_15_out0_stream, StreamingConv_10_weights, StreamingConv_10_biases, StreamingConv_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_0," << StreamingConv_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_1," << StreamingConv_10_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_6;
    BandwidthAdjustDecreaseChannels_6.run<162>(StreamingConv_10_out0_stream, BandwidthAdjustDecreaseChannels_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_0," << BandwidthAdjustDecreaseChannels_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_1," << BandwidthAdjustDecreaseChannels_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_0;
    StreamingLineBuffer_16_pixel_0.run<163>(BandwidthAdjustDecreaseChannels_6_out0_stream[0], StreamingLineBuffer_16_out0_stream_prepad[11], StreamingLineBuffer_16_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_11," << StreamingLineBuffer_16_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_0," << StreamingLineBuffer_16_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_1;
    StreamingLineBuffer_16_pixel_1.run<164>(BandwidthAdjustDecreaseChannels_6_out0_stream[1], StreamingLineBuffer_16_out0_stream_prepad[10], StreamingLineBuffer_16_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_10," << StreamingLineBuffer_16_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_1," << StreamingLineBuffer_16_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_2;
    StreamingLineBuffer_16_pixel_2.run<165>(StreamingLineBuffer_16_buffer_stream[0], StreamingLineBuffer_16_out0_stream_prepad[9], StreamingLineBuffer_16_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_9," << StreamingLineBuffer_16_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_2," << StreamingLineBuffer_16_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_3;
    StreamingLineBuffer_16_pixel_3.run<166>(StreamingLineBuffer_16_buffer_stream[1], StreamingLineBuffer_16_out0_stream_prepad[8], StreamingLineBuffer_16_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_8," << StreamingLineBuffer_16_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_3," << StreamingLineBuffer_16_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_4;
    StreamingLineBuffer_16_pixel_4.run<167>(StreamingLineBuffer_16_buffer_stream[2], StreamingLineBuffer_16_out0_stream_prepad[7], StreamingLineBuffer_16_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_7," << StreamingLineBuffer_16_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_4," << StreamingLineBuffer_16_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_5;
    StreamingLineBuffer_16_pixel_5.run<168>(StreamingLineBuffer_16_buffer_stream[3], StreamingLineBuffer_16_out0_stream_prepad[6], StreamingLineBuffer_16_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_6," << StreamingLineBuffer_16_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_5," << StreamingLineBuffer_16_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_6;
    StreamingLineBuffer_16_pixel_6.run<169>(StreamingLineBuffer_16_buffer_stream[4], StreamingLineBuffer_16_out0_stream_prepad[5], StreamingLineBuffer_16_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_5," << StreamingLineBuffer_16_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_6," << StreamingLineBuffer_16_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_7;
    StreamingLineBuffer_16_pixel_7.run<170>(StreamingLineBuffer_16_buffer_stream[5], StreamingLineBuffer_16_out0_stream_prepad[4], StreamingLineBuffer_16_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_4," << StreamingLineBuffer_16_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_7," << StreamingLineBuffer_16_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_8;
    StreamingLineBuffer_16_pixel_8.run<171>(StreamingLineBuffer_16_buffer_stream[6], StreamingLineBuffer_16_out0_stream_prepad[3], StreamingLineBuffer_16_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_3," << StreamingLineBuffer_16_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_8," << StreamingLineBuffer_16_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_9;
    StreamingLineBuffer_16_pixel_9.run<172>(StreamingLineBuffer_16_buffer_stream[7], StreamingLineBuffer_16_out0_stream_prepad[2], StreamingLineBuffer_16_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_2," << StreamingLineBuffer_16_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_9," << StreamingLineBuffer_16_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_10;
    StreamingLineBuffer_16_pixel_10.run<173>(StreamingLineBuffer_16_buffer_stream[8], StreamingLineBuffer_16_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_1," << StreamingLineBuffer_16_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_11;
    StreamingLineBuffer_16_pixel_11.run<174>(StreamingLineBuffer_16_buffer_stream[9], StreamingLineBuffer_16_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_0," << StreamingLineBuffer_16_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_16_pad;
    StreamingLineBuffer_16_pad.run<175>(StreamingLineBuffer_16_out0_stream_prepad, StreamingLineBuffer_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_0," << StreamingLineBuffer_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_1," << StreamingLineBuffer_16_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_2," << StreamingLineBuffer_16_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_3," << StreamingLineBuffer_16_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_4," << StreamingLineBuffer_16_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_5," << StreamingLineBuffer_16_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_6," << StreamingLineBuffer_16_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_7," << StreamingLineBuffer_16_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_8," << StreamingLineBuffer_16_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_9," << StreamingLineBuffer_16_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_10," << StreamingLineBuffer_16_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_11," << StreamingLineBuffer_16_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_5_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_5_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_5;
    StreamingDepthwiseConv_5.run<176>(StreamingLineBuffer_16_out0_stream, StreamingDepthwiseConv_5_weights, StreamingDepthwiseConv_5_biases, StreamingDepthwiseConv_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_5_out0_stream_0," << StreamingDepthwiseConv_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_5_out0_stream_1," << StreamingDepthwiseConv_5_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_11;
    BandwidthAdjustIncreaseChannels_11.run<177>(StreamingDepthwiseConv_5_out0_stream, BandwidthAdjustIncreaseChannels_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_11_out0_stream_0," << BandwidthAdjustIncreaseChannels_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_11_out0_stream_1," << BandwidthAdjustIncreaseChannels_11_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_17_pixel_0;
    StreamingLineBuffer_17_pixel_0.run<178>(BandwidthAdjustIncreaseChannels_11_out0_stream[1], StreamingLineBuffer_17_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_1," << StreamingLineBuffer_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_17_pixel_1;
    StreamingLineBuffer_17_pixel_1.run<179>(BandwidthAdjustIncreaseChannels_11_out0_stream[0], StreamingLineBuffer_17_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_0," << StreamingLineBuffer_17_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_11;
    StreamingConv_11.run<180>(StreamingLineBuffer_17_out0_stream, StreamingConv_11_weights, StreamingConv_11_biases, StreamingConv_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_0," << StreamingConv_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_1," << StreamingConv_11_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_2;
    StreamingAdd_2.run<181>(BandwidthAdjustIncreaseChannels_10_out0_stream, StreamingConv_11_out0_stream, StreamingAdd_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_0," << StreamingAdd_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_1," << StreamingAdd_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_0;
    StreamingLineBuffer_18_pixel_0.run<182>(StreamingAdd_2_out0_stream[1], StreamingLineBuffer_18_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_1," << StreamingLineBuffer_18_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_1;
    StreamingLineBuffer_18_pixel_1.run<183>(StreamingAdd_2_out0_stream[0], StreamingLineBuffer_18_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_0," << StreamingLineBuffer_18_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_12;
    StreamingConv_12.run<184>(StreamingLineBuffer_18_out0_stream, StreamingConv_12_weights, StreamingConv_12_biases, StreamingConv_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_0," << StreamingConv_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_1," << StreamingConv_12_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_7;
    BandwidthAdjustDecreaseChannels_7.run<185>(StreamingConv_12_out0_stream, BandwidthAdjustDecreaseChannels_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_7_out0_stream_0," << BandwidthAdjustDecreaseChannels_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_7_out0_stream_1," << BandwidthAdjustDecreaseChannels_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_0;
    StreamingLineBuffer_19_pixel_0.run<186>(BandwidthAdjustDecreaseChannels_7_out0_stream[1], StreamingLineBuffer_19_out0_stream_prepad[14], StreamingLineBuffer_19_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_14," << StreamingLineBuffer_19_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_0," << StreamingLineBuffer_19_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_1;
    StreamingLineBuffer_19_pixel_1.run<187>(BandwidthAdjustDecreaseChannels_7_out0_stream[0], StreamingLineBuffer_19_out0_stream_prepad[13], StreamingLineBuffer_19_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_13," << StreamingLineBuffer_19_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_1," << StreamingLineBuffer_19_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_2;
    StreamingLineBuffer_19_pixel_2.run<188>(StreamingLineBuffer_19_buffer_stream[0], StreamingLineBuffer_19_out0_stream_prepad[12], StreamingLineBuffer_19_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_12," << StreamingLineBuffer_19_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_2," << StreamingLineBuffer_19_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_3;
    StreamingLineBuffer_19_pixel_3.run<189>(StreamingLineBuffer_19_buffer_stream[1], StreamingLineBuffer_19_out0_stream_prepad[11], StreamingLineBuffer_19_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_11," << StreamingLineBuffer_19_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_4," << StreamingLineBuffer_19_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_4;
    StreamingLineBuffer_19_pixel_4.run<190>(StreamingLineBuffer_19_buffer_stream[2], StreamingLineBuffer_19_out0_stream_prepad[10], StreamingLineBuffer_19_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_10," << StreamingLineBuffer_19_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_3," << StreamingLineBuffer_19_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_6;
    StreamingLineBuffer_19_pixel_6.run<192>(StreamingLineBuffer_19_buffer_stream[4], StreamingLineBuffer_19_out0_stream_prepad[8], StreamingLineBuffer_19_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_8," << StreamingLineBuffer_19_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_6," << StreamingLineBuffer_19_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_5;
    StreamingLineBuffer_19_pixel_5.run<191>(StreamingLineBuffer_19_buffer_stream[3], StreamingLineBuffer_19_out0_stream_prepad[9], StreamingLineBuffer_19_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_9," << StreamingLineBuffer_19_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_5," << StreamingLineBuffer_19_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_8;
    StreamingLineBuffer_19_pixel_8.run<194>(StreamingLineBuffer_19_buffer_stream[6], StreamingLineBuffer_19_out0_stream_prepad[6], StreamingLineBuffer_19_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_6," << StreamingLineBuffer_19_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_9," << StreamingLineBuffer_19_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_7;
    StreamingLineBuffer_19_pixel_7.run<193>(StreamingLineBuffer_19_buffer_stream[5], StreamingLineBuffer_19_out0_stream_prepad[7], StreamingLineBuffer_19_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_7," << StreamingLineBuffer_19_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_7," << StreamingLineBuffer_19_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_11;
    StreamingLineBuffer_19_pixel_11.run<197>(StreamingLineBuffer_19_buffer_stream[9], StreamingLineBuffer_19_out0_stream_prepad[3], StreamingLineBuffer_19_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_3," << StreamingLineBuffer_19_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_11," << StreamingLineBuffer_19_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_9;
    StreamingLineBuffer_19_pixel_9.run<195>(StreamingLineBuffer_19_buffer_stream[7], StreamingLineBuffer_19_out0_stream_prepad[5], StreamingLineBuffer_19_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_5," << StreamingLineBuffer_19_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_8," << StreamingLineBuffer_19_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_13;
    StreamingLineBuffer_19_pixel_13.run<199>(StreamingLineBuffer_19_buffer_stream[11], StreamingLineBuffer_19_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_1," << StreamingLineBuffer_19_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_10;
    StreamingLineBuffer_19_pixel_10.run<196>(StreamingLineBuffer_19_buffer_stream[8], StreamingLineBuffer_19_out0_stream_prepad[4], StreamingLineBuffer_19_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_4," << StreamingLineBuffer_19_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_10," << StreamingLineBuffer_19_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_12;
    StreamingLineBuffer_19_pixel_12.run<198>(StreamingLineBuffer_19_buffer_stream[10], StreamingLineBuffer_19_out0_stream_prepad[2], StreamingLineBuffer_19_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_2," << StreamingLineBuffer_19_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_12," << StreamingLineBuffer_19_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_14;
    StreamingLineBuffer_19_pixel_14.run<200>(StreamingLineBuffer_19_buffer_stream[12], StreamingLineBuffer_19_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_0," << StreamingLineBuffer_19_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_19_pad;
    StreamingLineBuffer_19_pad.run<201>(StreamingLineBuffer_19_out0_stream_prepad, StreamingLineBuffer_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_0," << StreamingLineBuffer_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_1," << StreamingLineBuffer_19_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_2," << StreamingLineBuffer_19_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_3," << StreamingLineBuffer_19_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_4," << StreamingLineBuffer_19_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_5," << StreamingLineBuffer_19_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_6," << StreamingLineBuffer_19_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_7," << StreamingLineBuffer_19_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_8," << StreamingLineBuffer_19_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_9," << StreamingLineBuffer_19_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_10," << StreamingLineBuffer_19_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_11," << StreamingLineBuffer_19_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_12," << StreamingLineBuffer_19_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_13," << StreamingLineBuffer_19_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_14," << StreamingLineBuffer_19_out0_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_6_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_6_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_6_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_6_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_6;
    StreamingDepthwiseConv_6.run<202>(StreamingLineBuffer_19_out0_stream, StreamingDepthwiseConv_6_weights, StreamingDepthwiseConv_6_biases, StreamingDepthwiseConv_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_6_out0_stream_0," << StreamingDepthwiseConv_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_6_out0_stream_1," << StreamingDepthwiseConv_6_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_12;
    BandwidthAdjustIncreaseChannels_12.run<203>(StreamingDepthwiseConv_6_out0_stream, BandwidthAdjustIncreaseChannels_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_12_out0_stream_0," << BandwidthAdjustIncreaseChannels_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_12_out0_stream_1," << BandwidthAdjustIncreaseChannels_12_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        3,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_1;
    BandwidthAdjustDecreaseStreams_1.run<204>(BandwidthAdjustIncreaseChannels_12_out0_stream, BandwidthAdjustDecreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_1_out0_stream_0," << BandwidthAdjustDecreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        192,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_13;
    StreamingConv_13.run<205>(BandwidthAdjustDecreaseStreams_1_out0_stream, StreamingConv_13_weights, StreamingConv_13_biases, StreamingConv_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_13_out0_stream_0," << StreamingConv_13_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_3;
    TensorDuplicator_3.run<206>(StreamingConv_13_out0_stream, TensorDuplicator_3_out0_stream, TensorDuplicator_3_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out0_stream_0," << TensorDuplicator_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out1_stream_0," << TensorDuplicator_3_out1_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_1;
    BandwidthAdjustIncreaseStreams_1.run<207>(TensorDuplicator_3_out0_stream, BandwidthAdjustIncreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_1_out0_stream_0," << BandwidthAdjustIncreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_1_out0_stream_1," << BandwidthAdjustIncreaseStreams_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_2;
    BandwidthAdjustIncreaseStreams_2.run<208>(TensorDuplicator_3_out1_stream, BandwidthAdjustIncreaseStreams_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_2_out0_stream_0," << BandwidthAdjustIncreaseStreams_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_2_out0_stream_1," << BandwidthAdjustIncreaseStreams_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_0;
    StreamingLineBuffer_20_pixel_0.run<209>(BandwidthAdjustIncreaseStreams_1_out0_stream[1], StreamingLineBuffer_20_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_1," << StreamingLineBuffer_20_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_1;
    StreamingLineBuffer_20_pixel_1.run<210>(BandwidthAdjustIncreaseStreams_1_out0_stream[0], StreamingLineBuffer_20_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_0," << StreamingLineBuffer_20_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_14;
    StreamingConv_14.run<211>(StreamingLineBuffer_20_out0_stream, StreamingConv_14_weights, StreamingConv_14_biases, StreamingConv_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_0," << StreamingConv_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_1," << StreamingConv_14_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_8;
    BandwidthAdjustDecreaseChannels_8.run<212>(StreamingConv_14_out0_stream, BandwidthAdjustDecreaseChannels_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_8_out0_stream_0," << BandwidthAdjustDecreaseChannels_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_8_out0_stream_1," << BandwidthAdjustDecreaseChannels_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_0;
    StreamingLineBuffer_21_pixel_0.run<213>(BandwidthAdjustDecreaseChannels_8_out0_stream[0], StreamingLineBuffer_21_out0_stream_prepad[11], StreamingLineBuffer_21_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_11," << StreamingLineBuffer_21_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_0," << StreamingLineBuffer_21_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_1;
    StreamingLineBuffer_21_pixel_1.run<214>(BandwidthAdjustDecreaseChannels_8_out0_stream[1], StreamingLineBuffer_21_out0_stream_prepad[10], StreamingLineBuffer_21_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_10," << StreamingLineBuffer_21_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_1," << StreamingLineBuffer_21_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_2;
    StreamingLineBuffer_21_pixel_2.run<215>(StreamingLineBuffer_21_buffer_stream[0], StreamingLineBuffer_21_out0_stream_prepad[9], StreamingLineBuffer_21_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_9," << StreamingLineBuffer_21_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_2," << StreamingLineBuffer_21_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_3;
    StreamingLineBuffer_21_pixel_3.run<216>(StreamingLineBuffer_21_buffer_stream[1], StreamingLineBuffer_21_out0_stream_prepad[8], StreamingLineBuffer_21_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_8," << StreamingLineBuffer_21_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_3," << StreamingLineBuffer_21_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_4;
    StreamingLineBuffer_21_pixel_4.run<217>(StreamingLineBuffer_21_buffer_stream[2], StreamingLineBuffer_21_out0_stream_prepad[7], StreamingLineBuffer_21_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_7," << StreamingLineBuffer_21_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_4," << StreamingLineBuffer_21_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_5;
    StreamingLineBuffer_21_pixel_5.run<218>(StreamingLineBuffer_21_buffer_stream[3], StreamingLineBuffer_21_out0_stream_prepad[6], StreamingLineBuffer_21_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_6," << StreamingLineBuffer_21_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_5," << StreamingLineBuffer_21_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_6;
    StreamingLineBuffer_21_pixel_6.run<219>(StreamingLineBuffer_21_buffer_stream[4], StreamingLineBuffer_21_out0_stream_prepad[5], StreamingLineBuffer_21_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_5," << StreamingLineBuffer_21_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_6," << StreamingLineBuffer_21_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_7;
    StreamingLineBuffer_21_pixel_7.run<220>(StreamingLineBuffer_21_buffer_stream[5], StreamingLineBuffer_21_out0_stream_prepad[4], StreamingLineBuffer_21_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_4," << StreamingLineBuffer_21_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_7," << StreamingLineBuffer_21_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_8;
    StreamingLineBuffer_21_pixel_8.run<221>(StreamingLineBuffer_21_buffer_stream[6], StreamingLineBuffer_21_out0_stream_prepad[3], StreamingLineBuffer_21_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_3," << StreamingLineBuffer_21_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_8," << StreamingLineBuffer_21_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_9;
    StreamingLineBuffer_21_pixel_9.run<222>(StreamingLineBuffer_21_buffer_stream[7], StreamingLineBuffer_21_out0_stream_prepad[2], StreamingLineBuffer_21_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_2," << StreamingLineBuffer_21_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_9," << StreamingLineBuffer_21_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_10;
    StreamingLineBuffer_21_pixel_10.run<223>(StreamingLineBuffer_21_buffer_stream[8], StreamingLineBuffer_21_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_1," << StreamingLineBuffer_21_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_11;
    StreamingLineBuffer_21_pixel_11.run<224>(StreamingLineBuffer_21_buffer_stream[9], StreamingLineBuffer_21_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_prepad_0," << StreamingLineBuffer_21_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_21_pad;
    StreamingLineBuffer_21_pad.run<225>(StreamingLineBuffer_21_out0_stream_prepad, StreamingLineBuffer_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_0," << StreamingLineBuffer_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_1," << StreamingLineBuffer_21_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_2," << StreamingLineBuffer_21_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_3," << StreamingLineBuffer_21_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_4," << StreamingLineBuffer_21_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_5," << StreamingLineBuffer_21_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_6," << StreamingLineBuffer_21_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_7," << StreamingLineBuffer_21_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_8," << StreamingLineBuffer_21_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_9," << StreamingLineBuffer_21_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_10," << StreamingLineBuffer_21_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_11," << StreamingLineBuffer_21_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_7_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_7_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_7;
    StreamingDepthwiseConv_7.run<226>(StreamingLineBuffer_21_out0_stream, StreamingDepthwiseConv_7_weights, StreamingDepthwiseConv_7_biases, StreamingDepthwiseConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_7_out0_stream_0," << StreamingDepthwiseConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_7_out0_stream_1," << StreamingDepthwiseConv_7_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_13;
    BandwidthAdjustIncreaseChannels_13.run<227>(StreamingDepthwiseConv_7_out0_stream, BandwidthAdjustIncreaseChannels_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_13_out0_stream_0," << BandwidthAdjustIncreaseChannels_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_13_out0_stream_1," << BandwidthAdjustIncreaseChannels_13_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_22_pixel_0;
    StreamingLineBuffer_22_pixel_0.run<228>(BandwidthAdjustIncreaseChannels_13_out0_stream[1], StreamingLineBuffer_22_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_1," << StreamingLineBuffer_22_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_22_pixel_1;
    StreamingLineBuffer_22_pixel_1.run<229>(BandwidthAdjustIncreaseChannels_13_out0_stream[0], StreamingLineBuffer_22_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_0," << StreamingLineBuffer_22_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_15;
    StreamingConv_15.run<230>(StreamingLineBuffer_22_out0_stream, StreamingConv_15_weights, StreamingConv_15_biases, StreamingConv_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_0," << StreamingConv_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_1," << StreamingConv_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_3;
    StreamingAdd_3.run<231>(BandwidthAdjustIncreaseStreams_2_out0_stream, StreamingConv_15_out0_stream, StreamingAdd_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_0," << StreamingAdd_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_1," << StreamingAdd_3_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_2;
    BandwidthAdjustDecreaseStreams_2.run<232>(StreamingAdd_3_out0_stream, BandwidthAdjustDecreaseStreams_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_2_out0_stream_0," << BandwidthAdjustDecreaseStreams_2_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_4;
    TensorDuplicator_4.run<233>(BandwidthAdjustDecreaseStreams_2_out0_stream, TensorDuplicator_4_out0_stream, TensorDuplicator_4_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out0_stream_0," << TensorDuplicator_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out1_stream_0," << TensorDuplicator_4_out1_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_3;
    BandwidthAdjustIncreaseStreams_3.run<234>(TensorDuplicator_4_out0_stream, BandwidthAdjustIncreaseStreams_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_3_out0_stream_0," << BandwidthAdjustIncreaseStreams_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_3_out0_stream_1," << BandwidthAdjustIncreaseStreams_3_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_4;
    BandwidthAdjustIncreaseStreams_4.run<235>(TensorDuplicator_4_out1_stream, BandwidthAdjustIncreaseStreams_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_4_out0_stream_0," << BandwidthAdjustIncreaseStreams_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_4_out0_stream_1," << BandwidthAdjustIncreaseStreams_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_23_pixel_0;
    StreamingLineBuffer_23_pixel_0.run<236>(BandwidthAdjustIncreaseStreams_3_out0_stream[1], StreamingLineBuffer_23_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_23_out0_stream_1," << StreamingLineBuffer_23_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_23_pixel_1;
    StreamingLineBuffer_23_pixel_1.run<237>(BandwidthAdjustIncreaseStreams_3_out0_stream[0], StreamingLineBuffer_23_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_23_out0_stream_0," << StreamingLineBuffer_23_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_16;
    StreamingConv_16.run<238>(StreamingLineBuffer_23_out0_stream, StreamingConv_16_weights, StreamingConv_16_biases, StreamingConv_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_0," << StreamingConv_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_1," << StreamingConv_16_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_9;
    BandwidthAdjustDecreaseChannels_9.run<239>(StreamingConv_16_out0_stream, BandwidthAdjustDecreaseChannels_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_9_out0_stream_0," << BandwidthAdjustDecreaseChannels_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_9_out0_stream_1," << BandwidthAdjustDecreaseChannels_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_0;
    StreamingLineBuffer_24_pixel_0.run<240>(BandwidthAdjustDecreaseChannels_9_out0_stream[0], StreamingLineBuffer_24_out0_stream_prepad[11], StreamingLineBuffer_24_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_11," << StreamingLineBuffer_24_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_0," << StreamingLineBuffer_24_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_1;
    StreamingLineBuffer_24_pixel_1.run<241>(BandwidthAdjustDecreaseChannels_9_out0_stream[1], StreamingLineBuffer_24_out0_stream_prepad[10], StreamingLineBuffer_24_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_10," << StreamingLineBuffer_24_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_1," << StreamingLineBuffer_24_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_2;
    StreamingLineBuffer_24_pixel_2.run<242>(StreamingLineBuffer_24_buffer_stream[0], StreamingLineBuffer_24_out0_stream_prepad[9], StreamingLineBuffer_24_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_9," << StreamingLineBuffer_24_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_2," << StreamingLineBuffer_24_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_3;
    StreamingLineBuffer_24_pixel_3.run<243>(StreamingLineBuffer_24_buffer_stream[1], StreamingLineBuffer_24_out0_stream_prepad[8], StreamingLineBuffer_24_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_8," << StreamingLineBuffer_24_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_3," << StreamingLineBuffer_24_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_4;
    StreamingLineBuffer_24_pixel_4.run<244>(StreamingLineBuffer_24_buffer_stream[2], StreamingLineBuffer_24_out0_stream_prepad[7], StreamingLineBuffer_24_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_7," << StreamingLineBuffer_24_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_4," << StreamingLineBuffer_24_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_5;
    StreamingLineBuffer_24_pixel_5.run<245>(StreamingLineBuffer_24_buffer_stream[3], StreamingLineBuffer_24_out0_stream_prepad[6], StreamingLineBuffer_24_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_6," << StreamingLineBuffer_24_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_5," << StreamingLineBuffer_24_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_6;
    StreamingLineBuffer_24_pixel_6.run<246>(StreamingLineBuffer_24_buffer_stream[4], StreamingLineBuffer_24_out0_stream_prepad[5], StreamingLineBuffer_24_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_5," << StreamingLineBuffer_24_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_6," << StreamingLineBuffer_24_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_7;
    StreamingLineBuffer_24_pixel_7.run<247>(StreamingLineBuffer_24_buffer_stream[5], StreamingLineBuffer_24_out0_stream_prepad[4], StreamingLineBuffer_24_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_4," << StreamingLineBuffer_24_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_7," << StreamingLineBuffer_24_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_8;
    StreamingLineBuffer_24_pixel_8.run<248>(StreamingLineBuffer_24_buffer_stream[6], StreamingLineBuffer_24_out0_stream_prepad[3], StreamingLineBuffer_24_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_3," << StreamingLineBuffer_24_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_8," << StreamingLineBuffer_24_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_9;
    StreamingLineBuffer_24_pixel_9.run<249>(StreamingLineBuffer_24_buffer_stream[7], StreamingLineBuffer_24_out0_stream_prepad[2], StreamingLineBuffer_24_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_2," << StreamingLineBuffer_24_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_9," << StreamingLineBuffer_24_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_10;
    StreamingLineBuffer_24_pixel_10.run<250>(StreamingLineBuffer_24_buffer_stream[8], StreamingLineBuffer_24_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_1," << StreamingLineBuffer_24_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_11;
    StreamingLineBuffer_24_pixel_11.run<251>(StreamingLineBuffer_24_buffer_stream[9], StreamingLineBuffer_24_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_0," << StreamingLineBuffer_24_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_24_pad;
    StreamingLineBuffer_24_pad.run<252>(StreamingLineBuffer_24_out0_stream_prepad, StreamingLineBuffer_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_0," << StreamingLineBuffer_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_1," << StreamingLineBuffer_24_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_2," << StreamingLineBuffer_24_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_3," << StreamingLineBuffer_24_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_4," << StreamingLineBuffer_24_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_5," << StreamingLineBuffer_24_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_6," << StreamingLineBuffer_24_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_7," << StreamingLineBuffer_24_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_8," << StreamingLineBuffer_24_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_9," << StreamingLineBuffer_24_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_10," << StreamingLineBuffer_24_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_11," << StreamingLineBuffer_24_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_8_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_8_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_8;
    StreamingDepthwiseConv_8.run<253>(StreamingLineBuffer_24_out0_stream, StreamingDepthwiseConv_8_weights, StreamingDepthwiseConv_8_biases, StreamingDepthwiseConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_8_out0_stream_0," << StreamingDepthwiseConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_8_out0_stream_1," << StreamingDepthwiseConv_8_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_14;
    BandwidthAdjustIncreaseChannels_14.run<254>(StreamingDepthwiseConv_8_out0_stream, BandwidthAdjustIncreaseChannels_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_14_out0_stream_0," << BandwidthAdjustIncreaseChannels_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_14_out0_stream_1," << BandwidthAdjustIncreaseChannels_14_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_25_pixel_0;
    StreamingLineBuffer_25_pixel_0.run<255>(BandwidthAdjustIncreaseChannels_14_out0_stream[1], StreamingLineBuffer_25_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_1," << StreamingLineBuffer_25_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_25_pixel_1;
    StreamingLineBuffer_25_pixel_1.run<256>(BandwidthAdjustIncreaseChannels_14_out0_stream[0], StreamingLineBuffer_25_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_0," << StreamingLineBuffer_25_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_17;
    StreamingConv_17.run<257>(StreamingLineBuffer_25_out0_stream, StreamingConv_17_weights, StreamingConv_17_biases, StreamingConv_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_0," << StreamingConv_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_1," << StreamingConv_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_4;
    StreamingAdd_4.run<258>(BandwidthAdjustIncreaseStreams_4_out0_stream, StreamingConv_17_out0_stream, StreamingAdd_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_0," << StreamingAdd_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_1," << StreamingAdd_4_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_3;
    BandwidthAdjustDecreaseStreams_3.run<259>(StreamingAdd_4_out0_stream, BandwidthAdjustDecreaseStreams_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_3_out0_stream_0," << BandwidthAdjustDecreaseStreams_3_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_5;
    TensorDuplicator_5.run<260>(BandwidthAdjustDecreaseStreams_3_out0_stream, TensorDuplicator_5_out0_stream, TensorDuplicator_5_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out0_stream_0," << TensorDuplicator_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out1_stream_0," << TensorDuplicator_5_out1_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_5;
    BandwidthAdjustIncreaseStreams_5.run<261>(TensorDuplicator_5_out0_stream, BandwidthAdjustIncreaseStreams_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_5_out0_stream_0," << BandwidthAdjustIncreaseStreams_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_5_out0_stream_1," << BandwidthAdjustIncreaseStreams_5_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_6;
    BandwidthAdjustIncreaseStreams_6.run<262>(TensorDuplicator_5_out1_stream, BandwidthAdjustIncreaseStreams_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_6_out0_stream_0," << BandwidthAdjustIncreaseStreams_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_6_out0_stream_1," << BandwidthAdjustIncreaseStreams_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_26_pixel_0;
    StreamingLineBuffer_26_pixel_0.run<263>(BandwidthAdjustIncreaseStreams_5_out0_stream[1], StreamingLineBuffer_26_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_26_out0_stream_1," << StreamingLineBuffer_26_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_26_pixel_1;
    StreamingLineBuffer_26_pixel_1.run<264>(BandwidthAdjustIncreaseStreams_5_out0_stream[0], StreamingLineBuffer_26_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_26_out0_stream_0," << StreamingLineBuffer_26_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_18;
    StreamingConv_18.run<265>(StreamingLineBuffer_26_out0_stream, StreamingConv_18_weights, StreamingConv_18_biases, StreamingConv_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_0," << StreamingConv_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_1," << StreamingConv_18_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_10;
    BandwidthAdjustDecreaseChannels_10.run<266>(StreamingConv_18_out0_stream, BandwidthAdjustDecreaseChannels_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_10_out0_stream_0," << BandwidthAdjustDecreaseChannels_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_10_out0_stream_1," << BandwidthAdjustDecreaseChannels_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_0;
    StreamingLineBuffer_27_pixel_0.run<267>(BandwidthAdjustDecreaseChannels_10_out0_stream[0], StreamingLineBuffer_27_out0_stream_prepad[11], StreamingLineBuffer_27_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_11," << StreamingLineBuffer_27_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_0," << StreamingLineBuffer_27_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_1;
    StreamingLineBuffer_27_pixel_1.run<268>(BandwidthAdjustDecreaseChannels_10_out0_stream[1], StreamingLineBuffer_27_out0_stream_prepad[10], StreamingLineBuffer_27_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_10," << StreamingLineBuffer_27_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_1," << StreamingLineBuffer_27_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_2;
    StreamingLineBuffer_27_pixel_2.run<269>(StreamingLineBuffer_27_buffer_stream[0], StreamingLineBuffer_27_out0_stream_prepad[9], StreamingLineBuffer_27_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_9," << StreamingLineBuffer_27_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_2," << StreamingLineBuffer_27_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_3;
    StreamingLineBuffer_27_pixel_3.run<270>(StreamingLineBuffer_27_buffer_stream[1], StreamingLineBuffer_27_out0_stream_prepad[8], StreamingLineBuffer_27_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_8," << StreamingLineBuffer_27_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_3," << StreamingLineBuffer_27_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_4;
    StreamingLineBuffer_27_pixel_4.run<271>(StreamingLineBuffer_27_buffer_stream[2], StreamingLineBuffer_27_out0_stream_prepad[7], StreamingLineBuffer_27_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_7," << StreamingLineBuffer_27_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_4," << StreamingLineBuffer_27_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_5;
    StreamingLineBuffer_27_pixel_5.run<272>(StreamingLineBuffer_27_buffer_stream[3], StreamingLineBuffer_27_out0_stream_prepad[6], StreamingLineBuffer_27_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_6," << StreamingLineBuffer_27_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_5," << StreamingLineBuffer_27_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_6;
    StreamingLineBuffer_27_pixel_6.run<273>(StreamingLineBuffer_27_buffer_stream[4], StreamingLineBuffer_27_out0_stream_prepad[5], StreamingLineBuffer_27_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_5," << StreamingLineBuffer_27_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_6," << StreamingLineBuffer_27_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_7;
    StreamingLineBuffer_27_pixel_7.run<274>(StreamingLineBuffer_27_buffer_stream[5], StreamingLineBuffer_27_out0_stream_prepad[4], StreamingLineBuffer_27_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_4," << StreamingLineBuffer_27_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_7," << StreamingLineBuffer_27_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_8;
    StreamingLineBuffer_27_pixel_8.run<275>(StreamingLineBuffer_27_buffer_stream[6], StreamingLineBuffer_27_out0_stream_prepad[3], StreamingLineBuffer_27_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_3," << StreamingLineBuffer_27_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_8," << StreamingLineBuffer_27_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_9;
    StreamingLineBuffer_27_pixel_9.run<276>(StreamingLineBuffer_27_buffer_stream[7], StreamingLineBuffer_27_out0_stream_prepad[2], StreamingLineBuffer_27_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_2," << StreamingLineBuffer_27_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_buffer_stream_9," << StreamingLineBuffer_27_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_10;
    StreamingLineBuffer_27_pixel_10.run<277>(StreamingLineBuffer_27_buffer_stream[8], StreamingLineBuffer_27_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_1," << StreamingLineBuffer_27_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_11;
    StreamingLineBuffer_27_pixel_11.run<278>(StreamingLineBuffer_27_buffer_stream[9], StreamingLineBuffer_27_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_prepad_0," << StreamingLineBuffer_27_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_27_pad;
    StreamingLineBuffer_27_pad.run<279>(StreamingLineBuffer_27_out0_stream_prepad, StreamingLineBuffer_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_0," << StreamingLineBuffer_27_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_1," << StreamingLineBuffer_27_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_2," << StreamingLineBuffer_27_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_3," << StreamingLineBuffer_27_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_4," << StreamingLineBuffer_27_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_5," << StreamingLineBuffer_27_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_6," << StreamingLineBuffer_27_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_7," << StreamingLineBuffer_27_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_8," << StreamingLineBuffer_27_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_9," << StreamingLineBuffer_27_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_10," << StreamingLineBuffer_27_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_11," << StreamingLineBuffer_27_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_9_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_9_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_9;
    StreamingDepthwiseConv_9.run<280>(StreamingLineBuffer_27_out0_stream, StreamingDepthwiseConv_9_weights, StreamingDepthwiseConv_9_biases, StreamingDepthwiseConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_9_out0_stream_0," << StreamingDepthwiseConv_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_9_out0_stream_1," << StreamingDepthwiseConv_9_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_15;
    BandwidthAdjustIncreaseChannels_15.run<281>(StreamingDepthwiseConv_9_out0_stream, BandwidthAdjustIncreaseChannels_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_15_out0_stream_0," << BandwidthAdjustIncreaseChannels_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_15_out0_stream_1," << BandwidthAdjustIncreaseChannels_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_28_pixel_0;
    StreamingLineBuffer_28_pixel_0.run<282>(BandwidthAdjustIncreaseChannels_15_out0_stream[1], StreamingLineBuffer_28_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_1," << StreamingLineBuffer_28_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_28_pixel_1;
    StreamingLineBuffer_28_pixel_1.run<283>(BandwidthAdjustIncreaseChannels_15_out0_stream[0], StreamingLineBuffer_28_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_0," << StreamingLineBuffer_28_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_19;
    StreamingConv_19.run<284>(StreamingLineBuffer_28_out0_stream, StreamingConv_19_weights, StreamingConv_19_biases, StreamingConv_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_0," << StreamingConv_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_1," << StreamingConv_19_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_5;
    StreamingAdd_5.run<285>(BandwidthAdjustIncreaseStreams_6_out0_stream, StreamingConv_19_out0_stream, StreamingAdd_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_0," << StreamingAdd_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_1," << StreamingAdd_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_29_pixel_0;
    StreamingLineBuffer_29_pixel_0.run<286>(StreamingAdd_5_out0_stream[1], StreamingLineBuffer_29_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_1," << StreamingLineBuffer_29_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_29_pixel_1;
    StreamingLineBuffer_29_pixel_1.run<287>(StreamingAdd_5_out0_stream[0], StreamingLineBuffer_29_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_0," << StreamingLineBuffer_29_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_20;
    StreamingConv_20.run<288>(StreamingLineBuffer_29_out0_stream, StreamingConv_20_weights, StreamingConv_20_biases, StreamingConv_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_20_out0_stream_0," << StreamingConv_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_20_out0_stream_1," << StreamingConv_20_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_11;
    BandwidthAdjustDecreaseChannels_11.run<289>(StreamingConv_20_out0_stream, BandwidthAdjustDecreaseChannels_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_11_out0_stream_0," << BandwidthAdjustDecreaseChannels_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_11_out0_stream_1," << BandwidthAdjustDecreaseChannels_11_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_0;
    StreamingLineBuffer_30_pixel_0.run<290>(BandwidthAdjustDecreaseChannels_11_out0_stream[0], StreamingLineBuffer_30_out0_stream_prepad[11], StreamingLineBuffer_30_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_11," << StreamingLineBuffer_30_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_0," << StreamingLineBuffer_30_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_1;
    StreamingLineBuffer_30_pixel_1.run<291>(BandwidthAdjustDecreaseChannels_11_out0_stream[1], StreamingLineBuffer_30_out0_stream_prepad[10], StreamingLineBuffer_30_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_10," << StreamingLineBuffer_30_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_1," << StreamingLineBuffer_30_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_2;
    StreamingLineBuffer_30_pixel_2.run<292>(StreamingLineBuffer_30_buffer_stream[0], StreamingLineBuffer_30_out0_stream_prepad[9], StreamingLineBuffer_30_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_9," << StreamingLineBuffer_30_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_2," << StreamingLineBuffer_30_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_3;
    StreamingLineBuffer_30_pixel_3.run<293>(StreamingLineBuffer_30_buffer_stream[1], StreamingLineBuffer_30_out0_stream_prepad[8], StreamingLineBuffer_30_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_8," << StreamingLineBuffer_30_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_3," << StreamingLineBuffer_30_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_4;
    StreamingLineBuffer_30_pixel_4.run<294>(StreamingLineBuffer_30_buffer_stream[2], StreamingLineBuffer_30_out0_stream_prepad[7], StreamingLineBuffer_30_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_7," << StreamingLineBuffer_30_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_4," << StreamingLineBuffer_30_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_5;
    StreamingLineBuffer_30_pixel_5.run<295>(StreamingLineBuffer_30_buffer_stream[3], StreamingLineBuffer_30_out0_stream_prepad[6], StreamingLineBuffer_30_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_6," << StreamingLineBuffer_30_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_5," << StreamingLineBuffer_30_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_6;
    StreamingLineBuffer_30_pixel_6.run<296>(StreamingLineBuffer_30_buffer_stream[4], StreamingLineBuffer_30_out0_stream_prepad[5], StreamingLineBuffer_30_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_5," << StreamingLineBuffer_30_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_6," << StreamingLineBuffer_30_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_7;
    StreamingLineBuffer_30_pixel_7.run<297>(StreamingLineBuffer_30_buffer_stream[5], StreamingLineBuffer_30_out0_stream_prepad[4], StreamingLineBuffer_30_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_4," << StreamingLineBuffer_30_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_7," << StreamingLineBuffer_30_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_8;
    StreamingLineBuffer_30_pixel_8.run<298>(StreamingLineBuffer_30_buffer_stream[6], StreamingLineBuffer_30_out0_stream_prepad[3], StreamingLineBuffer_30_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_3," << StreamingLineBuffer_30_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_8," << StreamingLineBuffer_30_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_9;
    StreamingLineBuffer_30_pixel_9.run<299>(StreamingLineBuffer_30_buffer_stream[7], StreamingLineBuffer_30_out0_stream_prepad[2], StreamingLineBuffer_30_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_2," << StreamingLineBuffer_30_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_9," << StreamingLineBuffer_30_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_10;
    StreamingLineBuffer_30_pixel_10.run<300>(StreamingLineBuffer_30_buffer_stream[8], StreamingLineBuffer_30_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_1," << StreamingLineBuffer_30_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_11;
    StreamingLineBuffer_30_pixel_11.run<301>(StreamingLineBuffer_30_buffer_stream[9], StreamingLineBuffer_30_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_0," << StreamingLineBuffer_30_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_30_pad;
    StreamingLineBuffer_30_pad.run<302>(StreamingLineBuffer_30_out0_stream_prepad, StreamingLineBuffer_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_0," << StreamingLineBuffer_30_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_1," << StreamingLineBuffer_30_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_2," << StreamingLineBuffer_30_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_3," << StreamingLineBuffer_30_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_4," << StreamingLineBuffer_30_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_5," << StreamingLineBuffer_30_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_6," << StreamingLineBuffer_30_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_7," << StreamingLineBuffer_30_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_8," << StreamingLineBuffer_30_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_9," << StreamingLineBuffer_30_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_10," << StreamingLineBuffer_30_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_11," << StreamingLineBuffer_30_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_10_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_10_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_10;
    StreamingDepthwiseConv_10.run<303>(StreamingLineBuffer_30_out0_stream, StreamingDepthwiseConv_10_weights, StreamingDepthwiseConv_10_biases, StreamingDepthwiseConv_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_10_out0_stream_0," << StreamingDepthwiseConv_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_10_out0_stream_1," << StreamingDepthwiseConv_10_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_16;
    BandwidthAdjustIncreaseChannels_16.run<304>(StreamingDepthwiseConv_10_out0_stream, BandwidthAdjustIncreaseChannels_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_16_out0_stream_0," << BandwidthAdjustIncreaseChannels_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_16_out0_stream_1," << BandwidthAdjustIncreaseChannels_16_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        6  // CH_PAR
    > StreamingLineBuffer_31_pixel_0;
    StreamingLineBuffer_31_pixel_0.run<305>(BandwidthAdjustIncreaseChannels_16_out0_stream[1], StreamingLineBuffer_31_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_31_out0_stream_1," << StreamingLineBuffer_31_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        6  // CH_PAR
    > StreamingLineBuffer_31_pixel_1;
    StreamingLineBuffer_31_pixel_1.run<306>(BandwidthAdjustIncreaseChannels_16_out0_stream[0], StreamingLineBuffer_31_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_31_out0_stream_0," << StreamingLineBuffer_31_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 18>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<10, ap_int<27>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_21;
    StreamingConv_21.run<307>(StreamingLineBuffer_31_out0_stream, StreamingConv_21_weights, StreamingConv_21_biases, StreamingConv_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_21_out0_stream_0," << StreamingConv_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_21_out0_stream_1," << StreamingConv_21_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        3,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_6;
    TensorDuplicator_6.run<308>(StreamingConv_21_out0_stream, TensorDuplicator_6_out0_stream, TensorDuplicator_6_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_6_out0_stream_0," << TensorDuplicator_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_6_out0_stream_1," << TensorDuplicator_6_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_6_out1_stream_0," << TensorDuplicator_6_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_6_out1_stream_1," << TensorDuplicator_6_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        12  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_17;
    BandwidthAdjustIncreaseChannels_17.run<309>(TensorDuplicator_6_out0_stream, BandwidthAdjustIncreaseChannels_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_17_out0_stream_0," << BandwidthAdjustIncreaseChannels_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_17_out0_stream_1," << BandwidthAdjustIncreaseChannels_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_32_pixel_0;
    StreamingLineBuffer_32_pixel_0.run<310>(BandwidthAdjustIncreaseChannels_17_out0_stream[1], StreamingLineBuffer_32_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_32_out0_stream_1," << StreamingLineBuffer_32_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_32_pixel_1;
    StreamingLineBuffer_32_pixel_1.run<311>(BandwidthAdjustIncreaseChannels_17_out0_stream[0], StreamingLineBuffer_32_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_32_out0_stream_0," << StreamingLineBuffer_32_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 12>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        12,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_22;
    StreamingConv_22.run<312>(StreamingLineBuffer_32_out0_stream, StreamingConv_22_weights, StreamingConv_22_biases, StreamingConv_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_22_out0_stream_0," << StreamingConv_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_22_out0_stream_1," << StreamingConv_22_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_12;
    BandwidthAdjustDecreaseChannels_12.run<313>(StreamingConv_22_out0_stream, BandwidthAdjustDecreaseChannels_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_12_out0_stream_0," << BandwidthAdjustDecreaseChannels_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_12_out0_stream_1," << BandwidthAdjustDecreaseChannels_12_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_0;
    StreamingLineBuffer_33_pixel_0.run<314>(BandwidthAdjustDecreaseChannels_12_out0_stream[0], StreamingLineBuffer_33_out0_stream_prepad[11], StreamingLineBuffer_33_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_11," << StreamingLineBuffer_33_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_0," << StreamingLineBuffer_33_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_1;
    StreamingLineBuffer_33_pixel_1.run<315>(BandwidthAdjustDecreaseChannels_12_out0_stream[1], StreamingLineBuffer_33_out0_stream_prepad[10], StreamingLineBuffer_33_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_10," << StreamingLineBuffer_33_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_1," << StreamingLineBuffer_33_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_2;
    StreamingLineBuffer_33_pixel_2.run<316>(StreamingLineBuffer_33_buffer_stream[0], StreamingLineBuffer_33_out0_stream_prepad[9], StreamingLineBuffer_33_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_9," << StreamingLineBuffer_33_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_2," << StreamingLineBuffer_33_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_3;
    StreamingLineBuffer_33_pixel_3.run<317>(StreamingLineBuffer_33_buffer_stream[1], StreamingLineBuffer_33_out0_stream_prepad[8], StreamingLineBuffer_33_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_8," << StreamingLineBuffer_33_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_3," << StreamingLineBuffer_33_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_4;
    StreamingLineBuffer_33_pixel_4.run<318>(StreamingLineBuffer_33_buffer_stream[2], StreamingLineBuffer_33_out0_stream_prepad[7], StreamingLineBuffer_33_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_7," << StreamingLineBuffer_33_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_4," << StreamingLineBuffer_33_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_5;
    StreamingLineBuffer_33_pixel_5.run<319>(StreamingLineBuffer_33_buffer_stream[3], StreamingLineBuffer_33_out0_stream_prepad[6], StreamingLineBuffer_33_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_6," << StreamingLineBuffer_33_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_5," << StreamingLineBuffer_33_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_6;
    StreamingLineBuffer_33_pixel_6.run<320>(StreamingLineBuffer_33_buffer_stream[4], StreamingLineBuffer_33_out0_stream_prepad[5], StreamingLineBuffer_33_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_5," << StreamingLineBuffer_33_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_6," << StreamingLineBuffer_33_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_7;
    StreamingLineBuffer_33_pixel_7.run<321>(StreamingLineBuffer_33_buffer_stream[5], StreamingLineBuffer_33_out0_stream_prepad[4], StreamingLineBuffer_33_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_4," << StreamingLineBuffer_33_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_7," << StreamingLineBuffer_33_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_8;
    StreamingLineBuffer_33_pixel_8.run<322>(StreamingLineBuffer_33_buffer_stream[6], StreamingLineBuffer_33_out0_stream_prepad[3], StreamingLineBuffer_33_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_3," << StreamingLineBuffer_33_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_8," << StreamingLineBuffer_33_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_9;
    StreamingLineBuffer_33_pixel_9.run<323>(StreamingLineBuffer_33_buffer_stream[7], StreamingLineBuffer_33_out0_stream_prepad[2], StreamingLineBuffer_33_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_2," << StreamingLineBuffer_33_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_buffer_stream_9," << StreamingLineBuffer_33_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_10;
    StreamingLineBuffer_33_pixel_10.run<324>(StreamingLineBuffer_33_buffer_stream[8], StreamingLineBuffer_33_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_1," << StreamingLineBuffer_33_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_33_pixel_11;
    StreamingLineBuffer_33_pixel_11.run<325>(StreamingLineBuffer_33_buffer_stream[9], StreamingLineBuffer_33_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_prepad_0," << StreamingLineBuffer_33_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_33_pad;
    StreamingLineBuffer_33_pad.run<326>(StreamingLineBuffer_33_out0_stream_prepad, StreamingLineBuffer_33_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_0," << StreamingLineBuffer_33_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_1," << StreamingLineBuffer_33_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_2," << StreamingLineBuffer_33_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_3," << StreamingLineBuffer_33_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_4," << StreamingLineBuffer_33_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_5," << StreamingLineBuffer_33_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_6," << StreamingLineBuffer_33_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_7," << StreamingLineBuffer_33_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_8," << StreamingLineBuffer_33_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_9," << StreamingLineBuffer_33_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_10," << StreamingLineBuffer_33_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_11," << StreamingLineBuffer_33_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_11_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_11_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_11_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_11_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_11;
    StreamingDepthwiseConv_11.run<327>(StreamingLineBuffer_33_out0_stream, StreamingDepthwiseConv_11_weights, StreamingDepthwiseConv_11_biases, StreamingDepthwiseConv_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_11_out0_stream_0," << StreamingDepthwiseConv_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_11_out0_stream_1," << StreamingDepthwiseConv_11_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_18;
    BandwidthAdjustIncreaseChannels_18.run<328>(StreamingDepthwiseConv_11_out0_stream, BandwidthAdjustIncreaseChannels_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_18_out0_stream_0," << BandwidthAdjustIncreaseChannels_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_18_out0_stream_1," << BandwidthAdjustIncreaseChannels_18_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_34_pixel_0;
    StreamingLineBuffer_34_pixel_0.run<329>(BandwidthAdjustIncreaseChannels_18_out0_stream[1], StreamingLineBuffer_34_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_1," << StreamingLineBuffer_34_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_34_pixel_1;
    StreamingLineBuffer_34_pixel_1.run<330>(BandwidthAdjustIncreaseChannels_18_out0_stream[0], StreamingLineBuffer_34_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_0," << StreamingLineBuffer_34_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 27>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_23;
    StreamingConv_23.run<331>(StreamingLineBuffer_34_out0_stream, StreamingConv_23_weights, StreamingConv_23_biases, StreamingConv_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_23_out0_stream_0," << StreamingConv_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_23_out0_stream_1," << StreamingConv_23_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 3>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 3>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        3  // CH_PAR
    > StreamingAdd_6;
    StreamingAdd_6.run<332>(TensorDuplicator_6_out1_stream, StreamingConv_23_out0_stream, StreamingAdd_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_0," << StreamingAdd_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_1," << StreamingAdd_6_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        3,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_7;
    TensorDuplicator_7.run<333>(StreamingAdd_6_out0_stream, TensorDuplicator_7_out0_stream, TensorDuplicator_7_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_7_out0_stream_0," << TensorDuplicator_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_7_out0_stream_1," << TensorDuplicator_7_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_7_out1_stream_0," << TensorDuplicator_7_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_7_out1_stream_1," << TensorDuplicator_7_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        12  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_19;
    BandwidthAdjustIncreaseChannels_19.run<334>(TensorDuplicator_7_out0_stream, BandwidthAdjustIncreaseChannels_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_19_out0_stream_0," << BandwidthAdjustIncreaseChannels_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_19_out0_stream_1," << BandwidthAdjustIncreaseChannels_19_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_35_pixel_0;
    StreamingLineBuffer_35_pixel_0.run<335>(BandwidthAdjustIncreaseChannels_19_out0_stream[1], StreamingLineBuffer_35_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_35_out0_stream_1," << StreamingLineBuffer_35_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_35_pixel_1;
    StreamingLineBuffer_35_pixel_1.run<336>(BandwidthAdjustIncreaseChannels_19_out0_stream[0], StreamingLineBuffer_35_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_35_out0_stream_0," << StreamingLineBuffer_35_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 12>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        12,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_24;
    StreamingConv_24.run<337>(StreamingLineBuffer_35_out0_stream, StreamingConv_24_weights, StreamingConv_24_biases, StreamingConv_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_24_out0_stream_0," << StreamingConv_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_24_out0_stream_1," << StreamingConv_24_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_13;
    BandwidthAdjustDecreaseChannels_13.run<338>(StreamingConv_24_out0_stream, BandwidthAdjustDecreaseChannels_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_13_out0_stream_0," << BandwidthAdjustDecreaseChannels_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_13_out0_stream_1," << BandwidthAdjustDecreaseChannels_13_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_0;
    StreamingLineBuffer_36_pixel_0.run<339>(BandwidthAdjustDecreaseChannels_13_out0_stream[0], StreamingLineBuffer_36_out0_stream_prepad[11], StreamingLineBuffer_36_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_11," << StreamingLineBuffer_36_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_0," << StreamingLineBuffer_36_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_1;
    StreamingLineBuffer_36_pixel_1.run<340>(BandwidthAdjustDecreaseChannels_13_out0_stream[1], StreamingLineBuffer_36_out0_stream_prepad[10], StreamingLineBuffer_36_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_10," << StreamingLineBuffer_36_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_1," << StreamingLineBuffer_36_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_2;
    StreamingLineBuffer_36_pixel_2.run<341>(StreamingLineBuffer_36_buffer_stream[0], StreamingLineBuffer_36_out0_stream_prepad[9], StreamingLineBuffer_36_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_9," << StreamingLineBuffer_36_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_2," << StreamingLineBuffer_36_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_3;
    StreamingLineBuffer_36_pixel_3.run<342>(StreamingLineBuffer_36_buffer_stream[1], StreamingLineBuffer_36_out0_stream_prepad[8], StreamingLineBuffer_36_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_8," << StreamingLineBuffer_36_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_3," << StreamingLineBuffer_36_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_4;
    StreamingLineBuffer_36_pixel_4.run<343>(StreamingLineBuffer_36_buffer_stream[2], StreamingLineBuffer_36_out0_stream_prepad[7], StreamingLineBuffer_36_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_7," << StreamingLineBuffer_36_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_4," << StreamingLineBuffer_36_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_5;
    StreamingLineBuffer_36_pixel_5.run<344>(StreamingLineBuffer_36_buffer_stream[3], StreamingLineBuffer_36_out0_stream_prepad[6], StreamingLineBuffer_36_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_6," << StreamingLineBuffer_36_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_5," << StreamingLineBuffer_36_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_6;
    StreamingLineBuffer_36_pixel_6.run<345>(StreamingLineBuffer_36_buffer_stream[4], StreamingLineBuffer_36_out0_stream_prepad[5], StreamingLineBuffer_36_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_5," << StreamingLineBuffer_36_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_6," << StreamingLineBuffer_36_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_7;
    StreamingLineBuffer_36_pixel_7.run<346>(StreamingLineBuffer_36_buffer_stream[5], StreamingLineBuffer_36_out0_stream_prepad[4], StreamingLineBuffer_36_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_4," << StreamingLineBuffer_36_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_7," << StreamingLineBuffer_36_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_8;
    StreamingLineBuffer_36_pixel_8.run<347>(StreamingLineBuffer_36_buffer_stream[6], StreamingLineBuffer_36_out0_stream_prepad[3], StreamingLineBuffer_36_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_3," << StreamingLineBuffer_36_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_8," << StreamingLineBuffer_36_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_9;
    StreamingLineBuffer_36_pixel_9.run<348>(StreamingLineBuffer_36_buffer_stream[7], StreamingLineBuffer_36_out0_stream_prepad[2], StreamingLineBuffer_36_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_2," << StreamingLineBuffer_36_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_buffer_stream_9," << StreamingLineBuffer_36_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_10;
    StreamingLineBuffer_36_pixel_10.run<349>(StreamingLineBuffer_36_buffer_stream[8], StreamingLineBuffer_36_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_1," << StreamingLineBuffer_36_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_11;
    StreamingLineBuffer_36_pixel_11.run<350>(StreamingLineBuffer_36_buffer_stream[9], StreamingLineBuffer_36_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_prepad_0," << StreamingLineBuffer_36_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_36_pad;
    StreamingLineBuffer_36_pad.run<351>(StreamingLineBuffer_36_out0_stream_prepad, StreamingLineBuffer_36_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_0," << StreamingLineBuffer_36_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_1," << StreamingLineBuffer_36_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_2," << StreamingLineBuffer_36_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_3," << StreamingLineBuffer_36_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_4," << StreamingLineBuffer_36_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_5," << StreamingLineBuffer_36_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_6," << StreamingLineBuffer_36_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_7," << StreamingLineBuffer_36_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_8," << StreamingLineBuffer_36_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_9," << StreamingLineBuffer_36_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_10," << StreamingLineBuffer_36_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_11," << StreamingLineBuffer_36_out0_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_12_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_12_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_12_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_12_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_12;
    StreamingDepthwiseConv_12.run<352>(StreamingLineBuffer_36_out0_stream, StreamingDepthwiseConv_12_weights, StreamingDepthwiseConv_12_biases, StreamingDepthwiseConv_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_12_out0_stream_0," << StreamingDepthwiseConv_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_12_out0_stream_1," << StreamingDepthwiseConv_12_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_20;
    BandwidthAdjustIncreaseChannels_20.run<353>(StreamingDepthwiseConv_12_out0_stream, BandwidthAdjustIncreaseChannels_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_20_out0_stream_0," << BandwidthAdjustIncreaseChannels_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_20_out0_stream_1," << BandwidthAdjustIncreaseChannels_20_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_37_pixel_0;
    StreamingLineBuffer_37_pixel_0.run<354>(BandwidthAdjustIncreaseChannels_20_out0_stream[1], StreamingLineBuffer_37_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_37_out0_stream_1," << StreamingLineBuffer_37_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_37_pixel_1;
    StreamingLineBuffer_37_pixel_1.run<355>(BandwidthAdjustIncreaseChannels_20_out0_stream[0], StreamingLineBuffer_37_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_37_out0_stream_0," << StreamingLineBuffer_37_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 27>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_25;
    StreamingConv_25.run<356>(StreamingLineBuffer_37_out0_stream, StreamingConv_25_weights, StreamingConv_25_biases, StreamingConv_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_25_out0_stream_0," << StreamingConv_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_25_out0_stream_1," << StreamingConv_25_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 3>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 3>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        3  // CH_PAR
    > StreamingAdd_7;
    StreamingAdd_7.run<357>(TensorDuplicator_7_out1_stream, StreamingConv_25_out0_stream, StreamingAdd_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_0," << StreamingAdd_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_1," << StreamingAdd_7_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        12  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_21;
    BandwidthAdjustIncreaseChannels_21.run<358>(StreamingAdd_7_out0_stream, BandwidthAdjustIncreaseChannels_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_21_out0_stream_0," << BandwidthAdjustIncreaseChannels_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_21_out0_stream_1," << BandwidthAdjustIncreaseChannels_21_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_38_pixel_0;
    StreamingLineBuffer_38_pixel_0.run<359>(BandwidthAdjustIncreaseChannels_21_out0_stream[1], StreamingLineBuffer_38_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_1," << StreamingLineBuffer_38_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 12>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        12  // CH_PAR
    > StreamingLineBuffer_38_pixel_1;
    StreamingLineBuffer_38_pixel_1.run<360>(BandwidthAdjustIncreaseChannels_21_out0_stream[0], StreamingLineBuffer_38_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_0," << StreamingLineBuffer_38_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 12>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        12,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_26;
    StreamingConv_26.run<361>(StreamingLineBuffer_38_out0_stream, StreamingConv_26_weights, StreamingConv_26_biases, StreamingConv_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_26_out0_stream_0," << StreamingConv_26_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_26_out0_stream_1," << StreamingConv_26_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_14;
    BandwidthAdjustDecreaseChannels_14.run<362>(StreamingConv_26_out0_stream, BandwidthAdjustDecreaseChannels_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_14_out0_stream_0," << BandwidthAdjustDecreaseChannels_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_14_out0_stream_1," << BandwidthAdjustDecreaseChannels_14_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_4;
    BandwidthAdjustDecreaseStreams_4.run<363>(BandwidthAdjustDecreaseChannels_14_out0_stream, BandwidthAdjustDecreaseStreams_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_4_out0_stream_0," << BandwidthAdjustDecreaseStreams_4_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_0;
    StreamingLineBuffer_39_pixel_0.run<364>(BandwidthAdjustDecreaseStreams_4_out0_stream[0], StreamingLineBuffer_39_out0_stream_prepad[8], StreamingLineBuffer_39_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_8," << StreamingLineBuffer_39_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_0," << StreamingLineBuffer_39_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_1;
    StreamingLineBuffer_39_pixel_1.run<365>(StreamingLineBuffer_39_buffer_stream[0], StreamingLineBuffer_39_out0_stream_prepad[7], StreamingLineBuffer_39_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_7," << StreamingLineBuffer_39_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_1," << StreamingLineBuffer_39_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_2;
    StreamingLineBuffer_39_pixel_2.run<366>(StreamingLineBuffer_39_buffer_stream[1], StreamingLineBuffer_39_out0_stream_prepad[6], StreamingLineBuffer_39_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_6," << StreamingLineBuffer_39_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_2," << StreamingLineBuffer_39_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_3;
    StreamingLineBuffer_39_pixel_3.run<367>(StreamingLineBuffer_39_buffer_stream[2], StreamingLineBuffer_39_out0_stream_prepad[5], StreamingLineBuffer_39_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_5," << StreamingLineBuffer_39_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_3," << StreamingLineBuffer_39_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_4;
    StreamingLineBuffer_39_pixel_4.run<368>(StreamingLineBuffer_39_buffer_stream[3], StreamingLineBuffer_39_out0_stream_prepad[4], StreamingLineBuffer_39_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_4," << StreamingLineBuffer_39_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_4," << StreamingLineBuffer_39_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_5;
    StreamingLineBuffer_39_pixel_5.run<369>(StreamingLineBuffer_39_buffer_stream[4], StreamingLineBuffer_39_out0_stream_prepad[3], StreamingLineBuffer_39_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_3," << StreamingLineBuffer_39_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_5," << StreamingLineBuffer_39_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_6;
    StreamingLineBuffer_39_pixel_6.run<370>(StreamingLineBuffer_39_buffer_stream[5], StreamingLineBuffer_39_out0_stream_prepad[2], StreamingLineBuffer_39_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_2," << StreamingLineBuffer_39_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_6," << StreamingLineBuffer_39_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_7;
    StreamingLineBuffer_39_pixel_7.run<371>(StreamingLineBuffer_39_buffer_stream[6], StreamingLineBuffer_39_out0_stream_prepad[1], StreamingLineBuffer_39_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_1," << StreamingLineBuffer_39_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_7," << StreamingLineBuffer_39_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_8;
    StreamingLineBuffer_39_pixel_8.run<372>(StreamingLineBuffer_39_buffer_stream[7], StreamingLineBuffer_39_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_0," << StreamingLineBuffer_39_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_39_pad;
    StreamingLineBuffer_39_pad.run<373>(StreamingLineBuffer_39_out0_stream_prepad, StreamingLineBuffer_39_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_0," << StreamingLineBuffer_39_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_1," << StreamingLineBuffer_39_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_2," << StreamingLineBuffer_39_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_3," << StreamingLineBuffer_39_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_4," << StreamingLineBuffer_39_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_5," << StreamingLineBuffer_39_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_6," << StreamingLineBuffer_39_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_7," << StreamingLineBuffer_39_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_8," << StreamingLineBuffer_39_out0_stream[8].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_13_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_13_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_13_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_13_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_13;
    StreamingDepthwiseConv_13.run<374>(StreamingLineBuffer_39_out0_stream, StreamingDepthwiseConv_13_weights, StreamingDepthwiseConv_13_biases, StreamingDepthwiseConv_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_13_out0_stream_0," << StreamingDepthwiseConv_13_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_22;
    BandwidthAdjustIncreaseChannels_22.run<375>(StreamingDepthwiseConv_13_out0_stream, BandwidthAdjustIncreaseChannels_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_22_out0_stream_0," << BandwidthAdjustIncreaseChannels_22_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        576,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_27;
    StreamingConv_27.run<376>(BandwidthAdjustIncreaseChannels_22_out0_stream, StreamingConv_27_weights, StreamingConv_27_biases, StreamingConv_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_27_out0_stream_0," << StreamingConv_27_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_8;
    TensorDuplicator_8.run<377>(StreamingConv_27_out0_stream, TensorDuplicator_8_out0_stream, TensorDuplicator_8_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out0_stream_0," << TensorDuplicator_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out1_stream_0," << TensorDuplicator_8_out1_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_15;
    BandwidthAdjustDecreaseChannels_15.run<378>(TensorDuplicator_8_out0_stream, BandwidthAdjustDecreaseChannels_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_15_out0_stream_0," << BandwidthAdjustDecreaseChannels_15_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        10  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_23;
    BandwidthAdjustIncreaseChannels_23.run<379>(BandwidthAdjustDecreaseChannels_15_out0_stream, BandwidthAdjustIncreaseChannels_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_23_out0_stream_0," << BandwidthAdjustIncreaseChannels_23_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        10,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_28;
    StreamingConv_28.run<380>(BandwidthAdjustIncreaseChannels_23_out0_stream, StreamingConv_28_weights, StreamingConv_28_biases, StreamingConv_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_28_out0_stream_0," << StreamingConv_28_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_16;
    BandwidthAdjustDecreaseChannels_16.run<381>(StreamingConv_28_out0_stream, BandwidthAdjustDecreaseChannels_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_16_out0_stream_0," << BandwidthAdjustDecreaseChannels_16_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_0;
    StreamingLineBuffer_40_pixel_0.run<382>(BandwidthAdjustDecreaseChannels_16_out0_stream[0], StreamingLineBuffer_40_out0_stream_prepad[8], StreamingLineBuffer_40_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_8," << StreamingLineBuffer_40_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_0," << StreamingLineBuffer_40_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_1;
    StreamingLineBuffer_40_pixel_1.run<383>(StreamingLineBuffer_40_buffer_stream[0], StreamingLineBuffer_40_out0_stream_prepad[7], StreamingLineBuffer_40_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_7," << StreamingLineBuffer_40_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_1," << StreamingLineBuffer_40_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_2;
    StreamingLineBuffer_40_pixel_2.run<384>(StreamingLineBuffer_40_buffer_stream[1], StreamingLineBuffer_40_out0_stream_prepad[6], StreamingLineBuffer_40_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_6," << StreamingLineBuffer_40_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_2," << StreamingLineBuffer_40_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_3;
    StreamingLineBuffer_40_pixel_3.run<385>(StreamingLineBuffer_40_buffer_stream[2], StreamingLineBuffer_40_out0_stream_prepad[5], StreamingLineBuffer_40_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_5," << StreamingLineBuffer_40_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_3," << StreamingLineBuffer_40_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_4;
    StreamingLineBuffer_40_pixel_4.run<386>(StreamingLineBuffer_40_buffer_stream[3], StreamingLineBuffer_40_out0_stream_prepad[4], StreamingLineBuffer_40_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_4," << StreamingLineBuffer_40_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_4," << StreamingLineBuffer_40_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_5;
    StreamingLineBuffer_40_pixel_5.run<387>(StreamingLineBuffer_40_buffer_stream[4], StreamingLineBuffer_40_out0_stream_prepad[3], StreamingLineBuffer_40_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_3," << StreamingLineBuffer_40_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_5," << StreamingLineBuffer_40_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_6;
    StreamingLineBuffer_40_pixel_6.run<388>(StreamingLineBuffer_40_buffer_stream[5], StreamingLineBuffer_40_out0_stream_prepad[2], StreamingLineBuffer_40_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_2," << StreamingLineBuffer_40_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_6," << StreamingLineBuffer_40_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_7;
    StreamingLineBuffer_40_pixel_7.run<389>(StreamingLineBuffer_40_buffer_stream[6], StreamingLineBuffer_40_out0_stream_prepad[1], StreamingLineBuffer_40_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_1," << StreamingLineBuffer_40_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_buffer_stream_7," << StreamingLineBuffer_40_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_40_pixel_8;
    StreamingLineBuffer_40_pixel_8.run<390>(StreamingLineBuffer_40_buffer_stream[7], StreamingLineBuffer_40_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_prepad_0," << StreamingLineBuffer_40_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_40_pad;
    StreamingLineBuffer_40_pad.run<391>(StreamingLineBuffer_40_out0_stream_prepad, StreamingLineBuffer_40_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_0," << StreamingLineBuffer_40_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_1," << StreamingLineBuffer_40_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_2," << StreamingLineBuffer_40_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_3," << StreamingLineBuffer_40_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_4," << StreamingLineBuffer_40_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_5," << StreamingLineBuffer_40_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_6," << StreamingLineBuffer_40_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_7," << StreamingLineBuffer_40_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_8," << StreamingLineBuffer_40_out0_stream[8].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_14_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_14_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_14;
    StreamingDepthwiseConv_14.run<392>(StreamingLineBuffer_40_out0_stream, StreamingDepthwiseConv_14_weights, StreamingDepthwiseConv_14_biases, StreamingDepthwiseConv_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_14_out0_stream_0," << StreamingDepthwiseConv_14_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 10>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        10  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_24;
    BandwidthAdjustIncreaseChannels_24.run<393>(StreamingDepthwiseConv_14_out0_stream, BandwidthAdjustIncreaseChannels_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_24_out0_stream_0," << BandwidthAdjustIncreaseChannels_24_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 10>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<10, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        10,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_29;
    StreamingConv_29.run<394>(BandwidthAdjustIncreaseChannels_24_out0_stream, StreamingConv_29_weights, StreamingConv_29_biases, StreamingConv_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_29_out0_stream_0," << StreamingConv_29_out0_stream[0].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_8;
    StreamingAdd_8.run<395>(TensorDuplicator_8_out1_stream, StreamingConv_29_out0_stream, StreamingAdd_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_8_out0_stream_0," << StreamingAdd_8_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_9;
    TensorDuplicator_9.run<396>(StreamingAdd_8_out0_stream, TensorDuplicator_9_out0_stream, TensorDuplicator_9_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out0_stream_0," << TensorDuplicator_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out1_stream_0," << TensorDuplicator_9_out1_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_17;
    BandwidthAdjustDecreaseChannels_17.run<397>(TensorDuplicator_9_out0_stream, BandwidthAdjustDecreaseChannels_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_17_out0_stream_0," << BandwidthAdjustDecreaseChannels_17_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_18;
    BandwidthAdjustDecreaseChannels_18.run<398>(TensorDuplicator_9_out1_stream, BandwidthAdjustDecreaseChannels_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_18_out0_stream_0," << BandwidthAdjustDecreaseChannels_18_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        10  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_25;
    BandwidthAdjustIncreaseChannels_25.run<399>(BandwidthAdjustDecreaseChannels_17_out0_stream, BandwidthAdjustIncreaseChannels_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_25_out0_stream_0," << BandwidthAdjustIncreaseChannels_25_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 4>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        10,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_30;
    StreamingConv_30.run<400>(BandwidthAdjustIncreaseChannels_25_out0_stream, StreamingConv_30_weights, StreamingConv_30_biases, StreamingConv_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_30_out0_stream_0," << StreamingConv_30_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_19;
    BandwidthAdjustDecreaseChannels_19.run<401>(StreamingConv_30_out0_stream, BandwidthAdjustDecreaseChannels_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_19_out0_stream_0," << BandwidthAdjustDecreaseChannels_19_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_0;
    StreamingLineBuffer_41_pixel_0.run<402>(BandwidthAdjustDecreaseChannels_19_out0_stream[0], StreamingLineBuffer_41_out0_stream_prepad[8], StreamingLineBuffer_41_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_8," << StreamingLineBuffer_41_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_0," << StreamingLineBuffer_41_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_1;
    StreamingLineBuffer_41_pixel_1.run<403>(StreamingLineBuffer_41_buffer_stream[0], StreamingLineBuffer_41_out0_stream_prepad[7], StreamingLineBuffer_41_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_7," << StreamingLineBuffer_41_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_1," << StreamingLineBuffer_41_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_2;
    StreamingLineBuffer_41_pixel_2.run<404>(StreamingLineBuffer_41_buffer_stream[1], StreamingLineBuffer_41_out0_stream_prepad[6], StreamingLineBuffer_41_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_6," << StreamingLineBuffer_41_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_2," << StreamingLineBuffer_41_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_3;
    StreamingLineBuffer_41_pixel_3.run<405>(StreamingLineBuffer_41_buffer_stream[2], StreamingLineBuffer_41_out0_stream_prepad[5], StreamingLineBuffer_41_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_5," << StreamingLineBuffer_41_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_3," << StreamingLineBuffer_41_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_4;
    StreamingLineBuffer_41_pixel_4.run<406>(StreamingLineBuffer_41_buffer_stream[3], StreamingLineBuffer_41_out0_stream_prepad[4], StreamingLineBuffer_41_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_4," << StreamingLineBuffer_41_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_4," << StreamingLineBuffer_41_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_5;
    StreamingLineBuffer_41_pixel_5.run<407>(StreamingLineBuffer_41_buffer_stream[4], StreamingLineBuffer_41_out0_stream_prepad[3], StreamingLineBuffer_41_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_3," << StreamingLineBuffer_41_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_5," << StreamingLineBuffer_41_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_6;
    StreamingLineBuffer_41_pixel_6.run<408>(StreamingLineBuffer_41_buffer_stream[5], StreamingLineBuffer_41_out0_stream_prepad[2], StreamingLineBuffer_41_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_2," << StreamingLineBuffer_41_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_6," << StreamingLineBuffer_41_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_7;
    StreamingLineBuffer_41_pixel_7.run<409>(StreamingLineBuffer_41_buffer_stream[6], StreamingLineBuffer_41_out0_stream_prepad[1], StreamingLineBuffer_41_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_1," << StreamingLineBuffer_41_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_7," << StreamingLineBuffer_41_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_41_pixel_8;
    StreamingLineBuffer_41_pixel_8.run<410>(StreamingLineBuffer_41_buffer_stream[7], StreamingLineBuffer_41_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_0," << StreamingLineBuffer_41_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_41_pad;
    StreamingLineBuffer_41_pad.run<411>(StreamingLineBuffer_41_out0_stream_prepad, StreamingLineBuffer_41_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_0," << StreamingLineBuffer_41_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_1," << StreamingLineBuffer_41_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_2," << StreamingLineBuffer_41_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_3," << StreamingLineBuffer_41_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_4," << StreamingLineBuffer_41_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_5," << StreamingLineBuffer_41_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_6," << StreamingLineBuffer_41_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_7," << StreamingLineBuffer_41_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_8," << StreamingLineBuffer_41_out0_stream[8].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_15_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_15_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_15_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_15_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_15;
    StreamingDepthwiseConv_15.run<412>(StreamingLineBuffer_41_out0_stream, StreamingDepthwiseConv_15_weights, StreamingDepthwiseConv_15_biases, StreamingDepthwiseConv_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_15_out0_stream_0," << StreamingDepthwiseConv_15_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 20>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_26;
    BandwidthAdjustIncreaseChannels_26.run<413>(StreamingDepthwiseConv_15_out0_stream, BandwidthAdjustIncreaseChannels_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_26_out0_stream_0," << BandwidthAdjustIncreaseChannels_26_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 20>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_31;
    StreamingConv_31.run<414>(BandwidthAdjustIncreaseChannels_26_out0_stream, StreamingConv_31_weights, StreamingConv_31_biases, StreamingConv_31_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_31_out0_stream_0," << StreamingConv_31_out0_stream[0].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 2>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_9;
    StreamingAdd_9.run<415>(BandwidthAdjustDecreaseChannels_18_out0_stream, StreamingConv_31_out0_stream, StreamingAdd_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_9_out0_stream_0," << StreamingAdd_9_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 20>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_27;
    BandwidthAdjustIncreaseChannels_27.run<416>(StreamingAdd_9_out0_stream, BandwidthAdjustIncreaseChannels_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_27_out0_stream_0," << BandwidthAdjustIncreaseChannels_27_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 20>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_32;
    StreamingConv_32.run<417>(BandwidthAdjustIncreaseChannels_27_out0_stream, StreamingConv_32_weights, StreamingConv_32_biases, StreamingConv_32_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_32_out0_stream_0," << StreamingConv_32_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_20;
    BandwidthAdjustDecreaseChannels_20.run<418>(StreamingConv_32_out0_stream, BandwidthAdjustDecreaseChannels_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_20_out0_stream_0," << BandwidthAdjustDecreaseChannels_20_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_0;
    StreamingLineBuffer_42_pixel_0.run<419>(BandwidthAdjustDecreaseChannels_20_out0_stream[0], StreamingLineBuffer_42_out0_stream_prepad[8], StreamingLineBuffer_42_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_8," << StreamingLineBuffer_42_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_0," << StreamingLineBuffer_42_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_1;
    StreamingLineBuffer_42_pixel_1.run<420>(StreamingLineBuffer_42_buffer_stream[0], StreamingLineBuffer_42_out0_stream_prepad[7], StreamingLineBuffer_42_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_7," << StreamingLineBuffer_42_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_1," << StreamingLineBuffer_42_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_2;
    StreamingLineBuffer_42_pixel_2.run<421>(StreamingLineBuffer_42_buffer_stream[1], StreamingLineBuffer_42_out0_stream_prepad[6], StreamingLineBuffer_42_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_6," << StreamingLineBuffer_42_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_2," << StreamingLineBuffer_42_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_3;
    StreamingLineBuffer_42_pixel_3.run<422>(StreamingLineBuffer_42_buffer_stream[2], StreamingLineBuffer_42_out0_stream_prepad[5], StreamingLineBuffer_42_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_5," << StreamingLineBuffer_42_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_3," << StreamingLineBuffer_42_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_4;
    StreamingLineBuffer_42_pixel_4.run<423>(StreamingLineBuffer_42_buffer_stream[3], StreamingLineBuffer_42_out0_stream_prepad[4], StreamingLineBuffer_42_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_4," << StreamingLineBuffer_42_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_4," << StreamingLineBuffer_42_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_5;
    StreamingLineBuffer_42_pixel_5.run<424>(StreamingLineBuffer_42_buffer_stream[4], StreamingLineBuffer_42_out0_stream_prepad[3], StreamingLineBuffer_42_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_3," << StreamingLineBuffer_42_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_5," << StreamingLineBuffer_42_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_6;
    StreamingLineBuffer_42_pixel_6.run<425>(StreamingLineBuffer_42_buffer_stream[5], StreamingLineBuffer_42_out0_stream_prepad[2], StreamingLineBuffer_42_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_2," << StreamingLineBuffer_42_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_6," << StreamingLineBuffer_42_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_7;
    StreamingLineBuffer_42_pixel_7.run<426>(StreamingLineBuffer_42_buffer_stream[6], StreamingLineBuffer_42_out0_stream_prepad[1], StreamingLineBuffer_42_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_1," << StreamingLineBuffer_42_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_7," << StreamingLineBuffer_42_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_42_pixel_8;
    StreamingLineBuffer_42_pixel_8.run<427>(StreamingLineBuffer_42_buffer_stream[7], StreamingLineBuffer_42_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_0," << StreamingLineBuffer_42_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_42_pad;
    StreamingLineBuffer_42_pad.run<428>(StreamingLineBuffer_42_out0_stream_prepad, StreamingLineBuffer_42_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_0," << StreamingLineBuffer_42_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_1," << StreamingLineBuffer_42_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_2," << StreamingLineBuffer_42_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_3," << StreamingLineBuffer_42_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_4," << StreamingLineBuffer_42_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_5," << StreamingLineBuffer_42_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_6," << StreamingLineBuffer_42_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_7," << StreamingLineBuffer_42_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_8," << StreamingLineBuffer_42_out0_stream[8].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_16_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_16_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_16;
    StreamingDepthwiseConv_16.run<429>(StreamingLineBuffer_42_out0_stream, StreamingDepthwiseConv_16_weights, StreamingDepthwiseConv_16_biases, StreamingDepthwiseConv_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_16_out0_stream_0," << StreamingDepthwiseConv_16_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 30>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        30  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_28;
    BandwidthAdjustIncreaseChannels_28.run<430>(StreamingDepthwiseConv_16_out0_stream, BandwidthAdjustIncreaseChannels_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_28_out0_stream_0," << BandwidthAdjustIncreaseChannels_28_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 30>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 120>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        320,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        30,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_33;
    StreamingConv_33.run<431>(BandwidthAdjustIncreaseChannels_28_out0_stream, StreamingConv_33_weights, StreamingConv_33_biases, StreamingConv_33_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_33_out0_stream_0," << StreamingConv_33_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        320,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        40  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_29;
    BandwidthAdjustIncreaseChannels_29.run<432>(StreamingConv_33_out0_stream, BandwidthAdjustIncreaseChannels_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_29_out0_stream_0," << BandwidthAdjustIncreaseChannels_29_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 40>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 160>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 4>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_uint<8>>,  // Quantizer
        1280,  // OUT_CH
        320,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        40,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_34;
    StreamingConv_34.run<433>(BandwidthAdjustIncreaseChannels_29_out0_stream, StreamingConv_34_weights, StreamingConv_34_biases, StreamingConv_34_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_34_out0_stream_0," << StreamingConv_34_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        1280,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_21;
    BandwidthAdjustDecreaseChannels_21.run<434>(StreamingConv_34_out0_stream, BandwidthAdjustDecreaseChannels_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_21_out0_stream_0," << BandwidthAdjustDecreaseChannels_21_out0_stream[0].size() << std::endl;
    #endif
    StreamingGlobalAveragePool <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_uint<14>,  // TAcc
        ap_uint<6>,  // TDiv
        DequantQuantPo2<0, ap_uint<14>, ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        1280,  // OUT_CH
        1  // OUT_CH_PAR
    > StreamingGlobalAveragePool_0;
    StreamingGlobalAveragePool_0.run<435>(BandwidthAdjustDecreaseChannels_21_out0_stream, StreamingGlobalAveragePool_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingGlobalAveragePool_0_out0_stream_0," << StreamingGlobalAveragePool_0_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 5>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        1,  // IN_HEIGHT
        1,  // IN_WIDTH
        1280,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        5  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_30;
    BandwidthAdjustIncreaseChannels_30.run<436>(StreamingGlobalAveragePool_0_out0_stream, BandwidthAdjustIncreaseChannels_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_30_out0_stream_0," << BandwidthAdjustIncreaseChannels_30_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 5>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<9>, 2>,  // TBiasWord
        ap_int<9>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        1000,  // OUT_CH
        1280,  // IN_CH
        1,  // OUT_HEIGHT
        1,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        5,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_35;
    StreamingConv_35.run<437>(BandwidthAdjustIncreaseChannels_30_out0_stream, StreamingConv_35_weights, StreamingConv_35_biases, StreamingConv_35_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_35_out0_stream_0," << StreamingConv_35_out0_stream[0].size() << std::endl;
    #endif
    s2mm<ap_int<8>, 2, 1, 500>(StreamingConv_35_out0_stream, out_data);
}
