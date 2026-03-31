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
#include "StreamingDepthwiseConv.hpp"
#include "StreamingPad.hpp"
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
void resnet8(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis port=global_in
    #pragma HLS INTERFACE axis port=global_out
    hls::stream<std::array<ap_int<8>, 3>> NHWCToStream_0_out0_stream[4];
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_0_out0_stream[4];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream[18];
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
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[17] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[0] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[1] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[2] depth=50
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[3] depth=50
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[4] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[5] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[6] depth=24
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[7] depth=25
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[8] depth=29
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[9] depth=29
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[10] depth=27
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[11] depth=22
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[12] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_buffer_stream[14];
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
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[13] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_0_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_0_out0_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_0_out1_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[0] depth=656
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[1] depth=656
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[2] depth=656
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[3] depth=656
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream[18];
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
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[14] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[15] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[16] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[17] depth=4
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[0] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[1] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[2] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[3] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[4] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[5] depth=225
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[6] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[7] depth=146
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[8] depth=146
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[9] depth=146
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[10] depth=146
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[11] depth=113
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[13] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[14] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[15] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[16] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[13] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_1_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_2_out0_stream[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[17] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_2_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[1] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[2] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[3] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[4] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[5] depth=57
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[6] depth=37
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[7] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[8] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[9] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[10] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[11] depth=29
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[12] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[14] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[15] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[16] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_2_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[13] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_2_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_0_out0_stream[4];
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_1_out0_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[1] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[2] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_1_out1_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[1] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[2] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_out0_stream[27];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[0] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[1] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[2] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[3] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[4] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[5] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[6] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[7] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[8] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[9] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[10] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[11] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[12] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[13] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[14] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[15] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[16] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[17] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[18] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[19] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[20] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[21] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[22] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[23] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[24] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[25] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[26] depth=40
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_out0_stream_prepad[27];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[0] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[1] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[2] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[3] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[4] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[5] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[6] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[7] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[9] depth=49
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[10] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[11] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[12] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[13] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[14] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[15] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[16] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[17] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[18] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[19] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[20] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[21] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[22] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[23] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[24] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[25] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[26] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_buffer_stream[23];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[17] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[18] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[19] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[20] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[21] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[22] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_4_out0_stream[7];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[0] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[1] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[2] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[3] depth=43
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[4] depth=39
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[5] depth=39
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[6] depth=39
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_4_buffer_stream[3];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[2] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_3_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_4_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[0] depth=145
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[1] depth=145
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[2] depth=145
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[3] depth=145
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_5_out0_stream[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[8] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[9] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[10] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[11] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[12] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[13] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[14] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[15] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[16] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[17] depth=11
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_5_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[1] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[2] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[3] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[4] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[5] depth=97
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[6] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[7] depth=82
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[8] depth=82
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[9] depth=82
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[10] depth=82
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[11] depth=49
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[13] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[14] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[15] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[16] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_5_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[13] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_5_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 2>> StreamingAdd_1_out0_stream[4];
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[1] depth=3
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[2] depth=3
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[3] depth=3
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_2_out0_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[1] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[2] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_2_out1_stream[4];
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[1] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[2] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_out0_stream[27];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[0] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[1] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[2] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[3] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[4] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[5] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[6] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[7] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[8] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[10] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[11] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[12] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[13] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[14] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[15] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[16] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[17] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[18] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[19] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[20] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[21] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[22] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[23] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[24] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[25] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[26] depth=8
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_out0_stream_prepad[27];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[0] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[1] depth=47
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[2] depth=47
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[3] depth=47
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[4] depth=47
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[5] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[6] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[7] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[9] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[13] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[14] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[15] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[16] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[17] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[18] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[19] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[20] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[21] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[22] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[23] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[24] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[25] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[26] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_buffer_stream[23];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[17] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[18] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[19] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[20] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[21] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[22] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_7_out0_stream[7];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[0] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[1] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[2] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[3] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[5] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[6] depth=7
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_7_buffer_stream[3];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_buffer_stream[2] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_6_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[3] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_7_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[0] depth=193
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[1] depth=193
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[2] depth=193
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[3] depth=193
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_8_out0_stream[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[6] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[7] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[9] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[13] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[14] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[15] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[16] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[17] depth=33
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_8_out0_stream_prepad[18];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[0] depth=97
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[1] depth=161
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[2] depth=161
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[3] depth=161
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[4] depth=161
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[7] depth=98
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[8] depth=98
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[9] depth=98
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[10] depth=98
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[13] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[14] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[15] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[16] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[17] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_8_buffer_stream[14];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[13] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_8_out0_stream[4];
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[3] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingAdd_2_out0_stream[4];
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[1] depth=35
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[2] depth=65
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[3] depth=65
    hls::stream<std::array<ap_uint<8>, 2>> BandwidthAdjustDecreaseStreams_0_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_9_out0_stream[64];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[6] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[7] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[9] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[12] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[13] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[14] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[15] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[16] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[17] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[18] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[19] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[20] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[21] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[22] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[23] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[24] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[25] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[26] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[27] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[28] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[29] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[30] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[31] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[32] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[33] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[34] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[35] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[36] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[37] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[38] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[39] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[40] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[41] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[42] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[43] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[44] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[45] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[46] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[47] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[48] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[49] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[50] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[51] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[52] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[53] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[54] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[55] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[56] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[57] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[58] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[59] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[60] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[61] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[62] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[63] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_9_buffer_stream[63];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[17] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[18] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[19] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[20] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[21] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[22] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[23] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[24] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[25] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[26] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[27] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[28] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[29] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[30] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[31] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[32] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[33] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[34] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[35] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[36] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[37] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[38] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[39] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[40] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[41] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[42] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[43] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[44] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[45] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[46] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[47] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[48] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[49] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[50] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[51] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[52] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[53] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[54] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[55] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[56] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[57] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[58] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[59] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[60] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[61] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[62] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingMaxPool_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMaxPool_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_9_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[0] depth=2
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        16,  // DATA_PER_WORD
        32,  // HEIGHT
        32,  // WIDTH
        3,  // CH
        4,  // OUT_W_PAR
        3  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.run<0>(global_in, NHWCToStream_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_0," << NHWCToStream_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_1," << NHWCToStream_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_2," << NHWCToStream_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_3," << NHWCToStream_0_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        3,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_0;
    BandwidthAdjustDecreaseChannels_0.run<1>(NHWCToStream_0_out0_stream, BandwidthAdjustDecreaseChannels_0_out0_stream);
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_0;
    StreamingLineBuffer_0_pixel_0.run<2>(BandwidthAdjustDecreaseChannels_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[17], StreamingLineBuffer_0_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_17," << StreamingLineBuffer_0_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_0," << StreamingLineBuffer_0_buffer_stream[0].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_1;
    StreamingLineBuffer_0_pixel_1.run<3>(BandwidthAdjustDecreaseChannels_0_out0_stream[3], StreamingLineBuffer_0_out0_stream_prepad[16], StreamingLineBuffer_0_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_16," << StreamingLineBuffer_0_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_1," << StreamingLineBuffer_0_buffer_stream[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_2;
    StreamingLineBuffer_0_pixel_2.run<4>(BandwidthAdjustDecreaseChannels_0_out0_stream[2], StreamingLineBuffer_0_out0_stream_prepad[15], StreamingLineBuffer_0_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_15," << StreamingLineBuffer_0_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_4," << StreamingLineBuffer_0_buffer_stream[4].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_3;
    StreamingLineBuffer_0_pixel_3.run<5>(BandwidthAdjustDecreaseChannels_0_out0_stream[1], StreamingLineBuffer_0_out0_stream_prepad[14], StreamingLineBuffer_0_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_14," << StreamingLineBuffer_0_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_5," << StreamingLineBuffer_0_buffer_stream[5].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_4;
    StreamingLineBuffer_0_pixel_4.run<6>(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[13], StreamingLineBuffer_0_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_13," << StreamingLineBuffer_0_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_2," << StreamingLineBuffer_0_buffer_stream[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_5;
    StreamingLineBuffer_0_pixel_5.run<7>(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[12], StreamingLineBuffer_0_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_12," << StreamingLineBuffer_0_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_3," << StreamingLineBuffer_0_buffer_stream[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_8;
    StreamingLineBuffer_0_pixel_8.run<10>(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[9], StreamingLineBuffer_0_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_9," << StreamingLineBuffer_0_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_10," << StreamingLineBuffer_0_buffer_stream[10].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_9;
    StreamingLineBuffer_0_pixel_9.run<11>(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_8," << StreamingLineBuffer_0_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_11," << StreamingLineBuffer_0_buffer_stream[11].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_6;
    StreamingLineBuffer_0_pixel_6.run<8>(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[11], StreamingLineBuffer_0_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_11," << StreamingLineBuffer_0_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_6," << StreamingLineBuffer_0_buffer_stream[6].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_7;
    StreamingLineBuffer_0_pixel_7.run<9>(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[10], StreamingLineBuffer_0_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_10," << StreamingLineBuffer_0_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_7," << StreamingLineBuffer_0_buffer_stream[7].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_14;
    StreamingLineBuffer_0_pixel_14.run<16>(StreamingLineBuffer_0_buffer_stream[10], StreamingLineBuffer_0_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_3," << StreamingLineBuffer_0_out0_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_15;
    StreamingLineBuffer_0_pixel_15.run<17>(StreamingLineBuffer_0_buffer_stream[11], StreamingLineBuffer_0_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_2," << StreamingLineBuffer_0_out0_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_10;
    StreamingLineBuffer_0_pixel_10.run<12>(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_7," << StreamingLineBuffer_0_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_8," << StreamingLineBuffer_0_buffer_stream[8].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_11;
    StreamingLineBuffer_0_pixel_11.run<13>(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_6," << StreamingLineBuffer_0_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_9," << StreamingLineBuffer_0_buffer_stream[9].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_12;
    StreamingLineBuffer_0_pixel_12.run<14>(StreamingLineBuffer_0_buffer_stream[8], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_5," << StreamingLineBuffer_0_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_12," << StreamingLineBuffer_0_buffer_stream[12].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_13;
    StreamingLineBuffer_0_pixel_13.run<15>(StreamingLineBuffer_0_buffer_stream[9], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_4," << StreamingLineBuffer_0_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_13," << StreamingLineBuffer_0_buffer_stream[13].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_16;
    StreamingLineBuffer_0_pixel_16.run<18>(StreamingLineBuffer_0_buffer_stream[12], StreamingLineBuffer_0_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_1," << StreamingLineBuffer_0_out0_stream_prepad[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_17;
    StreamingLineBuffer_0_pixel_17.run<19>(StreamingLineBuffer_0_buffer_stream[13], StreamingLineBuffer_0_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_0," << StreamingLineBuffer_0_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
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
        4,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_0_pad;
    StreamingLineBuffer_0_pad.run<20>(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_15," << StreamingLineBuffer_0_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_16," << StreamingLineBuffer_0_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_17," << StreamingLineBuffer_0_out0_stream[17].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_0_weights[48][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=2 complete
    ap_int<16> StreamingConv_0_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=2 complete
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
        4  // W_PAR
    > StreamingConv_0;
    StreamingConv_0.run<21>(StreamingLineBuffer_0_out0_stream, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_0," << StreamingConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_1," << StreamingConv_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_2," << StreamingConv_0_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_3," << StreamingConv_0_out0_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<22>(StreamingConv_0_out0_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_0;
    StreamingLineBuffer_1_pixel_0.run<23>(TensorDuplicator_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[17], StreamingLineBuffer_1_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_17," << StreamingLineBuffer_1_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_0," << StreamingLineBuffer_1_buffer_stream[0].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_1;
    StreamingLineBuffer_1_pixel_1.run<24>(TensorDuplicator_0_out0_stream[3], StreamingLineBuffer_1_out0_stream_prepad[16], StreamingLineBuffer_1_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_16," << StreamingLineBuffer_1_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_1," << StreamingLineBuffer_1_buffer_stream[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_2;
    StreamingLineBuffer_1_pixel_2.run<25>(TensorDuplicator_0_out0_stream[2], StreamingLineBuffer_1_out0_stream_prepad[15], StreamingLineBuffer_1_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_15," << StreamingLineBuffer_1_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_4," << StreamingLineBuffer_1_buffer_stream[4].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_3;
    StreamingLineBuffer_1_pixel_3.run<26>(TensorDuplicator_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[14], StreamingLineBuffer_1_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_14," << StreamingLineBuffer_1_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_5," << StreamingLineBuffer_1_buffer_stream[5].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_4;
    StreamingLineBuffer_1_pixel_4.run<27>(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[13], StreamingLineBuffer_1_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_13," << StreamingLineBuffer_1_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_2," << StreamingLineBuffer_1_buffer_stream[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_5;
    StreamingLineBuffer_1_pixel_5.run<28>(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[12], StreamingLineBuffer_1_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_12," << StreamingLineBuffer_1_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_3," << StreamingLineBuffer_1_buffer_stream[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_8;
    StreamingLineBuffer_1_pixel_8.run<31>(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_9," << StreamingLineBuffer_1_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_10," << StreamingLineBuffer_1_buffer_stream[10].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_9;
    StreamingLineBuffer_1_pixel_9.run<32>(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_8," << StreamingLineBuffer_1_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_11," << StreamingLineBuffer_1_buffer_stream[11].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_6;
    StreamingLineBuffer_1_pixel_6.run<29>(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_11," << StreamingLineBuffer_1_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_6," << StreamingLineBuffer_1_buffer_stream[6].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_7;
    StreamingLineBuffer_1_pixel_7.run<30>(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_10," << StreamingLineBuffer_1_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_7," << StreamingLineBuffer_1_buffer_stream[7].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_14;
    StreamingLineBuffer_1_pixel_14.run<37>(StreamingLineBuffer_1_buffer_stream[10], StreamingLineBuffer_1_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_3," << StreamingLineBuffer_1_out0_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_15;
    StreamingLineBuffer_1_pixel_15.run<38>(StreamingLineBuffer_1_buffer_stream[11], StreamingLineBuffer_1_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_2," << StreamingLineBuffer_1_out0_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_10;
    StreamingLineBuffer_1_pixel_10.run<33>(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_7," << StreamingLineBuffer_1_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_8," << StreamingLineBuffer_1_buffer_stream[8].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_11;
    StreamingLineBuffer_1_pixel_11.run<34>(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_6," << StreamingLineBuffer_1_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_9," << StreamingLineBuffer_1_buffer_stream[9].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_12;
    StreamingLineBuffer_1_pixel_12.run<35>(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_5," << StreamingLineBuffer_1_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_12," << StreamingLineBuffer_1_buffer_stream[12].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_13;
    StreamingLineBuffer_1_pixel_13.run<36>(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_4," << StreamingLineBuffer_1_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_13," << StreamingLineBuffer_1_buffer_stream[13].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_16;
    StreamingLineBuffer_1_pixel_16.run<39>(StreamingLineBuffer_1_buffer_stream[12], StreamingLineBuffer_1_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_1," << StreamingLineBuffer_1_out0_stream_prepad[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_17;
    StreamingLineBuffer_1_pixel_17.run<40>(StreamingLineBuffer_1_buffer_stream[13], StreamingLineBuffer_1_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_0," << StreamingLineBuffer_1_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_1_pad;
    StreamingLineBuffer_1_pad.run<41>(StreamingLineBuffer_1_out0_stream_prepad, StreamingLineBuffer_1_out0_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_12," << StreamingLineBuffer_1_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_13," << StreamingLineBuffer_1_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_14," << StreamingLineBuffer_1_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_15," << StreamingLineBuffer_1_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_16," << StreamingLineBuffer_1_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_17," << StreamingLineBuffer_1_out0_stream[17].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_1_weights[64][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=2 complete
    ap_int<16> StreamingConv_1_biases[4][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
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
        4,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_1;
    StreamingConv_1.run<42>(StreamingLineBuffer_1_out0_stream, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_0," << StreamingConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_1," << StreamingConv_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_2," << StreamingConv_1_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_3," << StreamingConv_1_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_0;
    StreamingLineBuffer_2_pixel_0.run<43>(StreamingConv_1_out0_stream[0], StreamingLineBuffer_2_out0_stream_prepad[17], StreamingLineBuffer_2_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_17," << StreamingLineBuffer_2_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_0," << StreamingLineBuffer_2_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_1;
    StreamingLineBuffer_2_pixel_1.run<44>(StreamingConv_1_out0_stream[3], StreamingLineBuffer_2_out0_stream_prepad[16], StreamingLineBuffer_2_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_16," << StreamingLineBuffer_2_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_1," << StreamingLineBuffer_2_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_2;
    StreamingLineBuffer_2_pixel_2.run<45>(StreamingConv_1_out0_stream[2], StreamingLineBuffer_2_out0_stream_prepad[15], StreamingLineBuffer_2_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_15," << StreamingLineBuffer_2_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_4," << StreamingLineBuffer_2_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_3;
    StreamingLineBuffer_2_pixel_3.run<46>(StreamingConv_1_out0_stream[1], StreamingLineBuffer_2_out0_stream_prepad[14], StreamingLineBuffer_2_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_14," << StreamingLineBuffer_2_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_5," << StreamingLineBuffer_2_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_4;
    StreamingLineBuffer_2_pixel_4.run<47>(StreamingLineBuffer_2_buffer_stream[0], StreamingLineBuffer_2_out0_stream_prepad[13], StreamingLineBuffer_2_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_13," << StreamingLineBuffer_2_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_2," << StreamingLineBuffer_2_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_5;
    StreamingLineBuffer_2_pixel_5.run<48>(StreamingLineBuffer_2_buffer_stream[1], StreamingLineBuffer_2_out0_stream_prepad[12], StreamingLineBuffer_2_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_12," << StreamingLineBuffer_2_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_3," << StreamingLineBuffer_2_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_8;
    StreamingLineBuffer_2_pixel_8.run<51>(StreamingLineBuffer_2_buffer_stream[4], StreamingLineBuffer_2_out0_stream_prepad[9], StreamingLineBuffer_2_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_9," << StreamingLineBuffer_2_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_10," << StreamingLineBuffer_2_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_9;
    StreamingLineBuffer_2_pixel_9.run<52>(StreamingLineBuffer_2_buffer_stream[5], StreamingLineBuffer_2_out0_stream_prepad[8], StreamingLineBuffer_2_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_8," << StreamingLineBuffer_2_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_11," << StreamingLineBuffer_2_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_6;
    StreamingLineBuffer_2_pixel_6.run<49>(StreamingLineBuffer_2_buffer_stream[2], StreamingLineBuffer_2_out0_stream_prepad[11], StreamingLineBuffer_2_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_11," << StreamingLineBuffer_2_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_6," << StreamingLineBuffer_2_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_7;
    StreamingLineBuffer_2_pixel_7.run<50>(StreamingLineBuffer_2_buffer_stream[3], StreamingLineBuffer_2_out0_stream_prepad[10], StreamingLineBuffer_2_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_10," << StreamingLineBuffer_2_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_7," << StreamingLineBuffer_2_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_14;
    StreamingLineBuffer_2_pixel_14.run<57>(StreamingLineBuffer_2_buffer_stream[10], StreamingLineBuffer_2_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_3," << StreamingLineBuffer_2_out0_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_15;
    StreamingLineBuffer_2_pixel_15.run<58>(StreamingLineBuffer_2_buffer_stream[11], StreamingLineBuffer_2_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_2," << StreamingLineBuffer_2_out0_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_10;
    StreamingLineBuffer_2_pixel_10.run<53>(StreamingLineBuffer_2_buffer_stream[6], StreamingLineBuffer_2_out0_stream_prepad[7], StreamingLineBuffer_2_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_7," << StreamingLineBuffer_2_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_8," << StreamingLineBuffer_2_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_11;
    StreamingLineBuffer_2_pixel_11.run<54>(StreamingLineBuffer_2_buffer_stream[7], StreamingLineBuffer_2_out0_stream_prepad[6], StreamingLineBuffer_2_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_6," << StreamingLineBuffer_2_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_9," << StreamingLineBuffer_2_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_12;
    StreamingLineBuffer_2_pixel_12.run<55>(StreamingLineBuffer_2_buffer_stream[8], StreamingLineBuffer_2_out0_stream_prepad[5], StreamingLineBuffer_2_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_5," << StreamingLineBuffer_2_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_12," << StreamingLineBuffer_2_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // POS_W
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_13;
    StreamingLineBuffer_2_pixel_13.run<56>(StreamingLineBuffer_2_buffer_stream[9], StreamingLineBuffer_2_out0_stream_prepad[4], StreamingLineBuffer_2_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_4," << StreamingLineBuffer_2_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_13," << StreamingLineBuffer_2_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_16;
    StreamingLineBuffer_2_pixel_16.run<59>(StreamingLineBuffer_2_buffer_stream[12], StreamingLineBuffer_2_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_1," << StreamingLineBuffer_2_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_2_pixel_17;
    StreamingLineBuffer_2_pixel_17.run<60>(StreamingLineBuffer_2_buffer_stream[13], StreamingLineBuffer_2_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_0," << StreamingLineBuffer_2_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 4>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        4,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_2_pad;
    StreamingLineBuffer_2_pad.run<61>(StreamingLineBuffer_2_out0_stream_prepad, StreamingLineBuffer_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_0," << StreamingLineBuffer_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_1," << StreamingLineBuffer_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_2," << StreamingLineBuffer_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_3," << StreamingLineBuffer_2_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_4," << StreamingLineBuffer_2_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_5," << StreamingLineBuffer_2_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_6," << StreamingLineBuffer_2_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_7," << StreamingLineBuffer_2_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_8," << StreamingLineBuffer_2_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_9," << StreamingLineBuffer_2_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_10," << StreamingLineBuffer_2_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_11," << StreamingLineBuffer_2_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_12," << StreamingLineBuffer_2_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_13," << StreamingLineBuffer_2_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_14," << StreamingLineBuffer_2_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_15," << StreamingLineBuffer_2_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_16," << StreamingLineBuffer_2_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_17," << StreamingLineBuffer_2_out0_stream[17].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_2_weights[64][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=2 complete
    ap_int<16> StreamingConv_2_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 4>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
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
        4,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_2;
    StreamingConv_2.run<62>(StreamingLineBuffer_2_out0_stream, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_0," << StreamingConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_1," << StreamingConv_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_2," << StreamingConv_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_3," << StreamingConv_2_out0_stream[3].size() << std::endl;
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
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_uint<8>>,  // AlignB
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        4,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_0;
    StreamingAdd_0.run<63>(StreamingConv_2_out0_stream, TensorDuplicator_0_out1_stream, StreamingAdd_0_out0_stream);
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
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<64>(StreamingAdd_0_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_0," << TensorDuplicator_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_1," << TensorDuplicator_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_2," << TensorDuplicator_1_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out0_stream_3," << TensorDuplicator_1_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_0," << TensorDuplicator_1_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_1," << TensorDuplicator_1_out1_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_2," << TensorDuplicator_1_out1_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_1_out1_stream_3," << TensorDuplicator_1_out1_stream[3].size() << std::endl;
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_0;
    StreamingLineBuffer_3_pixel_0.run<65>(TensorDuplicator_1_out0_stream[3], StreamingLineBuffer_3_out0_stream_prepad[26], StreamingLineBuffer_3_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_26," << StreamingLineBuffer_3_out0_stream_prepad[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_0," << StreamingLineBuffer_3_buffer_stream[0].size() << std::endl;
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_1;
    StreamingLineBuffer_3_pixel_1.run<66>(TensorDuplicator_1_out0_stream[2], StreamingLineBuffer_3_out0_stream_prepad[25], StreamingLineBuffer_3_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_25," << StreamingLineBuffer_3_out0_stream_prepad[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_1," << StreamingLineBuffer_3_buffer_stream[1].size() << std::endl;
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_2;
    StreamingLineBuffer_3_pixel_2.run<67>(TensorDuplicator_1_out0_stream[1], StreamingLineBuffer_3_out0_stream_prepad[24], StreamingLineBuffer_3_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_24," << StreamingLineBuffer_3_out0_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_2," << StreamingLineBuffer_3_buffer_stream[2].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_3;
    StreamingLineBuffer_3_pixel_3.run<68>(TensorDuplicator_1_out0_stream[0], StreamingLineBuffer_3_out0_stream_prepad[23], StreamingLineBuffer_3_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_23," << StreamingLineBuffer_3_out0_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_3," << StreamingLineBuffer_3_buffer_stream[3].size() << std::endl;
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_0;
    StreamingLineBuffer_4_pixel_0.run<93>(TensorDuplicator_1_out1_stream[2], StreamingLineBuffer_4_out0_stream[6], StreamingLineBuffer_4_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_6," << StreamingLineBuffer_4_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_0," << StreamingLineBuffer_4_buffer_stream[0].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_1;
    StreamingLineBuffer_4_pixel_1.run<94>(TensorDuplicator_1_out1_stream[1], StreamingLineBuffer_4_out0_stream[5], StreamingLineBuffer_4_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_5," << StreamingLineBuffer_4_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_1," << StreamingLineBuffer_4_buffer_stream[1].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_2;
    StreamingLineBuffer_4_pixel_2.run<95>(TensorDuplicator_1_out1_stream[0], StreamingLineBuffer_4_out0_stream[4], StreamingLineBuffer_4_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_4," << StreamingLineBuffer_4_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_2," << StreamingLineBuffer_4_buffer_stream[2].size() << std::endl;
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
        3,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_3;
    StreamingLineBuffer_4_pixel_3.run<96>(TensorDuplicator_1_out1_stream[3], StreamingLineBuffer_4_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_3," << StreamingLineBuffer_4_out0_stream[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_4;
    StreamingLineBuffer_3_pixel_4.run<69>(StreamingLineBuffer_3_buffer_stream[0], StreamingLineBuffer_3_out0_stream_prepad[22], StreamingLineBuffer_3_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_22," << StreamingLineBuffer_3_out0_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_4," << StreamingLineBuffer_3_buffer_stream[4].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_5;
    StreamingLineBuffer_3_pixel_5.run<70>(StreamingLineBuffer_3_buffer_stream[1], StreamingLineBuffer_3_out0_stream_prepad[21], StreamingLineBuffer_3_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_21," << StreamingLineBuffer_3_out0_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_6," << StreamingLineBuffer_3_buffer_stream[6].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_6;
    StreamingLineBuffer_3_pixel_6.run<71>(StreamingLineBuffer_3_buffer_stream[2], StreamingLineBuffer_3_out0_stream_prepad[20], StreamingLineBuffer_3_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_20," << StreamingLineBuffer_3_out0_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_7," << StreamingLineBuffer_3_buffer_stream[7].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_7;
    StreamingLineBuffer_3_pixel_7.run<72>(StreamingLineBuffer_3_buffer_stream[3], StreamingLineBuffer_3_out0_stream_prepad[19], StreamingLineBuffer_3_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_19," << StreamingLineBuffer_3_out0_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_8," << StreamingLineBuffer_3_buffer_stream[8].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_4;
    StreamingLineBuffer_4_pixel_4.run<97>(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_2," << StreamingLineBuffer_4_out0_stream[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_5;
    StreamingLineBuffer_4_pixel_5.run<98>(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_1," << StreamingLineBuffer_4_out0_stream[1].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_4_pixel_6;
    StreamingLineBuffer_4_pixel_6.run<99>(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_0," << StreamingLineBuffer_4_out0_stream[0].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_8;
    StreamingLineBuffer_3_pixel_8.run<73>(StreamingLineBuffer_3_buffer_stream[4], StreamingLineBuffer_3_out0_stream_prepad[18], StreamingLineBuffer_3_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_18," << StreamingLineBuffer_3_out0_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_5," << StreamingLineBuffer_3_buffer_stream[5].size() << std::endl;
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_10;
    StreamingLineBuffer_3_pixel_10.run<75>(StreamingLineBuffer_3_buffer_stream[6], StreamingLineBuffer_3_out0_stream_prepad[16], StreamingLineBuffer_3_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_16," << StreamingLineBuffer_3_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_10," << StreamingLineBuffer_3_buffer_stream[10].size() << std::endl;
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_11;
    StreamingLineBuffer_3_pixel_11.run<76>(StreamingLineBuffer_3_buffer_stream[7], StreamingLineBuffer_3_out0_stream_prepad[15], StreamingLineBuffer_3_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_15," << StreamingLineBuffer_3_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_11," << StreamingLineBuffer_3_buffer_stream[11].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_12;
    StreamingLineBuffer_3_pixel_12.run<77>(StreamingLineBuffer_3_buffer_stream[8], StreamingLineBuffer_3_out0_stream_prepad[14], StreamingLineBuffer_3_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_14," << StreamingLineBuffer_3_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_12," << StreamingLineBuffer_3_buffer_stream[12].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_4_weights[256][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=2 complete
    ap_int<16> StreamingConv_4_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
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
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_4;
    StreamingConv_4.run<101>(StreamingLineBuffer_4_out0_stream, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_4_out0_stream);
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_9;
    StreamingLineBuffer_3_pixel_9.run<74>(StreamingLineBuffer_3_buffer_stream[5], StreamingLineBuffer_3_out0_stream_prepad[17], StreamingLineBuffer_3_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_17," << StreamingLineBuffer_3_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_9," << StreamingLineBuffer_3_buffer_stream[9].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_14;
    StreamingLineBuffer_3_pixel_14.run<79>(StreamingLineBuffer_3_buffer_stream[10], StreamingLineBuffer_3_out0_stream_prepad[12], StreamingLineBuffer_3_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_12," << StreamingLineBuffer_3_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_15," << StreamingLineBuffer_3_buffer_stream[15].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_15;
    StreamingLineBuffer_3_pixel_15.run<80>(StreamingLineBuffer_3_buffer_stream[11], StreamingLineBuffer_3_out0_stream_prepad[11], StreamingLineBuffer_3_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_11," << StreamingLineBuffer_3_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_16," << StreamingLineBuffer_3_buffer_stream[16].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_16;
    StreamingLineBuffer_3_pixel_16.run<81>(StreamingLineBuffer_3_buffer_stream[12], StreamingLineBuffer_3_out0_stream_prepad[10], StreamingLineBuffer_3_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_10," << StreamingLineBuffer_3_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_17," << StreamingLineBuffer_3_buffer_stream[17].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_13;
    StreamingLineBuffer_3_pixel_13.run<78>(StreamingLineBuffer_3_buffer_stream[9], StreamingLineBuffer_3_out0_stream_prepad[13], StreamingLineBuffer_3_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_13," << StreamingLineBuffer_3_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_13," << StreamingLineBuffer_3_buffer_stream[13].size() << std::endl;
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
        7,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_19;
    StreamingLineBuffer_3_pixel_19.run<84>(StreamingLineBuffer_3_buffer_stream[15], StreamingLineBuffer_3_out0_stream_prepad[7], StreamingLineBuffer_3_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_7," << StreamingLineBuffer_3_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_19," << StreamingLineBuffer_3_buffer_stream[19].size() << std::endl;
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
        6,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_20;
    StreamingLineBuffer_3_pixel_20.run<85>(StreamingLineBuffer_3_buffer_stream[16], StreamingLineBuffer_3_out0_stream_prepad[6], StreamingLineBuffer_3_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_6," << StreamingLineBuffer_3_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_20," << StreamingLineBuffer_3_buffer_stream[20].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_21;
    StreamingLineBuffer_3_pixel_21.run<86>(StreamingLineBuffer_3_buffer_stream[17], StreamingLineBuffer_3_out0_stream_prepad[5], StreamingLineBuffer_3_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_5," << StreamingLineBuffer_3_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_21," << StreamingLineBuffer_3_buffer_stream[21].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_17;
    StreamingLineBuffer_3_pixel_17.run<82>(StreamingLineBuffer_3_buffer_stream[13], StreamingLineBuffer_3_out0_stream_prepad[9], StreamingLineBuffer_3_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_9," << StreamingLineBuffer_3_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_14," << StreamingLineBuffer_3_buffer_stream[14].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_23;
    StreamingLineBuffer_3_pixel_23.run<88>(StreamingLineBuffer_3_buffer_stream[19], StreamingLineBuffer_3_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_3," << StreamingLineBuffer_3_out0_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_24;
    StreamingLineBuffer_3_pixel_24.run<89>(StreamingLineBuffer_3_buffer_stream[20], StreamingLineBuffer_3_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_2," << StreamingLineBuffer_3_out0_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_25;
    StreamingLineBuffer_3_pixel_25.run<90>(StreamingLineBuffer_3_buffer_stream[21], StreamingLineBuffer_3_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_1," << StreamingLineBuffer_3_out0_stream_prepad[1].size() << std::endl;
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
        8,  // POS_W
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_18;
    StreamingLineBuffer_3_pixel_18.run<83>(StreamingLineBuffer_3_buffer_stream[14], StreamingLineBuffer_3_out0_stream_prepad[8], StreamingLineBuffer_3_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_8," << StreamingLineBuffer_3_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_18," << StreamingLineBuffer_3_buffer_stream[18].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_22;
    StreamingLineBuffer_3_pixel_22.run<87>(StreamingLineBuffer_3_buffer_stream[18], StreamingLineBuffer_3_out0_stream_prepad[4], StreamingLineBuffer_3_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_4," << StreamingLineBuffer_3_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_22," << StreamingLineBuffer_3_buffer_stream[22].size() << std::endl;
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
        4,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_3_pixel_26;
    StreamingLineBuffer_3_pixel_26.run<91>(StreamingLineBuffer_3_buffer_stream[22], StreamingLineBuffer_3_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_0," << StreamingLineBuffer_3_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_3_pad;
    StreamingLineBuffer_3_pad.run<92>(StreamingLineBuffer_3_out0_stream_prepad, StreamingLineBuffer_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_0," << StreamingLineBuffer_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_1," << StreamingLineBuffer_3_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_2," << StreamingLineBuffer_3_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_3," << StreamingLineBuffer_3_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_4," << StreamingLineBuffer_3_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_5," << StreamingLineBuffer_3_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_6," << StreamingLineBuffer_3_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_7," << StreamingLineBuffer_3_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_8," << StreamingLineBuffer_3_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_9," << StreamingLineBuffer_3_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_10," << StreamingLineBuffer_3_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_11," << StreamingLineBuffer_3_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_12," << StreamingLineBuffer_3_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_13," << StreamingLineBuffer_3_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_14," << StreamingLineBuffer_3_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_15," << StreamingLineBuffer_3_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_16," << StreamingLineBuffer_3_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_17," << StreamingLineBuffer_3_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_18," << StreamingLineBuffer_3_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_19," << StreamingLineBuffer_3_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_20," << StreamingLineBuffer_3_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_21," << StreamingLineBuffer_3_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_22," << StreamingLineBuffer_3_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_23," << StreamingLineBuffer_3_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_24," << StreamingLineBuffer_3_out0_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_25," << StreamingLineBuffer_3_out0_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_26," << StreamingLineBuffer_3_out0_stream[26].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_3_weights[256][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=2 complete
    ap_int<16> StreamingConv_3_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=2 complete
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
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_3;
    StreamingConv_3.run<100>(StreamingLineBuffer_3_out0_stream, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_3_out0_stream);
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_0;
    StreamingLineBuffer_5_pixel_0.run<102>(StreamingConv_3_out0_stream[0], StreamingLineBuffer_5_out0_stream_prepad[17], StreamingLineBuffer_5_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_17," << StreamingLineBuffer_5_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_0," << StreamingLineBuffer_5_buffer_stream[0].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_1;
    StreamingLineBuffer_5_pixel_1.run<103>(StreamingConv_3_out0_stream[3], StreamingLineBuffer_5_out0_stream_prepad[16], StreamingLineBuffer_5_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_16," << StreamingLineBuffer_5_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_1," << StreamingLineBuffer_5_buffer_stream[1].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_2;
    StreamingLineBuffer_5_pixel_2.run<104>(StreamingConv_3_out0_stream[2], StreamingLineBuffer_5_out0_stream_prepad[15], StreamingLineBuffer_5_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_15," << StreamingLineBuffer_5_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_4," << StreamingLineBuffer_5_buffer_stream[4].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_3;
    StreamingLineBuffer_5_pixel_3.run<105>(StreamingConv_3_out0_stream[1], StreamingLineBuffer_5_out0_stream_prepad[14], StreamingLineBuffer_5_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_14," << StreamingLineBuffer_5_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_5," << StreamingLineBuffer_5_buffer_stream[5].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_4;
    StreamingLineBuffer_5_pixel_4.run<106>(StreamingLineBuffer_5_buffer_stream[0], StreamingLineBuffer_5_out0_stream_prepad[13], StreamingLineBuffer_5_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_13," << StreamingLineBuffer_5_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_2," << StreamingLineBuffer_5_buffer_stream[2].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_5;
    StreamingLineBuffer_5_pixel_5.run<107>(StreamingLineBuffer_5_buffer_stream[1], StreamingLineBuffer_5_out0_stream_prepad[12], StreamingLineBuffer_5_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_12," << StreamingLineBuffer_5_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_3," << StreamingLineBuffer_5_buffer_stream[3].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_8;
    StreamingLineBuffer_5_pixel_8.run<110>(StreamingLineBuffer_5_buffer_stream[4], StreamingLineBuffer_5_out0_stream_prepad[9], StreamingLineBuffer_5_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_9," << StreamingLineBuffer_5_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_10," << StreamingLineBuffer_5_buffer_stream[10].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_9;
    StreamingLineBuffer_5_pixel_9.run<111>(StreamingLineBuffer_5_buffer_stream[5], StreamingLineBuffer_5_out0_stream_prepad[8], StreamingLineBuffer_5_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_8," << StreamingLineBuffer_5_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_11," << StreamingLineBuffer_5_buffer_stream[11].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_6;
    StreamingLineBuffer_5_pixel_6.run<108>(StreamingLineBuffer_5_buffer_stream[2], StreamingLineBuffer_5_out0_stream_prepad[11], StreamingLineBuffer_5_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_11," << StreamingLineBuffer_5_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_6," << StreamingLineBuffer_5_buffer_stream[6].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_7;
    StreamingLineBuffer_5_pixel_7.run<109>(StreamingLineBuffer_5_buffer_stream[3], StreamingLineBuffer_5_out0_stream_prepad[10], StreamingLineBuffer_5_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_10," << StreamingLineBuffer_5_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_7," << StreamingLineBuffer_5_buffer_stream[7].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_14;
    StreamingLineBuffer_5_pixel_14.run<116>(StreamingLineBuffer_5_buffer_stream[10], StreamingLineBuffer_5_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_3," << StreamingLineBuffer_5_out0_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_15;
    StreamingLineBuffer_5_pixel_15.run<117>(StreamingLineBuffer_5_buffer_stream[11], StreamingLineBuffer_5_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_2," << StreamingLineBuffer_5_out0_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_10;
    StreamingLineBuffer_5_pixel_10.run<112>(StreamingLineBuffer_5_buffer_stream[6], StreamingLineBuffer_5_out0_stream_prepad[7], StreamingLineBuffer_5_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_7," << StreamingLineBuffer_5_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_8," << StreamingLineBuffer_5_buffer_stream[8].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_11;
    StreamingLineBuffer_5_pixel_11.run<113>(StreamingLineBuffer_5_buffer_stream[7], StreamingLineBuffer_5_out0_stream_prepad[6], StreamingLineBuffer_5_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_6," << StreamingLineBuffer_5_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_9," << StreamingLineBuffer_5_buffer_stream[9].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_12;
    StreamingLineBuffer_5_pixel_12.run<114>(StreamingLineBuffer_5_buffer_stream[8], StreamingLineBuffer_5_out0_stream_prepad[5], StreamingLineBuffer_5_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_5," << StreamingLineBuffer_5_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_12," << StreamingLineBuffer_5_buffer_stream[12].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_13;
    StreamingLineBuffer_5_pixel_13.run<115>(StreamingLineBuffer_5_buffer_stream[9], StreamingLineBuffer_5_out0_stream_prepad[4], StreamingLineBuffer_5_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_4," << StreamingLineBuffer_5_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_13," << StreamingLineBuffer_5_buffer_stream[13].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_16;
    StreamingLineBuffer_5_pixel_16.run<118>(StreamingLineBuffer_5_buffer_stream[12], StreamingLineBuffer_5_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_1," << StreamingLineBuffer_5_out0_stream_prepad[1].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_5_pixel_17;
    StreamingLineBuffer_5_pixel_17.run<119>(StreamingLineBuffer_5_buffer_stream[13], StreamingLineBuffer_5_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_0," << StreamingLineBuffer_5_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_5_pad;
    StreamingLineBuffer_5_pad.run<120>(StreamingLineBuffer_5_out0_stream_prepad, StreamingLineBuffer_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_0," << StreamingLineBuffer_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_1," << StreamingLineBuffer_5_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_2," << StreamingLineBuffer_5_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_3," << StreamingLineBuffer_5_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_4," << StreamingLineBuffer_5_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_5," << StreamingLineBuffer_5_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_6," << StreamingLineBuffer_5_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_7," << StreamingLineBuffer_5_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_8," << StreamingLineBuffer_5_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_9," << StreamingLineBuffer_5_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_10," << StreamingLineBuffer_5_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_11," << StreamingLineBuffer_5_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_12," << StreamingLineBuffer_5_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_13," << StreamingLineBuffer_5_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_14," << StreamingLineBuffer_5_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_15," << StreamingLineBuffer_5_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_16," << StreamingLineBuffer_5_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_17," << StreamingLineBuffer_5_out0_stream[17].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_5_weights[256][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=2 complete
    ap_int<16> StreamingConv_5_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
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
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_5;
    StreamingConv_5.run<121>(StreamingLineBuffer_5_out0_stream, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_5_out0_stream);
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
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 2>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<9>,  // TAcc
        ReLU<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        4,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_1;
    StreamingAdd_1.run<122>(StreamingConv_5_out0_stream, StreamingConv_4_out0_stream, StreamingAdd_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_0," << StreamingAdd_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_1," << StreamingAdd_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_2," << StreamingAdd_1_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_3," << StreamingAdd_1_out0_stream[3].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<123>(StreamingAdd_1_out0_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_0," << TensorDuplicator_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_1," << TensorDuplicator_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_2," << TensorDuplicator_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out0_stream_3," << TensorDuplicator_2_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_0," << TensorDuplicator_2_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_1," << TensorDuplicator_2_out1_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_2," << TensorDuplicator_2_out1_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_2_out1_stream_3," << TensorDuplicator_2_out1_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_0;
    StreamingLineBuffer_6_pixel_0.run<124>(TensorDuplicator_2_out0_stream[3], StreamingLineBuffer_6_out0_stream_prepad[26], StreamingLineBuffer_6_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_26," << StreamingLineBuffer_6_out0_stream_prepad[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_0," << StreamingLineBuffer_6_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_1;
    StreamingLineBuffer_6_pixel_1.run<125>(TensorDuplicator_2_out0_stream[2], StreamingLineBuffer_6_out0_stream_prepad[25], StreamingLineBuffer_6_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_25," << StreamingLineBuffer_6_out0_stream_prepad[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_1," << StreamingLineBuffer_6_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_2;
    StreamingLineBuffer_6_pixel_2.run<126>(TensorDuplicator_2_out0_stream[1], StreamingLineBuffer_6_out0_stream_prepad[24], StreamingLineBuffer_6_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_24," << StreamingLineBuffer_6_out0_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_2," << StreamingLineBuffer_6_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_3;
    StreamingLineBuffer_6_pixel_3.run<127>(TensorDuplicator_2_out0_stream[0], StreamingLineBuffer_6_out0_stream_prepad[23], StreamingLineBuffer_6_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_23," << StreamingLineBuffer_6_out0_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_3," << StreamingLineBuffer_6_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_0;
    StreamingLineBuffer_7_pixel_0.run<152>(TensorDuplicator_2_out1_stream[2], StreamingLineBuffer_7_out0_stream[6], StreamingLineBuffer_7_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_6," << StreamingLineBuffer_7_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_0," << StreamingLineBuffer_7_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_1;
    StreamingLineBuffer_7_pixel_1.run<153>(TensorDuplicator_2_out1_stream[1], StreamingLineBuffer_7_out0_stream[5], StreamingLineBuffer_7_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_5," << StreamingLineBuffer_7_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_1," << StreamingLineBuffer_7_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_2;
    StreamingLineBuffer_7_pixel_2.run<154>(TensorDuplicator_2_out1_stream[0], StreamingLineBuffer_7_out0_stream[4], StreamingLineBuffer_7_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_4," << StreamingLineBuffer_7_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_2," << StreamingLineBuffer_7_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        3,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_3;
    StreamingLineBuffer_7_pixel_3.run<155>(TensorDuplicator_2_out1_stream[3], StreamingLineBuffer_7_out0_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_3," << StreamingLineBuffer_7_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_4;
    StreamingLineBuffer_6_pixel_4.run<128>(StreamingLineBuffer_6_buffer_stream[0], StreamingLineBuffer_6_out0_stream_prepad[22], StreamingLineBuffer_6_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_22," << StreamingLineBuffer_6_out0_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_4," << StreamingLineBuffer_6_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_5;
    StreamingLineBuffer_6_pixel_5.run<129>(StreamingLineBuffer_6_buffer_stream[1], StreamingLineBuffer_6_out0_stream_prepad[21], StreamingLineBuffer_6_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_21," << StreamingLineBuffer_6_out0_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_6," << StreamingLineBuffer_6_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_6;
    StreamingLineBuffer_6_pixel_6.run<130>(StreamingLineBuffer_6_buffer_stream[2], StreamingLineBuffer_6_out0_stream_prepad[20], StreamingLineBuffer_6_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_20," << StreamingLineBuffer_6_out0_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_7," << StreamingLineBuffer_6_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_7;
    StreamingLineBuffer_6_pixel_7.run<131>(StreamingLineBuffer_6_buffer_stream[3], StreamingLineBuffer_6_out0_stream_prepad[19], StreamingLineBuffer_6_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_19," << StreamingLineBuffer_6_out0_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_8," << StreamingLineBuffer_6_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_4;
    StreamingLineBuffer_7_pixel_4.run<156>(StreamingLineBuffer_7_buffer_stream[0], StreamingLineBuffer_7_out0_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_2," << StreamingLineBuffer_7_out0_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_5;
    StreamingLineBuffer_7_pixel_5.run<157>(StreamingLineBuffer_7_buffer_stream[1], StreamingLineBuffer_7_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_1," << StreamingLineBuffer_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_6;
    StreamingLineBuffer_7_pixel_6.run<158>(StreamingLineBuffer_7_buffer_stream[2], StreamingLineBuffer_7_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_0," << StreamingLineBuffer_7_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_8;
    StreamingLineBuffer_6_pixel_8.run<132>(StreamingLineBuffer_6_buffer_stream[4], StreamingLineBuffer_6_out0_stream_prepad[18], StreamingLineBuffer_6_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_18," << StreamingLineBuffer_6_out0_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_5," << StreamingLineBuffer_6_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_10;
    StreamingLineBuffer_6_pixel_10.run<134>(StreamingLineBuffer_6_buffer_stream[6], StreamingLineBuffer_6_out0_stream_prepad[16], StreamingLineBuffer_6_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_16," << StreamingLineBuffer_6_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_10," << StreamingLineBuffer_6_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_11;
    StreamingLineBuffer_6_pixel_11.run<135>(StreamingLineBuffer_6_buffer_stream[7], StreamingLineBuffer_6_out0_stream_prepad[15], StreamingLineBuffer_6_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_15," << StreamingLineBuffer_6_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_11," << StreamingLineBuffer_6_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_12;
    StreamingLineBuffer_6_pixel_12.run<136>(StreamingLineBuffer_6_buffer_stream[8], StreamingLineBuffer_6_out0_stream_prepad[14], StreamingLineBuffer_6_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_14," << StreamingLineBuffer_6_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_12," << StreamingLineBuffer_6_buffer_stream[12].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_7_weights[512][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=2 complete
    ap_int<16> StreamingConv_7_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
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
        2,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_7;
    StreamingConv_7.run<160>(StreamingLineBuffer_7_out0_stream, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_0," << StreamingConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_1," << StreamingConv_7_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_2," << StreamingConv_7_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_3," << StreamingConv_7_out0_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_9;
    StreamingLineBuffer_6_pixel_9.run<133>(StreamingLineBuffer_6_buffer_stream[5], StreamingLineBuffer_6_out0_stream_prepad[17], StreamingLineBuffer_6_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_17," << StreamingLineBuffer_6_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_9," << StreamingLineBuffer_6_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_14;
    StreamingLineBuffer_6_pixel_14.run<138>(StreamingLineBuffer_6_buffer_stream[10], StreamingLineBuffer_6_out0_stream_prepad[12], StreamingLineBuffer_6_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_12," << StreamingLineBuffer_6_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_15," << StreamingLineBuffer_6_buffer_stream[15].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_15;
    StreamingLineBuffer_6_pixel_15.run<139>(StreamingLineBuffer_6_buffer_stream[11], StreamingLineBuffer_6_out0_stream_prepad[11], StreamingLineBuffer_6_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_11," << StreamingLineBuffer_6_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_16," << StreamingLineBuffer_6_buffer_stream[16].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_16;
    StreamingLineBuffer_6_pixel_16.run<140>(StreamingLineBuffer_6_buffer_stream[12], StreamingLineBuffer_6_out0_stream_prepad[10], StreamingLineBuffer_6_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_10," << StreamingLineBuffer_6_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_17," << StreamingLineBuffer_6_buffer_stream[17].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_13;
    StreamingLineBuffer_6_pixel_13.run<137>(StreamingLineBuffer_6_buffer_stream[9], StreamingLineBuffer_6_out0_stream_prepad[13], StreamingLineBuffer_6_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_13," << StreamingLineBuffer_6_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_13," << StreamingLineBuffer_6_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        7,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_19;
    StreamingLineBuffer_6_pixel_19.run<143>(StreamingLineBuffer_6_buffer_stream[15], StreamingLineBuffer_6_out0_stream_prepad[7], StreamingLineBuffer_6_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_7," << StreamingLineBuffer_6_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_19," << StreamingLineBuffer_6_buffer_stream[19].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        6,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_20;
    StreamingLineBuffer_6_pixel_20.run<144>(StreamingLineBuffer_6_buffer_stream[16], StreamingLineBuffer_6_out0_stream_prepad[6], StreamingLineBuffer_6_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_6," << StreamingLineBuffer_6_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_20," << StreamingLineBuffer_6_buffer_stream[20].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_21;
    StreamingLineBuffer_6_pixel_21.run<145>(StreamingLineBuffer_6_buffer_stream[17], StreamingLineBuffer_6_out0_stream_prepad[5], StreamingLineBuffer_6_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_5," << StreamingLineBuffer_6_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_21," << StreamingLineBuffer_6_buffer_stream[21].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_17;
    StreamingLineBuffer_6_pixel_17.run<141>(StreamingLineBuffer_6_buffer_stream[13], StreamingLineBuffer_6_out0_stream_prepad[9], StreamingLineBuffer_6_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_9," << StreamingLineBuffer_6_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_14," << StreamingLineBuffer_6_buffer_stream[14].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_23;
    StreamingLineBuffer_6_pixel_23.run<147>(StreamingLineBuffer_6_buffer_stream[19], StreamingLineBuffer_6_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_3," << StreamingLineBuffer_6_out0_stream_prepad[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_24;
    StreamingLineBuffer_6_pixel_24.run<148>(StreamingLineBuffer_6_buffer_stream[20], StreamingLineBuffer_6_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_2," << StreamingLineBuffer_6_out0_stream_prepad[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_25;
    StreamingLineBuffer_6_pixel_25.run<149>(StreamingLineBuffer_6_buffer_stream[21], StreamingLineBuffer_6_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_1," << StreamingLineBuffer_6_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        8,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_18;
    StreamingLineBuffer_6_pixel_18.run<142>(StreamingLineBuffer_6_buffer_stream[14], StreamingLineBuffer_6_out0_stream_prepad[8], StreamingLineBuffer_6_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_8," << StreamingLineBuffer_6_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_18," << StreamingLineBuffer_6_buffer_stream[18].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_22;
    StreamingLineBuffer_6_pixel_22.run<146>(StreamingLineBuffer_6_buffer_stream[18], StreamingLineBuffer_6_out0_stream_prepad[4], StreamingLineBuffer_6_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_4," << StreamingLineBuffer_6_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_22," << StreamingLineBuffer_6_buffer_stream[22].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_6_pixel_26;
    StreamingLineBuffer_6_pixel_26.run<150>(StreamingLineBuffer_6_buffer_stream[22], StreamingLineBuffer_6_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_0," << StreamingLineBuffer_6_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_6_pad;
    StreamingLineBuffer_6_pad.run<151>(StreamingLineBuffer_6_out0_stream_prepad, StreamingLineBuffer_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_0," << StreamingLineBuffer_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_1," << StreamingLineBuffer_6_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_2," << StreamingLineBuffer_6_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_3," << StreamingLineBuffer_6_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_4," << StreamingLineBuffer_6_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_5," << StreamingLineBuffer_6_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_6," << StreamingLineBuffer_6_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_7," << StreamingLineBuffer_6_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_8," << StreamingLineBuffer_6_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_9," << StreamingLineBuffer_6_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_10," << StreamingLineBuffer_6_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_11," << StreamingLineBuffer_6_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_12," << StreamingLineBuffer_6_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_13," << StreamingLineBuffer_6_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_14," << StreamingLineBuffer_6_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_15," << StreamingLineBuffer_6_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_16," << StreamingLineBuffer_6_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_17," << StreamingLineBuffer_6_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_18," << StreamingLineBuffer_6_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_19," << StreamingLineBuffer_6_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_20," << StreamingLineBuffer_6_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_21," << StreamingLineBuffer_6_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_22," << StreamingLineBuffer_6_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_23," << StreamingLineBuffer_6_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_24," << StreamingLineBuffer_6_out0_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_25," << StreamingLineBuffer_6_out0_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_26," << StreamingLineBuffer_6_out0_stream[26].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_6_weights[512][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=2 complete
    ap_int<16> StreamingConv_6_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
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
        2,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_6;
    StreamingConv_6.run<159>(StreamingLineBuffer_6_out0_stream, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_6_out0_stream);
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_0;
    StreamingLineBuffer_8_pixel_0.run<161>(StreamingConv_6_out0_stream[0], StreamingLineBuffer_8_out0_stream_prepad[17], StreamingLineBuffer_8_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_17," << StreamingLineBuffer_8_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_0," << StreamingLineBuffer_8_buffer_stream[0].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_1;
    StreamingLineBuffer_8_pixel_1.run<162>(StreamingConv_6_out0_stream[3], StreamingLineBuffer_8_out0_stream_prepad[16], StreamingLineBuffer_8_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_16," << StreamingLineBuffer_8_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_1," << StreamingLineBuffer_8_buffer_stream[1].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_2;
    StreamingLineBuffer_8_pixel_2.run<163>(StreamingConv_6_out0_stream[2], StreamingLineBuffer_8_out0_stream_prepad[15], StreamingLineBuffer_8_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_15," << StreamingLineBuffer_8_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_4," << StreamingLineBuffer_8_buffer_stream[4].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_3;
    StreamingLineBuffer_8_pixel_3.run<164>(StreamingConv_6_out0_stream[1], StreamingLineBuffer_8_out0_stream_prepad[14], StreamingLineBuffer_8_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_14," << StreamingLineBuffer_8_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_5," << StreamingLineBuffer_8_buffer_stream[5].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_4;
    StreamingLineBuffer_8_pixel_4.run<165>(StreamingLineBuffer_8_buffer_stream[0], StreamingLineBuffer_8_out0_stream_prepad[13], StreamingLineBuffer_8_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_13," << StreamingLineBuffer_8_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_2," << StreamingLineBuffer_8_buffer_stream[2].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_5;
    StreamingLineBuffer_8_pixel_5.run<166>(StreamingLineBuffer_8_buffer_stream[1], StreamingLineBuffer_8_out0_stream_prepad[12], StreamingLineBuffer_8_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_12," << StreamingLineBuffer_8_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_3," << StreamingLineBuffer_8_buffer_stream[3].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_8;
    StreamingLineBuffer_8_pixel_8.run<169>(StreamingLineBuffer_8_buffer_stream[4], StreamingLineBuffer_8_out0_stream_prepad[9], StreamingLineBuffer_8_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_9," << StreamingLineBuffer_8_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_10," << StreamingLineBuffer_8_buffer_stream[10].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_9;
    StreamingLineBuffer_8_pixel_9.run<170>(StreamingLineBuffer_8_buffer_stream[5], StreamingLineBuffer_8_out0_stream_prepad[8], StreamingLineBuffer_8_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_8," << StreamingLineBuffer_8_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_11," << StreamingLineBuffer_8_buffer_stream[11].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_6;
    StreamingLineBuffer_8_pixel_6.run<167>(StreamingLineBuffer_8_buffer_stream[2], StreamingLineBuffer_8_out0_stream_prepad[11], StreamingLineBuffer_8_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_11," << StreamingLineBuffer_8_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_6," << StreamingLineBuffer_8_buffer_stream[6].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_7;
    StreamingLineBuffer_8_pixel_7.run<168>(StreamingLineBuffer_8_buffer_stream[3], StreamingLineBuffer_8_out0_stream_prepad[10], StreamingLineBuffer_8_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_10," << StreamingLineBuffer_8_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_7," << StreamingLineBuffer_8_buffer_stream[7].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_14;
    StreamingLineBuffer_8_pixel_14.run<175>(StreamingLineBuffer_8_buffer_stream[10], StreamingLineBuffer_8_out0_stream_prepad[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_3," << StreamingLineBuffer_8_out0_stream_prepad[3].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_15;
    StreamingLineBuffer_8_pixel_15.run<176>(StreamingLineBuffer_8_buffer_stream[11], StreamingLineBuffer_8_out0_stream_prepad[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_2," << StreamingLineBuffer_8_out0_stream_prepad[2].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_10;
    StreamingLineBuffer_8_pixel_10.run<171>(StreamingLineBuffer_8_buffer_stream[6], StreamingLineBuffer_8_out0_stream_prepad[7], StreamingLineBuffer_8_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_7," << StreamingLineBuffer_8_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_8," << StreamingLineBuffer_8_buffer_stream[8].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_11;
    StreamingLineBuffer_8_pixel_11.run<172>(StreamingLineBuffer_8_buffer_stream[7], StreamingLineBuffer_8_out0_stream_prepad[6], StreamingLineBuffer_8_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_6," << StreamingLineBuffer_8_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_9," << StreamingLineBuffer_8_buffer_stream[9].size() << std::endl;
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
        5,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_12;
    StreamingLineBuffer_8_pixel_12.run<173>(StreamingLineBuffer_8_buffer_stream[8], StreamingLineBuffer_8_out0_stream_prepad[5], StreamingLineBuffer_8_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_5," << StreamingLineBuffer_8_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_12," << StreamingLineBuffer_8_buffer_stream[12].size() << std::endl;
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
        4,  // POS_W
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_13;
    StreamingLineBuffer_8_pixel_13.run<174>(StreamingLineBuffer_8_buffer_stream[9], StreamingLineBuffer_8_out0_stream_prepad[4], StreamingLineBuffer_8_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_4," << StreamingLineBuffer_8_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_13," << StreamingLineBuffer_8_buffer_stream[13].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_16;
    StreamingLineBuffer_8_pixel_16.run<177>(StreamingLineBuffer_8_buffer_stream[12], StreamingLineBuffer_8_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_1," << StreamingLineBuffer_8_out0_stream_prepad[1].size() << std::endl;
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
        4,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_8_pixel_17;
    StreamingLineBuffer_8_pixel_17.run<178>(StreamingLineBuffer_8_buffer_stream[13], StreamingLineBuffer_8_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_0," << StreamingLineBuffer_8_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
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
        4,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_8_pad;
    StreamingLineBuffer_8_pad.run<179>(StreamingLineBuffer_8_out0_stream_prepad, StreamingLineBuffer_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_0," << StreamingLineBuffer_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_1," << StreamingLineBuffer_8_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_2," << StreamingLineBuffer_8_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_3," << StreamingLineBuffer_8_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_4," << StreamingLineBuffer_8_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_5," << StreamingLineBuffer_8_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_6," << StreamingLineBuffer_8_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_7," << StreamingLineBuffer_8_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_8," << StreamingLineBuffer_8_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_9," << StreamingLineBuffer_8_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_10," << StreamingLineBuffer_8_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_11," << StreamingLineBuffer_8_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_12," << StreamingLineBuffer_8_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_13," << StreamingLineBuffer_8_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_14," << StreamingLineBuffer_8_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_15," << StreamingLineBuffer_8_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_16," << StreamingLineBuffer_8_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_17," << StreamingLineBuffer_8_out0_stream[17].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_8_weights[1024][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=2 complete
    ap_int<16> StreamingConv_8_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
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
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_8;
    StreamingConv_8.run<180>(StreamingLineBuffer_8_out0_stream, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_0," << StreamingConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_1," << StreamingConv_8_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_2," << StreamingConv_8_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_3," << StreamingConv_8_out0_stream[3].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 2>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<9>,  // TAcc
        ReLU<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        4,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_2;
    StreamingAdd_2.run<181>(StreamingConv_8_out0_stream, StreamingConv_7_out0_stream, StreamingAdd_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_0," << StreamingAdd_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_1," << StreamingAdd_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_2," << StreamingAdd_2_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_3," << StreamingAdd_2_out0_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        4,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_0;
    BandwidthAdjustDecreaseStreams_0.run<182>(StreamingAdd_2_out0_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_0," << BandwidthAdjustDecreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_0;
    StreamingLineBuffer_9_pixel_0.run<183>(BandwidthAdjustDecreaseStreams_0_out0_stream[0], StreamingLineBuffer_9_out0_stream[63], StreamingLineBuffer_9_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_63," << StreamingLineBuffer_9_out0_stream[63].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_0," << StreamingLineBuffer_9_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_1;
    StreamingLineBuffer_9_pixel_1.run<184>(StreamingLineBuffer_9_buffer_stream[0], StreamingLineBuffer_9_out0_stream[62], StreamingLineBuffer_9_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_62," << StreamingLineBuffer_9_out0_stream[62].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_1," << StreamingLineBuffer_9_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_2;
    StreamingLineBuffer_9_pixel_2.run<185>(StreamingLineBuffer_9_buffer_stream[1], StreamingLineBuffer_9_out0_stream[61], StreamingLineBuffer_9_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_61," << StreamingLineBuffer_9_out0_stream[61].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_2," << StreamingLineBuffer_9_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_3;
    StreamingLineBuffer_9_pixel_3.run<186>(StreamingLineBuffer_9_buffer_stream[2], StreamingLineBuffer_9_out0_stream[60], StreamingLineBuffer_9_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_60," << StreamingLineBuffer_9_out0_stream[60].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_3," << StreamingLineBuffer_9_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_4;
    StreamingLineBuffer_9_pixel_4.run<187>(StreamingLineBuffer_9_buffer_stream[3], StreamingLineBuffer_9_out0_stream[59], StreamingLineBuffer_9_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_59," << StreamingLineBuffer_9_out0_stream[59].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_4," << StreamingLineBuffer_9_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_5;
    StreamingLineBuffer_9_pixel_5.run<188>(StreamingLineBuffer_9_buffer_stream[4], StreamingLineBuffer_9_out0_stream[58], StreamingLineBuffer_9_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_58," << StreamingLineBuffer_9_out0_stream[58].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_5," << StreamingLineBuffer_9_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_6;
    StreamingLineBuffer_9_pixel_6.run<189>(StreamingLineBuffer_9_buffer_stream[5], StreamingLineBuffer_9_out0_stream[57], StreamingLineBuffer_9_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_57," << StreamingLineBuffer_9_out0_stream[57].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_6," << StreamingLineBuffer_9_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_7;
    StreamingLineBuffer_9_pixel_7.run<190>(StreamingLineBuffer_9_buffer_stream[6], StreamingLineBuffer_9_out0_stream[56], StreamingLineBuffer_9_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_56," << StreamingLineBuffer_9_out0_stream[56].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_7," << StreamingLineBuffer_9_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_8;
    StreamingLineBuffer_9_pixel_8.run<191>(StreamingLineBuffer_9_buffer_stream[7], StreamingLineBuffer_9_out0_stream[55], StreamingLineBuffer_9_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_55," << StreamingLineBuffer_9_out0_stream[55].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_8," << StreamingLineBuffer_9_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_9;
    StreamingLineBuffer_9_pixel_9.run<192>(StreamingLineBuffer_9_buffer_stream[8], StreamingLineBuffer_9_out0_stream[54], StreamingLineBuffer_9_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_54," << StreamingLineBuffer_9_out0_stream[54].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_9," << StreamingLineBuffer_9_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_10;
    StreamingLineBuffer_9_pixel_10.run<193>(StreamingLineBuffer_9_buffer_stream[9], StreamingLineBuffer_9_out0_stream[53], StreamingLineBuffer_9_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_53," << StreamingLineBuffer_9_out0_stream[53].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_10," << StreamingLineBuffer_9_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_11;
    StreamingLineBuffer_9_pixel_11.run<194>(StreamingLineBuffer_9_buffer_stream[10], StreamingLineBuffer_9_out0_stream[52], StreamingLineBuffer_9_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_52," << StreamingLineBuffer_9_out0_stream[52].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_11," << StreamingLineBuffer_9_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_12;
    StreamingLineBuffer_9_pixel_12.run<195>(StreamingLineBuffer_9_buffer_stream[11], StreamingLineBuffer_9_out0_stream[51], StreamingLineBuffer_9_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_51," << StreamingLineBuffer_9_out0_stream[51].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_12," << StreamingLineBuffer_9_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_13;
    StreamingLineBuffer_9_pixel_13.run<196>(StreamingLineBuffer_9_buffer_stream[12], StreamingLineBuffer_9_out0_stream[50], StreamingLineBuffer_9_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_50," << StreamingLineBuffer_9_out0_stream[50].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_13," << StreamingLineBuffer_9_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_14;
    StreamingLineBuffer_9_pixel_14.run<197>(StreamingLineBuffer_9_buffer_stream[13], StreamingLineBuffer_9_out0_stream[49], StreamingLineBuffer_9_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_49," << StreamingLineBuffer_9_out0_stream[49].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_14," << StreamingLineBuffer_9_buffer_stream[14].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_15;
    StreamingLineBuffer_9_pixel_15.run<198>(StreamingLineBuffer_9_buffer_stream[14], StreamingLineBuffer_9_out0_stream[48], StreamingLineBuffer_9_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_48," << StreamingLineBuffer_9_out0_stream[48].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_15," << StreamingLineBuffer_9_buffer_stream[15].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_16;
    StreamingLineBuffer_9_pixel_16.run<199>(StreamingLineBuffer_9_buffer_stream[15], StreamingLineBuffer_9_out0_stream[47], StreamingLineBuffer_9_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_47," << StreamingLineBuffer_9_out0_stream[47].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_16," << StreamingLineBuffer_9_buffer_stream[16].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_17;
    StreamingLineBuffer_9_pixel_17.run<200>(StreamingLineBuffer_9_buffer_stream[16], StreamingLineBuffer_9_out0_stream[46], StreamingLineBuffer_9_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_46," << StreamingLineBuffer_9_out0_stream[46].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_17," << StreamingLineBuffer_9_buffer_stream[17].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_18;
    StreamingLineBuffer_9_pixel_18.run<201>(StreamingLineBuffer_9_buffer_stream[17], StreamingLineBuffer_9_out0_stream[45], StreamingLineBuffer_9_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_45," << StreamingLineBuffer_9_out0_stream[45].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_18," << StreamingLineBuffer_9_buffer_stream[18].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_19;
    StreamingLineBuffer_9_pixel_19.run<202>(StreamingLineBuffer_9_buffer_stream[18], StreamingLineBuffer_9_out0_stream[44], StreamingLineBuffer_9_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_44," << StreamingLineBuffer_9_out0_stream[44].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_19," << StreamingLineBuffer_9_buffer_stream[19].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_20;
    StreamingLineBuffer_9_pixel_20.run<203>(StreamingLineBuffer_9_buffer_stream[19], StreamingLineBuffer_9_out0_stream[43], StreamingLineBuffer_9_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_43," << StreamingLineBuffer_9_out0_stream[43].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_20," << StreamingLineBuffer_9_buffer_stream[20].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_21;
    StreamingLineBuffer_9_pixel_21.run<204>(StreamingLineBuffer_9_buffer_stream[20], StreamingLineBuffer_9_out0_stream[42], StreamingLineBuffer_9_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_42," << StreamingLineBuffer_9_out0_stream[42].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_21," << StreamingLineBuffer_9_buffer_stream[21].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_22;
    StreamingLineBuffer_9_pixel_22.run<205>(StreamingLineBuffer_9_buffer_stream[21], StreamingLineBuffer_9_out0_stream[41], StreamingLineBuffer_9_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_41," << StreamingLineBuffer_9_out0_stream[41].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_22," << StreamingLineBuffer_9_buffer_stream[22].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_23;
    StreamingLineBuffer_9_pixel_23.run<206>(StreamingLineBuffer_9_buffer_stream[22], StreamingLineBuffer_9_out0_stream[40], StreamingLineBuffer_9_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_40," << StreamingLineBuffer_9_out0_stream[40].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_23," << StreamingLineBuffer_9_buffer_stream[23].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_24;
    StreamingLineBuffer_9_pixel_24.run<207>(StreamingLineBuffer_9_buffer_stream[23], StreamingLineBuffer_9_out0_stream[39], StreamingLineBuffer_9_buffer_stream[24]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_39," << StreamingLineBuffer_9_out0_stream[39].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_24," << StreamingLineBuffer_9_buffer_stream[24].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_25;
    StreamingLineBuffer_9_pixel_25.run<208>(StreamingLineBuffer_9_buffer_stream[24], StreamingLineBuffer_9_out0_stream[38], StreamingLineBuffer_9_buffer_stream[25]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_38," << StreamingLineBuffer_9_out0_stream[38].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_25," << StreamingLineBuffer_9_buffer_stream[25].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_26;
    StreamingLineBuffer_9_pixel_26.run<209>(StreamingLineBuffer_9_buffer_stream[25], StreamingLineBuffer_9_out0_stream[37], StreamingLineBuffer_9_buffer_stream[26]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_37," << StreamingLineBuffer_9_out0_stream[37].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_26," << StreamingLineBuffer_9_buffer_stream[26].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_27;
    StreamingLineBuffer_9_pixel_27.run<210>(StreamingLineBuffer_9_buffer_stream[26], StreamingLineBuffer_9_out0_stream[36], StreamingLineBuffer_9_buffer_stream[27]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_36," << StreamingLineBuffer_9_out0_stream[36].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_27," << StreamingLineBuffer_9_buffer_stream[27].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_28;
    StreamingLineBuffer_9_pixel_28.run<211>(StreamingLineBuffer_9_buffer_stream[27], StreamingLineBuffer_9_out0_stream[35], StreamingLineBuffer_9_buffer_stream[28]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_35," << StreamingLineBuffer_9_out0_stream[35].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_28," << StreamingLineBuffer_9_buffer_stream[28].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_29;
    StreamingLineBuffer_9_pixel_29.run<212>(StreamingLineBuffer_9_buffer_stream[28], StreamingLineBuffer_9_out0_stream[34], StreamingLineBuffer_9_buffer_stream[29]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_34," << StreamingLineBuffer_9_out0_stream[34].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_29," << StreamingLineBuffer_9_buffer_stream[29].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_30;
    StreamingLineBuffer_9_pixel_30.run<213>(StreamingLineBuffer_9_buffer_stream[29], StreamingLineBuffer_9_out0_stream[33], StreamingLineBuffer_9_buffer_stream[30]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_33," << StreamingLineBuffer_9_out0_stream[33].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_30," << StreamingLineBuffer_9_buffer_stream[30].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_31;
    StreamingLineBuffer_9_pixel_31.run<214>(StreamingLineBuffer_9_buffer_stream[30], StreamingLineBuffer_9_out0_stream[32], StreamingLineBuffer_9_buffer_stream[31]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_32," << StreamingLineBuffer_9_out0_stream[32].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_31," << StreamingLineBuffer_9_buffer_stream[31].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_32;
    StreamingLineBuffer_9_pixel_32.run<215>(StreamingLineBuffer_9_buffer_stream[31], StreamingLineBuffer_9_out0_stream[31], StreamingLineBuffer_9_buffer_stream[32]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_31," << StreamingLineBuffer_9_out0_stream[31].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_32," << StreamingLineBuffer_9_buffer_stream[32].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_33;
    StreamingLineBuffer_9_pixel_33.run<216>(StreamingLineBuffer_9_buffer_stream[32], StreamingLineBuffer_9_out0_stream[30], StreamingLineBuffer_9_buffer_stream[33]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_30," << StreamingLineBuffer_9_out0_stream[30].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_33," << StreamingLineBuffer_9_buffer_stream[33].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_34;
    StreamingLineBuffer_9_pixel_34.run<217>(StreamingLineBuffer_9_buffer_stream[33], StreamingLineBuffer_9_out0_stream[29], StreamingLineBuffer_9_buffer_stream[34]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_29," << StreamingLineBuffer_9_out0_stream[29].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_34," << StreamingLineBuffer_9_buffer_stream[34].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_35;
    StreamingLineBuffer_9_pixel_35.run<218>(StreamingLineBuffer_9_buffer_stream[34], StreamingLineBuffer_9_out0_stream[28], StreamingLineBuffer_9_buffer_stream[35]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_28," << StreamingLineBuffer_9_out0_stream[28].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_35," << StreamingLineBuffer_9_buffer_stream[35].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_36;
    StreamingLineBuffer_9_pixel_36.run<219>(StreamingLineBuffer_9_buffer_stream[35], StreamingLineBuffer_9_out0_stream[27], StreamingLineBuffer_9_buffer_stream[36]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_27," << StreamingLineBuffer_9_out0_stream[27].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_36," << StreamingLineBuffer_9_buffer_stream[36].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_37;
    StreamingLineBuffer_9_pixel_37.run<220>(StreamingLineBuffer_9_buffer_stream[36], StreamingLineBuffer_9_out0_stream[26], StreamingLineBuffer_9_buffer_stream[37]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_26," << StreamingLineBuffer_9_out0_stream[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_37," << StreamingLineBuffer_9_buffer_stream[37].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_38;
    StreamingLineBuffer_9_pixel_38.run<221>(StreamingLineBuffer_9_buffer_stream[37], StreamingLineBuffer_9_out0_stream[25], StreamingLineBuffer_9_buffer_stream[38]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_25," << StreamingLineBuffer_9_out0_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_38," << StreamingLineBuffer_9_buffer_stream[38].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_39;
    StreamingLineBuffer_9_pixel_39.run<222>(StreamingLineBuffer_9_buffer_stream[38], StreamingLineBuffer_9_out0_stream[24], StreamingLineBuffer_9_buffer_stream[39]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_24," << StreamingLineBuffer_9_out0_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_39," << StreamingLineBuffer_9_buffer_stream[39].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_40;
    StreamingLineBuffer_9_pixel_40.run<223>(StreamingLineBuffer_9_buffer_stream[39], StreamingLineBuffer_9_out0_stream[23], StreamingLineBuffer_9_buffer_stream[40]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_23," << StreamingLineBuffer_9_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_40," << StreamingLineBuffer_9_buffer_stream[40].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_41;
    StreamingLineBuffer_9_pixel_41.run<224>(StreamingLineBuffer_9_buffer_stream[40], StreamingLineBuffer_9_out0_stream[22], StreamingLineBuffer_9_buffer_stream[41]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_22," << StreamingLineBuffer_9_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_41," << StreamingLineBuffer_9_buffer_stream[41].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_42;
    StreamingLineBuffer_9_pixel_42.run<225>(StreamingLineBuffer_9_buffer_stream[41], StreamingLineBuffer_9_out0_stream[21], StreamingLineBuffer_9_buffer_stream[42]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_21," << StreamingLineBuffer_9_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_42," << StreamingLineBuffer_9_buffer_stream[42].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_43;
    StreamingLineBuffer_9_pixel_43.run<226>(StreamingLineBuffer_9_buffer_stream[42], StreamingLineBuffer_9_out0_stream[20], StreamingLineBuffer_9_buffer_stream[43]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_20," << StreamingLineBuffer_9_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_43," << StreamingLineBuffer_9_buffer_stream[43].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_44;
    StreamingLineBuffer_9_pixel_44.run<227>(StreamingLineBuffer_9_buffer_stream[43], StreamingLineBuffer_9_out0_stream[19], StreamingLineBuffer_9_buffer_stream[44]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_19," << StreamingLineBuffer_9_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_44," << StreamingLineBuffer_9_buffer_stream[44].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_45;
    StreamingLineBuffer_9_pixel_45.run<228>(StreamingLineBuffer_9_buffer_stream[44], StreamingLineBuffer_9_out0_stream[18], StreamingLineBuffer_9_buffer_stream[45]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_18," << StreamingLineBuffer_9_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_45," << StreamingLineBuffer_9_buffer_stream[45].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_46;
    StreamingLineBuffer_9_pixel_46.run<229>(StreamingLineBuffer_9_buffer_stream[45], StreamingLineBuffer_9_out0_stream[17], StreamingLineBuffer_9_buffer_stream[46]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_17," << StreamingLineBuffer_9_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_46," << StreamingLineBuffer_9_buffer_stream[46].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_47;
    StreamingLineBuffer_9_pixel_47.run<230>(StreamingLineBuffer_9_buffer_stream[46], StreamingLineBuffer_9_out0_stream[16], StreamingLineBuffer_9_buffer_stream[47]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_16," << StreamingLineBuffer_9_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_47," << StreamingLineBuffer_9_buffer_stream[47].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_48;
    StreamingLineBuffer_9_pixel_48.run<231>(StreamingLineBuffer_9_buffer_stream[47], StreamingLineBuffer_9_out0_stream[15], StreamingLineBuffer_9_buffer_stream[48]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_15," << StreamingLineBuffer_9_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_48," << StreamingLineBuffer_9_buffer_stream[48].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_49;
    StreamingLineBuffer_9_pixel_49.run<232>(StreamingLineBuffer_9_buffer_stream[48], StreamingLineBuffer_9_out0_stream[14], StreamingLineBuffer_9_buffer_stream[49]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_14," << StreamingLineBuffer_9_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_49," << StreamingLineBuffer_9_buffer_stream[49].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_50;
    StreamingLineBuffer_9_pixel_50.run<233>(StreamingLineBuffer_9_buffer_stream[49], StreamingLineBuffer_9_out0_stream[13], StreamingLineBuffer_9_buffer_stream[50]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_13," << StreamingLineBuffer_9_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_50," << StreamingLineBuffer_9_buffer_stream[50].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_51;
    StreamingLineBuffer_9_pixel_51.run<234>(StreamingLineBuffer_9_buffer_stream[50], StreamingLineBuffer_9_out0_stream[12], StreamingLineBuffer_9_buffer_stream[51]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_12," << StreamingLineBuffer_9_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_51," << StreamingLineBuffer_9_buffer_stream[51].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_52;
    StreamingLineBuffer_9_pixel_52.run<235>(StreamingLineBuffer_9_buffer_stream[51], StreamingLineBuffer_9_out0_stream[11], StreamingLineBuffer_9_buffer_stream[52]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_11," << StreamingLineBuffer_9_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_52," << StreamingLineBuffer_9_buffer_stream[52].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_53;
    StreamingLineBuffer_9_pixel_53.run<236>(StreamingLineBuffer_9_buffer_stream[52], StreamingLineBuffer_9_out0_stream[10], StreamingLineBuffer_9_buffer_stream[53]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_10," << StreamingLineBuffer_9_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_53," << StreamingLineBuffer_9_buffer_stream[53].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_54;
    StreamingLineBuffer_9_pixel_54.run<237>(StreamingLineBuffer_9_buffer_stream[53], StreamingLineBuffer_9_out0_stream[9], StreamingLineBuffer_9_buffer_stream[54]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_9," << StreamingLineBuffer_9_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_54," << StreamingLineBuffer_9_buffer_stream[54].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_55;
    StreamingLineBuffer_9_pixel_55.run<238>(StreamingLineBuffer_9_buffer_stream[54], StreamingLineBuffer_9_out0_stream[8], StreamingLineBuffer_9_buffer_stream[55]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_8," << StreamingLineBuffer_9_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_55," << StreamingLineBuffer_9_buffer_stream[55].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_56;
    StreamingLineBuffer_9_pixel_56.run<239>(StreamingLineBuffer_9_buffer_stream[55], StreamingLineBuffer_9_out0_stream[7], StreamingLineBuffer_9_buffer_stream[56]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_7," << StreamingLineBuffer_9_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_56," << StreamingLineBuffer_9_buffer_stream[56].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_57;
    StreamingLineBuffer_9_pixel_57.run<240>(StreamingLineBuffer_9_buffer_stream[56], StreamingLineBuffer_9_out0_stream[6], StreamingLineBuffer_9_buffer_stream[57]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_6," << StreamingLineBuffer_9_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_57," << StreamingLineBuffer_9_buffer_stream[57].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_58;
    StreamingLineBuffer_9_pixel_58.run<241>(StreamingLineBuffer_9_buffer_stream[57], StreamingLineBuffer_9_out0_stream[5], StreamingLineBuffer_9_buffer_stream[58]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_5," << StreamingLineBuffer_9_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_58," << StreamingLineBuffer_9_buffer_stream[58].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_59;
    StreamingLineBuffer_9_pixel_59.run<242>(StreamingLineBuffer_9_buffer_stream[58], StreamingLineBuffer_9_out0_stream[4], StreamingLineBuffer_9_buffer_stream[59]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_4," << StreamingLineBuffer_9_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_59," << StreamingLineBuffer_9_buffer_stream[59].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_60;
    StreamingLineBuffer_9_pixel_60.run<243>(StreamingLineBuffer_9_buffer_stream[59], StreamingLineBuffer_9_out0_stream[3], StreamingLineBuffer_9_buffer_stream[60]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_3," << StreamingLineBuffer_9_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_60," << StreamingLineBuffer_9_buffer_stream[60].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_61;
    StreamingLineBuffer_9_pixel_61.run<244>(StreamingLineBuffer_9_buffer_stream[60], StreamingLineBuffer_9_out0_stream[2], StreamingLineBuffer_9_buffer_stream[61]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_2," << StreamingLineBuffer_9_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_61," << StreamingLineBuffer_9_buffer_stream[61].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_62;
    StreamingLineBuffer_9_pixel_62.run<245>(StreamingLineBuffer_9_buffer_stream[61], StreamingLineBuffer_9_out0_stream[1], StreamingLineBuffer_9_buffer_stream[62]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_1," << StreamingLineBuffer_9_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_62," << StreamingLineBuffer_9_buffer_stream[62].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2  // CH_PAR
    > StreamingLineBuffer_9_pixel_63;
    StreamingLineBuffer_9_pixel_63.run<246>(StreamingLineBuffer_9_buffer_stream[62], StreamingLineBuffer_9_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_0," << StreamingLineBuffer_9_out0_stream[0].size() << std::endl;
    #endif
    StreamingMaxPool <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantPo2<1, ap_uint<8>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        1,  // IN_HEIGHT
        1,  // IN_WIDTH
        8,  // FH
        8,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // CH_PAR
        1  // W_PAR
    > StreamingMaxPool_0;
    StreamingMaxPool_0.run<247>(StreamingLineBuffer_9_out0_stream, StreamingMaxPool_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMaxPool_0_out0_stream_0," << StreamingMaxPool_0_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_9_weights[160][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=2 complete
    ap_int<16> StreamingConv_9_biases[5][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
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
        2,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_9;
    StreamingConv_9.run<248>(StreamingMaxPool_0_out0_stream, StreamingConv_9_weights, StreamingConv_9_biases, StreamingConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_0," << StreamingConv_9_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        6,  // ITER
        16,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        10,  // CH
        1,  // IN_W_PAR
        2  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.run<249>(StreamingConv_9_out0_stream, global_out);
}
