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
void mobilenet_v2(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis port=global_in
    #pragma HLS INTERFACE axis port=global_out
    hls::stream<std::array<ap_int<8>, 3>> Quant_107_out0_stream[4];
    #pragma HLS STREAM variable=Quant_107_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> Quant_107_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_107_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_107_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_window_stream[27];
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[0] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[1] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[2] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[3] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[4] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[5] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[6] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[7] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[8] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[9] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[10] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[11] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[12] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[13] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[14] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[15] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[16] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[17] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[18] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[19] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[20] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[21] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[22] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[23] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[24] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[25] depth=47
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream[26] depth=47
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_window_stream_prepad[27];
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[0] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[1] depth=14
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[2] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[3] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[4] depth=5
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[5] depth=14
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[6] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[7] depth=11
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[8] depth=6
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[9] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[10] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[11] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[12] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[13] depth=9
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[14] depth=15
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[15] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[16] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[17] depth=10
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[18] depth=12
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[19] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[20] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[21] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[22] depth=13
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[23] depth=14
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[24] depth=14
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[25] depth=14
    #pragma HLS STREAM variable=node_StreamingConv_0_window_stream_prepad[26] depth=14
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_0_streaming_linebuffer_buffer_stream[23];
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[5] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[6] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[7] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[8] depth=163
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[14] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[15] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[16] depth=166
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[17] depth=163
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[18] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[19] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[20] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[21] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_0_streaming_linebuffer_buffer_stream[22] depth=4
    hls::stream<std::array<ap_uint<8>, 2>> Quant_108_out0_stream[4];
    #pragma HLS STREAM variable=Quant_108_out0_stream[0] depth=9
    #pragma HLS STREAM variable=Quant_108_out0_stream[1] depth=9
    #pragma HLS STREAM variable=Quant_108_out0_stream[2] depth=9
    #pragma HLS STREAM variable=Quant_108_out0_stream[3] depth=9
    hls::stream<std::array<ap_uint<8>, 1>> Quant_108_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_108_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_108_out0_bwch_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_108_out0_bwch_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_108_out0_bwch_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_2_window_stream[18];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[14] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[15] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[16] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream[17] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_2_window_stream_prepad[18];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[0] depth=67
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[1] depth=35
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[2] depth=1033
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[3] depth=1033
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[4] depth=37
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[6] depth=71
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[7] depth=38
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[8] depth=138
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[9] depth=138
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[10] depth=72
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[11] depth=40
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[12] depth=106
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[13] depth=74
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[14] depth=108
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[15] depth=108
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[16] depth=108
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_window_stream_prepad[17] depth=76
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[14];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[2] depth=897
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[3] depth=897
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[4] depth=865
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[5] depth=865
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[6] depth=33
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[7] depth=33
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[8] depth=897
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[9] depth=897
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[10] depth=865
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[11] depth=865
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[12] depth=33
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[13] depth=33
    hls::stream<std::array<ap_uint<8>, 1>> Quant_109_out0_stream[4];
    #pragma HLS STREAM variable=Quant_109_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_109_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_109_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_109_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 8>> Quant_109_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_109_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_109_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_109_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_109_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 8>> node_StreamingConv_4_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[0] depth=2
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[1] depth=2
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[2] depth=2
    #pragma HLS STREAM variable=node_StreamingConv_4_window_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 2>> Quant_110_out0_stream[4];
    #pragma HLS STREAM variable=Quant_110_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_110_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_110_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_110_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_110_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_110_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_110_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_110_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_110_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_5_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_5_window_stream[0] depth=3
    #pragma HLS STREAM variable=node_StreamingConv_5_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingConv_5_window_stream[2] depth=3
    #pragma HLS STREAM variable=node_StreamingConv_5_window_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 2>> Quant_111_out0_stream[4];
    #pragma HLS STREAM variable=Quant_111_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_111_out0_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_111_out0_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_111_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingDepthwiseConv_7_window_stream[27];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[14] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[15] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[16] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[17] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[18] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[19] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[20] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[21] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[22] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[23] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[24] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[25] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream[26] depth=4
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingDepthwiseConv_7_window_stream_prepad[27];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[0] depth=51
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[1] depth=147
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[2] depth=99
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[3] depth=99
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[4] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[5] depth=107
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[6] depth=59
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[7] depth=59
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[8] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[9] depth=52
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[10] depth=100
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[11] depth=61
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[12] depth=61
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[13] depth=52
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[14] depth=100
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[15] depth=63
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[16] depth=63
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[17] depth=52
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[18] depth=63
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[19] depth=65
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[20] depth=65
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[21] depth=65
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[22] depth=65
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[23] depth=67
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[24] depth=67
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[25] depth=67
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_window_stream_prepad[26] depth=67
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[23];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[0] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[1] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[2] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[3] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[4] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[5] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[6] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[7] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[8] depth=1249
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[9] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[10] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[11] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[12] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[13] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[14] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[15] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[16] depth=1297
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[17] depth=1249
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[18] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[19] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[20] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[21] depth=49
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[22] depth=49
    hls::stream<std::array<ap_uint<8>, 2>> Quant_112_out0_stream[4];
    #pragma HLS STREAM variable=Quant_112_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_112_out0_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_112_out0_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_112_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> node_StreamingConv_9_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_9_window_stream[0] depth=362
    #pragma HLS STREAM variable=node_StreamingConv_9_window_stream[1] depth=362
    #pragma HLS STREAM variable=node_StreamingConv_9_window_stream[2] depth=362
    #pragma HLS STREAM variable=node_StreamingConv_9_window_stream[3] depth=362
    hls::stream<std::array<ap_int<8>, 6>> Quant_113_out0_stream[4];
    #pragma HLS STREAM variable=Quant_113_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_113_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_113_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_113_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_114_out0_stream[4];
    #pragma HLS STREAM variable=Quant_114_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_114_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_114_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_114_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_115_out0_stream[4];
    #pragma HLS STREAM variable=Quant_115_out0_stream[0] depth=79
    #pragma HLS STREAM variable=Quant_115_out0_stream[1] depth=79
    #pragma HLS STREAM variable=Quant_115_out0_stream[2] depth=79
    #pragma HLS STREAM variable=Quant_115_out0_stream[3] depth=79
    hls::stream<std::array<ap_int<8>, 6>> node_StreamingConv_10_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_10_window_stream[3] depth=4
    hls::stream<std::array<ap_uint<8>, 3>> Quant_116_out0_stream[4];
    #pragma HLS STREAM variable=Quant_116_out0_stream[0] depth=33
    #pragma HLS STREAM variable=Quant_116_out0_stream[1] depth=33
    #pragma HLS STREAM variable=Quant_116_out0_stream[2] depth=33
    #pragma HLS STREAM variable=Quant_116_out0_stream[3] depth=33
    hls::stream<std::array<ap_uint<8>, 1>> Quant_116_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_116_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_116_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_116_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_116_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_12_window_stream[18];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[14] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[15] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[16] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream[17] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_12_window_stream_prepad[18];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[0] depth=291
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[1] depth=147
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[2] depth=2601
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[3] depth=2601
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[4] depth=149
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[5] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[6] depth=295
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[7] depth=150
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[8] depth=586
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[9] depth=586
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[10] depth=296
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[11] depth=152
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[12] depth=442
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[13] depth=298
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[14] depth=444
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[15] depth=444
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[16] depth=444
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_window_stream_prepad[17] depth=300
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[14];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[0] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[1] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[2] depth=2017
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[3] depth=2017
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[4] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[5] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[6] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[7] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[8] depth=2017
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[9] depth=2017
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[10] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[11] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[12] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[13] depth=145
    hls::stream<std::array<ap_uint<8>, 1>> Quant_117_out0_stream[4];
    #pragma HLS STREAM variable=Quant_117_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_117_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_117_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_117_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 3>> Quant_117_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_117_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_117_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_117_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_117_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> node_StreamingConv_14_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[0] depth=62
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[1] depth=62
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[2] depth=62
    #pragma HLS STREAM variable=node_StreamingConv_14_window_stream[3] depth=62
    hls::stream<std::array<ap_int<8>, 6>> Quant_118_out0_stream[4];
    #pragma HLS STREAM variable=Quant_118_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_118_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_118_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_118_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_119_out0_stream[4];
    #pragma HLS STREAM variable=Quant_119_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_119_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_119_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_119_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 6>> node_StreamingConv_16_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_16_window_stream[3] depth=4
    hls::stream<std::array<ap_uint<8>, 3>> Quant_120_out0_stream[4];
    #pragma HLS STREAM variable=Quant_120_out0_stream[0] depth=33
    #pragma HLS STREAM variable=Quant_120_out0_stream[1] depth=33
    #pragma HLS STREAM variable=Quant_120_out0_stream[2] depth=33
    #pragma HLS STREAM variable=Quant_120_out0_stream[3] depth=33
    hls::stream<std::array<ap_uint<8>, 1>> Quant_120_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_120_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_120_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_120_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_120_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_18_window_stream[27];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[14] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[15] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[16] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[17] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[18] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[19] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[20] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[21] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[22] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[23] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[24] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[25] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream[26] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_18_window_stream_prepad[27];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[0] depth=147
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[1] depth=435
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[2] depth=291
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[3] depth=291
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[4] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[5] depth=299
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[6] depth=155
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[7] depth=155
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[8] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[9] depth=148
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[10] depth=292
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[11] depth=157
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[12] depth=157
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[13] depth=148
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[14] depth=292
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[15] depth=159
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[16] depth=159
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[17] depth=148
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[18] depth=159
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[19] depth=161
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[20] depth=161
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[21] depth=161
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[22] depth=161
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[23] depth=163
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[24] depth=163
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[25] depth=163
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_window_stream_prepad[26] depth=163
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[23];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[0] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[1] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[2] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[3] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[4] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[5] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[6] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[7] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[8] depth=1729
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[9] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[10] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[11] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[12] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[13] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[14] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[15] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[16] depth=1873
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[17] depth=1729
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[18] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[19] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[20] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[21] depth=145
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[22] depth=145
    hls::stream<std::array<ap_uint<8>, 1>> Quant_121_out0_stream[4];
    #pragma HLS STREAM variable=Quant_121_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_121_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_121_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_121_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 9>> Quant_121_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_121_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_121_out0_bwch_stream[1] depth=2
    #pragma HLS STREAM variable=Quant_121_out0_bwch_stream[2] depth=2
    #pragma HLS STREAM variable=Quant_121_out0_bwch_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> node_StreamingConv_20_window_stream[4];
    #pragma HLS STREAM variable=node_StreamingConv_20_window_stream[0] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_20_window_stream[1] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_20_window_stream[2] depth=36
    #pragma HLS STREAM variable=node_StreamingConv_20_window_stream[3] depth=36
    hls::stream<std::array<ap_int<8>, 1>> Quant_122_out0_stream[4];
    #pragma HLS STREAM variable=Quant_122_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_122_out0_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_122_out0_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_122_out0_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 1>> Quant_123_out0_stream[4];
    #pragma HLS STREAM variable=Quant_123_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_123_out0_stream[1] depth=4
    #pragma HLS STREAM variable=Quant_123_out0_stream[2] depth=35
    #pragma HLS STREAM variable=Quant_123_out0_stream[3] depth=35
    hls::stream<std::array<ap_int<8>, 1>> Quant_124_out0_stream[4];
    #pragma HLS STREAM variable=Quant_124_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_124_out0_stream[1] depth=4
    #pragma HLS STREAM variable=Quant_124_out0_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_124_out0_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 1>> Quant_123_out0_bww_stream[2];
    #pragma HLS STREAM variable=Quant_123_out0_bww_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_123_out0_bww_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_124_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_124_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_124_out0_bwch_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_124_out0_bwch_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_124_out0_bwch_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 16>> Quant_124_out0_bww_stream[2];
    #pragma HLS STREAM variable=Quant_124_out0_bww_stream[0] depth=49
    #pragma HLS STREAM variable=Quant_124_out0_bww_stream[1] depth=49
    hls::stream<std::array<ap_int<8>, 1>> node_StreamingConv_21_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_21_window_stream[0] depth=204
    #pragma HLS STREAM variable=node_StreamingConv_21_window_stream[1] depth=204
    hls::stream<std::array<ap_uint<8>, 16>> Quant_125_out0_stream[2];
    #pragma HLS STREAM variable=Quant_125_out0_stream[0] depth=12
    #pragma HLS STREAM variable=Quant_125_out0_stream[1] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> Quant_125_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_125_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_125_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_23_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_23_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[0] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[1] depth=195
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[2] depth=197
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[4] depth=199
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[6] depth=200
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[8] depth=202
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[10] depth=204
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[4] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[8] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[9] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> Quant_126_out0_stream[2];
    #pragma HLS STREAM variable=Quant_126_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_126_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_25_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_25_window_stream[0] depth=99
    #pragma HLS STREAM variable=node_StreamingConv_25_window_stream[1] depth=99
    hls::stream<std::array<ap_int<8>, 16>> Quant_127_out0_stream[2];
    #pragma HLS STREAM variable=Quant_127_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_127_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_128_out0_stream[2];
    #pragma HLS STREAM variable=Quant_128_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_128_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 16>> Quant_128_out0_bww_stream[4];
    #pragma HLS STREAM variable=Quant_128_out0_bww_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_128_out0_bww_stream[1] depth=4
    #pragma HLS STREAM variable=Quant_128_out0_bww_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_128_out0_bww_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 1>> Quant_128_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_128_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_128_out0_bwch_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_128_out0_bwch_stream[2] depth=3
    #pragma HLS STREAM variable=Quant_128_out0_bwch_stream[3] depth=3
    hls::stream<std::array<ap_int<8>, 1>> Quant_129_out0_stream[4];
    #pragma HLS STREAM variable=Quant_129_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_129_out0_stream[1] depth=4
    #pragma HLS STREAM variable=Quant_129_out0_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_129_out0_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 1>> Quant_130_out0_stream[4];
    #pragma HLS STREAM variable=Quant_130_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_130_out0_stream[1] depth=4
    #pragma HLS STREAM variable=Quant_130_out0_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_130_out0_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 16>> Quant_129_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_129_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_129_out0_bwch_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_129_out0_bwch_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_129_out0_bwch_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 16>> Quant_130_out0_bwch_stream[4];
    #pragma HLS STREAM variable=Quant_130_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_130_out0_bwch_stream[1] depth=3
    #pragma HLS STREAM variable=Quant_130_out0_bwch_stream[2] depth=4
    #pragma HLS STREAM variable=Quant_130_out0_bwch_stream[3] depth=4
    hls::stream<std::array<ap_int<8>, 16>> Quant_129_out0_bww_stream[2];
    #pragma HLS STREAM variable=Quant_129_out0_bww_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_129_out0_bww_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_130_out0_bww_stream[2];
    #pragma HLS STREAM variable=Quant_130_out0_bww_stream[0] depth=39
    #pragma HLS STREAM variable=Quant_130_out0_bww_stream[1] depth=39
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_27_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_27_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_27_window_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_131_out0_stream[2];
    #pragma HLS STREAM variable=Quant_131_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_131_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_29_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_29_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[0] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[1] depth=195
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[2] depth=197
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[4] depth=199
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[6] depth=200
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[8] depth=202
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[10] depth=204
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[4] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[8] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[9] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> Quant_132_out0_stream[2];
    #pragma HLS STREAM variable=Quant_132_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_132_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_31_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_31_window_stream[0] depth=99
    #pragma HLS STREAM variable=node_StreamingConv_31_window_stream[1] depth=99
    hls::stream<std::array<ap_int<8>, 16>> Quant_133_out0_stream[2];
    #pragma HLS STREAM variable=Quant_133_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_133_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_134_out0_stream[2];
    #pragma HLS STREAM variable=Quant_134_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_134_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_33_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_33_window_stream[0] depth=2
    #pragma HLS STREAM variable=node_StreamingConv_33_window_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> Quant_135_out0_stream[2];
    #pragma HLS STREAM variable=Quant_135_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_135_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_35_window_stream[15];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[11] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[12] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[13] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream[14] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_35_window_stream_prepad[15];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[0] depth=195
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[3] depth=395
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[5] depth=196
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[6] depth=388
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[7] depth=196
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[8] depth=388
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[9] depth=196
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[10] depth=207
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[11] depth=209
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[12] depth=209
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[13] depth=211
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_window_stream_prepad[14] depth=211
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[13];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[0] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[1] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[2] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[4] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[5] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[6] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[7] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[8] depth=2497
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[9] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[10] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[11] depth=193
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[12] depth=193
    hls::stream<std::array<ap_uint<8>, 1>> Quant_136_out0_stream[2];
    #pragma HLS STREAM variable=Quant_136_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_136_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_37_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_37_window_stream[0] depth=788
    #pragma HLS STREAM variable=node_StreamingConv_37_window_stream[1] depth=788
    hls::stream<std::array<ap_int<8>, 8>> Quant_137_out0_stream[2];
    #pragma HLS STREAM variable=Quant_137_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_137_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_138_out0_stream[2];
    #pragma HLS STREAM variable=Quant_138_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_138_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_139_out0_stream[2];
    #pragma HLS STREAM variable=Quant_139_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_139_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_139_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_139_out0_bwch_stream[0] depth=42
    #pragma HLS STREAM variable=Quant_139_out0_bwch_stream[1] depth=42
    hls::stream<std::array<ap_int<8>, 8>> node_StreamingConv_38_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_38_window_stream[0] depth=8
    #pragma HLS STREAM variable=node_StreamingConv_38_window_stream[1] depth=8
    hls::stream<std::array<ap_uint<8>, 2>> Quant_140_out0_stream[2];
    #pragma HLS STREAM variable=Quant_140_out0_stream[0] depth=97
    #pragma HLS STREAM variable=Quant_140_out0_stream[1] depth=97
    hls::stream<std::array<ap_uint<8>, 1>> Quant_140_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_140_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_140_out0_bwch_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_40_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_40_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[4] depth=391
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[6] depth=392
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[8] depth=394
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[10] depth=396
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> Quant_141_out0_stream[2];
    #pragma HLS STREAM variable=Quant_141_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_141_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_42_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_42_window_stream[0] depth=290
    #pragma HLS STREAM variable=node_StreamingConv_42_window_stream[1] depth=290
    hls::stream<std::array<ap_int<8>, 16>> Quant_142_out0_stream[2];
    #pragma HLS STREAM variable=Quant_142_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_142_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_143_out0_stream[2];
    #pragma HLS STREAM variable=Quant_143_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_143_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 8>> Quant_143_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_143_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_143_out0_bwch_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_144_out0_stream[2];
    #pragma HLS STREAM variable=Quant_144_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_144_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_145_out0_stream[2];
    #pragma HLS STREAM variable=Quant_145_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_145_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_144_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_144_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_144_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 16>> Quant_145_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_145_out0_bwch_stream[0] depth=42
    #pragma HLS STREAM variable=Quant_145_out0_bwch_stream[1] depth=42
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_44_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_44_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_44_window_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_146_out0_stream[2];
    #pragma HLS STREAM variable=Quant_146_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_146_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_46_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_46_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[4] depth=391
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[6] depth=392
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[8] depth=394
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[10] depth=396
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> Quant_147_out0_stream[2];
    #pragma HLS STREAM variable=Quant_147_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_147_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_48_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_48_window_stream[0] depth=290
    #pragma HLS STREAM variable=node_StreamingConv_48_window_stream[1] depth=290
    hls::stream<std::array<ap_int<8>, 16>> Quant_148_out0_stream[2];
    #pragma HLS STREAM variable=Quant_148_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_148_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_149_out0_stream[2];
    #pragma HLS STREAM variable=Quant_149_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_149_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 8>> Quant_149_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_149_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_149_out0_bwch_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_150_out0_stream[2];
    #pragma HLS STREAM variable=Quant_150_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_150_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 8>> Quant_151_out0_stream[2];
    #pragma HLS STREAM variable=Quant_151_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_151_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_150_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_150_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_150_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 16>> Quant_151_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_151_out0_bwch_stream[0] depth=42
    #pragma HLS STREAM variable=Quant_151_out0_bwch_stream[1] depth=42
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_50_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_50_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_50_window_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_152_out0_stream[2];
    #pragma HLS STREAM variable=Quant_152_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_152_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_52_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_52_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[4] depth=391
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[6] depth=392
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[8] depth=394
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[10] depth=396
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> Quant_153_out0_stream[2];
    #pragma HLS STREAM variable=Quant_153_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_153_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingConv_54_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_54_window_stream[0] depth=290
    #pragma HLS STREAM variable=node_StreamingConv_54_window_stream[1] depth=290
    hls::stream<std::array<ap_int<8>, 16>> Quant_154_out0_stream[2];
    #pragma HLS STREAM variable=Quant_154_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_154_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> Quant_155_out0_stream[2];
    #pragma HLS STREAM variable=Quant_155_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_155_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 16>> node_StreamingConv_56_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_56_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingConv_56_window_stream[1] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> Quant_156_out0_stream[2];
    #pragma HLS STREAM variable=Quant_156_out0_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_156_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_58_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_58_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[0] depth=771
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[2] depth=389
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[4] depth=391
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[6] depth=392
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[8] depth=394
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[10] depth=396
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[0] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[1] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[2] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[3] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[4] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[5] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[6] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[7] depth=2305
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[8] depth=385
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[9] depth=385
    hls::stream<std::array<ap_uint<8>, 1>> Quant_157_out0_stream[2];
    #pragma HLS STREAM variable=Quant_157_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_157_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 4>> Quant_157_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_157_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_157_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> node_StreamingConv_60_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_60_window_stream[0] depth=73
    #pragma HLS STREAM variable=node_StreamingConv_60_window_stream[1] depth=73
    hls::stream<std::array<ap_int<8>, 6>> Quant_158_out0_stream[2];
    #pragma HLS STREAM variable=Quant_158_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_158_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_159_out0_stream[2];
    #pragma HLS STREAM variable=Quant_159_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_159_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_160_out0_stream[2];
    #pragma HLS STREAM variable=Quant_160_out0_stream[0] depth=163
    #pragma HLS STREAM variable=Quant_160_out0_stream[1] depth=163
    hls::stream<std::array<ap_int<8>, 6>> node_StreamingConv_61_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_61_window_stream[0] depth=16
    #pragma HLS STREAM variable=node_StreamingConv_61_window_stream[1] depth=16
    hls::stream<std::array<ap_uint<8>, 6>> Quant_161_out0_stream[2];
    #pragma HLS STREAM variable=Quant_161_out0_stream[0] depth=81
    #pragma HLS STREAM variable=Quant_161_out0_stream[1] depth=81
    hls::stream<std::array<ap_uint<8>, 1>> Quant_161_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_161_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_161_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_63_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_63_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[0] depth=1155
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[2] depth=581
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[4] depth=583
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[6] depth=584
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[8] depth=586
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[10] depth=588
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[2] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[3] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[5] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[6] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[7] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[8] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[9] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> Quant_162_out0_stream[2];
    #pragma HLS STREAM variable=Quant_162_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_162_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 6>> Quant_162_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_162_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_162_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> node_StreamingConv_65_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_65_window_stream[0] depth=61
    #pragma HLS STREAM variable=node_StreamingConv_65_window_stream[1] depth=61
    hls::stream<std::array<ap_int<8>, 6>> Quant_163_out0_stream[2];
    #pragma HLS STREAM variable=Quant_163_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_163_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_164_out0_stream[2];
    #pragma HLS STREAM variable=Quant_164_out0_stream[0] depth=4
    #pragma HLS STREAM variable=Quant_164_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 6>> Quant_165_out0_stream[2];
    #pragma HLS STREAM variable=Quant_165_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_165_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_166_out0_stream[2];
    #pragma HLS STREAM variable=Quant_166_out0_stream[0] depth=163
    #pragma HLS STREAM variable=Quant_166_out0_stream[1] depth=163
    hls::stream<std::array<ap_int<8>, 6>> node_StreamingConv_67_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_67_window_stream[0] depth=16
    #pragma HLS STREAM variable=node_StreamingConv_67_window_stream[1] depth=16
    hls::stream<std::array<ap_uint<8>, 6>> Quant_167_out0_stream[2];
    #pragma HLS STREAM variable=Quant_167_out0_stream[0] depth=81
    #pragma HLS STREAM variable=Quant_167_out0_stream[1] depth=81
    hls::stream<std::array<ap_uint<8>, 1>> Quant_167_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_167_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_167_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_69_window_stream[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[0] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[1] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[2] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[3] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[4] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[5] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[6] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[7] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[8] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[9] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[10] depth=4
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream[11] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_69_window_stream_prepad[12];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[0] depth=1155
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[1] depth=579
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[2] depth=581
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[4] depth=583
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[6] depth=584
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[8] depth=586
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[10] depth=588
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_window_stream_prepad[11] depth=12
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[10];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[2] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[3] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[5] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[6] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[7] depth=3457
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[8] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[9] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> Quant_168_out0_stream[2];
    #pragma HLS STREAM variable=Quant_168_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_168_out0_stream[1] depth=3
    hls::stream<std::array<ap_uint<8>, 6>> Quant_168_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_168_out0_bwch_stream[0] depth=2
    #pragma HLS STREAM variable=Quant_168_out0_bwch_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> node_StreamingConv_71_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_71_window_stream[0] depth=61
    #pragma HLS STREAM variable=node_StreamingConv_71_window_stream[1] depth=61
    hls::stream<std::array<ap_int<8>, 6>> Quant_169_out0_stream[2];
    #pragma HLS STREAM variable=Quant_169_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_169_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> Quant_170_out0_stream[2];
    #pragma HLS STREAM variable=Quant_170_out0_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_170_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 6>> node_StreamingConv_73_window_stream[2];
    #pragma HLS STREAM variable=node_StreamingConv_73_window_stream[0] depth=16
    #pragma HLS STREAM variable=node_StreamingConv_73_window_stream[1] depth=16
    hls::stream<std::array<ap_uint<8>, 6>> Quant_171_out0_stream[2];
    #pragma HLS STREAM variable=Quant_171_out0_stream[0] depth=81
    #pragma HLS STREAM variable=Quant_171_out0_stream[1] depth=81
    hls::stream<std::array<ap_uint<8>, 1>> Quant_171_out0_bwch_stream[2];
    #pragma HLS STREAM variable=Quant_171_out0_bwch_stream[0] depth=3
    #pragma HLS STREAM variable=Quant_171_out0_bwch_stream[1] depth=578
    hls::stream<std::array<ap_uint<8>, 1>> Quant_171_out0_bww_stream[1];
    #pragma HLS STREAM variable=Quant_171_out0_bww_stream[0] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_75_window_stream[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[0] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[2] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[3] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[4] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[5] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[6] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[7] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream[8] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_75_window_stream_prepad[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[0] depth=579
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[4] depth=11
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[5] depth=13
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[6] depth=15
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[7] depth=17
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_window_stream_prepad[8] depth=19
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[8];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[0] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[1] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[2] depth=6913
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[3] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[4] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[5] depth=6913
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[6] depth=577
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[7] depth=577
    hls::stream<std::array<ap_uint<8>, 1>> Quant_172_out0_stream[1];
    #pragma HLS STREAM variable=Quant_172_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> Quant_172_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_172_out0_bwch_stream[0] depth=203
    hls::stream<std::array<ap_int<8>, 4>> Quant_173_out0_stream[1];
    #pragma HLS STREAM variable=Quant_173_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> Quant_174_out0_stream[1];
    #pragma HLS STREAM variable=Quant_174_out0_stream[0] depth=22
    hls::stream<std::array<ap_int<8>, 4>> Quant_175_out0_stream[1];
    #pragma HLS STREAM variable=Quant_175_out0_stream[0] depth=22
    hls::stream<std::array<ap_int<8>, 2>> Quant_174_out0_bwch_gcd_stream[1];
    #pragma HLS STREAM variable=Quant_174_out0_bwch_gcd_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> Quant_175_out0_bwch_gcd_stream[1];
    #pragma HLS STREAM variable=Quant_175_out0_bwch_gcd_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 10>> Quant_174_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_174_out0_bwch_stream[0] depth=16
    hls::stream<std::array<ap_int<8>, 10>> Quant_175_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_175_out0_bwch_stream[0] depth=162
    hls::stream<std::array<ap_uint<8>, 6>> Quant_176_out0_stream[1];
    #pragma HLS STREAM variable=Quant_176_out0_stream[0] depth=134
    hls::stream<std::array<ap_uint<8>, 1>> Quant_176_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_176_out0_bwch_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_80_window_stream[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[0] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[2] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[3] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[4] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[5] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[6] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[7] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream[8] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_80_window_stream_prepad[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[4] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[5] depth=12
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[6] depth=14
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[7] depth=16
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_window_stream_prepad[8] depth=18
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[8];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> Quant_177_out0_stream[1];
    #pragma HLS STREAM variable=Quant_177_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> Quant_177_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_177_out0_bwch_stream[0] depth=102
    hls::stream<std::array<ap_int<8>, 10>> Quant_178_out0_stream[1];
    #pragma HLS STREAM variable=Quant_178_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 10>> Quant_179_out0_stream[1];
    #pragma HLS STREAM variable=Quant_179_out0_stream[0] depth=15
    hls::stream<std::array<ap_int<8>, 2>> Quant_179_out0_bwch_gcd_stream[1];
    #pragma HLS STREAM variable=Quant_179_out0_bwch_gcd_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> Quant_179_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_179_out0_bwch_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> Quant_180_out0_stream[1];
    #pragma HLS STREAM variable=Quant_180_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> Quant_181_out0_stream[1];
    #pragma HLS STREAM variable=Quant_181_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> Quant_180_out0_bwch_gcd_stream[1];
    #pragma HLS STREAM variable=Quant_180_out0_bwch_gcd_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> Quant_181_out0_bwch_gcd_stream[1];
    #pragma HLS STREAM variable=Quant_181_out0_bwch_gcd_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 10>> Quant_180_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_180_out0_bwch_stream[0] depth=16
    hls::stream<std::array<ap_int<8>, 10>> Quant_181_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_181_out0_bwch_stream[0] depth=162
    hls::stream<std::array<ap_uint<8>, 6>> Quant_182_out0_stream[1];
    #pragma HLS STREAM variable=Quant_182_out0_stream[0] depth=134
    hls::stream<std::array<ap_uint<8>, 1>> Quant_182_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_182_out0_bwch_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_86_window_stream[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[0] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[2] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[3] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[4] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[5] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[6] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[7] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream[8] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_86_window_stream_prepad[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[4] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[5] depth=12
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[6] depth=14
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[7] depth=16
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_window_stream_prepad[8] depth=18
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[8];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> Quant_183_out0_stream[1];
    #pragma HLS STREAM variable=Quant_183_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> Quant_183_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_183_out0_bwch_stream[0] depth=102
    hls::stream<std::array<ap_int<8>, 10>> Quant_184_out0_stream[1];
    #pragma HLS STREAM variable=Quant_184_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 10>> Quant_185_out0_stream[1];
    #pragma HLS STREAM variable=Quant_185_out0_stream[0] depth=17
    hls::stream<std::array<ap_uint<8>, 6>> Quant_186_out0_stream[1];
    #pragma HLS STREAM variable=Quant_186_out0_stream[0] depth=134
    hls::stream<std::array<ap_uint<8>, 1>> Quant_186_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_186_out0_bwch_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_92_window_stream[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[0] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[1] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[2] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[3] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[4] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[5] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[6] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[7] depth=3
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream[8] depth=3
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_92_window_stream_prepad[9];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[0] depth=963
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[4] depth=10
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[5] depth=12
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[6] depth=14
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[7] depth=16
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_window_stream_prepad[8] depth=18
    hls::stream<std::array<ap_uint<8>, 1>> node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[8];
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[0] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[1] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[2] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[3] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[4] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[5] depth=4801
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[6] depth=961
    #pragma HLS STREAM variable=node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[7] depth=961
    hls::stream<std::array<ap_uint<8>, 1>> Quant_187_out0_stream[1];
    #pragma HLS STREAM variable=Quant_187_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 5>> Quant_187_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_187_out0_bwch_stream[0] depth=326
    hls::stream<std::array<ap_int<8>, 20>> Quant_188_out0_stream[1];
    #pragma HLS STREAM variable=Quant_188_out0_stream[0] depth=16
    hls::stream<std::array<ap_uint<8>, 8>> Quant_189_out0_stream[1];
    #pragma HLS STREAM variable=Quant_189_out0_stream[0] depth=141
    hls::stream<std::array<ap_uint<8>, 1>> Quant_189_out0_bwch_stream[1];
    #pragma HLS STREAM variable=Quant_189_out0_bwch_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> Quant_190_out0_stream[1];
    #pragma HLS STREAM variable=Quant_190_out0_stream[0] depth=1268
    hls::stream<std::array<ap_int<8>, 10>> Quant_191_out0_stream[1];
    #pragma HLS STREAM variable=Quant_191_out0_stream[0] depth=2
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        16,  // DATA_PER_WORD
        224,  // HEIGHT
        224,  // WIDTH
        3,  // CH
        4,  // OUT_W_PAR
        3  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.run<0>(global_in, Quant_107_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_stream_0," << Quant_107_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_stream_1," << Quant_107_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_stream_2," << Quant_107_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_stream_3," << Quant_107_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_NHWCToStream_0_node_StreamingConv_0;
    BandwidthAdjustDecreaseChannels_NHWCToStream_0_node_StreamingConv_0.run<1>(Quant_107_out0_stream, Quant_107_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_bwch_stream_0," << Quant_107_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_bwch_stream_1," << Quant_107_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_bwch_stream_2," << Quant_107_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_107_out0_bwch_stream_3," << Quant_107_out0_bwch_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_0;
    node_StreamingConv_0_streaming_linebuffer_pixel_0.run<2>(Quant_107_out0_bwch_stream[3], node_StreamingConv_0_window_stream_prepad[26], node_StreamingConv_0_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_26," << node_StreamingConv_0_window_stream_prepad[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_0,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_1;
    node_StreamingConv_0_streaming_linebuffer_pixel_1.run<3>(Quant_107_out0_bwch_stream[2], node_StreamingConv_0_window_stream_prepad[25], node_StreamingConv_0_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_25," << node_StreamingConv_0_window_stream_prepad[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_1,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_2;
    node_StreamingConv_0_streaming_linebuffer_pixel_2.run<4>(Quant_107_out0_bwch_stream[1], node_StreamingConv_0_window_stream_prepad[24], node_StreamingConv_0_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_24," << node_StreamingConv_0_window_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_2,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_3;
    node_StreamingConv_0_streaming_linebuffer_pixel_3.run<5>(Quant_107_out0_bwch_stream[0], node_StreamingConv_0_window_stream_prepad[23], node_StreamingConv_0_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_23," << node_StreamingConv_0_window_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_3,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_4;
    node_StreamingConv_0_streaming_linebuffer_pixel_4.run<6>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[0], node_StreamingConv_0_window_stream_prepad[22], node_StreamingConv_0_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_22," << node_StreamingConv_0_window_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_4,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_5;
    node_StreamingConv_0_streaming_linebuffer_pixel_5.run<7>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[1], node_StreamingConv_0_window_stream_prepad[21], node_StreamingConv_0_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_21," << node_StreamingConv_0_window_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_6,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_6;
    node_StreamingConv_0_streaming_linebuffer_pixel_6.run<8>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[2], node_StreamingConv_0_window_stream_prepad[20], node_StreamingConv_0_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_20," << node_StreamingConv_0_window_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_7,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_7;
    node_StreamingConv_0_streaming_linebuffer_pixel_7.run<9>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[3], node_StreamingConv_0_window_stream_prepad[19], node_StreamingConv_0_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_19," << node_StreamingConv_0_window_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_8,163" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_8;
    node_StreamingConv_0_streaming_linebuffer_pixel_8.run<10>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[4], node_StreamingConv_0_window_stream_prepad[18], node_StreamingConv_0_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_18," << node_StreamingConv_0_window_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_5,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_10;
    node_StreamingConv_0_streaming_linebuffer_pixel_10.run<12>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[6], node_StreamingConv_0_window_stream_prepad[16], node_StreamingConv_0_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_16," << node_StreamingConv_0_window_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_10,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_11;
    node_StreamingConv_0_streaming_linebuffer_pixel_11.run<13>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[7], node_StreamingConv_0_window_stream_prepad[15], node_StreamingConv_0_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_15," << node_StreamingConv_0_window_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_11,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_12;
    node_StreamingConv_0_streaming_linebuffer_pixel_12.run<14>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[8], node_StreamingConv_0_window_stream_prepad[14], node_StreamingConv_0_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_14," << node_StreamingConv_0_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_12,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_9;
    node_StreamingConv_0_streaming_linebuffer_pixel_9.run<11>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[5], node_StreamingConv_0_window_stream_prepad[17], node_StreamingConv_0_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_17," << node_StreamingConv_0_window_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_9,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_14;
    node_StreamingConv_0_streaming_linebuffer_pixel_14.run<16>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[10], node_StreamingConv_0_window_stream_prepad[12], node_StreamingConv_0_streaming_linebuffer_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_12," << node_StreamingConv_0_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_15,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_15;
    node_StreamingConv_0_streaming_linebuffer_pixel_15.run<17>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[11], node_StreamingConv_0_window_stream_prepad[11], node_StreamingConv_0_streaming_linebuffer_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_11," << node_StreamingConv_0_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_16,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_16;
    node_StreamingConv_0_streaming_linebuffer_pixel_16.run<18>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[12], node_StreamingConv_0_window_stream_prepad[10], node_StreamingConv_0_streaming_linebuffer_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_10," << node_StreamingConv_0_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_17,163" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_13;
    node_StreamingConv_0_streaming_linebuffer_pixel_13.run<15>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[9], node_StreamingConv_0_window_stream_prepad[13], node_StreamingConv_0_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_13," << node_StreamingConv_0_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_13,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_19;
    node_StreamingConv_0_streaming_linebuffer_pixel_19.run<21>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[15], node_StreamingConv_0_window_stream_prepad[7], node_StreamingConv_0_streaming_linebuffer_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_7," << node_StreamingConv_0_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_19,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_20;
    node_StreamingConv_0_streaming_linebuffer_pixel_20.run<22>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[16], node_StreamingConv_0_window_stream_prepad[6], node_StreamingConv_0_streaming_linebuffer_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_6," << node_StreamingConv_0_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_20,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_21;
    node_StreamingConv_0_streaming_linebuffer_pixel_21.run<23>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[17], node_StreamingConv_0_window_stream_prepad[5], node_StreamingConv_0_streaming_linebuffer_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_5," << node_StreamingConv_0_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_21,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_17;
    node_StreamingConv_0_streaming_linebuffer_pixel_17.run<19>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[13], node_StreamingConv_0_window_stream_prepad[9], node_StreamingConv_0_streaming_linebuffer_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_9," << node_StreamingConv_0_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_14,166" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_23;
    node_StreamingConv_0_streaming_linebuffer_pixel_23.run<25>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[19], node_StreamingConv_0_window_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_3," << node_StreamingConv_0_window_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_24;
    node_StreamingConv_0_streaming_linebuffer_pixel_24.run<26>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[20], node_StreamingConv_0_window_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_2," << node_StreamingConv_0_window_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_25;
    node_StreamingConv_0_streaming_linebuffer_pixel_25.run<27>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[21], node_StreamingConv_0_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_1," << node_StreamingConv_0_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_18;
    node_StreamingConv_0_streaming_linebuffer_pixel_18.run<20>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[14], node_StreamingConv_0_window_stream_prepad[8], node_StreamingConv_0_streaming_linebuffer_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_8," << node_StreamingConv_0_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_18,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_22;
    node_StreamingConv_0_streaming_linebuffer_pixel_22.run<24>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[18], node_StreamingConv_0_window_stream_prepad[4], node_StreamingConv_0_streaming_linebuffer_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_4," << node_StreamingConv_0_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_streaming_linebuffer_buffer_stream_22,4" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pixel_26;
    node_StreamingConv_0_streaming_linebuffer_pixel_26.run<28>(node_StreamingConv_0_streaming_linebuffer_buffer_stream[22], node_StreamingConv_0_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_prepad_0," << node_StreamingConv_0_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingConv_0_streaming_linebuffer_pad;
    node_StreamingConv_0_streaming_linebuffer_pad.run<29>(node_StreamingConv_0_window_stream_prepad, node_StreamingConv_0_window_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_12," << node_StreamingConv_0_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_13," << node_StreamingConv_0_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_14," << node_StreamingConv_0_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_15," << node_StreamingConv_0_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_16," << node_StreamingConv_0_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_17," << node_StreamingConv_0_window_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_18," << node_StreamingConv_0_window_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_19," << node_StreamingConv_0_window_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_20," << node_StreamingConv_0_window_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_21," << node_StreamingConv_0_window_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_22," << node_StreamingConv_0_window_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_23," << node_StreamingConv_0_window_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_24," << node_StreamingConv_0_window_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_25," << node_StreamingConv_0_window_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_0_window_stream_26," << node_StreamingConv_0_window_stream[26].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_0_weights[48][2][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_weights dim=2 complete
    ap_int<16> node_StreamingConv_0_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_0_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
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
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_0;
    node_StreamingConv_0.run<30>(node_StreamingConv_0_window_stream, node_StreamingConv_0_weights, node_StreamingConv_0_biases, Quant_108_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_stream_0," << Quant_108_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_stream_1," << Quant_108_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_stream_2," << Quant_108_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_stream_3," << Quant_108_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_0_node_StreamingDepthwiseConv_2;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_0_node_StreamingDepthwiseConv_2.run<31>(Quant_108_out0_stream, Quant_108_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_bwch_stream_0," << Quant_108_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_bwch_stream_1," << Quant_108_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_bwch_stream_2," << Quant_108_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_108_out0_bwch_stream_3," << Quant_108_out0_bwch_stream[3].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_0.run<32>(Quant_108_out0_bwch_stream[0], node_StreamingDepthwiseConv_2_window_stream_prepad[17], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_17," << node_StreamingDepthwiseConv_2_window_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_0,33" << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_1.run<33>(Quant_108_out0_bwch_stream[3], node_StreamingDepthwiseConv_2_window_stream_prepad[16], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_16," << node_StreamingDepthwiseConv_2_window_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_1,33" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_2.run<34>(Quant_108_out0_bwch_stream[2], node_StreamingDepthwiseConv_2_window_stream_prepad[15], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_15," << node_StreamingDepthwiseConv_2_window_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_4,865" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_3.run<35>(Quant_108_out0_bwch_stream[1], node_StreamingDepthwiseConv_2_window_stream_prepad[14], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_14," << node_StreamingDepthwiseConv_2_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_5,865" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_4.run<36>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_2_window_stream_prepad[13], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_13," << node_StreamingDepthwiseConv_2_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_2,897" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_5.run<37>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_2_window_stream_prepad[12], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_12," << node_StreamingDepthwiseConv_2_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_3,897" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_8.run<40>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_2_window_stream_prepad[9], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_9," << node_StreamingDepthwiseConv_2_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_10,865" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_9.run<41>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_2_window_stream_prepad[8], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_8," << node_StreamingDepthwiseConv_2_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_11,865" << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_6.run<38>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_2_window_stream_prepad[11], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_11," << node_StreamingDepthwiseConv_2_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_6,33" << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_7.run<39>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_2_window_stream_prepad[10], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_10," << node_StreamingDepthwiseConv_2_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_7,33" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_14;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_14.run<46>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[10], node_StreamingDepthwiseConv_2_window_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_3," << node_StreamingDepthwiseConv_2_window_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_15;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_15.run<47>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[11], node_StreamingDepthwiseConv_2_window_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_2," << node_StreamingDepthwiseConv_2_window_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_10.run<42>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_2_window_stream_prepad[7], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_7," << node_StreamingDepthwiseConv_2_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_8,897" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_11.run<43>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_2_window_stream_prepad[6], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_6," << node_StreamingDepthwiseConv_2_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_9,897" << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_12;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_12.run<44>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_2_window_stream_prepad[5], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_5," << node_StreamingDepthwiseConv_2_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_12,33" << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_13;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_13.run<45>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_2_window_stream_prepad[4], node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_4," << node_StreamingDepthwiseConv_2_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream_13,33" << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_16;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_16.run<48>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[12], node_StreamingDepthwiseConv_2_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_1," << node_StreamingDepthwiseConv_2_window_stream_prepad[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_17;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pixel_17.run<49>(node_StreamingDepthwiseConv_2_streaming_linebuffer_buffer_stream[13], node_StreamingDepthwiseConv_2_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_prepad_0," << node_StreamingDepthwiseConv_2_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_2_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_2_streaming_linebuffer_pad.run<50>(node_StreamingDepthwiseConv_2_window_stream_prepad, node_StreamingDepthwiseConv_2_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_0," << node_StreamingDepthwiseConv_2_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_1," << node_StreamingDepthwiseConv_2_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_2," << node_StreamingDepthwiseConv_2_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_3," << node_StreamingDepthwiseConv_2_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_4," << node_StreamingDepthwiseConv_2_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_5," << node_StreamingDepthwiseConv_2_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_6," << node_StreamingDepthwiseConv_2_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_7," << node_StreamingDepthwiseConv_2_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_8," << node_StreamingDepthwiseConv_2_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_9," << node_StreamingDepthwiseConv_2_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_10," << node_StreamingDepthwiseConv_2_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_11," << node_StreamingDepthwiseConv_2_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_12," << node_StreamingDepthwiseConv_2_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_13," << node_StreamingDepthwiseConv_2_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_14," << node_StreamingDepthwiseConv_2_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_15," << node_StreamingDepthwiseConv_2_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_16," << node_StreamingDepthwiseConv_2_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_2_window_stream_17," << node_StreamingDepthwiseConv_2_window_stream[17].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_2_weights[32][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_2_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_2_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_2_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
        4  // W_PAR
    > node_StreamingDepthwiseConv_2;
    node_StreamingDepthwiseConv_2.run<51>(node_StreamingDepthwiseConv_2_window_stream, node_StreamingDepthwiseConv_2_weights, node_StreamingDepthwiseConv_2_biases, Quant_109_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_stream_0," << Quant_109_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_stream_1," << Quant_109_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_stream_2," << Quant_109_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_stream_3," << Quant_109_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 8>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_2_node_StreamingConv_4;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_2_node_StreamingConv_4.run<52>(Quant_109_out0_stream, Quant_109_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_bwch_stream_0," << Quant_109_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_bwch_stream_1," << Quant_109_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_bwch_stream_2," << Quant_109_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_109_out0_bwch_stream_3," << Quant_109_out0_bwch_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
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
        3,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_0;
    node_StreamingConv_4_streaming_linebuffer_pixel_0.run<53>(Quant_109_out0_bwch_stream[3], node_StreamingConv_4_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_3," << node_StreamingConv_4_window_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
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
        2,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_1;
    node_StreamingConv_4_streaming_linebuffer_pixel_1.run<54>(Quant_109_out0_bwch_stream[2], node_StreamingConv_4_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_2," << node_StreamingConv_4_window_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
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
        4,  // W_PAR
        8  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_2;
    node_StreamingConv_4_streaming_linebuffer_pixel_2.run<55>(Quant_109_out0_bwch_stream[1], node_StreamingConv_4_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_1," << node_StreamingConv_4_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
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
        4,  // W_PAR
        8  // CH_PAR
    > node_StreamingConv_4_streaming_linebuffer_pixel_3;
    node_StreamingConv_4_streaming_linebuffer_pixel_3.run<56>(Quant_109_out0_bwch_stream[0], node_StreamingConv_4_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_4_window_stream_0," << node_StreamingConv_4_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_4_weights[32][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_weights dim=2 complete
    ap_int<16> node_StreamingConv_4_biases[8][2][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 8>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        DequantQuantEqual<ap_int<23>>,  // Activation
        DequantQuantPo2<8, ap_int<23>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        32,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_4;
    node_StreamingConv_4.run<57>(node_StreamingConv_4_window_stream, node_StreamingConv_4_weights, node_StreamingConv_4_biases, Quant_110_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_stream_0," << Quant_110_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_stream_1," << Quant_110_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_stream_2," << Quant_110_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_stream_3," << Quant_110_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        2,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingConv_4_node_StreamingConv_5;
    BandwidthAdjustIncreaseChannels_node_StreamingConv_4_node_StreamingConv_5.run<58>(Quant_110_out0_stream, Quant_110_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_bwch_stream_0," << Quant_110_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_bwch_stream_1," << Quant_110_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_bwch_stream_2," << Quant_110_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_110_out0_bwch_stream_3," << Quant_110_out0_bwch_stream[3].size() << std::endl;
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
        3,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > node_StreamingConv_5_streaming_linebuffer_pixel_0;
    node_StreamingConv_5_streaming_linebuffer_pixel_0.run<59>(Quant_110_out0_bwch_stream[3], node_StreamingConv_5_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_5_window_stream_3," << node_StreamingConv_5_window_stream[3].size() << std::endl;
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
        2,  // POS_W
        4,  // W_PAR
        16  // CH_PAR
    > node_StreamingConv_5_streaming_linebuffer_pixel_1;
    node_StreamingConv_5_streaming_linebuffer_pixel_1.run<60>(Quant_110_out0_bwch_stream[2], node_StreamingConv_5_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_5_window_stream_2," << node_StreamingConv_5_window_stream[2].size() << std::endl;
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
        4,  // W_PAR
        16  // CH_PAR
    > node_StreamingConv_5_streaming_linebuffer_pixel_2;
    node_StreamingConv_5_streaming_linebuffer_pixel_2.run<61>(Quant_110_out0_bwch_stream[1], node_StreamingConv_5_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_5_window_stream_1," << node_StreamingConv_5_window_stream[1].size() << std::endl;
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
        4,  // W_PAR
        16  // CH_PAR
    > node_StreamingConv_5_streaming_linebuffer_pixel_3;
    node_StreamingConv_5_streaming_linebuffer_pixel_3.run<62>(Quant_110_out0_bwch_stream[0], node_StreamingConv_5_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_5_window_stream_0," << node_StreamingConv_5_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_5_weights[48][32][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_5_weights dim=2 complete
    ap_int<16> node_StreamingConv_5_biases[48][2][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_5_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 32>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
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
        2,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_5;
    node_StreamingConv_5.run<63>(node_StreamingConv_5_window_stream, node_StreamingConv_5_weights, node_StreamingConv_5_biases, Quant_111_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_111_out0_stream_0," << Quant_111_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_111_out0_stream_1," << Quant_111_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_111_out0_stream_2," << Quant_111_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_111_out0_stream_3," << Quant_111_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_0.run<64>(Quant_111_out0_stream[3], node_StreamingDepthwiseConv_7_window_stream_prepad[26], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_26," << node_StreamingDepthwiseConv_7_window_stream_prepad[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_0,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_1.run<65>(Quant_111_out0_stream[2], node_StreamingDepthwiseConv_7_window_stream_prepad[25], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_25," << node_StreamingDepthwiseConv_7_window_stream_prepad[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_1,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_2.run<66>(Quant_111_out0_stream[1], node_StreamingDepthwiseConv_7_window_stream_prepad[24], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_24," << node_StreamingDepthwiseConv_7_window_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_2,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_3.run<67>(Quant_111_out0_stream[0], node_StreamingDepthwiseConv_7_window_stream_prepad[23], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_23," << node_StreamingDepthwiseConv_7_window_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_3,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_4.run<68>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_7_window_stream_prepad[22], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_22," << node_StreamingDepthwiseConv_7_window_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_4,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_5.run<69>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_7_window_stream_prepad[21], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_21," << node_StreamingDepthwiseConv_7_window_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_6,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_6.run<70>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_7_window_stream_prepad[20], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_20," << node_StreamingDepthwiseConv_7_window_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_7,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_7.run<71>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_7_window_stream_prepad[19], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_19," << node_StreamingDepthwiseConv_7_window_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_8,1249" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_8.run<72>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_7_window_stream_prepad[18], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_18," << node_StreamingDepthwiseConv_7_window_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_5,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_10.run<74>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_7_window_stream_prepad[16], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_16," << node_StreamingDepthwiseConv_7_window_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_10,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_11.run<75>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_7_window_stream_prepad[15], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_15," << node_StreamingDepthwiseConv_7_window_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_11,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_12;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_12.run<76>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_7_window_stream_prepad[14], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_14," << node_StreamingDepthwiseConv_7_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_12,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_9.run<73>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_7_window_stream_prepad[17], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_17," << node_StreamingDepthwiseConv_7_window_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_9,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_14;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_14.run<78>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[10], node_StreamingDepthwiseConv_7_window_stream_prepad[12], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_12," << node_StreamingDepthwiseConv_7_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_15,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_15;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_15.run<79>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[11], node_StreamingDepthwiseConv_7_window_stream_prepad[11], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_11," << node_StreamingDepthwiseConv_7_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_16,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_16;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_16.run<80>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[12], node_StreamingDepthwiseConv_7_window_stream_prepad[10], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_10," << node_StreamingDepthwiseConv_7_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_17,1249" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_13;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_13.run<77>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_7_window_stream_prepad[13], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_13," << node_StreamingDepthwiseConv_7_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_13,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_19;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_19.run<83>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[15], node_StreamingDepthwiseConv_7_window_stream_prepad[7], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_7," << node_StreamingDepthwiseConv_7_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_19,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_20;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_20.run<84>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[16], node_StreamingDepthwiseConv_7_window_stream_prepad[6], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_6," << node_StreamingDepthwiseConv_7_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_20,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_21;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_21.run<85>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[17], node_StreamingDepthwiseConv_7_window_stream_prepad[5], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_5," << node_StreamingDepthwiseConv_7_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_21,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_17;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_17.run<81>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[13], node_StreamingDepthwiseConv_7_window_stream_prepad[9], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_9," << node_StreamingDepthwiseConv_7_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_14,1297" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_23;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_23.run<87>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[19], node_StreamingDepthwiseConv_7_window_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_3," << node_StreamingDepthwiseConv_7_window_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_24;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_24.run<88>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[20], node_StreamingDepthwiseConv_7_window_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_2," << node_StreamingDepthwiseConv_7_window_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_25;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_25.run<89>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[21], node_StreamingDepthwiseConv_7_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_1," << node_StreamingDepthwiseConv_7_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_18;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_18.run<82>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[14], node_StreamingDepthwiseConv_7_window_stream_prepad[8], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_8," << node_StreamingDepthwiseConv_7_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_18,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_22;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_22.run<86>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[18], node_StreamingDepthwiseConv_7_window_stream_prepad[4], node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_4," << node_StreamingDepthwiseConv_7_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream_22,49" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_26;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pixel_26.run<90>(node_StreamingDepthwiseConv_7_streaming_linebuffer_buffer_stream[22], node_StreamingDepthwiseConv_7_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_prepad_0," << node_StreamingDepthwiseConv_7_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > node_StreamingDepthwiseConv_7_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_7_streaming_linebuffer_pad.run<91>(node_StreamingDepthwiseConv_7_window_stream_prepad, node_StreamingDepthwiseConv_7_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_0," << node_StreamingDepthwiseConv_7_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_1," << node_StreamingDepthwiseConv_7_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_2," << node_StreamingDepthwiseConv_7_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_3," << node_StreamingDepthwiseConv_7_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_4," << node_StreamingDepthwiseConv_7_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_5," << node_StreamingDepthwiseConv_7_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_6," << node_StreamingDepthwiseConv_7_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_7," << node_StreamingDepthwiseConv_7_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_8," << node_StreamingDepthwiseConv_7_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_9," << node_StreamingDepthwiseConv_7_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_10," << node_StreamingDepthwiseConv_7_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_11," << node_StreamingDepthwiseConv_7_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_12," << node_StreamingDepthwiseConv_7_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_13," << node_StreamingDepthwiseConv_7_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_14," << node_StreamingDepthwiseConv_7_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_15," << node_StreamingDepthwiseConv_7_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_16," << node_StreamingDepthwiseConv_7_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_17," << node_StreamingDepthwiseConv_7_window_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_18," << node_StreamingDepthwiseConv_7_window_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_19," << node_StreamingDepthwiseConv_7_window_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_20," << node_StreamingDepthwiseConv_7_window_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_21," << node_StreamingDepthwiseConv_7_window_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_22," << node_StreamingDepthwiseConv_7_window_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_23," << node_StreamingDepthwiseConv_7_window_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_24," << node_StreamingDepthwiseConv_7_window_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_25," << node_StreamingDepthwiseConv_7_window_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_7_window_stream_26," << node_StreamingDepthwiseConv_7_window_stream[26].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_7_weights[48][2][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_7_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_7_biases[48][2][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_7_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasStruct
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputStruct
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
        2,  // CH_PAR
        4  // W_PAR
    > node_StreamingDepthwiseConv_7;
    node_StreamingDepthwiseConv_7.run<92>(node_StreamingDepthwiseConv_7_window_stream, node_StreamingDepthwiseConv_7_weights, node_StreamingDepthwiseConv_7_biases, Quant_112_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_112_out0_stream_0," << Quant_112_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_112_out0_stream_1," << Quant_112_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_112_out0_stream_2," << Quant_112_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_112_out0_stream_3," << Quant_112_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > node_StreamingConv_9_streaming_linebuffer_pixel_0;
    node_StreamingConv_9_streaming_linebuffer_pixel_0.run<93>(Quant_112_out0_stream[3], node_StreamingConv_9_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_9_window_stream_3," << node_StreamingConv_9_window_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > node_StreamingConv_9_streaming_linebuffer_pixel_1;
    node_StreamingConv_9_streaming_linebuffer_pixel_1.run<94>(Quant_112_out0_stream[2], node_StreamingConv_9_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_9_window_stream_2," << node_StreamingConv_9_window_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > node_StreamingConv_9_streaming_linebuffer_pixel_2;
    node_StreamingConv_9_streaming_linebuffer_pixel_2.run<95>(Quant_112_out0_stream[1], node_StreamingConv_9_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_9_window_stream_1," << node_StreamingConv_9_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > node_StreamingConv_9_streaming_linebuffer_pixel_3;
    node_StreamingConv_9_streaming_linebuffer_pixel_3.run<96>(Quant_112_out0_stream[0], node_StreamingConv_9_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_9_window_stream_0," << node_StreamingConv_9_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_9_weights[192][12][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_9_weights dim=2 complete
    ap_int<16> node_StreamingConv_9_biases[4][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_9_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        96,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_9;
    node_StreamingConv_9.run<97>(node_StreamingConv_9_window_stream, node_StreamingConv_9_weights, node_StreamingConv_9_biases, Quant_113_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_113_out0_stream_0," << Quant_113_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_113_out0_stream_1," << Quant_113_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_113_out0_stream_2," << Quant_113_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_113_out0_stream_3," << Quant_113_out0_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 6>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        6,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<98>(Quant_113_out0_stream, Quant_114_out0_stream, Quant_115_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_114_out0_stream_0," << Quant_114_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_114_out0_stream_1," << Quant_114_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_114_out0_stream_2," << Quant_114_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_114_out0_stream_3," << Quant_114_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_115_out0_stream_0," << Quant_115_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_115_out0_stream_1," << Quant_115_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_115_out0_stream_2," << Quant_115_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_115_out0_stream_3," << Quant_115_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_0;
    node_StreamingConv_10_streaming_linebuffer_pixel_0.run<99>(Quant_114_out0_stream[3], node_StreamingConv_10_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_3," << node_StreamingConv_10_window_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_1;
    node_StreamingConv_10_streaming_linebuffer_pixel_1.run<100>(Quant_114_out0_stream[2], node_StreamingConv_10_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_2," << node_StreamingConv_10_window_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_2;
    node_StreamingConv_10_streaming_linebuffer_pixel_2.run<101>(Quant_114_out0_stream[1], node_StreamingConv_10_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_1," << node_StreamingConv_10_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_10_streaming_linebuffer_pixel_3;
    node_StreamingConv_10_streaming_linebuffer_pixel_3.run<102>(Quant_114_out0_stream[0], node_StreamingConv_10_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_10_window_stream_0," << node_StreamingConv_10_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_10_weights[192][18][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_weights dim=2 complete
    ap_int<16> node_StreamingConv_10_biases[48][3][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_10_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 6>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 18>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
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
        6,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_10;
    node_StreamingConv_10.run<103>(node_StreamingConv_10_window_stream, node_StreamingConv_10_weights, node_StreamingConv_10_biases, Quant_116_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_stream_0," << Quant_116_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_stream_1," << Quant_116_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_stream_2," << Quant_116_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_stream_3," << Quant_116_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_10_node_StreamingDepthwiseConv_12;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_10_node_StreamingDepthwiseConv_12.run<104>(Quant_116_out0_stream, Quant_116_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_bwch_stream_0," << Quant_116_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_bwch_stream_1," << Quant_116_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_bwch_stream_2," << Quant_116_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_116_out0_bwch_stream_3," << Quant_116_out0_bwch_stream[3].size() << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_0.run<105>(Quant_116_out0_bwch_stream[0], node_StreamingDepthwiseConv_12_window_stream_prepad[17], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_17," << node_StreamingDepthwiseConv_12_window_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_0,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_1.run<106>(Quant_116_out0_bwch_stream[3], node_StreamingDepthwiseConv_12_window_stream_prepad[16], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_16," << node_StreamingDepthwiseConv_12_window_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_1,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_2.run<107>(Quant_116_out0_bwch_stream[2], node_StreamingDepthwiseConv_12_window_stream_prepad[15], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_15," << node_StreamingDepthwiseConv_12_window_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_4,1873" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_3.run<108>(Quant_116_out0_bwch_stream[1], node_StreamingDepthwiseConv_12_window_stream_prepad[14], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_14," << node_StreamingDepthwiseConv_12_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_5,1873" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_4.run<109>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_12_window_stream_prepad[13], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_13," << node_StreamingDepthwiseConv_12_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_2,2017" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_5.run<110>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_12_window_stream_prepad[12], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_12," << node_StreamingDepthwiseConv_12_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_3,2017" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_8.run<113>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_12_window_stream_prepad[9], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_9," << node_StreamingDepthwiseConv_12_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_10,1873" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_9.run<114>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_12_window_stream_prepad[8], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_8," << node_StreamingDepthwiseConv_12_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_11,1873" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_6.run<111>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_12_window_stream_prepad[11], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_11," << node_StreamingDepthwiseConv_12_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_6,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_7.run<112>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_12_window_stream_prepad[10], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_10," << node_StreamingDepthwiseConv_12_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_7,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_14;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_14.run<119>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[10], node_StreamingDepthwiseConv_12_window_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_3," << node_StreamingDepthwiseConv_12_window_stream_prepad[3].size() << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_15;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_15.run<120>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[11], node_StreamingDepthwiseConv_12_window_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_2," << node_StreamingDepthwiseConv_12_window_stream_prepad[2].size() << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_10.run<115>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_12_window_stream_prepad[7], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_7," << node_StreamingDepthwiseConv_12_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_8,2017" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_11.run<116>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_12_window_stream_prepad[6], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_6," << node_StreamingDepthwiseConv_12_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_9,2017" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_12;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_12.run<117>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_12_window_stream_prepad[5], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_5," << node_StreamingDepthwiseConv_12_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_12,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_13;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_13.run<118>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_12_window_stream_prepad[4], node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_4," << node_StreamingDepthwiseConv_12_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream_13,145" << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_16;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_16.run<121>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[12], node_StreamingDepthwiseConv_12_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_1," << node_StreamingDepthwiseConv_12_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_17;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pixel_17.run<122>(node_StreamingDepthwiseConv_12_streaming_linebuffer_buffer_stream[13], node_StreamingDepthwiseConv_12_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_prepad_0," << node_StreamingDepthwiseConv_12_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_12_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_12_streaming_linebuffer_pad.run<123>(node_StreamingDepthwiseConv_12_window_stream_prepad, node_StreamingDepthwiseConv_12_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_0," << node_StreamingDepthwiseConv_12_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_1," << node_StreamingDepthwiseConv_12_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_2," << node_StreamingDepthwiseConv_12_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_3," << node_StreamingDepthwiseConv_12_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_4," << node_StreamingDepthwiseConv_12_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_5," << node_StreamingDepthwiseConv_12_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_6," << node_StreamingDepthwiseConv_12_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_7," << node_StreamingDepthwiseConv_12_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_8," << node_StreamingDepthwiseConv_12_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_9," << node_StreamingDepthwiseConv_12_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_10," << node_StreamingDepthwiseConv_12_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_11," << node_StreamingDepthwiseConv_12_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_12," << node_StreamingDepthwiseConv_12_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_13," << node_StreamingDepthwiseConv_12_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_14," << node_StreamingDepthwiseConv_12_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_15," << node_StreamingDepthwiseConv_12_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_16," << node_StreamingDepthwiseConv_12_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_12_window_stream_17," << node_StreamingDepthwiseConv_12_window_stream[17].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_12_weights[144][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_12_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_12_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_12_biases[144][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_12_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_12_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_12;
    node_StreamingDepthwiseConv_12.run<124>(node_StreamingDepthwiseConv_12_window_stream, node_StreamingDepthwiseConv_12_weights, node_StreamingDepthwiseConv_12_biases, Quant_117_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_stream_0," << Quant_117_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_stream_1," << Quant_117_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_stream_2," << Quant_117_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_stream_3," << Quant_117_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_12_node_StreamingConv_14;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_12_node_StreamingConv_14.run<125>(Quant_117_out0_stream, Quant_117_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_bwch_stream_0," << Quant_117_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_bwch_stream_1," << Quant_117_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_bwch_stream_2," << Quant_117_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_117_out0_bwch_stream_3," << Quant_117_out0_bwch_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
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
        3  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_0;
    node_StreamingConv_14_streaming_linebuffer_pixel_0.run<126>(Quant_117_out0_bwch_stream[3], node_StreamingConv_14_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_3," << node_StreamingConv_14_window_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
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
        3  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_1;
    node_StreamingConv_14_streaming_linebuffer_pixel_1.run<127>(Quant_117_out0_bwch_stream[2], node_StreamingConv_14_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_2," << node_StreamingConv_14_window_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
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
        3  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_2;
    node_StreamingConv_14_streaming_linebuffer_pixel_2.run<128>(Quant_117_out0_bwch_stream[1], node_StreamingConv_14_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_1," << node_StreamingConv_14_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
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
        3  // CH_PAR
    > node_StreamingConv_14_streaming_linebuffer_pixel_3;
    node_StreamingConv_14_streaming_linebuffer_pixel_3.run<129>(Quant_117_out0_bwch_stream[0], node_StreamingConv_14_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_14_window_stream_0," << node_StreamingConv_14_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_14_weights[192][18][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_weights dim=2 complete
    ap_int<16> node_StreamingConv_14_biases[4][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_14_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 18>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<9, ap_int<25>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        144,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_14;
    node_StreamingConv_14.run<130>(node_StreamingConv_14_window_stream, node_StreamingConv_14_weights, node_StreamingConv_14_biases, Quant_118_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_118_out0_stream_0," << Quant_118_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_118_out0_stream_1," << Quant_118_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_118_out0_stream_2," << Quant_118_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_118_out0_stream_3," << Quant_118_out0_stream[3].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 6>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 6>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // W_PAR
        6  // CH_PAR
    > node_StreamingAdd_15;
    node_StreamingAdd_15.run<131>(Quant_115_out0_stream, Quant_118_out0_stream, Quant_119_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_119_out0_stream_0," << Quant_119_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_119_out0_stream_1," << Quant_119_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_119_out0_stream_2," << Quant_119_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_119_out0_stream_3," << Quant_119_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_0;
    node_StreamingConv_16_streaming_linebuffer_pixel_0.run<132>(Quant_119_out0_stream[3], node_StreamingConv_16_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_3," << node_StreamingConv_16_window_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_1;
    node_StreamingConv_16_streaming_linebuffer_pixel_1.run<133>(Quant_119_out0_stream[2], node_StreamingConv_16_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_2," << node_StreamingConv_16_window_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_2;
    node_StreamingConv_16_streaming_linebuffer_pixel_2.run<134>(Quant_119_out0_stream[1], node_StreamingConv_16_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_1," << node_StreamingConv_16_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_16_streaming_linebuffer_pixel_3;
    node_StreamingConv_16_streaming_linebuffer_pixel_3.run<135>(Quant_119_out0_stream[0], node_StreamingConv_16_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_16_window_stream_0," << node_StreamingConv_16_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_16_weights[192][18][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_weights dim=2 complete
    ap_int<16> node_StreamingConv_16_biases[48][3][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_16_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 6>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 18>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
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
        6,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        4  // W_PAR
    > node_StreamingConv_16;
    node_StreamingConv_16.run<136>(node_StreamingConv_16_window_stream, node_StreamingConv_16_weights, node_StreamingConv_16_biases, Quant_120_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_stream_0," << Quant_120_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_stream_1," << Quant_120_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_stream_2," << Quant_120_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_stream_3," << Quant_120_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_16_node_StreamingDepthwiseConv_18;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_16_node_StreamingDepthwiseConv_18.run<137>(Quant_120_out0_stream, Quant_120_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_bwch_stream_0," << Quant_120_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_bwch_stream_1," << Quant_120_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_bwch_stream_2," << Quant_120_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_120_out0_bwch_stream_3," << Quant_120_out0_bwch_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_0.run<138>(Quant_120_out0_bwch_stream[3], node_StreamingDepthwiseConv_18_window_stream_prepad[26], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_26," << node_StreamingDepthwiseConv_18_window_stream_prepad[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_0,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_1.run<139>(Quant_120_out0_bwch_stream[2], node_StreamingDepthwiseConv_18_window_stream_prepad[25], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_25," << node_StreamingDepthwiseConv_18_window_stream_prepad[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_1,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_2.run<140>(Quant_120_out0_bwch_stream[1], node_StreamingDepthwiseConv_18_window_stream_prepad[24], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_24," << node_StreamingDepthwiseConv_18_window_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_2,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_3.run<141>(Quant_120_out0_bwch_stream[0], node_StreamingDepthwiseConv_18_window_stream_prepad[23], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_23," << node_StreamingDepthwiseConv_18_window_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_3,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_4.run<142>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_18_window_stream_prepad[22], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_22," << node_StreamingDepthwiseConv_18_window_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_4,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_5.run<143>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_18_window_stream_prepad[21], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_21," << node_StreamingDepthwiseConv_18_window_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_6,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_6.run<144>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_18_window_stream_prepad[20], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_20," << node_StreamingDepthwiseConv_18_window_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_7,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_7.run<145>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_18_window_stream_prepad[19], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_19," << node_StreamingDepthwiseConv_18_window_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_8,1729" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_8.run<146>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_18_window_stream_prepad[18], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_18," << node_StreamingDepthwiseConv_18_window_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_5,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_10.run<148>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_18_window_stream_prepad[16], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_16," << node_StreamingDepthwiseConv_18_window_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_10,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_11.run<149>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_18_window_stream_prepad[15], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_15," << node_StreamingDepthwiseConv_18_window_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_11,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_12;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_12.run<150>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_18_window_stream_prepad[14], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_14," << node_StreamingDepthwiseConv_18_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_12,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_9.run<147>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_18_window_stream_prepad[17], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_17," << node_StreamingDepthwiseConv_18_window_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_9,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_14;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_14.run<152>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[10], node_StreamingDepthwiseConv_18_window_stream_prepad[12], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_12," << node_StreamingDepthwiseConv_18_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_15,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_15;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_15.run<153>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[11], node_StreamingDepthwiseConv_18_window_stream_prepad[11], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_11," << node_StreamingDepthwiseConv_18_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_16,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_16;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_16.run<154>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[12], node_StreamingDepthwiseConv_18_window_stream_prepad[10], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_10," << node_StreamingDepthwiseConv_18_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_17,1729" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_13;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_13.run<151>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_18_window_stream_prepad[13], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_13," << node_StreamingDepthwiseConv_18_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_13,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_19;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_19.run<157>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[15], node_StreamingDepthwiseConv_18_window_stream_prepad[7], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_7," << node_StreamingDepthwiseConv_18_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_19,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_20;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_20.run<158>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[16], node_StreamingDepthwiseConv_18_window_stream_prepad[6], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_6," << node_StreamingDepthwiseConv_18_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_20,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_21;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_21.run<159>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[17], node_StreamingDepthwiseConv_18_window_stream_prepad[5], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_5," << node_StreamingDepthwiseConv_18_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_21,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_17;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_17.run<155>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[13], node_StreamingDepthwiseConv_18_window_stream_prepad[9], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_9," << node_StreamingDepthwiseConv_18_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_14,1873" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_23;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_23.run<161>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[19], node_StreamingDepthwiseConv_18_window_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_3," << node_StreamingDepthwiseConv_18_window_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_24;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_24.run<162>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[20], node_StreamingDepthwiseConv_18_window_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_2," << node_StreamingDepthwiseConv_18_window_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_25;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_25.run<163>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[21], node_StreamingDepthwiseConv_18_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_1," << node_StreamingDepthwiseConv_18_window_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_18;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_18.run<156>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[14], node_StreamingDepthwiseConv_18_window_stream_prepad[8], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_8," << node_StreamingDepthwiseConv_18_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_18,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_22;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_22.run<160>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[18], node_StreamingDepthwiseConv_18_window_stream_prepad[4], node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_4," << node_StreamingDepthwiseConv_18_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream_22,145" << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_26;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pixel_26.run<164>(node_StreamingDepthwiseConv_18_streaming_linebuffer_buffer_stream[22], node_StreamingDepthwiseConv_18_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_prepad_0," << node_StreamingDepthwiseConv_18_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        4,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_18_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_18_streaming_linebuffer_pad.run<165>(node_StreamingDepthwiseConv_18_window_stream_prepad, node_StreamingDepthwiseConv_18_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_0," << node_StreamingDepthwiseConv_18_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_1," << node_StreamingDepthwiseConv_18_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_2," << node_StreamingDepthwiseConv_18_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_3," << node_StreamingDepthwiseConv_18_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_4," << node_StreamingDepthwiseConv_18_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_5," << node_StreamingDepthwiseConv_18_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_6," << node_StreamingDepthwiseConv_18_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_7," << node_StreamingDepthwiseConv_18_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_8," << node_StreamingDepthwiseConv_18_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_9," << node_StreamingDepthwiseConv_18_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_10," << node_StreamingDepthwiseConv_18_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_11," << node_StreamingDepthwiseConv_18_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_12," << node_StreamingDepthwiseConv_18_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_13," << node_StreamingDepthwiseConv_18_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_14," << node_StreamingDepthwiseConv_18_window_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_15," << node_StreamingDepthwiseConv_18_window_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_16," << node_StreamingDepthwiseConv_18_window_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_17," << node_StreamingDepthwiseConv_18_window_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_18," << node_StreamingDepthwiseConv_18_window_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_19," << node_StreamingDepthwiseConv_18_window_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_20," << node_StreamingDepthwiseConv_18_window_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_21," << node_StreamingDepthwiseConv_18_window_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_22," << node_StreamingDepthwiseConv_18_window_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_23," << node_StreamingDepthwiseConv_18_window_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_24," << node_StreamingDepthwiseConv_18_window_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_25," << node_StreamingDepthwiseConv_18_window_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_18_window_stream_26," << node_StreamingDepthwiseConv_18_window_stream[26].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_18_weights[144][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_18_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_18_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_18_biases[144][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_18_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_18_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
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
        1,  // CH_PAR
        4  // W_PAR
    > node_StreamingDepthwiseConv_18;
    node_StreamingDepthwiseConv_18.run<166>(node_StreamingDepthwiseConv_18_window_stream, node_StreamingDepthwiseConv_18_weights, node_StreamingDepthwiseConv_18_biases, Quant_121_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_stream_0," << Quant_121_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_stream_1," << Quant_121_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_stream_2," << Quant_121_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_stream_3," << Quant_121_out0_stream[3].size() << std::endl;
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
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_18_node_StreamingConv_20;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_18_node_StreamingConv_20.run<167>(Quant_121_out0_stream, Quant_121_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_bwch_stream_0," << Quant_121_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_bwch_stream_1," << Quant_121_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_bwch_stream_2," << Quant_121_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_121_out0_bwch_stream_3," << Quant_121_out0_bwch_stream[3].size() << std::endl;
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
        3,  // POS_W
        4,  // W_PAR
        9  // CH_PAR
    > node_StreamingConv_20_streaming_linebuffer_pixel_0;
    node_StreamingConv_20_streaming_linebuffer_pixel_0.run<168>(Quant_121_out0_bwch_stream[3], node_StreamingConv_20_window_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_20_window_stream_3," << node_StreamingConv_20_window_stream[3].size() << std::endl;
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
        2,  // POS_W
        4,  // W_PAR
        9  // CH_PAR
    > node_StreamingConv_20_streaming_linebuffer_pixel_1;
    node_StreamingConv_20_streaming_linebuffer_pixel_1.run<169>(Quant_121_out0_bwch_stream[2], node_StreamingConv_20_window_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_20_window_stream_2," << node_StreamingConv_20_window_stream[2].size() << std::endl;
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
        4,  // W_PAR
        9  // CH_PAR
    > node_StreamingConv_20_streaming_linebuffer_pixel_2;
    node_StreamingConv_20_streaming_linebuffer_pixel_2.run<170>(Quant_121_out0_bwch_stream[1], node_StreamingConv_20_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_20_window_stream_1," << node_StreamingConv_20_window_stream[1].size() << std::endl;
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
        4,  // W_PAR
        9  // CH_PAR
    > node_StreamingConv_20_streaming_linebuffer_pixel_3;
    node_StreamingConv_20_streaming_linebuffer_pixel_3.run<171>(Quant_121_out0_bwch_stream[0], node_StreamingConv_20_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_20_window_stream_0," << node_StreamingConv_20_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_20_weights[512][9][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_weights dim=2 complete
    ap_int<16> node_StreamingConv_20_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_20_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 9>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
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
        4  // W_PAR
    > node_StreamingConv_20;
    node_StreamingConv_20.run<172>(node_StreamingConv_20_window_stream, node_StreamingConv_20_weights, node_StreamingConv_20_biases, Quant_122_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_122_out0_stream_0," << Quant_122_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_122_out0_stream_1," << Quant_122_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_122_out0_stream_2," << Quant_122_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_122_out0_stream_3," << Quant_122_out0_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<173>(Quant_122_out0_stream, Quant_123_out0_stream, Quant_124_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_stream_0," << Quant_123_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_stream_1," << Quant_123_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_stream_2," << Quant_123_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_stream_3," << Quant_123_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_stream_0," << Quant_124_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_stream_1," << Quant_124_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_stream_2," << Quant_124_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_stream_3," << Quant_124_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_TensorDuplicator_1_node_StreamingConv_21;
    BandwidthAdjustDecreaseStreams_TensorDuplicator_1_node_StreamingConv_21.run<174>(Quant_123_out0_stream, Quant_123_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_bww_stream_0," << Quant_123_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_123_out0_bww_stream_1," << Quant_123_out0_bww_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_1_node_StreamingAdd_26;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_1_node_StreamingAdd_26.run<175>(Quant_124_out0_stream, Quant_124_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bwch_stream_0," << Quant_124_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bwch_stream_1," << Quant_124_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bwch_stream_2," << Quant_124_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bwch_stream_3," << Quant_124_out0_bwch_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_TensorDuplicator_1_node_StreamingAdd_26;
    BandwidthAdjustDecreaseStreams_TensorDuplicator_1_node_StreamingAdd_26.run<176>(Quant_124_out0_bwch_stream, Quant_124_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bww_stream_0," << Quant_124_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_124_out0_bww_stream_1," << Quant_124_out0_bww_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_21_streaming_linebuffer_pixel_0;
    node_StreamingConv_21_streaming_linebuffer_pixel_0.run<177>(Quant_123_out0_bww_stream[1], node_StreamingConv_21_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_21_window_stream_1," << node_StreamingConv_21_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_21_streaming_linebuffer_pixel_1;
    node_StreamingConv_21_streaming_linebuffer_pixel_1.run<178>(Quant_123_out0_bww_stream[0], node_StreamingConv_21_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_21_window_stream_0," << node_StreamingConv_21_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_21_weights[384][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_21_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_21_weights dim=2 complete
    ap_int<16> node_StreamingConv_21_biases[12][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_21_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_21_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 16>,  // TOutputWord
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
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_21;
    node_StreamingConv_21.run<179>(node_StreamingConv_21_window_stream, node_StreamingConv_21_weights, node_StreamingConv_21_biases, Quant_125_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_125_out0_stream_0," << Quant_125_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_125_out0_stream_1," << Quant_125_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 16>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_21_node_StreamingDepthwiseConv_23;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_21_node_StreamingDepthwiseConv_23.run<180>(Quant_125_out0_stream, Quant_125_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_125_out0_bwch_stream_0," << Quant_125_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_125_out0_bwch_stream_1," << Quant_125_out0_bwch_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_0.run<181>(Quant_125_out0_bwch_stream[0], node_StreamingDepthwiseConv_23_window_stream_prepad[11], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_11," << node_StreamingDepthwiseConv_23_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_0,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_1.run<182>(Quant_125_out0_bwch_stream[1], node_StreamingDepthwiseConv_23_window_stream_prepad[10], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_10," << node_StreamingDepthwiseConv_23_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_1,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_2.run<183>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_23_window_stream_prepad[9], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_9," << node_StreamingDepthwiseConv_23_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_2,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_3.run<184>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_23_window_stream_prepad[8], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_8," << node_StreamingDepthwiseConv_23_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_3,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_4.run<185>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_23_window_stream_prepad[7], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_7," << node_StreamingDepthwiseConv_23_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_4,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_5.run<186>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_23_window_stream_prepad[6], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_6," << node_StreamingDepthwiseConv_23_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_5,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_6.run<187>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_23_window_stream_prepad[5], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_5," << node_StreamingDepthwiseConv_23_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_6,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_7.run<188>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_23_window_stream_prepad[4], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_4," << node_StreamingDepthwiseConv_23_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_7,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_8.run<189>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_23_window_stream_prepad[3], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_3," << node_StreamingDepthwiseConv_23_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_8,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_9.run<190>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_23_window_stream_prepad[2], node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_2," << node_StreamingDepthwiseConv_23_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream_9,193" << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_10.run<191>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_23_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_1," << node_StreamingDepthwiseConv_23_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pixel_11.run<192>(node_StreamingDepthwiseConv_23_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_23_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_prepad_0," << node_StreamingDepthwiseConv_23_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_23_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_23_streaming_linebuffer_pad.run<193>(node_StreamingDepthwiseConv_23_window_stream_prepad, node_StreamingDepthwiseConv_23_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_0," << node_StreamingDepthwiseConv_23_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_1," << node_StreamingDepthwiseConv_23_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_2," << node_StreamingDepthwiseConv_23_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_3," << node_StreamingDepthwiseConv_23_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_4," << node_StreamingDepthwiseConv_23_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_5," << node_StreamingDepthwiseConv_23_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_6," << node_StreamingDepthwiseConv_23_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_7," << node_StreamingDepthwiseConv_23_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_8," << node_StreamingDepthwiseConv_23_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_9," << node_StreamingDepthwiseConv_23_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_10," << node_StreamingDepthwiseConv_23_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_23_window_stream_11," << node_StreamingDepthwiseConv_23_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_23_weights[192][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_23_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_23_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_23_biases[192][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_23_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_23_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_23;
    node_StreamingDepthwiseConv_23.run<194>(node_StreamingDepthwiseConv_23_window_stream, node_StreamingDepthwiseConv_23_weights, node_StreamingDepthwiseConv_23_biases, Quant_126_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_126_out0_stream_0," << Quant_126_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_126_out0_stream_1," << Quant_126_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_25_streaming_linebuffer_pixel_0;
    node_StreamingConv_25_streaming_linebuffer_pixel_0.run<195>(Quant_126_out0_stream[1], node_StreamingConv_25_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_25_window_stream_1," << node_StreamingConv_25_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_25_streaming_linebuffer_pixel_1;
    node_StreamingConv_25_streaming_linebuffer_pixel_1.run<196>(Quant_126_out0_stream[0], node_StreamingConv_25_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_25_window_stream_0," << node_StreamingConv_25_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_25_weights[384][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_25_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_25_weights dim=2 complete
    ap_int<16> node_StreamingConv_25_biases[2][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_25_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_25_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_25;
    node_StreamingConv_25.run<197>(node_StreamingConv_25_window_stream, node_StreamingConv_25_weights, node_StreamingConv_25_biases, Quant_127_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_127_out0_stream_0," << Quant_127_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_127_out0_stream_1," << Quant_127_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 16>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 16>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        16  // CH_PAR
    > node_StreamingAdd_26;
    node_StreamingAdd_26.run<198>(Quant_124_out0_bww_stream, Quant_127_out0_stream, Quant_128_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_stream_0," << Quant_128_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_stream_1," << Quant_128_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        4,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_node_StreamingAdd_26_TensorDuplicator_2;
    BandwidthAdjustIncreaseStreams_node_StreamingAdd_26_TensorDuplicator_2.run<199>(Quant_128_out0_stream, Quant_128_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bww_stream_0," << Quant_128_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bww_stream_1," << Quant_128_out0_bww_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bww_stream_2," << Quant_128_out0_bww_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bww_stream_3," << Quant_128_out0_bww_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        16,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingAdd_26_TensorDuplicator_2;
    BandwidthAdjustDecreaseChannels_node_StreamingAdd_26_TensorDuplicator_2.run<200>(Quant_128_out0_bww_stream, Quant_128_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bwch_stream_0," << Quant_128_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bwch_stream_1," << Quant_128_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bwch_stream_2," << Quant_128_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_128_out0_bwch_stream_3," << Quant_128_out0_bwch_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<201>(Quant_128_out0_bwch_stream, Quant_129_out0_stream, Quant_130_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_stream_0," << Quant_129_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_stream_1," << Quant_129_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_stream_2," << Quant_129_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_stream_3," << Quant_129_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_stream_0," << Quant_130_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_stream_1," << Quant_130_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_stream_2," << Quant_130_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_stream_3," << Quant_130_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_2_node_StreamingConv_27;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_2_node_StreamingConv_27.run<202>(Quant_129_out0_stream, Quant_129_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bwch_stream_0," << Quant_129_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bwch_stream_1," << Quant_129_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bwch_stream_2," << Quant_129_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bwch_stream_3," << Quant_129_out0_bwch_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_2_node_StreamingAdd_32;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_2_node_StreamingAdd_32.run<203>(Quant_130_out0_stream, Quant_130_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bwch_stream_0," << Quant_130_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bwch_stream_1," << Quant_130_out0_bwch_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bwch_stream_2," << Quant_130_out0_bwch_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bwch_stream_3," << Quant_130_out0_bwch_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_TensorDuplicator_2_node_StreamingConv_27;
    BandwidthAdjustDecreaseStreams_TensorDuplicator_2_node_StreamingConv_27.run<204>(Quant_129_out0_bwch_stream, Quant_129_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bww_stream_0," << Quant_129_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_129_out0_bww_stream_1," << Quant_129_out0_bww_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_TensorDuplicator_2_node_StreamingAdd_32;
    BandwidthAdjustDecreaseStreams_TensorDuplicator_2_node_StreamingAdd_32.run<205>(Quant_130_out0_bwch_stream, Quant_130_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bww_stream_0," << Quant_130_out0_bww_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_130_out0_bww_stream_1," << Quant_130_out0_bww_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_27_streaming_linebuffer_pixel_0;
    node_StreamingConv_27_streaming_linebuffer_pixel_0.run<206>(Quant_129_out0_bww_stream[1], node_StreamingConv_27_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_27_window_stream_1," << node_StreamingConv_27_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_27_streaming_linebuffer_pixel_1;
    node_StreamingConv_27_streaming_linebuffer_pixel_1.run<207>(Quant_129_out0_bww_stream[0], node_StreamingConv_27_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_27_window_stream_0," << node_StreamingConv_27_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_27_weights[384][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_27_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_27_weights dim=2 complete
    ap_int<16> node_StreamingConv_27_biases[192][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_27_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_27_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
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
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_27;
    node_StreamingConv_27.run<208>(node_StreamingConv_27_window_stream, node_StreamingConv_27_weights, node_StreamingConv_27_biases, Quant_131_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_131_out0_stream_0," << Quant_131_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_131_out0_stream_1," << Quant_131_out0_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_0.run<209>(Quant_131_out0_stream[0], node_StreamingDepthwiseConv_29_window_stream_prepad[11], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_11," << node_StreamingDepthwiseConv_29_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_0,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_1.run<210>(Quant_131_out0_stream[1], node_StreamingDepthwiseConv_29_window_stream_prepad[10], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_10," << node_StreamingDepthwiseConv_29_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_1,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_2.run<211>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_29_window_stream_prepad[9], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_9," << node_StreamingDepthwiseConv_29_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_2,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_3.run<212>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_29_window_stream_prepad[8], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_8," << node_StreamingDepthwiseConv_29_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_3,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_4.run<213>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_29_window_stream_prepad[7], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_7," << node_StreamingDepthwiseConv_29_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_4,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_5.run<214>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_29_window_stream_prepad[6], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_6," << node_StreamingDepthwiseConv_29_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_5,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_6.run<215>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_29_window_stream_prepad[5], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_5," << node_StreamingDepthwiseConv_29_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_6,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_7.run<216>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_29_window_stream_prepad[4], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_4," << node_StreamingDepthwiseConv_29_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_7,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_8.run<217>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_29_window_stream_prepad[3], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_3," << node_StreamingDepthwiseConv_29_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_8,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_9.run<218>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_29_window_stream_prepad[2], node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_2," << node_StreamingDepthwiseConv_29_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream_9,193" << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_10.run<219>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_29_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_1," << node_StreamingDepthwiseConv_29_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pixel_11.run<220>(node_StreamingDepthwiseConv_29_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_29_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_prepad_0," << node_StreamingDepthwiseConv_29_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_29_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_29_streaming_linebuffer_pad.run<221>(node_StreamingDepthwiseConv_29_window_stream_prepad, node_StreamingDepthwiseConv_29_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_0," << node_StreamingDepthwiseConv_29_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_1," << node_StreamingDepthwiseConv_29_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_2," << node_StreamingDepthwiseConv_29_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_3," << node_StreamingDepthwiseConv_29_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_4," << node_StreamingDepthwiseConv_29_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_5," << node_StreamingDepthwiseConv_29_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_6," << node_StreamingDepthwiseConv_29_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_7," << node_StreamingDepthwiseConv_29_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_8," << node_StreamingDepthwiseConv_29_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_9," << node_StreamingDepthwiseConv_29_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_10," << node_StreamingDepthwiseConv_29_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_29_window_stream_11," << node_StreamingDepthwiseConv_29_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_29_weights[192][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_29_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_29_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_29_biases[192][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_29_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_29_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_29;
    node_StreamingDepthwiseConv_29.run<222>(node_StreamingDepthwiseConv_29_window_stream, node_StreamingDepthwiseConv_29_weights, node_StreamingDepthwiseConv_29_biases, Quant_132_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_132_out0_stream_0," << Quant_132_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_132_out0_stream_1," << Quant_132_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_31_streaming_linebuffer_pixel_0;
    node_StreamingConv_31_streaming_linebuffer_pixel_0.run<223>(Quant_132_out0_stream[1], node_StreamingConv_31_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_31_window_stream_1," << node_StreamingConv_31_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_31_streaming_linebuffer_pixel_1;
    node_StreamingConv_31_streaming_linebuffer_pixel_1.run<224>(Quant_132_out0_stream[0], node_StreamingConv_31_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_31_window_stream_0," << node_StreamingConv_31_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_31_weights[384][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_31_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_31_weights dim=2 complete
    ap_int<16> node_StreamingConv_31_biases[2][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_31_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_31_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<9, ap_int<25>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_31;
    node_StreamingConv_31.run<225>(node_StreamingConv_31_window_stream, node_StreamingConv_31_weights, node_StreamingConv_31_biases, Quant_133_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_133_out0_stream_0," << Quant_133_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_133_out0_stream_1," << Quant_133_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 16>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 16>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        16  // CH_PAR
    > node_StreamingAdd_32;
    node_StreamingAdd_32.run<226>(Quant_130_out0_bww_stream, Quant_133_out0_stream, Quant_134_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_134_out0_stream_0," << Quant_134_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_134_out0_stream_1," << Quant_134_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_33_streaming_linebuffer_pixel_0;
    node_StreamingConv_33_streaming_linebuffer_pixel_0.run<227>(Quant_134_out0_stream[1], node_StreamingConv_33_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_33_window_stream_1," << node_StreamingConv_33_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_33_streaming_linebuffer_pixel_1;
    node_StreamingConv_33_streaming_linebuffer_pixel_1.run<228>(Quant_134_out0_stream[0], node_StreamingConv_33_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_33_window_stream_0," << node_StreamingConv_33_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_33_weights[384][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_33_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_33_weights dim=2 complete
    ap_int<16> node_StreamingConv_33_biases[192][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_33_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_33_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
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
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_33;
    node_StreamingConv_33.run<229>(node_StreamingConv_33_window_stream, node_StreamingConv_33_weights, node_StreamingConv_33_biases, Quant_135_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_135_out0_stream_0," << Quant_135_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_135_out0_stream_1," << Quant_135_out0_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_0.run<230>(Quant_135_out0_stream[1], node_StreamingDepthwiseConv_35_window_stream_prepad[14], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_14," << node_StreamingDepthwiseConv_35_window_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_0,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_1.run<231>(Quant_135_out0_stream[0], node_StreamingDepthwiseConv_35_window_stream_prepad[13], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_13," << node_StreamingDepthwiseConv_35_window_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_1,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_2.run<232>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_35_window_stream_prepad[12], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_12," << node_StreamingDepthwiseConv_35_window_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_2,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_3.run<233>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_35_window_stream_prepad[11], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_11," << node_StreamingDepthwiseConv_35_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_4,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_4.run<234>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_35_window_stream_prepad[10], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_10," << node_StreamingDepthwiseConv_35_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_3,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_6.run<236>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_35_window_stream_prepad[8], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_8," << node_StreamingDepthwiseConv_35_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_6,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_5.run<235>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_35_window_stream_prepad[9], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_9," << node_StreamingDepthwiseConv_35_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_5,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_8.run<238>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_35_window_stream_prepad[6], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_6," << node_StreamingDepthwiseConv_35_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_9,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_7.run<237>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_35_window_stream_prepad[7], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_7," << node_StreamingDepthwiseConv_35_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_7,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_11.run<241>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_35_window_stream_prepad[3], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_3," << node_StreamingDepthwiseConv_35_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_11,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_9.run<239>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_35_window_stream_prepad[5], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_5," << node_StreamingDepthwiseConv_35_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_8,2497" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_13;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_13.run<243>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[11], node_StreamingDepthwiseConv_35_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_1," << node_StreamingDepthwiseConv_35_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_10.run<240>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_35_window_stream_prepad[4], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_4," << node_StreamingDepthwiseConv_35_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_10,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_12;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_12.run<242>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[10], node_StreamingDepthwiseConv_35_window_stream_prepad[2], node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_2," << node_StreamingDepthwiseConv_35_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream_12,193" << std::endl;
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
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_14;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pixel_14.run<244>(node_StreamingDepthwiseConv_35_streaming_linebuffer_buffer_stream[12], node_StreamingDepthwiseConv_35_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_prepad_0," << node_StreamingDepthwiseConv_35_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_35_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_35_streaming_linebuffer_pad.run<245>(node_StreamingDepthwiseConv_35_window_stream_prepad, node_StreamingDepthwiseConv_35_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_0," << node_StreamingDepthwiseConv_35_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_1," << node_StreamingDepthwiseConv_35_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_2," << node_StreamingDepthwiseConv_35_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_3," << node_StreamingDepthwiseConv_35_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_4," << node_StreamingDepthwiseConv_35_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_5," << node_StreamingDepthwiseConv_35_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_6," << node_StreamingDepthwiseConv_35_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_7," << node_StreamingDepthwiseConv_35_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_8," << node_StreamingDepthwiseConv_35_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_9," << node_StreamingDepthwiseConv_35_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_10," << node_StreamingDepthwiseConv_35_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_11," << node_StreamingDepthwiseConv_35_window_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_12," << node_StreamingDepthwiseConv_35_window_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_13," << node_StreamingDepthwiseConv_35_window_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_35_window_stream_14," << node_StreamingDepthwiseConv_35_window_stream[14].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_35_weights[192][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_35_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_35_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_35_biases[192][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_35_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_35_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_35;
    node_StreamingDepthwiseConv_35.run<246>(node_StreamingDepthwiseConv_35_window_stream, node_StreamingDepthwiseConv_35_weights, node_StreamingDepthwiseConv_35_biases, Quant_136_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_136_out0_stream_0," << Quant_136_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_136_out0_stream_1," << Quant_136_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
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
        1  // CH_PAR
    > node_StreamingConv_37_streaming_linebuffer_pixel_0;
    node_StreamingConv_37_streaming_linebuffer_pixel_0.run<247>(Quant_136_out0_stream[1], node_StreamingConv_37_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_37_window_stream_1," << node_StreamingConv_37_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
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
        1  // CH_PAR
    > node_StreamingConv_37_streaming_linebuffer_pixel_1;
    node_StreamingConv_37_streaming_linebuffer_pixel_1.run<248>(Quant_136_out0_stream[0], node_StreamingConv_37_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_37_window_stream_0," << node_StreamingConv_37_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_37_weights[1536][8][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_37_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_37_weights dim=2 complete
    ap_int<16> node_StreamingConv_37_biases[8][8][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_37_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_37_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 8>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 8>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<9, ap_int<25>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        192,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        8,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_37;
    node_StreamingConv_37.run<249>(node_StreamingConv_37_window_stream, node_StreamingConv_37_weights, node_StreamingConv_37_biases, Quant_137_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_137_out0_stream_0," << Quant_137_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_137_out0_stream_1," << Quant_137_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 8>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        8,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_3;
    TensorDuplicator_3.run<250>(Quant_137_out0_stream, Quant_138_out0_stream, Quant_139_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_138_out0_stream_0," << Quant_138_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_138_out0_stream_1," << Quant_138_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_139_out0_stream_0," << Quant_139_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_139_out0_stream_1," << Quant_139_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        8,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_3_node_StreamingAdd_43;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_3_node_StreamingAdd_43.run<251>(Quant_139_out0_stream, Quant_139_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_139_out0_bwch_stream_0," << Quant_139_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_139_out0_bwch_stream_1," << Quant_139_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
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
        8  // CH_PAR
    > node_StreamingConv_38_streaming_linebuffer_pixel_0;
    node_StreamingConv_38_streaming_linebuffer_pixel_0.run<252>(Quant_138_out0_stream[1], node_StreamingConv_38_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_38_window_stream_1," << node_StreamingConv_38_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
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
        8  // CH_PAR
    > node_StreamingConv_38_streaming_linebuffer_pixel_1;
    node_StreamingConv_38_streaming_linebuffer_pixel_1.run<253>(Quant_138_out0_stream[0], node_StreamingConv_38_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_38_window_stream_0," << node_StreamingConv_38_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_38_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_38_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_38_weights dim=2 complete
    ap_int<16> node_StreamingConv_38_biases[192][2][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_38_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_38_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 8>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
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
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_38;
    node_StreamingConv_38.run<254>(node_StreamingConv_38_window_stream, node_StreamingConv_38_weights, node_StreamingConv_38_biases, Quant_140_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_140_out0_stream_0," << Quant_140_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_140_out0_stream_1," << Quant_140_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_38_node_StreamingDepthwiseConv_40;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_38_node_StreamingDepthwiseConv_40.run<255>(Quant_140_out0_stream, Quant_140_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_140_out0_bwch_stream_0," << Quant_140_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_140_out0_bwch_stream_1," << Quant_140_out0_bwch_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_0.run<256>(Quant_140_out0_bwch_stream[0], node_StreamingDepthwiseConv_40_window_stream_prepad[11], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_11," << node_StreamingDepthwiseConv_40_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_0,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_1.run<257>(Quant_140_out0_bwch_stream[1], node_StreamingDepthwiseConv_40_window_stream_prepad[10], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_10," << node_StreamingDepthwiseConv_40_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_1,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_2.run<258>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_40_window_stream_prepad[9], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_9," << node_StreamingDepthwiseConv_40_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_2,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_3.run<259>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_40_window_stream_prepad[8], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_8," << node_StreamingDepthwiseConv_40_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_3,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_4.run<260>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_40_window_stream_prepad[7], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_7," << node_StreamingDepthwiseConv_40_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_4,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_5.run<261>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_40_window_stream_prepad[6], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_6," << node_StreamingDepthwiseConv_40_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_5,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_6.run<262>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_40_window_stream_prepad[5], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_5," << node_StreamingDepthwiseConv_40_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_6,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_7.run<263>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_40_window_stream_prepad[4], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_4," << node_StreamingDepthwiseConv_40_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_7,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_8.run<264>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_40_window_stream_prepad[3], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_3," << node_StreamingDepthwiseConv_40_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_8,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_9.run<265>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_40_window_stream_prepad[2], node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_2," << node_StreamingDepthwiseConv_40_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream_9,385" << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_10.run<266>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_40_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_1," << node_StreamingDepthwiseConv_40_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pixel_11.run<267>(node_StreamingDepthwiseConv_40_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_40_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_prepad_0," << node_StreamingDepthwiseConv_40_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_40_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_40_streaming_linebuffer_pad.run<268>(node_StreamingDepthwiseConv_40_window_stream_prepad, node_StreamingDepthwiseConv_40_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_0," << node_StreamingDepthwiseConv_40_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_1," << node_StreamingDepthwiseConv_40_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_2," << node_StreamingDepthwiseConv_40_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_3," << node_StreamingDepthwiseConv_40_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_4," << node_StreamingDepthwiseConv_40_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_5," << node_StreamingDepthwiseConv_40_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_6," << node_StreamingDepthwiseConv_40_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_7," << node_StreamingDepthwiseConv_40_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_8," << node_StreamingDepthwiseConv_40_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_9," << node_StreamingDepthwiseConv_40_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_10," << node_StreamingDepthwiseConv_40_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_40_window_stream_11," << node_StreamingDepthwiseConv_40_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_40_weights[384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_40_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_40_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_40_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_40_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_40_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_40;
    node_StreamingDepthwiseConv_40.run<269>(node_StreamingDepthwiseConv_40_window_stream, node_StreamingDepthwiseConv_40_weights, node_StreamingDepthwiseConv_40_biases, Quant_141_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_141_out0_stream_0," << Quant_141_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_141_out0_stream_1," << Quant_141_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_42_streaming_linebuffer_pixel_0;
    node_StreamingConv_42_streaming_linebuffer_pixel_0.run<270>(Quant_141_out0_stream[1], node_StreamingConv_42_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_42_window_stream_1," << node_StreamingConv_42_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_42_streaming_linebuffer_pixel_1;
    node_StreamingConv_42_streaming_linebuffer_pixel_1.run<271>(Quant_141_out0_stream[0], node_StreamingConv_42_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_42_window_stream_0," << node_StreamingConv_42_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_42_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_42_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_42_weights dim=2 complete
    ap_int<16> node_StreamingConv_42_biases[4][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_42_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_42_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_42;
    node_StreamingConv_42.run<272>(node_StreamingConv_42_window_stream, node_StreamingConv_42_weights, node_StreamingConv_42_biases, Quant_142_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_142_out0_stream_0," << Quant_142_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_142_out0_stream_1," << Quant_142_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 16>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 16>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        16  // CH_PAR
    > node_StreamingAdd_43;
    node_StreamingAdd_43.run<273>(Quant_139_out0_bwch_stream, Quant_142_out0_stream, Quant_143_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_143_out0_stream_0," << Quant_143_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_143_out0_stream_1," << Quant_143_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingAdd_43_TensorDuplicator_4;
    BandwidthAdjustDecreaseChannels_node_StreamingAdd_43_TensorDuplicator_4.run<274>(Quant_143_out0_stream, Quant_143_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_143_out0_bwch_stream_0," << Quant_143_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_143_out0_bwch_stream_1," << Quant_143_out0_bwch_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 8>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        8,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_4;
    TensorDuplicator_4.run<275>(Quant_143_out0_bwch_stream, Quant_144_out0_stream, Quant_145_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_144_out0_stream_0," << Quant_144_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_144_out0_stream_1," << Quant_144_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_145_out0_stream_0," << Quant_145_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_145_out0_stream_1," << Quant_145_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        8,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_4_node_StreamingConv_44;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_4_node_StreamingConv_44.run<276>(Quant_144_out0_stream, Quant_144_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_144_out0_bwch_stream_0," << Quant_144_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_144_out0_bwch_stream_1," << Quant_144_out0_bwch_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        8,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_4_node_StreamingAdd_49;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_4_node_StreamingAdd_49.run<277>(Quant_145_out0_stream, Quant_145_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_145_out0_bwch_stream_0," << Quant_145_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_145_out0_bwch_stream_1," << Quant_145_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_44_streaming_linebuffer_pixel_0;
    node_StreamingConv_44_streaming_linebuffer_pixel_0.run<278>(Quant_144_out0_bwch_stream[1], node_StreamingConv_44_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_44_window_stream_1," << node_StreamingConv_44_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_44_streaming_linebuffer_pixel_1;
    node_StreamingConv_44_streaming_linebuffer_pixel_1.run<279>(Quant_144_out0_bwch_stream[0], node_StreamingConv_44_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_44_window_stream_0," << node_StreamingConv_44_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_44_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_44_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_44_weights dim=2 complete
    ap_int<16> node_StreamingConv_44_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_44_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_44_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
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
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_44;
    node_StreamingConv_44.run<280>(node_StreamingConv_44_window_stream, node_StreamingConv_44_weights, node_StreamingConv_44_biases, Quant_146_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_146_out0_stream_0," << Quant_146_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_146_out0_stream_1," << Quant_146_out0_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_0.run<281>(Quant_146_out0_stream[0], node_StreamingDepthwiseConv_46_window_stream_prepad[11], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_11," << node_StreamingDepthwiseConv_46_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_0,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_1.run<282>(Quant_146_out0_stream[1], node_StreamingDepthwiseConv_46_window_stream_prepad[10], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_10," << node_StreamingDepthwiseConv_46_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_1,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_2.run<283>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_46_window_stream_prepad[9], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_9," << node_StreamingDepthwiseConv_46_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_2,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_3.run<284>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_46_window_stream_prepad[8], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_8," << node_StreamingDepthwiseConv_46_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_3,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_4.run<285>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_46_window_stream_prepad[7], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_7," << node_StreamingDepthwiseConv_46_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_4,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_5.run<286>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_46_window_stream_prepad[6], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_6," << node_StreamingDepthwiseConv_46_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_5,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_6.run<287>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_46_window_stream_prepad[5], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_5," << node_StreamingDepthwiseConv_46_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_6,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_7.run<288>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_46_window_stream_prepad[4], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_4," << node_StreamingDepthwiseConv_46_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_7,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_8.run<289>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_46_window_stream_prepad[3], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_3," << node_StreamingDepthwiseConv_46_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_8,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_9.run<290>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_46_window_stream_prepad[2], node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_2," << node_StreamingDepthwiseConv_46_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream_9,385" << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_10.run<291>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_46_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_1," << node_StreamingDepthwiseConv_46_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pixel_11.run<292>(node_StreamingDepthwiseConv_46_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_46_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_prepad_0," << node_StreamingDepthwiseConv_46_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_46_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_46_streaming_linebuffer_pad.run<293>(node_StreamingDepthwiseConv_46_window_stream_prepad, node_StreamingDepthwiseConv_46_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_0," << node_StreamingDepthwiseConv_46_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_1," << node_StreamingDepthwiseConv_46_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_2," << node_StreamingDepthwiseConv_46_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_3," << node_StreamingDepthwiseConv_46_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_4," << node_StreamingDepthwiseConv_46_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_5," << node_StreamingDepthwiseConv_46_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_6," << node_StreamingDepthwiseConv_46_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_7," << node_StreamingDepthwiseConv_46_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_8," << node_StreamingDepthwiseConv_46_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_9," << node_StreamingDepthwiseConv_46_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_10," << node_StreamingDepthwiseConv_46_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_46_window_stream_11," << node_StreamingDepthwiseConv_46_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_46_weights[384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_46_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_46_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_46_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_46_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_46_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_46;
    node_StreamingDepthwiseConv_46.run<294>(node_StreamingDepthwiseConv_46_window_stream, node_StreamingDepthwiseConv_46_weights, node_StreamingDepthwiseConv_46_biases, Quant_147_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_147_out0_stream_0," << Quant_147_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_147_out0_stream_1," << Quant_147_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_48_streaming_linebuffer_pixel_0;
    node_StreamingConv_48_streaming_linebuffer_pixel_0.run<295>(Quant_147_out0_stream[1], node_StreamingConv_48_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_48_window_stream_1," << node_StreamingConv_48_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_48_streaming_linebuffer_pixel_1;
    node_StreamingConv_48_streaming_linebuffer_pixel_1.run<296>(Quant_147_out0_stream[0], node_StreamingConv_48_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_48_window_stream_0," << node_StreamingConv_48_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_48_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_48_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_48_weights dim=2 complete
    ap_int<16> node_StreamingConv_48_biases[4][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_48_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_48_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_48;
    node_StreamingConv_48.run<297>(node_StreamingConv_48_window_stream, node_StreamingConv_48_weights, node_StreamingConv_48_biases, Quant_148_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_148_out0_stream_0," << Quant_148_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_148_out0_stream_1," << Quant_148_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 16>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 16>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        16  // CH_PAR
    > node_StreamingAdd_49;
    node_StreamingAdd_49.run<298>(Quant_145_out0_bwch_stream, Quant_148_out0_stream, Quant_149_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_149_out0_stream_0," << Quant_149_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_149_out0_stream_1," << Quant_149_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        16,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingAdd_49_TensorDuplicator_5;
    BandwidthAdjustDecreaseChannels_node_StreamingAdd_49_TensorDuplicator_5.run<299>(Quant_149_out0_stream, Quant_149_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_149_out0_bwch_stream_0," << Quant_149_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_149_out0_bwch_stream_1," << Quant_149_out0_bwch_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 8>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        8,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_5;
    TensorDuplicator_5.run<300>(Quant_149_out0_bwch_stream, Quant_150_out0_stream, Quant_151_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_150_out0_stream_0," << Quant_150_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_150_out0_stream_1," << Quant_150_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_151_out0_stream_0," << Quant_151_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_151_out0_stream_1," << Quant_151_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        8,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_5_node_StreamingConv_50;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_5_node_StreamingConv_50.run<301>(Quant_150_out0_stream, Quant_150_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_150_out0_bwch_stream_0," << Quant_150_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_150_out0_bwch_stream_1," << Quant_150_out0_bwch_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        8,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_5_node_StreamingAdd_55;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_5_node_StreamingAdd_55.run<302>(Quant_151_out0_stream, Quant_151_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_151_out0_bwch_stream_0," << Quant_151_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_151_out0_bwch_stream_1," << Quant_151_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_50_streaming_linebuffer_pixel_0;
    node_StreamingConv_50_streaming_linebuffer_pixel_0.run<303>(Quant_150_out0_bwch_stream[1], node_StreamingConv_50_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_50_window_stream_1," << node_StreamingConv_50_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_50_streaming_linebuffer_pixel_1;
    node_StreamingConv_50_streaming_linebuffer_pixel_1.run<304>(Quant_150_out0_bwch_stream[0], node_StreamingConv_50_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_50_window_stream_0," << node_StreamingConv_50_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_50_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_50_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_50_weights dim=2 complete
    ap_int<16> node_StreamingConv_50_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_50_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_50_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
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
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_50;
    node_StreamingConv_50.run<305>(node_StreamingConv_50_window_stream, node_StreamingConv_50_weights, node_StreamingConv_50_biases, Quant_152_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_152_out0_stream_0," << Quant_152_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_152_out0_stream_1," << Quant_152_out0_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_0.run<306>(Quant_152_out0_stream[0], node_StreamingDepthwiseConv_52_window_stream_prepad[11], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_11," << node_StreamingDepthwiseConv_52_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_0,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_1.run<307>(Quant_152_out0_stream[1], node_StreamingDepthwiseConv_52_window_stream_prepad[10], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_10," << node_StreamingDepthwiseConv_52_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_1,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_2.run<308>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_52_window_stream_prepad[9], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_9," << node_StreamingDepthwiseConv_52_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_2,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_3.run<309>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_52_window_stream_prepad[8], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_8," << node_StreamingDepthwiseConv_52_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_3,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_4.run<310>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_52_window_stream_prepad[7], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_7," << node_StreamingDepthwiseConv_52_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_4,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_5.run<311>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_52_window_stream_prepad[6], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_6," << node_StreamingDepthwiseConv_52_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_5,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_6.run<312>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_52_window_stream_prepad[5], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_5," << node_StreamingDepthwiseConv_52_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_6,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_7.run<313>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_52_window_stream_prepad[4], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_4," << node_StreamingDepthwiseConv_52_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_7,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_8.run<314>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_52_window_stream_prepad[3], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_3," << node_StreamingDepthwiseConv_52_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_8,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_9.run<315>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_52_window_stream_prepad[2], node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_2," << node_StreamingDepthwiseConv_52_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream_9,385" << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_10.run<316>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_52_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_1," << node_StreamingDepthwiseConv_52_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pixel_11.run<317>(node_StreamingDepthwiseConv_52_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_52_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_prepad_0," << node_StreamingDepthwiseConv_52_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_52_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_52_streaming_linebuffer_pad.run<318>(node_StreamingDepthwiseConv_52_window_stream_prepad, node_StreamingDepthwiseConv_52_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_0," << node_StreamingDepthwiseConv_52_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_1," << node_StreamingDepthwiseConv_52_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_2," << node_StreamingDepthwiseConv_52_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_3," << node_StreamingDepthwiseConv_52_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_4," << node_StreamingDepthwiseConv_52_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_5," << node_StreamingDepthwiseConv_52_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_6," << node_StreamingDepthwiseConv_52_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_7," << node_StreamingDepthwiseConv_52_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_8," << node_StreamingDepthwiseConv_52_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_9," << node_StreamingDepthwiseConv_52_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_10," << node_StreamingDepthwiseConv_52_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_52_window_stream_11," << node_StreamingDepthwiseConv_52_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_52_weights[384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_52_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_52_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_52_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_52_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_52_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_52;
    node_StreamingDepthwiseConv_52.run<319>(node_StreamingDepthwiseConv_52_window_stream, node_StreamingDepthwiseConv_52_weights, node_StreamingDepthwiseConv_52_biases, Quant_153_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_153_out0_stream_0," << Quant_153_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_153_out0_stream_1," << Quant_153_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_54_streaming_linebuffer_pixel_0;
    node_StreamingConv_54_streaming_linebuffer_pixel_0.run<320>(Quant_153_out0_stream[1], node_StreamingConv_54_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_54_window_stream_1," << node_StreamingConv_54_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > node_StreamingConv_54_streaming_linebuffer_pixel_1;
    node_StreamingConv_54_streaming_linebuffer_pixel_1.run<321>(Quant_153_out0_stream[0], node_StreamingConv_54_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_54_window_stream_0," << node_StreamingConv_54_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_54_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_54_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_54_weights dim=2 complete
    ap_int<16> node_StreamingConv_54_biases[4][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_54_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_54_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 16>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        16,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_54;
    node_StreamingConv_54.run<322>(node_StreamingConv_54_window_stream, node_StreamingConv_54_weights, node_StreamingConv_54_biases, Quant_154_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_154_out0_stream_0," << Quant_154_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_154_out0_stream_1," << Quant_154_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 16>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 16>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 16>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        16  // CH_PAR
    > node_StreamingAdd_55;
    node_StreamingAdd_55.run<323>(Quant_151_out0_bwch_stream, Quant_154_out0_stream, Quant_155_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_155_out0_stream_0," << Quant_155_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_155_out0_stream_1," << Quant_155_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_56_streaming_linebuffer_pixel_0;
    node_StreamingConv_56_streaming_linebuffer_pixel_0.run<324>(Quant_155_out0_stream[1], node_StreamingConv_56_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_56_window_stream_1," << node_StreamingConv_56_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
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
        16  // CH_PAR
    > node_StreamingConv_56_streaming_linebuffer_pixel_1;
    node_StreamingConv_56_streaming_linebuffer_pixel_1.run<325>(Quant_155_out0_stream[0], node_StreamingConv_56_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_56_window_stream_0," << node_StreamingConv_56_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_56_weights[1536][16][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_56_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_56_weights dim=2 complete
    ap_int<16> node_StreamingConv_56_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_56_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_56_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
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
        16,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_56;
    node_StreamingConv_56.run<326>(node_StreamingConv_56_window_stream, node_StreamingConv_56_weights, node_StreamingConv_56_biases, Quant_156_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_156_out0_stream_0," << Quant_156_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_156_out0_stream_1," << Quant_156_out0_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_0.run<327>(Quant_156_out0_stream[0], node_StreamingDepthwiseConv_58_window_stream_prepad[11], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_11," << node_StreamingDepthwiseConv_58_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_0,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_1.run<328>(Quant_156_out0_stream[1], node_StreamingDepthwiseConv_58_window_stream_prepad[10], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_10," << node_StreamingDepthwiseConv_58_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_1,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_2.run<329>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_58_window_stream_prepad[9], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_9," << node_StreamingDepthwiseConv_58_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_2,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_3.run<330>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_58_window_stream_prepad[8], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_8," << node_StreamingDepthwiseConv_58_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_3,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_4.run<331>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_58_window_stream_prepad[7], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_7," << node_StreamingDepthwiseConv_58_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_4,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_5.run<332>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_58_window_stream_prepad[6], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_6," << node_StreamingDepthwiseConv_58_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_5,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_6.run<333>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_58_window_stream_prepad[5], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_5," << node_StreamingDepthwiseConv_58_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_6,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_7.run<334>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_58_window_stream_prepad[4], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_4," << node_StreamingDepthwiseConv_58_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_7,2305" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_8.run<335>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_58_window_stream_prepad[3], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_3," << node_StreamingDepthwiseConv_58_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_8,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_9.run<336>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_58_window_stream_prepad[2], node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_2," << node_StreamingDepthwiseConv_58_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream_9,385" << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_10.run<337>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_58_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_1," << node_StreamingDepthwiseConv_58_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pixel_11.run<338>(node_StreamingDepthwiseConv_58_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_58_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_prepad_0," << node_StreamingDepthwiseConv_58_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_58_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_58_streaming_linebuffer_pad.run<339>(node_StreamingDepthwiseConv_58_window_stream_prepad, node_StreamingDepthwiseConv_58_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_0," << node_StreamingDepthwiseConv_58_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_1," << node_StreamingDepthwiseConv_58_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_2," << node_StreamingDepthwiseConv_58_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_3," << node_StreamingDepthwiseConv_58_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_4," << node_StreamingDepthwiseConv_58_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_5," << node_StreamingDepthwiseConv_58_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_6," << node_StreamingDepthwiseConv_58_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_7," << node_StreamingDepthwiseConv_58_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_8," << node_StreamingDepthwiseConv_58_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_9," << node_StreamingDepthwiseConv_58_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_10," << node_StreamingDepthwiseConv_58_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_58_window_stream_11," << node_StreamingDepthwiseConv_58_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_58_weights[384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_58_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_58_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_58_biases[384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_58_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_58_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_58;
    node_StreamingDepthwiseConv_58.run<340>(node_StreamingDepthwiseConv_58_window_stream, node_StreamingDepthwiseConv_58_weights, node_StreamingDepthwiseConv_58_biases, Quant_157_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_157_out0_stream_0," << Quant_157_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_157_out0_stream_1," << Quant_157_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 4>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_58_node_StreamingConv_60;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_58_node_StreamingConv_60.run<341>(Quant_157_out0_stream, Quant_157_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_157_out0_bwch_stream_0," << Quant_157_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_157_out0_bwch_stream_1," << Quant_157_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > node_StreamingConv_60_streaming_linebuffer_pixel_0;
    node_StreamingConv_60_streaming_linebuffer_pixel_0.run<342>(Quant_157_out0_bwch_stream[1], node_StreamingConv_60_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_60_window_stream_1," << node_StreamingConv_60_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > node_StreamingConv_60_streaming_linebuffer_pixel_1;
    node_StreamingConv_60_streaming_linebuffer_pixel_1.run<343>(Quant_157_out0_bwch_stream[0], node_StreamingConv_60_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_60_window_stream_0," << node_StreamingConv_60_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_60_weights[1536][24][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_60_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_60_weights dim=2 complete
    ap_int<16> node_StreamingConv_60_biases[16][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_60_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_60_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 4>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 24>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<10, ap_int<26>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_60;
    node_StreamingConv_60.run<344>(node_StreamingConv_60_window_stream, node_StreamingConv_60_weights, node_StreamingConv_60_biases, Quant_158_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_158_out0_stream_0," << Quant_158_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_158_out0_stream_1," << Quant_158_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        6,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_6;
    TensorDuplicator_6.run<345>(Quant_158_out0_stream, Quant_159_out0_stream, Quant_160_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_159_out0_stream_0," << Quant_159_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_159_out0_stream_1," << Quant_159_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_160_out0_stream_0," << Quant_160_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_160_out0_stream_1," << Quant_160_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_61_streaming_linebuffer_pixel_0;
    node_StreamingConv_61_streaming_linebuffer_pixel_0.run<346>(Quant_159_out0_stream[1], node_StreamingConv_61_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_61_window_stream_1," << node_StreamingConv_61_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_61_streaming_linebuffer_pixel_1;
    node_StreamingConv_61_streaming_linebuffer_pixel_1.run<347>(Quant_159_out0_stream[0], node_StreamingConv_61_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_61_window_stream_0," << node_StreamingConv_61_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_61_weights[1536][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_61_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_61_weights dim=2 complete
    ap_int<16> node_StreamingConv_61_biases[96][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_61_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_61_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 6>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_61;
    node_StreamingConv_61.run<348>(node_StreamingConv_61_window_stream, node_StreamingConv_61_weights, node_StreamingConv_61_biases, Quant_161_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_161_out0_stream_0," << Quant_161_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_161_out0_stream_1," << Quant_161_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_61_node_StreamingDepthwiseConv_63;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_61_node_StreamingDepthwiseConv_63.run<349>(Quant_161_out0_stream, Quant_161_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_161_out0_bwch_stream_0," << Quant_161_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_161_out0_bwch_stream_1," << Quant_161_out0_bwch_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_0.run<350>(Quant_161_out0_bwch_stream[0], node_StreamingDepthwiseConv_63_window_stream_prepad[11], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_11," << node_StreamingDepthwiseConv_63_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_0,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_1.run<351>(Quant_161_out0_bwch_stream[1], node_StreamingDepthwiseConv_63_window_stream_prepad[10], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_10," << node_StreamingDepthwiseConv_63_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_1,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_2.run<352>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_63_window_stream_prepad[9], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_9," << node_StreamingDepthwiseConv_63_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_2,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_3.run<353>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_63_window_stream_prepad[8], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_8," << node_StreamingDepthwiseConv_63_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_3,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_4.run<354>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_63_window_stream_prepad[7], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_7," << node_StreamingDepthwiseConv_63_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_4,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_5.run<355>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_63_window_stream_prepad[6], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_6," << node_StreamingDepthwiseConv_63_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_5,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_6.run<356>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_63_window_stream_prepad[5], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_5," << node_StreamingDepthwiseConv_63_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_6,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_7.run<357>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_63_window_stream_prepad[4], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_4," << node_StreamingDepthwiseConv_63_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_7,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_8.run<358>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_63_window_stream_prepad[3], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_3," << node_StreamingDepthwiseConv_63_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_8,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_9.run<359>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_63_window_stream_prepad[2], node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_2," << node_StreamingDepthwiseConv_63_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream_9,577" << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_10.run<360>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_63_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_1," << node_StreamingDepthwiseConv_63_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pixel_11.run<361>(node_StreamingDepthwiseConv_63_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_63_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_prepad_0," << node_StreamingDepthwiseConv_63_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_63_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_63_streaming_linebuffer_pad.run<362>(node_StreamingDepthwiseConv_63_window_stream_prepad, node_StreamingDepthwiseConv_63_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_0," << node_StreamingDepthwiseConv_63_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_1," << node_StreamingDepthwiseConv_63_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_2," << node_StreamingDepthwiseConv_63_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_3," << node_StreamingDepthwiseConv_63_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_4," << node_StreamingDepthwiseConv_63_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_5," << node_StreamingDepthwiseConv_63_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_6," << node_StreamingDepthwiseConv_63_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_7," << node_StreamingDepthwiseConv_63_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_8," << node_StreamingDepthwiseConv_63_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_9," << node_StreamingDepthwiseConv_63_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_10," << node_StreamingDepthwiseConv_63_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_63_window_stream_11," << node_StreamingDepthwiseConv_63_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_63_weights[576][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_63_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_63_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_63_biases[576][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_63_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_63_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_63;
    node_StreamingDepthwiseConv_63.run<363>(node_StreamingDepthwiseConv_63_window_stream, node_StreamingDepthwiseConv_63_weights, node_StreamingDepthwiseConv_63_biases, Quant_162_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_162_out0_stream_0," << Quant_162_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_162_out0_stream_1," << Quant_162_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_63_node_StreamingConv_65;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_63_node_StreamingConv_65.run<364>(Quant_162_out0_stream, Quant_162_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_162_out0_bwch_stream_0," << Quant_162_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_162_out0_bwch_stream_1," << Quant_162_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_65_streaming_linebuffer_pixel_0;
    node_StreamingConv_65_streaming_linebuffer_pixel_0.run<365>(Quant_162_out0_bwch_stream[1], node_StreamingConv_65_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_65_window_stream_1," << node_StreamingConv_65_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_65_streaming_linebuffer_pixel_1;
    node_StreamingConv_65_streaming_linebuffer_pixel_1.run<366>(Quant_162_out0_bwch_stream[0], node_StreamingConv_65_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_65_window_stream_0," << node_StreamingConv_65_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_65_weights[1536][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_65_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_65_weights dim=2 complete
    ap_int<16> node_StreamingConv_65_biases[16][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_65_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_65_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_65;
    node_StreamingConv_65.run<367>(node_StreamingConv_65_window_stream, node_StreamingConv_65_weights, node_StreamingConv_65_biases, Quant_163_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_163_out0_stream_0," << Quant_163_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_163_out0_stream_1," << Quant_163_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 6>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 6>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        6  // CH_PAR
    > node_StreamingAdd_66;
    node_StreamingAdd_66.run<368>(Quant_160_out0_stream, Quant_163_out0_stream, Quant_164_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_164_out0_stream_0," << Quant_164_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_164_out0_stream_1," << Quant_164_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        6,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_7;
    TensorDuplicator_7.run<369>(Quant_164_out0_stream, Quant_165_out0_stream, Quant_166_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_165_out0_stream_0," << Quant_165_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_165_out0_stream_1," << Quant_165_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_166_out0_stream_0," << Quant_166_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_166_out0_stream_1," << Quant_166_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_67_streaming_linebuffer_pixel_0;
    node_StreamingConv_67_streaming_linebuffer_pixel_0.run<370>(Quant_165_out0_stream[1], node_StreamingConv_67_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_67_window_stream_1," << node_StreamingConv_67_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_67_streaming_linebuffer_pixel_1;
    node_StreamingConv_67_streaming_linebuffer_pixel_1.run<371>(Quant_165_out0_stream[0], node_StreamingConv_67_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_67_window_stream_0," << node_StreamingConv_67_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_67_weights[1536][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_67_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_67_weights dim=2 complete
    ap_int<16> node_StreamingConv_67_biases[96][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_67_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_67_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 6>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_67;
    node_StreamingConv_67.run<372>(node_StreamingConv_67_window_stream, node_StreamingConv_67_weights, node_StreamingConv_67_biases, Quant_167_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_167_out0_stream_0," << Quant_167_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_167_out0_stream_1," << Quant_167_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_67_node_StreamingDepthwiseConv_69;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_67_node_StreamingDepthwiseConv_69.run<373>(Quant_167_out0_stream, Quant_167_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_167_out0_bwch_stream_0," << Quant_167_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_167_out0_bwch_stream_1," << Quant_167_out0_bwch_stream[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_0.run<374>(Quant_167_out0_bwch_stream[0], node_StreamingDepthwiseConv_69_window_stream_prepad[11], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_11," << node_StreamingDepthwiseConv_69_window_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_0,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_1.run<375>(Quant_167_out0_bwch_stream[1], node_StreamingDepthwiseConv_69_window_stream_prepad[10], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_10," << node_StreamingDepthwiseConv_69_window_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_1,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_2.run<376>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_69_window_stream_prepad[9], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_9," << node_StreamingDepthwiseConv_69_window_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_2,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_3.run<377>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_69_window_stream_prepad[8], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_8," << node_StreamingDepthwiseConv_69_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_3,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_4.run<378>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_69_window_stream_prepad[7], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_7," << node_StreamingDepthwiseConv_69_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_4,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_5.run<379>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_69_window_stream_prepad[6], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_6," << node_StreamingDepthwiseConv_69_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_5,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_6.run<380>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_69_window_stream_prepad[5], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_5," << node_StreamingDepthwiseConv_69_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_6,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_7.run<381>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_69_window_stream_prepad[4], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_4," << node_StreamingDepthwiseConv_69_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_7,3457" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_8.run<382>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_69_window_stream_prepad[3], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_3," << node_StreamingDepthwiseConv_69_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_8,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_9;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_9.run<383>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_69_window_stream_prepad[2], node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_2," << node_StreamingDepthwiseConv_69_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream_9,577" << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_10;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_10.run<384>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[8], node_StreamingDepthwiseConv_69_window_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_1," << node_StreamingDepthwiseConv_69_window_stream_prepad[1].size() << std::endl;
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
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_11;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pixel_11.run<385>(node_StreamingDepthwiseConv_69_streaming_linebuffer_buffer_stream[9], node_StreamingDepthwiseConv_69_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_prepad_0," << node_StreamingDepthwiseConv_69_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        2,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_69_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_69_streaming_linebuffer_pad.run<386>(node_StreamingDepthwiseConv_69_window_stream_prepad, node_StreamingDepthwiseConv_69_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_0," << node_StreamingDepthwiseConv_69_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_1," << node_StreamingDepthwiseConv_69_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_2," << node_StreamingDepthwiseConv_69_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_3," << node_StreamingDepthwiseConv_69_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_4," << node_StreamingDepthwiseConv_69_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_5," << node_StreamingDepthwiseConv_69_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_6," << node_StreamingDepthwiseConv_69_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_7," << node_StreamingDepthwiseConv_69_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_8," << node_StreamingDepthwiseConv_69_window_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_9," << node_StreamingDepthwiseConv_69_window_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_10," << node_StreamingDepthwiseConv_69_window_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_69_window_stream_11," << node_StreamingDepthwiseConv_69_window_stream[11].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_69_weights[576][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_69_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_69_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_69_biases[576][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_69_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_69_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_69;
    node_StreamingDepthwiseConv_69.run<387>(node_StreamingDepthwiseConv_69_window_stream, node_StreamingDepthwiseConv_69_weights, node_StreamingDepthwiseConv_69_biases, Quant_168_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_168_out0_stream_0," << Quant_168_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_168_out0_stream_1," << Quant_168_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_69_node_StreamingConv_71;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_69_node_StreamingConv_71.run<388>(Quant_168_out0_stream, Quant_168_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_168_out0_bwch_stream_0," << Quant_168_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_168_out0_bwch_stream_1," << Quant_168_out0_bwch_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_71_streaming_linebuffer_pixel_0;
    node_StreamingConv_71_streaming_linebuffer_pixel_0.run<389>(Quant_168_out0_bwch_stream[1], node_StreamingConv_71_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_71_window_stream_1," << node_StreamingConv_71_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_71_streaming_linebuffer_pixel_1;
    node_StreamingConv_71_streaming_linebuffer_pixel_1.run<390>(Quant_168_out0_bwch_stream[0], node_StreamingConv_71_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_71_window_stream_0," << node_StreamingConv_71_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_71_weights[1536][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_71_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_71_weights dim=2 complete
    ap_int<16> node_StreamingConv_71_biases[16][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_71_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_71_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_71;
    node_StreamingConv_71.run<391>(node_StreamingConv_71_window_stream, node_StreamingConv_71_weights, node_StreamingConv_71_biases, Quant_169_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_169_out0_stream_0," << Quant_169_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_169_out0_stream_1," << Quant_169_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 6>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 6>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 6>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        6  // CH_PAR
    > node_StreamingAdd_72;
    node_StreamingAdd_72.run<392>(Quant_166_out0_stream, Quant_169_out0_stream, Quant_170_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_170_out0_stream_0," << Quant_170_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_170_out0_stream_1," << Quant_170_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_73_streaming_linebuffer_pixel_0;
    node_StreamingConv_73_streaming_linebuffer_pixel_0.run<393>(Quant_170_out0_stream[1], node_StreamingConv_73_window_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_73_window_stream_1," << node_StreamingConv_73_window_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 6>,  // TWord
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
        6  // CH_PAR
    > node_StreamingConv_73_streaming_linebuffer_pixel_1;
    node_StreamingConv_73_streaming_linebuffer_pixel_1.run<394>(Quant_170_out0_stream[0], node_StreamingConv_73_window_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingConv_73_window_stream_0," << node_StreamingConv_73_window_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_73_weights[1536][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_73_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_73_weights dim=2 complete
    ap_int<16> node_StreamingConv_73_biases[96][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_73_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_73_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 6>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // IN_CH_PAR
        6,  // OUT_CH_PAR
        2  // W_PAR
    > node_StreamingConv_73;
    node_StreamingConv_73.run<395>(node_StreamingConv_73_window_stream, node_StreamingConv_73_weights, node_StreamingConv_73_biases, Quant_171_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_171_out0_stream_0," << Quant_171_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_171_out0_stream_1," << Quant_171_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_73_node_StreamingDepthwiseConv_75;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_73_node_StreamingDepthwiseConv_75.run<396>(Quant_171_out0_stream, Quant_171_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_171_out0_bwch_stream_0," << Quant_171_out0_bwch_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_171_out0_bwch_stream_1," << Quant_171_out0_bwch_stream[1].size() << std::endl;
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
    > BandwidthAdjustDecreaseStreams_node_StreamingConv_73_node_StreamingDepthwiseConv_75;
    BandwidthAdjustDecreaseStreams_node_StreamingConv_73_node_StreamingDepthwiseConv_75.run<397>(Quant_171_out0_bwch_stream, Quant_171_out0_bww_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_171_out0_bww_stream_0," << Quant_171_out0_bww_stream[0].size() << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_0.run<398>(Quant_171_out0_bww_stream[0], node_StreamingDepthwiseConv_75_window_stream_prepad[8], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_8," << node_StreamingDepthwiseConv_75_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_0,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_1.run<399>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_75_window_stream_prepad[7], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_7," << node_StreamingDepthwiseConv_75_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_1,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_2.run<400>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_75_window_stream_prepad[6], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_6," << node_StreamingDepthwiseConv_75_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_2,6913" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_3.run<401>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_75_window_stream_prepad[5], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_5," << node_StreamingDepthwiseConv_75_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_3,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_4.run<402>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_75_window_stream_prepad[4], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_4," << node_StreamingDepthwiseConv_75_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_4,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_5.run<403>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_75_window_stream_prepad[3], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_3," << node_StreamingDepthwiseConv_75_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_5,6913" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_6.run<404>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_75_window_stream_prepad[2], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_2," << node_StreamingDepthwiseConv_75_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_6,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_7.run<405>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_75_window_stream_prepad[1], node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_1," << node_StreamingDepthwiseConv_75_window_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream_7,577" << std::endl;
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
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pixel_8.run<406>(node_StreamingDepthwiseConv_75_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_75_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_prepad_0," << node_StreamingDepthwiseConv_75_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_75_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_75_streaming_linebuffer_pad.run<407>(node_StreamingDepthwiseConv_75_window_stream_prepad, node_StreamingDepthwiseConv_75_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_0," << node_StreamingDepthwiseConv_75_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_1," << node_StreamingDepthwiseConv_75_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_2," << node_StreamingDepthwiseConv_75_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_3," << node_StreamingDepthwiseConv_75_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_4," << node_StreamingDepthwiseConv_75_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_5," << node_StreamingDepthwiseConv_75_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_6," << node_StreamingDepthwiseConv_75_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_7," << node_StreamingDepthwiseConv_75_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_75_window_stream_8," << node_StreamingDepthwiseConv_75_window_stream[8].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_75_weights[576][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_75_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_75_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_75_biases[576][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_75_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_75_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_75;
    node_StreamingDepthwiseConv_75.run<408>(node_StreamingDepthwiseConv_75_window_stream, node_StreamingDepthwiseConv_75_weights, node_StreamingDepthwiseConv_75_biases, Quant_172_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_172_out0_stream_0," << Quant_172_out0_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_75_node_StreamingConv_77;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_75_node_StreamingConv_77.run<409>(Quant_172_out0_stream, Quant_172_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_172_out0_bwch_stream_0," << Quant_172_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_77_weights[2560][36][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_77_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_77_weights dim=2 complete
    ap_int<16> node_StreamingConv_77_biases[40][4][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_77_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_77_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 36>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
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
    > node_StreamingConv_77;
    node_StreamingConv_77.run<410>(Quant_172_out0_bwch_stream, node_StreamingConv_77_weights, node_StreamingConv_77_biases, Quant_173_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_173_out0_stream_0," << Quant_173_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_8;
    TensorDuplicator_8.run<411>(Quant_173_out0_stream, Quant_174_out0_stream, Quant_175_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_174_out0_stream_0," << Quant_174_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_175_out0_stream_0," << Quant_175_out0_stream[0].size() << std::endl;
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
    > BandwidthAdjustDecreaseChannels_TensorDuplicator_8_middle_node_StreamingConv_78;
    BandwidthAdjustDecreaseChannels_TensorDuplicator_8_middle_node_StreamingConv_78.run<412>(Quant_174_out0_stream, Quant_174_out0_bwch_gcd_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_174_out0_bwch_gcd_stream_0," << Quant_174_out0_bwch_gcd_stream[0].size() << std::endl;
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
    > BandwidthAdjustDecreaseChannels_TensorDuplicator_8_middle_node_StreamingAdd_83;
    BandwidthAdjustDecreaseChannels_TensorDuplicator_8_middle_node_StreamingAdd_83.run<413>(Quant_175_out0_stream, Quant_175_out0_bwch_gcd_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_175_out0_bwch_gcd_stream_0," << Quant_175_out0_bwch_gcd_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_8_node_StreamingConv_78;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_8_node_StreamingConv_78.run<414>(Quant_174_out0_bwch_gcd_stream, Quant_174_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_174_out0_bwch_stream_0," << Quant_174_out0_bwch_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_8_node_StreamingAdd_83;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_8_node_StreamingAdd_83.run<415>(Quant_175_out0_bwch_gcd_stream, Quant_175_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_175_out0_bwch_stream_0," << Quant_175_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_78_weights[2560][60][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_78_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_78_weights dim=2 complete
    ap_int<16> node_StreamingConv_78_biases[160][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_78_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_78_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 60>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_78;
    node_StreamingConv_78.run<416>(Quant_174_out0_bwch_stream, node_StreamingConv_78_weights, node_StreamingConv_78_biases, Quant_176_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_176_out0_stream_0," << Quant_176_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_78_node_StreamingDepthwiseConv_80;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_78_node_StreamingDepthwiseConv_80.run<417>(Quant_176_out0_stream, Quant_176_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_176_out0_bwch_stream_0," << Quant_176_out0_bwch_stream[0].size() << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_0.run<418>(Quant_176_out0_bwch_stream[0], node_StreamingDepthwiseConv_80_window_stream_prepad[8], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_8," << node_StreamingDepthwiseConv_80_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_0,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_1.run<419>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_80_window_stream_prepad[7], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_7," << node_StreamingDepthwiseConv_80_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_1,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_2.run<420>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_80_window_stream_prepad[6], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_6," << node_StreamingDepthwiseConv_80_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_2,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_3.run<421>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_80_window_stream_prepad[5], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_5," << node_StreamingDepthwiseConv_80_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_3,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_4.run<422>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_80_window_stream_prepad[4], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_4," << node_StreamingDepthwiseConv_80_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_4,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_5.run<423>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_80_window_stream_prepad[3], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_3," << node_StreamingDepthwiseConv_80_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_5,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_6.run<424>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_80_window_stream_prepad[2], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_2," << node_StreamingDepthwiseConv_80_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_6,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_7.run<425>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_80_window_stream_prepad[1], node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_1," << node_StreamingDepthwiseConv_80_window_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream_7,961" << std::endl;
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
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pixel_8.run<426>(node_StreamingDepthwiseConv_80_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_80_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_prepad_0," << node_StreamingDepthwiseConv_80_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_80_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_80_streaming_linebuffer_pad.run<427>(node_StreamingDepthwiseConv_80_window_stream_prepad, node_StreamingDepthwiseConv_80_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_0," << node_StreamingDepthwiseConv_80_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_1," << node_StreamingDepthwiseConv_80_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_2," << node_StreamingDepthwiseConv_80_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_3," << node_StreamingDepthwiseConv_80_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_4," << node_StreamingDepthwiseConv_80_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_5," << node_StreamingDepthwiseConv_80_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_6," << node_StreamingDepthwiseConv_80_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_7," << node_StreamingDepthwiseConv_80_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_80_window_stream_8," << node_StreamingDepthwiseConv_80_window_stream[8].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_80_weights[960][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_80_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_80_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_80_biases[960][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_80_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_80_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_80;
    node_StreamingDepthwiseConv_80.run<428>(node_StreamingDepthwiseConv_80_window_stream, node_StreamingDepthwiseConv_80_weights, node_StreamingDepthwiseConv_80_biases, Quant_177_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_177_out0_stream_0," << Quant_177_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_80_node_StreamingConv_82;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_80_node_StreamingConv_82.run<429>(Quant_177_out0_stream, Quant_177_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_177_out0_bwch_stream_0," << Quant_177_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_82_weights[2560][60][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_82_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_82_weights dim=2 complete
    ap_int<16> node_StreamingConv_82_biases[16][10][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_82_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_82_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 60>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 10>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 10>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<10, ap_int<27>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        10,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_82;
    node_StreamingConv_82.run<430>(Quant_177_out0_bwch_stream, node_StreamingConv_82_weights, node_StreamingConv_82_biases, Quant_178_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_178_out0_stream_0," << Quant_178_out0_stream[0].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 10>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 10>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 10>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        10  // CH_PAR
    > node_StreamingAdd_83;
    node_StreamingAdd_83.run<431>(Quant_175_out0_bwch_stream, Quant_178_out0_stream, Quant_179_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_179_out0_stream_0," << Quant_179_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 10>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        10,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingAdd_83_middle_TensorDuplicator_9;
    BandwidthAdjustDecreaseChannels_node_StreamingAdd_83_middle_TensorDuplicator_9.run<432>(Quant_179_out0_stream, Quant_179_out0_bwch_gcd_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_179_out0_bwch_gcd_stream_0," << Quant_179_out0_bwch_gcd_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingAdd_83_TensorDuplicator_9;
    BandwidthAdjustIncreaseChannels_node_StreamingAdd_83_TensorDuplicator_9.run<433>(Quant_179_out0_bwch_gcd_stream, Quant_179_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_179_out0_bwch_stream_0," << Quant_179_out0_bwch_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_9;
    TensorDuplicator_9.run<434>(Quant_179_out0_bwch_stream, Quant_180_out0_stream, Quant_181_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_180_out0_stream_0," << Quant_180_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "Quant_181_out0_stream_0," << Quant_181_out0_stream[0].size() << std::endl;
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
    > BandwidthAdjustDecreaseChannels_TensorDuplicator_9_middle_node_StreamingConv_84;
    BandwidthAdjustDecreaseChannels_TensorDuplicator_9_middle_node_StreamingConv_84.run<435>(Quant_180_out0_stream, Quant_180_out0_bwch_gcd_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_180_out0_bwch_gcd_stream_0," << Quant_180_out0_bwch_gcd_stream[0].size() << std::endl;
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
    > BandwidthAdjustDecreaseChannels_TensorDuplicator_9_middle_node_StreamingAdd_89;
    BandwidthAdjustDecreaseChannels_TensorDuplicator_9_middle_node_StreamingAdd_89.run<436>(Quant_181_out0_stream, Quant_181_out0_bwch_gcd_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_181_out0_bwch_gcd_stream_0," << Quant_181_out0_bwch_gcd_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_9_node_StreamingConv_84;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_9_node_StreamingConv_84.run<437>(Quant_180_out0_bwch_gcd_stream, Quant_180_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_180_out0_bwch_stream_0," << Quant_180_out0_bwch_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseChannels_TensorDuplicator_9_node_StreamingAdd_89;
    BandwidthAdjustIncreaseChannels_TensorDuplicator_9_node_StreamingAdd_89.run<438>(Quant_181_out0_bwch_gcd_stream, Quant_181_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_181_out0_bwch_stream_0," << Quant_181_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_84_weights[2560][60][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_84_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_84_weights dim=2 complete
    ap_int<16> node_StreamingConv_84_biases[160][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_84_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_84_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 60>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_84;
    node_StreamingConv_84.run<439>(Quant_180_out0_bwch_stream, node_StreamingConv_84_weights, node_StreamingConv_84_biases, Quant_182_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_182_out0_stream_0," << Quant_182_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_84_node_StreamingDepthwiseConv_86;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_84_node_StreamingDepthwiseConv_86.run<440>(Quant_182_out0_stream, Quant_182_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_182_out0_bwch_stream_0," << Quant_182_out0_bwch_stream[0].size() << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_0.run<441>(Quant_182_out0_bwch_stream[0], node_StreamingDepthwiseConv_86_window_stream_prepad[8], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_8," << node_StreamingDepthwiseConv_86_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_0,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_1.run<442>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_86_window_stream_prepad[7], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_7," << node_StreamingDepthwiseConv_86_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_1,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_2.run<443>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_86_window_stream_prepad[6], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_6," << node_StreamingDepthwiseConv_86_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_2,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_3.run<444>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_86_window_stream_prepad[5], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_5," << node_StreamingDepthwiseConv_86_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_3,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_4.run<445>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_86_window_stream_prepad[4], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_4," << node_StreamingDepthwiseConv_86_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_4,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_5.run<446>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_86_window_stream_prepad[3], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_3," << node_StreamingDepthwiseConv_86_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_5,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_6.run<447>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_86_window_stream_prepad[2], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_2," << node_StreamingDepthwiseConv_86_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_6,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_7.run<448>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_86_window_stream_prepad[1], node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_1," << node_StreamingDepthwiseConv_86_window_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream_7,961" << std::endl;
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
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pixel_8.run<449>(node_StreamingDepthwiseConv_86_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_86_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_prepad_0," << node_StreamingDepthwiseConv_86_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_86_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_86_streaming_linebuffer_pad.run<450>(node_StreamingDepthwiseConv_86_window_stream_prepad, node_StreamingDepthwiseConv_86_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_0," << node_StreamingDepthwiseConv_86_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_1," << node_StreamingDepthwiseConv_86_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_2," << node_StreamingDepthwiseConv_86_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_3," << node_StreamingDepthwiseConv_86_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_4," << node_StreamingDepthwiseConv_86_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_5," << node_StreamingDepthwiseConv_86_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_6," << node_StreamingDepthwiseConv_86_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_7," << node_StreamingDepthwiseConv_86_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_86_window_stream_8," << node_StreamingDepthwiseConv_86_window_stream[8].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_86_weights[960][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_86_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_86_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_86_biases[960][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_86_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_86_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_86;
    node_StreamingDepthwiseConv_86.run<451>(node_StreamingDepthwiseConv_86_window_stream, node_StreamingDepthwiseConv_86_weights, node_StreamingDepthwiseConv_86_biases, Quant_183_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_183_out0_stream_0," << Quant_183_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_86_node_StreamingConv_88;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_86_node_StreamingConv_88.run<452>(Quant_183_out0_stream, Quant_183_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_183_out0_bwch_stream_0," << Quant_183_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_88_weights[2560][60][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_88_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_88_weights dim=2 complete
    ap_int<16> node_StreamingConv_88_biases[16][10][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_88_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_88_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 60>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 10>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 10>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        10,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_88;
    node_StreamingConv_88.run<453>(Quant_183_out0_bwch_stream, node_StreamingConv_88_weights, node_StreamingConv_88_biases, Quant_184_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_184_out0_stream_0," << Quant_184_out0_stream[0].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 10>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 10>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 10>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        10  // CH_PAR
    > node_StreamingAdd_89;
    node_StreamingAdd_89.run<454>(Quant_181_out0_bwch_stream, Quant_184_out0_stream, Quant_185_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_185_out0_stream_0," << Quant_185_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_90_weights[2560][60][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_90_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_90_weights dim=2 complete
    ap_int<16> node_StreamingConv_90_biases[160][6][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_90_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_90_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 60>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 6>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 6>,  // TOutputWord
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
        6,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_90;
    node_StreamingConv_90.run<455>(Quant_185_out0_stream, node_StreamingConv_90_weights, node_StreamingConv_90_biases, Quant_186_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_186_out0_stream_0," << Quant_186_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 6>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        6,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_90_node_StreamingDepthwiseConv_92;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_90_node_StreamingDepthwiseConv_92.run<456>(Quant_186_out0_stream, Quant_186_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_186_out0_bwch_stream_0," << Quant_186_out0_bwch_stream[0].size() << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_0;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_0.run<457>(Quant_186_out0_bwch_stream[0], node_StreamingDepthwiseConv_92_window_stream_prepad[8], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_8," << node_StreamingDepthwiseConv_92_window_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_0,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_1;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_1.run<458>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[0], node_StreamingDepthwiseConv_92_window_stream_prepad[7], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_7," << node_StreamingDepthwiseConv_92_window_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_1,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_2;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_2.run<459>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[1], node_StreamingDepthwiseConv_92_window_stream_prepad[6], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_6," << node_StreamingDepthwiseConv_92_window_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_2,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_3;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_3.run<460>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[2], node_StreamingDepthwiseConv_92_window_stream_prepad[5], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_5," << node_StreamingDepthwiseConv_92_window_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_3,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_4;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_4.run<461>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[3], node_StreamingDepthwiseConv_92_window_stream_prepad[4], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_4," << node_StreamingDepthwiseConv_92_window_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_4,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_5;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_5.run<462>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[4], node_StreamingDepthwiseConv_92_window_stream_prepad[3], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_3," << node_StreamingDepthwiseConv_92_window_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_5,4801" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_6;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_6.run<463>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[5], node_StreamingDepthwiseConv_92_window_stream_prepad[2], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_2," << node_StreamingDepthwiseConv_92_window_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_6,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_7;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_7.run<464>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[6], node_StreamingDepthwiseConv_92_window_stream_prepad[1], node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_1," << node_StreamingDepthwiseConv_92_window_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream_7,961" << std::endl;
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
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_8;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pixel_8.run<465>(node_StreamingDepthwiseConv_92_streaming_linebuffer_buffer_stream[7], node_StreamingDepthwiseConv_92_window_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_prepad_0," << node_StreamingDepthwiseConv_92_window_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
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
        1,  // W_PAR
        1  // CH_PAR
    > node_StreamingDepthwiseConv_92_streaming_linebuffer_pad;
    node_StreamingDepthwiseConv_92_streaming_linebuffer_pad.run<466>(node_StreamingDepthwiseConv_92_window_stream_prepad, node_StreamingDepthwiseConv_92_window_stream);
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_0," << node_StreamingDepthwiseConv_92_window_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_1," << node_StreamingDepthwiseConv_92_window_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_2," << node_StreamingDepthwiseConv_92_window_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_3," << node_StreamingDepthwiseConv_92_window_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_4," << node_StreamingDepthwiseConv_92_window_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_5," << node_StreamingDepthwiseConv_92_window_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_6," << node_StreamingDepthwiseConv_92_window_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_7," << node_StreamingDepthwiseConv_92_window_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "node_StreamingDepthwiseConv_92_window_stream_8," << node_StreamingDepthwiseConv_92_window_stream[8].size() << std::endl;
    #endif
    ap_int<8> node_StreamingDepthwiseConv_92_weights[960][1][9];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_92_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_92_weights dim=2 complete
    ap_int<16> node_StreamingDepthwiseConv_92_biases[960][1][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_92_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingDepthwiseConv_92_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasStruct
        ap_int<16>,  // TBias
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
    > node_StreamingDepthwiseConv_92;
    node_StreamingDepthwiseConv_92.run<467>(node_StreamingDepthwiseConv_92_window_stream, node_StreamingDepthwiseConv_92_weights, node_StreamingDepthwiseConv_92_biases, Quant_187_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_187_out0_stream_0," << Quant_187_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 5>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        5  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_92_node_StreamingConv_94;
    BandwidthAdjustIncreaseChannels_node_StreamingDepthwiseConv_92_node_StreamingConv_94.run<468>(Quant_187_out0_stream, Quant_187_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_187_out0_bwch_stream_0," << Quant_187_out0_bwch_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_94_weights[3072][100][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_94_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_94_weights dim=2 complete
    ap_int<16> node_StreamingConv_94_biases[16][20][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_94_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_94_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 5>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 100>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 20>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 20>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        320,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        5,  // IN_CH_PAR
        20,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_94;
    node_StreamingConv_94.run<469>(Quant_187_out0_bwch_stream, node_StreamingConv_94_weights, node_StreamingConv_94_biases, Quant_188_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_188_out0_stream_0," << Quant_188_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_95_weights[2560][160][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_95_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_95_weights dim=2 complete
    ap_int<16> node_StreamingConv_95_biases[160][8][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_95_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_95_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 20>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 160>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 8>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 8>,  // TOutputWord
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
        20,  // IN_CH_PAR
        8,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_95;
    node_StreamingConv_95.run<470>(Quant_188_out0_stream, node_StreamingConv_95_weights, node_StreamingConv_95_biases, Quant_189_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_189_out0_stream_0," << Quant_189_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 8>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        1280,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        8,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_node_StreamingConv_95_node_StreamingGlobalAveragePool_97;
    BandwidthAdjustDecreaseChannels_node_StreamingConv_95_node_StreamingGlobalAveragePool_97.run<471>(Quant_189_out0_stream, Quant_189_out0_bwch_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_189_out0_bwch_stream_0," << Quant_189_out0_bwch_stream[0].size() << std::endl;
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
    > node_StreamingGlobalAveragePool_97;
    node_StreamingGlobalAveragePool_97.run<472>(Quant_189_out0_bwch_stream, Quant_190_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_190_out0_stream_0," << Quant_190_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> node_StreamingConv_98_weights[128000][10][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_98_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_98_weights dim=2 complete
    ap_int<16> node_StreamingConv_98_biases[100][10][1];
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_98_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=node_StreamingConv_98_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 10>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 10>,  // TOutputWord
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
        1,  // IN_CH_PAR
        10,  // OUT_CH_PAR
        1  // W_PAR
    > node_StreamingConv_98;
    node_StreamingConv_98.run<473>(Quant_190_out0_stream, node_StreamingConv_98_weights, node_StreamingConv_98_biases, Quant_191_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "Quant_191_out0_stream_0," << Quant_191_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 10>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        101,  // ITER
        16,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        1000,  // CH
        1,  // IN_W_PAR
        10  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.run<474>(Quant_191_out0_stream, global_out);
}