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
void mobilenet_v2(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_in_1, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis port=global_in
    #pragma HLS INTERFACE axis port=global_in_1
    #pragma HLS INTERFACE axis port=global_out
    hls::stream<std::array<ap_int<8>, 3>> NHWCToStream_0_out0_stream[2];
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> NHWCToStream_1_out0_stream[1];
    #pragma HLS STREAM variable=NHWCToStream_1_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[14] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[0] depth=56
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[1] depth=56
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[2] depth=56
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[3] depth=56
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[4] depth=56
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[5] depth=55
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[6] depth=57
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[7] depth=57
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[8] depth=57
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[9] depth=57
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[12] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingMemory_0_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_0_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_0_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_0_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_1_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_1_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_1_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_1_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_2_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_2_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_2_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_2_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[0] depth=3577
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[1] depth=3609
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[2] depth=3611
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[3] depth=3521
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[4] depth=1821
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[5] depth=1822
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[6] depth=1824
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[7] depth=1761
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[9] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[10] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[3] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[5] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[6] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[8] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[9] depth=3
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_3_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_3_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_3_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_3_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_4_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_4_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_4_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_4_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> BandwidthAdjustIncreaseChannels_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_5_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_5_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_5_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_5_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> StreamingLineBuffer_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 48>> StreamingMemory_6_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_6_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_6_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_6_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_7_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_7_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_7_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_7_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustIncreaseChannels_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingMemory_8_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_8_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_8_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_8_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 16>> StreamingLineBuffer_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_9_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_9_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_9_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_9_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 9>> StreamingMemory_10_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_10_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_10_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_10_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[14] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[0] depth=896
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[1] depth=920
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[2] depth=916
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[3] depth=896
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[4] depth=896
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[5] depth=865
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[6] depth=897
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[7] depth=897
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[8] depth=897
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[9] depth=897
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[10] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[4] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[5] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[6] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[7] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[8] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[10] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[11] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[12] depth=2
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_11_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_11_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_11_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_11_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingDepthwiseConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_12_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_12_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_12_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_12_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseStreams_0_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<14>, 4>> StreamingMemory_13_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_13_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_13_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_13_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_5_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[0] depth=241
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[1] depth=241
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[2] depth=237
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[3] depth=237
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_14_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_14_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_14_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_14_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_3_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_15_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_15_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_15_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_15_out1_stream[0] depth=2
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
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_16_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_16_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_16_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_16_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_0_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_1_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[0] depth=410
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[1] depth=410
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[2] depth=410
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[3] depth=410
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_17_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_17_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_17_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_17_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_2_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_18_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_18_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_18_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_18_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_6_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<13>, 2>> StreamingMemory_19_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_19_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_19_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_19_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_4_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[0] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[1] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[2] depth=28
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[3] depth=28
    hls::stream<std::array<ap_int<8>, 2>> StreamingMemory_20_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_20_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_20_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_20_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_2_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<15>, 2>> StreamingMemory_21_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_21_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_21_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_21_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[17] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[0] depth=4033
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[1] depth=4177
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[2] depth=4177
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[3] depth=4177
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[4] depth=4177
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[5] depth=3745
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[6] depth=2161
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[7] depth=2162
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[8] depth=2162
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[9] depth=2162
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[10] depth=2162
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[11] depth=1873
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[12] depth=289
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[13] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[14] depth=147
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[15] depth=147
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[16] depth=147
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[13] depth=2
    hls::stream<std::array<ap_int<8>, 9>> StreamingMemory_22_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_22_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_22_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_22_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_2_out0_stream[4];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_23_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_23_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_23_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_23_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> BandwidthAdjustIncreaseChannels_3_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_24_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_24_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_24_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_24_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 16>> StreamingLineBuffer_8_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_25_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_25_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_25_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_25_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_5_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_26_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_26_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_26_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_26_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_0_out0_stream[4];
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_27_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_27_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_27_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_27_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 8>> BandwidthAdjustIncreaseChannels_4_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_4_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_28_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_28_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_28_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_28_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 8>> StreamingLineBuffer_9_out0_stream[4];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_29_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_29_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_29_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_29_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_6_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[2] depth=73
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[3] depth=73
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_30_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_30_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_30_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_30_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> BandwidthAdjustDecreaseStreams_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_31_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_31_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_31_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_31_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[14] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[0] depth=1008
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[1] depth=1072
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[2] depth=1068
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[3] depth=1008
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[4] depth=1008
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[5] depth=937
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[6] depth=1009
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[7] depth=1009
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[8] depth=1009
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[9] depth=1009
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[11] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[12] depth=73
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[12] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_32_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_32_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_32_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_32_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingDepthwiseConv_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_33_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_33_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_33_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_33_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_34_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_34_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_34_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_34_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_35_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_35_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_35_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_35_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[0] depth=139
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[1] depth=139
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_36_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_36_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_36_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_36_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_37_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_37_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_37_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_37_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_38_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_38_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_38_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_38_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_7_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_7_out0_stream[0] depth=145
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_7_out0_stream[1] depth=145
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_39_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_39_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_39_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_39_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[1] depth=9
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_40_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_40_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_40_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_40_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[1] depth=44
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_41_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_41_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_41_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_41_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_4_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_42_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_42_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_42_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_42_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[1] depth=5569
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[2] depth=5569
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[3] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[4] depth=2881
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[5] depth=2882
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[6] depth=2882
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[9] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[10] depth=195
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_43_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_43_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_43_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_43_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_44_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_44_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_44_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_44_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_8_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_45_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_45_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_45_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_45_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[0] depth=643
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[1] depth=643
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_46_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_46_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_46_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_46_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_47_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_47_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_47_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_47_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[0] depth=8
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[1] depth=8
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_48_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_48_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_48_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_48_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_49_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_49_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_49_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_49_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_50_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_50_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_50_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_50_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_9_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_10_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_10_out0_stream[0] depth=145
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_10_out0_stream[1] depth=145
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_51_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_51_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_51_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_51_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_52_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_52_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_52_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_52_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[1] depth=44
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_53_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_53_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_53_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_53_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_54_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_54_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_54_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_54_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[1] depth=5569
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[2] depth=5569
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[3] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[4] depth=2881
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[5] depth=2882
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[6] depth=2882
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[8] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[9] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[10] depth=195
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_55_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_55_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_55_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_55_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_5_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_56_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_56_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_56_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_56_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_11_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_57_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_57_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_57_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_57_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[0] depth=643
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[1] depth=643
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_58_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_58_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_58_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_58_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_59_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_59_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_59_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_59_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_60_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_60_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_60_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_60_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_61_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_61_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_61_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_61_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[1] depth=44
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_62_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_62_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_62_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_62_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_7_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_63_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_63_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_63_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_63_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[14] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[0] depth=1344
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[1] depth=1535
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[2] depth=1535
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[3] depth=1344
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[4] depth=1344
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[5] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[6] depth=1345
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[7] depth=1345
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[8] depth=1345
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[9] depth=1345
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[10] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[11] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[12] depth=193
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[12] depth=2
    hls::stream<std::array<ap_int<8>, 18>> StreamingMemory_64_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_64_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_64_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_64_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_6_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_65_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_65_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_65_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_65_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_12_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_12_out0_stream[0] depth=23
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_12_out0_stream[1] depth=65
    hls::stream<std::array<ap_int<8>, 36>> StreamingMemory_66_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_66_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_66_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_66_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustDecreaseStreams_1_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_1_out0_stream[0] depth=564
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_67_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_67_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_67_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_67_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_13_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_68_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_68_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_68_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_68_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_69_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_69_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_69_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_69_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_2_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[0] depth=177
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[1] depth=161
    hls::stream<std::array<ap_int<8>, 27>> StreamingMemory_70_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_70_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_70_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_70_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[0] depth=24
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[1] depth=16
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_71_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_71_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_71_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_71_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[0] depth=87
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[1] depth=87
    hls::stream<std::array<ap_int<8>, 36>> StreamingMemory_72_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_72_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_72_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_72_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_8_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_73_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_73_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_73_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_73_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[1] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[2] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[3] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[4] depth=3073
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[5] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[6] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[8] depth=769
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[9] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[10] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_74_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_74_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_74_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_74_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_75_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_75_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_75_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_75_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_13_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 27>> StreamingMemory_76_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_76_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_76_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_76_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[0] depth=939
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[1] depth=939
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_77_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_77_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_77_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_77_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 36>> StreamingMemory_78_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_78_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_78_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_78_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[0] depth=17
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[1] depth=19
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_79_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_79_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_79_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_79_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_2_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_2_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_80_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_80_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_80_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_80_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_81_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_81_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_81_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_81_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_4_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_4_out0_stream[0] depth=177
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_4_out0_stream[1] depth=177
    hls::stream<std::array<ap_int<8>, 36>> StreamingMemory_82_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_82_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_82_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_82_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[0] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_83_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_83_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_83_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_83_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_16_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[0] depth=87
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[1] depth=87
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_84_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_84_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_84_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_84_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_9_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_85_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_85_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_85_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_85_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[1] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[2] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[3] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[4] depth=3073
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[5] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[6] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[8] depth=769
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[9] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[10] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_86_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_86_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_86_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_86_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_8_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_87_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_87_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_87_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_87_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_14_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_14_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_88_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_88_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_88_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_88_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[0] depth=939
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[1] depth=939
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_89_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_89_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_89_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_89_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_90_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_90_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_90_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_90_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[0] depth=17
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[1] depth=19
    hls::stream<std::array<ap_int<13>, 4>> StreamingMemory_91_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_91_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_91_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_91_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_3_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_3_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_92_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_92_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_92_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_92_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_93_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_93_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_93_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_93_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_6_out0_stream[0] depth=177
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_6_out0_stream[1] depth=177
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_94_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_94_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_94_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_94_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[0] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<15>, 2>> StreamingMemory_95_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_95_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_95_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_95_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[0] depth=87
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[1] depth=87
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_96_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_96_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_96_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_96_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_10_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<14>, 2>> StreamingMemory_97_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_97_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_97_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_97_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[1] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[2] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[3] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[4] depth=3073
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[5] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[6] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[8] depth=769
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[9] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[10] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_27_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_98_out0_stream[9];
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingMemory_98_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_98_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_98_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_9_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_99_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_99_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_99_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_99_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_15_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_15_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_15_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 120>> StreamingMemory_100_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_100_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_100_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_100_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_28_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[0] depth=939
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[1] depth=939
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_101_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_101_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_101_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_101_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 160>> StreamingMemory_102_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_102_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_102_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_102_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<12>, 4>> StreamingMemory_103_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_103_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_103_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_103_out1_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_29_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[0] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[1] depth=18
    hls::stream<std::array<ap_int<8>, 10>> StreamingMemory_104_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_104_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_104_out1_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_104_out1_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[0] depth=87
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[1] depth=87
    hls::stream<std::array<ap_int<9>, 2>> StreamingMemory_105_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMemory_105_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_11_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[0] depth=5377
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[1] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[2] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[3] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[4] depth=3073
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[5] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[6] depth=3074
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[7] depth=2305
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[8] depth=769
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[9] depth=385
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[10] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> BandwidthAdjustIncreaseChannels_16_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_16_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_16_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 6>> StreamingLineBuffer_31_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[0] depth=470
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[1] depth=470
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_21_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[0] depth=353
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[1] depth=353
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_17_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_17_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_17_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_32_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[1] depth=9
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_12_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[0] depth=8065
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[1] depth=8641
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[2] depth=8641
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[3] depth=6913
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[4] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[5] depth=4610
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[6] depth=4610
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[7] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[8] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[9] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[10] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_33_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_33_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_18_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_18_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_18_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_34_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[0] depth=353
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[1] depth=353
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_19_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_19_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_35_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[1] depth=9
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_24_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_13_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[0] depth=8065
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[1] depth=8641
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[2] depth=8641
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[3] depth=6913
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[4] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[5] depth=4610
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[6] depth=4610
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[7] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[8] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[9] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[10] depth=579
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_36_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_12_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_12_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_20_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_20_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_20_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_37_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> BandwidthAdjustIncreaseChannels_21_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_21_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_21_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 12>> StreamingLineBuffer_38_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[1] depth=9
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_14_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[1] depth=578
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseStreams_4_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_4_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[0] depth=4032
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[1] depth=4596
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[2] depth=4033
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[3] depth=3457
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[4] depth=4032
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[5] depth=4032
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[6] depth=576
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[7] depth=577
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[7] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_13_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_13_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_22_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_22_out0_stream[0] depth=141
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_27_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_27_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[0] depth=521
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_15_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_15_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 10>> BandwidthAdjustIncreaseChannels_23_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_23_out0_stream[0] depth=55
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_28_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_28_out0_stream[0] depth=181
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_16_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_16_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[0] depth=13441
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[1] depth=14401
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[2] depth=11521
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[3] depth=7681
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[4] depth=7682
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[5] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[6] depth=1921
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[7] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream_prepad[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_40_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_40_buffer_stream[7] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_14_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_14_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 10>> BandwidthAdjustIncreaseChannels_24_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_24_out0_stream[0] depth=650
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_29_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_29_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_8_out0_stream[1];
    #pragma HLS STREAM variable=StreamingAdd_8_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_9_out0_stream[0] depth=23
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_9_out1_stream[0] depth=23
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_17_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_17_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_18_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_18_out0_stream[0] depth=881
    hls::stream<std::array<ap_int<8>, 10>> BandwidthAdjustIncreaseChannels_25_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_25_out0_stream[0] depth=18
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_30_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_30_out0_stream[0] depth=181
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_19_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_19_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[0] depth=13441
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[1] depth=14401
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[2] depth=11521
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[3] depth=7681
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[4] depth=7682
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[5] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[6] depth=1921
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[7] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_41_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[7] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_15_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_15_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 20>> BandwidthAdjustIncreaseChannels_26_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_26_out0_stream[0] depth=326
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_31_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_31_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingAdd_9_out0_stream[1];
    #pragma HLS STREAM variable=StreamingAdd_9_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 20>> BandwidthAdjustIncreaseChannels_27_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_27_out0_stream[0] depth=9
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_32_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_32_out0_stream[0] depth=242
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_20_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_20_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[0] depth=13441
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[1] depth=14401
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[2] depth=11521
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[3] depth=7681
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[4] depth=7682
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[5] depth=5761
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[6] depth=1921
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[7] depth=961
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[8] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_42_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[7] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_16_out0_stream[1];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_16_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 30>> BandwidthAdjustIncreaseChannels_28_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_28_out0_stream[0] depth=182
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_33_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_33_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 40>> BandwidthAdjustIncreaseChannels_29_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_29_out0_stream[0] depth=9
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_34_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_34_out0_stream[0] depth=241
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_21_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_21_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingGlobalAveragePool_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingGlobalAveragePool_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 5>> BandwidthAdjustIncreaseChannels_30_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_30_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_35_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_35_out0_stream[0] depth=2
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
        2,  // OUT_W_PAR
        3  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.run<0>(global_in, NHWCToStream_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_0," << NHWCToStream_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_1," << NHWCToStream_0_out0_stream[1].size() << std::endl;
    #endif
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_uint<32>, 1>,  // TOutputStruct
        ap_uint<32>,  // TOutput
        DequantQuantEqual<ap_uint<32>>,  // Quantizer
        4,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        876302,  // CH
        1,  // OUT_W_PAR
        1  // OUT_CH_PAR
    > NHWCToStream_1;
    NHWCToStream_1.run<1>(global_in_1, NHWCToStream_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_1_out0_stream_0," << NHWCToStream_1_out0_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_0.run<2>(NHWCToStream_0_out0_stream[1], StreamingLineBuffer_0_out0_stream_prepad[14], StreamingLineBuffer_0_buffer_stream[0]);
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
    StreamingLineBuffer_0_pixel_1.run<3>(NHWCToStream_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[13], StreamingLineBuffer_0_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_13," << StreamingLineBuffer_0_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_1," << StreamingLineBuffer_0_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        4,  // DATA_PER_WORD
        876086,  // DATA_TO_SHIFT
        6272,  // TIMES
        864,  // WORDS
        9,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_0;
    StreamingMemory_0.run<18>(NHWCToStream_1_out0_stream, StreamingMemory_0_out0_stream, StreamingMemory_0_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_0," << StreamingMemory_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_1," << StreamingMemory_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_2," << StreamingMemory_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_3," << StreamingMemory_0_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_4," << StreamingMemory_0_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_5," << StreamingMemory_0_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_6," << StreamingMemory_0_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_7," << StreamingMemory_0_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out0_stream_8," << StreamingMemory_0_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_0_out1_stream_0," << StreamingMemory_0_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_2.run<4>(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[12], StreamingLineBuffer_0_buffer_stream[2]);
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
    StreamingLineBuffer_0_pixel_3.run<5>(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[11], StreamingLineBuffer_0_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_11," << StreamingLineBuffer_0_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_4," << StreamingLineBuffer_0_buffer_stream[4].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        876070,  // DATA_TO_SHIFT
        6272,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_1;
    StreamingMemory_1.run<19>(StreamingMemory_0_out1_stream, StreamingMemory_1_out0_stream, StreamingMemory_1_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_1_out0_stream_0," << StreamingMemory_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_1_out1_stream_0," << StreamingMemory_1_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_4.run<6>(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[10], StreamingLineBuffer_0_buffer_stream[3]);
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
    StreamingLineBuffer_0_pixel_6.run<8>(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_8," << StreamingLineBuffer_0_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_6," << StreamingLineBuffer_0_buffer_stream[6].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875998,  // DATA_TO_SHIFT
        6272,  // TIMES
        288,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_2;
    StreamingMemory_2.run<21>(StreamingMemory_1_out1_stream, StreamingMemory_2_out0_stream, StreamingMemory_2_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_0," << StreamingMemory_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_1," << StreamingMemory_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_2," << StreamingMemory_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_3," << StreamingMemory_2_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_4," << StreamingMemory_2_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_5," << StreamingMemory_2_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_6," << StreamingMemory_2_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_7," << StreamingMemory_2_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out0_stream_8," << StreamingMemory_2_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_2_out1_stream_0," << StreamingMemory_2_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_5.run<7>(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[9], StreamingLineBuffer_0_buffer_stream[5]);
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
    StreamingLineBuffer_0_pixel_8.run<10>(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_6," << StreamingLineBuffer_0_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_9," << StreamingLineBuffer_0_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875982,  // DATA_TO_SHIFT
        6272,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_3;
    StreamingMemory_3.run<35>(StreamingMemory_2_out1_stream, StreamingMemory_3_out0_stream, StreamingMemory_3_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_3_out0_stream_0," << StreamingMemory_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_3_out1_stream_0," << StreamingMemory_3_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_7.run<9>(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[7]);
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
    StreamingLineBuffer_0_pixel_11.run<13>(StreamingLineBuffer_0_buffer_stream[9], StreamingLineBuffer_0_out0_stream_prepad[3], StreamingLineBuffer_0_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_3," << StreamingLineBuffer_0_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_11," << StreamingLineBuffer_0_buffer_stream[11].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875854,  // DATA_TO_SHIFT
        6272,  // TIMES
        512,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_4;
    StreamingMemory_4.run<37>(StreamingMemory_3_out1_stream, StreamingMemory_4_out0_stream, StreamingMemory_4_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_4_out0_stream_0," << StreamingMemory_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_4_out1_stream_0," << StreamingMemory_4_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_9.run<11>(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[8]);
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
    StreamingLineBuffer_0_pixel_13.run<15>(StreamingLineBuffer_0_buffer_stream[11], StreamingLineBuffer_0_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_1," << StreamingLineBuffer_0_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875846,  // DATA_TO_SHIFT
        6272,  // TIMES
        16,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_5;
    StreamingMemory_5.run<39>(StreamingMemory_4_out1_stream, StreamingMemory_5_out0_stream, StreamingMemory_5_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_5_out0_stream_0," << StreamingMemory_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_5_out1_stream_0," << StreamingMemory_5_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_10.run<12>(StreamingLineBuffer_0_buffer_stream[8], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_4," << StreamingLineBuffer_0_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_10," << StreamingLineBuffer_0_buffer_stream[10].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 48>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875462,  // DATA_TO_SHIFT
        6272,  // TIMES
        1536,  // WORDS
        1,  // ARRAY_PAR
        48  // WORD_PAR
    > StreamingMemory_6;
    StreamingMemory_6.run<42>(StreamingMemory_5_out1_stream, StreamingMemory_6_out0_stream, StreamingMemory_6_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_6_out0_stream_0," << StreamingMemory_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_6_out1_stream_0," << StreamingMemory_6_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_12.run<14>(StreamingLineBuffer_0_buffer_stream[10], StreamingLineBuffer_0_out0_stream_prepad[2], StreamingLineBuffer_0_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_2," << StreamingLineBuffer_0_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_12," << StreamingLineBuffer_0_buffer_stream[12].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875414,  // DATA_TO_SHIFT
        6272,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_7;
    StreamingMemory_7.run<44>(StreamingMemory_6_out1_stream, StreamingMemory_7_out0_stream, StreamingMemory_7_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_7_out0_stream_0," << StreamingMemory_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_7_out1_stream_0," << StreamingMemory_7_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pixel_14.run<16>(StreamingLineBuffer_0_buffer_stream[12], StreamingLineBuffer_0_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_0," << StreamingLineBuffer_0_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875198,  // DATA_TO_SHIFT
        1568,  // TIMES
        864,  // WORDS
        9,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_8;
    StreamingMemory_8.run<46>(StreamingMemory_7_out1_stream, StreamingMemory_8_out0_stream, StreamingMemory_8_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_0," << StreamingMemory_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_1," << StreamingMemory_8_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_2," << StreamingMemory_8_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_3," << StreamingMemory_8_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_4," << StreamingMemory_8_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_5," << StreamingMemory_8_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_6," << StreamingMemory_8_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_7," << StreamingMemory_8_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out0_stream_8," << StreamingMemory_8_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_8_out1_stream_0," << StreamingMemory_8_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_0_pad.run<17>(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875150,  // DATA_TO_SHIFT
        1568,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_9;
    StreamingMemory_9.run<49>(StreamingMemory_8_out1_stream, StreamingMemory_9_out0_stream, StreamingMemory_9_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_9_out0_stream_0," << StreamingMemory_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_9_out1_stream_0," << StreamingMemory_9_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_0.run<20>(StreamingLineBuffer_0_out0_stream, StreamingMemory_0_out0_stream, StreamingMemory_1_out0_stream, StreamingConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_0," << StreamingConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_1," << StreamingConv_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 9>,  // TOutputStruct
        4,  // DATA_PER_WORD
        874574,  // DATA_TO_SHIFT
        784,  // TIMES
        2304,  // WORDS
        1,  // ARRAY_PAR
        9  // WORD_PAR
    > StreamingMemory_10;
    StreamingMemory_10.run<51>(StreamingMemory_9_out1_stream, StreamingMemory_10_out0_stream, StreamingMemory_10_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_10_out0_stream_0," << StreamingMemory_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_10_out1_stream_0," << StreamingMemory_10_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_0.run<22>(StreamingConv_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[0]);
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
    StreamingLineBuffer_1_pixel_1.run<23>(StreamingConv_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_10," << StreamingLineBuffer_1_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_1," << StreamingLineBuffer_1_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        874562,  // DATA_TO_SHIFT
        784,  // TIMES
        24,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_11;
    StreamingMemory_11.run<68>(StreamingMemory_10_out1_stream, StreamingMemory_11_out0_stream, StreamingMemory_11_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_11_out0_stream_0," << StreamingMemory_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_11_out1_stream_0," << StreamingMemory_11_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_2.run<24>(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[2]);
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
    StreamingLineBuffer_1_pixel_3.run<25>(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_8," << StreamingLineBuffer_1_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_3," << StreamingLineBuffer_1_buffer_stream[3].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        873698,  // DATA_TO_SHIFT
        784,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_12;
    StreamingMemory_12.run<70>(StreamingMemory_11_out1_stream, StreamingMemory_12_out0_stream, StreamingMemory_12_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_12_out0_stream_0," << StreamingMemory_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_12_out1_stream_0," << StreamingMemory_12_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_4.run<26>(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[4]);
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
    StreamingLineBuffer_1_pixel_5.run<27>(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_6," << StreamingLineBuffer_1_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_5," << StreamingLineBuffer_1_buffer_stream[5].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        873626,  // DATA_TO_SHIFT
        784,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_13;
    StreamingMemory_13.run<72>(StreamingMemory_12_out1_stream, StreamingMemory_13_out0_stream, StreamingMemory_13_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_13_out0_stream_0," << StreamingMemory_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_13_out1_stream_0," << StreamingMemory_13_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_6.run<28>(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[6]);
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
    StreamingLineBuffer_1_pixel_7.run<29>(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_4," << StreamingLineBuffer_1_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_7," << StreamingLineBuffer_1_buffer_stream[7].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        873302,  // DATA_TO_SHIFT
        784,  // TIMES
        1296,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_14;
    StreamingMemory_14.run<77>(StreamingMemory_13_out1_stream, StreamingMemory_14_out0_stream, StreamingMemory_14_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_0," << StreamingMemory_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_1," << StreamingMemory_14_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_2," << StreamingMemory_14_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_3," << StreamingMemory_14_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_4," << StreamingMemory_14_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_5," << StreamingMemory_14_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_6," << StreamingMemory_14_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_7," << StreamingMemory_14_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out0_stream_8," << StreamingMemory_14_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_14_out1_stream_0," << StreamingMemory_14_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_8.run<30>(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[3], StreamingLineBuffer_1_buffer_stream[8]);
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
    StreamingLineBuffer_1_pixel_9.run<31>(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[2], StreamingLineBuffer_1_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_2," << StreamingLineBuffer_1_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_9," << StreamingLineBuffer_1_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        873230,  // DATA_TO_SHIFT
        784,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_15;
    StreamingMemory_15.run<79>(StreamingMemory_14_out1_stream, StreamingMemory_15_out0_stream, StreamingMemory_15_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_15_out0_stream_0," << StreamingMemory_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_15_out1_stream_0," << StreamingMemory_15_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pixel_10.run<32>(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[1]);
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
    StreamingLineBuffer_1_pixel_11.run<33>(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_0," << StreamingLineBuffer_1_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        872366,  // DATA_TO_SHIFT
        784,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_16;
    StreamingMemory_16.run<81>(StreamingMemory_15_out1_stream, StreamingMemory_16_out0_stream, StreamingMemory_16_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_16_out0_stream_0," << StreamingMemory_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_16_out1_stream_0," << StreamingMemory_16_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_1_pad.run<34>(StreamingLineBuffer_1_out0_stream_prepad, StreamingLineBuffer_1_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        872354,  // DATA_TO_SHIFT
        784,  // TIMES
        24,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_17;
    StreamingMemory_17.run<84>(StreamingMemory_16_out1_stream, StreamingMemory_17_out0_stream, StreamingMemory_17_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_17_out0_stream_0," << StreamingMemory_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_17_out1_stream_0," << StreamingMemory_17_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_0.run<36>(StreamingLineBuffer_1_out0_stream, StreamingMemory_2_out0_stream, StreamingMemory_3_out0_stream, StreamingDepthwiseConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_0," << StreamingDepthwiseConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_1," << StreamingDepthwiseConv_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        871490,  // DATA_TO_SHIFT
        784,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_18;
    StreamingMemory_18.run<86>(StreamingMemory_17_out1_stream, StreamingMemory_18_out0_stream, StreamingMemory_18_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_18_out0_stream_0," << StreamingMemory_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_18_out1_stream_0," << StreamingMemory_18_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_0.run<38>(StreamingDepthwiseConv_0_out0_stream, BandwidthAdjustIncreaseChannels_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_0," << BandwidthAdjustIncreaseChannels_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_1," << BandwidthAdjustIncreaseChannels_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<13>,  // TOutput
        std::array<ap_int<13>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        871418,  // DATA_TO_SHIFT
        784,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_19;
    StreamingMemory_19.run<91>(StreamingMemory_18_out1_stream, StreamingMemory_19_out0_stream, StreamingMemory_19_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_19_out0_stream_0," << StreamingMemory_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_19_out1_stream_0," << StreamingMemory_19_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_2_pixel_0.run<40>(BandwidthAdjustIncreaseChannels_0_out0_stream[1], StreamingLineBuffer_2_out0_stream[1]);
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
    StreamingLineBuffer_2_pixel_1.run<41>(BandwidthAdjustIncreaseChannels_0_out0_stream[0], StreamingLineBuffer_2_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_0," << StreamingLineBuffer_2_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        4,  // DATA_PER_WORD
        871094,  // DATA_TO_SHIFT
        392,  // TIMES
        1296,  // WORDS
        9,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_20;
    StreamingMemory_20.run<93>(StreamingMemory_19_out1_stream, StreamingMemory_20_out0_stream, StreamingMemory_20_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_0," << StreamingMemory_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_1," << StreamingMemory_20_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_2," << StreamingMemory_20_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_3," << StreamingMemory_20_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_4," << StreamingMemory_20_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_5," << StreamingMemory_20_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_6," << StreamingMemory_20_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_7," << StreamingMemory_20_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out0_stream_8," << StreamingMemory_20_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_20_out1_stream_0," << StreamingMemory_20_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_1.run<43>(StreamingLineBuffer_2_out0_stream, StreamingMemory_4_out0_stream, StreamingMemory_5_out0_stream, StreamingConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_0," << StreamingConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_1," << StreamingConv_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        871022,  // DATA_TO_SHIFT
        392,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_21;
    StreamingMemory_21.run<95>(StreamingMemory_20_out1_stream, StreamingMemory_21_out0_stream, StreamingMemory_21_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_21_out0_stream_0," << StreamingMemory_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_21_out1_stream_0," << StreamingMemory_21_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_1.run<45>(StreamingConv_1_out0_stream, BandwidthAdjustIncreaseChannels_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_0," << BandwidthAdjustIncreaseChannels_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_1," << BandwidthAdjustIncreaseChannels_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 9>,  // TOutputStruct
        4,  // DATA_PER_WORD
        869870,  // DATA_TO_SHIFT
        392,  // TIMES
        4608,  // WORDS
        1,  // ARRAY_PAR
        9  // WORD_PAR
    > StreamingMemory_22;
    StreamingMemory_22.run<115>(StreamingMemory_21_out1_stream, StreamingMemory_22_out0_stream, StreamingMemory_22_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_22_out0_stream_0," << StreamingMemory_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_22_out1_stream_0," << StreamingMemory_22_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_3_pixel_0.run<47>(BandwidthAdjustIncreaseChannels_1_out0_stream[1], StreamingLineBuffer_3_out0_stream[1]);
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
    StreamingLineBuffer_3_pixel_1.run<48>(BandwidthAdjustIncreaseChannels_1_out0_stream[0], StreamingLineBuffer_3_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_0," << StreamingLineBuffer_3_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        869854,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_23;
    StreamingMemory_23.run<117>(StreamingMemory_22_out1_stream, StreamingMemory_23_out0_stream, StreamingMemory_23_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_23_out0_stream_0," << StreamingMemory_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_23_out1_stream_0," << StreamingMemory_23_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_2.run<50>(StreamingLineBuffer_3_out0_stream, StreamingMemory_6_out0_stream, StreamingMemory_7_out0_stream, StreamingConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_0," << StreamingConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_1," << StreamingConv_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        868318,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_24;
    StreamingMemory_24.run<119>(StreamingMemory_23_out1_stream, StreamingMemory_24_out0_stream, StreamingMemory_24_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_24_out0_stream_0," << StreamingMemory_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_24_out1_stream_0," << StreamingMemory_24_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_0.run<52>(StreamingConv_2_out0_stream[1], StreamingLineBuffer_4_out0_stream_prepad[14], StreamingLineBuffer_4_buffer_stream[0]);
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
    StreamingLineBuffer_4_pixel_1.run<53>(StreamingConv_2_out0_stream[0], StreamingLineBuffer_4_out0_stream_prepad[13], StreamingLineBuffer_4_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_13," << StreamingLineBuffer_4_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_1," << StreamingLineBuffer_4_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        868222,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_25;
    StreamingMemory_25.run<124>(StreamingMemory_24_out1_stream, StreamingMemory_25_out0_stream, StreamingMemory_25_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_25_out0_stream_0," << StreamingMemory_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_25_out1_stream_0," << StreamingMemory_25_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_2.run<54>(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream_prepad[12], StreamingLineBuffer_4_buffer_stream[2]);
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
    StreamingLineBuffer_4_pixel_3.run<55>(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream_prepad[11], StreamingLineBuffer_4_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_11," << StreamingLineBuffer_4_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_4," << StreamingLineBuffer_4_buffer_stream[4].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        867790,  // DATA_TO_SHIFT
        392,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_26;
    StreamingMemory_26.run<126>(StreamingMemory_25_out1_stream, StreamingMemory_26_out0_stream, StreamingMemory_26_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_0," << StreamingMemory_26_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_1," << StreamingMemory_26_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_2," << StreamingMemory_26_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_3," << StreamingMemory_26_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_4," << StreamingMemory_26_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_5," << StreamingMemory_26_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_6," << StreamingMemory_26_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_7," << StreamingMemory_26_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out0_stream_8," << StreamingMemory_26_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_26_out1_stream_0," << StreamingMemory_26_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_4.run<56>(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream_prepad[10], StreamingLineBuffer_4_buffer_stream[3]);
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
    StreamingLineBuffer_4_pixel_6.run<58>(StreamingLineBuffer_4_buffer_stream[4], StreamingLineBuffer_4_out0_stream_prepad[8], StreamingLineBuffer_4_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_8," << StreamingLineBuffer_4_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_6," << StreamingLineBuffer_4_buffer_stream[6].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        867694,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_27;
    StreamingMemory_27.run<128>(StreamingMemory_26_out1_stream, StreamingMemory_27_out0_stream, StreamingMemory_27_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_27_out0_stream_0," << StreamingMemory_27_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_27_out1_stream_0," << StreamingMemory_27_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_5.run<57>(StreamingLineBuffer_4_buffer_stream[3], StreamingLineBuffer_4_out0_stream_prepad[9], StreamingLineBuffer_4_buffer_stream[5]);
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
    StreamingLineBuffer_4_pixel_8.run<60>(StreamingLineBuffer_4_buffer_stream[6], StreamingLineBuffer_4_out0_stream_prepad[6], StreamingLineBuffer_4_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_6," << StreamingLineBuffer_4_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_9," << StreamingLineBuffer_4_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        866158,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_28;
    StreamingMemory_28.run<130>(StreamingMemory_27_out1_stream, StreamingMemory_28_out0_stream, StreamingMemory_28_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_28_out0_stream_0," << StreamingMemory_28_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_28_out1_stream_0," << StreamingMemory_28_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_7.run<59>(StreamingLineBuffer_4_buffer_stream[5], StreamingLineBuffer_4_out0_stream_prepad[7], StreamingLineBuffer_4_buffer_stream[7]);
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
    StreamingLineBuffer_4_pixel_11.run<63>(StreamingLineBuffer_4_buffer_stream[9], StreamingLineBuffer_4_out0_stream_prepad[3], StreamingLineBuffer_4_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_3," << StreamingLineBuffer_4_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_11," << StreamingLineBuffer_4_buffer_stream[11].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        866142,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_29;
    StreamingMemory_29.run<135>(StreamingMemory_28_out1_stream, StreamingMemory_29_out0_stream, StreamingMemory_29_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_29_out0_stream_0," << StreamingMemory_29_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_29_out1_stream_0," << StreamingMemory_29_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_9.run<61>(StreamingLineBuffer_4_buffer_stream[7], StreamingLineBuffer_4_out0_stream_prepad[5], StreamingLineBuffer_4_buffer_stream[8]);
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
    StreamingLineBuffer_4_pixel_13.run<65>(StreamingLineBuffer_4_buffer_stream[11], StreamingLineBuffer_4_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_1," << StreamingLineBuffer_4_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        864606,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_30;
    StreamingMemory_30.run<137>(StreamingMemory_29_out1_stream, StreamingMemory_30_out0_stream, StreamingMemory_30_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_30_out0_stream_0," << StreamingMemory_30_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_30_out1_stream_0," << StreamingMemory_30_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_10.run<62>(StreamingLineBuffer_4_buffer_stream[8], StreamingLineBuffer_4_out0_stream_prepad[4], StreamingLineBuffer_4_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_4," << StreamingLineBuffer_4_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_10," << StreamingLineBuffer_4_buffer_stream[10].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        864510,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_31;
    StreamingMemory_31.run<139>(StreamingMemory_30_out1_stream, StreamingMemory_31_out0_stream, StreamingMemory_31_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_31_out0_stream_0," << StreamingMemory_31_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_31_out1_stream_0," << StreamingMemory_31_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_12.run<64>(StreamingLineBuffer_4_buffer_stream[10], StreamingLineBuffer_4_out0_stream_prepad[2], StreamingLineBuffer_4_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_2," << StreamingLineBuffer_4_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_12," << StreamingLineBuffer_4_buffer_stream[12].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        864078,  // DATA_TO_SHIFT
        392,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_32;
    StreamingMemory_32.run<156>(StreamingMemory_31_out1_stream, StreamingMemory_32_out0_stream, StreamingMemory_32_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_0," << StreamingMemory_32_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_1," << StreamingMemory_32_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_2," << StreamingMemory_32_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_3," << StreamingMemory_32_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_4," << StreamingMemory_32_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_5," << StreamingMemory_32_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_6," << StreamingMemory_32_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_7," << StreamingMemory_32_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out0_stream_8," << StreamingMemory_32_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_32_out1_stream_0," << StreamingMemory_32_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pixel_14.run<66>(StreamingLineBuffer_4_buffer_stream[12], StreamingLineBuffer_4_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_0," << StreamingLineBuffer_4_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        863982,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_33;
    StreamingMemory_33.run<158>(StreamingMemory_32_out1_stream, StreamingMemory_33_out0_stream, StreamingMemory_33_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_33_out0_stream_0," << StreamingMemory_33_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_33_out1_stream_0," << StreamingMemory_33_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_4_pad.run<67>(StreamingLineBuffer_4_out0_stream_prepad, StreamingLineBuffer_4_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        862446,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_34;
    StreamingMemory_34.run<160>(StreamingMemory_33_out1_stream, StreamingMemory_34_out0_stream, StreamingMemory_34_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_34_out0_stream_0," << StreamingMemory_34_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_34_out1_stream_0," << StreamingMemory_34_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_1.run<69>(StreamingLineBuffer_4_out0_stream, StreamingMemory_8_out0_stream, StreamingMemory_9_out0_stream, StreamingDepthwiseConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_0," << StreamingDepthwiseConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_1," << StreamingDepthwiseConv_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        862430,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_35;
    StreamingMemory_35.run<162>(StreamingMemory_34_out1_stream, StreamingMemory_35_out0_stream, StreamingMemory_35_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_35_out0_stream_0," << StreamingMemory_35_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_35_out1_stream_0," << StreamingMemory_35_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseStreams_0.run<71>(StreamingDepthwiseConv_1_out0_stream, BandwidthAdjustIncreaseStreams_0_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        860894,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_36;
    StreamingMemory_36.run<165>(StreamingMemory_35_out1_stream, StreamingMemory_36_out0_stream, StreamingMemory_36_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_36_out0_stream_0," << StreamingMemory_36_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_36_out1_stream_0," << StreamingMemory_36_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_5_pixel_0.run<73>(BandwidthAdjustIncreaseStreams_0_out0_stream[3], StreamingLineBuffer_5_out0_stream[3]);
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
    StreamingLineBuffer_5_pixel_1.run<74>(BandwidthAdjustIncreaseStreams_0_out0_stream[2], StreamingLineBuffer_5_out0_stream[2]);
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
    StreamingLineBuffer_5_pixel_2.run<75>(BandwidthAdjustIncreaseStreams_0_out0_stream[1], StreamingLineBuffer_5_out0_stream[1]);
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
    StreamingLineBuffer_5_pixel_3.run<76>(BandwidthAdjustIncreaseStreams_0_out0_stream[0], StreamingLineBuffer_5_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_0," << StreamingLineBuffer_5_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        860798,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_37;
    StreamingMemory_37.run<167>(StreamingMemory_36_out1_stream, StreamingMemory_37_out0_stream, StreamingMemory_37_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_37_out0_stream_0," << StreamingMemory_37_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_37_out1_stream_0," << StreamingMemory_37_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_3.run<78>(StreamingLineBuffer_5_out0_stream, StreamingMemory_10_out0_stream, StreamingMemory_11_out0_stream, StreamingConv_3_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        860366,  // DATA_TO_SHIFT
        98,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_38;
    StreamingMemory_38.run<169>(StreamingMemory_37_out1_stream, StreamingMemory_38_out0_stream, StreamingMemory_38_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_0," << StreamingMemory_38_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_1," << StreamingMemory_38_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_2," << StreamingMemory_38_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_3," << StreamingMemory_38_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_4," << StreamingMemory_38_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_5," << StreamingMemory_38_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_6," << StreamingMemory_38_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_7," << StreamingMemory_38_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out0_stream_8," << StreamingMemory_38_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_38_out1_stream_0," << StreamingMemory_38_out1_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        3,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<80>(StreamingConv_3_out0_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        860270,  // DATA_TO_SHIFT
        98,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_39;
    StreamingMemory_39.run<172>(StreamingMemory_38_out1_stream, StreamingMemory_39_out0_stream, StreamingMemory_39_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_39_out0_stream_0," << StreamingMemory_39_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_39_out1_stream_0," << StreamingMemory_39_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_0.run<82>(TensorDuplicator_0_out0_stream, BandwidthAdjustDecreaseChannels_0_out0_stream);
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
    BandwidthAdjustDecreaseChannels_1.run<83>(TensorDuplicator_0_out1_stream, BandwidthAdjustDecreaseChannels_1_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        857198,  // DATA_TO_SHIFT
        196,  // TIMES
        12288,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_40;
    StreamingMemory_40.run<175>(StreamingMemory_39_out1_stream, StreamingMemory_40_out0_stream, StreamingMemory_40_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_40_out0_stream_0," << StreamingMemory_40_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_40_out1_stream_0," << StreamingMemory_40_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_2.run<85>(BandwidthAdjustDecreaseChannels_0_out0_stream, BandwidthAdjustIncreaseChannels_2_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        857166,  // DATA_TO_SHIFT
        196,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_41;
    StreamingMemory_41.run<177>(StreamingMemory_40_out1_stream, StreamingMemory_41_out0_stream, StreamingMemory_41_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_41_out0_stream_0," << StreamingMemory_41_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_41_out1_stream_0," << StreamingMemory_41_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_6_pixel_0.run<87>(BandwidthAdjustIncreaseChannels_2_out0_stream[3], StreamingLineBuffer_6_out0_stream[3]);
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
    StreamingLineBuffer_6_pixel_1.run<88>(BandwidthAdjustIncreaseChannels_2_out0_stream[2], StreamingLineBuffer_6_out0_stream[2]);
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
    StreamingLineBuffer_6_pixel_2.run<89>(BandwidthAdjustIncreaseChannels_2_out0_stream[1], StreamingLineBuffer_6_out0_stream[1]);
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
    StreamingLineBuffer_6_pixel_3.run<90>(BandwidthAdjustIncreaseChannels_2_out0_stream[0], StreamingLineBuffer_6_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_0," << StreamingLineBuffer_6_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        851022,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_42;
    StreamingMemory_42.run<179>(StreamingMemory_41_out1_stream, StreamingMemory_42_out0_stream, StreamingMemory_42_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_42_out0_stream_0," << StreamingMemory_42_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_42_out1_stream_0," << StreamingMemory_42_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_4.run<92>(StreamingLineBuffer_6_out0_stream, StreamingMemory_12_out0_stream, StreamingMemory_13_out0_stream, StreamingConv_4_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        850830,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_43;
    StreamingMemory_43.run<193>(StreamingMemory_42_out1_stream, StreamingMemory_43_out0_stream, StreamingMemory_43_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_43_out0_stream_0," << StreamingMemory_43_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_43_out1_stream_0," << StreamingMemory_43_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_2.run<94>(StreamingConv_4_out0_stream, BandwidthAdjustDecreaseChannels_2_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        849966,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_44;
    StreamingMemory_44.run<195>(StreamingMemory_43_out1_stream, StreamingMemory_44_out0_stream, StreamingMemory_44_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_0," << StreamingMemory_44_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_1," << StreamingMemory_44_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_2," << StreamingMemory_44_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_3," << StreamingMemory_44_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_4," << StreamingMemory_44_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_5," << StreamingMemory_44_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_6," << StreamingMemory_44_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_7," << StreamingMemory_44_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out0_stream_8," << StreamingMemory_44_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_44_out1_stream_0," << StreamingMemory_44_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_0.run<96>(BandwidthAdjustDecreaseChannels_2_out0_stream[0], StreamingLineBuffer_7_out0_stream_prepad[17], StreamingLineBuffer_7_buffer_stream[0]);
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
    StreamingLineBuffer_7_pixel_1.run<97>(BandwidthAdjustDecreaseChannels_2_out0_stream[3], StreamingLineBuffer_7_out0_stream_prepad[16], StreamingLineBuffer_7_buffer_stream[1]);
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
    StreamingLineBuffer_7_pixel_2.run<98>(BandwidthAdjustDecreaseChannels_2_out0_stream[2], StreamingLineBuffer_7_out0_stream_prepad[15], StreamingLineBuffer_7_buffer_stream[4]);
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
    StreamingLineBuffer_7_pixel_3.run<99>(BandwidthAdjustDecreaseChannels_2_out0_stream[1], StreamingLineBuffer_7_out0_stream_prepad[14], StreamingLineBuffer_7_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_14," << StreamingLineBuffer_7_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_5," << StreamingLineBuffer_7_buffer_stream[5].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        849774,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_45;
    StreamingMemory_45.run<197>(StreamingMemory_44_out1_stream, StreamingMemory_45_out0_stream, StreamingMemory_45_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_45_out0_stream_0," << StreamingMemory_45_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_45_out1_stream_0," << StreamingMemory_45_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_4.run<100>(StreamingLineBuffer_7_buffer_stream[0], StreamingLineBuffer_7_out0_stream_prepad[13], StreamingLineBuffer_7_buffer_stream[2]);
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
    StreamingLineBuffer_7_pixel_5.run<101>(StreamingLineBuffer_7_buffer_stream[1], StreamingLineBuffer_7_out0_stream_prepad[12], StreamingLineBuffer_7_buffer_stream[3]);
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
    StreamingLineBuffer_7_pixel_8.run<104>(StreamingLineBuffer_7_buffer_stream[4], StreamingLineBuffer_7_out0_stream_prepad[9], StreamingLineBuffer_7_buffer_stream[10]);
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
    StreamingLineBuffer_7_pixel_9.run<105>(StreamingLineBuffer_7_buffer_stream[5], StreamingLineBuffer_7_out0_stream_prepad[8], StreamingLineBuffer_7_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_8," << StreamingLineBuffer_7_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_11," << StreamingLineBuffer_7_buffer_stream[11].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        843630,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_46;
    StreamingMemory_46.run<200>(StreamingMemory_45_out1_stream, StreamingMemory_46_out0_stream, StreamingMemory_46_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_46_out0_stream_0," << StreamingMemory_46_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_46_out1_stream_0," << StreamingMemory_46_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_6.run<102>(StreamingLineBuffer_7_buffer_stream[2], StreamingLineBuffer_7_out0_stream_prepad[11], StreamingLineBuffer_7_buffer_stream[6]);
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
    StreamingLineBuffer_7_pixel_7.run<103>(StreamingLineBuffer_7_buffer_stream[3], StreamingLineBuffer_7_out0_stream_prepad[10], StreamingLineBuffer_7_buffer_stream[7]);
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
    StreamingLineBuffer_7_pixel_14.run<110>(StreamingLineBuffer_7_buffer_stream[10], StreamingLineBuffer_7_out0_stream_prepad[3]);
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
    StreamingLineBuffer_7_pixel_15.run<111>(StreamingLineBuffer_7_buffer_stream[11], StreamingLineBuffer_7_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_2," << StreamingLineBuffer_7_out0_stream_prepad[2].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        843598,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_47;
    StreamingMemory_47.run<202>(StreamingMemory_46_out1_stream, StreamingMemory_47_out0_stream, StreamingMemory_47_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_47_out0_stream_0," << StreamingMemory_47_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_47_out1_stream_0," << StreamingMemory_47_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_10.run<106>(StreamingLineBuffer_7_buffer_stream[6], StreamingLineBuffer_7_out0_stream_prepad[7], StreamingLineBuffer_7_buffer_stream[8]);
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
    StreamingLineBuffer_7_pixel_11.run<107>(StreamingLineBuffer_7_buffer_stream[7], StreamingLineBuffer_7_out0_stream_prepad[6], StreamingLineBuffer_7_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_6," << StreamingLineBuffer_7_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_9," << StreamingLineBuffer_7_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        837454,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_48;
    StreamingMemory_48.run<204>(StreamingMemory_47_out1_stream, StreamingMemory_48_out0_stream, StreamingMemory_48_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_48_out0_stream_0," << StreamingMemory_48_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_48_out1_stream_0," << StreamingMemory_48_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_12.run<108>(StreamingLineBuffer_7_buffer_stream[8], StreamingLineBuffer_7_out0_stream_prepad[5], StreamingLineBuffer_7_buffer_stream[12]);
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
    StreamingLineBuffer_7_pixel_13.run<109>(StreamingLineBuffer_7_buffer_stream[9], StreamingLineBuffer_7_out0_stream_prepad[4], StreamingLineBuffer_7_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_4," << StreamingLineBuffer_7_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_13," << StreamingLineBuffer_7_buffer_stream[13].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        837262,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_49;
    StreamingMemory_49.run<206>(StreamingMemory_48_out1_stream, StreamingMemory_49_out0_stream, StreamingMemory_49_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_49_out0_stream_0," << StreamingMemory_49_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_49_out1_stream_0," << StreamingMemory_49_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pixel_16.run<112>(StreamingLineBuffer_7_buffer_stream[12], StreamingLineBuffer_7_out0_stream_prepad[1]);
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
    StreamingLineBuffer_7_pixel_17.run<113>(StreamingLineBuffer_7_buffer_stream[13], StreamingLineBuffer_7_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_0," << StreamingLineBuffer_7_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        836398,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_50;
    StreamingMemory_50.run<208>(StreamingMemory_49_out1_stream, StreamingMemory_50_out0_stream, StreamingMemory_50_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_0," << StreamingMemory_50_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_1," << StreamingMemory_50_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_2," << StreamingMemory_50_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_3," << StreamingMemory_50_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_4," << StreamingMemory_50_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_5," << StreamingMemory_50_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_6," << StreamingMemory_50_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_7," << StreamingMemory_50_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out0_stream_8," << StreamingMemory_50_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_50_out1_stream_0," << StreamingMemory_50_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_7_pad.run<114>(StreamingLineBuffer_7_out0_stream_prepad, StreamingLineBuffer_7_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        836206,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_51;
    StreamingMemory_51.run<211>(StreamingMemory_50_out1_stream, StreamingMemory_51_out0_stream, StreamingMemory_51_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_51_out0_stream_0," << StreamingMemory_51_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_51_out1_stream_0," << StreamingMemory_51_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_2.run<116>(StreamingLineBuffer_7_out0_stream, StreamingMemory_14_out0_stream, StreamingMemory_15_out0_stream, StreamingDepthwiseConv_2_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        830062,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_52;
    StreamingMemory_52.run<214>(StreamingMemory_51_out1_stream, StreamingMemory_52_out0_stream, StreamingMemory_52_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_52_out0_stream_0," << StreamingMemory_52_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_52_out1_stream_0," << StreamingMemory_52_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_3.run<118>(StreamingDepthwiseConv_2_out0_stream, BandwidthAdjustIncreaseChannels_3_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        830030,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_53;
    StreamingMemory_53.run<216>(StreamingMemory_52_out1_stream, StreamingMemory_53_out0_stream, StreamingMemory_53_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_53_out0_stream_0," << StreamingMemory_53_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_53_out1_stream_0," << StreamingMemory_53_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_8_pixel_0.run<120>(BandwidthAdjustIncreaseChannels_3_out0_stream[3], StreamingLineBuffer_8_out0_stream[3]);
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
    StreamingLineBuffer_8_pixel_1.run<121>(BandwidthAdjustIncreaseChannels_3_out0_stream[2], StreamingLineBuffer_8_out0_stream[2]);
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
    StreamingLineBuffer_8_pixel_2.run<122>(BandwidthAdjustIncreaseChannels_3_out0_stream[1], StreamingLineBuffer_8_out0_stream[1]);
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
    StreamingLineBuffer_8_pixel_3.run<123>(BandwidthAdjustIncreaseChannels_3_out0_stream[0], StreamingLineBuffer_8_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_0," << StreamingLineBuffer_8_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        823886,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_54;
    StreamingMemory_54.run<218>(StreamingMemory_53_out1_stream, StreamingMemory_54_out0_stream, StreamingMemory_54_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_54_out0_stream_0," << StreamingMemory_54_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_54_out1_stream_0," << StreamingMemory_54_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_5.run<125>(StreamingLineBuffer_8_out0_stream, StreamingMemory_16_out0_stream, StreamingMemory_17_out0_stream, StreamingConv_5_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        823694,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_55;
    StreamingMemory_55.run<232>(StreamingMemory_54_out1_stream, StreamingMemory_55_out0_stream, StreamingMemory_55_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_55_out0_stream_0," << StreamingMemory_55_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_55_out1_stream_0," << StreamingMemory_55_out1_stream[0].size() << std::endl;
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
    StreamingAdd_0.run<127>(BandwidthAdjustDecreaseChannels_1_out0_stream, StreamingConv_5_out0_stream, StreamingAdd_0_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        822830,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_56;
    StreamingMemory_56.run<234>(StreamingMemory_55_out1_stream, StreamingMemory_56_out0_stream, StreamingMemory_56_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_0," << StreamingMemory_56_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_1," << StreamingMemory_56_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_2," << StreamingMemory_56_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_3," << StreamingMemory_56_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_4," << StreamingMemory_56_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_5," << StreamingMemory_56_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_6," << StreamingMemory_56_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_7," << StreamingMemory_56_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out0_stream_8," << StreamingMemory_56_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_56_out1_stream_0," << StreamingMemory_56_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_4.run<129>(StreamingAdd_0_out0_stream, BandwidthAdjustIncreaseChannels_4_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        822638,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_57;
    StreamingMemory_57.run<236>(StreamingMemory_56_out1_stream, StreamingMemory_57_out0_stream, StreamingMemory_57_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_57_out0_stream_0," << StreamingMemory_57_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_57_out1_stream_0," << StreamingMemory_57_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_9_pixel_0.run<131>(BandwidthAdjustIncreaseChannels_4_out0_stream[3], StreamingLineBuffer_9_out0_stream[3]);
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
    StreamingLineBuffer_9_pixel_1.run<132>(BandwidthAdjustIncreaseChannels_4_out0_stream[2], StreamingLineBuffer_9_out0_stream[2]);
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
    StreamingLineBuffer_9_pixel_2.run<133>(BandwidthAdjustIncreaseChannels_4_out0_stream[1], StreamingLineBuffer_9_out0_stream[1]);
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
    StreamingLineBuffer_9_pixel_3.run<134>(BandwidthAdjustIncreaseChannels_4_out0_stream[0], StreamingLineBuffer_9_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_0," << StreamingLineBuffer_9_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        816494,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_58;
    StreamingMemory_58.run<239>(StreamingMemory_57_out1_stream, StreamingMemory_58_out0_stream, StreamingMemory_58_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_58_out0_stream_0," << StreamingMemory_58_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_58_out1_stream_0," << StreamingMemory_58_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_6.run<136>(StreamingLineBuffer_9_out0_stream, StreamingMemory_18_out0_stream, StreamingMemory_19_out0_stream, StreamingConv_6_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        816462,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_59;
    StreamingMemory_59.run<241>(StreamingMemory_58_out1_stream, StreamingMemory_59_out0_stream, StreamingMemory_59_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_59_out0_stream_0," << StreamingMemory_59_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_59_out1_stream_0," << StreamingMemory_59_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseStreams_0.run<138>(StreamingConv_6_out0_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_0," << BandwidthAdjustDecreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_1," << BandwidthAdjustDecreaseStreams_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        810318,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_60;
    StreamingMemory_60.run<243>(StreamingMemory_59_out1_stream, StreamingMemory_60_out0_stream, StreamingMemory_60_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_60_out0_stream_0," << StreamingMemory_60_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_60_out1_stream_0," << StreamingMemory_60_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_0.run<140>(BandwidthAdjustDecreaseStreams_0_out0_stream[1], StreamingLineBuffer_10_out0_stream_prepad[14], StreamingLineBuffer_10_buffer_stream[0]);
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
    StreamingLineBuffer_10_pixel_1.run<141>(BandwidthAdjustDecreaseStreams_0_out0_stream[0], StreamingLineBuffer_10_out0_stream_prepad[13], StreamingLineBuffer_10_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_13," << StreamingLineBuffer_10_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_1," << StreamingLineBuffer_10_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        810126,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_61;
    StreamingMemory_61.run<246>(StreamingMemory_60_out1_stream, StreamingMemory_61_out0_stream, StreamingMemory_61_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_61_out0_stream_0," << StreamingMemory_61_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_61_out1_stream_0," << StreamingMemory_61_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_2.run<142>(StreamingLineBuffer_10_buffer_stream[0], StreamingLineBuffer_10_out0_stream_prepad[12], StreamingLineBuffer_10_buffer_stream[2]);
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
    StreamingLineBuffer_10_pixel_3.run<143>(StreamingLineBuffer_10_buffer_stream[1], StreamingLineBuffer_10_out0_stream_prepad[11], StreamingLineBuffer_10_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_11," << StreamingLineBuffer_10_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_4," << StreamingLineBuffer_10_buffer_stream[4].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        809262,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_62;
    StreamingMemory_62.run<248>(StreamingMemory_61_out1_stream, StreamingMemory_62_out0_stream, StreamingMemory_62_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_0," << StreamingMemory_62_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_1," << StreamingMemory_62_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_2," << StreamingMemory_62_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_3," << StreamingMemory_62_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_4," << StreamingMemory_62_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_5," << StreamingMemory_62_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_6," << StreamingMemory_62_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_7," << StreamingMemory_62_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out0_stream_8," << StreamingMemory_62_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_62_out1_stream_0," << StreamingMemory_62_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_4.run<144>(StreamingLineBuffer_10_buffer_stream[2], StreamingLineBuffer_10_out0_stream_prepad[10], StreamingLineBuffer_10_buffer_stream[3]);
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
    StreamingLineBuffer_10_pixel_6.run<146>(StreamingLineBuffer_10_buffer_stream[4], StreamingLineBuffer_10_out0_stream_prepad[8], StreamingLineBuffer_10_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_8," << StreamingLineBuffer_10_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_6," << StreamingLineBuffer_10_buffer_stream[6].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        809070,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_63;
    StreamingMemory_63.run<250>(StreamingMemory_62_out1_stream, StreamingMemory_63_out0_stream, StreamingMemory_63_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_63_out0_stream_0," << StreamingMemory_63_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_63_out1_stream_0," << StreamingMemory_63_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_5.run<145>(StreamingLineBuffer_10_buffer_stream[3], StreamingLineBuffer_10_out0_stream_prepad[9], StreamingLineBuffer_10_buffer_stream[5]);
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
    StreamingLineBuffer_10_pixel_8.run<148>(StreamingLineBuffer_10_buffer_stream[6], StreamingLineBuffer_10_out0_stream_prepad[6], StreamingLineBuffer_10_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_6," << StreamingLineBuffer_10_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_9," << StreamingLineBuffer_10_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 18>,  // TOutputStruct
        4,  // DATA_PER_WORD
        799854,  // DATA_TO_SHIFT
        98,  // TIMES
        36864,  // WORDS
        1,  // ARRAY_PAR
        18  // WORD_PAR
    > StreamingMemory_64;
    StreamingMemory_64.run<267>(StreamingMemory_63_out1_stream, StreamingMemory_64_out0_stream, StreamingMemory_64_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_64_out0_stream_0," << StreamingMemory_64_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_64_out1_stream_0," << StreamingMemory_64_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_7.run<147>(StreamingLineBuffer_10_buffer_stream[5], StreamingLineBuffer_10_out0_stream_prepad[7], StreamingLineBuffer_10_buffer_stream[7]);
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
    StreamingLineBuffer_10_pixel_11.run<151>(StreamingLineBuffer_10_buffer_stream[9], StreamingLineBuffer_10_out0_stream_prepad[3], StreamingLineBuffer_10_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_3," << StreamingLineBuffer_10_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_11," << StreamingLineBuffer_10_buffer_stream[11].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        799806,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_65;
    StreamingMemory_65.run<269>(StreamingMemory_64_out1_stream, StreamingMemory_65_out0_stream, StreamingMemory_65_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_65_out0_stream_0," << StreamingMemory_65_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_65_out1_stream_0," << StreamingMemory_65_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_9.run<149>(StreamingLineBuffer_10_buffer_stream[7], StreamingLineBuffer_10_out0_stream_prepad[5], StreamingLineBuffer_10_buffer_stream[8]);
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
    StreamingLineBuffer_10_pixel_13.run<153>(StreamingLineBuffer_10_buffer_stream[11], StreamingLineBuffer_10_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_1," << StreamingLineBuffer_10_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 36>,  // TOutputStruct
        4,  // DATA_PER_WORD
        785982,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        36  // WORD_PAR
    > StreamingMemory_66;
    StreamingMemory_66.run<271>(StreamingMemory_65_out1_stream, StreamingMemory_66_out0_stream, StreamingMemory_66_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_66_out0_stream_0," << StreamingMemory_66_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_66_out1_stream_0," << StreamingMemory_66_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_10.run<150>(StreamingLineBuffer_10_buffer_stream[8], StreamingLineBuffer_10_out0_stream_prepad[4], StreamingLineBuffer_10_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_4," << StreamingLineBuffer_10_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_10," << StreamingLineBuffer_10_buffer_stream[10].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        785694,  // DATA_TO_SHIFT
        98,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_67;
    StreamingMemory_67.run<273>(StreamingMemory_66_out1_stream, StreamingMemory_67_out0_stream, StreamingMemory_67_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_67_out0_stream_0," << StreamingMemory_67_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_67_out1_stream_0," << StreamingMemory_67_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_12.run<152>(StreamingLineBuffer_10_buffer_stream[10], StreamingLineBuffer_10_out0_stream_prepad[2], StreamingLineBuffer_10_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_2," << StreamingLineBuffer_10_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_12," << StreamingLineBuffer_10_buffer_stream[12].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        784398,  // DATA_TO_SHIFT
        98,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_68;
    StreamingMemory_68.run<275>(StreamingMemory_67_out1_stream, StreamingMemory_68_out0_stream, StreamingMemory_68_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_0," << StreamingMemory_68_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_1," << StreamingMemory_68_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_2," << StreamingMemory_68_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_3," << StreamingMemory_68_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_4," << StreamingMemory_68_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_5," << StreamingMemory_68_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_6," << StreamingMemory_68_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_7," << StreamingMemory_68_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out0_stream_8," << StreamingMemory_68_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_68_out1_stream_0," << StreamingMemory_68_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pixel_14.run<154>(StreamingLineBuffer_10_buffer_stream[12], StreamingLineBuffer_10_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_0," << StreamingLineBuffer_10_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        784110,  // DATA_TO_SHIFT
        98,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_69;
    StreamingMemory_69.run<277>(StreamingMemory_68_out1_stream, StreamingMemory_69_out0_stream, StreamingMemory_69_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_69_out0_stream_0," << StreamingMemory_69_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_69_out1_stream_0," << StreamingMemory_69_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_10_pad.run<155>(StreamingLineBuffer_10_out0_stream_prepad, StreamingLineBuffer_10_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 27>,  // TOutputStruct
        4,  // DATA_PER_WORD
        770286,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        27  // WORD_PAR
    > StreamingMemory_70;
    StreamingMemory_70.run<280>(StreamingMemory_69_out1_stream, StreamingMemory_70_out0_stream, StreamingMemory_70_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_70_out0_stream_0," << StreamingMemory_70_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_70_out1_stream_0," << StreamingMemory_70_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_3.run<157>(StreamingLineBuffer_10_out0_stream, StreamingMemory_20_out0_stream, StreamingMemory_21_out0_stream, StreamingDepthwiseConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_0," << StreamingDepthwiseConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_1," << StreamingDepthwiseConv_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        770238,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_71;
    StreamingMemory_71.run<283>(StreamingMemory_70_out1_stream, StreamingMemory_71_out0_stream, StreamingMemory_71_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_71_out0_stream_0," << StreamingMemory_71_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_71_out1_stream_0," << StreamingMemory_71_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_3.run<159>(StreamingDepthwiseConv_3_out0_stream, BandwidthAdjustDecreaseChannels_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_0," << BandwidthAdjustDecreaseChannels_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_1," << BandwidthAdjustDecreaseChannels_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 36>,  // TOutputStruct
        4,  // DATA_PER_WORD
        756414,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        36  // WORD_PAR
    > StreamingMemory_72;
    StreamingMemory_72.run<285>(StreamingMemory_71_out1_stream, StreamingMemory_72_out0_stream, StreamingMemory_72_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_72_out0_stream_0," << StreamingMemory_72_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_72_out1_stream_0," << StreamingMemory_72_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_5.run<161>(BandwidthAdjustDecreaseChannels_3_out0_stream, BandwidthAdjustIncreaseChannels_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_5_out0_stream_0," << BandwidthAdjustIncreaseChannels_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_5_out0_stream_1," << BandwidthAdjustIncreaseChannels_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        756126,  // DATA_TO_SHIFT
        98,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_73;
    StreamingMemory_73.run<287>(StreamingMemory_72_out1_stream, StreamingMemory_73_out0_stream, StreamingMemory_73_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_73_out0_stream_0," << StreamingMemory_73_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_73_out1_stream_0," << StreamingMemory_73_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_11_pixel_0.run<163>(BandwidthAdjustIncreaseChannels_5_out0_stream[1], StreamingLineBuffer_11_out0_stream[1]);
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
    StreamingLineBuffer_11_pixel_1.run<164>(BandwidthAdjustIncreaseChannels_5_out0_stream[0], StreamingLineBuffer_11_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_0," << StreamingLineBuffer_11_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        754830,  // DATA_TO_SHIFT
        98,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_74;
    StreamingMemory_74.run<301>(StreamingMemory_73_out1_stream, StreamingMemory_74_out0_stream, StreamingMemory_74_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_0," << StreamingMemory_74_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_1," << StreamingMemory_74_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_2," << StreamingMemory_74_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_3," << StreamingMemory_74_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_4," << StreamingMemory_74_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_5," << StreamingMemory_74_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_6," << StreamingMemory_74_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_7," << StreamingMemory_74_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out0_stream_8," << StreamingMemory_74_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_74_out1_stream_0," << StreamingMemory_74_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_7.run<166>(StreamingLineBuffer_11_out0_stream, StreamingMemory_22_out0_stream, StreamingMemory_23_out0_stream, StreamingConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_0," << StreamingConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_1," << StreamingConv_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        754542,  // DATA_TO_SHIFT
        98,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_75;
    StreamingMemory_75.run<303>(StreamingMemory_74_out1_stream, StreamingMemory_75_out0_stream, StreamingMemory_75_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_75_out0_stream_0," << StreamingMemory_75_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_75_out1_stream_0," << StreamingMemory_75_out1_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<168>(StreamingConv_7_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 27>,  // TOutputStruct
        4,  // DATA_PER_WORD
        740718,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        27  // WORD_PAR
    > StreamingMemory_76;
    StreamingMemory_76.run<305>(StreamingMemory_75_out1_stream, StreamingMemory_76_out0_stream, StreamingMemory_76_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_76_out0_stream_0," << StreamingMemory_76_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_76_out1_stream_0," << StreamingMemory_76_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_6.run<170>(TensorDuplicator_1_out0_stream, BandwidthAdjustIncreaseChannels_6_out0_stream);
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
    BandwidthAdjustIncreaseChannels_7.run<171>(TensorDuplicator_1_out1_stream, BandwidthAdjustIncreaseChannels_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_7_out0_stream_0," << BandwidthAdjustIncreaseChannels_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_7_out0_stream_1," << BandwidthAdjustIncreaseChannels_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        740670,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_77;
    StreamingMemory_77.run<308>(StreamingMemory_76_out1_stream, StreamingMemory_77_out0_stream, StreamingMemory_77_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_77_out0_stream_0," << StreamingMemory_77_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_77_out1_stream_0," << StreamingMemory_77_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_12_pixel_0.run<173>(BandwidthAdjustIncreaseChannels_6_out0_stream[1], StreamingLineBuffer_12_out0_stream[1]);
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
    StreamingLineBuffer_12_pixel_1.run<174>(BandwidthAdjustIncreaseChannels_6_out0_stream[0], StreamingLineBuffer_12_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_0," << StreamingLineBuffer_12_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 36>,  // TOutputStruct
        4,  // DATA_PER_WORD
        726846,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        36  // WORD_PAR
    > StreamingMemory_78;
    StreamingMemory_78.run<310>(StreamingMemory_77_out1_stream, StreamingMemory_78_out0_stream, StreamingMemory_78_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_78_out0_stream_0," << StreamingMemory_78_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_78_out1_stream_0," << StreamingMemory_78_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_8.run<176>(StreamingLineBuffer_12_out0_stream, StreamingMemory_24_out0_stream, StreamingMemory_25_out0_stream, StreamingConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_0," << StreamingConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_1," << StreamingConv_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        726558,  // DATA_TO_SHIFT
        98,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_79;
    StreamingMemory_79.run<312>(StreamingMemory_78_out1_stream, StreamingMemory_79_out0_stream, StreamingMemory_79_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_79_out0_stream_0," << StreamingMemory_79_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_79_out1_stream_0," << StreamingMemory_79_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_4.run<178>(StreamingConv_8_out0_stream, BandwidthAdjustDecreaseChannels_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_0," << BandwidthAdjustDecreaseChannels_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_1," << BandwidthAdjustDecreaseChannels_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        725262,  // DATA_TO_SHIFT
        49,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_80;
    StreamingMemory_80.run<314>(StreamingMemory_79_out1_stream, StreamingMemory_80_out0_stream, StreamingMemory_80_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_0," << StreamingMemory_80_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_1," << StreamingMemory_80_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_2," << StreamingMemory_80_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_3," << StreamingMemory_80_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_4," << StreamingMemory_80_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_5," << StreamingMemory_80_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_6," << StreamingMemory_80_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_7," << StreamingMemory_80_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out0_stream_8," << StreamingMemory_80_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_80_out1_stream_0," << StreamingMemory_80_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_0.run<180>(BandwidthAdjustDecreaseChannels_4_out0_stream[0], StreamingLineBuffer_13_out0_stream_prepad[11], StreamingLineBuffer_13_buffer_stream[0]);
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
    StreamingLineBuffer_13_pixel_1.run<181>(BandwidthAdjustDecreaseChannels_4_out0_stream[1], StreamingLineBuffer_13_out0_stream_prepad[10], StreamingLineBuffer_13_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_10," << StreamingLineBuffer_13_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_1," << StreamingLineBuffer_13_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        724974,  // DATA_TO_SHIFT
        49,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_81;
    StreamingMemory_81.run<316>(StreamingMemory_80_out1_stream, StreamingMemory_81_out0_stream, StreamingMemory_81_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_81_out0_stream_0," << StreamingMemory_81_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_81_out1_stream_0," << StreamingMemory_81_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_2.run<182>(StreamingLineBuffer_13_buffer_stream[0], StreamingLineBuffer_13_out0_stream_prepad[9], StreamingLineBuffer_13_buffer_stream[2]);
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
    StreamingLineBuffer_13_pixel_3.run<183>(StreamingLineBuffer_13_buffer_stream[1], StreamingLineBuffer_13_out0_stream_prepad[8], StreamingLineBuffer_13_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_8," << StreamingLineBuffer_13_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_3," << StreamingLineBuffer_13_buffer_stream[3].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 36>,  // TOutputStruct
        4,  // DATA_PER_WORD
        701934,  // DATA_TO_SHIFT
        49,  // TIMES
        92160,  // WORDS
        1,  // ARRAY_PAR
        36  // WORD_PAR
    > StreamingMemory_82;
    StreamingMemory_82.run<319>(StreamingMemory_81_out1_stream, StreamingMemory_82_out0_stream, StreamingMemory_82_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_82_out0_stream_0," << StreamingMemory_82_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_82_out1_stream_0," << StreamingMemory_82_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_4.run<184>(StreamingLineBuffer_13_buffer_stream[2], StreamingLineBuffer_13_out0_stream_prepad[7], StreamingLineBuffer_13_buffer_stream[4]);
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
    StreamingLineBuffer_13_pixel_5.run<185>(StreamingLineBuffer_13_buffer_stream[3], StreamingLineBuffer_13_out0_stream_prepad[6], StreamingLineBuffer_13_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_6," << StreamingLineBuffer_13_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_5," << StreamingLineBuffer_13_buffer_stream[5].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        701854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_83;
    StreamingMemory_83.run<322>(StreamingMemory_82_out1_stream, StreamingMemory_83_out0_stream, StreamingMemory_83_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_83_out0_stream_0," << StreamingMemory_83_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_83_out1_stream_0," << StreamingMemory_83_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_6.run<186>(StreamingLineBuffer_13_buffer_stream[4], StreamingLineBuffer_13_out0_stream_prepad[5], StreamingLineBuffer_13_buffer_stream[6]);
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
    StreamingLineBuffer_13_pixel_7.run<187>(StreamingLineBuffer_13_buffer_stream[5], StreamingLineBuffer_13_out0_stream_prepad[4], StreamingLineBuffer_13_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_4," << StreamingLineBuffer_13_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_7," << StreamingLineBuffer_13_buffer_stream[7].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        663454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_84;
    StreamingMemory_84.run<324>(StreamingMemory_83_out1_stream, StreamingMemory_84_out0_stream, StreamingMemory_84_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_84_out0_stream_0," << StreamingMemory_84_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_84_out1_stream_0," << StreamingMemory_84_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_8.run<188>(StreamingLineBuffer_13_buffer_stream[6], StreamingLineBuffer_13_out0_stream_prepad[3], StreamingLineBuffer_13_buffer_stream[8]);
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
    StreamingLineBuffer_13_pixel_9.run<189>(StreamingLineBuffer_13_buffer_stream[7], StreamingLineBuffer_13_out0_stream_prepad[2], StreamingLineBuffer_13_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_2," << StreamingLineBuffer_13_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_9," << StreamingLineBuffer_13_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        662974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_85;
    StreamingMemory_85.run<326>(StreamingMemory_84_out1_stream, StreamingMemory_85_out0_stream, StreamingMemory_85_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_85_out0_stream_0," << StreamingMemory_85_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_85_out1_stream_0," << StreamingMemory_85_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pixel_10.run<190>(StreamingLineBuffer_13_buffer_stream[8], StreamingLineBuffer_13_out0_stream_prepad[1]);
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
    StreamingLineBuffer_13_pixel_11.run<191>(StreamingLineBuffer_13_buffer_stream[9], StreamingLineBuffer_13_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_0," << StreamingLineBuffer_13_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        660814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_86;
    StreamingMemory_86.run<340>(StreamingMemory_85_out1_stream, StreamingMemory_86_out0_stream, StreamingMemory_86_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_0," << StreamingMemory_86_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_1," << StreamingMemory_86_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_2," << StreamingMemory_86_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_3," << StreamingMemory_86_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_4," << StreamingMemory_86_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_5," << StreamingMemory_86_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_6," << StreamingMemory_86_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_7," << StreamingMemory_86_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out0_stream_8," << StreamingMemory_86_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_86_out1_stream_0," << StreamingMemory_86_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_13_pad.run<192>(StreamingLineBuffer_13_out0_stream_prepad, StreamingLineBuffer_13_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        660334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_87;
    StreamingMemory_87.run<342>(StreamingMemory_86_out1_stream, StreamingMemory_87_out0_stream, StreamingMemory_87_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_87_out0_stream_0," << StreamingMemory_87_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_87_out1_stream_0," << StreamingMemory_87_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_4.run<194>(StreamingLineBuffer_13_out0_stream, StreamingMemory_26_out0_stream, StreamingMemory_27_out0_stream, StreamingDepthwiseConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_0," << StreamingDepthwiseConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_1," << StreamingDepthwiseConv_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        621934,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_88;
    StreamingMemory_88.run<344>(StreamingMemory_87_out1_stream, StreamingMemory_88_out0_stream, StreamingMemory_88_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_88_out0_stream_0," << StreamingMemory_88_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_88_out1_stream_0," << StreamingMemory_88_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_8.run<196>(StreamingDepthwiseConv_4_out0_stream, BandwidthAdjustIncreaseChannels_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_8_out0_stream_0," << BandwidthAdjustIncreaseChannels_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_8_out0_stream_1," << BandwidthAdjustIncreaseChannels_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        621854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_89;
    StreamingMemory_89.run<347>(StreamingMemory_88_out1_stream, StreamingMemory_89_out0_stream, StreamingMemory_89_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_89_out0_stream_0," << StreamingMemory_89_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_89_out1_stream_0," << StreamingMemory_89_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_14_pixel_0.run<198>(BandwidthAdjustIncreaseChannels_8_out0_stream[1], StreamingLineBuffer_14_out0_stream[1]);
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
    StreamingLineBuffer_14_pixel_1.run<199>(BandwidthAdjustIncreaseChannels_8_out0_stream[0], StreamingLineBuffer_14_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_0," << StreamingLineBuffer_14_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        583454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_90;
    StreamingMemory_90.run<349>(StreamingMemory_89_out1_stream, StreamingMemory_90_out0_stream, StreamingMemory_90_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_90_out0_stream_0," << StreamingMemory_90_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_90_out1_stream_0," << StreamingMemory_90_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_9.run<201>(StreamingLineBuffer_14_out0_stream, StreamingMemory_28_out0_stream, StreamingMemory_29_out0_stream, StreamingConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_0," << StreamingConv_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_1," << StreamingConv_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<13>,  // TOutput
        std::array<ap_int<13>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        582974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_91;
    StreamingMemory_91.run<351>(StreamingMemory_90_out1_stream, StreamingMemory_91_out0_stream, StreamingMemory_91_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_91_out0_stream_0," << StreamingMemory_91_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_91_out1_stream_0," << StreamingMemory_91_out1_stream[0].size() << std::endl;
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
    StreamingAdd_1.run<203>(BandwidthAdjustIncreaseChannels_7_out0_stream, StreamingConv_9_out0_stream, StreamingAdd_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_0," << StreamingAdd_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_1," << StreamingAdd_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        580814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_92;
    StreamingMemory_92.run<353>(StreamingMemory_91_out1_stream, StreamingMemory_92_out0_stream, StreamingMemory_92_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_0," << StreamingMemory_92_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_1," << StreamingMemory_92_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_2," << StreamingMemory_92_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_3," << StreamingMemory_92_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_4," << StreamingMemory_92_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_5," << StreamingMemory_92_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_6," << StreamingMemory_92_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_7," << StreamingMemory_92_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out0_stream_8," << StreamingMemory_92_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_92_out1_stream_0," << StreamingMemory_92_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_5.run<205>(StreamingAdd_1_out0_stream, BandwidthAdjustDecreaseChannels_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_0," << BandwidthAdjustDecreaseChannels_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_1," << BandwidthAdjustDecreaseChannels_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        580334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_93;
    StreamingMemory_93.run<355>(StreamingMemory_92_out1_stream, StreamingMemory_93_out0_stream, StreamingMemory_93_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_93_out0_stream_0," << StreamingMemory_93_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_93_out1_stream_0," << StreamingMemory_93_out1_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<207>(BandwidthAdjustDecreaseChannels_5_out0_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        541934,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_94;
    StreamingMemory_94.run<358>(StreamingMemory_93_out1_stream, StreamingMemory_94_out0_stream, StreamingMemory_94_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_94_out0_stream_0," << StreamingMemory_94_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_94_out1_stream_0," << StreamingMemory_94_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustIncreaseChannels_9.run<209>(TensorDuplicator_2_out0_stream, BandwidthAdjustIncreaseChannels_9_out0_stream);
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
    BandwidthAdjustIncreaseChannels_10.run<210>(TensorDuplicator_2_out1_stream, BandwidthAdjustIncreaseChannels_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_10_out0_stream_0," << BandwidthAdjustIncreaseChannels_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_10_out0_stream_1," << BandwidthAdjustIncreaseChannels_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        541854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_95;
    StreamingMemory_95.run<361>(StreamingMemory_94_out1_stream, StreamingMemory_95_out0_stream, StreamingMemory_95_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_95_out0_stream_0," << StreamingMemory_95_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_95_out1_stream_0," << StreamingMemory_95_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_15_pixel_0.run<212>(BandwidthAdjustIncreaseChannels_9_out0_stream[1], StreamingLineBuffer_15_out0_stream[1]);
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
    StreamingLineBuffer_15_pixel_1.run<213>(BandwidthAdjustIncreaseChannels_9_out0_stream[0], StreamingLineBuffer_15_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_0," << StreamingLineBuffer_15_out0_stream[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        503454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_96;
    StreamingMemory_96.run<363>(StreamingMemory_95_out1_stream, StreamingMemory_96_out0_stream, StreamingMemory_96_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_96_out0_stream_0," << StreamingMemory_96_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_96_out1_stream_0," << StreamingMemory_96_out1_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_10.run<215>(StreamingLineBuffer_15_out0_stream, StreamingMemory_30_out0_stream, StreamingMemory_31_out0_stream, StreamingConv_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_0," << StreamingConv_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_1," << StreamingConv_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        502974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_97;
    StreamingMemory_97.run<365>(StreamingMemory_96_out1_stream, StreamingMemory_97_out0_stream, StreamingMemory_97_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_97_out0_stream_0," << StreamingMemory_97_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_97_out1_stream_0," << StreamingMemory_97_out1_stream[0].size() << std::endl;
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
    BandwidthAdjustDecreaseChannels_6.run<217>(StreamingConv_10_out0_stream, BandwidthAdjustDecreaseChannels_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_0," << BandwidthAdjustDecreaseChannels_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_1," << BandwidthAdjustDecreaseChannels_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        500814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_98;
    StreamingMemory_98.run<379>(StreamingMemory_97_out1_stream, StreamingMemory_98_out0_stream, StreamingMemory_98_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_0," << StreamingMemory_98_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_1," << StreamingMemory_98_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_2," << StreamingMemory_98_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_3," << StreamingMemory_98_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_4," << StreamingMemory_98_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_5," << StreamingMemory_98_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_6," << StreamingMemory_98_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_7," << StreamingMemory_98_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out0_stream_8," << StreamingMemory_98_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_98_out1_stream_0," << StreamingMemory_98_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_0.run<219>(BandwidthAdjustDecreaseChannels_6_out0_stream[0], StreamingLineBuffer_16_out0_stream_prepad[11], StreamingLineBuffer_16_buffer_stream[0]);
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
    StreamingLineBuffer_16_pixel_1.run<220>(BandwidthAdjustDecreaseChannels_6_out0_stream[1], StreamingLineBuffer_16_out0_stream_prepad[10], StreamingLineBuffer_16_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_10," << StreamingLineBuffer_16_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_1," << StreamingLineBuffer_16_buffer_stream[1].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        500334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_99;
    StreamingMemory_99.run<381>(StreamingMemory_98_out1_stream, StreamingMemory_99_out0_stream, StreamingMemory_99_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_99_out0_stream_0," << StreamingMemory_99_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_99_out1_stream_0," << StreamingMemory_99_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_2.run<221>(StreamingLineBuffer_16_buffer_stream[0], StreamingLineBuffer_16_out0_stream_prepad[9], StreamingLineBuffer_16_buffer_stream[2]);
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
    StreamingLineBuffer_16_pixel_3.run<222>(StreamingLineBuffer_16_buffer_stream[1], StreamingLineBuffer_16_out0_stream_prepad[8], StreamingLineBuffer_16_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_8," << StreamingLineBuffer_16_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_3," << StreamingLineBuffer_16_buffer_stream[3].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 120>,  // TOutputStruct
        4,  // DATA_PER_WORD
        423534,  // DATA_TO_SHIFT
        49,  // TIMES
        307200,  // WORDS
        1,  // ARRAY_PAR
        120  // WORD_PAR
    > StreamingMemory_100;
    StreamingMemory_100.run<383>(StreamingMemory_99_out1_stream, StreamingMemory_100_out0_stream, StreamingMemory_100_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_100_out0_stream_0," << StreamingMemory_100_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_100_out1_stream_0," << StreamingMemory_100_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_4.run<223>(StreamingLineBuffer_16_buffer_stream[2], StreamingLineBuffer_16_out0_stream_prepad[7], StreamingLineBuffer_16_buffer_stream[4]);
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
    StreamingLineBuffer_16_pixel_5.run<224>(StreamingLineBuffer_16_buffer_stream[3], StreamingLineBuffer_16_out0_stream_prepad[6], StreamingLineBuffer_16_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_6," << StreamingLineBuffer_16_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_5," << StreamingLineBuffer_16_buffer_stream[5].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        423374,  // DATA_TO_SHIFT
        49,  // TIMES
        320,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_101;
    StreamingMemory_101.run<386>(StreamingMemory_100_out1_stream, StreamingMemory_101_out0_stream, StreamingMemory_101_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_101_out0_stream_0," << StreamingMemory_101_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_101_out1_stream_0," << StreamingMemory_101_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_6.run<225>(StreamingLineBuffer_16_buffer_stream[4], StreamingLineBuffer_16_out0_stream_prepad[5], StreamingLineBuffer_16_buffer_stream[6]);
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
    StreamingLineBuffer_16_pixel_7.run<226>(StreamingLineBuffer_16_buffer_stream[5], StreamingLineBuffer_16_out0_stream_prepad[4], StreamingLineBuffer_16_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_4," << StreamingLineBuffer_16_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_7," << StreamingLineBuffer_16_buffer_stream[7].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 160>,  // TOutputStruct
        4,  // DATA_PER_WORD
        320974,  // DATA_TO_SHIFT
        49,  // TIMES
        409600,  // WORDS
        1,  // ARRAY_PAR
        160  // WORD_PAR
    > StreamingMemory_102;
    StreamingMemory_102.run<388>(StreamingMemory_101_out1_stream, StreamingMemory_102_out0_stream, StreamingMemory_102_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_102_out0_stream_0," << StreamingMemory_102_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_102_out1_stream_0," << StreamingMemory_102_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_8.run<227>(StreamingLineBuffer_16_buffer_stream[6], StreamingLineBuffer_16_out0_stream_prepad[3], StreamingLineBuffer_16_buffer_stream[8]);
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
    StreamingLineBuffer_16_pixel_9.run<228>(StreamingLineBuffer_16_buffer_stream[7], StreamingLineBuffer_16_out0_stream_prepad[2], StreamingLineBuffer_16_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_2," << StreamingLineBuffer_16_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_9," << StreamingLineBuffer_16_buffer_stream[9].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<12>,  // TOutput
        std::array<ap_int<12>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        320334,  // DATA_TO_SHIFT
        49,  // TIMES
        1280,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_103;
    StreamingMemory_103.run<390>(StreamingMemory_102_out1_stream, StreamingMemory_103_out0_stream, StreamingMemory_103_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_103_out0_stream_0," << StreamingMemory_103_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_103_out1_stream_0," << StreamingMemory_103_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pixel_10.run<229>(StreamingLineBuffer_16_buffer_stream[8], StreamingLineBuffer_16_out0_stream_prepad[1]);
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
    StreamingLineBuffer_16_pixel_11.run<230>(StreamingLineBuffer_16_buffer_stream[9], StreamingLineBuffer_16_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_0," << StreamingLineBuffer_16_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 10>,  // TOutputStruct
        4,  // DATA_PER_WORD
        334,  // DATA_TO_SHIFT
        1,  // TIMES
        1280000,  // WORDS
        1,  // ARRAY_PAR
        10  // WORD_PAR
    > StreamingMemory_104;
    StreamingMemory_104.run<393>(StreamingMemory_103_out1_stream, StreamingMemory_104_out0_stream, StreamingMemory_104_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_104_out0_stream_0," << StreamingMemory_104_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_104_out1_stream_0," << StreamingMemory_104_out1_stream[0].size() << std::endl;
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
    StreamingLineBuffer_16_pad.run<231>(StreamingLineBuffer_16_out0_stream_prepad, StreamingLineBuffer_16_out0_stream);
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
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<9>,  // TOutput
        std::array<ap_int<9>, 2>,  // TOutputStruct
        3,  // DATA_PER_WORD
        0,  // DATA_TO_SHIFT
        1,  // TIMES
        1000,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_105;
    StreamingMemory_105.run<395>(StreamingMemory_104_out1_stream, StreamingMemory_105_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMemory_105_out0_stream_0," << StreamingMemory_105_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingDepthwiseConv_5.run<233>(StreamingLineBuffer_16_out0_stream, StreamingMemory_32_out0_stream, StreamingMemory_33_out0_stream, StreamingDepthwiseConv_5_out0_stream);
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
    BandwidthAdjustIncreaseChannels_11.run<235>(StreamingDepthwiseConv_5_out0_stream, BandwidthAdjustIncreaseChannels_11_out0_stream);
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
    StreamingLineBuffer_17_pixel_0.run<237>(BandwidthAdjustIncreaseChannels_11_out0_stream[1], StreamingLineBuffer_17_out0_stream[1]);
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
    StreamingLineBuffer_17_pixel_1.run<238>(BandwidthAdjustIncreaseChannels_11_out0_stream[0], StreamingLineBuffer_17_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_0," << StreamingLineBuffer_17_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_11.run<240>(StreamingLineBuffer_17_out0_stream, StreamingMemory_34_out0_stream, StreamingMemory_35_out0_stream, StreamingConv_11_out0_stream);
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
    StreamingAdd_2.run<242>(BandwidthAdjustIncreaseChannels_10_out0_stream, StreamingConv_11_out0_stream, StreamingAdd_2_out0_stream);
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
    StreamingLineBuffer_18_pixel_0.run<244>(StreamingAdd_2_out0_stream[1], StreamingLineBuffer_18_out0_stream[1]);
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
    StreamingLineBuffer_18_pixel_1.run<245>(StreamingAdd_2_out0_stream[0], StreamingLineBuffer_18_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_0," << StreamingLineBuffer_18_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_12.run<247>(StreamingLineBuffer_18_out0_stream, StreamingMemory_36_out0_stream, StreamingMemory_37_out0_stream, StreamingConv_12_out0_stream);
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
    BandwidthAdjustDecreaseChannels_7.run<249>(StreamingConv_12_out0_stream, BandwidthAdjustDecreaseChannels_7_out0_stream);
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
    StreamingLineBuffer_19_pixel_0.run<251>(BandwidthAdjustDecreaseChannels_7_out0_stream[1], StreamingLineBuffer_19_out0_stream_prepad[14], StreamingLineBuffer_19_buffer_stream[0]);
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
    StreamingLineBuffer_19_pixel_1.run<252>(BandwidthAdjustDecreaseChannels_7_out0_stream[0], StreamingLineBuffer_19_out0_stream_prepad[13], StreamingLineBuffer_19_buffer_stream[1]);
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
    StreamingLineBuffer_19_pixel_2.run<253>(StreamingLineBuffer_19_buffer_stream[0], StreamingLineBuffer_19_out0_stream_prepad[12], StreamingLineBuffer_19_buffer_stream[2]);
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
    StreamingLineBuffer_19_pixel_3.run<254>(StreamingLineBuffer_19_buffer_stream[1], StreamingLineBuffer_19_out0_stream_prepad[11], StreamingLineBuffer_19_buffer_stream[4]);
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
    StreamingLineBuffer_19_pixel_4.run<255>(StreamingLineBuffer_19_buffer_stream[2], StreamingLineBuffer_19_out0_stream_prepad[10], StreamingLineBuffer_19_buffer_stream[3]);
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
    StreamingLineBuffer_19_pixel_6.run<257>(StreamingLineBuffer_19_buffer_stream[4], StreamingLineBuffer_19_out0_stream_prepad[8], StreamingLineBuffer_19_buffer_stream[6]);
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
    StreamingLineBuffer_19_pixel_5.run<256>(StreamingLineBuffer_19_buffer_stream[3], StreamingLineBuffer_19_out0_stream_prepad[9], StreamingLineBuffer_19_buffer_stream[5]);
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
    StreamingLineBuffer_19_pixel_8.run<259>(StreamingLineBuffer_19_buffer_stream[6], StreamingLineBuffer_19_out0_stream_prepad[6], StreamingLineBuffer_19_buffer_stream[9]);
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
    StreamingLineBuffer_19_pixel_7.run<258>(StreamingLineBuffer_19_buffer_stream[5], StreamingLineBuffer_19_out0_stream_prepad[7], StreamingLineBuffer_19_buffer_stream[7]);
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
    StreamingLineBuffer_19_pixel_11.run<262>(StreamingLineBuffer_19_buffer_stream[9], StreamingLineBuffer_19_out0_stream_prepad[3], StreamingLineBuffer_19_buffer_stream[11]);
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
    StreamingLineBuffer_19_pixel_9.run<260>(StreamingLineBuffer_19_buffer_stream[7], StreamingLineBuffer_19_out0_stream_prepad[5], StreamingLineBuffer_19_buffer_stream[8]);
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
    StreamingLineBuffer_19_pixel_13.run<264>(StreamingLineBuffer_19_buffer_stream[11], StreamingLineBuffer_19_out0_stream_prepad[1]);
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
    StreamingLineBuffer_19_pixel_10.run<261>(StreamingLineBuffer_19_buffer_stream[8], StreamingLineBuffer_19_out0_stream_prepad[4], StreamingLineBuffer_19_buffer_stream[10]);
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
    StreamingLineBuffer_19_pixel_12.run<263>(StreamingLineBuffer_19_buffer_stream[10], StreamingLineBuffer_19_out0_stream_prepad[2], StreamingLineBuffer_19_buffer_stream[12]);
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
    StreamingLineBuffer_19_pixel_14.run<265>(StreamingLineBuffer_19_buffer_stream[12], StreamingLineBuffer_19_out0_stream_prepad[0]);
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
    StreamingLineBuffer_19_pad.run<266>(StreamingLineBuffer_19_out0_stream_prepad, StreamingLineBuffer_19_out0_stream);
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
    StreamingDepthwiseConv_6.run<268>(StreamingLineBuffer_19_out0_stream, StreamingMemory_38_out0_stream, StreamingMemory_39_out0_stream, StreamingDepthwiseConv_6_out0_stream);
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
    BandwidthAdjustIncreaseChannels_12.run<270>(StreamingDepthwiseConv_6_out0_stream, BandwidthAdjustIncreaseChannels_12_out0_stream);
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
    BandwidthAdjustDecreaseStreams_1.run<272>(BandwidthAdjustIncreaseChannels_12_out0_stream, BandwidthAdjustDecreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_1_out0_stream_0," << BandwidthAdjustDecreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_13.run<274>(BandwidthAdjustDecreaseStreams_1_out0_stream, StreamingMemory_40_out0_stream, StreamingMemory_41_out0_stream, StreamingConv_13_out0_stream);
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
    TensorDuplicator_3.run<276>(StreamingConv_13_out0_stream, TensorDuplicator_3_out0_stream, TensorDuplicator_3_out1_stream);
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
    BandwidthAdjustIncreaseStreams_1.run<278>(TensorDuplicator_3_out0_stream, BandwidthAdjustIncreaseStreams_1_out0_stream);
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
    BandwidthAdjustIncreaseStreams_2.run<279>(TensorDuplicator_3_out1_stream, BandwidthAdjustIncreaseStreams_2_out0_stream);
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
    StreamingLineBuffer_20_pixel_0.run<281>(BandwidthAdjustIncreaseStreams_1_out0_stream[1], StreamingLineBuffer_20_out0_stream[1]);
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
    StreamingLineBuffer_20_pixel_1.run<282>(BandwidthAdjustIncreaseStreams_1_out0_stream[0], StreamingLineBuffer_20_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_0," << StreamingLineBuffer_20_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_14.run<284>(StreamingLineBuffer_20_out0_stream, StreamingMemory_42_out0_stream, StreamingMemory_43_out0_stream, StreamingConv_14_out0_stream);
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
    BandwidthAdjustDecreaseChannels_8.run<286>(StreamingConv_14_out0_stream, BandwidthAdjustDecreaseChannels_8_out0_stream);
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
    StreamingLineBuffer_21_pixel_0.run<288>(BandwidthAdjustDecreaseChannels_8_out0_stream[0], StreamingLineBuffer_21_out0_stream_prepad[11], StreamingLineBuffer_21_buffer_stream[0]);
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
    StreamingLineBuffer_21_pixel_1.run<289>(BandwidthAdjustDecreaseChannels_8_out0_stream[1], StreamingLineBuffer_21_out0_stream_prepad[10], StreamingLineBuffer_21_buffer_stream[1]);
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
    StreamingLineBuffer_21_pixel_2.run<290>(StreamingLineBuffer_21_buffer_stream[0], StreamingLineBuffer_21_out0_stream_prepad[9], StreamingLineBuffer_21_buffer_stream[2]);
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
    StreamingLineBuffer_21_pixel_3.run<291>(StreamingLineBuffer_21_buffer_stream[1], StreamingLineBuffer_21_out0_stream_prepad[8], StreamingLineBuffer_21_buffer_stream[3]);
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
    StreamingLineBuffer_21_pixel_4.run<292>(StreamingLineBuffer_21_buffer_stream[2], StreamingLineBuffer_21_out0_stream_prepad[7], StreamingLineBuffer_21_buffer_stream[4]);
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
    StreamingLineBuffer_21_pixel_5.run<293>(StreamingLineBuffer_21_buffer_stream[3], StreamingLineBuffer_21_out0_stream_prepad[6], StreamingLineBuffer_21_buffer_stream[5]);
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
    StreamingLineBuffer_21_pixel_6.run<294>(StreamingLineBuffer_21_buffer_stream[4], StreamingLineBuffer_21_out0_stream_prepad[5], StreamingLineBuffer_21_buffer_stream[6]);
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
    StreamingLineBuffer_21_pixel_7.run<295>(StreamingLineBuffer_21_buffer_stream[5], StreamingLineBuffer_21_out0_stream_prepad[4], StreamingLineBuffer_21_buffer_stream[7]);
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
    StreamingLineBuffer_21_pixel_8.run<296>(StreamingLineBuffer_21_buffer_stream[6], StreamingLineBuffer_21_out0_stream_prepad[3], StreamingLineBuffer_21_buffer_stream[8]);
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
    StreamingLineBuffer_21_pixel_9.run<297>(StreamingLineBuffer_21_buffer_stream[7], StreamingLineBuffer_21_out0_stream_prepad[2], StreamingLineBuffer_21_buffer_stream[9]);
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
    StreamingLineBuffer_21_pixel_10.run<298>(StreamingLineBuffer_21_buffer_stream[8], StreamingLineBuffer_21_out0_stream_prepad[1]);
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
    StreamingLineBuffer_21_pixel_11.run<299>(StreamingLineBuffer_21_buffer_stream[9], StreamingLineBuffer_21_out0_stream_prepad[0]);
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
    StreamingLineBuffer_21_pad.run<300>(StreamingLineBuffer_21_out0_stream_prepad, StreamingLineBuffer_21_out0_stream);
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
    StreamingDepthwiseConv_7.run<302>(StreamingLineBuffer_21_out0_stream, StreamingMemory_44_out0_stream, StreamingMemory_45_out0_stream, StreamingDepthwiseConv_7_out0_stream);
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
    BandwidthAdjustIncreaseChannels_13.run<304>(StreamingDepthwiseConv_7_out0_stream, BandwidthAdjustIncreaseChannels_13_out0_stream);
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
    StreamingLineBuffer_22_pixel_0.run<306>(BandwidthAdjustIncreaseChannels_13_out0_stream[1], StreamingLineBuffer_22_out0_stream[1]);
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
    StreamingLineBuffer_22_pixel_1.run<307>(BandwidthAdjustIncreaseChannels_13_out0_stream[0], StreamingLineBuffer_22_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_0," << StreamingLineBuffer_22_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_15.run<309>(StreamingLineBuffer_22_out0_stream, StreamingMemory_46_out0_stream, StreamingMemory_47_out0_stream, StreamingConv_15_out0_stream);
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
    StreamingAdd_3.run<311>(BandwidthAdjustIncreaseStreams_2_out0_stream, StreamingConv_15_out0_stream, StreamingAdd_3_out0_stream);
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
    BandwidthAdjustDecreaseStreams_2.run<313>(StreamingAdd_3_out0_stream, BandwidthAdjustDecreaseStreams_2_out0_stream);
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
    TensorDuplicator_4.run<315>(BandwidthAdjustDecreaseStreams_2_out0_stream, TensorDuplicator_4_out0_stream, TensorDuplicator_4_out1_stream);
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
    BandwidthAdjustIncreaseStreams_3.run<317>(TensorDuplicator_4_out0_stream, BandwidthAdjustIncreaseStreams_3_out0_stream);
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
    BandwidthAdjustIncreaseStreams_4.run<318>(TensorDuplicator_4_out1_stream, BandwidthAdjustIncreaseStreams_4_out0_stream);
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
    StreamingLineBuffer_23_pixel_0.run<320>(BandwidthAdjustIncreaseStreams_3_out0_stream[1], StreamingLineBuffer_23_out0_stream[1]);
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
    StreamingLineBuffer_23_pixel_1.run<321>(BandwidthAdjustIncreaseStreams_3_out0_stream[0], StreamingLineBuffer_23_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_23_out0_stream_0," << StreamingLineBuffer_23_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_16.run<323>(StreamingLineBuffer_23_out0_stream, StreamingMemory_48_out0_stream, StreamingMemory_49_out0_stream, StreamingConv_16_out0_stream);
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
    BandwidthAdjustDecreaseChannels_9.run<325>(StreamingConv_16_out0_stream, BandwidthAdjustDecreaseChannels_9_out0_stream);
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
    StreamingLineBuffer_24_pixel_0.run<327>(BandwidthAdjustDecreaseChannels_9_out0_stream[0], StreamingLineBuffer_24_out0_stream_prepad[11], StreamingLineBuffer_24_buffer_stream[0]);
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
    StreamingLineBuffer_24_pixel_1.run<328>(BandwidthAdjustDecreaseChannels_9_out0_stream[1], StreamingLineBuffer_24_out0_stream_prepad[10], StreamingLineBuffer_24_buffer_stream[1]);
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
    StreamingLineBuffer_24_pixel_2.run<329>(StreamingLineBuffer_24_buffer_stream[0], StreamingLineBuffer_24_out0_stream_prepad[9], StreamingLineBuffer_24_buffer_stream[2]);
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
    StreamingLineBuffer_24_pixel_3.run<330>(StreamingLineBuffer_24_buffer_stream[1], StreamingLineBuffer_24_out0_stream_prepad[8], StreamingLineBuffer_24_buffer_stream[3]);
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
    StreamingLineBuffer_24_pixel_4.run<331>(StreamingLineBuffer_24_buffer_stream[2], StreamingLineBuffer_24_out0_stream_prepad[7], StreamingLineBuffer_24_buffer_stream[4]);
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
    StreamingLineBuffer_24_pixel_5.run<332>(StreamingLineBuffer_24_buffer_stream[3], StreamingLineBuffer_24_out0_stream_prepad[6], StreamingLineBuffer_24_buffer_stream[5]);
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
    StreamingLineBuffer_24_pixel_6.run<333>(StreamingLineBuffer_24_buffer_stream[4], StreamingLineBuffer_24_out0_stream_prepad[5], StreamingLineBuffer_24_buffer_stream[6]);
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
    StreamingLineBuffer_24_pixel_7.run<334>(StreamingLineBuffer_24_buffer_stream[5], StreamingLineBuffer_24_out0_stream_prepad[4], StreamingLineBuffer_24_buffer_stream[7]);
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
    StreamingLineBuffer_24_pixel_8.run<335>(StreamingLineBuffer_24_buffer_stream[6], StreamingLineBuffer_24_out0_stream_prepad[3], StreamingLineBuffer_24_buffer_stream[8]);
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
    StreamingLineBuffer_24_pixel_9.run<336>(StreamingLineBuffer_24_buffer_stream[7], StreamingLineBuffer_24_out0_stream_prepad[2], StreamingLineBuffer_24_buffer_stream[9]);
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
    StreamingLineBuffer_24_pixel_10.run<337>(StreamingLineBuffer_24_buffer_stream[8], StreamingLineBuffer_24_out0_stream_prepad[1]);
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
    StreamingLineBuffer_24_pixel_11.run<338>(StreamingLineBuffer_24_buffer_stream[9], StreamingLineBuffer_24_out0_stream_prepad[0]);
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
    StreamingLineBuffer_24_pad.run<339>(StreamingLineBuffer_24_out0_stream_prepad, StreamingLineBuffer_24_out0_stream);
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
    StreamingDepthwiseConv_8.run<341>(StreamingLineBuffer_24_out0_stream, StreamingMemory_50_out0_stream, StreamingMemory_51_out0_stream, StreamingDepthwiseConv_8_out0_stream);
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
    BandwidthAdjustIncreaseChannels_14.run<343>(StreamingDepthwiseConv_8_out0_stream, BandwidthAdjustIncreaseChannels_14_out0_stream);
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
    StreamingLineBuffer_25_pixel_0.run<345>(BandwidthAdjustIncreaseChannels_14_out0_stream[1], StreamingLineBuffer_25_out0_stream[1]);
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
    StreamingLineBuffer_25_pixel_1.run<346>(BandwidthAdjustIncreaseChannels_14_out0_stream[0], StreamingLineBuffer_25_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_0," << StreamingLineBuffer_25_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_17.run<348>(StreamingLineBuffer_25_out0_stream, StreamingMemory_52_out0_stream, StreamingMemory_53_out0_stream, StreamingConv_17_out0_stream);
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
    StreamingAdd_4.run<350>(BandwidthAdjustIncreaseStreams_4_out0_stream, StreamingConv_17_out0_stream, StreamingAdd_4_out0_stream);
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
    BandwidthAdjustDecreaseStreams_3.run<352>(StreamingAdd_4_out0_stream, BandwidthAdjustDecreaseStreams_3_out0_stream);
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
    TensorDuplicator_5.run<354>(BandwidthAdjustDecreaseStreams_3_out0_stream, TensorDuplicator_5_out0_stream, TensorDuplicator_5_out1_stream);
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
    BandwidthAdjustIncreaseStreams_5.run<356>(TensorDuplicator_5_out0_stream, BandwidthAdjustIncreaseStreams_5_out0_stream);
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
    BandwidthAdjustIncreaseStreams_6.run<357>(TensorDuplicator_5_out1_stream, BandwidthAdjustIncreaseStreams_6_out0_stream);
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
    StreamingLineBuffer_26_pixel_0.run<359>(BandwidthAdjustIncreaseStreams_5_out0_stream[1], StreamingLineBuffer_26_out0_stream[1]);
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
    StreamingLineBuffer_26_pixel_1.run<360>(BandwidthAdjustIncreaseStreams_5_out0_stream[0], StreamingLineBuffer_26_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_26_out0_stream_0," << StreamingLineBuffer_26_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_18.run<362>(StreamingLineBuffer_26_out0_stream, StreamingMemory_54_out0_stream, StreamingMemory_55_out0_stream, StreamingConv_18_out0_stream);
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
    BandwidthAdjustDecreaseChannels_10.run<364>(StreamingConv_18_out0_stream, BandwidthAdjustDecreaseChannels_10_out0_stream);
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
    StreamingLineBuffer_27_pixel_0.run<366>(BandwidthAdjustDecreaseChannels_10_out0_stream[0], StreamingLineBuffer_27_out0_stream_prepad[11], StreamingLineBuffer_27_buffer_stream[0]);
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
    StreamingLineBuffer_27_pixel_1.run<367>(BandwidthAdjustDecreaseChannels_10_out0_stream[1], StreamingLineBuffer_27_out0_stream_prepad[10], StreamingLineBuffer_27_buffer_stream[1]);
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
    StreamingLineBuffer_27_pixel_2.run<368>(StreamingLineBuffer_27_buffer_stream[0], StreamingLineBuffer_27_out0_stream_prepad[9], StreamingLineBuffer_27_buffer_stream[2]);
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
    StreamingLineBuffer_27_pixel_3.run<369>(StreamingLineBuffer_27_buffer_stream[1], StreamingLineBuffer_27_out0_stream_prepad[8], StreamingLineBuffer_27_buffer_stream[3]);
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
    StreamingLineBuffer_27_pixel_4.run<370>(StreamingLineBuffer_27_buffer_stream[2], StreamingLineBuffer_27_out0_stream_prepad[7], StreamingLineBuffer_27_buffer_stream[4]);
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
    StreamingLineBuffer_27_pixel_5.run<371>(StreamingLineBuffer_27_buffer_stream[3], StreamingLineBuffer_27_out0_stream_prepad[6], StreamingLineBuffer_27_buffer_stream[5]);
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
    StreamingLineBuffer_27_pixel_6.run<372>(StreamingLineBuffer_27_buffer_stream[4], StreamingLineBuffer_27_out0_stream_prepad[5], StreamingLineBuffer_27_buffer_stream[6]);
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
    StreamingLineBuffer_27_pixel_7.run<373>(StreamingLineBuffer_27_buffer_stream[5], StreamingLineBuffer_27_out0_stream_prepad[4], StreamingLineBuffer_27_buffer_stream[7]);
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
    StreamingLineBuffer_27_pixel_8.run<374>(StreamingLineBuffer_27_buffer_stream[6], StreamingLineBuffer_27_out0_stream_prepad[3], StreamingLineBuffer_27_buffer_stream[8]);
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
    StreamingLineBuffer_27_pixel_9.run<375>(StreamingLineBuffer_27_buffer_stream[7], StreamingLineBuffer_27_out0_stream_prepad[2], StreamingLineBuffer_27_buffer_stream[9]);
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
    StreamingLineBuffer_27_pixel_10.run<376>(StreamingLineBuffer_27_buffer_stream[8], StreamingLineBuffer_27_out0_stream_prepad[1]);
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
    StreamingLineBuffer_27_pixel_11.run<377>(StreamingLineBuffer_27_buffer_stream[9], StreamingLineBuffer_27_out0_stream_prepad[0]);
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
    StreamingLineBuffer_27_pad.run<378>(StreamingLineBuffer_27_out0_stream_prepad, StreamingLineBuffer_27_out0_stream);
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
    StreamingDepthwiseConv_9.run<380>(StreamingLineBuffer_27_out0_stream, StreamingMemory_56_out0_stream, StreamingMemory_57_out0_stream, StreamingDepthwiseConv_9_out0_stream);
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
    BandwidthAdjustIncreaseChannels_15.run<382>(StreamingDepthwiseConv_9_out0_stream, BandwidthAdjustIncreaseChannels_15_out0_stream);
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
    StreamingLineBuffer_28_pixel_0.run<384>(BandwidthAdjustIncreaseChannels_15_out0_stream[1], StreamingLineBuffer_28_out0_stream[1]);
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
    StreamingLineBuffer_28_pixel_1.run<385>(BandwidthAdjustIncreaseChannels_15_out0_stream[0], StreamingLineBuffer_28_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_0," << StreamingLineBuffer_28_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_19.run<387>(StreamingLineBuffer_28_out0_stream, StreamingMemory_58_out0_stream, StreamingMemory_59_out0_stream, StreamingConv_19_out0_stream);
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
    StreamingAdd_5.run<389>(BandwidthAdjustIncreaseStreams_6_out0_stream, StreamingConv_19_out0_stream, StreamingAdd_5_out0_stream);
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
    StreamingLineBuffer_29_pixel_0.run<391>(StreamingAdd_5_out0_stream[1], StreamingLineBuffer_29_out0_stream[1]);
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
    StreamingLineBuffer_29_pixel_1.run<392>(StreamingAdd_5_out0_stream[0], StreamingLineBuffer_29_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_0," << StreamingLineBuffer_29_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_20.run<394>(StreamingLineBuffer_29_out0_stream, StreamingMemory_60_out0_stream, StreamingMemory_61_out0_stream, StreamingConv_20_out0_stream);
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
    BandwidthAdjustDecreaseChannels_11.run<396>(StreamingConv_20_out0_stream, BandwidthAdjustDecreaseChannels_11_out0_stream);
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
    StreamingLineBuffer_30_pixel_0.run<397>(BandwidthAdjustDecreaseChannels_11_out0_stream[0], StreamingLineBuffer_30_out0_stream_prepad[11], StreamingLineBuffer_30_buffer_stream[0]);
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
    StreamingLineBuffer_30_pixel_1.run<398>(BandwidthAdjustDecreaseChannels_11_out0_stream[1], StreamingLineBuffer_30_out0_stream_prepad[10], StreamingLineBuffer_30_buffer_stream[1]);
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
    StreamingLineBuffer_30_pixel_2.run<399>(StreamingLineBuffer_30_buffer_stream[0], StreamingLineBuffer_30_out0_stream_prepad[9], StreamingLineBuffer_30_buffer_stream[2]);
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
    StreamingLineBuffer_30_pixel_3.run<400>(StreamingLineBuffer_30_buffer_stream[1], StreamingLineBuffer_30_out0_stream_prepad[8], StreamingLineBuffer_30_buffer_stream[3]);
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
    StreamingLineBuffer_30_pixel_4.run<401>(StreamingLineBuffer_30_buffer_stream[2], StreamingLineBuffer_30_out0_stream_prepad[7], StreamingLineBuffer_30_buffer_stream[4]);
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
    StreamingLineBuffer_30_pixel_5.run<402>(StreamingLineBuffer_30_buffer_stream[3], StreamingLineBuffer_30_out0_stream_prepad[6], StreamingLineBuffer_30_buffer_stream[5]);
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
    StreamingLineBuffer_30_pixel_6.run<403>(StreamingLineBuffer_30_buffer_stream[4], StreamingLineBuffer_30_out0_stream_prepad[5], StreamingLineBuffer_30_buffer_stream[6]);
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
    StreamingLineBuffer_30_pixel_7.run<404>(StreamingLineBuffer_30_buffer_stream[5], StreamingLineBuffer_30_out0_stream_prepad[4], StreamingLineBuffer_30_buffer_stream[7]);
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
    StreamingLineBuffer_30_pixel_8.run<405>(StreamingLineBuffer_30_buffer_stream[6], StreamingLineBuffer_30_out0_stream_prepad[3], StreamingLineBuffer_30_buffer_stream[8]);
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
    StreamingLineBuffer_30_pixel_9.run<406>(StreamingLineBuffer_30_buffer_stream[7], StreamingLineBuffer_30_out0_stream_prepad[2], StreamingLineBuffer_30_buffer_stream[9]);
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
    StreamingLineBuffer_30_pixel_10.run<407>(StreamingLineBuffer_30_buffer_stream[8], StreamingLineBuffer_30_out0_stream_prepad[1]);
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
    StreamingLineBuffer_30_pixel_11.run<408>(StreamingLineBuffer_30_buffer_stream[9], StreamingLineBuffer_30_out0_stream_prepad[0]);
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
    StreamingLineBuffer_30_pad.run<409>(StreamingLineBuffer_30_out0_stream_prepad, StreamingLineBuffer_30_out0_stream);
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
    StreamingDepthwiseConv_10.run<410>(StreamingLineBuffer_30_out0_stream, StreamingMemory_62_out0_stream, StreamingMemory_63_out0_stream, StreamingDepthwiseConv_10_out0_stream);
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
    BandwidthAdjustIncreaseChannels_16.run<411>(StreamingDepthwiseConv_10_out0_stream, BandwidthAdjustIncreaseChannels_16_out0_stream);
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
    StreamingLineBuffer_31_pixel_0.run<412>(BandwidthAdjustIncreaseChannels_16_out0_stream[1], StreamingLineBuffer_31_out0_stream[1]);
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
    StreamingLineBuffer_31_pixel_1.run<413>(BandwidthAdjustIncreaseChannels_16_out0_stream[0], StreamingLineBuffer_31_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_31_out0_stream_0," << StreamingLineBuffer_31_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_21.run<414>(StreamingLineBuffer_31_out0_stream, StreamingMemory_64_out0_stream, StreamingMemory_65_out0_stream, StreamingConv_21_out0_stream);
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
    TensorDuplicator_6.run<415>(StreamingConv_21_out0_stream, TensorDuplicator_6_out0_stream, TensorDuplicator_6_out1_stream);
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
    BandwidthAdjustIncreaseChannels_17.run<416>(TensorDuplicator_6_out0_stream, BandwidthAdjustIncreaseChannels_17_out0_stream);
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
    StreamingLineBuffer_32_pixel_0.run<417>(BandwidthAdjustIncreaseChannels_17_out0_stream[1], StreamingLineBuffer_32_out0_stream[1]);
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
    StreamingLineBuffer_32_pixel_1.run<418>(BandwidthAdjustIncreaseChannels_17_out0_stream[0], StreamingLineBuffer_32_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_32_out0_stream_0," << StreamingLineBuffer_32_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_22.run<419>(StreamingLineBuffer_32_out0_stream, StreamingMemory_66_out0_stream, StreamingMemory_67_out0_stream, StreamingConv_22_out0_stream);
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
    BandwidthAdjustDecreaseChannels_12.run<420>(StreamingConv_22_out0_stream, BandwidthAdjustDecreaseChannels_12_out0_stream);
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
    StreamingLineBuffer_33_pixel_0.run<421>(BandwidthAdjustDecreaseChannels_12_out0_stream[0], StreamingLineBuffer_33_out0_stream_prepad[11], StreamingLineBuffer_33_buffer_stream[0]);
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
    StreamingLineBuffer_33_pixel_1.run<422>(BandwidthAdjustDecreaseChannels_12_out0_stream[1], StreamingLineBuffer_33_out0_stream_prepad[10], StreamingLineBuffer_33_buffer_stream[1]);
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
    StreamingLineBuffer_33_pixel_2.run<423>(StreamingLineBuffer_33_buffer_stream[0], StreamingLineBuffer_33_out0_stream_prepad[9], StreamingLineBuffer_33_buffer_stream[2]);
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
    StreamingLineBuffer_33_pixel_3.run<424>(StreamingLineBuffer_33_buffer_stream[1], StreamingLineBuffer_33_out0_stream_prepad[8], StreamingLineBuffer_33_buffer_stream[3]);
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
    StreamingLineBuffer_33_pixel_4.run<425>(StreamingLineBuffer_33_buffer_stream[2], StreamingLineBuffer_33_out0_stream_prepad[7], StreamingLineBuffer_33_buffer_stream[4]);
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
    StreamingLineBuffer_33_pixel_5.run<426>(StreamingLineBuffer_33_buffer_stream[3], StreamingLineBuffer_33_out0_stream_prepad[6], StreamingLineBuffer_33_buffer_stream[5]);
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
    StreamingLineBuffer_33_pixel_6.run<427>(StreamingLineBuffer_33_buffer_stream[4], StreamingLineBuffer_33_out0_stream_prepad[5], StreamingLineBuffer_33_buffer_stream[6]);
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
    StreamingLineBuffer_33_pixel_7.run<428>(StreamingLineBuffer_33_buffer_stream[5], StreamingLineBuffer_33_out0_stream_prepad[4], StreamingLineBuffer_33_buffer_stream[7]);
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
    StreamingLineBuffer_33_pixel_8.run<429>(StreamingLineBuffer_33_buffer_stream[6], StreamingLineBuffer_33_out0_stream_prepad[3], StreamingLineBuffer_33_buffer_stream[8]);
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
    StreamingLineBuffer_33_pixel_9.run<430>(StreamingLineBuffer_33_buffer_stream[7], StreamingLineBuffer_33_out0_stream_prepad[2], StreamingLineBuffer_33_buffer_stream[9]);
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
    StreamingLineBuffer_33_pixel_10.run<431>(StreamingLineBuffer_33_buffer_stream[8], StreamingLineBuffer_33_out0_stream_prepad[1]);
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
    StreamingLineBuffer_33_pixel_11.run<432>(StreamingLineBuffer_33_buffer_stream[9], StreamingLineBuffer_33_out0_stream_prepad[0]);
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
    StreamingLineBuffer_33_pad.run<433>(StreamingLineBuffer_33_out0_stream_prepad, StreamingLineBuffer_33_out0_stream);
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
    StreamingDepthwiseConv_11.run<434>(StreamingLineBuffer_33_out0_stream, StreamingMemory_68_out0_stream, StreamingMemory_69_out0_stream, StreamingDepthwiseConv_11_out0_stream);
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
    BandwidthAdjustIncreaseChannels_18.run<435>(StreamingDepthwiseConv_11_out0_stream, BandwidthAdjustIncreaseChannels_18_out0_stream);
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
    StreamingLineBuffer_34_pixel_0.run<436>(BandwidthAdjustIncreaseChannels_18_out0_stream[1], StreamingLineBuffer_34_out0_stream[1]);
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
    StreamingLineBuffer_34_pixel_1.run<437>(BandwidthAdjustIncreaseChannels_18_out0_stream[0], StreamingLineBuffer_34_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_0," << StreamingLineBuffer_34_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_23.run<438>(StreamingLineBuffer_34_out0_stream, StreamingMemory_70_out0_stream, StreamingMemory_71_out0_stream, StreamingConv_23_out0_stream);
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
    StreamingAdd_6.run<439>(TensorDuplicator_6_out1_stream, StreamingConv_23_out0_stream, StreamingAdd_6_out0_stream);
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
    TensorDuplicator_7.run<440>(StreamingAdd_6_out0_stream, TensorDuplicator_7_out0_stream, TensorDuplicator_7_out1_stream);
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
    BandwidthAdjustIncreaseChannels_19.run<441>(TensorDuplicator_7_out0_stream, BandwidthAdjustIncreaseChannels_19_out0_stream);
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
    StreamingLineBuffer_35_pixel_0.run<442>(BandwidthAdjustIncreaseChannels_19_out0_stream[1], StreamingLineBuffer_35_out0_stream[1]);
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
    StreamingLineBuffer_35_pixel_1.run<443>(BandwidthAdjustIncreaseChannels_19_out0_stream[0], StreamingLineBuffer_35_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_35_out0_stream_0," << StreamingLineBuffer_35_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_24.run<444>(StreamingLineBuffer_35_out0_stream, StreamingMemory_72_out0_stream, StreamingMemory_73_out0_stream, StreamingConv_24_out0_stream);
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
    BandwidthAdjustDecreaseChannels_13.run<445>(StreamingConv_24_out0_stream, BandwidthAdjustDecreaseChannels_13_out0_stream);
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
    StreamingLineBuffer_36_pixel_0.run<446>(BandwidthAdjustDecreaseChannels_13_out0_stream[0], StreamingLineBuffer_36_out0_stream_prepad[11], StreamingLineBuffer_36_buffer_stream[0]);
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
    StreamingLineBuffer_36_pixel_1.run<447>(BandwidthAdjustDecreaseChannels_13_out0_stream[1], StreamingLineBuffer_36_out0_stream_prepad[10], StreamingLineBuffer_36_buffer_stream[1]);
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
    StreamingLineBuffer_36_pixel_2.run<448>(StreamingLineBuffer_36_buffer_stream[0], StreamingLineBuffer_36_out0_stream_prepad[9], StreamingLineBuffer_36_buffer_stream[2]);
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
    StreamingLineBuffer_36_pixel_3.run<449>(StreamingLineBuffer_36_buffer_stream[1], StreamingLineBuffer_36_out0_stream_prepad[8], StreamingLineBuffer_36_buffer_stream[3]);
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
    StreamingLineBuffer_36_pixel_4.run<450>(StreamingLineBuffer_36_buffer_stream[2], StreamingLineBuffer_36_out0_stream_prepad[7], StreamingLineBuffer_36_buffer_stream[4]);
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
    StreamingLineBuffer_36_pixel_5.run<451>(StreamingLineBuffer_36_buffer_stream[3], StreamingLineBuffer_36_out0_stream_prepad[6], StreamingLineBuffer_36_buffer_stream[5]);
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
    StreamingLineBuffer_36_pixel_6.run<452>(StreamingLineBuffer_36_buffer_stream[4], StreamingLineBuffer_36_out0_stream_prepad[5], StreamingLineBuffer_36_buffer_stream[6]);
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
    StreamingLineBuffer_36_pixel_7.run<453>(StreamingLineBuffer_36_buffer_stream[5], StreamingLineBuffer_36_out0_stream_prepad[4], StreamingLineBuffer_36_buffer_stream[7]);
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
    StreamingLineBuffer_36_pixel_8.run<454>(StreamingLineBuffer_36_buffer_stream[6], StreamingLineBuffer_36_out0_stream_prepad[3], StreamingLineBuffer_36_buffer_stream[8]);
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
    StreamingLineBuffer_36_pixel_9.run<455>(StreamingLineBuffer_36_buffer_stream[7], StreamingLineBuffer_36_out0_stream_prepad[2], StreamingLineBuffer_36_buffer_stream[9]);
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
    StreamingLineBuffer_36_pixel_10.run<456>(StreamingLineBuffer_36_buffer_stream[8], StreamingLineBuffer_36_out0_stream_prepad[1]);
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
    StreamingLineBuffer_36_pixel_11.run<457>(StreamingLineBuffer_36_buffer_stream[9], StreamingLineBuffer_36_out0_stream_prepad[0]);
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
    StreamingLineBuffer_36_pad.run<458>(StreamingLineBuffer_36_out0_stream_prepad, StreamingLineBuffer_36_out0_stream);
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
    StreamingDepthwiseConv_12.run<459>(StreamingLineBuffer_36_out0_stream, StreamingMemory_74_out0_stream, StreamingMemory_75_out0_stream, StreamingDepthwiseConv_12_out0_stream);
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
    BandwidthAdjustIncreaseChannels_20.run<460>(StreamingDepthwiseConv_12_out0_stream, BandwidthAdjustIncreaseChannels_20_out0_stream);
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
    StreamingLineBuffer_37_pixel_0.run<461>(BandwidthAdjustIncreaseChannels_20_out0_stream[1], StreamingLineBuffer_37_out0_stream[1]);
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
    StreamingLineBuffer_37_pixel_1.run<462>(BandwidthAdjustIncreaseChannels_20_out0_stream[0], StreamingLineBuffer_37_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_37_out0_stream_0," << StreamingLineBuffer_37_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_25.run<463>(StreamingLineBuffer_37_out0_stream, StreamingMemory_76_out0_stream, StreamingMemory_77_out0_stream, StreamingConv_25_out0_stream);
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
    StreamingAdd_7.run<464>(TensorDuplicator_7_out1_stream, StreamingConv_25_out0_stream, StreamingAdd_7_out0_stream);
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
    BandwidthAdjustIncreaseChannels_21.run<465>(StreamingAdd_7_out0_stream, BandwidthAdjustIncreaseChannels_21_out0_stream);
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
    StreamingLineBuffer_38_pixel_0.run<466>(BandwidthAdjustIncreaseChannels_21_out0_stream[1], StreamingLineBuffer_38_out0_stream[1]);
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
    StreamingLineBuffer_38_pixel_1.run<467>(BandwidthAdjustIncreaseChannels_21_out0_stream[0], StreamingLineBuffer_38_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_0," << StreamingLineBuffer_38_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_26.run<468>(StreamingLineBuffer_38_out0_stream, StreamingMemory_78_out0_stream, StreamingMemory_79_out0_stream, StreamingConv_26_out0_stream);
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
    BandwidthAdjustDecreaseChannels_14.run<469>(StreamingConv_26_out0_stream, BandwidthAdjustDecreaseChannels_14_out0_stream);
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
    BandwidthAdjustDecreaseStreams_4.run<470>(BandwidthAdjustDecreaseChannels_14_out0_stream, BandwidthAdjustDecreaseStreams_4_out0_stream);
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
    StreamingLineBuffer_39_pixel_0.run<471>(BandwidthAdjustDecreaseStreams_4_out0_stream[0], StreamingLineBuffer_39_out0_stream_prepad[8], StreamingLineBuffer_39_buffer_stream[0]);
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
    StreamingLineBuffer_39_pixel_1.run<472>(StreamingLineBuffer_39_buffer_stream[0], StreamingLineBuffer_39_out0_stream_prepad[7], StreamingLineBuffer_39_buffer_stream[1]);
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
    StreamingLineBuffer_39_pixel_2.run<473>(StreamingLineBuffer_39_buffer_stream[1], StreamingLineBuffer_39_out0_stream_prepad[6], StreamingLineBuffer_39_buffer_stream[2]);
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
    StreamingLineBuffer_39_pixel_3.run<474>(StreamingLineBuffer_39_buffer_stream[2], StreamingLineBuffer_39_out0_stream_prepad[5], StreamingLineBuffer_39_buffer_stream[3]);
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
    StreamingLineBuffer_39_pixel_4.run<475>(StreamingLineBuffer_39_buffer_stream[3], StreamingLineBuffer_39_out0_stream_prepad[4], StreamingLineBuffer_39_buffer_stream[4]);
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
    StreamingLineBuffer_39_pixel_5.run<476>(StreamingLineBuffer_39_buffer_stream[4], StreamingLineBuffer_39_out0_stream_prepad[3], StreamingLineBuffer_39_buffer_stream[5]);
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
    StreamingLineBuffer_39_pixel_6.run<477>(StreamingLineBuffer_39_buffer_stream[5], StreamingLineBuffer_39_out0_stream_prepad[2], StreamingLineBuffer_39_buffer_stream[6]);
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
    StreamingLineBuffer_39_pixel_7.run<478>(StreamingLineBuffer_39_buffer_stream[6], StreamingLineBuffer_39_out0_stream_prepad[1], StreamingLineBuffer_39_buffer_stream[7]);
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
    StreamingLineBuffer_39_pixel_8.run<479>(StreamingLineBuffer_39_buffer_stream[7], StreamingLineBuffer_39_out0_stream_prepad[0]);
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
    StreamingLineBuffer_39_pad.run<480>(StreamingLineBuffer_39_out0_stream_prepad, StreamingLineBuffer_39_out0_stream);
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
    StreamingDepthwiseConv_13.run<481>(StreamingLineBuffer_39_out0_stream, StreamingMemory_80_out0_stream, StreamingMemory_81_out0_stream, StreamingDepthwiseConv_13_out0_stream);
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
    BandwidthAdjustIncreaseChannels_22.run<482>(StreamingDepthwiseConv_13_out0_stream, BandwidthAdjustIncreaseChannels_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_22_out0_stream_0," << BandwidthAdjustIncreaseChannels_22_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_27.run<483>(BandwidthAdjustIncreaseChannels_22_out0_stream, StreamingMemory_82_out0_stream, StreamingMemory_83_out0_stream, StreamingConv_27_out0_stream);
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
    TensorDuplicator_8.run<484>(StreamingConv_27_out0_stream, TensorDuplicator_8_out0_stream, TensorDuplicator_8_out1_stream);
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
    BandwidthAdjustDecreaseChannels_15.run<485>(TensorDuplicator_8_out0_stream, BandwidthAdjustDecreaseChannels_15_out0_stream);
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
    BandwidthAdjustIncreaseChannels_23.run<486>(BandwidthAdjustDecreaseChannels_15_out0_stream, BandwidthAdjustIncreaseChannels_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_23_out0_stream_0," << BandwidthAdjustIncreaseChannels_23_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_28.run<487>(BandwidthAdjustIncreaseChannels_23_out0_stream, StreamingMemory_84_out0_stream, StreamingMemory_85_out0_stream, StreamingConv_28_out0_stream);
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
    BandwidthAdjustDecreaseChannels_16.run<488>(StreamingConv_28_out0_stream, BandwidthAdjustDecreaseChannels_16_out0_stream);
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
    StreamingLineBuffer_40_pixel_0.run<489>(BandwidthAdjustDecreaseChannels_16_out0_stream[0], StreamingLineBuffer_40_out0_stream_prepad[8], StreamingLineBuffer_40_buffer_stream[0]);
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
    StreamingLineBuffer_40_pixel_1.run<490>(StreamingLineBuffer_40_buffer_stream[0], StreamingLineBuffer_40_out0_stream_prepad[7], StreamingLineBuffer_40_buffer_stream[1]);
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
    StreamingLineBuffer_40_pixel_2.run<491>(StreamingLineBuffer_40_buffer_stream[1], StreamingLineBuffer_40_out0_stream_prepad[6], StreamingLineBuffer_40_buffer_stream[2]);
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
    StreamingLineBuffer_40_pixel_3.run<492>(StreamingLineBuffer_40_buffer_stream[2], StreamingLineBuffer_40_out0_stream_prepad[5], StreamingLineBuffer_40_buffer_stream[3]);
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
    StreamingLineBuffer_40_pixel_4.run<493>(StreamingLineBuffer_40_buffer_stream[3], StreamingLineBuffer_40_out0_stream_prepad[4], StreamingLineBuffer_40_buffer_stream[4]);
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
    StreamingLineBuffer_40_pixel_5.run<494>(StreamingLineBuffer_40_buffer_stream[4], StreamingLineBuffer_40_out0_stream_prepad[3], StreamingLineBuffer_40_buffer_stream[5]);
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
    StreamingLineBuffer_40_pixel_6.run<495>(StreamingLineBuffer_40_buffer_stream[5], StreamingLineBuffer_40_out0_stream_prepad[2], StreamingLineBuffer_40_buffer_stream[6]);
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
    StreamingLineBuffer_40_pixel_7.run<496>(StreamingLineBuffer_40_buffer_stream[6], StreamingLineBuffer_40_out0_stream_prepad[1], StreamingLineBuffer_40_buffer_stream[7]);
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
    StreamingLineBuffer_40_pixel_8.run<497>(StreamingLineBuffer_40_buffer_stream[7], StreamingLineBuffer_40_out0_stream_prepad[0]);
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
    StreamingLineBuffer_40_pad.run<498>(StreamingLineBuffer_40_out0_stream_prepad, StreamingLineBuffer_40_out0_stream);
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
    StreamingDepthwiseConv_14.run<499>(StreamingLineBuffer_40_out0_stream, StreamingMemory_86_out0_stream, StreamingMemory_87_out0_stream, StreamingDepthwiseConv_14_out0_stream);
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
    BandwidthAdjustIncreaseChannels_24.run<500>(StreamingDepthwiseConv_14_out0_stream, BandwidthAdjustIncreaseChannels_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_24_out0_stream_0," << BandwidthAdjustIncreaseChannels_24_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_29.run<501>(BandwidthAdjustIncreaseChannels_24_out0_stream, StreamingMemory_88_out0_stream, StreamingMemory_89_out0_stream, StreamingConv_29_out0_stream);
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
    StreamingAdd_8.run<502>(TensorDuplicator_8_out1_stream, StreamingConv_29_out0_stream, StreamingAdd_8_out0_stream);
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
    TensorDuplicator_9.run<503>(StreamingAdd_8_out0_stream, TensorDuplicator_9_out0_stream, TensorDuplicator_9_out1_stream);
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
    BandwidthAdjustDecreaseChannels_17.run<504>(TensorDuplicator_9_out0_stream, BandwidthAdjustDecreaseChannels_17_out0_stream);
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
    BandwidthAdjustDecreaseChannels_18.run<505>(TensorDuplicator_9_out1_stream, BandwidthAdjustDecreaseChannels_18_out0_stream);
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
    BandwidthAdjustIncreaseChannels_25.run<506>(BandwidthAdjustDecreaseChannels_17_out0_stream, BandwidthAdjustIncreaseChannels_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_25_out0_stream_0," << BandwidthAdjustIncreaseChannels_25_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_30.run<507>(BandwidthAdjustIncreaseChannels_25_out0_stream, StreamingMemory_90_out0_stream, StreamingMemory_91_out0_stream, StreamingConv_30_out0_stream);
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
    BandwidthAdjustDecreaseChannels_19.run<508>(StreamingConv_30_out0_stream, BandwidthAdjustDecreaseChannels_19_out0_stream);
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
    StreamingLineBuffer_41_pixel_0.run<509>(BandwidthAdjustDecreaseChannels_19_out0_stream[0], StreamingLineBuffer_41_out0_stream_prepad[8], StreamingLineBuffer_41_buffer_stream[0]);
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
    StreamingLineBuffer_41_pixel_1.run<510>(StreamingLineBuffer_41_buffer_stream[0], StreamingLineBuffer_41_out0_stream_prepad[7], StreamingLineBuffer_41_buffer_stream[1]);
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
    StreamingLineBuffer_41_pixel_2.run<511>(StreamingLineBuffer_41_buffer_stream[1], StreamingLineBuffer_41_out0_stream_prepad[6], StreamingLineBuffer_41_buffer_stream[2]);
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
    StreamingLineBuffer_41_pixel_3.run<512>(StreamingLineBuffer_41_buffer_stream[2], StreamingLineBuffer_41_out0_stream_prepad[5], StreamingLineBuffer_41_buffer_stream[3]);
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
    StreamingLineBuffer_41_pixel_4.run<513>(StreamingLineBuffer_41_buffer_stream[3], StreamingLineBuffer_41_out0_stream_prepad[4], StreamingLineBuffer_41_buffer_stream[4]);
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
    StreamingLineBuffer_41_pixel_5.run<514>(StreamingLineBuffer_41_buffer_stream[4], StreamingLineBuffer_41_out0_stream_prepad[3], StreamingLineBuffer_41_buffer_stream[5]);
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
    StreamingLineBuffer_41_pixel_6.run<515>(StreamingLineBuffer_41_buffer_stream[5], StreamingLineBuffer_41_out0_stream_prepad[2], StreamingLineBuffer_41_buffer_stream[6]);
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
    StreamingLineBuffer_41_pixel_7.run<516>(StreamingLineBuffer_41_buffer_stream[6], StreamingLineBuffer_41_out0_stream_prepad[1], StreamingLineBuffer_41_buffer_stream[7]);
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
    StreamingLineBuffer_41_pixel_8.run<517>(StreamingLineBuffer_41_buffer_stream[7], StreamingLineBuffer_41_out0_stream_prepad[0]);
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
    StreamingLineBuffer_41_pad.run<518>(StreamingLineBuffer_41_out0_stream_prepad, StreamingLineBuffer_41_out0_stream);
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
    StreamingDepthwiseConv_15.run<519>(StreamingLineBuffer_41_out0_stream, StreamingMemory_92_out0_stream, StreamingMemory_93_out0_stream, StreamingDepthwiseConv_15_out0_stream);
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
    BandwidthAdjustIncreaseChannels_26.run<520>(StreamingDepthwiseConv_15_out0_stream, BandwidthAdjustIncreaseChannels_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_26_out0_stream_0," << BandwidthAdjustIncreaseChannels_26_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_31.run<521>(BandwidthAdjustIncreaseChannels_26_out0_stream, StreamingMemory_94_out0_stream, StreamingMemory_95_out0_stream, StreamingConv_31_out0_stream);
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
    StreamingAdd_9.run<522>(BandwidthAdjustDecreaseChannels_18_out0_stream, StreamingConv_31_out0_stream, StreamingAdd_9_out0_stream);
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
    BandwidthAdjustIncreaseChannels_27.run<523>(StreamingAdd_9_out0_stream, BandwidthAdjustIncreaseChannels_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_27_out0_stream_0," << BandwidthAdjustIncreaseChannels_27_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_32.run<524>(BandwidthAdjustIncreaseChannels_27_out0_stream, StreamingMemory_96_out0_stream, StreamingMemory_97_out0_stream, StreamingConv_32_out0_stream);
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
    BandwidthAdjustDecreaseChannels_20.run<525>(StreamingConv_32_out0_stream, BandwidthAdjustDecreaseChannels_20_out0_stream);
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
    StreamingLineBuffer_42_pixel_0.run<526>(BandwidthAdjustDecreaseChannels_20_out0_stream[0], StreamingLineBuffer_42_out0_stream_prepad[8], StreamingLineBuffer_42_buffer_stream[0]);
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
    StreamingLineBuffer_42_pixel_1.run<527>(StreamingLineBuffer_42_buffer_stream[0], StreamingLineBuffer_42_out0_stream_prepad[7], StreamingLineBuffer_42_buffer_stream[1]);
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
    StreamingLineBuffer_42_pixel_2.run<528>(StreamingLineBuffer_42_buffer_stream[1], StreamingLineBuffer_42_out0_stream_prepad[6], StreamingLineBuffer_42_buffer_stream[2]);
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
    StreamingLineBuffer_42_pixel_3.run<529>(StreamingLineBuffer_42_buffer_stream[2], StreamingLineBuffer_42_out0_stream_prepad[5], StreamingLineBuffer_42_buffer_stream[3]);
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
    StreamingLineBuffer_42_pixel_4.run<530>(StreamingLineBuffer_42_buffer_stream[3], StreamingLineBuffer_42_out0_stream_prepad[4], StreamingLineBuffer_42_buffer_stream[4]);
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
    StreamingLineBuffer_42_pixel_5.run<531>(StreamingLineBuffer_42_buffer_stream[4], StreamingLineBuffer_42_out0_stream_prepad[3], StreamingLineBuffer_42_buffer_stream[5]);
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
    StreamingLineBuffer_42_pixel_6.run<532>(StreamingLineBuffer_42_buffer_stream[5], StreamingLineBuffer_42_out0_stream_prepad[2], StreamingLineBuffer_42_buffer_stream[6]);
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
    StreamingLineBuffer_42_pixel_7.run<533>(StreamingLineBuffer_42_buffer_stream[6], StreamingLineBuffer_42_out0_stream_prepad[1], StreamingLineBuffer_42_buffer_stream[7]);
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
    StreamingLineBuffer_42_pixel_8.run<534>(StreamingLineBuffer_42_buffer_stream[7], StreamingLineBuffer_42_out0_stream_prepad[0]);
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
    StreamingLineBuffer_42_pad.run<535>(StreamingLineBuffer_42_out0_stream_prepad, StreamingLineBuffer_42_out0_stream);
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
    StreamingDepthwiseConv_16.run<536>(StreamingLineBuffer_42_out0_stream, StreamingMemory_98_out0_stream, StreamingMemory_99_out0_stream, StreamingDepthwiseConv_16_out0_stream);
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
    BandwidthAdjustIncreaseChannels_28.run<537>(StreamingDepthwiseConv_16_out0_stream, BandwidthAdjustIncreaseChannels_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_28_out0_stream_0," << BandwidthAdjustIncreaseChannels_28_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_33.run<538>(BandwidthAdjustIncreaseChannels_28_out0_stream, StreamingMemory_100_out0_stream, StreamingMemory_101_out0_stream, StreamingConv_33_out0_stream);
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
    BandwidthAdjustIncreaseChannels_29.run<539>(StreamingConv_33_out0_stream, BandwidthAdjustIncreaseChannels_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_29_out0_stream_0," << BandwidthAdjustIncreaseChannels_29_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_34.run<540>(BandwidthAdjustIncreaseChannels_29_out0_stream, StreamingMemory_102_out0_stream, StreamingMemory_103_out0_stream, StreamingConv_34_out0_stream);
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
    BandwidthAdjustDecreaseChannels_21.run<541>(StreamingConv_34_out0_stream, BandwidthAdjustDecreaseChannels_21_out0_stream);
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
    StreamingGlobalAveragePool_0.run<542>(BandwidthAdjustDecreaseChannels_21_out0_stream, StreamingGlobalAveragePool_0_out0_stream);
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
    BandwidthAdjustIncreaseChannels_30.run<543>(StreamingGlobalAveragePool_0_out0_stream, BandwidthAdjustIncreaseChannels_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_30_out0_stream_0," << BandwidthAdjustIncreaseChannels_30_out0_stream[0].size() << std::endl;
    #endif
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
    StreamingConv_35.run<544>(BandwidthAdjustIncreaseChannels_30_out0_stream, StreamingMemory_104_out0_stream, StreamingMemory_105_out0_stream, StreamingConv_35_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_35_out0_stream_0," << StreamingConv_35_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        501,  // ITER
        16,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        1000,  // CH
        1,  // IN_W_PAR
        2  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.run<545>(StreamingConv_35_out0_stream, global_out);
}
