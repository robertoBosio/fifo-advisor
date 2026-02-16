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
void resnet20(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis port=global_in
    #pragma HLS INTERFACE axis port=global_out
    hls::stream<std::array<ap_int<8>, 1>> NHWCToStream_0_out0_stream[1];
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustIncreaseStreams_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream[12];
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
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[2] depth=42
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[3] depth=50
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[7] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[8] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_0_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[1] depth=65
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_0_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[0] depth=673
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[1] depth=673
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
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[0] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[0] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[2] depth=241
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[3] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[5] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[6] depth=238
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[8] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_2_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_2_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[0] depth=86
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[1] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[2] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[3] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[4] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[5] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[6] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[7] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[8] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_2_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[2] depth=58
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[3] depth=60
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[4] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[6] depth=118
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[7] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_2_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_1_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_1_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[0] depth=592
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[1] depth=592
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[0] depth=109
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[1] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[2] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[3] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[4] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[5] depth=77
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[6] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[7] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[9] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[10] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_3_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[2] depth=179
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[3] depth=181
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[5] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[6] depth=238
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_4_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_4_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[0] depth=86
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[1] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[2] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[3] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[4] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[5] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[6] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[7] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[8] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_4_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[2] depth=58
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[3] depth=60
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[4] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[6] depth=118
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[7] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_2_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_2_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[0] depth=592
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[1] depth=592
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_5_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_5_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[0] depth=109
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[1] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[2] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[3] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[4] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[5] depth=77
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[6] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[7] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[9] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[10] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_5_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[2] depth=179
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[3] depth=181
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[5] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[6] depth=238
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_5_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[0] depth=86
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[1] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[2] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[3] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[4] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[5] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[6] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[7] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[8] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[9] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_6_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[2] depth=58
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[3] depth=60
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[4] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[6] depth=118
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[7] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_3_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_3_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[0] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[1] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[2] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[3] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[4] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[5] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[6] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[7] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[8] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[9] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[10] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[11] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[12] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[13] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[14] depth=71
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[0] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[1] depth=142
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[2] depth=135
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[3] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[4] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[5] depth=112
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[6] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[7] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[8] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[9] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[10] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[11] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[12] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_7_buffer_stream[13];
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
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_8_out0_stream[3];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[0] depth=22
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[1] depth=22
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[2] depth=14
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_8_buffer_stream[1];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[0] depth=289
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[1] depth=289
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_9_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_9_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[0] depth=157
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[1] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[2] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[3] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[4] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[5] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[6] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[7] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[9] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_9_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[2] depth=163
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[3] depth=165
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[5] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[6] depth=222
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingAdd_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_4_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_4_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[0] depth=336
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[1] depth=336
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[1] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[2] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[3] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[4] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[5] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[6] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[7] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[9] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[10] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[2] depth=50
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[3] depth=52
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[5] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[6] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[7] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_11_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_11_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[0] depth=157
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[1] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[2] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[3] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[4] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[5] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[6] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[7] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[9] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_11_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[2] depth=163
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[3] depth=165
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[5] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[6] depth=222
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingAdd_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_5_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_5_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[0] depth=336
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[1] depth=336
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_12_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_12_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[1] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[2] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[3] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[4] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[5] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[6] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[7] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[9] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[10] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_12_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[2] depth=50
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[3] depth=52
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[5] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[6] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[7] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_12_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[0] depth=157
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[1] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[2] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[3] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[4] depth=126
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[5] depth=93
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[6] depth=125
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[7] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[9] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[2] depth=163
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[3] depth=165
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[5] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[6] depth=222
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_13_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_13_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingAdd_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_6_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> TensorDuplicator_6_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_14_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[0] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[1] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[2] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[3] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[4] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[5] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[6] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[7] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[8] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[9] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[10] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[11] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[12] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[13] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[14] depth=15
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_14_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[0] depth=63
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[1] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[2] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[3] depth=63
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[4] depth=63
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[5] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[6] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[7] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[9] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[10] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[11] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[12] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[14] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_14_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[12] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_15_out0_stream[3];
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[0] depth=22
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[1] depth=22
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[2] depth=14
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_15_buffer_stream[1];
    #pragma HLS STREAM variable=StreamingLineBuffer_15_buffer_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[0] depth=640
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[1] depth=640
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_16_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_16_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[0] depth=166
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[1] depth=182
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[2] depth=183
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[3] depth=151
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[4] depth=160
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[5] depth=150
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[6] depth=169
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[7] depth=104
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[9] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[10] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_16_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[4] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[6] depth=62
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[7] depth=105
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[8] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[9] depth=17
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_16_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[0] depth=46
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[1] depth=46
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_7_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_7_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[0] depth=769
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[1] depth=769
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_17_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[0] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[1] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[2] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[3] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[4] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[5] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[7] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[8] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[9] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[10] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[11] depth=72
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_17_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[1] depth=187
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[2] depth=188
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[3] depth=124
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[4] depth=188
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[5] depth=123
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[6] depth=187
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[7] depth=124
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[8] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[9] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[10] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_17_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[2] depth=133
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[3] depth=135
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[4] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[5] depth=62
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[6] depth=190
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_18_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[9] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[11] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_18_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[0] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[1] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[2] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[3] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[4] depth=80
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[5] depth=78
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[6] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[7] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[8] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[9] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[10] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_18_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[6] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[7] depth=49
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[8] depth=47
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[9] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[0] depth=66
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[1] depth=66
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_8_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> TensorDuplicator_8_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[0] depth=2
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[1] depth=129
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseStreams_0_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[0] depth=1473
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream[12];
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
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[1] depth=187
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[2] depth=188
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[3] depth=124
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[4] depth=188
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[5] depth=123
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[6] depth=187
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[7] depth=124
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[8] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[9] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[10] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[11] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[2] depth=133
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[3] depth=135
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[4] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[5] depth=62
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[6] depth=190
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[7] depth=254
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[8] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[9] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[1] depth=16
    hls::stream<std::array<ap_uint<8>, 4>> BandwidthAdjustDecreaseStreams_1_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_1_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_20_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[3] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[4] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[5] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[8] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_20_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[0] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[1] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[2] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[3] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[4] depth=94
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[5] depth=95
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[6] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[7] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream_prepad[8] depth=2
    hls::stream<std::array<ap_uint<8>, 4>> StreamingLineBuffer_20_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[0] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[1] depth=16
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[2] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[3] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[4] depth=14
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[5] depth=110
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[6] depth=79
    #pragma HLS STREAM variable=StreamingLineBuffer_20_buffer_stream[7] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_20_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingAdd_8_out0_stream[1];
    #pragma HLS STREAM variable=StreamingAdd_8_out0_stream[0] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream[64];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[0] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[2] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[3] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[4] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[5] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[6] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[7] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[8] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[9] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[10] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[11] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[12] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[13] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[14] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[15] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[16] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[17] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[18] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[19] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[20] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[21] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[22] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[23] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[24] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[25] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[26] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[27] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[28] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[29] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[30] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[31] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[32] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[33] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[34] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[35] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[36] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[37] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[38] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[39] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[40] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[41] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[42] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[43] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[44] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[45] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[46] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[47] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[48] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[49] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[50] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[51] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[52] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[53] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[54] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[55] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[56] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[57] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[58] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[59] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[60] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[61] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[62] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[63] depth=2
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_buffer_stream[63];
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
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[10] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[11] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[12] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[13] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[14] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[15] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[16] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[17] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[18] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[19] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[20] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[21] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[22] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[23] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[24] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[25] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[26] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[27] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[28] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[29] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[30] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[31] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[32] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[33] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[34] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[35] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[36] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[37] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[38] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[39] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[40] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[41] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[42] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[43] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[44] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[45] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[46] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[47] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[48] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[49] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[50] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[51] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[52] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[53] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[54] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[55] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[56] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[57] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[58] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[59] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[60] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[61] depth=2
    #pragma HLS STREAM variable=StreamingLineBuffer_21_buffer_stream[62] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingMaxPool_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMaxPool_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_21_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[0] depth=2
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        16,  // DATA_PER_WORD
        32,  // HEIGHT
        32,  // WIDTH
        3,  // CH
        1,  // OUT_W_PAR
        1  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.run<0>(global_in, NHWCToStream_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_0," << NHWCToStream_0_out0_stream[0].size() << std::endl;
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
    > BandwidthAdjustIncreaseStreams_0;
    BandwidthAdjustIncreaseStreams_0.run<1>(NHWCToStream_0_out0_stream, BandwidthAdjustIncreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_0," << BandwidthAdjustIncreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_1," << BandwidthAdjustIncreaseStreams_0_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_0_pixel_0;
    StreamingLineBuffer_0_pixel_0.run<2>(BandwidthAdjustIncreaseStreams_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[11], StreamingLineBuffer_0_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_11," << StreamingLineBuffer_0_out0_stream_prepad[11].size() << std::endl;
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
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_1;
    StreamingLineBuffer_0_pixel_1.run<3>(BandwidthAdjustIncreaseStreams_0_out0_stream[1], StreamingLineBuffer_0_out0_stream_prepad[10], StreamingLineBuffer_0_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_10," << StreamingLineBuffer_0_out0_stream_prepad[10].size() << std::endl;
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
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_2;
    StreamingLineBuffer_0_pixel_2.run<4>(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[9], StreamingLineBuffer_0_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_9," << StreamingLineBuffer_0_out0_stream_prepad[9].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_3;
    StreamingLineBuffer_0_pixel_3.run<5>(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_8," << StreamingLineBuffer_0_out0_stream_prepad[8].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_4;
    StreamingLineBuffer_0_pixel_4.run<6>(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_7," << StreamingLineBuffer_0_out0_stream_prepad[7].size() << std::endl;
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
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_5;
    StreamingLineBuffer_0_pixel_5.run<7>(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_6," << StreamingLineBuffer_0_out0_stream_prepad[6].size() << std::endl;
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
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_6;
    StreamingLineBuffer_0_pixel_6.run<8>(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_5," << StreamingLineBuffer_0_out0_stream_prepad[5].size() << std::endl;
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
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_7;
    StreamingLineBuffer_0_pixel_7.run<9>(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_4," << StreamingLineBuffer_0_out0_stream_prepad[4].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_8;
    StreamingLineBuffer_0_pixel_8.run<10>(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[3], StreamingLineBuffer_0_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_3," << StreamingLineBuffer_0_out0_stream_prepad[3].size() << std::endl;
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
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_9;
    StreamingLineBuffer_0_pixel_9.run<11>(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[2], StreamingLineBuffer_0_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_2," << StreamingLineBuffer_0_out0_stream_prepad[2].size() << std::endl;
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
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_10;
    StreamingLineBuffer_0_pixel_10.run<12>(StreamingLineBuffer_0_buffer_stream[8], StreamingLineBuffer_0_out0_stream_prepad[1]);
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_11;
    StreamingLineBuffer_0_pixel_11.run<13>(StreamingLineBuffer_0_buffer_stream[9], StreamingLineBuffer_0_out0_stream_prepad[0]);
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_0_pad;
    StreamingLineBuffer_0_pad.run<14>(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
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
    ap_int<8> StreamingConv_0_weights[48][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=2 complete
    ap_int<14> StreamingConv_0_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<6, ap_int<22>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_0;
    StreamingConv_0.run<15>(StreamingLineBuffer_0_out0_stream, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_0," << StreamingConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_1," << StreamingConv_0_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<16>(StreamingConv_0_out0_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_0," << TensorDuplicator_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out0_stream_1," << TensorDuplicator_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_0," << TensorDuplicator_0_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_0_out1_stream_1," << TensorDuplicator_0_out1_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_1_pixel_0;
    StreamingLineBuffer_1_pixel_0.run<17>(TensorDuplicator_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_11," << StreamingLineBuffer_1_out0_stream_prepad[11].size() << std::endl;
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
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_1;
    StreamingLineBuffer_1_pixel_1.run<18>(TensorDuplicator_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_10," << StreamingLineBuffer_1_out0_stream_prepad[10].size() << std::endl;
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
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_2;
    StreamingLineBuffer_1_pixel_2.run<19>(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_9," << StreamingLineBuffer_1_out0_stream_prepad[9].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_3;
    StreamingLineBuffer_1_pixel_3.run<20>(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_8," << StreamingLineBuffer_1_out0_stream_prepad[8].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_4;
    StreamingLineBuffer_1_pixel_4.run<21>(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_7," << StreamingLineBuffer_1_out0_stream_prepad[7].size() << std::endl;
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
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_5;
    StreamingLineBuffer_1_pixel_5.run<22>(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_6," << StreamingLineBuffer_1_out0_stream_prepad[6].size() << std::endl;
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
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_6;
    StreamingLineBuffer_1_pixel_6.run<23>(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_5," << StreamingLineBuffer_1_out0_stream_prepad[5].size() << std::endl;
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
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_7;
    StreamingLineBuffer_1_pixel_7.run<24>(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_4," << StreamingLineBuffer_1_out0_stream_prepad[4].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_8;
    StreamingLineBuffer_1_pixel_8.run<25>(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[3], StreamingLineBuffer_1_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_3," << StreamingLineBuffer_1_out0_stream_prepad[3].size() << std::endl;
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
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_9;
    StreamingLineBuffer_1_pixel_9.run<26>(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[2], StreamingLineBuffer_1_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_2," << StreamingLineBuffer_1_out0_stream_prepad[2].size() << std::endl;
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
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_10;
    StreamingLineBuffer_1_pixel_10.run<27>(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[1]);
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_11;
    StreamingLineBuffer_1_pixel_11.run<28>(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[0]);
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_1_pad;
    StreamingLineBuffer_1_pad.run<29>(StreamingLineBuffer_1_out0_stream_prepad, StreamingLineBuffer_1_out0_stream);
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
    ap_int<8> StreamingConv_1_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=2 complete
    ap_int<16> StreamingConv_1_biases[8][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=2 complete
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
        DequantQuantPo2<8, ap_int<26>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_1;
    StreamingConv_1.run<30>(StreamingLineBuffer_1_out0_stream, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_0," << StreamingConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_1," << StreamingConv_1_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_0;
    StreamingLineBuffer_2_pixel_0.run<31>(StreamingConv_1_out0_stream[0], StreamingLineBuffer_2_out0_stream_prepad[11], StreamingLineBuffer_2_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_11," << StreamingLineBuffer_2_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_0," << StreamingLineBuffer_2_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_1;
    StreamingLineBuffer_2_pixel_1.run<32>(StreamingConv_1_out0_stream[1], StreamingLineBuffer_2_out0_stream_prepad[10], StreamingLineBuffer_2_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_10," << StreamingLineBuffer_2_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_1," << StreamingLineBuffer_2_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_2;
    StreamingLineBuffer_2_pixel_2.run<33>(StreamingLineBuffer_2_buffer_stream[0], StreamingLineBuffer_2_out0_stream_prepad[9], StreamingLineBuffer_2_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_9," << StreamingLineBuffer_2_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_2," << StreamingLineBuffer_2_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_3;
    StreamingLineBuffer_2_pixel_3.run<34>(StreamingLineBuffer_2_buffer_stream[1], StreamingLineBuffer_2_out0_stream_prepad[8], StreamingLineBuffer_2_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_8," << StreamingLineBuffer_2_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_3," << StreamingLineBuffer_2_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_4;
    StreamingLineBuffer_2_pixel_4.run<35>(StreamingLineBuffer_2_buffer_stream[2], StreamingLineBuffer_2_out0_stream_prepad[7], StreamingLineBuffer_2_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_7," << StreamingLineBuffer_2_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_4," << StreamingLineBuffer_2_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_5;
    StreamingLineBuffer_2_pixel_5.run<36>(StreamingLineBuffer_2_buffer_stream[3], StreamingLineBuffer_2_out0_stream_prepad[6], StreamingLineBuffer_2_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_6," << StreamingLineBuffer_2_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_5," << StreamingLineBuffer_2_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_6;
    StreamingLineBuffer_2_pixel_6.run<37>(StreamingLineBuffer_2_buffer_stream[4], StreamingLineBuffer_2_out0_stream_prepad[5], StreamingLineBuffer_2_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_5," << StreamingLineBuffer_2_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_6," << StreamingLineBuffer_2_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_7;
    StreamingLineBuffer_2_pixel_7.run<38>(StreamingLineBuffer_2_buffer_stream[5], StreamingLineBuffer_2_out0_stream_prepad[4], StreamingLineBuffer_2_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_4," << StreamingLineBuffer_2_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_7," << StreamingLineBuffer_2_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_8;
    StreamingLineBuffer_2_pixel_8.run<39>(StreamingLineBuffer_2_buffer_stream[6], StreamingLineBuffer_2_out0_stream_prepad[3], StreamingLineBuffer_2_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_3," << StreamingLineBuffer_2_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_8," << StreamingLineBuffer_2_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_9;
    StreamingLineBuffer_2_pixel_9.run<40>(StreamingLineBuffer_2_buffer_stream[7], StreamingLineBuffer_2_out0_stream_prepad[2], StreamingLineBuffer_2_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_2," << StreamingLineBuffer_2_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_buffer_stream_9," << StreamingLineBuffer_2_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_10;
    StreamingLineBuffer_2_pixel_10.run<41>(StreamingLineBuffer_2_buffer_stream[8], StreamingLineBuffer_2_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_1," << StreamingLineBuffer_2_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_2_pixel_11;
    StreamingLineBuffer_2_pixel_11.run<42>(StreamingLineBuffer_2_buffer_stream[9], StreamingLineBuffer_2_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_prepad_0," << StreamingLineBuffer_2_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_2_pad;
    StreamingLineBuffer_2_pad.run<43>(StreamingLineBuffer_2_out0_stream_prepad, StreamingLineBuffer_2_out0_stream);
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
    ap_int<8> StreamingConv_2_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=2 complete
    ap_int<15> StreamingConv_2_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
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
    > StreamingConv_2;
    StreamingConv_2.run<44>(StreamingLineBuffer_2_out0_stream, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_0," << StreamingConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_1," << StreamingConv_2_out0_stream[1].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_0;
    StreamingAdd_0.run<45>(StreamingConv_2_out0_stream, TensorDuplicator_0_out1_stream, StreamingAdd_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_0," << StreamingAdd_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_1," << StreamingAdd_0_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<46>(StreamingAdd_0_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
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
    > StreamingLineBuffer_3_pixel_0;
    StreamingLineBuffer_3_pixel_0.run<47>(TensorDuplicator_1_out0_stream[0], StreamingLineBuffer_3_out0_stream_prepad[11], StreamingLineBuffer_3_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_11," << StreamingLineBuffer_3_out0_stream_prepad[11].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_1;
    StreamingLineBuffer_3_pixel_1.run<48>(TensorDuplicator_1_out0_stream[1], StreamingLineBuffer_3_out0_stream_prepad[10], StreamingLineBuffer_3_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_10," << StreamingLineBuffer_3_out0_stream_prepad[10].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_2;
    StreamingLineBuffer_3_pixel_2.run<49>(StreamingLineBuffer_3_buffer_stream[0], StreamingLineBuffer_3_out0_stream_prepad[9], StreamingLineBuffer_3_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_9," << StreamingLineBuffer_3_out0_stream_prepad[9].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_3;
    StreamingLineBuffer_3_pixel_3.run<50>(StreamingLineBuffer_3_buffer_stream[1], StreamingLineBuffer_3_out0_stream_prepad[8], StreamingLineBuffer_3_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_8," << StreamingLineBuffer_3_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_3," << StreamingLineBuffer_3_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_4;
    StreamingLineBuffer_3_pixel_4.run<51>(StreamingLineBuffer_3_buffer_stream[2], StreamingLineBuffer_3_out0_stream_prepad[7], StreamingLineBuffer_3_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_7," << StreamingLineBuffer_3_out0_stream_prepad[7].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_5;
    StreamingLineBuffer_3_pixel_5.run<52>(StreamingLineBuffer_3_buffer_stream[3], StreamingLineBuffer_3_out0_stream_prepad[6], StreamingLineBuffer_3_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_6," << StreamingLineBuffer_3_out0_stream_prepad[6].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_6;
    StreamingLineBuffer_3_pixel_6.run<53>(StreamingLineBuffer_3_buffer_stream[4], StreamingLineBuffer_3_out0_stream_prepad[5], StreamingLineBuffer_3_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_5," << StreamingLineBuffer_3_out0_stream_prepad[5].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_7;
    StreamingLineBuffer_3_pixel_7.run<54>(StreamingLineBuffer_3_buffer_stream[5], StreamingLineBuffer_3_out0_stream_prepad[4], StreamingLineBuffer_3_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_4," << StreamingLineBuffer_3_out0_stream_prepad[4].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_8;
    StreamingLineBuffer_3_pixel_8.run<55>(StreamingLineBuffer_3_buffer_stream[6], StreamingLineBuffer_3_out0_stream_prepad[3], StreamingLineBuffer_3_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_3," << StreamingLineBuffer_3_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_8," << StreamingLineBuffer_3_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_9;
    StreamingLineBuffer_3_pixel_9.run<56>(StreamingLineBuffer_3_buffer_stream[7], StreamingLineBuffer_3_out0_stream_prepad[2], StreamingLineBuffer_3_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_2," << StreamingLineBuffer_3_out0_stream_prepad[2].size() << std::endl;
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
    > StreamingLineBuffer_3_pixel_10;
    StreamingLineBuffer_3_pixel_10.run<57>(StreamingLineBuffer_3_buffer_stream[8], StreamingLineBuffer_3_out0_stream_prepad[1]);
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
    > StreamingLineBuffer_3_pixel_11;
    StreamingLineBuffer_3_pixel_11.run<58>(StreamingLineBuffer_3_buffer_stream[9], StreamingLineBuffer_3_out0_stream_prepad[0]);
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
    > StreamingLineBuffer_3_pad;
    StreamingLineBuffer_3_pad.run<59>(StreamingLineBuffer_3_out0_stream_prepad, StreamingLineBuffer_3_out0_stream);
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
    ap_int<8> StreamingConv_3_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=2 complete
    ap_int<15> StreamingConv_3_biases[8][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_3;
    StreamingConv_3.run<60>(StreamingLineBuffer_3_out0_stream, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_0," << StreamingConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_1," << StreamingConv_3_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_0;
    StreamingLineBuffer_4_pixel_0.run<61>(StreamingConv_3_out0_stream[0], StreamingLineBuffer_4_out0_stream_prepad[11], StreamingLineBuffer_4_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_11," << StreamingLineBuffer_4_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_0," << StreamingLineBuffer_4_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_1;
    StreamingLineBuffer_4_pixel_1.run<62>(StreamingConv_3_out0_stream[1], StreamingLineBuffer_4_out0_stream_prepad[10], StreamingLineBuffer_4_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_10," << StreamingLineBuffer_4_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_1," << StreamingLineBuffer_4_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_2;
    StreamingLineBuffer_4_pixel_2.run<63>(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream_prepad[9], StreamingLineBuffer_4_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_9," << StreamingLineBuffer_4_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_2," << StreamingLineBuffer_4_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_3;
    StreamingLineBuffer_4_pixel_3.run<64>(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream_prepad[8], StreamingLineBuffer_4_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_8," << StreamingLineBuffer_4_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_3," << StreamingLineBuffer_4_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_4;
    StreamingLineBuffer_4_pixel_4.run<65>(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream_prepad[7], StreamingLineBuffer_4_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_7," << StreamingLineBuffer_4_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_4," << StreamingLineBuffer_4_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_5;
    StreamingLineBuffer_4_pixel_5.run<66>(StreamingLineBuffer_4_buffer_stream[3], StreamingLineBuffer_4_out0_stream_prepad[6], StreamingLineBuffer_4_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_6," << StreamingLineBuffer_4_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_5," << StreamingLineBuffer_4_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_6;
    StreamingLineBuffer_4_pixel_6.run<67>(StreamingLineBuffer_4_buffer_stream[4], StreamingLineBuffer_4_out0_stream_prepad[5], StreamingLineBuffer_4_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_5," << StreamingLineBuffer_4_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_6," << StreamingLineBuffer_4_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_7;
    StreamingLineBuffer_4_pixel_7.run<68>(StreamingLineBuffer_4_buffer_stream[5], StreamingLineBuffer_4_out0_stream_prepad[4], StreamingLineBuffer_4_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_4," << StreamingLineBuffer_4_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_7," << StreamingLineBuffer_4_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_8;
    StreamingLineBuffer_4_pixel_8.run<69>(StreamingLineBuffer_4_buffer_stream[6], StreamingLineBuffer_4_out0_stream_prepad[3], StreamingLineBuffer_4_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_3," << StreamingLineBuffer_4_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_8," << StreamingLineBuffer_4_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_9;
    StreamingLineBuffer_4_pixel_9.run<70>(StreamingLineBuffer_4_buffer_stream[7], StreamingLineBuffer_4_out0_stream_prepad[2], StreamingLineBuffer_4_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_2," << StreamingLineBuffer_4_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_9," << StreamingLineBuffer_4_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_10;
    StreamingLineBuffer_4_pixel_10.run<71>(StreamingLineBuffer_4_buffer_stream[8], StreamingLineBuffer_4_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_1," << StreamingLineBuffer_4_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_4_pixel_11;
    StreamingLineBuffer_4_pixel_11.run<72>(StreamingLineBuffer_4_buffer_stream[9], StreamingLineBuffer_4_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_0," << StreamingLineBuffer_4_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_4_pad;
    StreamingLineBuffer_4_pad.run<73>(StreamingLineBuffer_4_out0_stream_prepad, StreamingLineBuffer_4_out0_stream);
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
    ap_int<8> StreamingConv_4_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=2 complete
    ap_int<14> StreamingConv_4_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
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
    > StreamingConv_4;
    StreamingConv_4.run<74>(StreamingLineBuffer_4_out0_stream, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_0," << StreamingConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_1," << StreamingConv_4_out0_stream[1].size() << std::endl;
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
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_1;
    StreamingAdd_1.run<75>(StreamingConv_4_out0_stream, TensorDuplicator_1_out1_stream, StreamingAdd_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_0," << StreamingAdd_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_1," << StreamingAdd_1_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<76>(StreamingAdd_1_out0_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
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
    > StreamingLineBuffer_5_pixel_0;
    StreamingLineBuffer_5_pixel_0.run<77>(TensorDuplicator_2_out0_stream[0], StreamingLineBuffer_5_out0_stream_prepad[11], StreamingLineBuffer_5_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_11," << StreamingLineBuffer_5_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_0," << StreamingLineBuffer_5_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_1;
    StreamingLineBuffer_5_pixel_1.run<78>(TensorDuplicator_2_out0_stream[1], StreamingLineBuffer_5_out0_stream_prepad[10], StreamingLineBuffer_5_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_10," << StreamingLineBuffer_5_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_1," << StreamingLineBuffer_5_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_2;
    StreamingLineBuffer_5_pixel_2.run<79>(StreamingLineBuffer_5_buffer_stream[0], StreamingLineBuffer_5_out0_stream_prepad[9], StreamingLineBuffer_5_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_9," << StreamingLineBuffer_5_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_2," << StreamingLineBuffer_5_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_3;
    StreamingLineBuffer_5_pixel_3.run<80>(StreamingLineBuffer_5_buffer_stream[1], StreamingLineBuffer_5_out0_stream_prepad[8], StreamingLineBuffer_5_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_8," << StreamingLineBuffer_5_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_3," << StreamingLineBuffer_5_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_4;
    StreamingLineBuffer_5_pixel_4.run<81>(StreamingLineBuffer_5_buffer_stream[2], StreamingLineBuffer_5_out0_stream_prepad[7], StreamingLineBuffer_5_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_7," << StreamingLineBuffer_5_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_4," << StreamingLineBuffer_5_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_5;
    StreamingLineBuffer_5_pixel_5.run<82>(StreamingLineBuffer_5_buffer_stream[3], StreamingLineBuffer_5_out0_stream_prepad[6], StreamingLineBuffer_5_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_6," << StreamingLineBuffer_5_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_5," << StreamingLineBuffer_5_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_6;
    StreamingLineBuffer_5_pixel_6.run<83>(StreamingLineBuffer_5_buffer_stream[4], StreamingLineBuffer_5_out0_stream_prepad[5], StreamingLineBuffer_5_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_5," << StreamingLineBuffer_5_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_6," << StreamingLineBuffer_5_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_7;
    StreamingLineBuffer_5_pixel_7.run<84>(StreamingLineBuffer_5_buffer_stream[5], StreamingLineBuffer_5_out0_stream_prepad[4], StreamingLineBuffer_5_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_4," << StreamingLineBuffer_5_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_7," << StreamingLineBuffer_5_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_8;
    StreamingLineBuffer_5_pixel_8.run<85>(StreamingLineBuffer_5_buffer_stream[6], StreamingLineBuffer_5_out0_stream_prepad[3], StreamingLineBuffer_5_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_3," << StreamingLineBuffer_5_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_8," << StreamingLineBuffer_5_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_9;
    StreamingLineBuffer_5_pixel_9.run<86>(StreamingLineBuffer_5_buffer_stream[7], StreamingLineBuffer_5_out0_stream_prepad[2], StreamingLineBuffer_5_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_2," << StreamingLineBuffer_5_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_buffer_stream_9," << StreamingLineBuffer_5_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_10;
    StreamingLineBuffer_5_pixel_10.run<87>(StreamingLineBuffer_5_buffer_stream[8], StreamingLineBuffer_5_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_1," << StreamingLineBuffer_5_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_5_pixel_11;
    StreamingLineBuffer_5_pixel_11.run<88>(StreamingLineBuffer_5_buffer_stream[9], StreamingLineBuffer_5_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_prepad_0," << StreamingLineBuffer_5_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_5_pad;
    StreamingLineBuffer_5_pad.run<89>(StreamingLineBuffer_5_out0_stream_prepad, StreamingLineBuffer_5_out0_stream);
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
    ap_int<8> StreamingConv_5_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=2 complete
    ap_int<15> StreamingConv_5_biases[8][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_5;
    StreamingConv_5.run<90>(StreamingLineBuffer_5_out0_stream, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_0," << StreamingConv_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_1," << StreamingConv_5_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_0;
    StreamingLineBuffer_6_pixel_0.run<91>(StreamingConv_5_out0_stream[0], StreamingLineBuffer_6_out0_stream_prepad[11], StreamingLineBuffer_6_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_11," << StreamingLineBuffer_6_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_0," << StreamingLineBuffer_6_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_1;
    StreamingLineBuffer_6_pixel_1.run<92>(StreamingConv_5_out0_stream[1], StreamingLineBuffer_6_out0_stream_prepad[10], StreamingLineBuffer_6_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_10," << StreamingLineBuffer_6_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_1," << StreamingLineBuffer_6_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_2;
    StreamingLineBuffer_6_pixel_2.run<93>(StreamingLineBuffer_6_buffer_stream[0], StreamingLineBuffer_6_out0_stream_prepad[9], StreamingLineBuffer_6_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_9," << StreamingLineBuffer_6_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_2," << StreamingLineBuffer_6_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_3;
    StreamingLineBuffer_6_pixel_3.run<94>(StreamingLineBuffer_6_buffer_stream[1], StreamingLineBuffer_6_out0_stream_prepad[8], StreamingLineBuffer_6_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_8," << StreamingLineBuffer_6_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_3," << StreamingLineBuffer_6_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_4;
    StreamingLineBuffer_6_pixel_4.run<95>(StreamingLineBuffer_6_buffer_stream[2], StreamingLineBuffer_6_out0_stream_prepad[7], StreamingLineBuffer_6_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_7," << StreamingLineBuffer_6_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_4," << StreamingLineBuffer_6_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_5;
    StreamingLineBuffer_6_pixel_5.run<96>(StreamingLineBuffer_6_buffer_stream[3], StreamingLineBuffer_6_out0_stream_prepad[6], StreamingLineBuffer_6_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_6," << StreamingLineBuffer_6_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_5," << StreamingLineBuffer_6_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_6;
    StreamingLineBuffer_6_pixel_6.run<97>(StreamingLineBuffer_6_buffer_stream[4], StreamingLineBuffer_6_out0_stream_prepad[5], StreamingLineBuffer_6_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_5," << StreamingLineBuffer_6_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_6," << StreamingLineBuffer_6_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_7;
    StreamingLineBuffer_6_pixel_7.run<98>(StreamingLineBuffer_6_buffer_stream[5], StreamingLineBuffer_6_out0_stream_prepad[4], StreamingLineBuffer_6_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_4," << StreamingLineBuffer_6_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_7," << StreamingLineBuffer_6_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_8;
    StreamingLineBuffer_6_pixel_8.run<99>(StreamingLineBuffer_6_buffer_stream[6], StreamingLineBuffer_6_out0_stream_prepad[3], StreamingLineBuffer_6_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_3," << StreamingLineBuffer_6_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_8," << StreamingLineBuffer_6_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_9;
    StreamingLineBuffer_6_pixel_9.run<100>(StreamingLineBuffer_6_buffer_stream[7], StreamingLineBuffer_6_out0_stream_prepad[2], StreamingLineBuffer_6_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_2," << StreamingLineBuffer_6_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_9," << StreamingLineBuffer_6_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_10;
    StreamingLineBuffer_6_pixel_10.run<101>(StreamingLineBuffer_6_buffer_stream[8], StreamingLineBuffer_6_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_1," << StreamingLineBuffer_6_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_6_pixel_11;
    StreamingLineBuffer_6_pixel_11.run<102>(StreamingLineBuffer_6_buffer_stream[9], StreamingLineBuffer_6_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_0," << StreamingLineBuffer_6_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_6_pad;
    StreamingLineBuffer_6_pad.run<103>(StreamingLineBuffer_6_out0_stream_prepad, StreamingLineBuffer_6_out0_stream);
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
    ap_int<8> StreamingConv_6_weights[128][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=2 complete
    ap_int<13> StreamingConv_6_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
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
    > StreamingConv_6;
    StreamingConv_6.run<104>(StreamingLineBuffer_6_out0_stream, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_0," << StreamingConv_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_1," << StreamingConv_6_out0_stream[1].size() << std::endl;
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
        DequantQuantPo2<1, ap_int<10>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_uint<8>>,  // AlignB
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_2;
    StreamingAdd_2.run<105>(StreamingConv_6_out0_stream, TensorDuplicator_2_out1_stream, StreamingAdd_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_0," << StreamingAdd_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_1," << StreamingAdd_2_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        32,  // IN_HEIGHT
        32,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_3;
    TensorDuplicator_3.run<106>(StreamingAdd_2_out0_stream, TensorDuplicator_3_out0_stream, TensorDuplicator_3_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out0_stream_0," << TensorDuplicator_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out0_stream_1," << TensorDuplicator_3_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out1_stream_0," << TensorDuplicator_3_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_3_out1_stream_1," << TensorDuplicator_3_out1_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_0;
    StreamingLineBuffer_7_pixel_0.run<107>(TensorDuplicator_3_out0_stream[1], StreamingLineBuffer_7_out0_stream_prepad[14], StreamingLineBuffer_7_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_14," << StreamingLineBuffer_7_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_0," << StreamingLineBuffer_7_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_1;
    StreamingLineBuffer_7_pixel_1.run<108>(TensorDuplicator_3_out0_stream[0], StreamingLineBuffer_7_out0_stream_prepad[13], StreamingLineBuffer_7_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_13," << StreamingLineBuffer_7_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_1," << StreamingLineBuffer_7_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_8_pixel_0;
    StreamingLineBuffer_8_pixel_0.run<123>(TensorDuplicator_3_out1_stream[0], StreamingLineBuffer_8_out0_stream[2], StreamingLineBuffer_8_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_2," << StreamingLineBuffer_8_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_0," << StreamingLineBuffer_8_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_8_pixel_1;
    StreamingLineBuffer_8_pixel_1.run<124>(TensorDuplicator_3_out1_stream[1], StreamingLineBuffer_8_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_1," << StreamingLineBuffer_8_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_2;
    StreamingLineBuffer_7_pixel_2.run<109>(StreamingLineBuffer_7_buffer_stream[0], StreamingLineBuffer_7_out0_stream_prepad[12], StreamingLineBuffer_7_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_12," << StreamingLineBuffer_7_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_2," << StreamingLineBuffer_7_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_3;
    StreamingLineBuffer_7_pixel_3.run<110>(StreamingLineBuffer_7_buffer_stream[1], StreamingLineBuffer_7_out0_stream_prepad[11], StreamingLineBuffer_7_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_11," << StreamingLineBuffer_7_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_4," << StreamingLineBuffer_7_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_8_pixel_2;
    StreamingLineBuffer_8_pixel_2.run<125>(StreamingLineBuffer_8_buffer_stream[0], StreamingLineBuffer_8_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_0," << StreamingLineBuffer_8_out0_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_4;
    StreamingLineBuffer_7_pixel_4.run<111>(StreamingLineBuffer_7_buffer_stream[2], StreamingLineBuffer_7_out0_stream_prepad[10], StreamingLineBuffer_7_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_10," << StreamingLineBuffer_7_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_3," << StreamingLineBuffer_7_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_6;
    StreamingLineBuffer_7_pixel_6.run<113>(StreamingLineBuffer_7_buffer_stream[4], StreamingLineBuffer_7_out0_stream_prepad[8], StreamingLineBuffer_7_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_8," << StreamingLineBuffer_7_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_6," << StreamingLineBuffer_7_buffer_stream[6].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_8_weights[256][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=2 complete
    ap_int<13> StreamingConv_8_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        DequantQuantEqual<ap_int<23>>,  // Activation
        DequantQuantPo2<6, ap_int<23>, ap_int<8>>,  // Quantizer
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
        2  // W_PAR
    > StreamingConv_8;
    StreamingConv_8.run<127>(StreamingLineBuffer_8_out0_stream, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_0," << StreamingConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_1," << StreamingConv_8_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_5;
    StreamingLineBuffer_7_pixel_5.run<112>(StreamingLineBuffer_7_buffer_stream[3], StreamingLineBuffer_7_out0_stream_prepad[9], StreamingLineBuffer_7_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_9," << StreamingLineBuffer_7_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_5," << StreamingLineBuffer_7_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_8;
    StreamingLineBuffer_7_pixel_8.run<115>(StreamingLineBuffer_7_buffer_stream[6], StreamingLineBuffer_7_out0_stream_prepad[6], StreamingLineBuffer_7_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_6," << StreamingLineBuffer_7_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_9," << StreamingLineBuffer_7_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_7;
    StreamingLineBuffer_7_pixel_7.run<114>(StreamingLineBuffer_7_buffer_stream[5], StreamingLineBuffer_7_out0_stream_prepad[7], StreamingLineBuffer_7_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_7," << StreamingLineBuffer_7_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_7," << StreamingLineBuffer_7_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_11;
    StreamingLineBuffer_7_pixel_11.run<118>(StreamingLineBuffer_7_buffer_stream[9], StreamingLineBuffer_7_out0_stream_prepad[3], StreamingLineBuffer_7_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_3," << StreamingLineBuffer_7_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_11," << StreamingLineBuffer_7_buffer_stream[11].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_9;
    StreamingLineBuffer_7_pixel_9.run<116>(StreamingLineBuffer_7_buffer_stream[7], StreamingLineBuffer_7_out0_stream_prepad[5], StreamingLineBuffer_7_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_5," << StreamingLineBuffer_7_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_8," << StreamingLineBuffer_7_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_13;
    StreamingLineBuffer_7_pixel_13.run<120>(StreamingLineBuffer_7_buffer_stream[11], StreamingLineBuffer_7_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_1," << StreamingLineBuffer_7_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_10;
    StreamingLineBuffer_7_pixel_10.run<117>(StreamingLineBuffer_7_buffer_stream[8], StreamingLineBuffer_7_out0_stream_prepad[4], StreamingLineBuffer_7_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_4," << StreamingLineBuffer_7_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_10," << StreamingLineBuffer_7_buffer_stream[10].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_12;
    StreamingLineBuffer_7_pixel_12.run<119>(StreamingLineBuffer_7_buffer_stream[10], StreamingLineBuffer_7_out0_stream_prepad[2], StreamingLineBuffer_7_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_2," << StreamingLineBuffer_7_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_buffer_stream_12," << StreamingLineBuffer_7_buffer_stream[12].size() << std::endl;
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
    > StreamingLineBuffer_7_pixel_14;
    StreamingLineBuffer_7_pixel_14.run<121>(StreamingLineBuffer_7_buffer_stream[12], StreamingLineBuffer_7_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_prepad_0," << StreamingLineBuffer_7_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_7_pad;
    StreamingLineBuffer_7_pad.run<122>(StreamingLineBuffer_7_out0_stream_prepad, StreamingLineBuffer_7_out0_stream);
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
    ap_int<8> StreamingConv_7_weights[512][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=2 complete
    ap_int<17> StreamingConv_7_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<17>, 1>,  // TBiasWord
        ap_int<17>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_7;
    StreamingConv_7.run<126>(StreamingLineBuffer_7_out0_stream, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_0," << StreamingConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_1," << StreamingConv_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_0;
    StreamingLineBuffer_9_pixel_0.run<128>(StreamingConv_7_out0_stream[0], StreamingLineBuffer_9_out0_stream_prepad[11], StreamingLineBuffer_9_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_11," << StreamingLineBuffer_9_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_0," << StreamingLineBuffer_9_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_1;
    StreamingLineBuffer_9_pixel_1.run<129>(StreamingConv_7_out0_stream[1], StreamingLineBuffer_9_out0_stream_prepad[10], StreamingLineBuffer_9_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_10," << StreamingLineBuffer_9_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_1," << StreamingLineBuffer_9_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_2;
    StreamingLineBuffer_9_pixel_2.run<130>(StreamingLineBuffer_9_buffer_stream[0], StreamingLineBuffer_9_out0_stream_prepad[9], StreamingLineBuffer_9_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_9," << StreamingLineBuffer_9_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_2," << StreamingLineBuffer_9_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_3;
    StreamingLineBuffer_9_pixel_3.run<131>(StreamingLineBuffer_9_buffer_stream[1], StreamingLineBuffer_9_out0_stream_prepad[8], StreamingLineBuffer_9_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_8," << StreamingLineBuffer_9_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_3," << StreamingLineBuffer_9_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_4;
    StreamingLineBuffer_9_pixel_4.run<132>(StreamingLineBuffer_9_buffer_stream[2], StreamingLineBuffer_9_out0_stream_prepad[7], StreamingLineBuffer_9_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_7," << StreamingLineBuffer_9_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_4," << StreamingLineBuffer_9_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_5;
    StreamingLineBuffer_9_pixel_5.run<133>(StreamingLineBuffer_9_buffer_stream[3], StreamingLineBuffer_9_out0_stream_prepad[6], StreamingLineBuffer_9_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_6," << StreamingLineBuffer_9_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_5," << StreamingLineBuffer_9_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_6;
    StreamingLineBuffer_9_pixel_6.run<134>(StreamingLineBuffer_9_buffer_stream[4], StreamingLineBuffer_9_out0_stream_prepad[5], StreamingLineBuffer_9_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_5," << StreamingLineBuffer_9_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_6," << StreamingLineBuffer_9_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_7;
    StreamingLineBuffer_9_pixel_7.run<135>(StreamingLineBuffer_9_buffer_stream[5], StreamingLineBuffer_9_out0_stream_prepad[4], StreamingLineBuffer_9_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_4," << StreamingLineBuffer_9_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_7," << StreamingLineBuffer_9_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_8;
    StreamingLineBuffer_9_pixel_8.run<136>(StreamingLineBuffer_9_buffer_stream[6], StreamingLineBuffer_9_out0_stream_prepad[3], StreamingLineBuffer_9_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_3," << StreamingLineBuffer_9_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_8," << StreamingLineBuffer_9_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_9;
    StreamingLineBuffer_9_pixel_9.run<137>(StreamingLineBuffer_9_buffer_stream[7], StreamingLineBuffer_9_out0_stream_prepad[2], StreamingLineBuffer_9_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_2," << StreamingLineBuffer_9_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_9," << StreamingLineBuffer_9_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_10;
    StreamingLineBuffer_9_pixel_10.run<138>(StreamingLineBuffer_9_buffer_stream[8], StreamingLineBuffer_9_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_1," << StreamingLineBuffer_9_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_9_pixel_11;
    StreamingLineBuffer_9_pixel_11.run<139>(StreamingLineBuffer_9_buffer_stream[9], StreamingLineBuffer_9_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_0," << StreamingLineBuffer_9_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_9_pad;
    StreamingLineBuffer_9_pad.run<140>(StreamingLineBuffer_9_out0_stream_prepad, StreamingLineBuffer_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_0," << StreamingLineBuffer_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_1," << StreamingLineBuffer_9_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_2," << StreamingLineBuffer_9_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_3," << StreamingLineBuffer_9_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_4," << StreamingLineBuffer_9_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_5," << StreamingLineBuffer_9_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_6," << StreamingLineBuffer_9_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_7," << StreamingLineBuffer_9_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_8," << StreamingLineBuffer_9_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_9," << StreamingLineBuffer_9_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_10," << StreamingLineBuffer_9_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_11," << StreamingLineBuffer_9_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_9_weights[512][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=2 complete
    ap_int<15> StreamingConv_9_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<7, ap_int<27>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_9;
    StreamingConv_9.run<141>(StreamingLineBuffer_9_out0_stream, StreamingConv_9_weights, StreamingConv_9_biases, StreamingConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_0," << StreamingConv_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_1," << StreamingConv_9_out0_stream[1].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_3;
    StreamingAdd_3.run<142>(StreamingConv_9_out0_stream, StreamingConv_8_out0_stream, StreamingAdd_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_0," << StreamingAdd_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_1," << StreamingAdd_3_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_4;
    TensorDuplicator_4.run<143>(StreamingAdd_3_out0_stream, TensorDuplicator_4_out0_stream, TensorDuplicator_4_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out0_stream_0," << TensorDuplicator_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out0_stream_1," << TensorDuplicator_4_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out1_stream_0," << TensorDuplicator_4_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_4_out1_stream_1," << TensorDuplicator_4_out1_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_0;
    StreamingLineBuffer_10_pixel_0.run<144>(TensorDuplicator_4_out0_stream[0], StreamingLineBuffer_10_out0_stream_prepad[11], StreamingLineBuffer_10_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_11," << StreamingLineBuffer_10_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_0," << StreamingLineBuffer_10_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_1;
    StreamingLineBuffer_10_pixel_1.run<145>(TensorDuplicator_4_out0_stream[1], StreamingLineBuffer_10_out0_stream_prepad[10], StreamingLineBuffer_10_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_10," << StreamingLineBuffer_10_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_1," << StreamingLineBuffer_10_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_2;
    StreamingLineBuffer_10_pixel_2.run<146>(StreamingLineBuffer_10_buffer_stream[0], StreamingLineBuffer_10_out0_stream_prepad[9], StreamingLineBuffer_10_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_9," << StreamingLineBuffer_10_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_2," << StreamingLineBuffer_10_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_3;
    StreamingLineBuffer_10_pixel_3.run<147>(StreamingLineBuffer_10_buffer_stream[1], StreamingLineBuffer_10_out0_stream_prepad[8], StreamingLineBuffer_10_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_8," << StreamingLineBuffer_10_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_3," << StreamingLineBuffer_10_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_4;
    StreamingLineBuffer_10_pixel_4.run<148>(StreamingLineBuffer_10_buffer_stream[2], StreamingLineBuffer_10_out0_stream_prepad[7], StreamingLineBuffer_10_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_7," << StreamingLineBuffer_10_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_4," << StreamingLineBuffer_10_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_5;
    StreamingLineBuffer_10_pixel_5.run<149>(StreamingLineBuffer_10_buffer_stream[3], StreamingLineBuffer_10_out0_stream_prepad[6], StreamingLineBuffer_10_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_6," << StreamingLineBuffer_10_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_5," << StreamingLineBuffer_10_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_6;
    StreamingLineBuffer_10_pixel_6.run<150>(StreamingLineBuffer_10_buffer_stream[4], StreamingLineBuffer_10_out0_stream_prepad[5], StreamingLineBuffer_10_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_5," << StreamingLineBuffer_10_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_6," << StreamingLineBuffer_10_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_7;
    StreamingLineBuffer_10_pixel_7.run<151>(StreamingLineBuffer_10_buffer_stream[5], StreamingLineBuffer_10_out0_stream_prepad[4], StreamingLineBuffer_10_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_4," << StreamingLineBuffer_10_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_7," << StreamingLineBuffer_10_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_8;
    StreamingLineBuffer_10_pixel_8.run<152>(StreamingLineBuffer_10_buffer_stream[6], StreamingLineBuffer_10_out0_stream_prepad[3], StreamingLineBuffer_10_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_3," << StreamingLineBuffer_10_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_8," << StreamingLineBuffer_10_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_9;
    StreamingLineBuffer_10_pixel_9.run<153>(StreamingLineBuffer_10_buffer_stream[7], StreamingLineBuffer_10_out0_stream_prepad[2], StreamingLineBuffer_10_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_2," << StreamingLineBuffer_10_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_9," << StreamingLineBuffer_10_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_10;
    StreamingLineBuffer_10_pixel_10.run<154>(StreamingLineBuffer_10_buffer_stream[8], StreamingLineBuffer_10_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_1," << StreamingLineBuffer_10_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_10_pixel_11;
    StreamingLineBuffer_10_pixel_11.run<155>(StreamingLineBuffer_10_buffer_stream[9], StreamingLineBuffer_10_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_0," << StreamingLineBuffer_10_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_10_pad;
    StreamingLineBuffer_10_pad.run<156>(StreamingLineBuffer_10_out0_stream_prepad, StreamingLineBuffer_10_out0_stream);
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
    ap_int<8> StreamingConv_10_weights[512][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=2 complete
    ap_int<16> StreamingConv_10_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        ReLU<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_10;
    StreamingConv_10.run<157>(StreamingLineBuffer_10_out0_stream, StreamingConv_10_weights, StreamingConv_10_biases, StreamingConv_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_0," << StreamingConv_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_1," << StreamingConv_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_0;
    StreamingLineBuffer_11_pixel_0.run<158>(StreamingConv_10_out0_stream[0], StreamingLineBuffer_11_out0_stream_prepad[11], StreamingLineBuffer_11_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_11," << StreamingLineBuffer_11_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_0," << StreamingLineBuffer_11_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_1;
    StreamingLineBuffer_11_pixel_1.run<159>(StreamingConv_10_out0_stream[1], StreamingLineBuffer_11_out0_stream_prepad[10], StreamingLineBuffer_11_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_10," << StreamingLineBuffer_11_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_1," << StreamingLineBuffer_11_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_2;
    StreamingLineBuffer_11_pixel_2.run<160>(StreamingLineBuffer_11_buffer_stream[0], StreamingLineBuffer_11_out0_stream_prepad[9], StreamingLineBuffer_11_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_9," << StreamingLineBuffer_11_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_2," << StreamingLineBuffer_11_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_3;
    StreamingLineBuffer_11_pixel_3.run<161>(StreamingLineBuffer_11_buffer_stream[1], StreamingLineBuffer_11_out0_stream_prepad[8], StreamingLineBuffer_11_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_8," << StreamingLineBuffer_11_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_3," << StreamingLineBuffer_11_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_4;
    StreamingLineBuffer_11_pixel_4.run<162>(StreamingLineBuffer_11_buffer_stream[2], StreamingLineBuffer_11_out0_stream_prepad[7], StreamingLineBuffer_11_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_7," << StreamingLineBuffer_11_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_4," << StreamingLineBuffer_11_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_5;
    StreamingLineBuffer_11_pixel_5.run<163>(StreamingLineBuffer_11_buffer_stream[3], StreamingLineBuffer_11_out0_stream_prepad[6], StreamingLineBuffer_11_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_6," << StreamingLineBuffer_11_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_5," << StreamingLineBuffer_11_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_6;
    StreamingLineBuffer_11_pixel_6.run<164>(StreamingLineBuffer_11_buffer_stream[4], StreamingLineBuffer_11_out0_stream_prepad[5], StreamingLineBuffer_11_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_5," << StreamingLineBuffer_11_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_6," << StreamingLineBuffer_11_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_7;
    StreamingLineBuffer_11_pixel_7.run<165>(StreamingLineBuffer_11_buffer_stream[5], StreamingLineBuffer_11_out0_stream_prepad[4], StreamingLineBuffer_11_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_4," << StreamingLineBuffer_11_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_7," << StreamingLineBuffer_11_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_8;
    StreamingLineBuffer_11_pixel_8.run<166>(StreamingLineBuffer_11_buffer_stream[6], StreamingLineBuffer_11_out0_stream_prepad[3], StreamingLineBuffer_11_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_3," << StreamingLineBuffer_11_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_8," << StreamingLineBuffer_11_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_9;
    StreamingLineBuffer_11_pixel_9.run<167>(StreamingLineBuffer_11_buffer_stream[7], StreamingLineBuffer_11_out0_stream_prepad[2], StreamingLineBuffer_11_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_2," << StreamingLineBuffer_11_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_9," << StreamingLineBuffer_11_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_10;
    StreamingLineBuffer_11_pixel_10.run<168>(StreamingLineBuffer_11_buffer_stream[8], StreamingLineBuffer_11_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_1," << StreamingLineBuffer_11_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_11_pixel_11;
    StreamingLineBuffer_11_pixel_11.run<169>(StreamingLineBuffer_11_buffer_stream[9], StreamingLineBuffer_11_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_0," << StreamingLineBuffer_11_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_11_pad;
    StreamingLineBuffer_11_pad.run<170>(StreamingLineBuffer_11_out0_stream_prepad, StreamingLineBuffer_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_0," << StreamingLineBuffer_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_1," << StreamingLineBuffer_11_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_2," << StreamingLineBuffer_11_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_3," << StreamingLineBuffer_11_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_4," << StreamingLineBuffer_11_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_5," << StreamingLineBuffer_11_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_6," << StreamingLineBuffer_11_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_7," << StreamingLineBuffer_11_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_8," << StreamingLineBuffer_11_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_9," << StreamingLineBuffer_11_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_10," << StreamingLineBuffer_11_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_11," << StreamingLineBuffer_11_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_11_weights[512][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=2 complete
    ap_int<15> StreamingConv_11_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_11;
    StreamingConv_11.run<171>(StreamingLineBuffer_11_out0_stream, StreamingConv_11_weights, StreamingConv_11_biases, StreamingConv_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_0," << StreamingConv_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_1," << StreamingConv_11_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_uint<8>, 2>,  // TInputWordB
        ap_uint<8>,  // TInputB
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<10>,  // TAcc
        ReLU<ap_int<10>>,  // Activation
        DequantQuantPo2<0, ap_int<10>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_uint<8>>,  // AlignB
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_4;
    StreamingAdd_4.run<172>(StreamingConv_11_out0_stream, TensorDuplicator_4_out1_stream, StreamingAdd_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_0," << StreamingAdd_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_1," << StreamingAdd_4_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_5;
    TensorDuplicator_5.run<173>(StreamingAdd_4_out0_stream, TensorDuplicator_5_out0_stream, TensorDuplicator_5_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out0_stream_0," << TensorDuplicator_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out0_stream_1," << TensorDuplicator_5_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out1_stream_0," << TensorDuplicator_5_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_5_out1_stream_1," << TensorDuplicator_5_out1_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_0;
    StreamingLineBuffer_12_pixel_0.run<174>(TensorDuplicator_5_out0_stream[0], StreamingLineBuffer_12_out0_stream_prepad[11], StreamingLineBuffer_12_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_11," << StreamingLineBuffer_12_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_0," << StreamingLineBuffer_12_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_1;
    StreamingLineBuffer_12_pixel_1.run<175>(TensorDuplicator_5_out0_stream[1], StreamingLineBuffer_12_out0_stream_prepad[10], StreamingLineBuffer_12_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_10," << StreamingLineBuffer_12_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_1," << StreamingLineBuffer_12_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_2;
    StreamingLineBuffer_12_pixel_2.run<176>(StreamingLineBuffer_12_buffer_stream[0], StreamingLineBuffer_12_out0_stream_prepad[9], StreamingLineBuffer_12_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_9," << StreamingLineBuffer_12_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_2," << StreamingLineBuffer_12_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_3;
    StreamingLineBuffer_12_pixel_3.run<177>(StreamingLineBuffer_12_buffer_stream[1], StreamingLineBuffer_12_out0_stream_prepad[8], StreamingLineBuffer_12_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_8," << StreamingLineBuffer_12_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_3," << StreamingLineBuffer_12_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_4;
    StreamingLineBuffer_12_pixel_4.run<178>(StreamingLineBuffer_12_buffer_stream[2], StreamingLineBuffer_12_out0_stream_prepad[7], StreamingLineBuffer_12_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_7," << StreamingLineBuffer_12_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_4," << StreamingLineBuffer_12_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_5;
    StreamingLineBuffer_12_pixel_5.run<179>(StreamingLineBuffer_12_buffer_stream[3], StreamingLineBuffer_12_out0_stream_prepad[6], StreamingLineBuffer_12_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_6," << StreamingLineBuffer_12_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_5," << StreamingLineBuffer_12_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_6;
    StreamingLineBuffer_12_pixel_6.run<180>(StreamingLineBuffer_12_buffer_stream[4], StreamingLineBuffer_12_out0_stream_prepad[5], StreamingLineBuffer_12_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_5," << StreamingLineBuffer_12_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_6," << StreamingLineBuffer_12_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_7;
    StreamingLineBuffer_12_pixel_7.run<181>(StreamingLineBuffer_12_buffer_stream[5], StreamingLineBuffer_12_out0_stream_prepad[4], StreamingLineBuffer_12_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_4," << StreamingLineBuffer_12_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_7," << StreamingLineBuffer_12_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_8;
    StreamingLineBuffer_12_pixel_8.run<182>(StreamingLineBuffer_12_buffer_stream[6], StreamingLineBuffer_12_out0_stream_prepad[3], StreamingLineBuffer_12_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_3," << StreamingLineBuffer_12_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_8," << StreamingLineBuffer_12_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_9;
    StreamingLineBuffer_12_pixel_9.run<183>(StreamingLineBuffer_12_buffer_stream[7], StreamingLineBuffer_12_out0_stream_prepad[2], StreamingLineBuffer_12_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_2," << StreamingLineBuffer_12_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_buffer_stream_9," << StreamingLineBuffer_12_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_10;
    StreamingLineBuffer_12_pixel_10.run<184>(StreamingLineBuffer_12_buffer_stream[8], StreamingLineBuffer_12_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_1," << StreamingLineBuffer_12_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_12_pixel_11;
    StreamingLineBuffer_12_pixel_11.run<185>(StreamingLineBuffer_12_buffer_stream[9], StreamingLineBuffer_12_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_prepad_0," << StreamingLineBuffer_12_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_12_pad;
    StreamingLineBuffer_12_pad.run<186>(StreamingLineBuffer_12_out0_stream_prepad, StreamingLineBuffer_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_0," << StreamingLineBuffer_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_1," << StreamingLineBuffer_12_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_2," << StreamingLineBuffer_12_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_3," << StreamingLineBuffer_12_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_4," << StreamingLineBuffer_12_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_5," << StreamingLineBuffer_12_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_6," << StreamingLineBuffer_12_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_7," << StreamingLineBuffer_12_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_8," << StreamingLineBuffer_12_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_9," << StreamingLineBuffer_12_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_10," << StreamingLineBuffer_12_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_11," << StreamingLineBuffer_12_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_12_weights[512][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=2 complete
    ap_int<16> StreamingConv_12_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        ReLU<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_uint<8>>,  // Quantizer
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
    > StreamingConv_12;
    StreamingConv_12.run<187>(StreamingLineBuffer_12_out0_stream, StreamingConv_12_weights, StreamingConv_12_biases, StreamingConv_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_0," << StreamingConv_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_1," << StreamingConv_12_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_0;
    StreamingLineBuffer_13_pixel_0.run<188>(StreamingConv_12_out0_stream[0], StreamingLineBuffer_13_out0_stream_prepad[11], StreamingLineBuffer_13_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_11," << StreamingLineBuffer_13_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_0," << StreamingLineBuffer_13_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_1;
    StreamingLineBuffer_13_pixel_1.run<189>(StreamingConv_12_out0_stream[1], StreamingLineBuffer_13_out0_stream_prepad[10], StreamingLineBuffer_13_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_10," << StreamingLineBuffer_13_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_1," << StreamingLineBuffer_13_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_2;
    StreamingLineBuffer_13_pixel_2.run<190>(StreamingLineBuffer_13_buffer_stream[0], StreamingLineBuffer_13_out0_stream_prepad[9], StreamingLineBuffer_13_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_9," << StreamingLineBuffer_13_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_2," << StreamingLineBuffer_13_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_3;
    StreamingLineBuffer_13_pixel_3.run<191>(StreamingLineBuffer_13_buffer_stream[1], StreamingLineBuffer_13_out0_stream_prepad[8], StreamingLineBuffer_13_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_8," << StreamingLineBuffer_13_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_3," << StreamingLineBuffer_13_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_4;
    StreamingLineBuffer_13_pixel_4.run<192>(StreamingLineBuffer_13_buffer_stream[2], StreamingLineBuffer_13_out0_stream_prepad[7], StreamingLineBuffer_13_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_7," << StreamingLineBuffer_13_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_4," << StreamingLineBuffer_13_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_5;
    StreamingLineBuffer_13_pixel_5.run<193>(StreamingLineBuffer_13_buffer_stream[3], StreamingLineBuffer_13_out0_stream_prepad[6], StreamingLineBuffer_13_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_6," << StreamingLineBuffer_13_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_5," << StreamingLineBuffer_13_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_6;
    StreamingLineBuffer_13_pixel_6.run<194>(StreamingLineBuffer_13_buffer_stream[4], StreamingLineBuffer_13_out0_stream_prepad[5], StreamingLineBuffer_13_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_5," << StreamingLineBuffer_13_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_6," << StreamingLineBuffer_13_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_7;
    StreamingLineBuffer_13_pixel_7.run<195>(StreamingLineBuffer_13_buffer_stream[5], StreamingLineBuffer_13_out0_stream_prepad[4], StreamingLineBuffer_13_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_4," << StreamingLineBuffer_13_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_7," << StreamingLineBuffer_13_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_8;
    StreamingLineBuffer_13_pixel_8.run<196>(StreamingLineBuffer_13_buffer_stream[6], StreamingLineBuffer_13_out0_stream_prepad[3], StreamingLineBuffer_13_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_3," << StreamingLineBuffer_13_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_8," << StreamingLineBuffer_13_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_9;
    StreamingLineBuffer_13_pixel_9.run<197>(StreamingLineBuffer_13_buffer_stream[7], StreamingLineBuffer_13_out0_stream_prepad[2], StreamingLineBuffer_13_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_2," << StreamingLineBuffer_13_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_buffer_stream_9," << StreamingLineBuffer_13_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_10;
    StreamingLineBuffer_13_pixel_10.run<198>(StreamingLineBuffer_13_buffer_stream[8], StreamingLineBuffer_13_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_1," << StreamingLineBuffer_13_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_11;
    StreamingLineBuffer_13_pixel_11.run<199>(StreamingLineBuffer_13_buffer_stream[9], StreamingLineBuffer_13_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_prepad_0," << StreamingLineBuffer_13_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_13_pad;
    StreamingLineBuffer_13_pad.run<200>(StreamingLineBuffer_13_out0_stream_prepad, StreamingLineBuffer_13_out0_stream);
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
    ap_int<8> StreamingConv_13_weights[512][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=2 complete
    ap_int<14> StreamingConv_13_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<7, ap_int<27>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        16,  // OUT_HEIGHT
        16,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_13;
    StreamingConv_13.run<201>(StreamingLineBuffer_13_out0_stream, StreamingConv_13_weights, StreamingConv_13_biases, StreamingConv_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_13_out0_stream_0," << StreamingConv_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_13_out0_stream_1," << StreamingConv_13_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_uint<8>, 2>,  // TInputWordB
        ap_uint<8>,  // TInputB
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<10>,  // TAcc
        ReLU<ap_int<10>>,  // Activation
        DequantQuantPo2<1, ap_int<10>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_uint<8>>,  // AlignB
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_5;
    StreamingAdd_5.run<202>(StreamingConv_13_out0_stream, TensorDuplicator_5_out1_stream, StreamingAdd_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_0," << StreamingAdd_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_1," << StreamingAdd_5_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 2>,  // TWord
        16,  // IN_HEIGHT
        16,  // IN_WIDTH
        32,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_6;
    TensorDuplicator_6.run<203>(StreamingAdd_5_out0_stream, TensorDuplicator_6_out0_stream, TensorDuplicator_6_out1_stream);
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_0;
    StreamingLineBuffer_14_pixel_0.run<204>(TensorDuplicator_6_out0_stream[1], StreamingLineBuffer_14_out0_stream_prepad[14], StreamingLineBuffer_14_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_14," << StreamingLineBuffer_14_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_0," << StreamingLineBuffer_14_buffer_stream[0].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_1;
    StreamingLineBuffer_14_pixel_1.run<205>(TensorDuplicator_6_out0_stream[0], StreamingLineBuffer_14_out0_stream_prepad[13], StreamingLineBuffer_14_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_13," << StreamingLineBuffer_14_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_1," << StreamingLineBuffer_14_buffer_stream[1].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_15_pixel_0;
    StreamingLineBuffer_15_pixel_0.run<220>(TensorDuplicator_6_out1_stream[0], StreamingLineBuffer_15_out0_stream[2], StreamingLineBuffer_15_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_2," << StreamingLineBuffer_15_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_buffer_stream_0," << StreamingLineBuffer_15_buffer_stream[0].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_15_pixel_1;
    StreamingLineBuffer_15_pixel_1.run<221>(TensorDuplicator_6_out1_stream[1], StreamingLineBuffer_15_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_1," << StreamingLineBuffer_15_out0_stream[1].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_2;
    StreamingLineBuffer_14_pixel_2.run<206>(StreamingLineBuffer_14_buffer_stream[0], StreamingLineBuffer_14_out0_stream_prepad[12], StreamingLineBuffer_14_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_12," << StreamingLineBuffer_14_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_2," << StreamingLineBuffer_14_buffer_stream[2].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_3;
    StreamingLineBuffer_14_pixel_3.run<207>(StreamingLineBuffer_14_buffer_stream[1], StreamingLineBuffer_14_out0_stream_prepad[11], StreamingLineBuffer_14_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_11," << StreamingLineBuffer_14_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_4," << StreamingLineBuffer_14_buffer_stream[4].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_15_pixel_2;
    StreamingLineBuffer_15_pixel_2.run<222>(StreamingLineBuffer_15_buffer_stream[0], StreamingLineBuffer_15_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_0," << StreamingLineBuffer_15_out0_stream[0].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_4;
    StreamingLineBuffer_14_pixel_4.run<208>(StreamingLineBuffer_14_buffer_stream[2], StreamingLineBuffer_14_out0_stream_prepad[10], StreamingLineBuffer_14_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_10," << StreamingLineBuffer_14_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_3," << StreamingLineBuffer_14_buffer_stream[3].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_6;
    StreamingLineBuffer_14_pixel_6.run<210>(StreamingLineBuffer_14_buffer_stream[4], StreamingLineBuffer_14_out0_stream_prepad[8], StreamingLineBuffer_14_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_8," << StreamingLineBuffer_14_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_6," << StreamingLineBuffer_14_buffer_stream[6].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_15_weights[1024][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=2 complete
    ap_int<14> StreamingConv_15_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_int<8>>,  // Quantizer
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
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_15;
    StreamingConv_15.run<224>(StreamingLineBuffer_15_out0_stream, StreamingConv_15_weights, StreamingConv_15_biases, StreamingConv_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_0," << StreamingConv_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_1," << StreamingConv_15_out0_stream[1].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_5;
    StreamingLineBuffer_14_pixel_5.run<209>(StreamingLineBuffer_14_buffer_stream[3], StreamingLineBuffer_14_out0_stream_prepad[9], StreamingLineBuffer_14_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_9," << StreamingLineBuffer_14_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_5," << StreamingLineBuffer_14_buffer_stream[5].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_8;
    StreamingLineBuffer_14_pixel_8.run<212>(StreamingLineBuffer_14_buffer_stream[6], StreamingLineBuffer_14_out0_stream_prepad[6], StreamingLineBuffer_14_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_6," << StreamingLineBuffer_14_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_9," << StreamingLineBuffer_14_buffer_stream[9].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_7;
    StreamingLineBuffer_14_pixel_7.run<211>(StreamingLineBuffer_14_buffer_stream[5], StreamingLineBuffer_14_out0_stream_prepad[7], StreamingLineBuffer_14_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_7," << StreamingLineBuffer_14_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_7," << StreamingLineBuffer_14_buffer_stream[7].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_11;
    StreamingLineBuffer_14_pixel_11.run<215>(StreamingLineBuffer_14_buffer_stream[9], StreamingLineBuffer_14_out0_stream_prepad[3], StreamingLineBuffer_14_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_3," << StreamingLineBuffer_14_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_11," << StreamingLineBuffer_14_buffer_stream[11].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_9;
    StreamingLineBuffer_14_pixel_9.run<213>(StreamingLineBuffer_14_buffer_stream[7], StreamingLineBuffer_14_out0_stream_prepad[5], StreamingLineBuffer_14_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_5," << StreamingLineBuffer_14_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_8," << StreamingLineBuffer_14_buffer_stream[8].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_13;
    StreamingLineBuffer_14_pixel_13.run<217>(StreamingLineBuffer_14_buffer_stream[11], StreamingLineBuffer_14_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_1," << StreamingLineBuffer_14_out0_stream_prepad[1].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_10;
    StreamingLineBuffer_14_pixel_10.run<214>(StreamingLineBuffer_14_buffer_stream[8], StreamingLineBuffer_14_out0_stream_prepad[4], StreamingLineBuffer_14_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_4," << StreamingLineBuffer_14_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_10," << StreamingLineBuffer_14_buffer_stream[10].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_12;
    StreamingLineBuffer_14_pixel_12.run<216>(StreamingLineBuffer_14_buffer_stream[10], StreamingLineBuffer_14_out0_stream_prepad[2], StreamingLineBuffer_14_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_2," << StreamingLineBuffer_14_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_12," << StreamingLineBuffer_14_buffer_stream[12].size() << std::endl;
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
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_14_pixel_14;
    StreamingLineBuffer_14_pixel_14.run<218>(StreamingLineBuffer_14_buffer_stream[12], StreamingLineBuffer_14_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_0," << StreamingLineBuffer_14_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_14_pad;
    StreamingLineBuffer_14_pad.run<219>(StreamingLineBuffer_14_out0_stream_prepad, StreamingLineBuffer_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_0," << StreamingLineBuffer_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_1," << StreamingLineBuffer_14_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_2," << StreamingLineBuffer_14_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_3," << StreamingLineBuffer_14_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_4," << StreamingLineBuffer_14_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_5," << StreamingLineBuffer_14_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_6," << StreamingLineBuffer_14_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_7," << StreamingLineBuffer_14_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_8," << StreamingLineBuffer_14_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_9," << StreamingLineBuffer_14_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_10," << StreamingLineBuffer_14_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_11," << StreamingLineBuffer_14_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_12," << StreamingLineBuffer_14_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_13," << StreamingLineBuffer_14_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_14," << StreamingLineBuffer_14_out0_stream[14].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_14_weights[512][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=2 complete
    ap_int<16> StreamingConv_14_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        ReLU<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_uint<8>>,  // Quantizer
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
        2  // W_PAR
    > StreamingConv_14;
    StreamingConv_14.run<223>(StreamingLineBuffer_14_out0_stream, StreamingConv_14_weights, StreamingConv_14_biases, StreamingConv_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_0," << StreamingConv_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_1," << StreamingConv_14_out0_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_0;
    StreamingLineBuffer_16_pixel_0.run<225>(StreamingConv_14_out0_stream[0], StreamingLineBuffer_16_out0_stream_prepad[11], StreamingLineBuffer_16_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_11," << StreamingLineBuffer_16_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_0," << StreamingLineBuffer_16_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_1;
    StreamingLineBuffer_16_pixel_1.run<226>(StreamingConv_14_out0_stream[1], StreamingLineBuffer_16_out0_stream_prepad[10], StreamingLineBuffer_16_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_10," << StreamingLineBuffer_16_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_1," << StreamingLineBuffer_16_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_2;
    StreamingLineBuffer_16_pixel_2.run<227>(StreamingLineBuffer_16_buffer_stream[0], StreamingLineBuffer_16_out0_stream_prepad[9], StreamingLineBuffer_16_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_9," << StreamingLineBuffer_16_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_2," << StreamingLineBuffer_16_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_3;
    StreamingLineBuffer_16_pixel_3.run<228>(StreamingLineBuffer_16_buffer_stream[1], StreamingLineBuffer_16_out0_stream_prepad[8], StreamingLineBuffer_16_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_8," << StreamingLineBuffer_16_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_3," << StreamingLineBuffer_16_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_4;
    StreamingLineBuffer_16_pixel_4.run<229>(StreamingLineBuffer_16_buffer_stream[2], StreamingLineBuffer_16_out0_stream_prepad[7], StreamingLineBuffer_16_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_7," << StreamingLineBuffer_16_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_4," << StreamingLineBuffer_16_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_5;
    StreamingLineBuffer_16_pixel_5.run<230>(StreamingLineBuffer_16_buffer_stream[3], StreamingLineBuffer_16_out0_stream_prepad[6], StreamingLineBuffer_16_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_6," << StreamingLineBuffer_16_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_5," << StreamingLineBuffer_16_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_6;
    StreamingLineBuffer_16_pixel_6.run<231>(StreamingLineBuffer_16_buffer_stream[4], StreamingLineBuffer_16_out0_stream_prepad[5], StreamingLineBuffer_16_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_5," << StreamingLineBuffer_16_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_6," << StreamingLineBuffer_16_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_7;
    StreamingLineBuffer_16_pixel_7.run<232>(StreamingLineBuffer_16_buffer_stream[5], StreamingLineBuffer_16_out0_stream_prepad[4], StreamingLineBuffer_16_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_4," << StreamingLineBuffer_16_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_7," << StreamingLineBuffer_16_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_8;
    StreamingLineBuffer_16_pixel_8.run<233>(StreamingLineBuffer_16_buffer_stream[6], StreamingLineBuffer_16_out0_stream_prepad[3], StreamingLineBuffer_16_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_3," << StreamingLineBuffer_16_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_8," << StreamingLineBuffer_16_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_9;
    StreamingLineBuffer_16_pixel_9.run<234>(StreamingLineBuffer_16_buffer_stream[7], StreamingLineBuffer_16_out0_stream_prepad[2], StreamingLineBuffer_16_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_2," << StreamingLineBuffer_16_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_9," << StreamingLineBuffer_16_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_10;
    StreamingLineBuffer_16_pixel_10.run<235>(StreamingLineBuffer_16_buffer_stream[8], StreamingLineBuffer_16_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_1," << StreamingLineBuffer_16_out0_stream_prepad[1].size() << std::endl;
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
    > StreamingLineBuffer_16_pixel_11;
    StreamingLineBuffer_16_pixel_11.run<236>(StreamingLineBuffer_16_buffer_stream[9], StreamingLineBuffer_16_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_0," << StreamingLineBuffer_16_out0_stream_prepad[0].size() << std::endl;
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
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_16_pad;
    StreamingLineBuffer_16_pad.run<237>(StreamingLineBuffer_16_out0_stream_prepad, StreamingLineBuffer_16_out0_stream);
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
    ap_int<8> StreamingConv_16_weights[2048][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=2 complete
    ap_int<15> StreamingConv_16_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 2>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
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
    > StreamingConv_16;
    StreamingConv_16.run<238>(StreamingLineBuffer_16_out0_stream, StreamingConv_16_weights, StreamingConv_16_biases, StreamingConv_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_0," << StreamingConv_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_1," << StreamingConv_16_out0_stream[1].size() << std::endl;
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
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_6;
    StreamingAdd_6.run<239>(StreamingConv_16_out0_stream, StreamingConv_15_out0_stream, StreamingAdd_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_0," << StreamingAdd_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_1," << StreamingAdd_6_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_7;
    TensorDuplicator_7.run<240>(StreamingAdd_6_out0_stream, TensorDuplicator_7_out0_stream, TensorDuplicator_7_out1_stream);
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
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_0;
    StreamingLineBuffer_17_pixel_0.run<241>(TensorDuplicator_7_out0_stream[0], StreamingLineBuffer_17_out0_stream_prepad[11], StreamingLineBuffer_17_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_11," << StreamingLineBuffer_17_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_0," << StreamingLineBuffer_17_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_1;
    StreamingLineBuffer_17_pixel_1.run<242>(TensorDuplicator_7_out0_stream[1], StreamingLineBuffer_17_out0_stream_prepad[10], StreamingLineBuffer_17_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_10," << StreamingLineBuffer_17_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_1," << StreamingLineBuffer_17_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_2;
    StreamingLineBuffer_17_pixel_2.run<243>(StreamingLineBuffer_17_buffer_stream[0], StreamingLineBuffer_17_out0_stream_prepad[9], StreamingLineBuffer_17_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_9," << StreamingLineBuffer_17_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_2," << StreamingLineBuffer_17_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_3;
    StreamingLineBuffer_17_pixel_3.run<244>(StreamingLineBuffer_17_buffer_stream[1], StreamingLineBuffer_17_out0_stream_prepad[8], StreamingLineBuffer_17_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_8," << StreamingLineBuffer_17_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_3," << StreamingLineBuffer_17_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_4;
    StreamingLineBuffer_17_pixel_4.run<245>(StreamingLineBuffer_17_buffer_stream[2], StreamingLineBuffer_17_out0_stream_prepad[7], StreamingLineBuffer_17_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_7," << StreamingLineBuffer_17_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_4," << StreamingLineBuffer_17_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_5;
    StreamingLineBuffer_17_pixel_5.run<246>(StreamingLineBuffer_17_buffer_stream[3], StreamingLineBuffer_17_out0_stream_prepad[6], StreamingLineBuffer_17_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_6," << StreamingLineBuffer_17_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_5," << StreamingLineBuffer_17_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_6;
    StreamingLineBuffer_17_pixel_6.run<247>(StreamingLineBuffer_17_buffer_stream[4], StreamingLineBuffer_17_out0_stream_prepad[5], StreamingLineBuffer_17_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_5," << StreamingLineBuffer_17_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_6," << StreamingLineBuffer_17_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_7;
    StreamingLineBuffer_17_pixel_7.run<248>(StreamingLineBuffer_17_buffer_stream[5], StreamingLineBuffer_17_out0_stream_prepad[4], StreamingLineBuffer_17_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_4," << StreamingLineBuffer_17_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_7," << StreamingLineBuffer_17_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_8;
    StreamingLineBuffer_17_pixel_8.run<249>(StreamingLineBuffer_17_buffer_stream[6], StreamingLineBuffer_17_out0_stream_prepad[3], StreamingLineBuffer_17_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_3," << StreamingLineBuffer_17_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_8," << StreamingLineBuffer_17_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_9;
    StreamingLineBuffer_17_pixel_9.run<250>(StreamingLineBuffer_17_buffer_stream[7], StreamingLineBuffer_17_out0_stream_prepad[2], StreamingLineBuffer_17_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_2," << StreamingLineBuffer_17_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_9," << StreamingLineBuffer_17_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_10;
    StreamingLineBuffer_17_pixel_10.run<251>(StreamingLineBuffer_17_buffer_stream[8], StreamingLineBuffer_17_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_1," << StreamingLineBuffer_17_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_17_pixel_11;
    StreamingLineBuffer_17_pixel_11.run<252>(StreamingLineBuffer_17_buffer_stream[9], StreamingLineBuffer_17_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_0," << StreamingLineBuffer_17_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_17_pad;
    StreamingLineBuffer_17_pad.run<253>(StreamingLineBuffer_17_out0_stream_prepad, StreamingLineBuffer_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_0," << StreamingLineBuffer_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_1," << StreamingLineBuffer_17_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_2," << StreamingLineBuffer_17_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_3," << StreamingLineBuffer_17_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_4," << StreamingLineBuffer_17_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_5," << StreamingLineBuffer_17_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_6," << StreamingLineBuffer_17_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_7," << StreamingLineBuffer_17_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_8," << StreamingLineBuffer_17_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_9," << StreamingLineBuffer_17_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_10," << StreamingLineBuffer_17_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_11," << StreamingLineBuffer_17_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_17_weights[1024][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=2 complete
    ap_int<15> StreamingConv_17_biases[16][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        ReLU<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_uint<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_17;
    StreamingConv_17.run<254>(StreamingLineBuffer_17_out0_stream, StreamingConv_17_weights, StreamingConv_17_biases, StreamingConv_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_0," << StreamingConv_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_1," << StreamingConv_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_0;
    StreamingLineBuffer_18_pixel_0.run<255>(StreamingConv_17_out0_stream[0], StreamingLineBuffer_18_out0_stream_prepad[11], StreamingLineBuffer_18_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_11," << StreamingLineBuffer_18_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_0," << StreamingLineBuffer_18_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_1;
    StreamingLineBuffer_18_pixel_1.run<256>(StreamingConv_17_out0_stream[1], StreamingLineBuffer_18_out0_stream_prepad[10], StreamingLineBuffer_18_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_10," << StreamingLineBuffer_18_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_1," << StreamingLineBuffer_18_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_2;
    StreamingLineBuffer_18_pixel_2.run<257>(StreamingLineBuffer_18_buffer_stream[0], StreamingLineBuffer_18_out0_stream_prepad[9], StreamingLineBuffer_18_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_9," << StreamingLineBuffer_18_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_2," << StreamingLineBuffer_18_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_3;
    StreamingLineBuffer_18_pixel_3.run<258>(StreamingLineBuffer_18_buffer_stream[1], StreamingLineBuffer_18_out0_stream_prepad[8], StreamingLineBuffer_18_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_8," << StreamingLineBuffer_18_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_3," << StreamingLineBuffer_18_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_4;
    StreamingLineBuffer_18_pixel_4.run<259>(StreamingLineBuffer_18_buffer_stream[2], StreamingLineBuffer_18_out0_stream_prepad[7], StreamingLineBuffer_18_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_7," << StreamingLineBuffer_18_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_4," << StreamingLineBuffer_18_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_5;
    StreamingLineBuffer_18_pixel_5.run<260>(StreamingLineBuffer_18_buffer_stream[3], StreamingLineBuffer_18_out0_stream_prepad[6], StreamingLineBuffer_18_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_6," << StreamingLineBuffer_18_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_5," << StreamingLineBuffer_18_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_6;
    StreamingLineBuffer_18_pixel_6.run<261>(StreamingLineBuffer_18_buffer_stream[4], StreamingLineBuffer_18_out0_stream_prepad[5], StreamingLineBuffer_18_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_5," << StreamingLineBuffer_18_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_6," << StreamingLineBuffer_18_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_7;
    StreamingLineBuffer_18_pixel_7.run<262>(StreamingLineBuffer_18_buffer_stream[5], StreamingLineBuffer_18_out0_stream_prepad[4], StreamingLineBuffer_18_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_4," << StreamingLineBuffer_18_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_7," << StreamingLineBuffer_18_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_8;
    StreamingLineBuffer_18_pixel_8.run<263>(StreamingLineBuffer_18_buffer_stream[6], StreamingLineBuffer_18_out0_stream_prepad[3], StreamingLineBuffer_18_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_3," << StreamingLineBuffer_18_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_8," << StreamingLineBuffer_18_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_9;
    StreamingLineBuffer_18_pixel_9.run<264>(StreamingLineBuffer_18_buffer_stream[7], StreamingLineBuffer_18_out0_stream_prepad[2], StreamingLineBuffer_18_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_2," << StreamingLineBuffer_18_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_9," << StreamingLineBuffer_18_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_10;
    StreamingLineBuffer_18_pixel_10.run<265>(StreamingLineBuffer_18_buffer_stream[8], StreamingLineBuffer_18_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_1," << StreamingLineBuffer_18_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_11;
    StreamingLineBuffer_18_pixel_11.run<266>(StreamingLineBuffer_18_buffer_stream[9], StreamingLineBuffer_18_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_0," << StreamingLineBuffer_18_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 4>,  // TWord
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
        2,  // W_PAR
        4,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_18_pad;
    StreamingLineBuffer_18_pad.run<267>(StreamingLineBuffer_18_out0_stream_prepad, StreamingLineBuffer_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_0," << StreamingLineBuffer_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_1," << StreamingLineBuffer_18_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_2," << StreamingLineBuffer_18_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_3," << StreamingLineBuffer_18_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_4," << StreamingLineBuffer_18_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_5," << StreamingLineBuffer_18_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_6," << StreamingLineBuffer_18_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_7," << StreamingLineBuffer_18_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_8," << StreamingLineBuffer_18_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_9," << StreamingLineBuffer_18_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_10," << StreamingLineBuffer_18_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_11," << StreamingLineBuffer_18_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_18_weights[1024][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=2 complete
    ap_int<15> StreamingConv_18_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 4>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_18;
    StreamingConv_18.run<268>(StreamingLineBuffer_18_out0_stream, StreamingConv_18_weights, StreamingConv_18_biases, StreamingConv_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_0," << StreamingConv_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_1," << StreamingConv_18_out0_stream[1].size() << std::endl;
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
        DequantQuantPo2<1, ap_int<10>, ap_uint<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_uint<8>>,  // AlignB
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_7;
    StreamingAdd_7.run<269>(StreamingConv_18_out0_stream, TensorDuplicator_7_out1_stream, StreamingAdd_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_0," << StreamingAdd_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_1," << StreamingAdd_7_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_uint<8>, 1>,  // TWord
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_8;
    TensorDuplicator_8.run<270>(StreamingAdd_7_out0_stream, TensorDuplicator_8_out0_stream, TensorDuplicator_8_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out0_stream_0," << TensorDuplicator_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out0_stream_1," << TensorDuplicator_8_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out1_stream_0," << TensorDuplicator_8_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_8_out1_stream_1," << TensorDuplicator_8_out1_stream[1].size() << std::endl;
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
    > BandwidthAdjustDecreaseStreams_0;
    BandwidthAdjustDecreaseStreams_0.run<271>(TensorDuplicator_8_out1_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_0," << BandwidthAdjustDecreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_0;
    StreamingLineBuffer_19_pixel_0.run<272>(TensorDuplicator_8_out0_stream[0], StreamingLineBuffer_19_out0_stream_prepad[11], StreamingLineBuffer_19_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_11," << StreamingLineBuffer_19_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_0," << StreamingLineBuffer_19_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_1;
    StreamingLineBuffer_19_pixel_1.run<273>(TensorDuplicator_8_out0_stream[1], StreamingLineBuffer_19_out0_stream_prepad[10], StreamingLineBuffer_19_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_10," << StreamingLineBuffer_19_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_1," << StreamingLineBuffer_19_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_2;
    StreamingLineBuffer_19_pixel_2.run<274>(StreamingLineBuffer_19_buffer_stream[0], StreamingLineBuffer_19_out0_stream_prepad[9], StreamingLineBuffer_19_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_9," << StreamingLineBuffer_19_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_2," << StreamingLineBuffer_19_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_3;
    StreamingLineBuffer_19_pixel_3.run<275>(StreamingLineBuffer_19_buffer_stream[1], StreamingLineBuffer_19_out0_stream_prepad[8], StreamingLineBuffer_19_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_8," << StreamingLineBuffer_19_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_3," << StreamingLineBuffer_19_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_4;
    StreamingLineBuffer_19_pixel_4.run<276>(StreamingLineBuffer_19_buffer_stream[2], StreamingLineBuffer_19_out0_stream_prepad[7], StreamingLineBuffer_19_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_7," << StreamingLineBuffer_19_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_4," << StreamingLineBuffer_19_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_5;
    StreamingLineBuffer_19_pixel_5.run<277>(StreamingLineBuffer_19_buffer_stream[3], StreamingLineBuffer_19_out0_stream_prepad[6], StreamingLineBuffer_19_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_6," << StreamingLineBuffer_19_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_5," << StreamingLineBuffer_19_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_6;
    StreamingLineBuffer_19_pixel_6.run<278>(StreamingLineBuffer_19_buffer_stream[4], StreamingLineBuffer_19_out0_stream_prepad[5], StreamingLineBuffer_19_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_5," << StreamingLineBuffer_19_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_6," << StreamingLineBuffer_19_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_7;
    StreamingLineBuffer_19_pixel_7.run<279>(StreamingLineBuffer_19_buffer_stream[5], StreamingLineBuffer_19_out0_stream_prepad[4], StreamingLineBuffer_19_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_4," << StreamingLineBuffer_19_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_7," << StreamingLineBuffer_19_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_8;
    StreamingLineBuffer_19_pixel_8.run<280>(StreamingLineBuffer_19_buffer_stream[6], StreamingLineBuffer_19_out0_stream_prepad[3], StreamingLineBuffer_19_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_3," << StreamingLineBuffer_19_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_8," << StreamingLineBuffer_19_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_9;
    StreamingLineBuffer_19_pixel_9.run<281>(StreamingLineBuffer_19_buffer_stream[7], StreamingLineBuffer_19_out0_stream_prepad[2], StreamingLineBuffer_19_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_2," << StreamingLineBuffer_19_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_9," << StreamingLineBuffer_19_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_10;
    StreamingLineBuffer_19_pixel_10.run<282>(StreamingLineBuffer_19_buffer_stream[8], StreamingLineBuffer_19_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_1," << StreamingLineBuffer_19_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
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
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_11;
    StreamingLineBuffer_19_pixel_11.run<283>(StreamingLineBuffer_19_buffer_stream[9], StreamingLineBuffer_19_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_0," << StreamingLineBuffer_19_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
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
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_19_pad;
    StreamingLineBuffer_19_pad.run<284>(StreamingLineBuffer_19_out0_stream_prepad, StreamingLineBuffer_19_out0_stream);
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
    ap_int<8> StreamingConv_19_weights[1024][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=2 complete
    ap_int<15> StreamingConv_19_biases[16][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 1>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        ReLU<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_uint<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_19;
    StreamingConv_19.run<285>(StreamingLineBuffer_19_out0_stream, StreamingConv_19_weights, StreamingConv_19_biases, StreamingConv_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_0," << StreamingConv_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_1," << StreamingConv_19_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 4>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_1;
    BandwidthAdjustDecreaseStreams_1.run<286>(StreamingConv_19_out0_stream, BandwidthAdjustDecreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_1_out0_stream_0," << BandwidthAdjustDecreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_0;
    StreamingLineBuffer_20_pixel_0.run<287>(BandwidthAdjustDecreaseStreams_1_out0_stream[0], StreamingLineBuffer_20_out0_stream_prepad[8], StreamingLineBuffer_20_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_8," << StreamingLineBuffer_20_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_0," << StreamingLineBuffer_20_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_1;
    StreamingLineBuffer_20_pixel_1.run<288>(StreamingLineBuffer_20_buffer_stream[0], StreamingLineBuffer_20_out0_stream_prepad[7], StreamingLineBuffer_20_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_7," << StreamingLineBuffer_20_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_1," << StreamingLineBuffer_20_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_2;
    StreamingLineBuffer_20_pixel_2.run<289>(StreamingLineBuffer_20_buffer_stream[1], StreamingLineBuffer_20_out0_stream_prepad[6], StreamingLineBuffer_20_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_6," << StreamingLineBuffer_20_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_2," << StreamingLineBuffer_20_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_3;
    StreamingLineBuffer_20_pixel_3.run<290>(StreamingLineBuffer_20_buffer_stream[2], StreamingLineBuffer_20_out0_stream_prepad[5], StreamingLineBuffer_20_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_5," << StreamingLineBuffer_20_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_3," << StreamingLineBuffer_20_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_4;
    StreamingLineBuffer_20_pixel_4.run<291>(StreamingLineBuffer_20_buffer_stream[3], StreamingLineBuffer_20_out0_stream_prepad[4], StreamingLineBuffer_20_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_4," << StreamingLineBuffer_20_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_4," << StreamingLineBuffer_20_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_5;
    StreamingLineBuffer_20_pixel_5.run<292>(StreamingLineBuffer_20_buffer_stream[4], StreamingLineBuffer_20_out0_stream_prepad[3], StreamingLineBuffer_20_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_3," << StreamingLineBuffer_20_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_5," << StreamingLineBuffer_20_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_6;
    StreamingLineBuffer_20_pixel_6.run<293>(StreamingLineBuffer_20_buffer_stream[5], StreamingLineBuffer_20_out0_stream_prepad[2], StreamingLineBuffer_20_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_2," << StreamingLineBuffer_20_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_6," << StreamingLineBuffer_20_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_7;
    StreamingLineBuffer_20_pixel_7.run<294>(StreamingLineBuffer_20_buffer_stream[6], StreamingLineBuffer_20_out0_stream_prepad[1], StreamingLineBuffer_20_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_1," << StreamingLineBuffer_20_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_buffer_stream_7," << StreamingLineBuffer_20_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_8;
    StreamingLineBuffer_20_pixel_8.run<295>(StreamingLineBuffer_20_buffer_stream[7], StreamingLineBuffer_20_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_prepad_0," << StreamingLineBuffer_20_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_uint<8>, 4>,  // TWord
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
        1,  // W_PAR
        4,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_20_pad;
    StreamingLineBuffer_20_pad.run<296>(StreamingLineBuffer_20_out0_stream_prepad, StreamingLineBuffer_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_0," << StreamingLineBuffer_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_1," << StreamingLineBuffer_20_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_2," << StreamingLineBuffer_20_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_3," << StreamingLineBuffer_20_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_4," << StreamingLineBuffer_20_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_5," << StreamingLineBuffer_20_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_6," << StreamingLineBuffer_20_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_7," << StreamingLineBuffer_20_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_8," << StreamingLineBuffer_20_out0_stream[8].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_20_weights[1024][4][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=2 complete
    ap_int<15> StreamingConv_20_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=2 complete
    StreamingConv <
        std::array<ap_uint<8>, 4>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        8,  // OUT_HEIGHT
        8,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_20;
    StreamingConv_20.run<297>(StreamingLineBuffer_20_out0_stream, StreamingConv_20_weights, StreamingConv_20_biases, StreamingConv_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_20_out0_stream_0," << StreamingConv_20_out0_stream[0].size() << std::endl;
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
        8,  // IN_HEIGHT
        8,  // IN_WIDTH
        64,  // IN_CH
        1,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_8;
    StreamingAdd_8.run<298>(StreamingConv_20_out0_stream, BandwidthAdjustDecreaseStreams_0_out0_stream, StreamingAdd_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_8_out0_stream_0," << StreamingAdd_8_out0_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_0;
    StreamingLineBuffer_21_pixel_0.run<299>(StreamingAdd_8_out0_stream[0], StreamingLineBuffer_21_out0_stream[63], StreamingLineBuffer_21_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_63," << StreamingLineBuffer_21_out0_stream[63].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_0," << StreamingLineBuffer_21_buffer_stream[0].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_1;
    StreamingLineBuffer_21_pixel_1.run<300>(StreamingLineBuffer_21_buffer_stream[0], StreamingLineBuffer_21_out0_stream[62], StreamingLineBuffer_21_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_62," << StreamingLineBuffer_21_out0_stream[62].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_1," << StreamingLineBuffer_21_buffer_stream[1].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_2;
    StreamingLineBuffer_21_pixel_2.run<301>(StreamingLineBuffer_21_buffer_stream[1], StreamingLineBuffer_21_out0_stream[61], StreamingLineBuffer_21_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_61," << StreamingLineBuffer_21_out0_stream[61].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_2," << StreamingLineBuffer_21_buffer_stream[2].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_3;
    StreamingLineBuffer_21_pixel_3.run<302>(StreamingLineBuffer_21_buffer_stream[2], StreamingLineBuffer_21_out0_stream[60], StreamingLineBuffer_21_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_60," << StreamingLineBuffer_21_out0_stream[60].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_3," << StreamingLineBuffer_21_buffer_stream[3].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_4;
    StreamingLineBuffer_21_pixel_4.run<303>(StreamingLineBuffer_21_buffer_stream[3], StreamingLineBuffer_21_out0_stream[59], StreamingLineBuffer_21_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_59," << StreamingLineBuffer_21_out0_stream[59].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_4," << StreamingLineBuffer_21_buffer_stream[4].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_5;
    StreamingLineBuffer_21_pixel_5.run<304>(StreamingLineBuffer_21_buffer_stream[4], StreamingLineBuffer_21_out0_stream[58], StreamingLineBuffer_21_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_58," << StreamingLineBuffer_21_out0_stream[58].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_5," << StreamingLineBuffer_21_buffer_stream[5].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_6;
    StreamingLineBuffer_21_pixel_6.run<305>(StreamingLineBuffer_21_buffer_stream[5], StreamingLineBuffer_21_out0_stream[57], StreamingLineBuffer_21_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_57," << StreamingLineBuffer_21_out0_stream[57].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_6," << StreamingLineBuffer_21_buffer_stream[6].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_7;
    StreamingLineBuffer_21_pixel_7.run<306>(StreamingLineBuffer_21_buffer_stream[6], StreamingLineBuffer_21_out0_stream[56], StreamingLineBuffer_21_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_56," << StreamingLineBuffer_21_out0_stream[56].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_7," << StreamingLineBuffer_21_buffer_stream[7].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_8;
    StreamingLineBuffer_21_pixel_8.run<307>(StreamingLineBuffer_21_buffer_stream[7], StreamingLineBuffer_21_out0_stream[55], StreamingLineBuffer_21_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_55," << StreamingLineBuffer_21_out0_stream[55].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_8," << StreamingLineBuffer_21_buffer_stream[8].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_9;
    StreamingLineBuffer_21_pixel_9.run<308>(StreamingLineBuffer_21_buffer_stream[8], StreamingLineBuffer_21_out0_stream[54], StreamingLineBuffer_21_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_54," << StreamingLineBuffer_21_out0_stream[54].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_9," << StreamingLineBuffer_21_buffer_stream[9].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_10;
    StreamingLineBuffer_21_pixel_10.run<309>(StreamingLineBuffer_21_buffer_stream[9], StreamingLineBuffer_21_out0_stream[53], StreamingLineBuffer_21_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_53," << StreamingLineBuffer_21_out0_stream[53].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_10," << StreamingLineBuffer_21_buffer_stream[10].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_11;
    StreamingLineBuffer_21_pixel_11.run<310>(StreamingLineBuffer_21_buffer_stream[10], StreamingLineBuffer_21_out0_stream[52], StreamingLineBuffer_21_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_52," << StreamingLineBuffer_21_out0_stream[52].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_11," << StreamingLineBuffer_21_buffer_stream[11].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_12;
    StreamingLineBuffer_21_pixel_12.run<311>(StreamingLineBuffer_21_buffer_stream[11], StreamingLineBuffer_21_out0_stream[51], StreamingLineBuffer_21_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_51," << StreamingLineBuffer_21_out0_stream[51].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_12," << StreamingLineBuffer_21_buffer_stream[12].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_13;
    StreamingLineBuffer_21_pixel_13.run<312>(StreamingLineBuffer_21_buffer_stream[12], StreamingLineBuffer_21_out0_stream[50], StreamingLineBuffer_21_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_50," << StreamingLineBuffer_21_out0_stream[50].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_13," << StreamingLineBuffer_21_buffer_stream[13].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_14;
    StreamingLineBuffer_21_pixel_14.run<313>(StreamingLineBuffer_21_buffer_stream[13], StreamingLineBuffer_21_out0_stream[49], StreamingLineBuffer_21_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_49," << StreamingLineBuffer_21_out0_stream[49].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_14," << StreamingLineBuffer_21_buffer_stream[14].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_15;
    StreamingLineBuffer_21_pixel_15.run<314>(StreamingLineBuffer_21_buffer_stream[14], StreamingLineBuffer_21_out0_stream[48], StreamingLineBuffer_21_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_48," << StreamingLineBuffer_21_out0_stream[48].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_15," << StreamingLineBuffer_21_buffer_stream[15].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_16;
    StreamingLineBuffer_21_pixel_16.run<315>(StreamingLineBuffer_21_buffer_stream[15], StreamingLineBuffer_21_out0_stream[47], StreamingLineBuffer_21_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_47," << StreamingLineBuffer_21_out0_stream[47].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_16," << StreamingLineBuffer_21_buffer_stream[16].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_17;
    StreamingLineBuffer_21_pixel_17.run<316>(StreamingLineBuffer_21_buffer_stream[16], StreamingLineBuffer_21_out0_stream[46], StreamingLineBuffer_21_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_46," << StreamingLineBuffer_21_out0_stream[46].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_17," << StreamingLineBuffer_21_buffer_stream[17].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_18;
    StreamingLineBuffer_21_pixel_18.run<317>(StreamingLineBuffer_21_buffer_stream[17], StreamingLineBuffer_21_out0_stream[45], StreamingLineBuffer_21_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_45," << StreamingLineBuffer_21_out0_stream[45].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_18," << StreamingLineBuffer_21_buffer_stream[18].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_19;
    StreamingLineBuffer_21_pixel_19.run<318>(StreamingLineBuffer_21_buffer_stream[18], StreamingLineBuffer_21_out0_stream[44], StreamingLineBuffer_21_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_44," << StreamingLineBuffer_21_out0_stream[44].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_19," << StreamingLineBuffer_21_buffer_stream[19].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_20;
    StreamingLineBuffer_21_pixel_20.run<319>(StreamingLineBuffer_21_buffer_stream[19], StreamingLineBuffer_21_out0_stream[43], StreamingLineBuffer_21_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_43," << StreamingLineBuffer_21_out0_stream[43].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_20," << StreamingLineBuffer_21_buffer_stream[20].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_21;
    StreamingLineBuffer_21_pixel_21.run<320>(StreamingLineBuffer_21_buffer_stream[20], StreamingLineBuffer_21_out0_stream[42], StreamingLineBuffer_21_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_42," << StreamingLineBuffer_21_out0_stream[42].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_21," << StreamingLineBuffer_21_buffer_stream[21].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_22;
    StreamingLineBuffer_21_pixel_22.run<321>(StreamingLineBuffer_21_buffer_stream[21], StreamingLineBuffer_21_out0_stream[41], StreamingLineBuffer_21_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_41," << StreamingLineBuffer_21_out0_stream[41].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_22," << StreamingLineBuffer_21_buffer_stream[22].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_23;
    StreamingLineBuffer_21_pixel_23.run<322>(StreamingLineBuffer_21_buffer_stream[22], StreamingLineBuffer_21_out0_stream[40], StreamingLineBuffer_21_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_40," << StreamingLineBuffer_21_out0_stream[40].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_23," << StreamingLineBuffer_21_buffer_stream[23].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_24;
    StreamingLineBuffer_21_pixel_24.run<323>(StreamingLineBuffer_21_buffer_stream[23], StreamingLineBuffer_21_out0_stream[39], StreamingLineBuffer_21_buffer_stream[24]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_39," << StreamingLineBuffer_21_out0_stream[39].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_24," << StreamingLineBuffer_21_buffer_stream[24].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_25;
    StreamingLineBuffer_21_pixel_25.run<324>(StreamingLineBuffer_21_buffer_stream[24], StreamingLineBuffer_21_out0_stream[38], StreamingLineBuffer_21_buffer_stream[25]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_38," << StreamingLineBuffer_21_out0_stream[38].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_25," << StreamingLineBuffer_21_buffer_stream[25].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_26;
    StreamingLineBuffer_21_pixel_26.run<325>(StreamingLineBuffer_21_buffer_stream[25], StreamingLineBuffer_21_out0_stream[37], StreamingLineBuffer_21_buffer_stream[26]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_37," << StreamingLineBuffer_21_out0_stream[37].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_26," << StreamingLineBuffer_21_buffer_stream[26].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_27;
    StreamingLineBuffer_21_pixel_27.run<326>(StreamingLineBuffer_21_buffer_stream[26], StreamingLineBuffer_21_out0_stream[36], StreamingLineBuffer_21_buffer_stream[27]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_36," << StreamingLineBuffer_21_out0_stream[36].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_27," << StreamingLineBuffer_21_buffer_stream[27].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_28;
    StreamingLineBuffer_21_pixel_28.run<327>(StreamingLineBuffer_21_buffer_stream[27], StreamingLineBuffer_21_out0_stream[35], StreamingLineBuffer_21_buffer_stream[28]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_35," << StreamingLineBuffer_21_out0_stream[35].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_28," << StreamingLineBuffer_21_buffer_stream[28].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_29;
    StreamingLineBuffer_21_pixel_29.run<328>(StreamingLineBuffer_21_buffer_stream[28], StreamingLineBuffer_21_out0_stream[34], StreamingLineBuffer_21_buffer_stream[29]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_34," << StreamingLineBuffer_21_out0_stream[34].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_29," << StreamingLineBuffer_21_buffer_stream[29].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_30;
    StreamingLineBuffer_21_pixel_30.run<329>(StreamingLineBuffer_21_buffer_stream[29], StreamingLineBuffer_21_out0_stream[33], StreamingLineBuffer_21_buffer_stream[30]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_33," << StreamingLineBuffer_21_out0_stream[33].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_30," << StreamingLineBuffer_21_buffer_stream[30].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_31;
    StreamingLineBuffer_21_pixel_31.run<330>(StreamingLineBuffer_21_buffer_stream[30], StreamingLineBuffer_21_out0_stream[32], StreamingLineBuffer_21_buffer_stream[31]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_32," << StreamingLineBuffer_21_out0_stream[32].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_31," << StreamingLineBuffer_21_buffer_stream[31].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_32;
    StreamingLineBuffer_21_pixel_32.run<331>(StreamingLineBuffer_21_buffer_stream[31], StreamingLineBuffer_21_out0_stream[31], StreamingLineBuffer_21_buffer_stream[32]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_31," << StreamingLineBuffer_21_out0_stream[31].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_32," << StreamingLineBuffer_21_buffer_stream[32].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_33;
    StreamingLineBuffer_21_pixel_33.run<332>(StreamingLineBuffer_21_buffer_stream[32], StreamingLineBuffer_21_out0_stream[30], StreamingLineBuffer_21_buffer_stream[33]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_30," << StreamingLineBuffer_21_out0_stream[30].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_33," << StreamingLineBuffer_21_buffer_stream[33].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_34;
    StreamingLineBuffer_21_pixel_34.run<333>(StreamingLineBuffer_21_buffer_stream[33], StreamingLineBuffer_21_out0_stream[29], StreamingLineBuffer_21_buffer_stream[34]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_29," << StreamingLineBuffer_21_out0_stream[29].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_34," << StreamingLineBuffer_21_buffer_stream[34].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_35;
    StreamingLineBuffer_21_pixel_35.run<334>(StreamingLineBuffer_21_buffer_stream[34], StreamingLineBuffer_21_out0_stream[28], StreamingLineBuffer_21_buffer_stream[35]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_28," << StreamingLineBuffer_21_out0_stream[28].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_35," << StreamingLineBuffer_21_buffer_stream[35].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_36;
    StreamingLineBuffer_21_pixel_36.run<335>(StreamingLineBuffer_21_buffer_stream[35], StreamingLineBuffer_21_out0_stream[27], StreamingLineBuffer_21_buffer_stream[36]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_27," << StreamingLineBuffer_21_out0_stream[27].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_36," << StreamingLineBuffer_21_buffer_stream[36].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_37;
    StreamingLineBuffer_21_pixel_37.run<336>(StreamingLineBuffer_21_buffer_stream[36], StreamingLineBuffer_21_out0_stream[26], StreamingLineBuffer_21_buffer_stream[37]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_26," << StreamingLineBuffer_21_out0_stream[26].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_37," << StreamingLineBuffer_21_buffer_stream[37].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_38;
    StreamingLineBuffer_21_pixel_38.run<337>(StreamingLineBuffer_21_buffer_stream[37], StreamingLineBuffer_21_out0_stream[25], StreamingLineBuffer_21_buffer_stream[38]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_25," << StreamingLineBuffer_21_out0_stream[25].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_38," << StreamingLineBuffer_21_buffer_stream[38].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_39;
    StreamingLineBuffer_21_pixel_39.run<338>(StreamingLineBuffer_21_buffer_stream[38], StreamingLineBuffer_21_out0_stream[24], StreamingLineBuffer_21_buffer_stream[39]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_24," << StreamingLineBuffer_21_out0_stream[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_39," << StreamingLineBuffer_21_buffer_stream[39].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_40;
    StreamingLineBuffer_21_pixel_40.run<339>(StreamingLineBuffer_21_buffer_stream[39], StreamingLineBuffer_21_out0_stream[23], StreamingLineBuffer_21_buffer_stream[40]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_23," << StreamingLineBuffer_21_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_40," << StreamingLineBuffer_21_buffer_stream[40].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_41;
    StreamingLineBuffer_21_pixel_41.run<340>(StreamingLineBuffer_21_buffer_stream[40], StreamingLineBuffer_21_out0_stream[22], StreamingLineBuffer_21_buffer_stream[41]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_22," << StreamingLineBuffer_21_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_41," << StreamingLineBuffer_21_buffer_stream[41].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_42;
    StreamingLineBuffer_21_pixel_42.run<341>(StreamingLineBuffer_21_buffer_stream[41], StreamingLineBuffer_21_out0_stream[21], StreamingLineBuffer_21_buffer_stream[42]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_21," << StreamingLineBuffer_21_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_42," << StreamingLineBuffer_21_buffer_stream[42].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_43;
    StreamingLineBuffer_21_pixel_43.run<342>(StreamingLineBuffer_21_buffer_stream[42], StreamingLineBuffer_21_out0_stream[20], StreamingLineBuffer_21_buffer_stream[43]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_20," << StreamingLineBuffer_21_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_43," << StreamingLineBuffer_21_buffer_stream[43].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_44;
    StreamingLineBuffer_21_pixel_44.run<343>(StreamingLineBuffer_21_buffer_stream[43], StreamingLineBuffer_21_out0_stream[19], StreamingLineBuffer_21_buffer_stream[44]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_19," << StreamingLineBuffer_21_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_44," << StreamingLineBuffer_21_buffer_stream[44].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_45;
    StreamingLineBuffer_21_pixel_45.run<344>(StreamingLineBuffer_21_buffer_stream[44], StreamingLineBuffer_21_out0_stream[18], StreamingLineBuffer_21_buffer_stream[45]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_18," << StreamingLineBuffer_21_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_45," << StreamingLineBuffer_21_buffer_stream[45].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_46;
    StreamingLineBuffer_21_pixel_46.run<345>(StreamingLineBuffer_21_buffer_stream[45], StreamingLineBuffer_21_out0_stream[17], StreamingLineBuffer_21_buffer_stream[46]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_17," << StreamingLineBuffer_21_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_46," << StreamingLineBuffer_21_buffer_stream[46].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_47;
    StreamingLineBuffer_21_pixel_47.run<346>(StreamingLineBuffer_21_buffer_stream[46], StreamingLineBuffer_21_out0_stream[16], StreamingLineBuffer_21_buffer_stream[47]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_16," << StreamingLineBuffer_21_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_47," << StreamingLineBuffer_21_buffer_stream[47].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_48;
    StreamingLineBuffer_21_pixel_48.run<347>(StreamingLineBuffer_21_buffer_stream[47], StreamingLineBuffer_21_out0_stream[15], StreamingLineBuffer_21_buffer_stream[48]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_15," << StreamingLineBuffer_21_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_48," << StreamingLineBuffer_21_buffer_stream[48].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_49;
    StreamingLineBuffer_21_pixel_49.run<348>(StreamingLineBuffer_21_buffer_stream[48], StreamingLineBuffer_21_out0_stream[14], StreamingLineBuffer_21_buffer_stream[49]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_14," << StreamingLineBuffer_21_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_49," << StreamingLineBuffer_21_buffer_stream[49].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_50;
    StreamingLineBuffer_21_pixel_50.run<349>(StreamingLineBuffer_21_buffer_stream[49], StreamingLineBuffer_21_out0_stream[13], StreamingLineBuffer_21_buffer_stream[50]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_13," << StreamingLineBuffer_21_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_50," << StreamingLineBuffer_21_buffer_stream[50].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_51;
    StreamingLineBuffer_21_pixel_51.run<350>(StreamingLineBuffer_21_buffer_stream[50], StreamingLineBuffer_21_out0_stream[12], StreamingLineBuffer_21_buffer_stream[51]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_12," << StreamingLineBuffer_21_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_51," << StreamingLineBuffer_21_buffer_stream[51].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_52;
    StreamingLineBuffer_21_pixel_52.run<351>(StreamingLineBuffer_21_buffer_stream[51], StreamingLineBuffer_21_out0_stream[11], StreamingLineBuffer_21_buffer_stream[52]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_11," << StreamingLineBuffer_21_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_52," << StreamingLineBuffer_21_buffer_stream[52].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_53;
    StreamingLineBuffer_21_pixel_53.run<352>(StreamingLineBuffer_21_buffer_stream[52], StreamingLineBuffer_21_out0_stream[10], StreamingLineBuffer_21_buffer_stream[53]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_10," << StreamingLineBuffer_21_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_53," << StreamingLineBuffer_21_buffer_stream[53].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_54;
    StreamingLineBuffer_21_pixel_54.run<353>(StreamingLineBuffer_21_buffer_stream[53], StreamingLineBuffer_21_out0_stream[9], StreamingLineBuffer_21_buffer_stream[54]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_9," << StreamingLineBuffer_21_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_54," << StreamingLineBuffer_21_buffer_stream[54].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_55;
    StreamingLineBuffer_21_pixel_55.run<354>(StreamingLineBuffer_21_buffer_stream[54], StreamingLineBuffer_21_out0_stream[8], StreamingLineBuffer_21_buffer_stream[55]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_8," << StreamingLineBuffer_21_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_55," << StreamingLineBuffer_21_buffer_stream[55].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_56;
    StreamingLineBuffer_21_pixel_56.run<355>(StreamingLineBuffer_21_buffer_stream[55], StreamingLineBuffer_21_out0_stream[7], StreamingLineBuffer_21_buffer_stream[56]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_7," << StreamingLineBuffer_21_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_56," << StreamingLineBuffer_21_buffer_stream[56].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_57;
    StreamingLineBuffer_21_pixel_57.run<356>(StreamingLineBuffer_21_buffer_stream[56], StreamingLineBuffer_21_out0_stream[6], StreamingLineBuffer_21_buffer_stream[57]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_6," << StreamingLineBuffer_21_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_57," << StreamingLineBuffer_21_buffer_stream[57].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_58;
    StreamingLineBuffer_21_pixel_58.run<357>(StreamingLineBuffer_21_buffer_stream[57], StreamingLineBuffer_21_out0_stream[5], StreamingLineBuffer_21_buffer_stream[58]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_5," << StreamingLineBuffer_21_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_58," << StreamingLineBuffer_21_buffer_stream[58].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_59;
    StreamingLineBuffer_21_pixel_59.run<358>(StreamingLineBuffer_21_buffer_stream[58], StreamingLineBuffer_21_out0_stream[4], StreamingLineBuffer_21_buffer_stream[59]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_4," << StreamingLineBuffer_21_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_59," << StreamingLineBuffer_21_buffer_stream[59].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_60;
    StreamingLineBuffer_21_pixel_60.run<359>(StreamingLineBuffer_21_buffer_stream[59], StreamingLineBuffer_21_out0_stream[3], StreamingLineBuffer_21_buffer_stream[60]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_3," << StreamingLineBuffer_21_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_60," << StreamingLineBuffer_21_buffer_stream[60].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_61;
    StreamingLineBuffer_21_pixel_61.run<360>(StreamingLineBuffer_21_buffer_stream[60], StreamingLineBuffer_21_out0_stream[2], StreamingLineBuffer_21_buffer_stream[61]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_2," << StreamingLineBuffer_21_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_61," << StreamingLineBuffer_21_buffer_stream[61].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_62;
    StreamingLineBuffer_21_pixel_62.run<361>(StreamingLineBuffer_21_buffer_stream[61], StreamingLineBuffer_21_out0_stream[1], StreamingLineBuffer_21_buffer_stream[62]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_1," << StreamingLineBuffer_21_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_buffer_stream_62," << StreamingLineBuffer_21_buffer_stream[62].size() << std::endl;
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
    > StreamingLineBuffer_21_pixel_63;
    StreamingLineBuffer_21_pixel_63.run<362>(StreamingLineBuffer_21_buffer_stream[62], StreamingLineBuffer_21_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_0," << StreamingLineBuffer_21_out0_stream[0].size() << std::endl;
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
    > StreamingMaxPool_0;
    StreamingMaxPool_0.run<363>(StreamingLineBuffer_21_out0_stream, StreamingMaxPool_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMaxPool_0_out0_stream_0," << StreamingMaxPool_0_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_21_weights[640][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=2 complete
    ap_int<2> StreamingConv_21_biases[10][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<2>, 1>,  // TBiasWord
        ap_int<2>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
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
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_21;
    StreamingConv_21.run<364>(StreamingMaxPool_0_out0_stream, StreamingConv_21_weights, StreamingConv_21_biases, StreamingConv_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_21_out0_stream_0," << StreamingConv_21_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        11,  // ITER
        16,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        10,  // CH
        1,  // IN_W_PAR
        1  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.run<365>(StreamingConv_21_out0_stream, global_out);
}
