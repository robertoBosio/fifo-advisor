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
#include "StreamingDepthwiseConv.hpp"
#include "StreamingPad.hpp"
#include "StreamingMaxPool.hpp"
#include "StreamingGlobalAveragePool.hpp"
#include "StreamingConv.hpp"
#include "DequantQuant.hpp"
#include "StreamingLeakyReLU.hpp"
#include "TensorDuplicator.hpp"
#include "StreamingConcat.hpp"
#include "StreamingWindowSelector.hpp"
#include "StreamingReLU.hpp"
#include "StreamToNHWC.hpp"
#include "StreamingMemory.hpp"
#include "StreamingAdd.hpp"
#include "NHWCToStream.hpp"
#include "BandwidthAdjust.hpp"
void resnet8(
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
)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    hls::stream<std::array<ap_int<8>, 1>> Quant_21_out0_stream[1];
    #pragma HLS STREAM variable=Quant_21_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> Quant_21_out0_bww_stream[2];
    #pragma HLS STREAM variable=Quant_21_out0_bww_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_21_out0_bww_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[0] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[1] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[2] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[3] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[4] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[5] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[6] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[7] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[8] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[9] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[10] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[11] depth=11
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[0] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[1] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[4] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[6] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[8] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[9] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[10] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[2] depth=46
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[3] depth=46
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[6] depth=46
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[7] depth=46
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[9] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_22_out0_stream[2];
    #pragma HLS STREAM variable=Quant_22_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_22_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_23_out0_stream[2];
    #pragma HLS STREAM variable=Quant_23_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_23_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_24_out0_stream[2];
    #pragma HLS STREAM variable=Quant_24_out0_stream[0] depth=627
    #pragma HLS STREAM variable=Quant_24_out0_stream[1] depth=627
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_2_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[0] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[1] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[2] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[3] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[4] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[5] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[6] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[7] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[8] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[9] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[10] depth=48
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream[11] depth=48
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_2_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[0] depth=35
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[1] depth=19
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[2] depth=21
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[4] depth=23
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[6] depth=24
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[8] depth=26
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[10] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_2_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_2_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[2] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[3] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[4] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[6] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[7] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[8] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_2_streaming_linebuffer_buffer_stream[9] depth=17
    hls::stream<std::array<ap_uint<8>, 2>> Quant_25_out0_stream[2];
    #pragma HLS STREAM variable=Quant_25_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_25_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_4_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[0] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[1] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[2] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[3] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[4] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[5] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[6] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[7] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[8] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[9] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[10] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[11] depth=10
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_4_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[0] depth=19
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[1] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[2] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[4] depth=15
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[6] depth=16
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[8] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[10] depth=20
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_4_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[0] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[1] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[2] depth=121
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[3] depth=121
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[4] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[5] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[6] depth=121
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[7] depth=121
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[8] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_4_streaming_linebuffer_buffer_stream[9] depth=9
    hls::stream<std::array<ap_int<8>, 1>> Quant_26_out0_stream[2];
    #pragma HLS STREAM variable=Quant_26_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_26_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_27_out0_stream[2];
    #pragma HLS STREAM variable=Quant_27_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_27_out0_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_28_out0_stream[2];
    #pragma HLS STREAM variable=Quant_28_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_28_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_29_out0_stream[2];
    #pragma HLS STREAM variable=Quant_29_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_29_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_7_window_stream[15];
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[0] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[1] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[2] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[3] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[4] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[5] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[6] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[7] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[8] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[9] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[10] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[11] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[12] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[13] depth=74
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream[14] depth=74
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_7_window_stream_prepad[15];
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[0] depth=19
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[1] depth=51
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[3] depth=43
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[5] depth=20
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[6] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[7] depth=20
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[8] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[9] depth=20
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[10] depth=31
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[11] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[13] depth=35
    #pragma HLS STREAM variable=node_StreamingConv_7_window_stream_prepad[14] depth=35
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_7_streaming_linebuffer_buffer_stream[13];
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[2] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[3] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[4] depth=225
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[6] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[7] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[8] depth=241
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[9] depth=225
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[10] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[11] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_7_streaming_linebuffer_buffer_stream[12] depth=17
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_8_window_stream[3];
    #pragma HLS STREAM variable=node_StreamingConv_8_window_stream[0] depth=75
    #pragma HLS STREAM variable=node_StreamingConv_8_window_stream[1] depth=76
    #pragma HLS STREAM variable=node_StreamingConv_8_window_stream[2] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_8_streaming_linebuffer_buffer_stream[1];
    #pragma HLS STREAM variable=node_StreamingConv_8_streaming_linebuffer_buffer_stream[0] depth=17
    hls::stream<std::array<ap_uint<8>, 1>> Quant_31_out0_stream[2];
    #pragma HLS STREAM variable=Quant_31_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_31_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> Quant_30_out0_stream[2];
    #pragma HLS STREAM variable=Quant_30_out0_stream[0] depth=482
    #pragma HLS STREAM variable=Quant_30_out0_stream[1] depth=482
    hls::stream<std::array<ap_uint<8>, 2>> Quant_31_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_31_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_31_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_10_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[0] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[1] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[2] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[3] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[4] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[5] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[6] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[7] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[8] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[9] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[10] depth=18
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[11] depth=18
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_10_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[0] depth=35
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[1] depth=19
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[2] depth=21
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[4] depth=22
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[6] depth=23
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[7] depth=7
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[8] depth=24
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[10] depth=26
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream_prepad[11] depth=10
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_10_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[2] depth=113
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[3] depth=113
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[4] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[6] depth=113
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[7] depth=113
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[8] depth=17
    #pragma HLS STREAM variable=node_StreamingConv_10_streaming_linebuffer_buffer_stream[9] depth=17
    hls::stream<std::array<ap_int<8>, 1>> Quant_32_out0_stream[2];
    #pragma HLS STREAM variable=Quant_32_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_32_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_33_out0_stream[2];
    #pragma HLS STREAM variable=Quant_33_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_33_out0_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_34_out0_stream[2];
    #pragma HLS STREAM variable=Quant_34_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_34_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_35_out0_stream[2];
    #pragma HLS STREAM variable=Quant_35_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_35_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_13_window_stream[15];
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[0] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[1] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[2] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[3] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[4] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[5] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[6] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[7] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[8] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[9] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[10] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[11] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[12] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[13] depth=28
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream[14] depth=28
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_13_window_stream_prepad[15];
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[0] depth=35
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[1] depth=99
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[3] depth=75
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[5] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[6] depth=68
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[7] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[8] depth=68
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[9] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[10] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[11] depth=49
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[12] depth=49
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[13] depth=51
    #pragma HLS STREAM variable=node_StreamingConv_13_window_stream_prepad[14] depth=51
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_13_streaming_linebuffer_buffer_stream[13];
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[2] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[3] depth=225
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[4] depth=193
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[6] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[7] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[8] depth=225
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[9] depth=193
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[10] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[11] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_13_streaming_linebuffer_buffer_stream[12] depth=33
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_14_window_stream[3];
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[0] depth=87
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[1] depth=88
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[2] depth=80
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_14_streaming_linebuffer_buffer_stream[1];
    #pragma HLS STREAM variable=node_StreamingConv_14_streaming_linebuffer_buffer_stream[0] depth=33
    hls::stream<std::array<ap_uint<8>, 2>> Quant_37_out0_stream[2];
    #pragma HLS STREAM variable=Quant_37_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_37_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> Quant_36_out0_stream[2];
    #pragma HLS STREAM variable=Quant_36_out0_stream[0] depth=578
    #pragma HLS STREAM variable=Quant_36_out0_stream[1] depth=578
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_16_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[0] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[1] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[2] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[3] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[4] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[5] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[6] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[7] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[8] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[9] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[10] depth=89
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[11] depth=89
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_16_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[0] depth=67
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[1] depth=35
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[2] depth=37
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[4] depth=39
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[6] depth=40
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[8] depth=42
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[10] depth=44
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_16_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[2] depth=97
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[3] depth=97
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[6] depth=97
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[7] depth=97
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=node_StreamingConv_16_streaming_linebuffer_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> Quant_38_out0_stream[2];
    #pragma HLS STREAM variable=Quant_38_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_38_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> Quant_39_out0_stream[2];
    #pragma HLS STREAM variable=Quant_39_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_39_out0_stream[1] depth=67
    hls::stream<std::array<ap_uint<8>, 1>> Quant_39_out0_bww_stream[1];
    #pragma HLS STREAM variable=Quant_39_out0_bww_stream[0] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingMaxPool_19_window_stream[64];
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[0] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[2] depth=5
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[3] depth=7
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[4] depth=9
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[5] depth=11
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[6] depth=13
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[7] depth=15
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[8] depth=17
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[9] depth=19
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[10] depth=21
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[11] depth=23
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[12] depth=25
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[13] depth=27
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[14] depth=29
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[15] depth=31
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[16] depth=33
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[17] depth=35
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[18] depth=37
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[19] depth=39
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[20] depth=41
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[21] depth=43
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[22] depth=45
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[23] depth=47
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[24] depth=49
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[25] depth=51
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[26] depth=53
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[27] depth=55
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[28] depth=57
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[29] depth=59
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[30] depth=61
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[31] depth=63
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[32] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[33] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[34] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[35] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[36] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[37] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[38] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[39] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[40] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[41] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[42] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[43] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[44] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[45] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[46] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[47] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[48] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[49] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[50] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[51] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[52] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[53] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[54] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[55] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[56] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[57] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[58] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[59] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[60] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[61] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[62] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_window_stream[63] depth=65
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[63];
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[2] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[7] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[9] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[10] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[11] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[12] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[13] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[14] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[15] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[16] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[17] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[18] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[19] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[20] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[21] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[22] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[23] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[24] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[25] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[26] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[27] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[28] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[29] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[30] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[31] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[32] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[33] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[34] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[35] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[36] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[37] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[38] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[39] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[40] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[41] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[42] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[43] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[44] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[45] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[46] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[47] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[48] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[49] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[50] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[51] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[52] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[53] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[54] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[55] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[56] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[57] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[58] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[59] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[60] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[61] depth=65
    #pragma HLS STREAM variable=node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[62] depth=65
    hls::stream<std::array<ap_int<8>, 1>> Quant_40_out0_stream[1];
    #pragma HLS STREAM variable=Quant_40_out0_stream[0] depth=51
    hls::stream<std::array<ap_int<8>, 2>> Quant_41_out0_stream[1];
    #pragma HLS STREAM variable=Quant_41_out0_stream[0] depth=2
    mm2s<ap_int<8>, 1, 1, 3072>(in_data, Quant_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_21_out0_stream_0," << Quant_21_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_NHWCToStream_0_node_StreamingConv_0;
    BandwidthAdjustIncreaseStreams_NHWCToStream_0_node_StreamingConv_0.run<1>(Quant_21_out0_stream, Quant_21_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_21_out0_bww_stream_0," << Quant_21_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_21_out0_bww_stream_1," << Quant_21_out0_bww_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_0;
    node_StreamingConv_0_streaming_linebuffer_pixel_0.run<2>(Quant_21_out0_bww_stream[0], node_StreamingConv_0_window_stream_prepad[11], node_StreamingConv_0_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_11," << node_StreamingConv_0_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_0 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_1;
    node_StreamingConv_0_streaming_linebuffer_pixel_1.run<3>(Quant_21_out0_bww_stream[1], node_StreamingConv_0_window_stream_prepad[10], node_StreamingConv_0_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_10," << node_StreamingConv_0_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_1 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_2;
    node_StreamingConv_0_streaming_linebuffer_pixel_2.run<4>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[0], node_StreamingConv_0_window_stream_prepad[9], node_StreamingConv_0_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_9," << node_StreamingConv_0_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_2 46" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_3;
    node_StreamingConv_0_streaming_linebuffer_pixel_3.run<5>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[1], node_StreamingConv_0_window_stream_prepad[8], node_StreamingConv_0_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_8," << node_StreamingConv_0_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_3 46" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_4;
    node_StreamingConv_0_streaming_linebuffer_pixel_4.run<6>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[2], node_StreamingConv_0_window_stream_prepad[7], node_StreamingConv_0_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_7," << node_StreamingConv_0_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_4 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_5;
    node_StreamingConv_0_streaming_linebuffer_pixel_5.run<7>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[3], node_StreamingConv_0_window_stream_prepad[6], node_StreamingConv_0_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_6," << node_StreamingConv_0_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_5 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_6;
    node_StreamingConv_0_streaming_linebuffer_pixel_6.run<8>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[4], node_StreamingConv_0_window_stream_prepad[5], node_StreamingConv_0_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_5," << node_StreamingConv_0_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_6 46" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_7;
    node_StreamingConv_0_streaming_linebuffer_pixel_7.run<9>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[5], node_StreamingConv_0_window_stream_prepad[4], node_StreamingConv_0_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_4," << node_StreamingConv_0_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_7 46" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_8;
    node_StreamingConv_0_streaming_linebuffer_pixel_8.run<10>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[6], node_StreamingConv_0_window_stream_prepad[3], node_StreamingConv_0_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_3," << node_StreamingConv_0_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_8 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_9;
    node_StreamingConv_0_streaming_linebuffer_pixel_9.run<11>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[7], node_StreamingConv_0_window_stream_prepad[2], node_StreamingConv_0_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_2," << node_StreamingConv_0_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_9 4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_10;
    node_StreamingConv_0_streaming_linebuffer_pixel_10.run<12>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[8], node_StreamingConv_0_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_1," << node_StreamingConv_0_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
    > node_StreamingConv_0_streaming_linebuffer_pixel_11;
    node_StreamingConv_0_streaming_linebuffer_pixel_11.run<13>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[9], node_StreamingConv_0_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_0," << node_StreamingConv_0_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
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
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pad;
    node_StreamingConv_0_streaming_linebuffer_pad.run<14>(node_StreamingConv_0_window_stream_prepad, node_StreamingConv_0_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_0," << node_StreamingConv_0_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_1," << node_StreamingConv_0_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_2," << node_StreamingConv_0_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_3," << node_StreamingConv_0_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_4," << node_StreamingConv_0_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_5," << node_StreamingConv_0_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_6," << node_StreamingConv_0_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_7," << node_StreamingConv_0_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_8," << node_StreamingConv_0_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_9," << node_StreamingConv_0_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_10," << node_StreamingConv_0_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_11," << node_StreamingConv_0_window_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<5, ap_int<22>, ap_uint<8>>,  // Quantizer
        16,  // OUT_CH
        3,  // IN_CH
        32,  // OUT_HEIGHT
        32,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_0;
    node_StreamingConv_0.run<15>(node_StreamingConv_0_window_stream, node_StreamingConv_0_weights, node_StreamingConv_0_biases, Quant_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_22_out0_stream_0," << Quant_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_22_out0_stream_1," << Quant_22_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<16>(Quant_22_out0_stream, Quant_23_out0_stream, Quant_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_23_out0_stream_0," << Quant_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_23_out0_stream_1," << Quant_23_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_24_out0_stream_0," << Quant_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_24_out0_stream_1," << Quant_24_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_0;
    node_StreamingConv_2_streaming_linebuffer_pixel_0.run<17>(Quant_23_out0_stream[0], node_StreamingConv_2_window_stream_prepad[11], node_StreamingConv_2_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_11," << node_StreamingConv_2_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_0 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_1;
    node_StreamingConv_2_streaming_linebuffer_pixel_1.run<18>(Quant_23_out0_stream[1], node_StreamingConv_2_window_stream_prepad[10], node_StreamingConv_2_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_10," << node_StreamingConv_2_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_1 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_2;
    node_StreamingConv_2_streaming_linebuffer_pixel_2.run<19>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[0], node_StreamingConv_2_window_stream_prepad[9], node_StreamingConv_2_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_9," << node_StreamingConv_2_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_2 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_3;
    node_StreamingConv_2_streaming_linebuffer_pixel_3.run<20>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[1], node_StreamingConv_2_window_stream_prepad[8], node_StreamingConv_2_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_8," << node_StreamingConv_2_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_3 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_4;
    node_StreamingConv_2_streaming_linebuffer_pixel_4.run<21>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[2], node_StreamingConv_2_window_stream_prepad[7], node_StreamingConv_2_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_7," << node_StreamingConv_2_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_4 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_5;
    node_StreamingConv_2_streaming_linebuffer_pixel_5.run<22>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[3], node_StreamingConv_2_window_stream_prepad[6], node_StreamingConv_2_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_6," << node_StreamingConv_2_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_5 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_6;
    node_StreamingConv_2_streaming_linebuffer_pixel_6.run<23>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[4], node_StreamingConv_2_window_stream_prepad[5], node_StreamingConv_2_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_5," << node_StreamingConv_2_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_6 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_7;
    node_StreamingConv_2_streaming_linebuffer_pixel_7.run<24>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[5], node_StreamingConv_2_window_stream_prepad[4], node_StreamingConv_2_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_4," << node_StreamingConv_2_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_7 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_8;
    node_StreamingConv_2_streaming_linebuffer_pixel_8.run<25>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[6], node_StreamingConv_2_window_stream_prepad[3], node_StreamingConv_2_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_3," << node_StreamingConv_2_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_8 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_9;
    node_StreamingConv_2_streaming_linebuffer_pixel_9.run<26>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[7], node_StreamingConv_2_window_stream_prepad[2], node_StreamingConv_2_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_2," << node_StreamingConv_2_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_streaming_linebuffer_buffer_stream_9 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_10;
    node_StreamingConv_2_streaming_linebuffer_pixel_10.run<27>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[8], node_StreamingConv_2_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_1," << node_StreamingConv_2_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_2_streaming_linebuffer_pixel_11;
    node_StreamingConv_2_streaming_linebuffer_pixel_11.run<28>(node_StreamingConv_2_streaming_linebuffer_buffer_stream[9], node_StreamingConv_2_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_prepad_0," << node_StreamingConv_2_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        1  // CH_PAR
    > node_StreamingConv_2_streaming_linebuffer_pad;
    node_StreamingConv_2_streaming_linebuffer_pad.run<29>(node_StreamingConv_2_window_stream_prepad, node_StreamingConv_2_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_0," << node_StreamingConv_2_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_1," << node_StreamingConv_2_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_2," << node_StreamingConv_2_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_3," << node_StreamingConv_2_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_4," << node_StreamingConv_2_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_5," << node_StreamingConv_2_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_6," << node_StreamingConv_2_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_7," << node_StreamingConv_2_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_8," << node_StreamingConv_2_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_9," << node_StreamingConv_2_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_10," << node_StreamingConv_2_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_2_window_stream_11," << node_StreamingConv_2_window_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_2_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_2_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_uint<8>>,  // Quantizer
        16,  // OUT_CH
        16,  // IN_CH
        32,  // OUT_HEIGHT
        32,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_2;
    node_StreamingConv_2.run<30>(node_StreamingConv_2_window_stream, node_StreamingConv_2_weights, node_StreamingConv_2_biases, Quant_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_25_out0_stream_0," << Quant_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_25_out0_stream_1," << Quant_25_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_0;
    node_StreamingConv_4_streaming_linebuffer_pixel_0.run<31>(Quant_25_out0_stream[0], node_StreamingConv_4_window_stream_prepad[11], node_StreamingConv_4_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_11," << node_StreamingConv_4_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_0 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_1;
    node_StreamingConv_4_streaming_linebuffer_pixel_1.run<32>(Quant_25_out0_stream[1], node_StreamingConv_4_window_stream_prepad[10], node_StreamingConv_4_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_10," << node_StreamingConv_4_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_1 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_2;
    node_StreamingConv_4_streaming_linebuffer_pixel_2.run<33>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[0], node_StreamingConv_4_window_stream_prepad[9], node_StreamingConv_4_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_9," << node_StreamingConv_4_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_2 121" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_3;
    node_StreamingConv_4_streaming_linebuffer_pixel_3.run<34>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[1], node_StreamingConv_4_window_stream_prepad[8], node_StreamingConv_4_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_8," << node_StreamingConv_4_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_3 121" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_4;
    node_StreamingConv_4_streaming_linebuffer_pixel_4.run<35>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[2], node_StreamingConv_4_window_stream_prepad[7], node_StreamingConv_4_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_7," << node_StreamingConv_4_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_4 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_5;
    node_StreamingConv_4_streaming_linebuffer_pixel_5.run<36>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[3], node_StreamingConv_4_window_stream_prepad[6], node_StreamingConv_4_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_6," << node_StreamingConv_4_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_5 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_6;
    node_StreamingConv_4_streaming_linebuffer_pixel_6.run<37>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[4], node_StreamingConv_4_window_stream_prepad[5], node_StreamingConv_4_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_5," << node_StreamingConv_4_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_6 121" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_7;
    node_StreamingConv_4_streaming_linebuffer_pixel_7.run<38>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[5], node_StreamingConv_4_window_stream_prepad[4], node_StreamingConv_4_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_4," << node_StreamingConv_4_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_7 121" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_8;
    node_StreamingConv_4_streaming_linebuffer_pixel_8.run<39>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[6], node_StreamingConv_4_window_stream_prepad[3], node_StreamingConv_4_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_3," << node_StreamingConv_4_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_8 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_9;
    node_StreamingConv_4_streaming_linebuffer_pixel_9.run<40>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[7], node_StreamingConv_4_window_stream_prepad[2], node_StreamingConv_4_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_2," << node_StreamingConv_4_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_streaming_linebuffer_buffer_stream_9 9" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_10;
    node_StreamingConv_4_streaming_linebuffer_pixel_10.run<41>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[8], node_StreamingConv_4_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_1," << node_StreamingConv_4_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_11;
    node_StreamingConv_4_streaming_linebuffer_pixel_11.run<42>(node_StreamingConv_4_streaming_linebuffer_buffer_stream[9], node_StreamingConv_4_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_prepad_0," << node_StreamingConv_4_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pad;
    node_StreamingConv_4_streaming_linebuffer_pad.run<43>(node_StreamingConv_4_window_stream_prepad, node_StreamingConv_4_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_0," << node_StreamingConv_4_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_1," << node_StreamingConv_4_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_2," << node_StreamingConv_4_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_3," << node_StreamingConv_4_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_4," << node_StreamingConv_4_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_5," << node_StreamingConv_4_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_6," << node_StreamingConv_4_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_7," << node_StreamingConv_4_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_8," << node_StreamingConv_4_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_9," << node_StreamingConv_4_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_10," << node_StreamingConv_4_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_11," << node_StreamingConv_4_window_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        16,  // IN_CH
        32,  // OUT_HEIGHT
        32,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_4;
    node_StreamingConv_4.run<44>(node_StreamingConv_4_window_stream, node_StreamingConv_4_weights, node_StreamingConv_4_biases, Quant_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_26_out0_stream_0," << Quant_26_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_26_out0_stream_1," << Quant_26_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_uint<8>, 1>,  // TInputWordB
        ap_uint<8>,  // TInputB
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<10>,  // TAcc
        ReLU<ap_int<10>>,  // Activation
        DequantQuantPo2<0, ap_int<10>, ap_uint<8>>,  // Quantizer
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingAdd_5;
    node_StreamingAdd_5.run<45>(Quant_26_out0_stream, Quant_24_out0_stream, Quant_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_27_out0_stream_0," << Quant_27_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_27_out0_stream_1," << Quant_27_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<46>(Quant_27_out0_stream, Quant_28_out0_stream, Quant_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_28_out0_stream_0," << Quant_28_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_28_out0_stream_1," << Quant_28_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_29_out0_stream_0," << Quant_29_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_29_out0_stream_1," << Quant_29_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_0;
    node_StreamingConv_7_streaming_linebuffer_pixel_0.run<47>(Quant_28_out0_stream[1], node_StreamingConv_7_window_stream_prepad[14], node_StreamingConv_7_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_14," << node_StreamingConv_7_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_0 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_1;
    node_StreamingConv_7_streaming_linebuffer_pixel_1.run<48>(Quant_28_out0_stream[0], node_StreamingConv_7_window_stream_prepad[13], node_StreamingConv_7_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_13," << node_StreamingConv_7_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_1 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_8_streaming_linebuffer_pixel_0;
    node_StreamingConv_8_streaming_linebuffer_pixel_0.run<63>(Quant_29_out0_stream[0], node_StreamingConv_8_window_stream[2], node_StreamingConv_8_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_8_window_stream_2," << node_StreamingConv_8_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_8_streaming_linebuffer_buffer_stream_0 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_8_streaming_linebuffer_pixel_1;
    node_StreamingConv_8_streaming_linebuffer_pixel_1.run<64>(Quant_29_out0_stream[1], node_StreamingConv_8_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_8_window_stream_1," << node_StreamingConv_8_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_2;
    node_StreamingConv_7_streaming_linebuffer_pixel_2.run<49>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[0], node_StreamingConv_7_window_stream_prepad[12], node_StreamingConv_7_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_12," << node_StreamingConv_7_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_2 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_3;
    node_StreamingConv_7_streaming_linebuffer_pixel_3.run<50>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[1], node_StreamingConv_7_window_stream_prepad[11], node_StreamingConv_7_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_11," << node_StreamingConv_7_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_4 225" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_8_streaming_linebuffer_pixel_2;
    node_StreamingConv_8_streaming_linebuffer_pixel_2.run<65>(node_StreamingConv_8_streaming_linebuffer_buffer_stream[0], node_StreamingConv_8_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_8_window_stream_0," << node_StreamingConv_8_window_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_4;
    node_StreamingConv_7_streaming_linebuffer_pixel_4.run<51>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[2], node_StreamingConv_7_window_stream_prepad[10], node_StreamingConv_7_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_10," << node_StreamingConv_7_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_3 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_6;
    node_StreamingConv_7_streaming_linebuffer_pixel_6.run<53>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[4], node_StreamingConv_7_window_stream_prepad[8], node_StreamingConv_7_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_8," << node_StreamingConv_7_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_6 17" << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_8_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_8_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        DequantQuantEqual<ap_int<22>>,  // Activation
        DequantQuantPo2<8, ap_int<22>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        16,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_8;
    node_StreamingConv_8.run<67>(node_StreamingConv_8_window_stream, node_StreamingConv_8_weights, node_StreamingConv_8_biases, Quant_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_30_out0_stream_0," << Quant_30_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_30_out0_stream_1," << Quant_30_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_5;
    node_StreamingConv_7_streaming_linebuffer_pixel_5.run<52>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[3], node_StreamingConv_7_window_stream_prepad[9], node_StreamingConv_7_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_9," << node_StreamingConv_7_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_5 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_8;
    node_StreamingConv_7_streaming_linebuffer_pixel_8.run<55>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[6], node_StreamingConv_7_window_stream_prepad[6], node_StreamingConv_7_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_6," << node_StreamingConv_7_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_9 225" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_7;
    node_StreamingConv_7_streaming_linebuffer_pixel_7.run<54>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[5], node_StreamingConv_7_window_stream_prepad[7], node_StreamingConv_7_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_7," << node_StreamingConv_7_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_7 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_11;
    node_StreamingConv_7_streaming_linebuffer_pixel_11.run<58>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[9], node_StreamingConv_7_window_stream_prepad[3], node_StreamingConv_7_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_3," << node_StreamingConv_7_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_11 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_9;
    node_StreamingConv_7_streaming_linebuffer_pixel_9.run<56>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[7], node_StreamingConv_7_window_stream_prepad[5], node_StreamingConv_7_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_5," << node_StreamingConv_7_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_8 241" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_13;
    node_StreamingConv_7_streaming_linebuffer_pixel_13.run<60>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[11], node_StreamingConv_7_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_1," << node_StreamingConv_7_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_10;
    node_StreamingConv_7_streaming_linebuffer_pixel_10.run<57>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[8], node_StreamingConv_7_window_stream_prepad[4], node_StreamingConv_7_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_4," << node_StreamingConv_7_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_10 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_12;
    node_StreamingConv_7_streaming_linebuffer_pixel_12.run<59>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[10], node_StreamingConv_7_window_stream_prepad[2], node_StreamingConv_7_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_2," << node_StreamingConv_7_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_streaming_linebuffer_buffer_stream_12 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
    > node_StreamingConv_7_streaming_linebuffer_pixel_14;
    node_StreamingConv_7_streaming_linebuffer_pixel_14.run<61>(node_StreamingConv_7_streaming_linebuffer_buffer_stream[12], node_StreamingConv_7_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_prepad_0," << node_StreamingConv_7_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
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
        1  // CH_PAR
    > node_StreamingConv_7_streaming_linebuffer_pad;
    node_StreamingConv_7_streaming_linebuffer_pad.run<62>(node_StreamingConv_7_window_stream_prepad, node_StreamingConv_7_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_0," << node_StreamingConv_7_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_1," << node_StreamingConv_7_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_2," << node_StreamingConv_7_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_3," << node_StreamingConv_7_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_4," << node_StreamingConv_7_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_5," << node_StreamingConv_7_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_6," << node_StreamingConv_7_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_7," << node_StreamingConv_7_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_8," << node_StreamingConv_7_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_9," << node_StreamingConv_7_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_10," << node_StreamingConv_7_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_11," << node_StreamingConv_7_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_12," << node_StreamingConv_7_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_13," << node_StreamingConv_7_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_7_window_stream_14," << node_StreamingConv_7_window_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_7_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_7_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_uint<8>>,  // Quantizer
        32,  // OUT_CH
        16,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_7;
    node_StreamingConv_7.run<66>(node_StreamingConv_7_window_stream, node_StreamingConv_7_weights, node_StreamingConv_7_biases, Quant_31_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_31_out0_stream_0," << Quant_31_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_31_out0_stream_1," << Quant_31_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingConv_7_node_StreamingConv_10;
    BandwidthAdjustIncreaseChannels_node_StreamingConv_7_node_StreamingConv_10.run<68>(Quant_31_out0_stream, Quant_31_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_31_out0_bwch_stream_0," << Quant_31_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_31_out0_bwch_stream_1," << Quant_31_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_0;
    node_StreamingConv_10_streaming_linebuffer_pixel_0.run<69>(Quant_31_out0_bwch_stream[0], node_StreamingConv_10_window_stream_prepad[11], node_StreamingConv_10_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_11," << node_StreamingConv_10_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_0 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_1;
    node_StreamingConv_10_streaming_linebuffer_pixel_1.run<70>(Quant_31_out0_bwch_stream[1], node_StreamingConv_10_window_stream_prepad[10], node_StreamingConv_10_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_10," << node_StreamingConv_10_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_1 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_2;
    node_StreamingConv_10_streaming_linebuffer_pixel_2.run<71>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[0], node_StreamingConv_10_window_stream_prepad[9], node_StreamingConv_10_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_9," << node_StreamingConv_10_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_2 113" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_3;
    node_StreamingConv_10_streaming_linebuffer_pixel_3.run<72>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[1], node_StreamingConv_10_window_stream_prepad[8], node_StreamingConv_10_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_8," << node_StreamingConv_10_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_3 113" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_4;
    node_StreamingConv_10_streaming_linebuffer_pixel_4.run<73>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[2], node_StreamingConv_10_window_stream_prepad[7], node_StreamingConv_10_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_7," << node_StreamingConv_10_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_4 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_5;
    node_StreamingConv_10_streaming_linebuffer_pixel_5.run<74>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[3], node_StreamingConv_10_window_stream_prepad[6], node_StreamingConv_10_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_6," << node_StreamingConv_10_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_5 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_6;
    node_StreamingConv_10_streaming_linebuffer_pixel_6.run<75>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[4], node_StreamingConv_10_window_stream_prepad[5], node_StreamingConv_10_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_5," << node_StreamingConv_10_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_6 113" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_7;
    node_StreamingConv_10_streaming_linebuffer_pixel_7.run<76>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[5], node_StreamingConv_10_window_stream_prepad[4], node_StreamingConv_10_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_4," << node_StreamingConv_10_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_7 113" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_8;
    node_StreamingConv_10_streaming_linebuffer_pixel_8.run<77>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[6], node_StreamingConv_10_window_stream_prepad[3], node_StreamingConv_10_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_3," << node_StreamingConv_10_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_8 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_9;
    node_StreamingConv_10_streaming_linebuffer_pixel_9.run<78>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[7], node_StreamingConv_10_window_stream_prepad[2], node_StreamingConv_10_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_2," << node_StreamingConv_10_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_streaming_linebuffer_buffer_stream_9 17" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_10;
    node_StreamingConv_10_streaming_linebuffer_pixel_10.run<79>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[8], node_StreamingConv_10_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_1," << node_StreamingConv_10_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_11;
    node_StreamingConv_10_streaming_linebuffer_pixel_11.run<80>(node_StreamingConv_10_streaming_linebuffer_buffer_stream[9], node_StreamingConv_10_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_prepad_0," << node_StreamingConv_10_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
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
        2  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pad;
    node_StreamingConv_10_streaming_linebuffer_pad.run<81>(node_StreamingConv_10_window_stream_prepad, node_StreamingConv_10_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_0," << node_StreamingConv_10_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_1," << node_StreamingConv_10_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_2," << node_StreamingConv_10_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_3," << node_StreamingConv_10_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_4," << node_StreamingConv_10_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_5," << node_StreamingConv_10_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_6," << node_StreamingConv_10_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_7," << node_StreamingConv_10_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_8," << node_StreamingConv_10_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_9," << node_StreamingConv_10_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_10," << node_StreamingConv_10_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_11," << node_StreamingConv_10_window_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_10;
    node_StreamingConv_10.run<82>(node_StreamingConv_10_window_stream, node_StreamingConv_10_weights, node_StreamingConv_10_biases, Quant_32_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_32_out0_stream_0," << Quant_32_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_32_out0_stream_1," << Quant_32_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<9>,  // TAcc
        ReLU<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_uint<8>>,  // Quantizer
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingAdd_11;
    node_StreamingAdd_11.run<83>(Quant_32_out0_stream, Quant_30_out0_stream, Quant_33_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_33_out0_stream_0," << Quant_33_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_33_out0_stream_1," << Quant_33_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<84>(Quant_33_out0_stream, Quant_34_out0_stream, Quant_35_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_34_out0_stream_0," << Quant_34_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_34_out0_stream_1," << Quant_34_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_35_out0_stream_0," << Quant_35_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_35_out0_stream_1," << Quant_35_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_0;
    node_StreamingConv_13_streaming_linebuffer_pixel_0.run<85>(Quant_34_out0_stream[1], node_StreamingConv_13_window_stream_prepad[14], node_StreamingConv_13_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_14," << node_StreamingConv_13_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_0 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_1;
    node_StreamingConv_13_streaming_linebuffer_pixel_1.run<86>(Quant_34_out0_stream[0], node_StreamingConv_13_window_stream_prepad[13], node_StreamingConv_13_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_13," << node_StreamingConv_13_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_1 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_0;
    node_StreamingConv_14_streaming_linebuffer_pixel_0.run<101>(Quant_35_out0_stream[0], node_StreamingConv_14_window_stream[2], node_StreamingConv_14_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_2," << node_StreamingConv_14_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_streaming_linebuffer_buffer_stream_0 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_1;
    node_StreamingConv_14_streaming_linebuffer_pixel_1.run<102>(Quant_35_out0_stream[1], node_StreamingConv_14_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_1," << node_StreamingConv_14_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_2;
    node_StreamingConv_13_streaming_linebuffer_pixel_2.run<87>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[0], node_StreamingConv_13_window_stream_prepad[12], node_StreamingConv_13_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_12," << node_StreamingConv_13_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_2 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_3;
    node_StreamingConv_13_streaming_linebuffer_pixel_3.run<88>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[1], node_StreamingConv_13_window_stream_prepad[11], node_StreamingConv_13_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_11," << node_StreamingConv_13_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_4 193" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_2;
    node_StreamingConv_14_streaming_linebuffer_pixel_2.run<103>(node_StreamingConv_14_streaming_linebuffer_buffer_stream[0], node_StreamingConv_14_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_0," << node_StreamingConv_14_window_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_4;
    node_StreamingConv_13_streaming_linebuffer_pixel_4.run<89>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[2], node_StreamingConv_13_window_stream_prepad[10], node_StreamingConv_13_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_10," << node_StreamingConv_13_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_3 225" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_6;
    node_StreamingConv_13_streaming_linebuffer_pixel_6.run<91>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[4], node_StreamingConv_13_window_stream_prepad[8], node_StreamingConv_13_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_8," << node_StreamingConv_13_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_6 33" << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        DequantQuantEqual<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        32,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_14;
    node_StreamingConv_14.run<105>(node_StreamingConv_14_window_stream, node_StreamingConv_14_weights, node_StreamingConv_14_biases, Quant_36_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_36_out0_stream_0," << Quant_36_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_36_out0_stream_1," << Quant_36_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_5;
    node_StreamingConv_13_streaming_linebuffer_pixel_5.run<90>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[3], node_StreamingConv_13_window_stream_prepad[9], node_StreamingConv_13_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_9," << node_StreamingConv_13_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_5 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_8;
    node_StreamingConv_13_streaming_linebuffer_pixel_8.run<93>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[6], node_StreamingConv_13_window_stream_prepad[6], node_StreamingConv_13_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_6," << node_StreamingConv_13_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_9 193" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_7;
    node_StreamingConv_13_streaming_linebuffer_pixel_7.run<92>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[5], node_StreamingConv_13_window_stream_prepad[7], node_StreamingConv_13_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_7," << node_StreamingConv_13_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_7 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_11;
    node_StreamingConv_13_streaming_linebuffer_pixel_11.run<96>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[9], node_StreamingConv_13_window_stream_prepad[3], node_StreamingConv_13_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_3," << node_StreamingConv_13_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_11 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_9;
    node_StreamingConv_13_streaming_linebuffer_pixel_9.run<94>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[7], node_StreamingConv_13_window_stream_prepad[5], node_StreamingConv_13_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_5," << node_StreamingConv_13_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_8 225" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_13;
    node_StreamingConv_13_streaming_linebuffer_pixel_13.run<98>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[11], node_StreamingConv_13_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_1," << node_StreamingConv_13_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_10;
    node_StreamingConv_13_streaming_linebuffer_pixel_10.run<95>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[8], node_StreamingConv_13_window_stream_prepad[4], node_StreamingConv_13_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_4," << node_StreamingConv_13_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_10 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_12;
    node_StreamingConv_13_streaming_linebuffer_pixel_12.run<97>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[10], node_StreamingConv_13_window_stream_prepad[2], node_StreamingConv_13_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_2," << node_StreamingConv_13_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_streaming_linebuffer_buffer_stream_12 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
    > node_StreamingConv_13_streaming_linebuffer_pixel_14;
    node_StreamingConv_13_streaming_linebuffer_pixel_14.run<99>(node_StreamingConv_13_streaming_linebuffer_buffer_stream[12], node_StreamingConv_13_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_prepad_0," << node_StreamingConv_13_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
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
        1  // CH_PAR
    > node_StreamingConv_13_streaming_linebuffer_pad;
    node_StreamingConv_13_streaming_linebuffer_pad.run<100>(node_StreamingConv_13_window_stream_prepad, node_StreamingConv_13_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_0," << node_StreamingConv_13_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_1," << node_StreamingConv_13_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_2," << node_StreamingConv_13_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_3," << node_StreamingConv_13_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_4," << node_StreamingConv_13_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_5," << node_StreamingConv_13_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_6," << node_StreamingConv_13_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_7," << node_StreamingConv_13_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_8," << node_StreamingConv_13_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_9," << node_StreamingConv_13_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_10," << node_StreamingConv_13_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_11," << node_StreamingConv_13_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_12," << node_StreamingConv_13_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_13," << node_StreamingConv_13_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_13_window_stream_14," << node_StreamingConv_13_window_stream[14].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_13_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_13_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_13_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_13_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_uint<8>>,  // Quantizer
        64,  // OUT_CH
        32,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_13;
    node_StreamingConv_13.run<104>(node_StreamingConv_13_window_stream, node_StreamingConv_13_weights, node_StreamingConv_13_biases, Quant_37_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_37_out0_stream_0," << Quant_37_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_37_out0_stream_1," << Quant_37_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_0;
    node_StreamingConv_16_streaming_linebuffer_pixel_0.run<106>(Quant_37_out0_stream[0], node_StreamingConv_16_window_stream_prepad[11], node_StreamingConv_16_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_11," << node_StreamingConv_16_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_0 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_1;
    node_StreamingConv_16_streaming_linebuffer_pixel_1.run<107>(Quant_37_out0_stream[1], node_StreamingConv_16_window_stream_prepad[10], node_StreamingConv_16_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_10," << node_StreamingConv_16_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_1 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_2;
    node_StreamingConv_16_streaming_linebuffer_pixel_2.run<108>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[0], node_StreamingConv_16_window_stream_prepad[9], node_StreamingConv_16_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_9," << node_StreamingConv_16_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_2 97" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_3;
    node_StreamingConv_16_streaming_linebuffer_pixel_3.run<109>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[1], node_StreamingConv_16_window_stream_prepad[8], node_StreamingConv_16_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_8," << node_StreamingConv_16_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_3 97" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_4;
    node_StreamingConv_16_streaming_linebuffer_pixel_4.run<110>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[2], node_StreamingConv_16_window_stream_prepad[7], node_StreamingConv_16_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_7," << node_StreamingConv_16_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_4 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_5;
    node_StreamingConv_16_streaming_linebuffer_pixel_5.run<111>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[3], node_StreamingConv_16_window_stream_prepad[6], node_StreamingConv_16_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_6," << node_StreamingConv_16_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_5 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_6;
    node_StreamingConv_16_streaming_linebuffer_pixel_6.run<112>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[4], node_StreamingConv_16_window_stream_prepad[5], node_StreamingConv_16_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_5," << node_StreamingConv_16_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_6 97" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_7;
    node_StreamingConv_16_streaming_linebuffer_pixel_7.run<113>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[5], node_StreamingConv_16_window_stream_prepad[4], node_StreamingConv_16_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_4," << node_StreamingConv_16_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_7 97" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_8;
    node_StreamingConv_16_streaming_linebuffer_pixel_8.run<114>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[6], node_StreamingConv_16_window_stream_prepad[3], node_StreamingConv_16_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_3," << node_StreamingConv_16_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_8 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_9;
    node_StreamingConv_16_streaming_linebuffer_pixel_9.run<115>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[7], node_StreamingConv_16_window_stream_prepad[2], node_StreamingConv_16_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_2," << node_StreamingConv_16_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_streaming_linebuffer_buffer_stream_9 33" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_10;
    node_StreamingConv_16_streaming_linebuffer_pixel_10.run<116>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[8], node_StreamingConv_16_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_1," << node_StreamingConv_16_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_11;
    node_StreamingConv_16_streaming_linebuffer_pixel_11.run<117>(node_StreamingConv_16_streaming_linebuffer_buffer_stream[9], node_StreamingConv_16_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_prepad_0," << node_StreamingConv_16_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
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
        2  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pad;
    node_StreamingConv_16_streaming_linebuffer_pad.run<118>(node_StreamingConv_16_window_stream_prepad, node_StreamingConv_16_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_0," << node_StreamingConv_16_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_1," << node_StreamingConv_16_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_2," << node_StreamingConv_16_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_3," << node_StreamingConv_16_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_4," << node_StreamingConv_16_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_5," << node_StreamingConv_16_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_6," << node_StreamingConv_16_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_7," << node_StreamingConv_16_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_8," << node_StreamingConv_16_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_9," << node_StreamingConv_16_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_10," << node_StreamingConv_16_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_11," << node_StreamingConv_16_window_stream[11].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<7, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_16;
    node_StreamingConv_16.run<119>(node_StreamingConv_16_window_stream, node_StreamingConv_16_weights, node_StreamingConv_16_biases, Quant_38_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_38_out0_stream_0," << Quant_38_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_38_out0_stream_1," << Quant_38_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<9>,  // TAcc
        ReLU<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_uint<8>>,  // Quantizer
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingAdd_17;
    node_StreamingAdd_17.run<120>(Quant_38_out0_stream, Quant_36_out0_stream, Quant_39_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_39_out0_stream_0," << Quant_39_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_39_out0_stream_1," << Quant_39_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_node_StreamingAdd_17_node_StreamingMaxPool_19;
    BandwidthAdjustDecreaseStreams_node_StreamingAdd_17_node_StreamingMaxPool_19.run<121>(Quant_39_out0_stream, Quant_39_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_39_out0_bww_stream_0," << Quant_39_out0_bww_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_0;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_0.run<122>(Quant_39_out0_bww_stream[0], node_StreamingMaxPool_19_window_stream[63], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_63," << node_StreamingMaxPool_19_window_stream[63].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_0 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_1;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_1.run<123>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[0], node_StreamingMaxPool_19_window_stream[62], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_62," << node_StreamingMaxPool_19_window_stream[62].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_1 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_2;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_2.run<124>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[1], node_StreamingMaxPool_19_window_stream[61], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_61," << node_StreamingMaxPool_19_window_stream[61].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_2 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_3;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_3.run<125>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[2], node_StreamingMaxPool_19_window_stream[60], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_60," << node_StreamingMaxPool_19_window_stream[60].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_3 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_4;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_4.run<126>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[3], node_StreamingMaxPool_19_window_stream[59], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_59," << node_StreamingMaxPool_19_window_stream[59].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_4 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_5;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_5.run<127>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[4], node_StreamingMaxPool_19_window_stream[58], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_58," << node_StreamingMaxPool_19_window_stream[58].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_5 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_6;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_6.run<128>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[5], node_StreamingMaxPool_19_window_stream[57], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_57," << node_StreamingMaxPool_19_window_stream[57].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_6 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        7,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_7;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_7.run<129>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[6], node_StreamingMaxPool_19_window_stream[56], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_56," << node_StreamingMaxPool_19_window_stream[56].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_7 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_8;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_8.run<130>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[7], node_StreamingMaxPool_19_window_stream[55], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_55," << node_StreamingMaxPool_19_window_stream[55].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_8 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_9;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_9.run<131>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[8], node_StreamingMaxPool_19_window_stream[54], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_54," << node_StreamingMaxPool_19_window_stream[54].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_9 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_10;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_10.run<132>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[9], node_StreamingMaxPool_19_window_stream[53], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_53," << node_StreamingMaxPool_19_window_stream[53].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_10 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_11;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_11.run<133>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[10], node_StreamingMaxPool_19_window_stream[52], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_52," << node_StreamingMaxPool_19_window_stream[52].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_11 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_12;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_12.run<134>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[11], node_StreamingMaxPool_19_window_stream[51], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_51," << node_StreamingMaxPool_19_window_stream[51].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_12 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_13;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_13.run<135>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[12], node_StreamingMaxPool_19_window_stream[50], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_50," << node_StreamingMaxPool_19_window_stream[50].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_13 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_14;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_14.run<136>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[13], node_StreamingMaxPool_19_window_stream[49], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_49," << node_StreamingMaxPool_19_window_stream[49].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_14 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        6,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_15;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_15.run<137>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[14], node_StreamingMaxPool_19_window_stream[48], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_48," << node_StreamingMaxPool_19_window_stream[48].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_15 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_16;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_16.run<138>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[15], node_StreamingMaxPool_19_window_stream[47], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_47," << node_StreamingMaxPool_19_window_stream[47].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_16 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_17;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_17.run<139>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[16], node_StreamingMaxPool_19_window_stream[46], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_46," << node_StreamingMaxPool_19_window_stream[46].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_17 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_18;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_18.run<140>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[17], node_StreamingMaxPool_19_window_stream[45], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_45," << node_StreamingMaxPool_19_window_stream[45].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_18 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_19;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_19.run<141>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[18], node_StreamingMaxPool_19_window_stream[44], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_44," << node_StreamingMaxPool_19_window_stream[44].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_19 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_20;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_20.run<142>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[19], node_StreamingMaxPool_19_window_stream[43], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_43," << node_StreamingMaxPool_19_window_stream[43].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_20 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_21;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_21.run<143>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[20], node_StreamingMaxPool_19_window_stream[42], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_42," << node_StreamingMaxPool_19_window_stream[42].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_21 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_22;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_22.run<144>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[21], node_StreamingMaxPool_19_window_stream[41], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_41," << node_StreamingMaxPool_19_window_stream[41].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_22 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        5,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_23;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_23.run<145>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[22], node_StreamingMaxPool_19_window_stream[40], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_40," << node_StreamingMaxPool_19_window_stream[40].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_23 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_24;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_24.run<146>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[23], node_StreamingMaxPool_19_window_stream[39], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[24]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_39," << node_StreamingMaxPool_19_window_stream[39].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_24 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_25;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_25.run<147>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[24], node_StreamingMaxPool_19_window_stream[38], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[25]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_38," << node_StreamingMaxPool_19_window_stream[38].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_25 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_26;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_26.run<148>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[25], node_StreamingMaxPool_19_window_stream[37], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[26]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_37," << node_StreamingMaxPool_19_window_stream[37].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_26 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_27;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_27.run<149>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[26], node_StreamingMaxPool_19_window_stream[36], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[27]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_36," << node_StreamingMaxPool_19_window_stream[36].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_27 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_28;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_28.run<150>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[27], node_StreamingMaxPool_19_window_stream[35], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[28]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_35," << node_StreamingMaxPool_19_window_stream[35].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_28 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_29;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_29.run<151>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[28], node_StreamingMaxPool_19_window_stream[34], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[29]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_34," << node_StreamingMaxPool_19_window_stream[34].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_29 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_30;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_30.run<152>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[29], node_StreamingMaxPool_19_window_stream[33], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[30]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_33," << node_StreamingMaxPool_19_window_stream[33].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_30 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        4,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_31;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_31.run<153>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[30], node_StreamingMaxPool_19_window_stream[32], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[31]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_32," << node_StreamingMaxPool_19_window_stream[32].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_31 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_32;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_32.run<154>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[31], node_StreamingMaxPool_19_window_stream[31], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[32]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_31," << node_StreamingMaxPool_19_window_stream[31].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_32 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_33;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_33.run<155>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[32], node_StreamingMaxPool_19_window_stream[30], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[33]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_30," << node_StreamingMaxPool_19_window_stream[30].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_33 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_34;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_34.run<156>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[33], node_StreamingMaxPool_19_window_stream[29], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[34]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_29," << node_StreamingMaxPool_19_window_stream[29].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_34 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_35;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_35.run<157>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[34], node_StreamingMaxPool_19_window_stream[28], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[35]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_28," << node_StreamingMaxPool_19_window_stream[28].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_35 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_36;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_36.run<158>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[35], node_StreamingMaxPool_19_window_stream[27], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[36]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_27," << node_StreamingMaxPool_19_window_stream[27].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_36 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_37;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_37.run<159>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[36], node_StreamingMaxPool_19_window_stream[26], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[37]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_26," << node_StreamingMaxPool_19_window_stream[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_37 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_38;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_38.run<160>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[37], node_StreamingMaxPool_19_window_stream[25], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[38]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_25," << node_StreamingMaxPool_19_window_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_38 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        3,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_39;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_39.run<161>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[38], node_StreamingMaxPool_19_window_stream[24], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[39]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_24," << node_StreamingMaxPool_19_window_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_39 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_40;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_40.run<162>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[39], node_StreamingMaxPool_19_window_stream[23], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[40]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_23," << node_StreamingMaxPool_19_window_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_40 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_41;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_41.run<163>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[40], node_StreamingMaxPool_19_window_stream[22], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[41]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_22," << node_StreamingMaxPool_19_window_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_41 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_42;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_42.run<164>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[41], node_StreamingMaxPool_19_window_stream[21], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[42]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_21," << node_StreamingMaxPool_19_window_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_42 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_43;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_43.run<165>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[42], node_StreamingMaxPool_19_window_stream[20], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[43]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_20," << node_StreamingMaxPool_19_window_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_43 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_44;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_44.run<166>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[43], node_StreamingMaxPool_19_window_stream[19], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[44]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_19," << node_StreamingMaxPool_19_window_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_44 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_45;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_45.run<167>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[44], node_StreamingMaxPool_19_window_stream[18], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[45]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_18," << node_StreamingMaxPool_19_window_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_45 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_46;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_46.run<168>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[45], node_StreamingMaxPool_19_window_stream[17], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[46]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_17," << node_StreamingMaxPool_19_window_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_46 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_47;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_47.run<169>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[46], node_StreamingMaxPool_19_window_stream[16], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[47]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_16," << node_StreamingMaxPool_19_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_47 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_48;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_48.run<170>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[47], node_StreamingMaxPool_19_window_stream[15], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[48]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_15," << node_StreamingMaxPool_19_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_48 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_49;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_49.run<171>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[48], node_StreamingMaxPool_19_window_stream[14], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[49]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_14," << node_StreamingMaxPool_19_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_49 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_50;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_50.run<172>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[49], node_StreamingMaxPool_19_window_stream[13], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[50]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_13," << node_StreamingMaxPool_19_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_50 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_51;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_51.run<173>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[50], node_StreamingMaxPool_19_window_stream[12], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[51]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_12," << node_StreamingMaxPool_19_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_51 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_52;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_52.run<174>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[51], node_StreamingMaxPool_19_window_stream[11], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[52]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_11," << node_StreamingMaxPool_19_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_52 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_53;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_53.run<175>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[52], node_StreamingMaxPool_19_window_stream[10], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[53]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_10," << node_StreamingMaxPool_19_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_53 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_54;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_54.run<176>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[53], node_StreamingMaxPool_19_window_stream[9], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[54]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_9," << node_StreamingMaxPool_19_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_54 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_55;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_55.run<177>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[54], node_StreamingMaxPool_19_window_stream[8], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[55]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_8," << node_StreamingMaxPool_19_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_55 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        7,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_56;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_56.run<178>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[55], node_StreamingMaxPool_19_window_stream[7], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[56]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_7," << node_StreamingMaxPool_19_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_56 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        6,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_57;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_57.run<179>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[56], node_StreamingMaxPool_19_window_stream[6], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[57]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_6," << node_StreamingMaxPool_19_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_57 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        5,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_58;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_58.run<180>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[57], node_StreamingMaxPool_19_window_stream[5], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[58]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_5," << node_StreamingMaxPool_19_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_58 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_59;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_59.run<181>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[58], node_StreamingMaxPool_19_window_stream[4], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[59]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_4," << node_StreamingMaxPool_19_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_59 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_60;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_60.run<182>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[59], node_StreamingMaxPool_19_window_stream[3], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[60]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_3," << node_StreamingMaxPool_19_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_60 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_61;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_61.run<183>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[60], node_StreamingMaxPool_19_window_stream[2], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[61]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_2," << node_StreamingMaxPool_19_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_61 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_62;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_62.run<184>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[61], node_StreamingMaxPool_19_window_stream[1], node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[62]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_1," << node_StreamingMaxPool_19_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream_62 65" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        8,  // FH
        8,  // FW
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingMaxPool_19_streaming_linebuffer_pixel_63;
    node_StreamingMaxPool_19_streaming_linebuffer_pixel_63.run<185>(node_StreamingMaxPool_19_streaming_linebuffer_buffer_stream[62], node_StreamingMaxPool_19_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingMaxPool_19_window_stream_0," << node_StreamingMaxPool_19_window_stream[0].size() << std::endl;
    #endif
    StreamingMaxPool <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantPo2<1, ap_uint<8>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        1,  // IN_HEIGHT
        1,  // IN_WIDTH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > node_StreamingMaxPool_19;
    node_StreamingMaxPool_19.run<186>(node_StreamingMaxPool_19_window_stream, Quant_40_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_40_out0_stream_0," << Quant_40_out0_stream[0].size() << std::endl;
    #endif
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_weights dim=2 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_int<8>>,  // Quantizer
        10,  // OUT_CH
        64,  // IN_CH
        1,  // OUT_HEIGHT
        1,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_20;
    node_StreamingConv_20.run<187>(Quant_40_out0_stream, node_StreamingConv_20_weights, node_StreamingConv_20_biases, Quant_41_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_41_out0_stream_0," << Quant_41_out0_stream[0].size() << std::endl;
    #endif
    s2mm<ap_int<8>, 2, 1, 5>(Quant_41_out0_stream, out_data);
}