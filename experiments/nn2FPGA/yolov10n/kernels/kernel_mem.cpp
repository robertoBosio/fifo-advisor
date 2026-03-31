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
#include "StreamingConstMul.hpp"
#include "StreamingDepthwiseConv.hpp"
#include "StreamingPad.hpp"
#include "StreamingReshape.hpp"
#include "StreamingMaxPool.hpp"
#include "StreamingSoftmax.hpp"
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
#include "YoloAttention/SplitReshape.hpp"
#include "YoloAttention/VPMatMul.hpp"
#include "YoloAttention/QKMatMul.hpp"
#include "YoloAttention/Transpose.hpp"
void yolov10n(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out_2, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out_1)
{
    #pragma HLS TOP
    #pragma HLS DATAFLOW disable_start_propagation
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis port=global_in
    #pragma HLS INTERFACE axis port=global_out_2
    #pragma HLS INTERFACE axis port=global_out
    #pragma HLS INTERFACE axis port=global_out_1
    hls::stream<std::array<ap_int<8>, 1>> NHWCToStream_0_out0_stream[1];
    #pragma HLS STREAM variable=NHWCToStream_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream[8] depth=11
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[5] depth=12
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[6] depth=12
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[7] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_0_out0_stream_prepad[8] depth=13
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_0_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[2] depth=1915
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[5] depth=1915
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_0_buffer_stream[7] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_0_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustIncreaseStreams_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_1_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[11] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[12] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[13] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream[14] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_1_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[0] depth=772
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[1] depth=801
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[2] depth=765
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[3] depth=799
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[4] depth=765
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[5] depth=775
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[6] depth=796
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[7] depth=776
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[8] depth=796
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[9] depth=777
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[10] depth=781
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[11] depth=794
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[12] depth=782
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[13] depth=795
    #pragma HLS STREAM variable=StreamingLineBuffer_1_out0_stream_prepad[14] depth=783
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_1_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[2] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[3] depth=2545
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[4] depth=2529
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[6] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[7] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[8] depth=2545
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[9] depth=2529
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[10] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[11] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_1_buffer_stream[12] depth=17
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_1_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustIncreaseChannels_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[0] depth=20
    #pragma HLS STREAM variable=StreamingLineBuffer_2_out0_stream[1] depth=20
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_2_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSplit_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_0_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_0_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_0_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_0_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_0_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_0_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[0] depth=2643
    #pragma HLS STREAM variable=TensorDuplicator_0_out1_stream[1] depth=2643
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_1_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_0_out0_stream[0] depth=5249
    #pragma HLS STREAM variable=StreamingConcat_0_out0_stream[1] depth=5249
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_3_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_3_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[0] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[1] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[3] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[5] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[6] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[7] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[8] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[9] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[10] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_3_out0_stream_prepad[11] depth=20
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_3_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[2] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[3] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[4] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[6] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[7] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[8] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_3_buffer_stream[9] depth=17
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_3_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_4_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_4_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[0] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[1] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[3] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[4] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[5] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[6] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[7] depth=18
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[8] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[9] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[10] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_4_out0_stream_prepad[11] depth=20
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_4_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[0] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[1] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[2] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[3] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[4] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[5] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[6] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[7] depth=1265
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[8] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_4_buffer_stream[9] depth=17
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_4_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_4_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_4_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConcat_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[0] depth=1313
    #pragma HLS STREAM variable=StreamingLineBuffer_5_out0_stream[1] depth=1313
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_5_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_5_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingSwish_5_out0_stream[1] depth=9
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_0_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_0_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_6_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[11] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[12] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[13] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream[14] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_6_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[0] depth=324
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[1] depth=391
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[2] depth=305
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[3] depth=372
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[4] depth=306
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[5] depth=327
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[6] depth=361
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[7] depth=328
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[8] depth=362
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[9] depth=329
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[10] depth=342
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[11] depth=343
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[12] depth=343
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[13] depth=344
    #pragma HLS STREAM variable=StreamingLineBuffer_6_out0_stream_prepad[14] depth=344
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_6_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[2] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[3] depth=2529
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[4] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[6] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[7] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[8] depth=2529
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[9] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[10] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[11] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_6_buffer_stream[12] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_6_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_6_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_6_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_7_out0_stream[1] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_7_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_7_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingSplit_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSplit_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingSplit_1_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_1_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_1_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_2_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_2_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_2_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[0] depth=6
    #pragma HLS STREAM variable=TensorDuplicator_2_out1_stream[1] depth=6
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[0] depth=6
    #pragma HLS STREAM variable=TensorDuplicator_3_out0_stream[1] depth=6
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_3_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[0] depth=2722
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_1_out0_stream[1] depth=2722
    hls::stream<std::array<ap_int<8>, 4>> StreamingConcat_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_2_out0_stream[0] depth=9
    #pragma HLS STREAM variable=StreamingConcat_2_out0_stream[1] depth=9
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_2_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[0] depth=10753
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_3_out0_stream[1] depth=10753
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_8_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_8_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_8_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_8_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_8_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_8_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_8_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_8_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_9_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_9_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_9_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_9_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_9_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_9_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_9_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_9_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_1_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_2_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_2_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_4_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_4_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_5_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_4_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[0] depth=2689
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_4_out0_stream[1] depth=2689
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_5_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_5_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_6_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[0] depth=2722
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_6_out0_stream[1] depth=2722
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_10_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_10_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_10_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_10_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_10_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_10_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_10_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_11_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_11_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_11_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_11_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_11_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_11_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_11_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_11_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_11_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_2_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_3_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingConcat_3_out0_stream[1] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_4_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConcat_4_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[0] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_12_out0_stream[1] depth=127
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_12_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> StreamingSwish_12_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_12_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_12_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_6_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_6_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_6_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[0] depth=87090
    #pragma HLS STREAM variable=TensorDuplicator_6_out1_stream[1] depth=87090
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_13_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[0] depth=20
    #pragma HLS STREAM variable=StreamingLineBuffer_13_out0_stream[1] depth=20
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_13_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_13_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_13_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_14_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream[14] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_14_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[1] depth=387
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[3] depth=267
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[5] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[6] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[7] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[8] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[9] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[10] depth=143
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[11] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[12] depth=145
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[13] depth=147
    #pragma HLS STREAM variable=StreamingLineBuffer_14_out0_stream_prepad[14] depth=147
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_14_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[3] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[4] depth=4865
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[6] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[7] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[8] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[9] depth=4865
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[10] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[11] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_14_buffer_stream[12] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingDepthwiseConv_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_0_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[0] depth=1019
    #pragma HLS STREAM variable=StreamingLineBuffer_15_out0_stream[1] depth=1019
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_14_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_14_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_14_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingSwish_14_out0_stream[1] depth=33
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_7_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_7_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_2_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSplit_2_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_2_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_2_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_2_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_7_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_7_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[0] depth=2883
    #pragma HLS STREAM variable=TensorDuplicator_7_out1_stream[1] depth=2883
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_8_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_8_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_8_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_8_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_5_out0_stream[0] depth=11265
    #pragma HLS STREAM variable=StreamingConcat_5_out0_stream[1] depth=11265
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_16_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_16_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[1] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[4] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[6] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[7] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[8] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[9] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[10] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_16_out0_stream_prepad[11] depth=68
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_16_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[2] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[3] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[6] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[7] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_16_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_15_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_15_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_15_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_15_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_17_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_17_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[1] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[4] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[6] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[7] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[8] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[9] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[10] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_17_out0_stream_prepad[11] depth=68
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_17_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[2] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[3] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[6] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[7] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_17_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_16_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_16_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_16_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_16_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_16_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_3_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_9_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_9_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_9_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_9_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_9_out1_stream[0] depth=2818
    #pragma HLS STREAM variable=TensorDuplicator_9_out1_stream[1] depth=2818
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_10_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_10_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_10_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_10_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_10_out1_stream[0] depth=2883
    #pragma HLS STREAM variable=TensorDuplicator_10_out1_stream[1] depth=2883
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_18_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_18_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[1] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[4] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[6] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[7] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[8] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[9] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[10] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_18_out0_stream_prepad[11] depth=68
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_18_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[2] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[3] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[6] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[7] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_18_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_17_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_17_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_17_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_19_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_19_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[0] depth=192
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[1] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[4] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[6] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[7] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[8] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[9] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[10] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_19_out0_stream_prepad[11] depth=68
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_19_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[2] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[3] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[6] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[7] depth=1217
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_19_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_18_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_18_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_18_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_4_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_6_out0_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingConcat_6_out0_stream[1] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_7_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConcat_7_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[0] depth=255
    #pragma HLS STREAM variable=StreamingLineBuffer_20_out0_stream[1] depth=255
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_19_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> StreamingSwish_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_19_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_19_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_11_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_11_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_11_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_11_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_11_out1_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_11_out1_stream[1] depth=35
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_0_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_0_out0_stream[0] depth=77666
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_21_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[0] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_21_out0_stream[1] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_20_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_20_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_20_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_20_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_22_out0_stream[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream[14] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_22_out0_stream_prepad[15];
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[0] depth=259
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[1] depth=771
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[2] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[3] depth=523
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[4] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[5] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[6] depth=516
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[7] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[8] depth=516
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[9] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[10] depth=271
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[11] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[12] depth=273
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[13] depth=275
    #pragma HLS STREAM variable=StreamingLineBuffer_22_out0_stream_prepad[14] depth=275
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_22_buffer_stream[13];
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[0] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[1] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[2] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[3] depth=4865
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[4] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[5] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[6] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[7] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[8] depth=4865
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[9] depth=4609
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[10] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[11] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_22_buffer_stream[12] depth=257
    hls::stream<std::array<ap_int<8>, 1>> StreamingDepthwiseConv_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingDepthwiseConv_1_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[0] depth=889
    #pragma HLS STREAM variable=StreamingLineBuffer_23_out0_stream[1] depth=889
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_21_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_21_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_21_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_21_out0_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingSwish_21_out0_stream[1] depth=65
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_8_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_8_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_3_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSplit_3_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_3_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_3_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_3_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_12_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_12_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_12_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_12_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_12_out1_stream[0] depth=3203
    #pragma HLS STREAM variable=TensorDuplicator_12_out1_stream[1] depth=3203
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_13_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_13_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_13_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_13_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_13_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_13_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_8_out0_stream[0] depth=6145
    #pragma HLS STREAM variable=StreamingConcat_8_out0_stream[1] depth=6145
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_24_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_24_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[0] depth=384
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[1] depth=256
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[2] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[3] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[4] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[6] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[7] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[8] depth=259
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[9] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[10] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_24_out0_stream_prepad[11] depth=132
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_24_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[2] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[3] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[4] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[6] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[7] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_24_buffer_stream[9] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_22_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_22_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_22_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_25_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_25_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[0] depth=384
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[1] depth=256
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[2] depth=257
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[3] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[4] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[6] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[7] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[8] depth=259
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[9] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[10] depth=260
    #pragma HLS STREAM variable=StreamingLineBuffer_25_out0_stream_prepad[11] depth=132
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_25_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[2] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[3] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[4] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[6] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[7] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_25_buffer_stream[9] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_23_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_23_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_23_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_23_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_5_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_5_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_9_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_9_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConcat_9_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[0] depth=1455
    #pragma HLS STREAM variable=StreamingLineBuffer_26_out0_stream[1] depth=1455
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_24_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_24_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_24_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_24_out0_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingSwish_24_out0_stream[1] depth=65
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_9_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_9_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_27_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[0] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_27_out0_stream[1] depth=258
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_25_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_25_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_25_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_25_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_14_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_14_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_14_out0_stream[1] depth=131
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_14_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_14_out1_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_14_out1_stream[1] depth=131
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_1_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_1_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_2_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_2_out0_stream[0] depth=5506
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_28_out0_stream[25];
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[14] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[15] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[16] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[17] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[18] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[19] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[20] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[21] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[22] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[23] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream[24] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_28_out0_stream_prepad[25];
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[5] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[6] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[7] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[8] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[9] depth=21
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[10] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[11] depth=25
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[12] depth=26
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[13] depth=28
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[14] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[15] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[16] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[17] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[18] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[19] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[20] depth=42
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[21] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[22] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[23] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_28_out0_stream_prepad[24] depth=50
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_28_buffer_stream[24];
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[3] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[4] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[6] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[7] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[9] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[10] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[11] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[12] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[13] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[14] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[15] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[16] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[17] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[18] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[19] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[20] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[21] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[22] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_28_buffer_stream[23] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingMaxPool_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMaxPool_0_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_15_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_15_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_15_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_15_out1_stream[0] depth=131
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_10_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_10_out0_stream[0] depth=21746
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_29_out0_stream[25];
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[11] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[14] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[15] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[16] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[17] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[18] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[19] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[20] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[21] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[22] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[23] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream[24] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_29_out0_stream_prepad[25];
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[5] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[6] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[7] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[8] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[9] depth=21
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[10] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[11] depth=25
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[12] depth=26
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[13] depth=28
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[14] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[15] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[16] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[17] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[18] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[19] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[20] depth=42
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[21] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[22] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[23] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_29_out0_stream_prepad[24] depth=50
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_29_buffer_stream[24];
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[3] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[4] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[6] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[7] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[9] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[10] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[11] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[12] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[13] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[14] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[15] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[16] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[17] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[18] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[19] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[20] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[21] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[22] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_29_buffer_stream[23] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingMaxPool_1_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMaxPool_1_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_16_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_16_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_16_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_16_out1_stream[0] depth=5466
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_30_out0_stream[25];
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
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[12] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[13] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[14] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[15] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[16] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[17] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[18] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[19] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[20] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[21] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[22] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[23] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream[24] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_30_out0_stream_prepad[25];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[1] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[2] depth=7
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[3] depth=9
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[5] depth=13
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[6] depth=15
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[7] depth=17
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[8] depth=19
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[9] depth=21
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[10] depth=23
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[11] depth=25
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[12] depth=26
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[13] depth=28
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[14] depth=30
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[15] depth=32
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[16] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[17] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[18] depth=38
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[19] depth=40
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[20] depth=42
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[21] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[22] depth=46
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[23] depth=48
    #pragma HLS STREAM variable=StreamingLineBuffer_30_out0_stream_prepad[24] depth=50
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_30_buffer_stream[24];
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[2] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[3] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[4] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[6] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[7] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[9] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[10] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[11] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[12] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[13] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[14] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[15] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[16] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[17] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[18] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[19] depth=2049
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[20] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[21] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[22] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_30_buffer_stream[23] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingMaxPool_2_out0_stream[1];
    #pragma HLS STREAM variable=StreamingMaxPool_2_out0_stream[0] depth=130
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_11_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_11_out0_stream[0] depth=258
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_12_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_12_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustIncreaseStreams_1_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_31_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[0] depth=580
    #pragma HLS STREAM variable=StreamingLineBuffer_31_out0_stream[1] depth=508
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_26_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> StreamingSwish_26_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_26_out0_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingSwish_26_out0_stream[1] depth=33
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_10_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_10_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_32_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[0] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_32_out0_stream[1] depth=132
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_27_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_27_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_27_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_27_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_27_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_27_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_4_out0_stream[0] depth=25857
    #pragma HLS STREAM variable=StreamingSplit_4_out0_stream[1] depth=25857
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_4_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_4_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_4_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_17_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_17_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_17_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_17_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_17_out1_stream[0] depth=25859
    #pragma HLS STREAM variable=TensorDuplicator_17_out1_stream[1] depth=25859
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_33_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_33_out0_stream[1] depth=131
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_28_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_28_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_28_out0_stream[1] depth=258
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_3_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_3_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> stream_q[2];
    #pragma HLS STREAM variable=stream_q[0] depth=12769
    #pragma HLS STREAM variable=stream_q[1] depth=12769
    hls::stream<std::array<ap_int<8>, 1>> stream_k[2];
    #pragma HLS STREAM variable=stream_k[0] depth=6337
    #pragma HLS STREAM variable=stream_k[1] depth=6337
    hls::stream<std::array<ap_int<8>, 1>> stream_v[2];
    #pragma HLS STREAM variable=stream_v[0] depth=3
    #pragma HLS STREAM variable=stream_v[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> stream_v_out[2];
    #pragma HLS STREAM variable=stream_v_out[0] depth=3
    #pragma HLS STREAM variable=stream_v_out[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> stream_v_copy[2];
    #pragma HLS STREAM variable=stream_v_copy[0] depth=3
    #pragma HLS STREAM variable=stream_v_copy[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> stream_qk[2];
    #pragma HLS STREAM variable=stream_qk[0] depth=2
    #pragma HLS STREAM variable=stream_qk[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> stream_qkscaled[2];
    #pragma HLS STREAM variable=stream_qkscaled[0] depth=26
    #pragma HLS STREAM variable=stream_qkscaled[1] depth=26
    hls::stream<std::array<ap_int<8>, 1>> stream_p[2];
    #pragma HLS STREAM variable=stream_p[0] depth=80001
    #pragma HLS STREAM variable=stream_p[1] depth=80001
    hls::stream<std::array<ap_int<8>, 1>> stream_v_transposed[2];
    #pragma HLS STREAM variable=stream_v_transposed[0] depth=382
    #pragma HLS STREAM variable=stream_v_transposed[1] depth=382
    hls::stream<std::array<ap_int<8>, 1>> stream_y[2];
    #pragma HLS STREAM variable=stream_y[0] depth=2
    #pragma HLS STREAM variable=stream_y[1] depth=64
    hls::stream<std::array<ap_int<8>, 1>> StreamingYoloAttention_0_out1_stream[1];
    #pragma HLS STREAM variable=StreamingYoloAttention_0_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingYoloAttention_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingYoloAttention_0_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustIncreaseStreams_2_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[0] depth=131
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_2_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustIncreaseStreams_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseStreams_3_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_34_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream[11] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_34_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[0] depth=259
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[1] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[2] depth=132
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[4] depth=133
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[6] depth=133
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[8] depth=134
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[10] depth=135
    #pragma HLS STREAM variable=StreamingLineBuffer_34_out0_stream_prepad[11] depth=12
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_34_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[0] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[1] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[2] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[3] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[4] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[5] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[6] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[7] depth=1153
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[8] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_34_buffer_stream[9] depth=129
    hls::stream<std::array<ap_int<8>, 1>> StreamingDepthwiseConv_2_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[0] depth=24280
    #pragma HLS STREAM variable=StreamingDepthwiseConv_2_out0_stream[1] depth=24280
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_6_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_35_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[0] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_35_out0_stream[1] depth=68
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_29_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_29_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_29_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_7_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingAdd_7_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_18_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_18_out0_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_18_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_18_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_18_out1_stream[0] depth=259
    #pragma HLS STREAM variable=TensorDuplicator_18_out1_stream[1] depth=259
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_36_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_36_out0_stream[1] depth=131
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_30_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_30_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_30_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_28_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_28_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_28_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_37_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[0] depth=258
    #pragma HLS STREAM variable=StreamingLineBuffer_37_out0_stream[1] depth=258
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_31_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_31_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingConv_31_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingAdd_8_out0_stream[2];
    #pragma HLS STREAM variable=StreamingAdd_8_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingAdd_8_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_13_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_13_out0_stream[0] depth=130
    #pragma HLS STREAM variable=StreamingConcat_13_out0_stream[1] depth=259
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_4_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_4_out0_stream[0] depth=508
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_32_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_32_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingSwish_29_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_29_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_19_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_19_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_19_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_19_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 4>> StreamingUpsample_0_out0_stream[2];
    #pragma HLS STREAM variable=StreamingUpsample_0_out0_stream[0] depth=643
    #pragma HLS STREAM variable=StreamingUpsample_0_out0_stream[1] depth=706
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_5_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_5_out0_stream[0] depth=898
    hls::stream<std::array<ap_int<8>, 4>> StreamingConcat_14_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_14_out0_stream[0] depth=3974
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_33_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_33_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_30_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_30_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSplit_5_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSplit_5_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSplit_5_out1_stream[1];
    #pragma HLS STREAM variable=StreamingSplit_5_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_20_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_20_out0_stream[0] depth=18
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_20_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_20_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> StreamingConcat_15_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_15_out0_stream[0] depth=5377
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_11_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_11_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_38_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream[8] depth=11
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_38_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[0] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[2] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[3] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[4] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[5] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[6] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[7] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_38_out0_stream_prepad[8] depth=71
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_38_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[2] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[5] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_38_buffer_stream[7] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_34_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_34_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_31_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_31_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_39_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream[8] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_39_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[0] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[3] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[5] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[6] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[7] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_39_out0_stream_prepad[8] depth=70
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_39_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[2] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[5] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_39_buffer_stream[7] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_35_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_35_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_32_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_32_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConcat_16_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_16_out0_stream[0] depth=102
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_36_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_36_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_33_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_33_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_21_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_21_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_21_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_21_out1_stream[0] depth=5378
    hls::stream<std::array<ap_int<8>, 2>> StreamingUpsample_1_out0_stream[2];
    #pragma HLS STREAM variable=StreamingUpsample_1_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingUpsample_1_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_3_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[0] depth=9
    #pragma HLS STREAM variable=BandwidthAdjustIncreaseChannels_3_out0_stream[1] depth=9
    hls::stream<std::array<ap_int<8>, 4>> StreamingConcat_17_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_17_out0_stream[0] depth=1309
    #pragma HLS STREAM variable=StreamingConcat_17_out0_stream[1] depth=1309
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_12_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_12_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_40_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[0] depth=7563
    #pragma HLS STREAM variable=StreamingLineBuffer_40_out0_stream[1] depth=7563
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_37_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_37_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_37_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 4>> StreamingSwish_34_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_34_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_34_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 4>> StreamingSplit_6_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_6_out0_stream[0] depth=7
    #pragma HLS STREAM variable=StreamingSplit_6_out0_stream[1] depth=7
    hls::stream<std::array<ap_int<8>, 4>> StreamingSplit_6_out1_stream[2];
    #pragma HLS STREAM variable=StreamingSplit_6_out1_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSplit_6_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_22_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_22_out0_stream[0] depth=8
    #pragma HLS STREAM variable=TensorDuplicator_22_out0_stream[1] depth=8
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_22_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_22_out1_stream[0] depth=8
    #pragma HLS STREAM variable=TensorDuplicator_22_out1_stream[1] depth=8
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_13_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_13_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_14_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[0] depth=2
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_14_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_15_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_15_out0_stream[0] depth=25
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_15_out0_stream[1] depth=25
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_18_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_18_out0_stream[0] depth=5377
    #pragma HLS STREAM variable=StreamingConcat_18_out0_stream[1] depth=5377
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_41_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_41_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_41_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_41_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_41_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_38_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_38_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_38_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_35_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_35_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_35_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_42_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_42_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_42_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_42_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_42_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_39_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_39_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_39_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_36_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_36_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_36_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_19_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_19_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConcat_19_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_43_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_43_out0_stream[0] depth=98
    #pragma HLS STREAM variable=StreamingLineBuffer_43_out0_stream[1] depth=98
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_40_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_40_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_40_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_37_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_37_out0_stream[0] depth=3
    #pragma HLS STREAM variable=StreamingSwish_37_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_23_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_23_out0_stream[0] depth=4
    #pragma HLS STREAM variable=TensorDuplicator_23_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_23_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_23_out1_stream[0] depth=18
    #pragma HLS STREAM variable=TensorDuplicator_23_out1_stream[1] depth=18
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_24_out0_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_24_out0_stream[0] depth=18
    #pragma HLS STREAM variable=TensorDuplicator_24_out0_stream[1] depth=18
    hls::stream<std::array<ap_int<8>, 2>> TensorDuplicator_24_out1_stream[2];
    #pragma HLS STREAM variable=TensorDuplicator_24_out1_stream[0] depth=3
    #pragma HLS STREAM variable=TensorDuplicator_24_out1_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_16_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_16_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_16_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_17_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_17_out0_stream[0] depth=4
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_17_out0_stream[1] depth=67
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_44_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream[11] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_44_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[0] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[1] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[2] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[4] depth=71
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[6] depth=72
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[8] depth=74
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[10] depth=76
    #pragma HLS STREAM variable=StreamingLineBuffer_44_out0_stream_prepad[11] depth=12
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_44_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_44_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_45_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[8] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[9] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[10] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream[11] depth=11
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_45_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[0] depth=96
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[1] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[2] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[3] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[4] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[6] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[7] depth=34
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[8] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[9] depth=35
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[10] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_45_out0_stream_prepad[11] depth=36
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_45_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[0] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[1] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[2] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[3] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[4] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[5] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[6] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[7] depth=1249
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[8] depth=33
    #pragma HLS STREAM variable=StreamingLineBuffer_45_buffer_stream[9] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingDepthwiseConv_3_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingDepthwiseConv_3_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_41_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_41_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_41_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_6_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_6_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_38_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_38_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_38_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_39_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_39_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_39_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_46_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream[8] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_46_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[0] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[1] depth=62
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[2] depth=63
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[3] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[5] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[6] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[7] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_46_out0_stream_prepad[8] depth=69
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_46_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[2] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[5] depth=4993
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_46_buffer_stream[7] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_42_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_42_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_47_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_47_out0_stream[0] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_47_out0_stream[1] depth=66
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_48_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[0] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[1] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[2] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[3] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[4] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[5] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[6] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[7] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[8] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[10] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream[11] depth=10
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_48_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[0] depth=191
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[1] depth=127
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[2] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[3] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[4] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[5] depth=64
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[6] depth=129
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[7] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[8] depth=130
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[9] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[10] depth=131
    #pragma HLS STREAM variable=StreamingLineBuffer_48_out0_stream_prepad[11] depth=67
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_48_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[2] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[3] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[5] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[6] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[7] depth=2497
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[8] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_48_buffer_stream[9] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_43_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_43_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_43_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_44_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_44_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_44_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_40_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_40_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_41_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_41_out0_stream[0] depth=21
    #pragma HLS STREAM variable=StreamingSwish_41_out0_stream[1] depth=21
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_42_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_42_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_42_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingConcat_20_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_20_out0_stream[0] depth=1969
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_18_out0_stream[2];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_18_out0_stream[0] depth=3
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_18_out0_stream[1] depth=3
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_45_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_45_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_49_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_49_out0_stream[0] depth=36
    #pragma HLS STREAM variable=StreamingLineBuffer_49_out0_stream[1] depth=36
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_46_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_46_out0_stream[0] depth=385
    #pragma HLS STREAM variable=StreamingConv_46_out0_stream[1] depth=385
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_43_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_43_out0_stream[0] depth=33
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_50_out0_stream[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[1] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[2] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[3] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[4] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[5] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[6] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[7] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[8] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[9] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[10] depth=4
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream[11] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_50_out0_stream_prepad[12];
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[0] depth=163
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[1] depth=83
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[2] depth=85
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[3] depth=5
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[4] depth=87
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[5] depth=6
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[6] depth=88
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[7] depth=8
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[8] depth=90
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[9] depth=10
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[10] depth=92
    #pragma HLS STREAM variable=StreamingLineBuffer_50_out0_stream_prepad[11] depth=12
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_50_buffer_stream[10];
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[0] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[1] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[2] depth=3121
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[3] depth=3121
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[4] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[5] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[6] depth=3121
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[7] depth=3121
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[8] depth=81
    #pragma HLS STREAM variable=StreamingLineBuffer_50_buffer_stream[9] depth=81
    hls::stream<std::array<ap_int<8>, 1>> StreamingDepthwiseConv_4_out0_stream[2];
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingDepthwiseConv_4_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_19_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseChannels_19_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_44_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_44_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_44_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_7_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSplit_7_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSplit_7_out1_stream[1];
    #pragma HLS STREAM variable=StreamingSplit_7_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_25_out0_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_25_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_25_out1_stream[1];
    #pragma HLS STREAM variable=TensorDuplicator_25_out1_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_51_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_51_out0_stream[0] depth=574
    #pragma HLS STREAM variable=StreamingLineBuffer_51_out0_stream[1] depth=574
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_47_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_47_out0_stream[0] depth=4
    #pragma HLS STREAM variable=StreamingConv_47_out0_stream[1] depth=4
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_21_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_21_out0_stream[0] depth=10753
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_52_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream[8] depth=11
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_52_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[0] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[2] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[3] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[4] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[5] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[6] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[7] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_52_out0_stream_prepad[8] depth=71
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_52_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[2] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[5] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_52_buffer_stream[7] depth=65
    hls::stream<std::array<ap_int<8>, 2>> StreamingSwish_45_out0_stream[2];
    #pragma HLS STREAM variable=StreamingSwish_45_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingSwish_45_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_48_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_48_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_46_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_46_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 2>> StreamingLineBuffer_53_out0_stream[2];
    #pragma HLS STREAM variable=StreamingLineBuffer_53_out0_stream[0] depth=44
    #pragma HLS STREAM variable=StreamingLineBuffer_53_out0_stream[1] depth=44
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_49_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConv_49_out0_stream[0] depth=2
    #pragma HLS STREAM variable=StreamingConv_49_out0_stream[1] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_54_out0_stream[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[0] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[1] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[2] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[3] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[4] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[5] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[6] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[7] depth=11
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream[8] depth=11
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_54_out0_stream_prepad[9];
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[0] depth=128
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[2] depth=66
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[3] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[4] depth=67
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[5] depth=68
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[6] depth=69
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[7] depth=70
    #pragma HLS STREAM variable=StreamingLineBuffer_54_out0_stream_prepad[8] depth=71
    hls::stream<std::array<ap_int<8>, 1>> StreamingLineBuffer_54_buffer_stream[8];
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[0] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[1] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[2] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[3] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[4] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[5] depth=2433
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[6] depth=65
    #pragma HLS STREAM variable=StreamingLineBuffer_54_buffer_stream[7] depth=65
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_22_out0_stream[2];
    #pragma HLS STREAM variable=StreamingConcat_22_out0_stream[0] depth=66
    #pragma HLS STREAM variable=StreamingConcat_22_out0_stream[1] depth=147
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_50_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConv_50_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseStreams_7_out0_stream[1];
    #pragma HLS STREAM variable=BandwidthAdjustDecreaseStreams_7_out0_stream[0] depth=3
    hls::stream<std::array<ap_int<8>, 1>> StreamingSwish_47_out0_stream[1];
    #pragma HLS STREAM variable=StreamingSwish_47_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingReshape_0_out0_stream[1];
    #pragma HLS STREAM variable=StreamingReshape_0_out0_stream[0] depth=2
    hls::stream<std::array<ap_int<8>, 1>> StreamingConcat_23_out0_stream[1];
    #pragma HLS STREAM variable=StreamingConcat_23_out0_stream[0] depth=2
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        16,  // DATA_PER_WORD
        640,  // HEIGHT
        640,  // WIDTH
        3,  // CH
        1,  // OUT_W_PAR
        1  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.run<0>(global_in, NHWCToStream_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "NHWCToStream_0_out0_stream_0," << NHWCToStream_0_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_0;
    StreamingLineBuffer_0_pixel_0.run<1>(NHWCToStream_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_8," << StreamingLineBuffer_0_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_0," << StreamingLineBuffer_0_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_1;
    StreamingLineBuffer_0_pixel_1.run<2>(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_7," << StreamingLineBuffer_0_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_1," << StreamingLineBuffer_0_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_2;
    StreamingLineBuffer_0_pixel_2.run<3>(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_6," << StreamingLineBuffer_0_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_2," << StreamingLineBuffer_0_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_3;
    StreamingLineBuffer_0_pixel_3.run<4>(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_5," << StreamingLineBuffer_0_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_3," << StreamingLineBuffer_0_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_4;
    StreamingLineBuffer_0_pixel_4.run<5>(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_4," << StreamingLineBuffer_0_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_4," << StreamingLineBuffer_0_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_5;
    StreamingLineBuffer_0_pixel_5.run<6>(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[3], StreamingLineBuffer_0_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_3," << StreamingLineBuffer_0_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_5," << StreamingLineBuffer_0_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_6;
    StreamingLineBuffer_0_pixel_6.run<7>(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[2], StreamingLineBuffer_0_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_2," << StreamingLineBuffer_0_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_6," << StreamingLineBuffer_0_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_7;
    StreamingLineBuffer_0_pixel_7.run<8>(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[1], StreamingLineBuffer_0_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_1," << StreamingLineBuffer_0_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_buffer_stream_7," << StreamingLineBuffer_0_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_0_pixel_8;
    StreamingLineBuffer_0_pixel_8.run<9>(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_0_out0_stream_prepad_0," << StreamingLineBuffer_0_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        640,  // IN_HEIGHT
        640,  // IN_WIDTH
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
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_0_pad;
    StreamingLineBuffer_0_pad.run<10>(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
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
    ap_int<8> StreamingConv_0_weights[48][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_weights dim=2 complete
    ap_int<15> StreamingConv_0_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_0_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        DequantQuantEqual<ap_int<22>>,  // Activation
        DequantQuantPo2<8, ap_int<22>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        3,  // IN_CH
        320,  // OUT_HEIGHT
        320,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_0;
    StreamingConv_0.run<11>(StreamingLineBuffer_0_out0_stream, StreamingConv_0_weights, StreamingConv_0_biases, StreamingConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_0_out0_stream_0," << StreamingConv_0_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_0_lut[256] = {0, 1, 1, 2, 3, 4, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -1, -1, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_0;
    StreamingSwish_0.run<12>(StreamingConv_0_out0_stream, StreamingSwish_0_lut, StreamingSwish_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_0_out0_stream_0," << StreamingSwish_0_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
        16,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_0;
    BandwidthAdjustIncreaseStreams_0.run<13>(StreamingSwish_0_out0_stream, BandwidthAdjustIncreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_0," << BandwidthAdjustIncreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_0_out0_stream_1," << BandwidthAdjustIncreaseStreams_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_0;
    StreamingLineBuffer_1_pixel_0.run<14>(BandwidthAdjustIncreaseStreams_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[14], StreamingLineBuffer_1_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_14," << StreamingLineBuffer_1_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_0," << StreamingLineBuffer_1_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_1;
    StreamingLineBuffer_1_pixel_1.run<15>(BandwidthAdjustIncreaseStreams_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[13], StreamingLineBuffer_1_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_13," << StreamingLineBuffer_1_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_1," << StreamingLineBuffer_1_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_2;
    StreamingLineBuffer_1_pixel_2.run<16>(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[12], StreamingLineBuffer_1_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_12," << StreamingLineBuffer_1_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_2," << StreamingLineBuffer_1_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_3;
    StreamingLineBuffer_1_pixel_3.run<17>(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_11," << StreamingLineBuffer_1_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_4," << StreamingLineBuffer_1_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_4;
    StreamingLineBuffer_1_pixel_4.run<18>(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_10," << StreamingLineBuffer_1_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_3," << StreamingLineBuffer_1_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_6;
    StreamingLineBuffer_1_pixel_6.run<20>(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_8," << StreamingLineBuffer_1_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_6," << StreamingLineBuffer_1_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_5;
    StreamingLineBuffer_1_pixel_5.run<19>(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_9," << StreamingLineBuffer_1_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_5," << StreamingLineBuffer_1_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_8;
    StreamingLineBuffer_1_pixel_8.run<22>(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_6," << StreamingLineBuffer_1_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_9," << StreamingLineBuffer_1_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_7;
    StreamingLineBuffer_1_pixel_7.run<21>(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_7," << StreamingLineBuffer_1_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_7," << StreamingLineBuffer_1_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_11;
    StreamingLineBuffer_1_pixel_11.run<25>(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[3], StreamingLineBuffer_1_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_3," << StreamingLineBuffer_1_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_11," << StreamingLineBuffer_1_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_9;
    StreamingLineBuffer_1_pixel_9.run<23>(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_5," << StreamingLineBuffer_1_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_8," << StreamingLineBuffer_1_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_13;
    StreamingLineBuffer_1_pixel_13.run<27>(StreamingLineBuffer_1_buffer_stream[11], StreamingLineBuffer_1_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_1," << StreamingLineBuffer_1_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_10;
    StreamingLineBuffer_1_pixel_10.run<24>(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_4," << StreamingLineBuffer_1_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_10," << StreamingLineBuffer_1_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_12;
    StreamingLineBuffer_1_pixel_12.run<26>(StreamingLineBuffer_1_buffer_stream[10], StreamingLineBuffer_1_out0_stream_prepad[2], StreamingLineBuffer_1_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_2," << StreamingLineBuffer_1_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_buffer_stream_12," << StreamingLineBuffer_1_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    > StreamingLineBuffer_1_pixel_14;
    StreamingLineBuffer_1_pixel_14.run<28>(StreamingLineBuffer_1_buffer_stream[12], StreamingLineBuffer_1_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_prepad_0," << StreamingLineBuffer_1_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        320,  // IN_HEIGHT
        320,  // IN_WIDTH
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_12," << StreamingLineBuffer_1_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_13," << StreamingLineBuffer_1_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_1_out0_stream_14," << StreamingLineBuffer_1_out0_stream[14].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_1_weights[512][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_weights dim=2 complete
    ap_int<13> StreamingConv_1_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_1_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        16,  // IN_CH
        160,  // OUT_HEIGHT
        160,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_1;
    StreamingConv_1.run<30>(StreamingLineBuffer_1_out0_stream, StreamingConv_1_weights, StreamingConv_1_biases, StreamingConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_0," << StreamingConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_1_out0_stream_1," << StreamingConv_1_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_1_lut[256] = {0, 1, 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_1;
    StreamingSwish_1.run<31>(StreamingConv_1_out0_stream, StreamingSwish_1_lut, StreamingSwish_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_1_out0_stream_0," << StreamingSwish_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_1_out0_stream_1," << StreamingSwish_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_0;
    BandwidthAdjustIncreaseChannels_0.run<32>(StreamingSwish_1_out0_stream, BandwidthAdjustIncreaseChannels_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_0," << BandwidthAdjustIncreaseChannels_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_0_out0_stream_1," << BandwidthAdjustIncreaseChannels_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
        2  // CH_PAR
    > StreamingLineBuffer_2_pixel_0;
    StreamingLineBuffer_2_pixel_0.run<33>(BandwidthAdjustIncreaseChannels_0_out0_stream[1], StreamingLineBuffer_2_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_1," << StreamingLineBuffer_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
        2  // CH_PAR
    > StreamingLineBuffer_2_pixel_1;
    StreamingLineBuffer_2_pixel_1.run<34>(BandwidthAdjustIncreaseChannels_0_out0_stream[0], StreamingLineBuffer_2_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_2_out0_stream_0," << StreamingLineBuffer_2_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_2_weights[512][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_weights dim=2 complete
    ap_int<11> StreamingConv_2_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_2_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<11>, 1>,  // TBiasWord
        ap_int<11>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        DequantQuantEqual<ap_int<23>>,  // Activation
        DequantQuantPo2<6, ap_int<23>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        160,  // OUT_HEIGHT
        160,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_2;
    StreamingConv_2.run<35>(StreamingLineBuffer_2_out0_stream, StreamingConv_2_weights, StreamingConv_2_biases, StreamingConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_0," << StreamingConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_2_out0_stream_1," << StreamingConv_2_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_2_lut[256] = {0, 1, 2, 4, 5, 7, 9, 11, 13, 16, 18, 21, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -2, -3, -3, -3, -3, -3, -2, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_2;
    StreamingSwish_2.run<36>(StreamingConv_2_out0_stream, StreamingSwish_2_lut, StreamingSwish_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_2_out0_stream_0," << StreamingSwish_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_2_out0_stream_1," << StreamingSwish_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        16,  // SPLIT
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_0;
    StreamingSplit_0.run<37>(StreamingSwish_2_out0_stream, StreamingSplit_0_out0_stream, StreamingSplit_0_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_0_out0_stream_0," << StreamingSplit_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_0_out0_stream_1," << StreamingSplit_0_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_0_out1_stream_0," << StreamingSplit_0_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_0_out1_stream_1," << StreamingSplit_0_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.run<38>(StreamingSplit_0_out1_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
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
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.run<39>(TensorDuplicator_0_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
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
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH_A
        16,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_0;
    StreamingConcat_0.run<40>(StreamingSplit_0_out0_stream, TensorDuplicator_1_out1_stream, StreamingConcat_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_0_out0_stream_0," << StreamingConcat_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_0_out0_stream_1," << StreamingConcat_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_0.run<41>(TensorDuplicator_1_out0_stream[0], StreamingLineBuffer_3_out0_stream_prepad[11], StreamingLineBuffer_3_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_11," << StreamingLineBuffer_3_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_0," << StreamingLineBuffer_3_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_1.run<42>(TensorDuplicator_1_out0_stream[1], StreamingLineBuffer_3_out0_stream_prepad[10], StreamingLineBuffer_3_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_10," << StreamingLineBuffer_3_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_1," << StreamingLineBuffer_3_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_2.run<43>(StreamingLineBuffer_3_buffer_stream[0], StreamingLineBuffer_3_out0_stream_prepad[9], StreamingLineBuffer_3_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_9," << StreamingLineBuffer_3_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_2," << StreamingLineBuffer_3_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_3.run<44>(StreamingLineBuffer_3_buffer_stream[1], StreamingLineBuffer_3_out0_stream_prepad[8], StreamingLineBuffer_3_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_8," << StreamingLineBuffer_3_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_3," << StreamingLineBuffer_3_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_4.run<45>(StreamingLineBuffer_3_buffer_stream[2], StreamingLineBuffer_3_out0_stream_prepad[7], StreamingLineBuffer_3_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_7," << StreamingLineBuffer_3_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_4," << StreamingLineBuffer_3_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_5.run<46>(StreamingLineBuffer_3_buffer_stream[3], StreamingLineBuffer_3_out0_stream_prepad[6], StreamingLineBuffer_3_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_6," << StreamingLineBuffer_3_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_5," << StreamingLineBuffer_3_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_6.run<47>(StreamingLineBuffer_3_buffer_stream[4], StreamingLineBuffer_3_out0_stream_prepad[5], StreamingLineBuffer_3_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_5," << StreamingLineBuffer_3_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_6," << StreamingLineBuffer_3_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_7.run<48>(StreamingLineBuffer_3_buffer_stream[5], StreamingLineBuffer_3_out0_stream_prepad[4], StreamingLineBuffer_3_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_4," << StreamingLineBuffer_3_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_7," << StreamingLineBuffer_3_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_8.run<49>(StreamingLineBuffer_3_buffer_stream[6], StreamingLineBuffer_3_out0_stream_prepad[3], StreamingLineBuffer_3_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_3," << StreamingLineBuffer_3_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_8," << StreamingLineBuffer_3_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_9.run<50>(StreamingLineBuffer_3_buffer_stream[7], StreamingLineBuffer_3_out0_stream_prepad[2], StreamingLineBuffer_3_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_2," << StreamingLineBuffer_3_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_buffer_stream_9," << StreamingLineBuffer_3_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_10.run<51>(StreamingLineBuffer_3_buffer_stream[8], StreamingLineBuffer_3_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_1," << StreamingLineBuffer_3_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pixel_11.run<52>(StreamingLineBuffer_3_buffer_stream[9], StreamingLineBuffer_3_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_3_out0_stream_prepad_0," << StreamingLineBuffer_3_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    StreamingLineBuffer_3_pad.run<53>(StreamingLineBuffer_3_out0_stream_prepad, StreamingLineBuffer_3_out0_stream);
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
    ap_int<8> StreamingConv_3_weights[256][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_weights dim=2 complete
    ap_int<12> StreamingConv_3_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_3_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 1>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<5, ap_int<25>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        16,  // IN_CH
        160,  // OUT_HEIGHT
        160,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_3;
    StreamingConv_3.run<54>(StreamingLineBuffer_3_out0_stream, StreamingConv_3_weights, StreamingConv_3_biases, StreamingConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_0," << StreamingConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_3_out0_stream_1," << StreamingConv_3_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_3_lut[256] = {0, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_3;
    StreamingSwish_3.run<55>(StreamingConv_3_out0_stream, StreamingSwish_3_lut, StreamingSwish_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_3_out0_stream_0," << StreamingSwish_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_3_out0_stream_1," << StreamingSwish_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_0;
    StreamingLineBuffer_4_pixel_0.run<56>(StreamingSwish_3_out0_stream[0], StreamingLineBuffer_4_out0_stream_prepad[11], StreamingLineBuffer_4_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_11," << StreamingLineBuffer_4_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_0," << StreamingLineBuffer_4_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_1;
    StreamingLineBuffer_4_pixel_1.run<57>(StreamingSwish_3_out0_stream[1], StreamingLineBuffer_4_out0_stream_prepad[10], StreamingLineBuffer_4_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_10," << StreamingLineBuffer_4_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_1," << StreamingLineBuffer_4_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_2;
    StreamingLineBuffer_4_pixel_2.run<58>(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream_prepad[9], StreamingLineBuffer_4_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_9," << StreamingLineBuffer_4_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_2," << StreamingLineBuffer_4_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_3;
    StreamingLineBuffer_4_pixel_3.run<59>(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream_prepad[8], StreamingLineBuffer_4_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_8," << StreamingLineBuffer_4_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_3," << StreamingLineBuffer_4_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_4;
    StreamingLineBuffer_4_pixel_4.run<60>(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream_prepad[7], StreamingLineBuffer_4_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_7," << StreamingLineBuffer_4_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_4," << StreamingLineBuffer_4_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_5;
    StreamingLineBuffer_4_pixel_5.run<61>(StreamingLineBuffer_4_buffer_stream[3], StreamingLineBuffer_4_out0_stream_prepad[6], StreamingLineBuffer_4_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_6," << StreamingLineBuffer_4_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_5," << StreamingLineBuffer_4_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_6;
    StreamingLineBuffer_4_pixel_6.run<62>(StreamingLineBuffer_4_buffer_stream[4], StreamingLineBuffer_4_out0_stream_prepad[5], StreamingLineBuffer_4_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_5," << StreamingLineBuffer_4_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_6," << StreamingLineBuffer_4_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_7;
    StreamingLineBuffer_4_pixel_7.run<63>(StreamingLineBuffer_4_buffer_stream[5], StreamingLineBuffer_4_out0_stream_prepad[4], StreamingLineBuffer_4_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_4," << StreamingLineBuffer_4_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_7," << StreamingLineBuffer_4_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_8;
    StreamingLineBuffer_4_pixel_8.run<64>(StreamingLineBuffer_4_buffer_stream[6], StreamingLineBuffer_4_out0_stream_prepad[3], StreamingLineBuffer_4_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_3," << StreamingLineBuffer_4_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_8," << StreamingLineBuffer_4_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_9;
    StreamingLineBuffer_4_pixel_9.run<65>(StreamingLineBuffer_4_buffer_stream[7], StreamingLineBuffer_4_out0_stream_prepad[2], StreamingLineBuffer_4_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_2," << StreamingLineBuffer_4_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_buffer_stream_9," << StreamingLineBuffer_4_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_10;
    StreamingLineBuffer_4_pixel_10.run<66>(StreamingLineBuffer_4_buffer_stream[8], StreamingLineBuffer_4_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_1," << StreamingLineBuffer_4_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pixel_11;
    StreamingLineBuffer_4_pixel_11.run<67>(StreamingLineBuffer_4_buffer_stream[9], StreamingLineBuffer_4_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_4_out0_stream_prepad_0," << StreamingLineBuffer_4_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_4_pad;
    StreamingLineBuffer_4_pad.run<68>(StreamingLineBuffer_4_out0_stream_prepad, StreamingLineBuffer_4_out0_stream);
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
    ap_int<8> StreamingConv_4_weights[256][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_weights dim=2 complete
    ap_int<13> StreamingConv_4_biases[16][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_4_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        16,  // IN_CH
        160,  // OUT_HEIGHT
        160,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_4;
    StreamingConv_4.run<69>(StreamingLineBuffer_4_out0_stream, StreamingConv_4_weights, StreamingConv_4_biases, StreamingConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_0," << StreamingConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_4_out0_stream_1," << StreamingConv_4_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_4_lut[256] = {0, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_4;
    StreamingSwish_4.run<70>(StreamingConv_4_out0_stream, StreamingSwish_4_lut, StreamingSwish_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_4_out0_stream_0," << StreamingSwish_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_4_out0_stream_1," << StreamingSwish_4_out0_stream[1].size() << std::endl;
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
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        16,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_0;
    StreamingAdd_0.run<71>(TensorDuplicator_0_out1_stream, StreamingSwish_4_out0_stream, StreamingAdd_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_0," << StreamingAdd_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_0_out0_stream_1," << StreamingAdd_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH_A
        16,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_1;
    StreamingConcat_1.run<72>(StreamingConcat_0_out0_stream, StreamingAdd_0_out0_stream, StreamingConcat_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_1_out0_stream_0," << StreamingConcat_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_1_out0_stream_1," << StreamingConcat_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        48,  // IN_CH
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
    > StreamingLineBuffer_5_pixel_0;
    StreamingLineBuffer_5_pixel_0.run<73>(StreamingConcat_1_out0_stream[1], StreamingLineBuffer_5_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_1," << StreamingLineBuffer_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        48,  // IN_CH
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
    > StreamingLineBuffer_5_pixel_1;
    StreamingLineBuffer_5_pixel_1.run<74>(StreamingConcat_1_out0_stream[0], StreamingLineBuffer_5_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_5_out0_stream_0," << StreamingLineBuffer_5_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_5_weights[768][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_weights dim=2 complete
    ap_int<14> StreamingConv_5_biases[16][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_5_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        DequantQuantEqual<ap_int<23>>,  // Activation
        DequantQuantPo2<6, ap_int<23>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        48,  // IN_CH
        160,  // OUT_HEIGHT
        160,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_5;
    StreamingConv_5.run<75>(StreamingLineBuffer_5_out0_stream, StreamingConv_5_weights, StreamingConv_5_biases, StreamingConv_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_0," << StreamingConv_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_5_out0_stream_1," << StreamingConv_5_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_5_lut[256] = {0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 14, 16, 18, 20, 22, 24, 27, 29, 32, 34, 37, 39, 42, 45, 48, 50, 52, 54, 56, 58, 60, 62, 64, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -4, -4, -5, -5, -6, -6, -6, -6, -6, -6, -6, -5, -5, -4, -4, -3, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_5;
    StreamingSwish_5.run<76>(StreamingConv_5_out0_stream, StreamingSwish_5_lut, StreamingSwish_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_5_out0_stream_0," << StreamingSwish_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_5_out0_stream_1," << StreamingSwish_5_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_0;
    BandwidthAdjustDecreaseChannels_0.run<77>(StreamingSwish_5_out0_stream, BandwidthAdjustDecreaseChannels_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_0," << BandwidthAdjustDecreaseChannels_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_0_out0_stream_1," << BandwidthAdjustDecreaseChannels_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_0;
    StreamingLineBuffer_6_pixel_0.run<78>(BandwidthAdjustDecreaseChannels_0_out0_stream[1], StreamingLineBuffer_6_out0_stream_prepad[14], StreamingLineBuffer_6_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_14," << StreamingLineBuffer_6_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_0," << StreamingLineBuffer_6_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_1;
    StreamingLineBuffer_6_pixel_1.run<79>(BandwidthAdjustDecreaseChannels_0_out0_stream[0], StreamingLineBuffer_6_out0_stream_prepad[13], StreamingLineBuffer_6_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_13," << StreamingLineBuffer_6_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_1," << StreamingLineBuffer_6_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_2;
    StreamingLineBuffer_6_pixel_2.run<80>(StreamingLineBuffer_6_buffer_stream[0], StreamingLineBuffer_6_out0_stream_prepad[12], StreamingLineBuffer_6_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_12," << StreamingLineBuffer_6_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_2," << StreamingLineBuffer_6_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_3;
    StreamingLineBuffer_6_pixel_3.run<81>(StreamingLineBuffer_6_buffer_stream[1], StreamingLineBuffer_6_out0_stream_prepad[11], StreamingLineBuffer_6_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_11," << StreamingLineBuffer_6_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_4," << StreamingLineBuffer_6_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_4;
    StreamingLineBuffer_6_pixel_4.run<82>(StreamingLineBuffer_6_buffer_stream[2], StreamingLineBuffer_6_out0_stream_prepad[10], StreamingLineBuffer_6_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_10," << StreamingLineBuffer_6_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_3," << StreamingLineBuffer_6_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_6;
    StreamingLineBuffer_6_pixel_6.run<84>(StreamingLineBuffer_6_buffer_stream[4], StreamingLineBuffer_6_out0_stream_prepad[8], StreamingLineBuffer_6_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_8," << StreamingLineBuffer_6_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_6," << StreamingLineBuffer_6_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_5;
    StreamingLineBuffer_6_pixel_5.run<83>(StreamingLineBuffer_6_buffer_stream[3], StreamingLineBuffer_6_out0_stream_prepad[9], StreamingLineBuffer_6_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_9," << StreamingLineBuffer_6_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_5," << StreamingLineBuffer_6_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_8;
    StreamingLineBuffer_6_pixel_8.run<86>(StreamingLineBuffer_6_buffer_stream[6], StreamingLineBuffer_6_out0_stream_prepad[6], StreamingLineBuffer_6_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_6," << StreamingLineBuffer_6_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_9," << StreamingLineBuffer_6_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_7;
    StreamingLineBuffer_6_pixel_7.run<85>(StreamingLineBuffer_6_buffer_stream[5], StreamingLineBuffer_6_out0_stream_prepad[7], StreamingLineBuffer_6_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_7," << StreamingLineBuffer_6_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_7," << StreamingLineBuffer_6_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_11;
    StreamingLineBuffer_6_pixel_11.run<89>(StreamingLineBuffer_6_buffer_stream[9], StreamingLineBuffer_6_out0_stream_prepad[3], StreamingLineBuffer_6_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_3," << StreamingLineBuffer_6_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_11," << StreamingLineBuffer_6_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_9;
    StreamingLineBuffer_6_pixel_9.run<87>(StreamingLineBuffer_6_buffer_stream[7], StreamingLineBuffer_6_out0_stream_prepad[5], StreamingLineBuffer_6_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_5," << StreamingLineBuffer_6_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_8," << StreamingLineBuffer_6_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_13;
    StreamingLineBuffer_6_pixel_13.run<91>(StreamingLineBuffer_6_buffer_stream[11], StreamingLineBuffer_6_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_1," << StreamingLineBuffer_6_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_10;
    StreamingLineBuffer_6_pixel_10.run<88>(StreamingLineBuffer_6_buffer_stream[8], StreamingLineBuffer_6_out0_stream_prepad[4], StreamingLineBuffer_6_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_4," << StreamingLineBuffer_6_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_10," << StreamingLineBuffer_6_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_12;
    StreamingLineBuffer_6_pixel_12.run<90>(StreamingLineBuffer_6_buffer_stream[10], StreamingLineBuffer_6_out0_stream_prepad[2], StreamingLineBuffer_6_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_2," << StreamingLineBuffer_6_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_buffer_stream_12," << StreamingLineBuffer_6_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
    > StreamingLineBuffer_6_pixel_14;
    StreamingLineBuffer_6_pixel_14.run<92>(StreamingLineBuffer_6_buffer_stream[12], StreamingLineBuffer_6_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_6_out0_stream_prepad_0," << StreamingLineBuffer_6_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        160,  // IN_HEIGHT
        160,  // IN_WIDTH
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
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_6_pad;
    StreamingLineBuffer_6_pad.run<93>(StreamingLineBuffer_6_out0_stream_prepad, StreamingLineBuffer_6_out0_stream);
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
    ap_int<8> StreamingConv_6_weights[2048][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_weights dim=2 complete
    ap_int<14> StreamingConv_6_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_6_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_6;
    StreamingConv_6.run<94>(StreamingLineBuffer_6_out0_stream, StreamingConv_6_weights, StreamingConv_6_biases, StreamingConv_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_0," << StreamingConv_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_6_out0_stream_1," << StreamingConv_6_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_6_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_6;
    StreamingSwish_6.run<95>(StreamingConv_6_out0_stream, StreamingSwish_6_lut, StreamingSwish_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_6_out0_stream_0," << StreamingSwish_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_6_out0_stream_1," << StreamingSwish_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_0;
    StreamingLineBuffer_7_pixel_0.run<96>(StreamingSwish_6_out0_stream[1], StreamingLineBuffer_7_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_1," << StreamingLineBuffer_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_7_pixel_1;
    StreamingLineBuffer_7_pixel_1.run<97>(StreamingSwish_6_out0_stream[0], StreamingLineBuffer_7_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_7_out0_stream_0," << StreamingLineBuffer_7_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_7_weights[2048][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_weights dim=2 complete
    ap_int<13> StreamingConv_7_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_7_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_7;
    StreamingConv_7.run<98>(StreamingLineBuffer_7_out0_stream, StreamingConv_7_weights, StreamingConv_7_biases, StreamingConv_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_0," << StreamingConv_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_7_out0_stream_1," << StreamingConv_7_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_7_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_7;
    StreamingSwish_7.run<99>(StreamingConv_7_out0_stream, StreamingSwish_7_lut, StreamingSwish_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_7_out0_stream_0," << StreamingSwish_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_7_out0_stream_1," << StreamingSwish_7_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_1;
    BandwidthAdjustIncreaseChannels_1.run<100>(StreamingSwish_7_out0_stream, BandwidthAdjustIncreaseChannels_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_0," << BandwidthAdjustIncreaseChannels_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_1_out0_stream_1," << BandwidthAdjustIncreaseChannels_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        32,  // SPLIT
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_1;
    StreamingSplit_1.run<101>(BandwidthAdjustIncreaseChannels_1_out0_stream, StreamingSplit_1_out0_stream, StreamingSplit_1_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_1_out0_stream_0," << StreamingSplit_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_1_out0_stream_1," << StreamingSplit_1_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_1_out1_stream_0," << StreamingSplit_1_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_1_out1_stream_1," << StreamingSplit_1_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.run<102>(StreamingSplit_1_out1_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
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
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_3;
    TensorDuplicator_3.run<103>(TensorDuplicator_2_out0_stream, TensorDuplicator_3_out0_stream, TensorDuplicator_3_out1_stream);
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
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_1;
    BandwidthAdjustDecreaseChannels_1.run<104>(TensorDuplicator_2_out1_stream, BandwidthAdjustDecreaseChannels_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_0," << BandwidthAdjustDecreaseChannels_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_1_out0_stream_1," << BandwidthAdjustDecreaseChannels_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH_A
        32,  // IN_CH_B
        2,  // W_PAR
        4  // CH_PAR
    > StreamingConcat_2;
    StreamingConcat_2.run<105>(StreamingSplit_1_out0_stream, TensorDuplicator_3_out1_stream, StreamingConcat_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_2_out0_stream_0," << StreamingConcat_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_2_out0_stream_1," << StreamingConcat_2_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_2;
    BandwidthAdjustDecreaseChannels_2.run<106>(TensorDuplicator_3_out0_stream, BandwidthAdjustDecreaseChannels_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_0," << BandwidthAdjustDecreaseChannels_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_2_out0_stream_1," << BandwidthAdjustDecreaseChannels_2_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_3;
    BandwidthAdjustDecreaseChannels_3.run<107>(StreamingConcat_2_out0_stream, BandwidthAdjustDecreaseChannels_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_0," << BandwidthAdjustDecreaseChannels_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_3_out0_stream_1," << BandwidthAdjustDecreaseChannels_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_0;
    StreamingLineBuffer_8_pixel_0.run<108>(BandwidthAdjustDecreaseChannels_2_out0_stream[0], StreamingLineBuffer_8_out0_stream_prepad[11], StreamingLineBuffer_8_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_11," << StreamingLineBuffer_8_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_0," << StreamingLineBuffer_8_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_1;
    StreamingLineBuffer_8_pixel_1.run<109>(BandwidthAdjustDecreaseChannels_2_out0_stream[1], StreamingLineBuffer_8_out0_stream_prepad[10], StreamingLineBuffer_8_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_10," << StreamingLineBuffer_8_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_1," << StreamingLineBuffer_8_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_2;
    StreamingLineBuffer_8_pixel_2.run<110>(StreamingLineBuffer_8_buffer_stream[0], StreamingLineBuffer_8_out0_stream_prepad[9], StreamingLineBuffer_8_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_9," << StreamingLineBuffer_8_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_2," << StreamingLineBuffer_8_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_3;
    StreamingLineBuffer_8_pixel_3.run<111>(StreamingLineBuffer_8_buffer_stream[1], StreamingLineBuffer_8_out0_stream_prepad[8], StreamingLineBuffer_8_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_8," << StreamingLineBuffer_8_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_3," << StreamingLineBuffer_8_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_4;
    StreamingLineBuffer_8_pixel_4.run<112>(StreamingLineBuffer_8_buffer_stream[2], StreamingLineBuffer_8_out0_stream_prepad[7], StreamingLineBuffer_8_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_7," << StreamingLineBuffer_8_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_4," << StreamingLineBuffer_8_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_5;
    StreamingLineBuffer_8_pixel_5.run<113>(StreamingLineBuffer_8_buffer_stream[3], StreamingLineBuffer_8_out0_stream_prepad[6], StreamingLineBuffer_8_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_6," << StreamingLineBuffer_8_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_5," << StreamingLineBuffer_8_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_6;
    StreamingLineBuffer_8_pixel_6.run<114>(StreamingLineBuffer_8_buffer_stream[4], StreamingLineBuffer_8_out0_stream_prepad[5], StreamingLineBuffer_8_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_5," << StreamingLineBuffer_8_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_6," << StreamingLineBuffer_8_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_7;
    StreamingLineBuffer_8_pixel_7.run<115>(StreamingLineBuffer_8_buffer_stream[5], StreamingLineBuffer_8_out0_stream_prepad[4], StreamingLineBuffer_8_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_4," << StreamingLineBuffer_8_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_7," << StreamingLineBuffer_8_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_8;
    StreamingLineBuffer_8_pixel_8.run<116>(StreamingLineBuffer_8_buffer_stream[6], StreamingLineBuffer_8_out0_stream_prepad[3], StreamingLineBuffer_8_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_3," << StreamingLineBuffer_8_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_8," << StreamingLineBuffer_8_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_9;
    StreamingLineBuffer_8_pixel_9.run<117>(StreamingLineBuffer_8_buffer_stream[7], StreamingLineBuffer_8_out0_stream_prepad[2], StreamingLineBuffer_8_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_2," << StreamingLineBuffer_8_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_buffer_stream_9," << StreamingLineBuffer_8_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_10;
    StreamingLineBuffer_8_pixel_10.run<118>(StreamingLineBuffer_8_buffer_stream[8], StreamingLineBuffer_8_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_1," << StreamingLineBuffer_8_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pixel_11;
    StreamingLineBuffer_8_pixel_11.run<119>(StreamingLineBuffer_8_buffer_stream[9], StreamingLineBuffer_8_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_8_out0_stream_prepad_0," << StreamingLineBuffer_8_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_8_pad;
    StreamingLineBuffer_8_pad.run<120>(StreamingLineBuffer_8_out0_stream_prepad, StreamingLineBuffer_8_out0_stream);
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
    ap_int<8> StreamingConv_8_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_weights dim=2 complete
    ap_int<13> StreamingConv_8_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_8_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<6, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_8;
    StreamingConv_8.run<121>(StreamingLineBuffer_8_out0_stream, StreamingConv_8_weights, StreamingConv_8_biases, StreamingConv_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_0," << StreamingConv_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_8_out0_stream_1," << StreamingConv_8_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_8_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_8;
    StreamingSwish_8.run<122>(StreamingConv_8_out0_stream, StreamingSwish_8_lut, StreamingSwish_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_8_out0_stream_0," << StreamingSwish_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_8_out0_stream_1," << StreamingSwish_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_0.run<123>(StreamingSwish_8_out0_stream[0], StreamingLineBuffer_9_out0_stream_prepad[11], StreamingLineBuffer_9_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_11," << StreamingLineBuffer_9_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_0," << StreamingLineBuffer_9_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_1.run<124>(StreamingSwish_8_out0_stream[1], StreamingLineBuffer_9_out0_stream_prepad[10], StreamingLineBuffer_9_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_10," << StreamingLineBuffer_9_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_1," << StreamingLineBuffer_9_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_2.run<125>(StreamingLineBuffer_9_buffer_stream[0], StreamingLineBuffer_9_out0_stream_prepad[9], StreamingLineBuffer_9_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_9," << StreamingLineBuffer_9_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_2," << StreamingLineBuffer_9_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_3.run<126>(StreamingLineBuffer_9_buffer_stream[1], StreamingLineBuffer_9_out0_stream_prepad[8], StreamingLineBuffer_9_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_8," << StreamingLineBuffer_9_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_3," << StreamingLineBuffer_9_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_4.run<127>(StreamingLineBuffer_9_buffer_stream[2], StreamingLineBuffer_9_out0_stream_prepad[7], StreamingLineBuffer_9_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_7," << StreamingLineBuffer_9_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_4," << StreamingLineBuffer_9_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_5.run<128>(StreamingLineBuffer_9_buffer_stream[3], StreamingLineBuffer_9_out0_stream_prepad[6], StreamingLineBuffer_9_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_6," << StreamingLineBuffer_9_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_5," << StreamingLineBuffer_9_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_6.run<129>(StreamingLineBuffer_9_buffer_stream[4], StreamingLineBuffer_9_out0_stream_prepad[5], StreamingLineBuffer_9_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_5," << StreamingLineBuffer_9_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_6," << StreamingLineBuffer_9_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_7.run<130>(StreamingLineBuffer_9_buffer_stream[5], StreamingLineBuffer_9_out0_stream_prepad[4], StreamingLineBuffer_9_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_4," << StreamingLineBuffer_9_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_7," << StreamingLineBuffer_9_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_8.run<131>(StreamingLineBuffer_9_buffer_stream[6], StreamingLineBuffer_9_out0_stream_prepad[3], StreamingLineBuffer_9_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_3," << StreamingLineBuffer_9_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_8," << StreamingLineBuffer_9_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_9.run<132>(StreamingLineBuffer_9_buffer_stream[7], StreamingLineBuffer_9_out0_stream_prepad[2], StreamingLineBuffer_9_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_2," << StreamingLineBuffer_9_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_buffer_stream_9," << StreamingLineBuffer_9_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_10.run<133>(StreamingLineBuffer_9_buffer_stream[8], StreamingLineBuffer_9_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_1," << StreamingLineBuffer_9_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pixel_11.run<134>(StreamingLineBuffer_9_buffer_stream[9], StreamingLineBuffer_9_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_9_out0_stream_prepad_0," << StreamingLineBuffer_9_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_9_pad.run<135>(StreamingLineBuffer_9_out0_stream_prepad, StreamingLineBuffer_9_out0_stream);
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
    ap_int<8> StreamingConv_9_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_weights dim=2 complete
    ap_int<14> StreamingConv_9_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_9_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_9;
    StreamingConv_9.run<136>(StreamingLineBuffer_9_out0_stream, StreamingConv_9_weights, StreamingConv_9_biases, StreamingConv_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_0," << StreamingConv_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_9_out0_stream_1," << StreamingConv_9_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_9_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_9;
    StreamingSwish_9.run<137>(StreamingConv_9_out0_stream, StreamingSwish_9_lut, StreamingSwish_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_9_out0_stream_0," << StreamingSwish_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_9_out0_stream_1," << StreamingSwish_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<10>,  // TAcc
        DequantQuantEqual<ap_int<10>>,  // Activation
        DequantQuantPo2<1, ap_int<10>, ap_int<8>>,  // Quantizer
        DequantQuantPo2<-1, ap_int<8>, ap_int<10>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_1;
    StreamingAdd_1.run<138>(BandwidthAdjustDecreaseChannels_1_out0_stream, StreamingSwish_9_out0_stream, StreamingAdd_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_0," << StreamingAdd_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_1_out0_stream_1," << StreamingAdd_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_2;
    BandwidthAdjustIncreaseChannels_2.run<139>(StreamingAdd_1_out0_stream, BandwidthAdjustIncreaseChannels_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_0," << BandwidthAdjustIncreaseChannels_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_2_out0_stream_1," << BandwidthAdjustIncreaseChannels_2_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_4;
    TensorDuplicator_4.run<140>(BandwidthAdjustIncreaseChannels_2_out0_stream, TensorDuplicator_4_out0_stream, TensorDuplicator_4_out1_stream);
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
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_5;
    TensorDuplicator_5.run<141>(TensorDuplicator_4_out0_stream, TensorDuplicator_5_out0_stream, TensorDuplicator_5_out1_stream);
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
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_4;
    BandwidthAdjustDecreaseChannels_4.run<142>(TensorDuplicator_4_out1_stream, BandwidthAdjustDecreaseChannels_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_0," << BandwidthAdjustDecreaseChannels_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_4_out0_stream_1," << BandwidthAdjustDecreaseChannels_4_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_5;
    BandwidthAdjustDecreaseChannels_5.run<143>(TensorDuplicator_5_out0_stream, BandwidthAdjustDecreaseChannels_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_0," << BandwidthAdjustDecreaseChannels_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_5_out0_stream_1," << BandwidthAdjustDecreaseChannels_5_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_6;
    BandwidthAdjustDecreaseChannels_6.run<144>(TensorDuplicator_5_out1_stream, BandwidthAdjustDecreaseChannels_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_0," << BandwidthAdjustDecreaseChannels_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_6_out0_stream_1," << BandwidthAdjustDecreaseChannels_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_0;
    StreamingLineBuffer_10_pixel_0.run<145>(BandwidthAdjustDecreaseChannels_5_out0_stream[0], StreamingLineBuffer_10_out0_stream_prepad[11], StreamingLineBuffer_10_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_11," << StreamingLineBuffer_10_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_0," << StreamingLineBuffer_10_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_1;
    StreamingLineBuffer_10_pixel_1.run<146>(BandwidthAdjustDecreaseChannels_5_out0_stream[1], StreamingLineBuffer_10_out0_stream_prepad[10], StreamingLineBuffer_10_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_10," << StreamingLineBuffer_10_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_1," << StreamingLineBuffer_10_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_2;
    StreamingLineBuffer_10_pixel_2.run<147>(StreamingLineBuffer_10_buffer_stream[0], StreamingLineBuffer_10_out0_stream_prepad[9], StreamingLineBuffer_10_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_9," << StreamingLineBuffer_10_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_2," << StreamingLineBuffer_10_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_3;
    StreamingLineBuffer_10_pixel_3.run<148>(StreamingLineBuffer_10_buffer_stream[1], StreamingLineBuffer_10_out0_stream_prepad[8], StreamingLineBuffer_10_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_8," << StreamingLineBuffer_10_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_3," << StreamingLineBuffer_10_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_4;
    StreamingLineBuffer_10_pixel_4.run<149>(StreamingLineBuffer_10_buffer_stream[2], StreamingLineBuffer_10_out0_stream_prepad[7], StreamingLineBuffer_10_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_7," << StreamingLineBuffer_10_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_4," << StreamingLineBuffer_10_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_5;
    StreamingLineBuffer_10_pixel_5.run<150>(StreamingLineBuffer_10_buffer_stream[3], StreamingLineBuffer_10_out0_stream_prepad[6], StreamingLineBuffer_10_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_6," << StreamingLineBuffer_10_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_5," << StreamingLineBuffer_10_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_6;
    StreamingLineBuffer_10_pixel_6.run<151>(StreamingLineBuffer_10_buffer_stream[4], StreamingLineBuffer_10_out0_stream_prepad[5], StreamingLineBuffer_10_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_5," << StreamingLineBuffer_10_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_6," << StreamingLineBuffer_10_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_7;
    StreamingLineBuffer_10_pixel_7.run<152>(StreamingLineBuffer_10_buffer_stream[5], StreamingLineBuffer_10_out0_stream_prepad[4], StreamingLineBuffer_10_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_4," << StreamingLineBuffer_10_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_7," << StreamingLineBuffer_10_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_8;
    StreamingLineBuffer_10_pixel_8.run<153>(StreamingLineBuffer_10_buffer_stream[6], StreamingLineBuffer_10_out0_stream_prepad[3], StreamingLineBuffer_10_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_3," << StreamingLineBuffer_10_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_8," << StreamingLineBuffer_10_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_9;
    StreamingLineBuffer_10_pixel_9.run<154>(StreamingLineBuffer_10_buffer_stream[7], StreamingLineBuffer_10_out0_stream_prepad[2], StreamingLineBuffer_10_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_2," << StreamingLineBuffer_10_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_buffer_stream_9," << StreamingLineBuffer_10_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_10;
    StreamingLineBuffer_10_pixel_10.run<155>(StreamingLineBuffer_10_buffer_stream[8], StreamingLineBuffer_10_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_1," << StreamingLineBuffer_10_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pixel_11;
    StreamingLineBuffer_10_pixel_11.run<156>(StreamingLineBuffer_10_buffer_stream[9], StreamingLineBuffer_10_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_10_out0_stream_prepad_0," << StreamingLineBuffer_10_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_10_pad;
    StreamingLineBuffer_10_pad.run<157>(StreamingLineBuffer_10_out0_stream_prepad, StreamingLineBuffer_10_out0_stream);
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
    ap_int<8> StreamingConv_10_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_weights dim=2 complete
    ap_int<14> StreamingConv_10_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_10_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<6, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_10;
    StreamingConv_10.run<158>(StreamingLineBuffer_10_out0_stream, StreamingConv_10_weights, StreamingConv_10_biases, StreamingConv_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_0," << StreamingConv_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_10_out0_stream_1," << StreamingConv_10_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_10_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_10;
    StreamingSwish_10.run<159>(StreamingConv_10_out0_stream, StreamingSwish_10_lut, StreamingSwish_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_10_out0_stream_0," << StreamingSwish_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_10_out0_stream_1," << StreamingSwish_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_0.run<160>(StreamingSwish_10_out0_stream[0], StreamingLineBuffer_11_out0_stream_prepad[11], StreamingLineBuffer_11_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_11," << StreamingLineBuffer_11_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_0," << StreamingLineBuffer_11_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_1.run<161>(StreamingSwish_10_out0_stream[1], StreamingLineBuffer_11_out0_stream_prepad[10], StreamingLineBuffer_11_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_10," << StreamingLineBuffer_11_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_1," << StreamingLineBuffer_11_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_2.run<162>(StreamingLineBuffer_11_buffer_stream[0], StreamingLineBuffer_11_out0_stream_prepad[9], StreamingLineBuffer_11_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_9," << StreamingLineBuffer_11_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_2," << StreamingLineBuffer_11_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_3.run<163>(StreamingLineBuffer_11_buffer_stream[1], StreamingLineBuffer_11_out0_stream_prepad[8], StreamingLineBuffer_11_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_8," << StreamingLineBuffer_11_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_3," << StreamingLineBuffer_11_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_4.run<164>(StreamingLineBuffer_11_buffer_stream[2], StreamingLineBuffer_11_out0_stream_prepad[7], StreamingLineBuffer_11_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_7," << StreamingLineBuffer_11_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_4," << StreamingLineBuffer_11_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_5.run<165>(StreamingLineBuffer_11_buffer_stream[3], StreamingLineBuffer_11_out0_stream_prepad[6], StreamingLineBuffer_11_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_6," << StreamingLineBuffer_11_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_5," << StreamingLineBuffer_11_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_6.run<166>(StreamingLineBuffer_11_buffer_stream[4], StreamingLineBuffer_11_out0_stream_prepad[5], StreamingLineBuffer_11_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_5," << StreamingLineBuffer_11_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_6," << StreamingLineBuffer_11_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_7.run<167>(StreamingLineBuffer_11_buffer_stream[5], StreamingLineBuffer_11_out0_stream_prepad[4], StreamingLineBuffer_11_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_4," << StreamingLineBuffer_11_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_7," << StreamingLineBuffer_11_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_8.run<168>(StreamingLineBuffer_11_buffer_stream[6], StreamingLineBuffer_11_out0_stream_prepad[3], StreamingLineBuffer_11_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_3," << StreamingLineBuffer_11_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_8," << StreamingLineBuffer_11_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_9.run<169>(StreamingLineBuffer_11_buffer_stream[7], StreamingLineBuffer_11_out0_stream_prepad[2], StreamingLineBuffer_11_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_2," << StreamingLineBuffer_11_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_buffer_stream_9," << StreamingLineBuffer_11_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_10.run<170>(StreamingLineBuffer_11_buffer_stream[8], StreamingLineBuffer_11_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_1," << StreamingLineBuffer_11_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pixel_11.run<171>(StreamingLineBuffer_11_buffer_stream[9], StreamingLineBuffer_11_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_11_out0_stream_prepad_0," << StreamingLineBuffer_11_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    StreamingLineBuffer_11_pad.run<172>(StreamingLineBuffer_11_out0_stream_prepad, StreamingLineBuffer_11_out0_stream);
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
    ap_int<8> StreamingConv_11_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_weights dim=2 complete
    ap_int<15> StreamingConv_11_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_11_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
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
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_11;
    StreamingConv_11.run<173>(StreamingLineBuffer_11_out0_stream, StreamingConv_11_weights, StreamingConv_11_biases, StreamingConv_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_0," << StreamingConv_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_11_out0_stream_1," << StreamingConv_11_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_11_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_11;
    StreamingSwish_11.run<174>(StreamingConv_11_out0_stream, StreamingSwish_11_lut, StreamingSwish_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_11_out0_stream_0," << StreamingSwish_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_11_out0_stream_1," << StreamingSwish_11_out0_stream[1].size() << std::endl;
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
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_2;
    StreamingAdd_2.run<175>(BandwidthAdjustDecreaseChannels_6_out0_stream, StreamingSwish_11_out0_stream, StreamingAdd_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_0," << StreamingAdd_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_2_out0_stream_1," << StreamingAdd_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH_A
        32,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_3;
    StreamingConcat_3.run<176>(BandwidthAdjustDecreaseChannels_4_out0_stream, StreamingAdd_2_out0_stream, StreamingConcat_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_3_out0_stream_0," << StreamingConcat_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_3_out0_stream_1," << StreamingConcat_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH_A
        64,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_4;
    StreamingConcat_4.run<177>(BandwidthAdjustDecreaseChannels_3_out0_stream, StreamingConcat_3_out0_stream, StreamingConcat_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_4_out0_stream_0," << StreamingConcat_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_4_out0_stream_1," << StreamingConcat_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_12_pixel_0;
    StreamingLineBuffer_12_pixel_0.run<178>(StreamingConcat_4_out0_stream[1], StreamingLineBuffer_12_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_1," << StreamingLineBuffer_12_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_12_pixel_1;
    StreamingLineBuffer_12_pixel_1.run<179>(StreamingConcat_4_out0_stream[0], StreamingLineBuffer_12_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_12_out0_stream_0," << StreamingLineBuffer_12_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_12_weights[2048][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_weights dim=2 complete
    ap_int<14> StreamingConv_12_biases[16][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_12_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 4>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        128,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_12;
    StreamingConv_12.run<180>(StreamingLineBuffer_12_out0_stream, StreamingConv_12_weights, StreamingConv_12_biases, StreamingConv_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_0," << StreamingConv_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_12_out0_stream_1," << StreamingConv_12_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_12_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_12;
    StreamingSwish_12.run<181>(StreamingConv_12_out0_stream, StreamingSwish_12_lut, StreamingSwish_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_12_out0_stream_0," << StreamingSwish_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_12_out0_stream_1," << StreamingSwish_12_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_6;
    TensorDuplicator_6.run<182>(StreamingSwish_12_out0_stream, TensorDuplicator_6_out0_stream, TensorDuplicator_6_out1_stream);
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
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_13_pixel_0;
    StreamingLineBuffer_13_pixel_0.run<183>(TensorDuplicator_6_out0_stream[1], StreamingLineBuffer_13_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_1," << StreamingLineBuffer_13_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_13_pixel_1;
    StreamingLineBuffer_13_pixel_1.run<184>(TensorDuplicator_6_out0_stream[0], StreamingLineBuffer_13_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_13_out0_stream_0," << StreamingLineBuffer_13_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_13_weights[2048][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_weights dim=2 complete
    ap_int<14> StreamingConv_13_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_13_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_13;
    StreamingConv_13.run<185>(StreamingLineBuffer_13_out0_stream, StreamingConv_13_weights, StreamingConv_13_biases, StreamingConv_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_13_out0_stream_0," << StreamingConv_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_13_out0_stream_1," << StreamingConv_13_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_13_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_13;
    StreamingSwish_13.run<186>(StreamingConv_13_out0_stream, StreamingSwish_13_lut, StreamingSwish_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_13_out0_stream_0," << StreamingSwish_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_13_out0_stream_1," << StreamingSwish_13_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_0;
    StreamingLineBuffer_14_pixel_0.run<187>(StreamingSwish_13_out0_stream[1], StreamingLineBuffer_14_out0_stream_prepad[14], StreamingLineBuffer_14_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_14," << StreamingLineBuffer_14_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_0," << StreamingLineBuffer_14_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_1;
    StreamingLineBuffer_14_pixel_1.run<188>(StreamingSwish_13_out0_stream[0], StreamingLineBuffer_14_out0_stream_prepad[13], StreamingLineBuffer_14_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_13," << StreamingLineBuffer_14_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_1," << StreamingLineBuffer_14_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_2;
    StreamingLineBuffer_14_pixel_2.run<189>(StreamingLineBuffer_14_buffer_stream[0], StreamingLineBuffer_14_out0_stream_prepad[12], StreamingLineBuffer_14_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_12," << StreamingLineBuffer_14_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_2," << StreamingLineBuffer_14_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_3;
    StreamingLineBuffer_14_pixel_3.run<190>(StreamingLineBuffer_14_buffer_stream[1], StreamingLineBuffer_14_out0_stream_prepad[11], StreamingLineBuffer_14_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_11," << StreamingLineBuffer_14_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_4," << StreamingLineBuffer_14_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_4;
    StreamingLineBuffer_14_pixel_4.run<191>(StreamingLineBuffer_14_buffer_stream[2], StreamingLineBuffer_14_out0_stream_prepad[10], StreamingLineBuffer_14_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_10," << StreamingLineBuffer_14_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_3," << StreamingLineBuffer_14_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_6;
    StreamingLineBuffer_14_pixel_6.run<193>(StreamingLineBuffer_14_buffer_stream[4], StreamingLineBuffer_14_out0_stream_prepad[8], StreamingLineBuffer_14_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_8," << StreamingLineBuffer_14_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_6," << StreamingLineBuffer_14_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_5;
    StreamingLineBuffer_14_pixel_5.run<192>(StreamingLineBuffer_14_buffer_stream[3], StreamingLineBuffer_14_out0_stream_prepad[9], StreamingLineBuffer_14_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_9," << StreamingLineBuffer_14_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_5," << StreamingLineBuffer_14_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_8;
    StreamingLineBuffer_14_pixel_8.run<195>(StreamingLineBuffer_14_buffer_stream[6], StreamingLineBuffer_14_out0_stream_prepad[6], StreamingLineBuffer_14_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_6," << StreamingLineBuffer_14_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_9," << StreamingLineBuffer_14_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_7;
    StreamingLineBuffer_14_pixel_7.run<194>(StreamingLineBuffer_14_buffer_stream[5], StreamingLineBuffer_14_out0_stream_prepad[7], StreamingLineBuffer_14_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_7," << StreamingLineBuffer_14_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_7," << StreamingLineBuffer_14_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_11;
    StreamingLineBuffer_14_pixel_11.run<198>(StreamingLineBuffer_14_buffer_stream[9], StreamingLineBuffer_14_out0_stream_prepad[3], StreamingLineBuffer_14_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_3," << StreamingLineBuffer_14_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_11," << StreamingLineBuffer_14_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_9;
    StreamingLineBuffer_14_pixel_9.run<196>(StreamingLineBuffer_14_buffer_stream[7], StreamingLineBuffer_14_out0_stream_prepad[5], StreamingLineBuffer_14_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_5," << StreamingLineBuffer_14_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_8," << StreamingLineBuffer_14_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_13;
    StreamingLineBuffer_14_pixel_13.run<200>(StreamingLineBuffer_14_buffer_stream[11], StreamingLineBuffer_14_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_1," << StreamingLineBuffer_14_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_10;
    StreamingLineBuffer_14_pixel_10.run<197>(StreamingLineBuffer_14_buffer_stream[8], StreamingLineBuffer_14_out0_stream_prepad[4], StreamingLineBuffer_14_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_4," << StreamingLineBuffer_14_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_10," << StreamingLineBuffer_14_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_12;
    StreamingLineBuffer_14_pixel_12.run<199>(StreamingLineBuffer_14_buffer_stream[10], StreamingLineBuffer_14_out0_stream_prepad[2], StreamingLineBuffer_14_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_2," << StreamingLineBuffer_14_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_buffer_stream_12," << StreamingLineBuffer_14_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pixel_14;
    StreamingLineBuffer_14_pixel_14.run<201>(StreamingLineBuffer_14_buffer_stream[12], StreamingLineBuffer_14_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_14_out0_stream_prepad_0," << StreamingLineBuffer_14_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_14_pad;
    StreamingLineBuffer_14_pad.run<202>(StreamingLineBuffer_14_out0_stream_prepad, StreamingLineBuffer_14_out0_stream);
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
    ap_int<8> StreamingDepthwiseConv_0_weights[128][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_weights dim=2 complete
    ap_int<13> StreamingDepthwiseConv_0_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_0_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasStruct
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        DequantQuantEqual<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_0;
    StreamingDepthwiseConv_0.run<203>(StreamingLineBuffer_14_out0_stream, StreamingDepthwiseConv_0_weights, StreamingDepthwiseConv_0_biases, StreamingDepthwiseConv_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_0," << StreamingDepthwiseConv_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_0_out0_stream_1," << StreamingDepthwiseConv_0_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_15_pixel_0;
    StreamingLineBuffer_15_pixel_0.run<204>(StreamingDepthwiseConv_0_out0_stream[1], StreamingLineBuffer_15_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_1," << StreamingLineBuffer_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_15_pixel_1;
    StreamingLineBuffer_15_pixel_1.run<205>(StreamingDepthwiseConv_0_out0_stream[0], StreamingLineBuffer_15_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_15_out0_stream_0," << StreamingLineBuffer_15_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_14_weights[8192][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_weights dim=2 complete
    ap_int<12> StreamingConv_14_biases[64][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_14_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 2>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_14;
    StreamingConv_14.run<206>(StreamingLineBuffer_15_out0_stream, StreamingConv_14_weights, StreamingConv_14_biases, StreamingConv_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_0," << StreamingConv_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_14_out0_stream_1," << StreamingConv_14_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_14_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_14;
    StreamingSwish_14.run<207>(StreamingConv_14_out0_stream, StreamingSwish_14_lut, StreamingSwish_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_14_out0_stream_0," << StreamingSwish_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_14_out0_stream_1," << StreamingSwish_14_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_7;
    BandwidthAdjustDecreaseChannels_7.run<208>(StreamingSwish_14_out0_stream, BandwidthAdjustDecreaseChannels_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_7_out0_stream_0," << BandwidthAdjustDecreaseChannels_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_7_out0_stream_1," << BandwidthAdjustDecreaseChannels_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        64,  // SPLIT
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_2;
    StreamingSplit_2.run<209>(BandwidthAdjustDecreaseChannels_7_out0_stream, StreamingSplit_2_out0_stream, StreamingSplit_2_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_2_out0_stream_0," << StreamingSplit_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_2_out0_stream_1," << StreamingSplit_2_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_2_out1_stream_0," << StreamingSplit_2_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_2_out1_stream_1," << StreamingSplit_2_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_7;
    TensorDuplicator_7.run<210>(StreamingSplit_2_out1_stream, TensorDuplicator_7_out0_stream, TensorDuplicator_7_out1_stream);
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
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_8;
    TensorDuplicator_8.run<211>(TensorDuplicator_7_out0_stream, TensorDuplicator_8_out0_stream, TensorDuplicator_8_out1_stream);
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
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH_A
        64,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_5;
    StreamingConcat_5.run<212>(StreamingSplit_2_out0_stream, TensorDuplicator_8_out1_stream, StreamingConcat_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_5_out0_stream_0," << StreamingConcat_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_5_out0_stream_1," << StreamingConcat_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_0;
    StreamingLineBuffer_16_pixel_0.run<213>(TensorDuplicator_8_out0_stream[0], StreamingLineBuffer_16_out0_stream_prepad[11], StreamingLineBuffer_16_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_11," << StreamingLineBuffer_16_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_0," << StreamingLineBuffer_16_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_1;
    StreamingLineBuffer_16_pixel_1.run<214>(TensorDuplicator_8_out0_stream[1], StreamingLineBuffer_16_out0_stream_prepad[10], StreamingLineBuffer_16_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_10," << StreamingLineBuffer_16_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_1," << StreamingLineBuffer_16_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_2;
    StreamingLineBuffer_16_pixel_2.run<215>(StreamingLineBuffer_16_buffer_stream[0], StreamingLineBuffer_16_out0_stream_prepad[9], StreamingLineBuffer_16_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_9," << StreamingLineBuffer_16_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_2," << StreamingLineBuffer_16_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_3;
    StreamingLineBuffer_16_pixel_3.run<216>(StreamingLineBuffer_16_buffer_stream[1], StreamingLineBuffer_16_out0_stream_prepad[8], StreamingLineBuffer_16_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_8," << StreamingLineBuffer_16_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_3," << StreamingLineBuffer_16_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_4;
    StreamingLineBuffer_16_pixel_4.run<217>(StreamingLineBuffer_16_buffer_stream[2], StreamingLineBuffer_16_out0_stream_prepad[7], StreamingLineBuffer_16_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_7," << StreamingLineBuffer_16_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_4," << StreamingLineBuffer_16_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_5;
    StreamingLineBuffer_16_pixel_5.run<218>(StreamingLineBuffer_16_buffer_stream[3], StreamingLineBuffer_16_out0_stream_prepad[6], StreamingLineBuffer_16_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_6," << StreamingLineBuffer_16_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_5," << StreamingLineBuffer_16_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_6;
    StreamingLineBuffer_16_pixel_6.run<219>(StreamingLineBuffer_16_buffer_stream[4], StreamingLineBuffer_16_out0_stream_prepad[5], StreamingLineBuffer_16_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_5," << StreamingLineBuffer_16_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_6," << StreamingLineBuffer_16_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_7;
    StreamingLineBuffer_16_pixel_7.run<220>(StreamingLineBuffer_16_buffer_stream[5], StreamingLineBuffer_16_out0_stream_prepad[4], StreamingLineBuffer_16_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_4," << StreamingLineBuffer_16_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_7," << StreamingLineBuffer_16_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_8;
    StreamingLineBuffer_16_pixel_8.run<221>(StreamingLineBuffer_16_buffer_stream[6], StreamingLineBuffer_16_out0_stream_prepad[3], StreamingLineBuffer_16_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_3," << StreamingLineBuffer_16_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_8," << StreamingLineBuffer_16_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_9;
    StreamingLineBuffer_16_pixel_9.run<222>(StreamingLineBuffer_16_buffer_stream[7], StreamingLineBuffer_16_out0_stream_prepad[2], StreamingLineBuffer_16_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_2," << StreamingLineBuffer_16_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_buffer_stream_9," << StreamingLineBuffer_16_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_10;
    StreamingLineBuffer_16_pixel_10.run<223>(StreamingLineBuffer_16_buffer_stream[8], StreamingLineBuffer_16_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_1," << StreamingLineBuffer_16_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pixel_11;
    StreamingLineBuffer_16_pixel_11.run<224>(StreamingLineBuffer_16_buffer_stream[9], StreamingLineBuffer_16_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_16_out0_stream_prepad_0," << StreamingLineBuffer_16_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_16_pad;
    StreamingLineBuffer_16_pad.run<225>(StreamingLineBuffer_16_out0_stream_prepad, StreamingLineBuffer_16_out0_stream);
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
    ap_int<8> StreamingConv_15_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_weights dim=2 complete
    ap_int<13> StreamingConv_15_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_15_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<6, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_15;
    StreamingConv_15.run<226>(StreamingLineBuffer_16_out0_stream, StreamingConv_15_weights, StreamingConv_15_biases, StreamingConv_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_0," << StreamingConv_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_15_out0_stream_1," << StreamingConv_15_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_15_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_15;
    StreamingSwish_15.run<227>(StreamingConv_15_out0_stream, StreamingSwish_15_lut, StreamingSwish_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_15_out0_stream_0," << StreamingSwish_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_15_out0_stream_1," << StreamingSwish_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_0.run<228>(StreamingSwish_15_out0_stream[0], StreamingLineBuffer_17_out0_stream_prepad[11], StreamingLineBuffer_17_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_11," << StreamingLineBuffer_17_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_0," << StreamingLineBuffer_17_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_1.run<229>(StreamingSwish_15_out0_stream[1], StreamingLineBuffer_17_out0_stream_prepad[10], StreamingLineBuffer_17_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_10," << StreamingLineBuffer_17_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_1," << StreamingLineBuffer_17_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_2.run<230>(StreamingLineBuffer_17_buffer_stream[0], StreamingLineBuffer_17_out0_stream_prepad[9], StreamingLineBuffer_17_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_9," << StreamingLineBuffer_17_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_2," << StreamingLineBuffer_17_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_3.run<231>(StreamingLineBuffer_17_buffer_stream[1], StreamingLineBuffer_17_out0_stream_prepad[8], StreamingLineBuffer_17_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_8," << StreamingLineBuffer_17_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_3," << StreamingLineBuffer_17_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_4.run<232>(StreamingLineBuffer_17_buffer_stream[2], StreamingLineBuffer_17_out0_stream_prepad[7], StreamingLineBuffer_17_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_7," << StreamingLineBuffer_17_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_4," << StreamingLineBuffer_17_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_5.run<233>(StreamingLineBuffer_17_buffer_stream[3], StreamingLineBuffer_17_out0_stream_prepad[6], StreamingLineBuffer_17_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_6," << StreamingLineBuffer_17_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_5," << StreamingLineBuffer_17_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_6.run<234>(StreamingLineBuffer_17_buffer_stream[4], StreamingLineBuffer_17_out0_stream_prepad[5], StreamingLineBuffer_17_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_5," << StreamingLineBuffer_17_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_6," << StreamingLineBuffer_17_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_7.run<235>(StreamingLineBuffer_17_buffer_stream[5], StreamingLineBuffer_17_out0_stream_prepad[4], StreamingLineBuffer_17_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_4," << StreamingLineBuffer_17_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_7," << StreamingLineBuffer_17_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_8.run<236>(StreamingLineBuffer_17_buffer_stream[6], StreamingLineBuffer_17_out0_stream_prepad[3], StreamingLineBuffer_17_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_3," << StreamingLineBuffer_17_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_8," << StreamingLineBuffer_17_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_9.run<237>(StreamingLineBuffer_17_buffer_stream[7], StreamingLineBuffer_17_out0_stream_prepad[2], StreamingLineBuffer_17_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_2," << StreamingLineBuffer_17_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_buffer_stream_9," << StreamingLineBuffer_17_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_10.run<238>(StreamingLineBuffer_17_buffer_stream[8], StreamingLineBuffer_17_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_1," << StreamingLineBuffer_17_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pixel_11.run<239>(StreamingLineBuffer_17_buffer_stream[9], StreamingLineBuffer_17_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_17_out0_stream_prepad_0," << StreamingLineBuffer_17_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_17_pad.run<240>(StreamingLineBuffer_17_out0_stream_prepad, StreamingLineBuffer_17_out0_stream);
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
    ap_int<8> StreamingConv_16_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_weights dim=2 complete
    ap_int<14> StreamingConv_16_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_16_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<7, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_16;
    StreamingConv_16.run<241>(StreamingLineBuffer_17_out0_stream, StreamingConv_16_weights, StreamingConv_16_biases, StreamingConv_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_0," << StreamingConv_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_16_out0_stream_1," << StreamingConv_16_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_16_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_16;
    StreamingSwish_16.run<242>(StreamingConv_16_out0_stream, StreamingSwish_16_lut, StreamingSwish_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_16_out0_stream_0," << StreamingSwish_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_16_out0_stream_1," << StreamingSwish_16_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<10>,  // TAcc
        DequantQuantEqual<ap_int<10>>,  // Activation
        DequantQuantPo2<1, ap_int<10>, ap_int<8>>,  // Quantizer
        DequantQuantPo2<-1, ap_int<8>, ap_int<10>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_3;
    StreamingAdd_3.run<243>(TensorDuplicator_7_out1_stream, StreamingSwish_16_out0_stream, StreamingAdd_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_0," << StreamingAdd_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_3_out0_stream_1," << StreamingAdd_3_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_9;
    TensorDuplicator_9.run<244>(StreamingAdd_3_out0_stream, TensorDuplicator_9_out0_stream, TensorDuplicator_9_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out0_stream_0," << TensorDuplicator_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out0_stream_1," << TensorDuplicator_9_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out1_stream_0," << TensorDuplicator_9_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_9_out1_stream_1," << TensorDuplicator_9_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_10;
    TensorDuplicator_10.run<245>(TensorDuplicator_9_out0_stream, TensorDuplicator_10_out0_stream, TensorDuplicator_10_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_10_out0_stream_0," << TensorDuplicator_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_10_out0_stream_1," << TensorDuplicator_10_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_10_out1_stream_0," << TensorDuplicator_10_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_10_out1_stream_1," << TensorDuplicator_10_out1_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_0;
    StreamingLineBuffer_18_pixel_0.run<246>(TensorDuplicator_10_out0_stream[0], StreamingLineBuffer_18_out0_stream_prepad[11], StreamingLineBuffer_18_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_11," << StreamingLineBuffer_18_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_0," << StreamingLineBuffer_18_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_1;
    StreamingLineBuffer_18_pixel_1.run<247>(TensorDuplicator_10_out0_stream[1], StreamingLineBuffer_18_out0_stream_prepad[10], StreamingLineBuffer_18_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_10," << StreamingLineBuffer_18_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_1," << StreamingLineBuffer_18_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_2;
    StreamingLineBuffer_18_pixel_2.run<248>(StreamingLineBuffer_18_buffer_stream[0], StreamingLineBuffer_18_out0_stream_prepad[9], StreamingLineBuffer_18_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_9," << StreamingLineBuffer_18_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_2," << StreamingLineBuffer_18_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_3;
    StreamingLineBuffer_18_pixel_3.run<249>(StreamingLineBuffer_18_buffer_stream[1], StreamingLineBuffer_18_out0_stream_prepad[8], StreamingLineBuffer_18_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_8," << StreamingLineBuffer_18_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_3," << StreamingLineBuffer_18_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_4;
    StreamingLineBuffer_18_pixel_4.run<250>(StreamingLineBuffer_18_buffer_stream[2], StreamingLineBuffer_18_out0_stream_prepad[7], StreamingLineBuffer_18_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_7," << StreamingLineBuffer_18_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_4," << StreamingLineBuffer_18_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_5;
    StreamingLineBuffer_18_pixel_5.run<251>(StreamingLineBuffer_18_buffer_stream[3], StreamingLineBuffer_18_out0_stream_prepad[6], StreamingLineBuffer_18_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_6," << StreamingLineBuffer_18_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_5," << StreamingLineBuffer_18_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_6;
    StreamingLineBuffer_18_pixel_6.run<252>(StreamingLineBuffer_18_buffer_stream[4], StreamingLineBuffer_18_out0_stream_prepad[5], StreamingLineBuffer_18_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_5," << StreamingLineBuffer_18_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_6," << StreamingLineBuffer_18_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_7;
    StreamingLineBuffer_18_pixel_7.run<253>(StreamingLineBuffer_18_buffer_stream[5], StreamingLineBuffer_18_out0_stream_prepad[4], StreamingLineBuffer_18_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_4," << StreamingLineBuffer_18_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_7," << StreamingLineBuffer_18_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_8;
    StreamingLineBuffer_18_pixel_8.run<254>(StreamingLineBuffer_18_buffer_stream[6], StreamingLineBuffer_18_out0_stream_prepad[3], StreamingLineBuffer_18_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_3," << StreamingLineBuffer_18_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_8," << StreamingLineBuffer_18_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_9;
    StreamingLineBuffer_18_pixel_9.run<255>(StreamingLineBuffer_18_buffer_stream[7], StreamingLineBuffer_18_out0_stream_prepad[2], StreamingLineBuffer_18_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_2," << StreamingLineBuffer_18_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_buffer_stream_9," << StreamingLineBuffer_18_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_10;
    StreamingLineBuffer_18_pixel_10.run<256>(StreamingLineBuffer_18_buffer_stream[8], StreamingLineBuffer_18_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_1," << StreamingLineBuffer_18_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pixel_11;
    StreamingLineBuffer_18_pixel_11.run<257>(StreamingLineBuffer_18_buffer_stream[9], StreamingLineBuffer_18_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_18_out0_stream_prepad_0," << StreamingLineBuffer_18_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    > StreamingLineBuffer_18_pad;
    StreamingLineBuffer_18_pad.run<258>(StreamingLineBuffer_18_out0_stream_prepad, StreamingLineBuffer_18_out0_stream);
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
    ap_int<8> StreamingConv_17_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_weights dim=2 complete
    ap_int<15> StreamingConv_17_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_17_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_17;
    StreamingConv_17.run<259>(StreamingLineBuffer_18_out0_stream, StreamingConv_17_weights, StreamingConv_17_biases, StreamingConv_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_0," << StreamingConv_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_17_out0_stream_1," << StreamingConv_17_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_17_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_17;
    StreamingSwish_17.run<260>(StreamingConv_17_out0_stream, StreamingSwish_17_lut, StreamingSwish_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_17_out0_stream_0," << StreamingSwish_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_17_out0_stream_1," << StreamingSwish_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_0.run<261>(StreamingSwish_17_out0_stream[0], StreamingLineBuffer_19_out0_stream_prepad[11], StreamingLineBuffer_19_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_11," << StreamingLineBuffer_19_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_0," << StreamingLineBuffer_19_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_1.run<262>(StreamingSwish_17_out0_stream[1], StreamingLineBuffer_19_out0_stream_prepad[10], StreamingLineBuffer_19_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_10," << StreamingLineBuffer_19_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_1," << StreamingLineBuffer_19_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_2.run<263>(StreamingLineBuffer_19_buffer_stream[0], StreamingLineBuffer_19_out0_stream_prepad[9], StreamingLineBuffer_19_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_9," << StreamingLineBuffer_19_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_2," << StreamingLineBuffer_19_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_3.run<264>(StreamingLineBuffer_19_buffer_stream[1], StreamingLineBuffer_19_out0_stream_prepad[8], StreamingLineBuffer_19_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_8," << StreamingLineBuffer_19_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_3," << StreamingLineBuffer_19_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_4.run<265>(StreamingLineBuffer_19_buffer_stream[2], StreamingLineBuffer_19_out0_stream_prepad[7], StreamingLineBuffer_19_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_7," << StreamingLineBuffer_19_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_4," << StreamingLineBuffer_19_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_5.run<266>(StreamingLineBuffer_19_buffer_stream[3], StreamingLineBuffer_19_out0_stream_prepad[6], StreamingLineBuffer_19_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_6," << StreamingLineBuffer_19_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_5," << StreamingLineBuffer_19_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_6.run<267>(StreamingLineBuffer_19_buffer_stream[4], StreamingLineBuffer_19_out0_stream_prepad[5], StreamingLineBuffer_19_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_5," << StreamingLineBuffer_19_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_6," << StreamingLineBuffer_19_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_7.run<268>(StreamingLineBuffer_19_buffer_stream[5], StreamingLineBuffer_19_out0_stream_prepad[4], StreamingLineBuffer_19_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_4," << StreamingLineBuffer_19_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_7," << StreamingLineBuffer_19_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_8.run<269>(StreamingLineBuffer_19_buffer_stream[6], StreamingLineBuffer_19_out0_stream_prepad[3], StreamingLineBuffer_19_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_3," << StreamingLineBuffer_19_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_8," << StreamingLineBuffer_19_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_9.run<270>(StreamingLineBuffer_19_buffer_stream[7], StreamingLineBuffer_19_out0_stream_prepad[2], StreamingLineBuffer_19_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_2," << StreamingLineBuffer_19_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_buffer_stream_9," << StreamingLineBuffer_19_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_10.run<271>(StreamingLineBuffer_19_buffer_stream[8], StreamingLineBuffer_19_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_1," << StreamingLineBuffer_19_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pixel_11.run<272>(StreamingLineBuffer_19_buffer_stream[9], StreamingLineBuffer_19_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_19_out0_stream_prepad_0," << StreamingLineBuffer_19_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
    StreamingLineBuffer_19_pad.run<273>(StreamingLineBuffer_19_out0_stream_prepad, StreamingLineBuffer_19_out0_stream);
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
    ap_int<8> StreamingConv_18_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_weights dim=2 complete
    ap_int<15> StreamingConv_18_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_18_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_18;
    StreamingConv_18.run<274>(StreamingLineBuffer_19_out0_stream, StreamingConv_18_weights, StreamingConv_18_biases, StreamingConv_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_0," << StreamingConv_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_18_out0_stream_1," << StreamingConv_18_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_18_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_18;
    StreamingSwish_18.run<275>(StreamingConv_18_out0_stream, StreamingSwish_18_lut, StreamingSwish_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_18_out0_stream_0," << StreamingSwish_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_18_out0_stream_1," << StreamingSwish_18_out0_stream[1].size() << std::endl;
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
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_4;
    StreamingAdd_4.run<276>(TensorDuplicator_10_out1_stream, StreamingSwish_18_out0_stream, StreamingAdd_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_0," << StreamingAdd_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_4_out0_stream_1," << StreamingAdd_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH_A
        64,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_6;
    StreamingConcat_6.run<277>(TensorDuplicator_9_out1_stream, StreamingAdd_4_out0_stream, StreamingConcat_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_6_out0_stream_0," << StreamingConcat_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_6_out0_stream_1," << StreamingConcat_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH_A
        128,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_7;
    StreamingConcat_7.run<278>(StreamingConcat_5_out0_stream, StreamingConcat_6_out0_stream, StreamingConcat_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_7_out0_stream_0," << StreamingConcat_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_7_out0_stream_1," << StreamingConcat_7_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_20_pixel_0;
    StreamingLineBuffer_20_pixel_0.run<279>(StreamingConcat_7_out0_stream[1], StreamingLineBuffer_20_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_1," << StreamingLineBuffer_20_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_20_pixel_1;
    StreamingLineBuffer_20_pixel_1.run<280>(StreamingConcat_7_out0_stream[0], StreamingLineBuffer_20_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_20_out0_stream_0," << StreamingLineBuffer_20_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_19_weights[8192][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_weights dim=2 complete
    ap_int<15> StreamingConv_19_biases[32][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_19_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        256,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_19;
    StreamingConv_19.run<281>(StreamingLineBuffer_20_out0_stream, StreamingConv_19_weights, StreamingConv_19_biases, StreamingConv_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_0," << StreamingConv_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_19_out0_stream_1," << StreamingConv_19_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_19_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_19;
    StreamingSwish_19.run<282>(StreamingConv_19_out0_stream, StreamingSwish_19_lut, StreamingSwish_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_19_out0_stream_0," << StreamingSwish_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_19_out0_stream_1," << StreamingSwish_19_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_11;
    TensorDuplicator_11.run<283>(StreamingSwish_19_out0_stream, TensorDuplicator_11_out0_stream, TensorDuplicator_11_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_11_out0_stream_0," << TensorDuplicator_11_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_11_out0_stream_1," << TensorDuplicator_11_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_11_out1_stream_0," << TensorDuplicator_11_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_11_out1_stream_1," << TensorDuplicator_11_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_0;
    BandwidthAdjustDecreaseStreams_0.run<284>(TensorDuplicator_11_out1_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_0_out0_stream_0," << BandwidthAdjustDecreaseStreams_0_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_21_pixel_0;
    StreamingLineBuffer_21_pixel_0.run<285>(TensorDuplicator_11_out0_stream[1], StreamingLineBuffer_21_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_1," << StreamingLineBuffer_21_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_21_pixel_1;
    StreamingLineBuffer_21_pixel_1.run<286>(TensorDuplicator_11_out0_stream[0], StreamingLineBuffer_21_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_21_out0_stream_0," << StreamingLineBuffer_21_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_20_weights[8192][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_weights dim=2 complete
    ap_int<14> StreamingConv_20_biases[256][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_20_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        128,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_20;
    StreamingConv_20.run<287>(StreamingLineBuffer_21_out0_stream, StreamingConv_20_weights, StreamingConv_20_biases, StreamingConv_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_20_out0_stream_0," << StreamingConv_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_20_out0_stream_1," << StreamingConv_20_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_20_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_20;
    StreamingSwish_20.run<288>(StreamingConv_20_out0_stream, StreamingSwish_20_lut, StreamingSwish_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_20_out0_stream_0," << StreamingSwish_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_20_out0_stream_1," << StreamingSwish_20_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_0;
    StreamingLineBuffer_22_pixel_0.run<289>(StreamingSwish_20_out0_stream[1], StreamingLineBuffer_22_out0_stream_prepad[14], StreamingLineBuffer_22_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_14," << StreamingLineBuffer_22_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_0," << StreamingLineBuffer_22_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_1;
    StreamingLineBuffer_22_pixel_1.run<290>(StreamingSwish_20_out0_stream[0], StreamingLineBuffer_22_out0_stream_prepad[13], StreamingLineBuffer_22_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_13," << StreamingLineBuffer_22_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_1," << StreamingLineBuffer_22_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_2;
    StreamingLineBuffer_22_pixel_2.run<291>(StreamingLineBuffer_22_buffer_stream[0], StreamingLineBuffer_22_out0_stream_prepad[12], StreamingLineBuffer_22_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_12," << StreamingLineBuffer_22_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_2," << StreamingLineBuffer_22_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_3;
    StreamingLineBuffer_22_pixel_3.run<292>(StreamingLineBuffer_22_buffer_stream[1], StreamingLineBuffer_22_out0_stream_prepad[11], StreamingLineBuffer_22_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_11," << StreamingLineBuffer_22_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_4," << StreamingLineBuffer_22_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_4;
    StreamingLineBuffer_22_pixel_4.run<293>(StreamingLineBuffer_22_buffer_stream[2], StreamingLineBuffer_22_out0_stream_prepad[10], StreamingLineBuffer_22_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_10," << StreamingLineBuffer_22_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_3," << StreamingLineBuffer_22_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_6;
    StreamingLineBuffer_22_pixel_6.run<295>(StreamingLineBuffer_22_buffer_stream[4], StreamingLineBuffer_22_out0_stream_prepad[8], StreamingLineBuffer_22_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_8," << StreamingLineBuffer_22_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_6," << StreamingLineBuffer_22_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_5;
    StreamingLineBuffer_22_pixel_5.run<294>(StreamingLineBuffer_22_buffer_stream[3], StreamingLineBuffer_22_out0_stream_prepad[9], StreamingLineBuffer_22_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_9," << StreamingLineBuffer_22_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_5," << StreamingLineBuffer_22_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_8;
    StreamingLineBuffer_22_pixel_8.run<297>(StreamingLineBuffer_22_buffer_stream[6], StreamingLineBuffer_22_out0_stream_prepad[6], StreamingLineBuffer_22_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_6," << StreamingLineBuffer_22_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_9," << StreamingLineBuffer_22_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_7;
    StreamingLineBuffer_22_pixel_7.run<296>(StreamingLineBuffer_22_buffer_stream[5], StreamingLineBuffer_22_out0_stream_prepad[7], StreamingLineBuffer_22_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_7," << StreamingLineBuffer_22_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_7," << StreamingLineBuffer_22_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_11;
    StreamingLineBuffer_22_pixel_11.run<300>(StreamingLineBuffer_22_buffer_stream[9], StreamingLineBuffer_22_out0_stream_prepad[3], StreamingLineBuffer_22_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_3," << StreamingLineBuffer_22_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_11," << StreamingLineBuffer_22_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_9;
    StreamingLineBuffer_22_pixel_9.run<298>(StreamingLineBuffer_22_buffer_stream[7], StreamingLineBuffer_22_out0_stream_prepad[5], StreamingLineBuffer_22_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_5," << StreamingLineBuffer_22_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_8," << StreamingLineBuffer_22_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_13;
    StreamingLineBuffer_22_pixel_13.run<302>(StreamingLineBuffer_22_buffer_stream[11], StreamingLineBuffer_22_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_1," << StreamingLineBuffer_22_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_10;
    StreamingLineBuffer_22_pixel_10.run<299>(StreamingLineBuffer_22_buffer_stream[8], StreamingLineBuffer_22_out0_stream_prepad[4], StreamingLineBuffer_22_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_4," << StreamingLineBuffer_22_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_10," << StreamingLineBuffer_22_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_12;
    StreamingLineBuffer_22_pixel_12.run<301>(StreamingLineBuffer_22_buffer_stream[10], StreamingLineBuffer_22_out0_stream_prepad[2], StreamingLineBuffer_22_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_2," << StreamingLineBuffer_22_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_buffer_stream_12," << StreamingLineBuffer_22_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pixel_14;
    StreamingLineBuffer_22_pixel_14.run<303>(StreamingLineBuffer_22_buffer_stream[12], StreamingLineBuffer_22_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_prepad_0," << StreamingLineBuffer_22_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_22_pad;
    StreamingLineBuffer_22_pad.run<304>(StreamingLineBuffer_22_out0_stream_prepad, StreamingLineBuffer_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_0," << StreamingLineBuffer_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_1," << StreamingLineBuffer_22_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_2," << StreamingLineBuffer_22_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_3," << StreamingLineBuffer_22_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_4," << StreamingLineBuffer_22_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_5," << StreamingLineBuffer_22_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_6," << StreamingLineBuffer_22_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_7," << StreamingLineBuffer_22_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_8," << StreamingLineBuffer_22_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_9," << StreamingLineBuffer_22_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_10," << StreamingLineBuffer_22_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_11," << StreamingLineBuffer_22_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_12," << StreamingLineBuffer_22_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_13," << StreamingLineBuffer_22_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_22_out0_stream_14," << StreamingLineBuffer_22_out0_stream[14].size() << std::endl;
    #endif
    ap_int<8> StreamingDepthwiseConv_1_weights[256][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_weights dim=2 complete
    ap_int<14> StreamingDepthwiseConv_1_biases[256][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_1_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        DequantQuantEqual<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        256,  // IN_CH
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_1;
    StreamingDepthwiseConv_1.run<305>(StreamingLineBuffer_22_out0_stream, StreamingDepthwiseConv_1_weights, StreamingDepthwiseConv_1_biases, StreamingDepthwiseConv_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_0," << StreamingDepthwiseConv_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_1_out0_stream_1," << StreamingDepthwiseConv_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_23_pixel_0;
    StreamingLineBuffer_23_pixel_0.run<306>(StreamingDepthwiseConv_1_out0_stream[1], StreamingLineBuffer_23_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_23_out0_stream_1," << StreamingLineBuffer_23_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_23_pixel_1;
    StreamingLineBuffer_23_pixel_1.run<307>(StreamingDepthwiseConv_1_out0_stream[0], StreamingLineBuffer_23_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_23_out0_stream_0," << StreamingLineBuffer_23_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_21_weights[32768][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_weights dim=2 complete
    ap_int<14> StreamingConv_21_biases[128][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_21_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        256,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_21;
    StreamingConv_21.run<308>(StreamingLineBuffer_23_out0_stream, StreamingConv_21_weights, StreamingConv_21_biases, StreamingConv_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_21_out0_stream_0," << StreamingConv_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_21_out0_stream_1," << StreamingConv_21_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_21_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_21;
    StreamingSwish_21.run<309>(StreamingConv_21_out0_stream, StreamingSwish_21_lut, StreamingSwish_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_21_out0_stream_0," << StreamingSwish_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_21_out0_stream_1," << StreamingSwish_21_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_8;
    BandwidthAdjustDecreaseChannels_8.run<310>(StreamingSwish_21_out0_stream, BandwidthAdjustDecreaseChannels_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_8_out0_stream_0," << BandwidthAdjustDecreaseChannels_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_8_out0_stream_1," << BandwidthAdjustDecreaseChannels_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        128,  // SPLIT
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_3;
    StreamingSplit_3.run<311>(BandwidthAdjustDecreaseChannels_8_out0_stream, StreamingSplit_3_out0_stream, StreamingSplit_3_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_3_out0_stream_0," << StreamingSplit_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_3_out0_stream_1," << StreamingSplit_3_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_3_out1_stream_0," << StreamingSplit_3_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_3_out1_stream_1," << StreamingSplit_3_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_12;
    TensorDuplicator_12.run<312>(StreamingSplit_3_out1_stream, TensorDuplicator_12_out0_stream, TensorDuplicator_12_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_12_out0_stream_0," << TensorDuplicator_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_12_out0_stream_1," << TensorDuplicator_12_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_12_out1_stream_0," << TensorDuplicator_12_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_12_out1_stream_1," << TensorDuplicator_12_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_13;
    TensorDuplicator_13.run<313>(TensorDuplicator_12_out0_stream, TensorDuplicator_13_out0_stream, TensorDuplicator_13_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_13_out0_stream_0," << TensorDuplicator_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_13_out0_stream_1," << TensorDuplicator_13_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_13_out1_stream_0," << TensorDuplicator_13_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_13_out1_stream_1," << TensorDuplicator_13_out1_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH_A
        128,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_8;
    StreamingConcat_8.run<314>(StreamingSplit_3_out0_stream, TensorDuplicator_13_out1_stream, StreamingConcat_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_8_out0_stream_0," << StreamingConcat_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_8_out0_stream_1," << StreamingConcat_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_0.run<315>(TensorDuplicator_13_out0_stream[0], StreamingLineBuffer_24_out0_stream_prepad[11], StreamingLineBuffer_24_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_11," << StreamingLineBuffer_24_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_0," << StreamingLineBuffer_24_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_1.run<316>(TensorDuplicator_13_out0_stream[1], StreamingLineBuffer_24_out0_stream_prepad[10], StreamingLineBuffer_24_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_10," << StreamingLineBuffer_24_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_1," << StreamingLineBuffer_24_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_2.run<317>(StreamingLineBuffer_24_buffer_stream[0], StreamingLineBuffer_24_out0_stream_prepad[9], StreamingLineBuffer_24_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_9," << StreamingLineBuffer_24_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_2," << StreamingLineBuffer_24_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_3.run<318>(StreamingLineBuffer_24_buffer_stream[1], StreamingLineBuffer_24_out0_stream_prepad[8], StreamingLineBuffer_24_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_8," << StreamingLineBuffer_24_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_3," << StreamingLineBuffer_24_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_4.run<319>(StreamingLineBuffer_24_buffer_stream[2], StreamingLineBuffer_24_out0_stream_prepad[7], StreamingLineBuffer_24_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_7," << StreamingLineBuffer_24_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_4," << StreamingLineBuffer_24_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_5.run<320>(StreamingLineBuffer_24_buffer_stream[3], StreamingLineBuffer_24_out0_stream_prepad[6], StreamingLineBuffer_24_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_6," << StreamingLineBuffer_24_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_5," << StreamingLineBuffer_24_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_6.run<321>(StreamingLineBuffer_24_buffer_stream[4], StreamingLineBuffer_24_out0_stream_prepad[5], StreamingLineBuffer_24_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_5," << StreamingLineBuffer_24_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_6," << StreamingLineBuffer_24_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_7.run<322>(StreamingLineBuffer_24_buffer_stream[5], StreamingLineBuffer_24_out0_stream_prepad[4], StreamingLineBuffer_24_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_4," << StreamingLineBuffer_24_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_7," << StreamingLineBuffer_24_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_8.run<323>(StreamingLineBuffer_24_buffer_stream[6], StreamingLineBuffer_24_out0_stream_prepad[3], StreamingLineBuffer_24_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_3," << StreamingLineBuffer_24_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_8," << StreamingLineBuffer_24_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_9.run<324>(StreamingLineBuffer_24_buffer_stream[7], StreamingLineBuffer_24_out0_stream_prepad[2], StreamingLineBuffer_24_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_2," << StreamingLineBuffer_24_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_buffer_stream_9," << StreamingLineBuffer_24_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_10.run<325>(StreamingLineBuffer_24_buffer_stream[8], StreamingLineBuffer_24_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_1," << StreamingLineBuffer_24_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    StreamingLineBuffer_24_pixel_11.run<326>(StreamingLineBuffer_24_buffer_stream[9], StreamingLineBuffer_24_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_24_out0_stream_prepad_0," << StreamingLineBuffer_24_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    StreamingLineBuffer_24_pad.run<327>(StreamingLineBuffer_24_out0_stream_prepad, StreamingLineBuffer_24_out0_stream);
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
    ap_int<8> StreamingConv_22_weights[16384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_weights dim=2 complete
    ap_int<14> StreamingConv_22_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_22_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<7, ap_int<28>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_22;
    StreamingConv_22.run<328>(StreamingLineBuffer_24_out0_stream, StreamingConv_22_weights, StreamingConv_22_biases, StreamingConv_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_22_out0_stream_0," << StreamingConv_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_22_out0_stream_1," << StreamingConv_22_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_22_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_22;
    StreamingSwish_22.run<329>(StreamingConv_22_out0_stream, StreamingSwish_22_lut, StreamingSwish_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_22_out0_stream_0," << StreamingSwish_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_22_out0_stream_1," << StreamingSwish_22_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_0;
    StreamingLineBuffer_25_pixel_0.run<330>(StreamingSwish_22_out0_stream[0], StreamingLineBuffer_25_out0_stream_prepad[11], StreamingLineBuffer_25_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_11," << StreamingLineBuffer_25_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_0," << StreamingLineBuffer_25_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_1;
    StreamingLineBuffer_25_pixel_1.run<331>(StreamingSwish_22_out0_stream[1], StreamingLineBuffer_25_out0_stream_prepad[10], StreamingLineBuffer_25_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_10," << StreamingLineBuffer_25_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_1," << StreamingLineBuffer_25_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_2;
    StreamingLineBuffer_25_pixel_2.run<332>(StreamingLineBuffer_25_buffer_stream[0], StreamingLineBuffer_25_out0_stream_prepad[9], StreamingLineBuffer_25_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_9," << StreamingLineBuffer_25_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_2," << StreamingLineBuffer_25_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_3;
    StreamingLineBuffer_25_pixel_3.run<333>(StreamingLineBuffer_25_buffer_stream[1], StreamingLineBuffer_25_out0_stream_prepad[8], StreamingLineBuffer_25_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_8," << StreamingLineBuffer_25_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_3," << StreamingLineBuffer_25_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_4;
    StreamingLineBuffer_25_pixel_4.run<334>(StreamingLineBuffer_25_buffer_stream[2], StreamingLineBuffer_25_out0_stream_prepad[7], StreamingLineBuffer_25_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_7," << StreamingLineBuffer_25_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_4," << StreamingLineBuffer_25_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_5;
    StreamingLineBuffer_25_pixel_5.run<335>(StreamingLineBuffer_25_buffer_stream[3], StreamingLineBuffer_25_out0_stream_prepad[6], StreamingLineBuffer_25_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_6," << StreamingLineBuffer_25_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_5," << StreamingLineBuffer_25_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_6;
    StreamingLineBuffer_25_pixel_6.run<336>(StreamingLineBuffer_25_buffer_stream[4], StreamingLineBuffer_25_out0_stream_prepad[5], StreamingLineBuffer_25_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_5," << StreamingLineBuffer_25_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_6," << StreamingLineBuffer_25_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_7;
    StreamingLineBuffer_25_pixel_7.run<337>(StreamingLineBuffer_25_buffer_stream[5], StreamingLineBuffer_25_out0_stream_prepad[4], StreamingLineBuffer_25_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_4," << StreamingLineBuffer_25_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_7," << StreamingLineBuffer_25_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_8;
    StreamingLineBuffer_25_pixel_8.run<338>(StreamingLineBuffer_25_buffer_stream[6], StreamingLineBuffer_25_out0_stream_prepad[3], StreamingLineBuffer_25_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_3," << StreamingLineBuffer_25_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_8," << StreamingLineBuffer_25_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_9;
    StreamingLineBuffer_25_pixel_9.run<339>(StreamingLineBuffer_25_buffer_stream[7], StreamingLineBuffer_25_out0_stream_prepad[2], StreamingLineBuffer_25_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_2," << StreamingLineBuffer_25_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_buffer_stream_9," << StreamingLineBuffer_25_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_10;
    StreamingLineBuffer_25_pixel_10.run<340>(StreamingLineBuffer_25_buffer_stream[8], StreamingLineBuffer_25_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_1," << StreamingLineBuffer_25_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_25_pixel_11;
    StreamingLineBuffer_25_pixel_11.run<341>(StreamingLineBuffer_25_buffer_stream[9], StreamingLineBuffer_25_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_prepad_0," << StreamingLineBuffer_25_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_25_pad;
    StreamingLineBuffer_25_pad.run<342>(StreamingLineBuffer_25_out0_stream_prepad, StreamingLineBuffer_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_0," << StreamingLineBuffer_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_1," << StreamingLineBuffer_25_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_2," << StreamingLineBuffer_25_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_3," << StreamingLineBuffer_25_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_4," << StreamingLineBuffer_25_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_5," << StreamingLineBuffer_25_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_6," << StreamingLineBuffer_25_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_7," << StreamingLineBuffer_25_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_8," << StreamingLineBuffer_25_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_9," << StreamingLineBuffer_25_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_10," << StreamingLineBuffer_25_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_25_out0_stream_11," << StreamingLineBuffer_25_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_23_weights[16384][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_weights dim=2 complete
    ap_int<14> StreamingConv_23_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_23_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<7, ap_int<28>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_23;
    StreamingConv_23.run<343>(StreamingLineBuffer_25_out0_stream, StreamingConv_23_weights, StreamingConv_23_biases, StreamingConv_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_23_out0_stream_0," << StreamingConv_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_23_out0_stream_1," << StreamingConv_23_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_23_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_23;
    StreamingSwish_23.run<344>(StreamingConv_23_out0_stream, StreamingSwish_23_lut, StreamingSwish_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_23_out0_stream_0," << StreamingSwish_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_23_out0_stream_1," << StreamingSwish_23_out0_stream[1].size() << std::endl;
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
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_5;
    StreamingAdd_5.run<345>(TensorDuplicator_12_out1_stream, StreamingSwish_23_out0_stream, StreamingAdd_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_0," << StreamingAdd_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_5_out0_stream_1," << StreamingAdd_5_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH_A
        128,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_9;
    StreamingConcat_9.run<346>(StreamingConcat_8_out0_stream, StreamingAdd_5_out0_stream, StreamingConcat_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_9_out0_stream_0," << StreamingConcat_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_9_out0_stream_1," << StreamingConcat_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
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
    > StreamingLineBuffer_26_pixel_0;
    StreamingLineBuffer_26_pixel_0.run<347>(StreamingConcat_9_out0_stream[1], StreamingLineBuffer_26_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_26_out0_stream_1," << StreamingLineBuffer_26_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
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
    > StreamingLineBuffer_26_pixel_1;
    StreamingLineBuffer_26_pixel_1.run<348>(StreamingConcat_9_out0_stream[0], StreamingLineBuffer_26_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_26_out0_stream_0," << StreamingLineBuffer_26_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_24_weights[49152][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_weights dim=2 complete
    ap_int<14> StreamingConv_24_biases[128][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_24_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        384,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_24;
    StreamingConv_24.run<349>(StreamingLineBuffer_26_out0_stream, StreamingConv_24_weights, StreamingConv_24_biases, StreamingConv_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_24_out0_stream_0," << StreamingConv_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_24_out0_stream_1," << StreamingConv_24_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_24_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_24;
    StreamingSwish_24.run<350>(StreamingConv_24_out0_stream, StreamingSwish_24_lut, StreamingSwish_24_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_24_out0_stream_0," << StreamingSwish_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_24_out0_stream_1," << StreamingSwish_24_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_9;
    BandwidthAdjustDecreaseChannels_9.run<351>(StreamingSwish_24_out0_stream, BandwidthAdjustDecreaseChannels_9_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_9_out0_stream_0," << BandwidthAdjustDecreaseChannels_9_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_9_out0_stream_1," << BandwidthAdjustDecreaseChannels_9_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_27_pixel_0;
    StreamingLineBuffer_27_pixel_0.run<352>(BandwidthAdjustDecreaseChannels_9_out0_stream[1], StreamingLineBuffer_27_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_1," << StreamingLineBuffer_27_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_27_pixel_1;
    StreamingLineBuffer_27_pixel_1.run<353>(BandwidthAdjustDecreaseChannels_9_out0_stream[0], StreamingLineBuffer_27_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_27_out0_stream_0," << StreamingLineBuffer_27_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_25_weights[32768][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_weights dim=2 complete
    ap_int<15> StreamingConv_25_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_25_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        256,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_25;
    StreamingConv_25.run<354>(StreamingLineBuffer_27_out0_stream, StreamingConv_25_weights, StreamingConv_25_biases, StreamingConv_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_25_out0_stream_0," << StreamingConv_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_25_out0_stream_1," << StreamingConv_25_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_25_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_25;
    StreamingSwish_25.run<355>(StreamingConv_25_out0_stream, StreamingSwish_25_lut, StreamingSwish_25_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_25_out0_stream_0," << StreamingSwish_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_25_out0_stream_1," << StreamingSwish_25_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_14;
    TensorDuplicator_14.run<356>(StreamingSwish_25_out0_stream, TensorDuplicator_14_out0_stream, TensorDuplicator_14_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_14_out0_stream_0," << TensorDuplicator_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_14_out0_stream_1," << TensorDuplicator_14_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_14_out1_stream_0," << TensorDuplicator_14_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_14_out1_stream_1," << TensorDuplicator_14_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_1;
    BandwidthAdjustDecreaseStreams_1.run<357>(TensorDuplicator_14_out0_stream, BandwidthAdjustDecreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_1_out0_stream_0," << BandwidthAdjustDecreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_2;
    BandwidthAdjustDecreaseStreams_2.run<358>(TensorDuplicator_14_out1_stream, BandwidthAdjustDecreaseStreams_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_2_out0_stream_0," << BandwidthAdjustDecreaseStreams_2_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_0;
    StreamingLineBuffer_28_pixel_0.run<359>(BandwidthAdjustDecreaseStreams_1_out0_stream[0], StreamingLineBuffer_28_out0_stream_prepad[24], StreamingLineBuffer_28_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_24," << StreamingLineBuffer_28_out0_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_0," << StreamingLineBuffer_28_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_1;
    StreamingLineBuffer_28_pixel_1.run<360>(StreamingLineBuffer_28_buffer_stream[0], StreamingLineBuffer_28_out0_stream_prepad[23], StreamingLineBuffer_28_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_23," << StreamingLineBuffer_28_out0_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_1," << StreamingLineBuffer_28_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_2;
    StreamingLineBuffer_28_pixel_2.run<361>(StreamingLineBuffer_28_buffer_stream[1], StreamingLineBuffer_28_out0_stream_prepad[22], StreamingLineBuffer_28_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_22," << StreamingLineBuffer_28_out0_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_2," << StreamingLineBuffer_28_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_3;
    StreamingLineBuffer_28_pixel_3.run<362>(StreamingLineBuffer_28_buffer_stream[2], StreamingLineBuffer_28_out0_stream_prepad[21], StreamingLineBuffer_28_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_21," << StreamingLineBuffer_28_out0_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_3," << StreamingLineBuffer_28_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_4;
    StreamingLineBuffer_28_pixel_4.run<363>(StreamingLineBuffer_28_buffer_stream[3], StreamingLineBuffer_28_out0_stream_prepad[20], StreamingLineBuffer_28_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_20," << StreamingLineBuffer_28_out0_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_4," << StreamingLineBuffer_28_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_5;
    StreamingLineBuffer_28_pixel_5.run<364>(StreamingLineBuffer_28_buffer_stream[4], StreamingLineBuffer_28_out0_stream_prepad[19], StreamingLineBuffer_28_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_19," << StreamingLineBuffer_28_out0_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_5," << StreamingLineBuffer_28_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_6;
    StreamingLineBuffer_28_pixel_6.run<365>(StreamingLineBuffer_28_buffer_stream[5], StreamingLineBuffer_28_out0_stream_prepad[18], StreamingLineBuffer_28_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_18," << StreamingLineBuffer_28_out0_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_6," << StreamingLineBuffer_28_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_7;
    StreamingLineBuffer_28_pixel_7.run<366>(StreamingLineBuffer_28_buffer_stream[6], StreamingLineBuffer_28_out0_stream_prepad[17], StreamingLineBuffer_28_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_17," << StreamingLineBuffer_28_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_7," << StreamingLineBuffer_28_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_8;
    StreamingLineBuffer_28_pixel_8.run<367>(StreamingLineBuffer_28_buffer_stream[7], StreamingLineBuffer_28_out0_stream_prepad[16], StreamingLineBuffer_28_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_16," << StreamingLineBuffer_28_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_8," << StreamingLineBuffer_28_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_9;
    StreamingLineBuffer_28_pixel_9.run<368>(StreamingLineBuffer_28_buffer_stream[8], StreamingLineBuffer_28_out0_stream_prepad[15], StreamingLineBuffer_28_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_15," << StreamingLineBuffer_28_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_9," << StreamingLineBuffer_28_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_10;
    StreamingLineBuffer_28_pixel_10.run<369>(StreamingLineBuffer_28_buffer_stream[9], StreamingLineBuffer_28_out0_stream_prepad[14], StreamingLineBuffer_28_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_14," << StreamingLineBuffer_28_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_10," << StreamingLineBuffer_28_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_11;
    StreamingLineBuffer_28_pixel_11.run<370>(StreamingLineBuffer_28_buffer_stream[10], StreamingLineBuffer_28_out0_stream_prepad[13], StreamingLineBuffer_28_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_13," << StreamingLineBuffer_28_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_11," << StreamingLineBuffer_28_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_12;
    StreamingLineBuffer_28_pixel_12.run<371>(StreamingLineBuffer_28_buffer_stream[11], StreamingLineBuffer_28_out0_stream_prepad[12], StreamingLineBuffer_28_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_12," << StreamingLineBuffer_28_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_12," << StreamingLineBuffer_28_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_13;
    StreamingLineBuffer_28_pixel_13.run<372>(StreamingLineBuffer_28_buffer_stream[12], StreamingLineBuffer_28_out0_stream_prepad[11], StreamingLineBuffer_28_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_11," << StreamingLineBuffer_28_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_13," << StreamingLineBuffer_28_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_14;
    StreamingLineBuffer_28_pixel_14.run<373>(StreamingLineBuffer_28_buffer_stream[13], StreamingLineBuffer_28_out0_stream_prepad[10], StreamingLineBuffer_28_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_10," << StreamingLineBuffer_28_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_14," << StreamingLineBuffer_28_buffer_stream[14].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_15;
    StreamingLineBuffer_28_pixel_15.run<374>(StreamingLineBuffer_28_buffer_stream[14], StreamingLineBuffer_28_out0_stream_prepad[9], StreamingLineBuffer_28_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_9," << StreamingLineBuffer_28_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_15," << StreamingLineBuffer_28_buffer_stream[15].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_16;
    StreamingLineBuffer_28_pixel_16.run<375>(StreamingLineBuffer_28_buffer_stream[15], StreamingLineBuffer_28_out0_stream_prepad[8], StreamingLineBuffer_28_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_8," << StreamingLineBuffer_28_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_16," << StreamingLineBuffer_28_buffer_stream[16].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_17;
    StreamingLineBuffer_28_pixel_17.run<376>(StreamingLineBuffer_28_buffer_stream[16], StreamingLineBuffer_28_out0_stream_prepad[7], StreamingLineBuffer_28_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_7," << StreamingLineBuffer_28_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_17," << StreamingLineBuffer_28_buffer_stream[17].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_18;
    StreamingLineBuffer_28_pixel_18.run<377>(StreamingLineBuffer_28_buffer_stream[17], StreamingLineBuffer_28_out0_stream_prepad[6], StreamingLineBuffer_28_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_6," << StreamingLineBuffer_28_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_18," << StreamingLineBuffer_28_buffer_stream[18].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_19;
    StreamingLineBuffer_28_pixel_19.run<378>(StreamingLineBuffer_28_buffer_stream[18], StreamingLineBuffer_28_out0_stream_prepad[5], StreamingLineBuffer_28_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_5," << StreamingLineBuffer_28_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_19," << StreamingLineBuffer_28_buffer_stream[19].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_20;
    StreamingLineBuffer_28_pixel_20.run<379>(StreamingLineBuffer_28_buffer_stream[19], StreamingLineBuffer_28_out0_stream_prepad[4], StreamingLineBuffer_28_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_4," << StreamingLineBuffer_28_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_20," << StreamingLineBuffer_28_buffer_stream[20].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_21;
    StreamingLineBuffer_28_pixel_21.run<380>(StreamingLineBuffer_28_buffer_stream[20], StreamingLineBuffer_28_out0_stream_prepad[3], StreamingLineBuffer_28_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_3," << StreamingLineBuffer_28_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_21," << StreamingLineBuffer_28_buffer_stream[21].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_22;
    StreamingLineBuffer_28_pixel_22.run<381>(StreamingLineBuffer_28_buffer_stream[21], StreamingLineBuffer_28_out0_stream_prepad[2], StreamingLineBuffer_28_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_2," << StreamingLineBuffer_28_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_22," << StreamingLineBuffer_28_buffer_stream[22].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_23;
    StreamingLineBuffer_28_pixel_23.run<382>(StreamingLineBuffer_28_buffer_stream[22], StreamingLineBuffer_28_out0_stream_prepad[1], StreamingLineBuffer_28_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_1," << StreamingLineBuffer_28_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_buffer_stream_23," << StreamingLineBuffer_28_buffer_stream[23].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_28_pixel_24;
    StreamingLineBuffer_28_pixel_24.run<383>(StreamingLineBuffer_28_buffer_stream[23], StreamingLineBuffer_28_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_prepad_0," << StreamingLineBuffer_28_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        -128  // PAD_VALUE
    > StreamingLineBuffer_28_pad;
    StreamingLineBuffer_28_pad.run<384>(StreamingLineBuffer_28_out0_stream_prepad, StreamingLineBuffer_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_0," << StreamingLineBuffer_28_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_1," << StreamingLineBuffer_28_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_2," << StreamingLineBuffer_28_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_3," << StreamingLineBuffer_28_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_4," << StreamingLineBuffer_28_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_5," << StreamingLineBuffer_28_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_6," << StreamingLineBuffer_28_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_7," << StreamingLineBuffer_28_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_8," << StreamingLineBuffer_28_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_9," << StreamingLineBuffer_28_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_10," << StreamingLineBuffer_28_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_11," << StreamingLineBuffer_28_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_12," << StreamingLineBuffer_28_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_13," << StreamingLineBuffer_28_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_14," << StreamingLineBuffer_28_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_15," << StreamingLineBuffer_28_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_16," << StreamingLineBuffer_28_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_17," << StreamingLineBuffer_28_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_18," << StreamingLineBuffer_28_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_19," << StreamingLineBuffer_28_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_20," << StreamingLineBuffer_28_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_21," << StreamingLineBuffer_28_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_22," << StreamingLineBuffer_28_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_23," << StreamingLineBuffer_28_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_28_out0_stream_24," << StreamingLineBuffer_28_out0_stream[24].size() << std::endl;
    #endif
    StreamingMaxPool <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingMaxPool_0;
    StreamingMaxPool_0.run<385>(StreamingLineBuffer_28_out0_stream, StreamingMaxPool_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMaxPool_0_out0_stream_0," << StreamingMaxPool_0_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_15;
    TensorDuplicator_15.run<386>(StreamingMaxPool_0_out0_stream, TensorDuplicator_15_out0_stream, TensorDuplicator_15_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_15_out0_stream_0," << TensorDuplicator_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_15_out1_stream_0," << TensorDuplicator_15_out1_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH_A
        128,  // IN_CH_B
        1,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_10;
    StreamingConcat_10.run<387>(BandwidthAdjustDecreaseStreams_2_out0_stream, TensorDuplicator_15_out1_stream, StreamingConcat_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_10_out0_stream_0," << StreamingConcat_10_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_0;
    StreamingLineBuffer_29_pixel_0.run<388>(TensorDuplicator_15_out0_stream[0], StreamingLineBuffer_29_out0_stream_prepad[24], StreamingLineBuffer_29_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_24," << StreamingLineBuffer_29_out0_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_0," << StreamingLineBuffer_29_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_1;
    StreamingLineBuffer_29_pixel_1.run<389>(StreamingLineBuffer_29_buffer_stream[0], StreamingLineBuffer_29_out0_stream_prepad[23], StreamingLineBuffer_29_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_23," << StreamingLineBuffer_29_out0_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_1," << StreamingLineBuffer_29_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_2;
    StreamingLineBuffer_29_pixel_2.run<390>(StreamingLineBuffer_29_buffer_stream[1], StreamingLineBuffer_29_out0_stream_prepad[22], StreamingLineBuffer_29_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_22," << StreamingLineBuffer_29_out0_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_2," << StreamingLineBuffer_29_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_3;
    StreamingLineBuffer_29_pixel_3.run<391>(StreamingLineBuffer_29_buffer_stream[2], StreamingLineBuffer_29_out0_stream_prepad[21], StreamingLineBuffer_29_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_21," << StreamingLineBuffer_29_out0_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_3," << StreamingLineBuffer_29_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_4;
    StreamingLineBuffer_29_pixel_4.run<392>(StreamingLineBuffer_29_buffer_stream[3], StreamingLineBuffer_29_out0_stream_prepad[20], StreamingLineBuffer_29_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_20," << StreamingLineBuffer_29_out0_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_4," << StreamingLineBuffer_29_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_5;
    StreamingLineBuffer_29_pixel_5.run<393>(StreamingLineBuffer_29_buffer_stream[4], StreamingLineBuffer_29_out0_stream_prepad[19], StreamingLineBuffer_29_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_19," << StreamingLineBuffer_29_out0_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_5," << StreamingLineBuffer_29_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_6;
    StreamingLineBuffer_29_pixel_6.run<394>(StreamingLineBuffer_29_buffer_stream[5], StreamingLineBuffer_29_out0_stream_prepad[18], StreamingLineBuffer_29_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_18," << StreamingLineBuffer_29_out0_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_6," << StreamingLineBuffer_29_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_7;
    StreamingLineBuffer_29_pixel_7.run<395>(StreamingLineBuffer_29_buffer_stream[6], StreamingLineBuffer_29_out0_stream_prepad[17], StreamingLineBuffer_29_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_17," << StreamingLineBuffer_29_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_7," << StreamingLineBuffer_29_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_8;
    StreamingLineBuffer_29_pixel_8.run<396>(StreamingLineBuffer_29_buffer_stream[7], StreamingLineBuffer_29_out0_stream_prepad[16], StreamingLineBuffer_29_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_16," << StreamingLineBuffer_29_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_8," << StreamingLineBuffer_29_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_9;
    StreamingLineBuffer_29_pixel_9.run<397>(StreamingLineBuffer_29_buffer_stream[8], StreamingLineBuffer_29_out0_stream_prepad[15], StreamingLineBuffer_29_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_15," << StreamingLineBuffer_29_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_9," << StreamingLineBuffer_29_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_10;
    StreamingLineBuffer_29_pixel_10.run<398>(StreamingLineBuffer_29_buffer_stream[9], StreamingLineBuffer_29_out0_stream_prepad[14], StreamingLineBuffer_29_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_14," << StreamingLineBuffer_29_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_10," << StreamingLineBuffer_29_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_11;
    StreamingLineBuffer_29_pixel_11.run<399>(StreamingLineBuffer_29_buffer_stream[10], StreamingLineBuffer_29_out0_stream_prepad[13], StreamingLineBuffer_29_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_13," << StreamingLineBuffer_29_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_11," << StreamingLineBuffer_29_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_12;
    StreamingLineBuffer_29_pixel_12.run<400>(StreamingLineBuffer_29_buffer_stream[11], StreamingLineBuffer_29_out0_stream_prepad[12], StreamingLineBuffer_29_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_12," << StreamingLineBuffer_29_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_12," << StreamingLineBuffer_29_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_13;
    StreamingLineBuffer_29_pixel_13.run<401>(StreamingLineBuffer_29_buffer_stream[12], StreamingLineBuffer_29_out0_stream_prepad[11], StreamingLineBuffer_29_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_11," << StreamingLineBuffer_29_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_13," << StreamingLineBuffer_29_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_14;
    StreamingLineBuffer_29_pixel_14.run<402>(StreamingLineBuffer_29_buffer_stream[13], StreamingLineBuffer_29_out0_stream_prepad[10], StreamingLineBuffer_29_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_10," << StreamingLineBuffer_29_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_14," << StreamingLineBuffer_29_buffer_stream[14].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_15;
    StreamingLineBuffer_29_pixel_15.run<403>(StreamingLineBuffer_29_buffer_stream[14], StreamingLineBuffer_29_out0_stream_prepad[9], StreamingLineBuffer_29_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_9," << StreamingLineBuffer_29_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_15," << StreamingLineBuffer_29_buffer_stream[15].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_16;
    StreamingLineBuffer_29_pixel_16.run<404>(StreamingLineBuffer_29_buffer_stream[15], StreamingLineBuffer_29_out0_stream_prepad[8], StreamingLineBuffer_29_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_8," << StreamingLineBuffer_29_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_16," << StreamingLineBuffer_29_buffer_stream[16].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_17;
    StreamingLineBuffer_29_pixel_17.run<405>(StreamingLineBuffer_29_buffer_stream[16], StreamingLineBuffer_29_out0_stream_prepad[7], StreamingLineBuffer_29_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_7," << StreamingLineBuffer_29_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_17," << StreamingLineBuffer_29_buffer_stream[17].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_18;
    StreamingLineBuffer_29_pixel_18.run<406>(StreamingLineBuffer_29_buffer_stream[17], StreamingLineBuffer_29_out0_stream_prepad[6], StreamingLineBuffer_29_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_6," << StreamingLineBuffer_29_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_18," << StreamingLineBuffer_29_buffer_stream[18].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_19;
    StreamingLineBuffer_29_pixel_19.run<407>(StreamingLineBuffer_29_buffer_stream[18], StreamingLineBuffer_29_out0_stream_prepad[5], StreamingLineBuffer_29_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_5," << StreamingLineBuffer_29_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_19," << StreamingLineBuffer_29_buffer_stream[19].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_20;
    StreamingLineBuffer_29_pixel_20.run<408>(StreamingLineBuffer_29_buffer_stream[19], StreamingLineBuffer_29_out0_stream_prepad[4], StreamingLineBuffer_29_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_4," << StreamingLineBuffer_29_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_20," << StreamingLineBuffer_29_buffer_stream[20].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_21;
    StreamingLineBuffer_29_pixel_21.run<409>(StreamingLineBuffer_29_buffer_stream[20], StreamingLineBuffer_29_out0_stream_prepad[3], StreamingLineBuffer_29_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_3," << StreamingLineBuffer_29_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_21," << StreamingLineBuffer_29_buffer_stream[21].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_22;
    StreamingLineBuffer_29_pixel_22.run<410>(StreamingLineBuffer_29_buffer_stream[21], StreamingLineBuffer_29_out0_stream_prepad[2], StreamingLineBuffer_29_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_2," << StreamingLineBuffer_29_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_22," << StreamingLineBuffer_29_buffer_stream[22].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_23;
    StreamingLineBuffer_29_pixel_23.run<411>(StreamingLineBuffer_29_buffer_stream[22], StreamingLineBuffer_29_out0_stream_prepad[1], StreamingLineBuffer_29_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_1," << StreamingLineBuffer_29_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_buffer_stream_23," << StreamingLineBuffer_29_buffer_stream[23].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_29_pixel_24;
    StreamingLineBuffer_29_pixel_24.run<412>(StreamingLineBuffer_29_buffer_stream[23], StreamingLineBuffer_29_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_prepad_0," << StreamingLineBuffer_29_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        -128  // PAD_VALUE
    > StreamingLineBuffer_29_pad;
    StreamingLineBuffer_29_pad.run<413>(StreamingLineBuffer_29_out0_stream_prepad, StreamingLineBuffer_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_0," << StreamingLineBuffer_29_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_1," << StreamingLineBuffer_29_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_2," << StreamingLineBuffer_29_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_3," << StreamingLineBuffer_29_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_4," << StreamingLineBuffer_29_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_5," << StreamingLineBuffer_29_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_6," << StreamingLineBuffer_29_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_7," << StreamingLineBuffer_29_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_8," << StreamingLineBuffer_29_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_9," << StreamingLineBuffer_29_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_10," << StreamingLineBuffer_29_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_11," << StreamingLineBuffer_29_out0_stream[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_12," << StreamingLineBuffer_29_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_13," << StreamingLineBuffer_29_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_14," << StreamingLineBuffer_29_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_15," << StreamingLineBuffer_29_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_16," << StreamingLineBuffer_29_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_17," << StreamingLineBuffer_29_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_18," << StreamingLineBuffer_29_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_19," << StreamingLineBuffer_29_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_20," << StreamingLineBuffer_29_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_21," << StreamingLineBuffer_29_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_22," << StreamingLineBuffer_29_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_23," << StreamingLineBuffer_29_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_29_out0_stream_24," << StreamingLineBuffer_29_out0_stream[24].size() << std::endl;
    #endif
    StreamingMaxPool <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingMaxPool_1;
    StreamingMaxPool_1.run<414>(StreamingLineBuffer_29_out0_stream, StreamingMaxPool_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMaxPool_1_out0_stream_0," << StreamingMaxPool_1_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_16;
    TensorDuplicator_16.run<415>(StreamingMaxPool_1_out0_stream, TensorDuplicator_16_out0_stream, TensorDuplicator_16_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_16_out0_stream_0," << TensorDuplicator_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_16_out1_stream_0," << TensorDuplicator_16_out1_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_0;
    StreamingLineBuffer_30_pixel_0.run<416>(TensorDuplicator_16_out0_stream[0], StreamingLineBuffer_30_out0_stream_prepad[24], StreamingLineBuffer_30_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_24," << StreamingLineBuffer_30_out0_stream_prepad[24].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_0," << StreamingLineBuffer_30_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_1;
    StreamingLineBuffer_30_pixel_1.run<417>(StreamingLineBuffer_30_buffer_stream[0], StreamingLineBuffer_30_out0_stream_prepad[23], StreamingLineBuffer_30_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_23," << StreamingLineBuffer_30_out0_stream_prepad[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_1," << StreamingLineBuffer_30_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_2;
    StreamingLineBuffer_30_pixel_2.run<418>(StreamingLineBuffer_30_buffer_stream[1], StreamingLineBuffer_30_out0_stream_prepad[22], StreamingLineBuffer_30_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_22," << StreamingLineBuffer_30_out0_stream_prepad[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_2," << StreamingLineBuffer_30_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_3;
    StreamingLineBuffer_30_pixel_3.run<419>(StreamingLineBuffer_30_buffer_stream[2], StreamingLineBuffer_30_out0_stream_prepad[21], StreamingLineBuffer_30_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_21," << StreamingLineBuffer_30_out0_stream_prepad[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_3," << StreamingLineBuffer_30_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        4,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_4;
    StreamingLineBuffer_30_pixel_4.run<420>(StreamingLineBuffer_30_buffer_stream[3], StreamingLineBuffer_30_out0_stream_prepad[20], StreamingLineBuffer_30_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_20," << StreamingLineBuffer_30_out0_stream_prepad[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_4," << StreamingLineBuffer_30_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_5;
    StreamingLineBuffer_30_pixel_5.run<421>(StreamingLineBuffer_30_buffer_stream[4], StreamingLineBuffer_30_out0_stream_prepad[19], StreamingLineBuffer_30_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_19," << StreamingLineBuffer_30_out0_stream_prepad[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_5," << StreamingLineBuffer_30_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_6;
    StreamingLineBuffer_30_pixel_6.run<422>(StreamingLineBuffer_30_buffer_stream[5], StreamingLineBuffer_30_out0_stream_prepad[18], StreamingLineBuffer_30_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_18," << StreamingLineBuffer_30_out0_stream_prepad[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_6," << StreamingLineBuffer_30_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_7;
    StreamingLineBuffer_30_pixel_7.run<423>(StreamingLineBuffer_30_buffer_stream[6], StreamingLineBuffer_30_out0_stream_prepad[17], StreamingLineBuffer_30_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_17," << StreamingLineBuffer_30_out0_stream_prepad[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_7," << StreamingLineBuffer_30_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_8;
    StreamingLineBuffer_30_pixel_8.run<424>(StreamingLineBuffer_30_buffer_stream[7], StreamingLineBuffer_30_out0_stream_prepad[16], StreamingLineBuffer_30_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_16," << StreamingLineBuffer_30_out0_stream_prepad[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_8," << StreamingLineBuffer_30_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        3,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_9;
    StreamingLineBuffer_30_pixel_9.run<425>(StreamingLineBuffer_30_buffer_stream[8], StreamingLineBuffer_30_out0_stream_prepad[15], StreamingLineBuffer_30_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_15," << StreamingLineBuffer_30_out0_stream_prepad[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_9," << StreamingLineBuffer_30_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_10;
    StreamingLineBuffer_30_pixel_10.run<426>(StreamingLineBuffer_30_buffer_stream[9], StreamingLineBuffer_30_out0_stream_prepad[14], StreamingLineBuffer_30_buffer_stream[10]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_14," << StreamingLineBuffer_30_out0_stream_prepad[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_10," << StreamingLineBuffer_30_buffer_stream[10].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_11;
    StreamingLineBuffer_30_pixel_11.run<427>(StreamingLineBuffer_30_buffer_stream[10], StreamingLineBuffer_30_out0_stream_prepad[13], StreamingLineBuffer_30_buffer_stream[11]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_13," << StreamingLineBuffer_30_out0_stream_prepad[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_11," << StreamingLineBuffer_30_buffer_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_12;
    StreamingLineBuffer_30_pixel_12.run<428>(StreamingLineBuffer_30_buffer_stream[11], StreamingLineBuffer_30_out0_stream_prepad[12], StreamingLineBuffer_30_buffer_stream[12]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_12," << StreamingLineBuffer_30_out0_stream_prepad[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_12," << StreamingLineBuffer_30_buffer_stream[12].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_13;
    StreamingLineBuffer_30_pixel_13.run<429>(StreamingLineBuffer_30_buffer_stream[12], StreamingLineBuffer_30_out0_stream_prepad[11], StreamingLineBuffer_30_buffer_stream[13]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_11," << StreamingLineBuffer_30_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_13," << StreamingLineBuffer_30_buffer_stream[13].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_14;
    StreamingLineBuffer_30_pixel_14.run<430>(StreamingLineBuffer_30_buffer_stream[13], StreamingLineBuffer_30_out0_stream_prepad[10], StreamingLineBuffer_30_buffer_stream[14]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_10," << StreamingLineBuffer_30_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_14," << StreamingLineBuffer_30_buffer_stream[14].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_15;
    StreamingLineBuffer_30_pixel_15.run<431>(StreamingLineBuffer_30_buffer_stream[14], StreamingLineBuffer_30_out0_stream_prepad[9], StreamingLineBuffer_30_buffer_stream[15]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_9," << StreamingLineBuffer_30_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_15," << StreamingLineBuffer_30_buffer_stream[15].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_16;
    StreamingLineBuffer_30_pixel_16.run<432>(StreamingLineBuffer_30_buffer_stream[15], StreamingLineBuffer_30_out0_stream_prepad[8], StreamingLineBuffer_30_buffer_stream[16]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_8," << StreamingLineBuffer_30_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_16," << StreamingLineBuffer_30_buffer_stream[16].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_17;
    StreamingLineBuffer_30_pixel_17.run<433>(StreamingLineBuffer_30_buffer_stream[16], StreamingLineBuffer_30_out0_stream_prepad[7], StreamingLineBuffer_30_buffer_stream[17]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_7," << StreamingLineBuffer_30_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_17," << StreamingLineBuffer_30_buffer_stream[17].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_18;
    StreamingLineBuffer_30_pixel_18.run<434>(StreamingLineBuffer_30_buffer_stream[17], StreamingLineBuffer_30_out0_stream_prepad[6], StreamingLineBuffer_30_buffer_stream[18]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_6," << StreamingLineBuffer_30_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_18," << StreamingLineBuffer_30_buffer_stream[18].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_19;
    StreamingLineBuffer_30_pixel_19.run<435>(StreamingLineBuffer_30_buffer_stream[18], StreamingLineBuffer_30_out0_stream_prepad[5], StreamingLineBuffer_30_buffer_stream[19]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_5," << StreamingLineBuffer_30_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_19," << StreamingLineBuffer_30_buffer_stream[19].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_20;
    StreamingLineBuffer_30_pixel_20.run<436>(StreamingLineBuffer_30_buffer_stream[19], StreamingLineBuffer_30_out0_stream_prepad[4], StreamingLineBuffer_30_buffer_stream[20]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_4," << StreamingLineBuffer_30_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_20," << StreamingLineBuffer_30_buffer_stream[20].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_21;
    StreamingLineBuffer_30_pixel_21.run<437>(StreamingLineBuffer_30_buffer_stream[20], StreamingLineBuffer_30_out0_stream_prepad[3], StreamingLineBuffer_30_buffer_stream[21]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_3," << StreamingLineBuffer_30_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_21," << StreamingLineBuffer_30_buffer_stream[21].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_22;
    StreamingLineBuffer_30_pixel_22.run<438>(StreamingLineBuffer_30_buffer_stream[21], StreamingLineBuffer_30_out0_stream_prepad[2], StreamingLineBuffer_30_buffer_stream[22]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_2," << StreamingLineBuffer_30_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_22," << StreamingLineBuffer_30_buffer_stream[22].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_23;
    StreamingLineBuffer_30_pixel_23.run<439>(StreamingLineBuffer_30_buffer_stream[22], StreamingLineBuffer_30_out0_stream_prepad[1], StreamingLineBuffer_30_buffer_stream[23]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_1," << StreamingLineBuffer_30_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_buffer_stream_23," << StreamingLineBuffer_30_buffer_stream[23].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_24;
    StreamingLineBuffer_30_pixel_24.run<440>(StreamingLineBuffer_30_buffer_stream[23], StreamingLineBuffer_30_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_prepad_0," << StreamingLineBuffer_30_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        2,  // PAD_T
        2,  // PAD_L
        2,  // PAD_B
        2,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        -128  // PAD_VALUE
    > StreamingLineBuffer_30_pad;
    StreamingLineBuffer_30_pad.run<441>(StreamingLineBuffer_30_out0_stream_prepad, StreamingLineBuffer_30_out0_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_12," << StreamingLineBuffer_30_out0_stream[12].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_13," << StreamingLineBuffer_30_out0_stream[13].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_14," << StreamingLineBuffer_30_out0_stream[14].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_15," << StreamingLineBuffer_30_out0_stream[15].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_16," << StreamingLineBuffer_30_out0_stream[16].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_17," << StreamingLineBuffer_30_out0_stream[17].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_18," << StreamingLineBuffer_30_out0_stream[18].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_19," << StreamingLineBuffer_30_out0_stream[19].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_20," << StreamingLineBuffer_30_out0_stream[20].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_21," << StreamingLineBuffer_30_out0_stream[21].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_22," << StreamingLineBuffer_30_out0_stream[22].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_23," << StreamingLineBuffer_30_out0_stream[23].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_30_out0_stream_24," << StreamingLineBuffer_30_out0_stream[24].size() << std::endl;
    #endif
    StreamingMaxPool <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        5,  // FH
        5,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingMaxPool_2;
    StreamingMaxPool_2.run<442>(StreamingLineBuffer_30_out0_stream, StreamingMaxPool_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingMaxPool_2_out0_stream_0," << StreamingMaxPool_2_out0_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH_A
        128,  // IN_CH_B
        1,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_11;
    StreamingConcat_11.run<443>(TensorDuplicator_16_out1_stream, StreamingMaxPool_2_out0_stream, StreamingConcat_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_11_out0_stream_0," << StreamingConcat_11_out0_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH_A
        256,  // IN_CH_B
        1,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_12;
    StreamingConcat_12.run<444>(StreamingConcat_10_out0_stream, StreamingConcat_11_out0_stream, StreamingConcat_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_12_out0_stream_0," << StreamingConcat_12_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        512,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_1;
    BandwidthAdjustIncreaseStreams_1.run<445>(StreamingConcat_12_out0_stream, BandwidthAdjustIncreaseStreams_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_1_out0_stream_0," << BandwidthAdjustIncreaseStreams_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_1_out0_stream_1," << BandwidthAdjustIncreaseStreams_1_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        512,  // IN_CH
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
    > StreamingLineBuffer_31_pixel_0;
    StreamingLineBuffer_31_pixel_0.run<446>(BandwidthAdjustIncreaseStreams_1_out0_stream[1], StreamingLineBuffer_31_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_31_out0_stream_1," << StreamingLineBuffer_31_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        512,  // IN_CH
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
    > StreamingLineBuffer_31_pixel_1;
    StreamingLineBuffer_31_pixel_1.run<447>(BandwidthAdjustIncreaseStreams_1_out0_stream[0], StreamingLineBuffer_31_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_31_out0_stream_0," << StreamingLineBuffer_31_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_26_weights[32768][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_weights dim=2 complete
    ap_int<17> StreamingConv_26_biases[64][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_26_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<17>, 4>,  // TBiasWord
        ap_int<17>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        512,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_26;
    StreamingConv_26.run<448>(StreamingLineBuffer_31_out0_stream, StreamingConv_26_weights, StreamingConv_26_biases, StreamingConv_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_26_out0_stream_0," << StreamingConv_26_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_26_out0_stream_1," << StreamingConv_26_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_26_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_26;
    StreamingSwish_26.run<449>(StreamingConv_26_out0_stream, StreamingSwish_26_lut, StreamingSwish_26_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_26_out0_stream_0," << StreamingSwish_26_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_26_out0_stream_1," << StreamingSwish_26_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_10;
    BandwidthAdjustDecreaseChannels_10.run<450>(StreamingSwish_26_out0_stream, BandwidthAdjustDecreaseChannels_10_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_10_out0_stream_0," << BandwidthAdjustDecreaseChannels_10_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_10_out0_stream_1," << BandwidthAdjustDecreaseChannels_10_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
        2  // CH_PAR
    > StreamingLineBuffer_32_pixel_0;
    StreamingLineBuffer_32_pixel_0.run<451>(BandwidthAdjustDecreaseChannels_10_out0_stream[1], StreamingLineBuffer_32_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_32_out0_stream_1," << StreamingLineBuffer_32_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
        2  // CH_PAR
    > StreamingLineBuffer_32_pixel_1;
    StreamingLineBuffer_32_pixel_1.run<452>(BandwidthAdjustDecreaseChannels_10_out0_stream[0], StreamingLineBuffer_32_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_32_out0_stream_0," << StreamingLineBuffer_32_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_27_weights[32768][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_weights dim=2 complete
    ap_int<12> StreamingConv_27_biases[256][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_27_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 1>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<6, ap_int<26>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        256,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_27;
    StreamingConv_27.run<453>(StreamingLineBuffer_32_out0_stream, StreamingConv_27_weights, StreamingConv_27_biases, StreamingConv_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_27_out0_stream_0," << StreamingConv_27_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_27_out0_stream_1," << StreamingConv_27_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_27_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_27;
    StreamingSwish_27.run<454>(StreamingConv_27_out0_stream, StreamingSwish_27_lut, StreamingSwish_27_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_27_out0_stream_0," << StreamingSwish_27_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_27_out0_stream_1," << StreamingSwish_27_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        128,  // SPLIT
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_4;
    StreamingSplit_4.run<455>(StreamingSwish_27_out0_stream, StreamingSplit_4_out0_stream, StreamingSplit_4_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_4_out0_stream_0," << StreamingSplit_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_4_out0_stream_1," << StreamingSplit_4_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_4_out1_stream_0," << StreamingSplit_4_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_4_out1_stream_1," << StreamingSplit_4_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_17;
    TensorDuplicator_17.run<456>(StreamingSplit_4_out1_stream, TensorDuplicator_17_out0_stream, TensorDuplicator_17_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_17_out0_stream_0," << TensorDuplicator_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_17_out0_stream_1," << TensorDuplicator_17_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_17_out1_stream_0," << TensorDuplicator_17_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_17_out1_stream_1," << TensorDuplicator_17_out1_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_33_pixel_0;
    StreamingLineBuffer_33_pixel_0.run<457>(TensorDuplicator_17_out0_stream[1], StreamingLineBuffer_33_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_1," << StreamingLineBuffer_33_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_33_pixel_1;
    StreamingLineBuffer_33_pixel_1.run<458>(TensorDuplicator_17_out0_stream[0], StreamingLineBuffer_33_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_33_out0_stream_0," << StreamingLineBuffer_33_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_28_weights[32768][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_weights dim=2 complete
    ap_int<15> StreamingConv_28_biases[256][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_28_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        128,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_28;
    StreamingConv_28.run<459>(StreamingLineBuffer_33_out0_stream, StreamingConv_28_weights, StreamingConv_28_biases, StreamingConv_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_28_out0_stream_0," << StreamingConv_28_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_28_out0_stream_1," << StreamingConv_28_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_3;
    BandwidthAdjustDecreaseStreams_3.run<460>(StreamingConv_28_out0_stream, BandwidthAdjustDecreaseStreams_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_3_out0_stream_0," << BandwidthAdjustDecreaseStreams_3_out0_stream[0].size() << std::endl;
    #endif
    SplitReshapeQKV <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TSplitWord
        ap_int<8>,  // TSplit
        DequantQuantEqual<ap_int<8>>,  // SplitQuantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CHANNELS
        1
    > splitreshapeqkv;
    splitreshapeqkv.run<461>( BandwidthAdjustDecreaseStreams_3_out0_stream, stream_q, stream_k, stream_v);
    #ifndef __SYNTHESIS__
    std::cout << "stream_q_0," << stream_q[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_q_1," << stream_q[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_k_0," << stream_k[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_k_1," << stream_k[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_0," << stream_v[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_1," << stream_v[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TSplitWord
        64,  // DIM_V
        400,  // DIM_SEQ_VP
        1,  // DIM_HEADS
        1,  // W_PAR
        1  // REDUCE_PAR
    > tensorduplicator_head0;
    tensorduplicator_head0.run<462>(&stream_v[0], &stream_v_out[0], &stream_v_copy[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_out_0," << stream_v_out[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_copy_0," << stream_v_copy[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TSplitWord
        64,  // DIM_V
        400,  // DIM_SEQ_VP
        1,  // DIM_HEADS
        1,  // W_PAR
        1  // REDUCE_PAR
    > tensorduplicator_head1;
    tensorduplicator_head1.run<463>(&stream_v[1], &stream_v_out[1], &stream_v_copy[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_out_1," << stream_v_out[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_copy_1," << stream_v_copy[1].size() << std::endl;
    #endif
    QKMatMul <
        std::array<ap_int<8>, 1>,  // TQInputWord
        ap_int<8>,  // TQInput
        std::array<ap_int<8>, 1>,  // TKInputWord
        ap_int<8>,  // TKInput
        std::array<ap_int<8>, 1>,  // TQKWord
        ap_int<8>,  // TQK
        ap_int<21>,  // TAccQK
        DequantQuantPo2<7, ap_int<21>, ap_int<8>>,  // QKQuantizer
        1,  // DIM_HEADS
        400,  // DIM_Q
        400,  // DIM_K
        32,  // DIM_SEQ_QK
        1  // REDUCE_PAR
    > matmulqk_head0;
    matmulqk_head0.run<464>(&stream_q[0], &stream_k[0], &stream_qk[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_qk_0," << stream_qk[0].size() << std::endl;
    #endif
    QKMatMul <
        std::array<ap_int<8>, 1>,  // TQInputWord
        ap_int<8>,  // TQInput
        std::array<ap_int<8>, 1>,  // TKInputWord
        ap_int<8>,  // TKInput
        std::array<ap_int<8>, 1>,  // TQKWord
        ap_int<8>,  // TQK
        ap_int<21>,  // TAccQK
        DequantQuantPo2<7, ap_int<21>, ap_int<8>>,  // QKQuantizer
        1,  // DIM_HEADS
        400,  // DIM_Q
        400,  // DIM_K
        32,  // DIM_SEQ_QK
        1  // REDUCE_PAR
    > matmulqk_head1;
    matmulqk_head1.run<465>(&stream_q[1], &stream_k[1], &stream_qk[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_qk_1," << stream_qk[1].size() << std::endl;
    #endif
    const ap_int<8> CONST_SCALE = 91;
    StreamingConstMul <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        ap_int<8>,  // TConst
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<16>,  // TMul
        DequantQuantEqual<ap_int<16>>,  // MulActivation
        DequantQuantPo2<7, ap_int<16>, ap_int<8>>,  // MulQuantizer
        400,  // MUL_HEIGHT
        400,  // MUL_WIDTH
        1,  // MUL_CHANNELS
        1,  // MUL_W_PAR
        1  // MUL_CH_PAR
    > constmulqk_head0;
    constmulqk_head0.run<466>(&stream_qk[0], CONST_SCALE, &stream_qkscaled[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_qkscaled_0," << stream_qkscaled[0].size() << std::endl;
    #endif
    StreamingConstMul <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        ap_int<8>,  // TConst
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<16>,  // TMul
        DequantQuantEqual<ap_int<16>>,  // MulActivation
        DequantQuantPo2<7, ap_int<16>, ap_int<8>>,  // MulQuantizer
        400,  // MUL_HEIGHT
        400,  // MUL_WIDTH
        1,  // MUL_CHANNELS
        1,  // MUL_W_PAR
        1  // MUL_CH_PAR
    > constmulqk_head1;
    constmulqk_head1.run<467>(&stream_qk[1], CONST_SCALE, &stream_qkscaled[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_qkscaled_1," << stream_qkscaled[1].size() << std::endl;
    #endif
    TransposeRowCol <
        std::array<ap_int<8>, 1>,  // TInputWord
        64,  // DIM_V
        400,  // DIM_SEQ_VP
        1  // DIM_HEADS
    > transposev_head0;
    transposev_head0.run<470>(&stream_v_copy[0], &stream_v_transposed[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_transposed_0," << stream_v_transposed[0].size() << std::endl;
    #endif
    TransposeRowCol <
        std::array<ap_int<8>, 1>,  // TInputWord
        64,  // DIM_V
        400,  // DIM_SEQ_VP
        1  // DIM_HEADS
    > transposev_head1;
    transposev_head1.run<471>(&stream_v_copy[1], &stream_v_transposed[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_v_transposed_1," << stream_v_transposed[1].size() << std::endl;
    #endif
    ReshapeV <
        std::array<ap_int<8>, 1>,  // TSplitWord
        ap_int<8>,  // TSplit
        std::array<ap_int<8>, 1>,  // TReshapeWord
        ap_int<8>,  // TReshape
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        128,  // OUT_CH
        1  // REDUCE_PAR
    > reshapev;
    reshapev.run<474>(stream_v_out, StreamingYoloAttention_0_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingYoloAttention_0_out1_stream_0," << StreamingYoloAttention_0_out1_stream[0].size() << std::endl;
    #endif
    ap_uint<12> LUTmem[256] = {4095, 3615, 3190, 2815, 2484, 2192, 1935, 1707, 1507, 1330, 1174, 1036, 914, 807, 712, 628, 554, 489, 432, 381, 336, 297, 262, 231, 204, 180, 159, 140, 124, 109, 96, 85, 75, 66, 58, 52, 46, 40, 35, 31, 28, 24, 21, 19, 17, 15, 13, 12, 10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    StreamingSoftmax <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_uint<12>,  // TLut
        ap_uint<21>,  // TAcc
        ap_uint<32>,  // TDiv
        DequantQuantPo2<13, ap_uint<32>, ap_int<8>>,  // Quantizer
        256,  // LUT_SIZE
        400,  // HEIGHT
        400,  // WIDTH
        1,  // W_PAR
        1  // CH_PAR
    > softmax_head0;
    softmax_head0.run<468>(&stream_qkscaled[0], LUTmem, &stream_p[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_p_0," << stream_p[0].size() << std::endl;
    #endif
    StreamingSoftmax <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_uint<12>,  // TLut
        ap_uint<21>,  // TAcc
        ap_uint<32>,  // TDiv
        DequantQuantPo2<13, ap_uint<32>, ap_int<8>>,  // Quantizer
        256,  // LUT_SIZE
        400,  // HEIGHT
        400,  // WIDTH
        1,  // W_PAR
        1  // CH_PAR
    > softmax_head1;
    softmax_head1.run<469>(&stream_qkscaled[1], LUTmem, &stream_p[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_p_1," << stream_p[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_3;
    BandwidthAdjustIncreaseStreams_3.run<476>(StreamingYoloAttention_0_out1_stream, BandwidthAdjustIncreaseStreams_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_3_out0_stream_0," << BandwidthAdjustIncreaseStreams_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_3_out0_stream_1," << BandwidthAdjustIncreaseStreams_3_out0_stream[1].size() << std::endl;
    #endif
    VPMatMul <
        std::array<ap_int<8>, 1>,  // TVInputWord
        ap_int<8>,  // TVInput
        std::array<ap_int<8>, 1>,  // TPInputWord
        ap_int<8>,  // TPInput
        std::array<ap_int<8>, 1>,  // TVPOutputWord
        ap_int<8>,  // TVPOutput
        ap_int<25>,  // TAccVP
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // VPQuantizer
        1,  // DIM_HEADS
        64,  // DIM_V
        400,  // DIM_P
        400,  // DIM_SEQ_VP
        1  // REDUCE_PAR
    > matmulvp_head0;
    matmulvp_head0.run<472>(&stream_v_transposed[0], &stream_p[0], &stream_y[0]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_y_0," << stream_y[0].size() << std::endl;
    #endif
    VPMatMul <
        std::array<ap_int<8>, 1>,  // TVInputWord
        ap_int<8>,  // TVInput
        std::array<ap_int<8>, 1>,  // TPInputWord
        ap_int<8>,  // TPInput
        std::array<ap_int<8>, 1>,  // TVPOutputWord
        ap_int<8>,  // TVPOutput
        ap_int<25>,  // TAccVP
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // VPQuantizer
        1,  // DIM_HEADS
        64,  // DIM_V
        400,  // DIM_P
        400,  // DIM_SEQ_VP
        1  // REDUCE_PAR
    > matmulvp_head1;
    matmulvp_head1.run<473>(&stream_v_transposed[1], &stream_p[1], &stream_y[1]);
    #ifndef __SYNTHESIS__
    std::cout << "stream_y_1," << stream_y[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_0;
    StreamingLineBuffer_34_pixel_0.run<477>(BandwidthAdjustIncreaseStreams_3_out0_stream[0], StreamingLineBuffer_34_out0_stream_prepad[11], StreamingLineBuffer_34_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_11," << StreamingLineBuffer_34_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_0," << StreamingLineBuffer_34_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_1;
    StreamingLineBuffer_34_pixel_1.run<478>(BandwidthAdjustIncreaseStreams_3_out0_stream[1], StreamingLineBuffer_34_out0_stream_prepad[10], StreamingLineBuffer_34_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_10," << StreamingLineBuffer_34_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_1," << StreamingLineBuffer_34_buffer_stream[1].size() << std::endl;
    #endif
    ReshapeV <
        std::array<ap_int<8>, 1>,  // TVPOutputWord
        ap_int<8>,  // TVPOutput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        128,  // OUT_CH
        1  // REDUCE_PAR
    > reshapey;
    reshapey.run<475>(stream_y, StreamingYoloAttention_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingYoloAttention_0_out0_stream_0," << StreamingYoloAttention_0_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_2;
    StreamingLineBuffer_34_pixel_2.run<479>(StreamingLineBuffer_34_buffer_stream[0], StreamingLineBuffer_34_out0_stream_prepad[9], StreamingLineBuffer_34_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_9," << StreamingLineBuffer_34_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_2," << StreamingLineBuffer_34_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_3;
    StreamingLineBuffer_34_pixel_3.run<480>(StreamingLineBuffer_34_buffer_stream[1], StreamingLineBuffer_34_out0_stream_prepad[8], StreamingLineBuffer_34_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_8," << StreamingLineBuffer_34_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_3," << StreamingLineBuffer_34_buffer_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_2;
    BandwidthAdjustIncreaseStreams_2.run<475>(StreamingYoloAttention_0_out0_stream, BandwidthAdjustIncreaseStreams_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_2_out0_stream_0," << BandwidthAdjustIncreaseStreams_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseStreams_2_out0_stream_1," << BandwidthAdjustIncreaseStreams_2_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_4;
    StreamingLineBuffer_34_pixel_4.run<481>(StreamingLineBuffer_34_buffer_stream[2], StreamingLineBuffer_34_out0_stream_prepad[7], StreamingLineBuffer_34_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_7," << StreamingLineBuffer_34_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_4," << StreamingLineBuffer_34_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_5;
    StreamingLineBuffer_34_pixel_5.run<482>(StreamingLineBuffer_34_buffer_stream[3], StreamingLineBuffer_34_out0_stream_prepad[6], StreamingLineBuffer_34_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_6," << StreamingLineBuffer_34_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_5," << StreamingLineBuffer_34_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_6;
    StreamingLineBuffer_34_pixel_6.run<483>(StreamingLineBuffer_34_buffer_stream[4], StreamingLineBuffer_34_out0_stream_prepad[5], StreamingLineBuffer_34_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_5," << StreamingLineBuffer_34_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_6," << StreamingLineBuffer_34_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_7;
    StreamingLineBuffer_34_pixel_7.run<484>(StreamingLineBuffer_34_buffer_stream[5], StreamingLineBuffer_34_out0_stream_prepad[4], StreamingLineBuffer_34_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_4," << StreamingLineBuffer_34_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_7," << StreamingLineBuffer_34_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_8;
    StreamingLineBuffer_34_pixel_8.run<485>(StreamingLineBuffer_34_buffer_stream[6], StreamingLineBuffer_34_out0_stream_prepad[3], StreamingLineBuffer_34_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_3," << StreamingLineBuffer_34_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_8," << StreamingLineBuffer_34_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_9;
    StreamingLineBuffer_34_pixel_9.run<486>(StreamingLineBuffer_34_buffer_stream[7], StreamingLineBuffer_34_out0_stream_prepad[2], StreamingLineBuffer_34_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_2," << StreamingLineBuffer_34_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_buffer_stream_9," << StreamingLineBuffer_34_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_10;
    StreamingLineBuffer_34_pixel_10.run<487>(StreamingLineBuffer_34_buffer_stream[8], StreamingLineBuffer_34_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_1," << StreamingLineBuffer_34_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_34_pixel_11;
    StreamingLineBuffer_34_pixel_11.run<488>(StreamingLineBuffer_34_buffer_stream[9], StreamingLineBuffer_34_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_prepad_0," << StreamingLineBuffer_34_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_34_pad;
    StreamingLineBuffer_34_pad.run<489>(StreamingLineBuffer_34_out0_stream_prepad, StreamingLineBuffer_34_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_0," << StreamingLineBuffer_34_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_1," << StreamingLineBuffer_34_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_2," << StreamingLineBuffer_34_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_3," << StreamingLineBuffer_34_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_4," << StreamingLineBuffer_34_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_5," << StreamingLineBuffer_34_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_6," << StreamingLineBuffer_34_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_7," << StreamingLineBuffer_34_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_8," << StreamingLineBuffer_34_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_9," << StreamingLineBuffer_34_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_10," << StreamingLineBuffer_34_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_34_out0_stream_11," << StreamingLineBuffer_34_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingDepthwiseConv_2_weights[128][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_weights dim=2 complete
    ap_int<13> StreamingDepthwiseConv_2_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_2_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasStruct
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        DequantQuantEqual<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_2;
    StreamingDepthwiseConv_2.run<490>(StreamingLineBuffer_34_out0_stream, StreamingDepthwiseConv_2_weights, StreamingDepthwiseConv_2_biases, StreamingDepthwiseConv_2_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_0," << StreamingDepthwiseConv_2_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_2_out0_stream_1," << StreamingDepthwiseConv_2_out0_stream[1].size() << std::endl;
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
        DequantQuantPo2<-1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_6;
    StreamingAdd_6.run<491>(BandwidthAdjustIncreaseStreams_2_out0_stream, StreamingDepthwiseConv_2_out0_stream, StreamingAdd_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_0," << StreamingAdd_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_6_out0_stream_1," << StreamingAdd_6_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_35_pixel_0;
    StreamingLineBuffer_35_pixel_0.run<492>(StreamingAdd_6_out0_stream[1], StreamingLineBuffer_35_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_35_out0_stream_1," << StreamingLineBuffer_35_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_35_pixel_1;
    StreamingLineBuffer_35_pixel_1.run<493>(StreamingAdd_6_out0_stream[0], StreamingLineBuffer_35_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_35_out0_stream_0," << StreamingLineBuffer_35_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_29_weights[16384][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_weights dim=2 complete
    ap_int<12> StreamingConv_29_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_29_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 1>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        128,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_29;
    StreamingConv_29.run<494>(StreamingLineBuffer_35_out0_stream, StreamingConv_29_weights, StreamingConv_29_biases, StreamingConv_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_29_out0_stream_0," << StreamingConv_29_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_29_out0_stream_1," << StreamingConv_29_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<10>,  // TAcc
        DequantQuantEqual<ap_int<10>>,  // Activation
        DequantQuantPo2<1, ap_int<10>, ap_int<8>>,  // Quantizer
        DequantQuantPo2<-1, ap_int<8>, ap_int<10>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_7;
    StreamingAdd_7.run<495>(TensorDuplicator_17_out1_stream, StreamingConv_29_out0_stream, StreamingAdd_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_0," << StreamingAdd_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_7_out0_stream_1," << StreamingAdd_7_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_18;
    TensorDuplicator_18.run<496>(StreamingAdd_7_out0_stream, TensorDuplicator_18_out0_stream, TensorDuplicator_18_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_18_out0_stream_0," << TensorDuplicator_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_18_out0_stream_1," << TensorDuplicator_18_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_18_out1_stream_0," << TensorDuplicator_18_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_18_out1_stream_1," << TensorDuplicator_18_out1_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_36_pixel_0;
    StreamingLineBuffer_36_pixel_0.run<497>(TensorDuplicator_18_out0_stream[1], StreamingLineBuffer_36_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_1," << StreamingLineBuffer_36_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
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
    > StreamingLineBuffer_36_pixel_1;
    StreamingLineBuffer_36_pixel_1.run<498>(TensorDuplicator_18_out0_stream[0], StreamingLineBuffer_36_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_36_out0_stream_0," << StreamingLineBuffer_36_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_30_weights[32768][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_weights dim=2 complete
    ap_int<14> StreamingConv_30_biases[256][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_30_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        128,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_30;
    StreamingConv_30.run<499>(StreamingLineBuffer_36_out0_stream, StreamingConv_30_weights, StreamingConv_30_biases, StreamingConv_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_30_out0_stream_0," << StreamingConv_30_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_30_out0_stream_1," << StreamingConv_30_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_28_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_28;
    StreamingSwish_28.run<500>(StreamingConv_30_out0_stream, StreamingSwish_28_lut, StreamingSwish_28_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_28_out0_stream_0," << StreamingSwish_28_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_28_out0_stream_1," << StreamingSwish_28_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_37_pixel_0;
    StreamingLineBuffer_37_pixel_0.run<501>(StreamingSwish_28_out0_stream[1], StreamingLineBuffer_37_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_37_out0_stream_1," << StreamingLineBuffer_37_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
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
    > StreamingLineBuffer_37_pixel_1;
    StreamingLineBuffer_37_pixel_1.run<502>(StreamingSwish_28_out0_stream[0], StreamingLineBuffer_37_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_37_out0_stream_0," << StreamingLineBuffer_37_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_31_weights[32768][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_weights dim=2 complete
    ap_int<13> StreamingConv_31_biases[128][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_31_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 1>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        256,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_31;
    StreamingConv_31.run<503>(StreamingLineBuffer_37_out0_stream, StreamingConv_31_weights, StreamingConv_31_biases, StreamingConv_31_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_31_out0_stream_0," << StreamingConv_31_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_31_out0_stream_1," << StreamingConv_31_out0_stream[1].size() << std::endl;
    #endif
    StreamingAdd <
        std::array<ap_int<8>, 1>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 1>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<10>,  // TAcc
        DequantQuantEqual<ap_int<10>>,  // Activation
        DequantQuantPo2<1, ap_int<10>, ap_int<8>>,  // Quantizer
        DequantQuantPo2<-1, ap_int<8>, ap_int<10>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH
        2,  // W_PAR
        1  // CH_PAR
    > StreamingAdd_8;
    StreamingAdd_8.run<504>(TensorDuplicator_18_out1_stream, StreamingConv_31_out0_stream, StreamingAdd_8_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_8_out0_stream_0," << StreamingAdd_8_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingAdd_8_out0_stream_1," << StreamingAdd_8_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        128,  // IN_CH_A
        128,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_13;
    StreamingConcat_13.run<505>(StreamingSplit_4_out0_stream, StreamingAdd_8_out0_stream, StreamingConcat_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_13_out0_stream_0," << StreamingConcat_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_13_out0_stream_1," << StreamingConcat_13_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_4;
    BandwidthAdjustDecreaseStreams_4.run<506>(StreamingConcat_13_out0_stream, BandwidthAdjustDecreaseStreams_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_4_out0_stream_0," << BandwidthAdjustDecreaseStreams_4_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_32_weights[16384][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_weights dim=2 complete
    ap_int<14> StreamingConv_32_biases[64][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_32_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 4>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        256,  // OUT_CH
        256,  // IN_CH
        20,  // OUT_HEIGHT
        20,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_32;
    StreamingConv_32.run<507>(BandwidthAdjustDecreaseStreams_4_out0_stream, StreamingConv_32_weights, StreamingConv_32_biases, StreamingConv_32_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_32_out0_stream_0," << StreamingConv_32_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_29_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_29;
    StreamingSwish_29.run<508>(StreamingConv_32_out0_stream, StreamingSwish_29_lut, StreamingSwish_29_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_29_out0_stream_0," << StreamingSwish_29_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_19;
    TensorDuplicator_19.run<509>(StreamingSwish_29_out0_stream, TensorDuplicator_19_out0_stream, TensorDuplicator_19_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_19_out0_stream_0," << TensorDuplicator_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_19_out1_stream_0," << TensorDuplicator_19_out1_stream[0].size() << std::endl;
    #endif
    StreamingUpsample <
        std::array<ap_int<8>, 4>,  // TInputWord
        std::array<ap_int<8>, 4>,  // TOutputWord
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        20,  // IN_HEIGHT
        20,  // IN_WIDTH
        256,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        2,  // SCALE_FACTOR
        4,  // CH_PAR
        1,  // IN_W_PAR
        2  // OUT_W_PAR
    > StreamingUpsample_0;
    StreamingUpsample_0.run<510>(TensorDuplicator_19_out0_stream, StreamingUpsample_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingUpsample_0_out0_stream_0," << StreamingUpsample_0_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingUpsample_0_out0_stream_1," << StreamingUpsample_0_out0_stream[1].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        25600,  // ITER
        16,  // DATA_PER_WORD
        20,  // HEIGHT
        20,  // WIDTH
        256,  // CH
        1,  // IN_W_PAR
        4  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.run<511>(TensorDuplicator_19_out1_stream, global_out_2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_5;
    BandwidthAdjustDecreaseStreams_5.run<512>(StreamingUpsample_0_out0_stream, BandwidthAdjustDecreaseStreams_5_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_5_out0_stream_0," << BandwidthAdjustDecreaseStreams_5_out0_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        256,  // IN_CH_A
        128,  // IN_CH_B
        1,  // W_PAR
        4  // CH_PAR
    > StreamingConcat_14;
    StreamingConcat_14.run<513>(BandwidthAdjustDecreaseStreams_5_out0_stream, BandwidthAdjustDecreaseStreams_0_out0_stream, StreamingConcat_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_14_out0_stream_0," << StreamingConcat_14_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_33_weights[6144][8][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_weights dim=2 complete
    ap_int<14> StreamingConv_33_biases[64][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_33_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        384,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_33;
    StreamingConv_33.run<514>(StreamingConcat_14_out0_stream, StreamingConv_33_weights, StreamingConv_33_biases, StreamingConv_33_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_33_out0_stream_0," << StreamingConv_33_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_30_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_30;
    StreamingSwish_30.run<515>(StreamingConv_33_out0_stream, StreamingSwish_30_lut, StreamingSwish_30_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_30_out0_stream_0," << StreamingSwish_30_out0_stream[0].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        64,  // SPLIT
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSplit_5;
    StreamingSplit_5.run<516>(StreamingSwish_30_out0_stream, StreamingSplit_5_out0_stream, StreamingSplit_5_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_5_out0_stream_0," << StreamingSplit_5_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_5_out1_stream_0," << StreamingSplit_5_out1_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 2>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_20;
    TensorDuplicator_20.run<517>(StreamingSplit_5_out1_stream, TensorDuplicator_20_out0_stream, TensorDuplicator_20_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_20_out0_stream_0," << TensorDuplicator_20_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_20_out1_stream_0," << TensorDuplicator_20_out1_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH_A
        64,  // IN_CH_B
        1,  // W_PAR
        2  // CH_PAR
    > StreamingConcat_15;
    StreamingConcat_15.run<518>(StreamingSplit_5_out0_stream, TensorDuplicator_20_out1_stream, StreamingConcat_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_15_out0_stream_0," << StreamingConcat_15_out0_stream[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_11;
    BandwidthAdjustDecreaseChannels_11.run<519>(TensorDuplicator_20_out0_stream, BandwidthAdjustDecreaseChannels_11_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_11_out0_stream_0," << BandwidthAdjustDecreaseChannels_11_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_0;
    StreamingLineBuffer_38_pixel_0.run<520>(BandwidthAdjustDecreaseChannels_11_out0_stream[0], StreamingLineBuffer_38_out0_stream_prepad[8], StreamingLineBuffer_38_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_8," << StreamingLineBuffer_38_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_0," << StreamingLineBuffer_38_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_1;
    StreamingLineBuffer_38_pixel_1.run<521>(StreamingLineBuffer_38_buffer_stream[0], StreamingLineBuffer_38_out0_stream_prepad[7], StreamingLineBuffer_38_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_7," << StreamingLineBuffer_38_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_1," << StreamingLineBuffer_38_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_2;
    StreamingLineBuffer_38_pixel_2.run<522>(StreamingLineBuffer_38_buffer_stream[1], StreamingLineBuffer_38_out0_stream_prepad[6], StreamingLineBuffer_38_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_6," << StreamingLineBuffer_38_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_2," << StreamingLineBuffer_38_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_3;
    StreamingLineBuffer_38_pixel_3.run<523>(StreamingLineBuffer_38_buffer_stream[2], StreamingLineBuffer_38_out0_stream_prepad[5], StreamingLineBuffer_38_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_5," << StreamingLineBuffer_38_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_3," << StreamingLineBuffer_38_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_4;
    StreamingLineBuffer_38_pixel_4.run<524>(StreamingLineBuffer_38_buffer_stream[3], StreamingLineBuffer_38_out0_stream_prepad[4], StreamingLineBuffer_38_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_4," << StreamingLineBuffer_38_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_4," << StreamingLineBuffer_38_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_5;
    StreamingLineBuffer_38_pixel_5.run<525>(StreamingLineBuffer_38_buffer_stream[4], StreamingLineBuffer_38_out0_stream_prepad[3], StreamingLineBuffer_38_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_3," << StreamingLineBuffer_38_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_5," << StreamingLineBuffer_38_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_6;
    StreamingLineBuffer_38_pixel_6.run<526>(StreamingLineBuffer_38_buffer_stream[5], StreamingLineBuffer_38_out0_stream_prepad[2], StreamingLineBuffer_38_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_2," << StreamingLineBuffer_38_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_6," << StreamingLineBuffer_38_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_7;
    StreamingLineBuffer_38_pixel_7.run<527>(StreamingLineBuffer_38_buffer_stream[6], StreamingLineBuffer_38_out0_stream_prepad[1], StreamingLineBuffer_38_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_1," << StreamingLineBuffer_38_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_buffer_stream_7," << StreamingLineBuffer_38_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_8;
    StreamingLineBuffer_38_pixel_8.run<528>(StreamingLineBuffer_38_buffer_stream[7], StreamingLineBuffer_38_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_prepad_0," << StreamingLineBuffer_38_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_38_pad;
    StreamingLineBuffer_38_pad.run<529>(StreamingLineBuffer_38_out0_stream_prepad, StreamingLineBuffer_38_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_0," << StreamingLineBuffer_38_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_1," << StreamingLineBuffer_38_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_2," << StreamingLineBuffer_38_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_3," << StreamingLineBuffer_38_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_4," << StreamingLineBuffer_38_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_5," << StreamingLineBuffer_38_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_6," << StreamingLineBuffer_38_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_7," << StreamingLineBuffer_38_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_38_out0_stream_8," << StreamingLineBuffer_38_out0_stream[8].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_34_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_weights dim=2 complete
    ap_int<15> StreamingConv_34_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_34_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_34;
    StreamingConv_34.run<530>(StreamingLineBuffer_38_out0_stream, StreamingConv_34_weights, StreamingConv_34_biases, StreamingConv_34_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_34_out0_stream_0," << StreamingConv_34_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_31_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_31;
    StreamingSwish_31.run<531>(StreamingConv_34_out0_stream, StreamingSwish_31_lut, StreamingSwish_31_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_31_out0_stream_0," << StreamingSwish_31_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_0;
    StreamingLineBuffer_39_pixel_0.run<532>(StreamingSwish_31_out0_stream[0], StreamingLineBuffer_39_out0_stream_prepad[8], StreamingLineBuffer_39_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_8," << StreamingLineBuffer_39_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_0," << StreamingLineBuffer_39_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_1;
    StreamingLineBuffer_39_pixel_1.run<533>(StreamingLineBuffer_39_buffer_stream[0], StreamingLineBuffer_39_out0_stream_prepad[7], StreamingLineBuffer_39_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_7," << StreamingLineBuffer_39_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_1," << StreamingLineBuffer_39_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_2;
    StreamingLineBuffer_39_pixel_2.run<534>(StreamingLineBuffer_39_buffer_stream[1], StreamingLineBuffer_39_out0_stream_prepad[6], StreamingLineBuffer_39_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_6," << StreamingLineBuffer_39_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_2," << StreamingLineBuffer_39_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_3;
    StreamingLineBuffer_39_pixel_3.run<535>(StreamingLineBuffer_39_buffer_stream[2], StreamingLineBuffer_39_out0_stream_prepad[5], StreamingLineBuffer_39_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_5," << StreamingLineBuffer_39_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_3," << StreamingLineBuffer_39_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_4;
    StreamingLineBuffer_39_pixel_4.run<536>(StreamingLineBuffer_39_buffer_stream[3], StreamingLineBuffer_39_out0_stream_prepad[4], StreamingLineBuffer_39_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_4," << StreamingLineBuffer_39_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_4," << StreamingLineBuffer_39_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_5;
    StreamingLineBuffer_39_pixel_5.run<537>(StreamingLineBuffer_39_buffer_stream[4], StreamingLineBuffer_39_out0_stream_prepad[3], StreamingLineBuffer_39_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_3," << StreamingLineBuffer_39_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_5," << StreamingLineBuffer_39_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_6;
    StreamingLineBuffer_39_pixel_6.run<538>(StreamingLineBuffer_39_buffer_stream[5], StreamingLineBuffer_39_out0_stream_prepad[2], StreamingLineBuffer_39_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_2," << StreamingLineBuffer_39_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_6," << StreamingLineBuffer_39_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_7;
    StreamingLineBuffer_39_pixel_7.run<539>(StreamingLineBuffer_39_buffer_stream[6], StreamingLineBuffer_39_out0_stream_prepad[1], StreamingLineBuffer_39_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_1," << StreamingLineBuffer_39_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_buffer_stream_7," << StreamingLineBuffer_39_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_8;
    StreamingLineBuffer_39_pixel_8.run<540>(StreamingLineBuffer_39_buffer_stream[7], StreamingLineBuffer_39_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_39_out0_stream_prepad_0," << StreamingLineBuffer_39_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_39_pad;
    StreamingLineBuffer_39_pad.run<541>(StreamingLineBuffer_39_out0_stream_prepad, StreamingLineBuffer_39_out0_stream);
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
    ap_int<8> StreamingConv_35_weights[2048][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_weights dim=2 complete
    ap_int<14> StreamingConv_35_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_35_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
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
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_35;
    StreamingConv_35.run<542>(StreamingLineBuffer_39_out0_stream, StreamingConv_35_weights, StreamingConv_35_biases, StreamingConv_35_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_35_out0_stream_0," << StreamingConv_35_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_32_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_32;
    StreamingSwish_32.run<543>(StreamingConv_35_out0_stream, StreamingSwish_32_lut, StreamingSwish_32_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_32_out0_stream_0," << StreamingSwish_32_out0_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH_A
        64,  // IN_CH_B
        1,  // W_PAR
        2  // CH_PAR
    > StreamingConcat_16;
    StreamingConcat_16.run<544>(StreamingConcat_15_out0_stream, StreamingSwish_32_out0_stream, StreamingConcat_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_16_out0_stream_0," << StreamingConcat_16_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_36_weights[6144][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_36_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_36_weights dim=2 complete
    ap_int<14> StreamingConv_36_biases[64][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_36_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_36_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        192,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_36;
    StreamingConv_36.run<545>(StreamingConcat_16_out0_stream, StreamingConv_36_weights, StreamingConv_36_biases, StreamingConv_36_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_36_out0_stream_0," << StreamingConv_36_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_33_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_33;
    StreamingSwish_33.run<546>(StreamingConv_36_out0_stream, StreamingSwish_33_lut, StreamingSwish_33_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_33_out0_stream_0," << StreamingSwish_33_out0_stream[0].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 2>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_21;
    TensorDuplicator_21.run<547>(StreamingSwish_33_out0_stream, TensorDuplicator_21_out0_stream, TensorDuplicator_21_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_21_out0_stream_0," << TensorDuplicator_21_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_21_out1_stream_0," << TensorDuplicator_21_out1_stream[0].size() << std::endl;
    #endif
    StreamingUpsample <
        std::array<ap_int<8>, 2>,  // TInputWord
        std::array<ap_int<8>, 2>,  // TOutputWord
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        2,  // SCALE_FACTOR
        2,  // CH_PAR
        1,  // IN_W_PAR
        2  // OUT_W_PAR
    > StreamingUpsample_1;
    StreamingUpsample_1.run<548>(TensorDuplicator_21_out0_stream, StreamingUpsample_1_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingUpsample_1_out0_stream_0," << StreamingUpsample_1_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingUpsample_1_out0_stream_1," << StreamingUpsample_1_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_3;
    BandwidthAdjustIncreaseChannels_3.run<549>(StreamingUpsample_1_out0_stream, BandwidthAdjustIncreaseChannels_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_0," << BandwidthAdjustIncreaseChannels_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustIncreaseChannels_3_out0_stream_1," << BandwidthAdjustIncreaseChannels_3_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        128,  // IN_CH_A
        64,  // IN_CH_B
        2,  // W_PAR
        4  // CH_PAR
    > StreamingConcat_17;
    StreamingConcat_17.run<550>(BandwidthAdjustIncreaseChannels_3_out0_stream, TensorDuplicator_6_out1_stream, StreamingConcat_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_17_out0_stream_0," << StreamingConcat_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_17_out0_stream_1," << StreamingConcat_17_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_12;
    BandwidthAdjustDecreaseChannels_12.run<551>(StreamingConcat_17_out0_stream, BandwidthAdjustDecreaseChannels_12_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_12_out0_stream_0," << BandwidthAdjustDecreaseChannels_12_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_12_out0_stream_1," << BandwidthAdjustDecreaseChannels_12_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_40_pixel_0;
    StreamingLineBuffer_40_pixel_0.run<552>(BandwidthAdjustDecreaseChannels_12_out0_stream[1], StreamingLineBuffer_40_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_1," << StreamingLineBuffer_40_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_40_pixel_1;
    StreamingLineBuffer_40_pixel_1.run<553>(BandwidthAdjustDecreaseChannels_12_out0_stream[0], StreamingLineBuffer_40_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_40_out0_stream_0," << StreamingLineBuffer_40_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_37_weights[3072][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_37_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_37_weights dim=2 complete
    ap_int<14> StreamingConv_37_biases[16][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_37_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_37_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 4>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<7, ap_int<25>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        192,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_37;
    StreamingConv_37.run<554>(StreamingLineBuffer_40_out0_stream, StreamingConv_37_weights, StreamingConv_37_biases, StreamingConv_37_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_37_out0_stream_0," << StreamingConv_37_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_37_out0_stream_1," << StreamingConv_37_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_34_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_34;
    StreamingSwish_34.run<555>(StreamingConv_37_out0_stream, StreamingSwish_34_lut, StreamingSwish_34_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_34_out0_stream_0," << StreamingSwish_34_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_34_out0_stream_1," << StreamingSwish_34_out0_stream[1].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        32,  // SPLIT
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > StreamingSplit_6;
    StreamingSplit_6.run<556>(StreamingSwish_34_out0_stream, StreamingSplit_6_out0_stream, StreamingSplit_6_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_6_out0_stream_0," << StreamingSplit_6_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_6_out0_stream_1," << StreamingSplit_6_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_6_out1_stream_0," << StreamingSplit_6_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_6_out1_stream_1," << StreamingSplit_6_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        4,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_22;
    TensorDuplicator_22.run<557>(StreamingSplit_6_out1_stream, TensorDuplicator_22_out0_stream, TensorDuplicator_22_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_22_out0_stream_0," << TensorDuplicator_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_22_out0_stream_1," << TensorDuplicator_22_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_22_out1_stream_0," << TensorDuplicator_22_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_22_out1_stream_1," << TensorDuplicator_22_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_13;
    BandwidthAdjustDecreaseChannels_13.run<558>(StreamingSplit_6_out0_stream, BandwidthAdjustDecreaseChannels_13_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_13_out0_stream_0," << BandwidthAdjustDecreaseChannels_13_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_13_out0_stream_1," << BandwidthAdjustDecreaseChannels_13_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_14;
    BandwidthAdjustDecreaseChannels_14.run<559>(TensorDuplicator_22_out0_stream, BandwidthAdjustDecreaseChannels_14_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_14_out0_stream_0," << BandwidthAdjustDecreaseChannels_14_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_14_out0_stream_1," << BandwidthAdjustDecreaseChannels_14_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_15;
    BandwidthAdjustDecreaseChannels_15.run<560>(TensorDuplicator_22_out1_stream, BandwidthAdjustDecreaseChannels_15_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_15_out0_stream_0," << BandwidthAdjustDecreaseChannels_15_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_15_out0_stream_1," << BandwidthAdjustDecreaseChannels_15_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH_A
        32,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_18;
    StreamingConcat_18.run<561>(BandwidthAdjustDecreaseChannels_13_out0_stream, BandwidthAdjustDecreaseChannels_15_out0_stream, StreamingConcat_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_18_out0_stream_0," << StreamingConcat_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_18_out0_stream_1," << StreamingConcat_18_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_0;
    StreamingLineBuffer_41_pixel_0.run<562>(BandwidthAdjustDecreaseChannels_14_out0_stream[0], StreamingLineBuffer_41_out0_stream_prepad[11], StreamingLineBuffer_41_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_11," << StreamingLineBuffer_41_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_0," << StreamingLineBuffer_41_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_1;
    StreamingLineBuffer_41_pixel_1.run<563>(BandwidthAdjustDecreaseChannels_14_out0_stream[1], StreamingLineBuffer_41_out0_stream_prepad[10], StreamingLineBuffer_41_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_10," << StreamingLineBuffer_41_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_1," << StreamingLineBuffer_41_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_2;
    StreamingLineBuffer_41_pixel_2.run<564>(StreamingLineBuffer_41_buffer_stream[0], StreamingLineBuffer_41_out0_stream_prepad[9], StreamingLineBuffer_41_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_9," << StreamingLineBuffer_41_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_2," << StreamingLineBuffer_41_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_3;
    StreamingLineBuffer_41_pixel_3.run<565>(StreamingLineBuffer_41_buffer_stream[1], StreamingLineBuffer_41_out0_stream_prepad[8], StreamingLineBuffer_41_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_8," << StreamingLineBuffer_41_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_3," << StreamingLineBuffer_41_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_4;
    StreamingLineBuffer_41_pixel_4.run<566>(StreamingLineBuffer_41_buffer_stream[2], StreamingLineBuffer_41_out0_stream_prepad[7], StreamingLineBuffer_41_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_7," << StreamingLineBuffer_41_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_4," << StreamingLineBuffer_41_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_5;
    StreamingLineBuffer_41_pixel_5.run<567>(StreamingLineBuffer_41_buffer_stream[3], StreamingLineBuffer_41_out0_stream_prepad[6], StreamingLineBuffer_41_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_6," << StreamingLineBuffer_41_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_5," << StreamingLineBuffer_41_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_6;
    StreamingLineBuffer_41_pixel_6.run<568>(StreamingLineBuffer_41_buffer_stream[4], StreamingLineBuffer_41_out0_stream_prepad[5], StreamingLineBuffer_41_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_5," << StreamingLineBuffer_41_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_6," << StreamingLineBuffer_41_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_7;
    StreamingLineBuffer_41_pixel_7.run<569>(StreamingLineBuffer_41_buffer_stream[5], StreamingLineBuffer_41_out0_stream_prepad[4], StreamingLineBuffer_41_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_4," << StreamingLineBuffer_41_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_7," << StreamingLineBuffer_41_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_8;
    StreamingLineBuffer_41_pixel_8.run<570>(StreamingLineBuffer_41_buffer_stream[6], StreamingLineBuffer_41_out0_stream_prepad[3], StreamingLineBuffer_41_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_3," << StreamingLineBuffer_41_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_8," << StreamingLineBuffer_41_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_9;
    StreamingLineBuffer_41_pixel_9.run<571>(StreamingLineBuffer_41_buffer_stream[7], StreamingLineBuffer_41_out0_stream_prepad[2], StreamingLineBuffer_41_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_2," << StreamingLineBuffer_41_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_buffer_stream_9," << StreamingLineBuffer_41_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_10;
    StreamingLineBuffer_41_pixel_10.run<572>(StreamingLineBuffer_41_buffer_stream[8], StreamingLineBuffer_41_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_1," << StreamingLineBuffer_41_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pixel_11;
    StreamingLineBuffer_41_pixel_11.run<573>(StreamingLineBuffer_41_buffer_stream[9], StreamingLineBuffer_41_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_prepad_0," << StreamingLineBuffer_41_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_41_pad;
    StreamingLineBuffer_41_pad.run<574>(StreamingLineBuffer_41_out0_stream_prepad, StreamingLineBuffer_41_out0_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_9," << StreamingLineBuffer_41_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_10," << StreamingLineBuffer_41_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_41_out0_stream_11," << StreamingLineBuffer_41_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_38_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_38_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_38_weights dim=2 complete
    ap_int<16> StreamingConv_38_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_38_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_38_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_38;
    StreamingConv_38.run<575>(StreamingLineBuffer_41_out0_stream, StreamingConv_38_weights, StreamingConv_38_biases, StreamingConv_38_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_38_out0_stream_0," << StreamingConv_38_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_38_out0_stream_1," << StreamingConv_38_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_35_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_35;
    StreamingSwish_35.run<576>(StreamingConv_38_out0_stream, StreamingSwish_35_lut, StreamingSwish_35_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_35_out0_stream_0," << StreamingSwish_35_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_35_out0_stream_1," << StreamingSwish_35_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_0;
    StreamingLineBuffer_42_pixel_0.run<577>(StreamingSwish_35_out0_stream[0], StreamingLineBuffer_42_out0_stream_prepad[11], StreamingLineBuffer_42_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_11," << StreamingLineBuffer_42_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_0," << StreamingLineBuffer_42_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_1;
    StreamingLineBuffer_42_pixel_1.run<578>(StreamingSwish_35_out0_stream[1], StreamingLineBuffer_42_out0_stream_prepad[10], StreamingLineBuffer_42_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_10," << StreamingLineBuffer_42_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_1," << StreamingLineBuffer_42_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_2;
    StreamingLineBuffer_42_pixel_2.run<579>(StreamingLineBuffer_42_buffer_stream[0], StreamingLineBuffer_42_out0_stream_prepad[9], StreamingLineBuffer_42_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_9," << StreamingLineBuffer_42_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_2," << StreamingLineBuffer_42_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_3;
    StreamingLineBuffer_42_pixel_3.run<580>(StreamingLineBuffer_42_buffer_stream[1], StreamingLineBuffer_42_out0_stream_prepad[8], StreamingLineBuffer_42_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_8," << StreamingLineBuffer_42_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_3," << StreamingLineBuffer_42_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_4;
    StreamingLineBuffer_42_pixel_4.run<581>(StreamingLineBuffer_42_buffer_stream[2], StreamingLineBuffer_42_out0_stream_prepad[7], StreamingLineBuffer_42_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_7," << StreamingLineBuffer_42_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_4," << StreamingLineBuffer_42_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_5;
    StreamingLineBuffer_42_pixel_5.run<582>(StreamingLineBuffer_42_buffer_stream[3], StreamingLineBuffer_42_out0_stream_prepad[6], StreamingLineBuffer_42_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_6," << StreamingLineBuffer_42_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_5," << StreamingLineBuffer_42_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_6;
    StreamingLineBuffer_42_pixel_6.run<583>(StreamingLineBuffer_42_buffer_stream[4], StreamingLineBuffer_42_out0_stream_prepad[5], StreamingLineBuffer_42_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_5," << StreamingLineBuffer_42_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_6," << StreamingLineBuffer_42_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_7;
    StreamingLineBuffer_42_pixel_7.run<584>(StreamingLineBuffer_42_buffer_stream[5], StreamingLineBuffer_42_out0_stream_prepad[4], StreamingLineBuffer_42_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_4," << StreamingLineBuffer_42_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_7," << StreamingLineBuffer_42_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_8;
    StreamingLineBuffer_42_pixel_8.run<585>(StreamingLineBuffer_42_buffer_stream[6], StreamingLineBuffer_42_out0_stream_prepad[3], StreamingLineBuffer_42_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_3," << StreamingLineBuffer_42_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_8," << StreamingLineBuffer_42_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_9;
    StreamingLineBuffer_42_pixel_9.run<586>(StreamingLineBuffer_42_buffer_stream[7], StreamingLineBuffer_42_out0_stream_prepad[2], StreamingLineBuffer_42_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_2," << StreamingLineBuffer_42_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_buffer_stream_9," << StreamingLineBuffer_42_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_10;
    StreamingLineBuffer_42_pixel_10.run<587>(StreamingLineBuffer_42_buffer_stream[8], StreamingLineBuffer_42_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_1," << StreamingLineBuffer_42_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pixel_11;
    StreamingLineBuffer_42_pixel_11.run<588>(StreamingLineBuffer_42_buffer_stream[9], StreamingLineBuffer_42_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_prepad_0," << StreamingLineBuffer_42_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_42_pad;
    StreamingLineBuffer_42_pad.run<589>(StreamingLineBuffer_42_out0_stream_prepad, StreamingLineBuffer_42_out0_stream);
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
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_9," << StreamingLineBuffer_42_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_10," << StreamingLineBuffer_42_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_42_out0_stream_11," << StreamingLineBuffer_42_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_39_weights[1024][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_39_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_39_weights dim=2 complete
    ap_int<15> StreamingConv_39_biases[32][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_39_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_39_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
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
        32,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_39;
    StreamingConv_39.run<590>(StreamingLineBuffer_42_out0_stream, StreamingConv_39_weights, StreamingConv_39_biases, StreamingConv_39_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_39_out0_stream_0," << StreamingConv_39_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_39_out0_stream_1," << StreamingConv_39_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_36_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_36;
    StreamingSwish_36.run<591>(StreamingConv_39_out0_stream, StreamingSwish_36_lut, StreamingSwish_36_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_36_out0_stream_0," << StreamingSwish_36_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_36_out0_stream_1," << StreamingSwish_36_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH_A
        32,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_19;
    StreamingConcat_19.run<592>(StreamingConcat_18_out0_stream, StreamingSwish_36_out0_stream, StreamingConcat_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_19_out0_stream_0," << StreamingConcat_19_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_19_out0_stream_1," << StreamingConcat_19_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_43_pixel_0;
    StreamingLineBuffer_43_pixel_0.run<593>(StreamingConcat_19_out0_stream[1], StreamingLineBuffer_43_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_43_out0_stream_1," << StreamingLineBuffer_43_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_43_pixel_1;
    StreamingLineBuffer_43_pixel_1.run<594>(StreamingConcat_19_out0_stream[0], StreamingLineBuffer_43_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_43_out0_stream_0," << StreamingLineBuffer_43_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_40_weights[3072][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_40_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_40_weights dim=2 complete
    ap_int<14> StreamingConv_40_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_40_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_40_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        96,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_40;
    StreamingConv_40.run<595>(StreamingLineBuffer_43_out0_stream, StreamingConv_40_weights, StreamingConv_40_biases, StreamingConv_40_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_40_out0_stream_0," << StreamingConv_40_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_40_out0_stream_1," << StreamingConv_40_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_37_lut[256] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 14, 15, 16, 17, 19, 20, 21, 23, 24, 26, 27, 28, 30, 32, 33, 35, 36, 38, 39, 41, 42, 44, 46, 48, 50, 51, 53, 55, 57, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 87, 88, 91, 93, 95, 98, 100, 102, 104, 107, 109, 111, 114, 116, 119, 121, 123, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -3, -4, -4, -6, -7, -7, -8, -9, -9, -10, -12, -12, -13, -14, -14, -15, -16, -15, -16, -17, -17, -18, -19, -19, -19, -20, -20, -21, -21, -21, -22, -22, -22, -22, -23, -23, -23, -24, -23, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -24, -23, -23, -23, -23, -22, -22, -22, -22, -22, -21, -21, -20, -20, -19, -19, -18, -18, -18, -17, -16, -16, -15, -15, -14, -13, -13, -12, -11, -10, -10, -9, -8, -7, -6, -6, -5, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_37;
    StreamingSwish_37.run<596>(StreamingConv_40_out0_stream, StreamingSwish_37_lut, StreamingSwish_37_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_37_out0_stream_0," << StreamingSwish_37_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_37_out0_stream_1," << StreamingSwish_37_out0_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_23;
    TensorDuplicator_23.run<597>(StreamingSwish_37_out0_stream, TensorDuplicator_23_out0_stream, TensorDuplicator_23_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_23_out0_stream_0," << TensorDuplicator_23_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_23_out0_stream_1," << TensorDuplicator_23_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_23_out1_stream_0," << TensorDuplicator_23_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_23_out1_stream_1," << TensorDuplicator_23_out1_stream[1].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_24;
    TensorDuplicator_24.run<598>(TensorDuplicator_23_out0_stream, TensorDuplicator_24_out0_stream, TensorDuplicator_24_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_24_out0_stream_0," << TensorDuplicator_24_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_24_out0_stream_1," << TensorDuplicator_24_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_24_out1_stream_0," << TensorDuplicator_24_out1_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_24_out1_stream_1," << TensorDuplicator_24_out1_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_16;
    BandwidthAdjustDecreaseChannels_16.run<599>(TensorDuplicator_23_out1_stream, BandwidthAdjustDecreaseChannels_16_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_16_out0_stream_0," << BandwidthAdjustDecreaseChannels_16_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_16_out0_stream_1," << BandwidthAdjustDecreaseChannels_16_out0_stream[1].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_17;
    BandwidthAdjustDecreaseChannels_17.run<600>(TensorDuplicator_24_out0_stream, BandwidthAdjustDecreaseChannels_17_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_17_out0_stream_0," << BandwidthAdjustDecreaseChannels_17_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_17_out0_stream_1," << BandwidthAdjustDecreaseChannels_17_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_0;
    StreamingLineBuffer_44_pixel_0.run<601>(BandwidthAdjustDecreaseChannels_16_out0_stream[0], StreamingLineBuffer_44_out0_stream_prepad[11], StreamingLineBuffer_44_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_11," << StreamingLineBuffer_44_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_0," << StreamingLineBuffer_44_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_1;
    StreamingLineBuffer_44_pixel_1.run<602>(BandwidthAdjustDecreaseChannels_16_out0_stream[1], StreamingLineBuffer_44_out0_stream_prepad[10], StreamingLineBuffer_44_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_10," << StreamingLineBuffer_44_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_1," << StreamingLineBuffer_44_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_0;
    StreamingLineBuffer_45_pixel_0.run<614>(TensorDuplicator_24_out1_stream[0], StreamingLineBuffer_45_out0_stream_prepad[11], StreamingLineBuffer_45_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_11," << StreamingLineBuffer_45_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_0," << StreamingLineBuffer_45_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_1;
    StreamingLineBuffer_45_pixel_1.run<615>(TensorDuplicator_24_out1_stream[1], StreamingLineBuffer_45_out0_stream_prepad[10], StreamingLineBuffer_45_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_10," << StreamingLineBuffer_45_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_1," << StreamingLineBuffer_45_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_2;
    StreamingLineBuffer_44_pixel_2.run<603>(StreamingLineBuffer_44_buffer_stream[0], StreamingLineBuffer_44_out0_stream_prepad[9], StreamingLineBuffer_44_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_9," << StreamingLineBuffer_44_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_2," << StreamingLineBuffer_44_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_3;
    StreamingLineBuffer_44_pixel_3.run<604>(StreamingLineBuffer_44_buffer_stream[1], StreamingLineBuffer_44_out0_stream_prepad[8], StreamingLineBuffer_44_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_8," << StreamingLineBuffer_44_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_3," << StreamingLineBuffer_44_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_2;
    StreamingLineBuffer_45_pixel_2.run<616>(StreamingLineBuffer_45_buffer_stream[0], StreamingLineBuffer_45_out0_stream_prepad[9], StreamingLineBuffer_45_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_9," << StreamingLineBuffer_45_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_2," << StreamingLineBuffer_45_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_3;
    StreamingLineBuffer_45_pixel_3.run<617>(StreamingLineBuffer_45_buffer_stream[1], StreamingLineBuffer_45_out0_stream_prepad[8], StreamingLineBuffer_45_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_8," << StreamingLineBuffer_45_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_3," << StreamingLineBuffer_45_buffer_stream[3].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_6;
    BandwidthAdjustDecreaseStreams_6.run<629>(BandwidthAdjustDecreaseChannels_17_out0_stream, BandwidthAdjustDecreaseStreams_6_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_6_out0_stream_0," << BandwidthAdjustDecreaseStreams_6_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_4;
    StreamingLineBuffer_44_pixel_4.run<605>(StreamingLineBuffer_44_buffer_stream[2], StreamingLineBuffer_44_out0_stream_prepad[7], StreamingLineBuffer_44_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_7," << StreamingLineBuffer_44_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_4," << StreamingLineBuffer_44_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_5;
    StreamingLineBuffer_44_pixel_5.run<606>(StreamingLineBuffer_44_buffer_stream[3], StreamingLineBuffer_44_out0_stream_prepad[6], StreamingLineBuffer_44_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_6," << StreamingLineBuffer_44_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_5," << StreamingLineBuffer_44_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_4;
    StreamingLineBuffer_45_pixel_4.run<618>(StreamingLineBuffer_45_buffer_stream[2], StreamingLineBuffer_45_out0_stream_prepad[7], StreamingLineBuffer_45_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_7," << StreamingLineBuffer_45_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_4," << StreamingLineBuffer_45_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_5;
    StreamingLineBuffer_45_pixel_5.run<619>(StreamingLineBuffer_45_buffer_stream[3], StreamingLineBuffer_45_out0_stream_prepad[6], StreamingLineBuffer_45_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_6," << StreamingLineBuffer_45_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_5," << StreamingLineBuffer_45_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_0;
    StreamingLineBuffer_46_pixel_0.run<632>(BandwidthAdjustDecreaseStreams_6_out0_stream[0], StreamingLineBuffer_46_out0_stream_prepad[8], StreamingLineBuffer_46_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_8," << StreamingLineBuffer_46_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_0," << StreamingLineBuffer_46_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_6;
    StreamingLineBuffer_44_pixel_6.run<607>(StreamingLineBuffer_44_buffer_stream[4], StreamingLineBuffer_44_out0_stream_prepad[5], StreamingLineBuffer_44_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_5," << StreamingLineBuffer_44_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_6," << StreamingLineBuffer_44_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_7;
    StreamingLineBuffer_44_pixel_7.run<608>(StreamingLineBuffer_44_buffer_stream[5], StreamingLineBuffer_44_out0_stream_prepad[4], StreamingLineBuffer_44_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_4," << StreamingLineBuffer_44_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_7," << StreamingLineBuffer_44_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_6;
    StreamingLineBuffer_45_pixel_6.run<620>(StreamingLineBuffer_45_buffer_stream[4], StreamingLineBuffer_45_out0_stream_prepad[5], StreamingLineBuffer_45_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_5," << StreamingLineBuffer_45_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_6," << StreamingLineBuffer_45_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_7;
    StreamingLineBuffer_45_pixel_7.run<621>(StreamingLineBuffer_45_buffer_stream[5], StreamingLineBuffer_45_out0_stream_prepad[4], StreamingLineBuffer_45_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_4," << StreamingLineBuffer_45_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_7," << StreamingLineBuffer_45_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_1;
    StreamingLineBuffer_46_pixel_1.run<633>(StreamingLineBuffer_46_buffer_stream[0], StreamingLineBuffer_46_out0_stream_prepad[7], StreamingLineBuffer_46_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_7," << StreamingLineBuffer_46_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_1," << StreamingLineBuffer_46_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_8;
    StreamingLineBuffer_44_pixel_8.run<609>(StreamingLineBuffer_44_buffer_stream[6], StreamingLineBuffer_44_out0_stream_prepad[3], StreamingLineBuffer_44_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_3," << StreamingLineBuffer_44_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_8," << StreamingLineBuffer_44_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_9;
    StreamingLineBuffer_44_pixel_9.run<610>(StreamingLineBuffer_44_buffer_stream[7], StreamingLineBuffer_44_out0_stream_prepad[2], StreamingLineBuffer_44_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_2," << StreamingLineBuffer_44_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_buffer_stream_9," << StreamingLineBuffer_44_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_8;
    StreamingLineBuffer_45_pixel_8.run<622>(StreamingLineBuffer_45_buffer_stream[6], StreamingLineBuffer_45_out0_stream_prepad[3], StreamingLineBuffer_45_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_3," << StreamingLineBuffer_45_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_8," << StreamingLineBuffer_45_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_9;
    StreamingLineBuffer_45_pixel_9.run<623>(StreamingLineBuffer_45_buffer_stream[7], StreamingLineBuffer_45_out0_stream_prepad[2], StreamingLineBuffer_45_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_2," << StreamingLineBuffer_45_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_buffer_stream_9," << StreamingLineBuffer_45_buffer_stream[9].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_2;
    StreamingLineBuffer_46_pixel_2.run<634>(StreamingLineBuffer_46_buffer_stream[1], StreamingLineBuffer_46_out0_stream_prepad[6], StreamingLineBuffer_46_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_6," << StreamingLineBuffer_46_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_2," << StreamingLineBuffer_46_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_10;
    StreamingLineBuffer_44_pixel_10.run<611>(StreamingLineBuffer_44_buffer_stream[8], StreamingLineBuffer_44_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_1," << StreamingLineBuffer_44_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pixel_11;
    StreamingLineBuffer_44_pixel_11.run<612>(StreamingLineBuffer_44_buffer_stream[9], StreamingLineBuffer_44_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_prepad_0," << StreamingLineBuffer_44_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_10;
    StreamingLineBuffer_45_pixel_10.run<624>(StreamingLineBuffer_45_buffer_stream[8], StreamingLineBuffer_45_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_1," << StreamingLineBuffer_45_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pixel_11;
    StreamingLineBuffer_45_pixel_11.run<625>(StreamingLineBuffer_45_buffer_stream[9], StreamingLineBuffer_45_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_prepad_0," << StreamingLineBuffer_45_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_3;
    StreamingLineBuffer_46_pixel_3.run<635>(StreamingLineBuffer_46_buffer_stream[2], StreamingLineBuffer_46_out0_stream_prepad[5], StreamingLineBuffer_46_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_5," << StreamingLineBuffer_46_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_3," << StreamingLineBuffer_46_buffer_stream[3].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_44_pad;
    StreamingLineBuffer_44_pad.run<613>(StreamingLineBuffer_44_out0_stream_prepad, StreamingLineBuffer_44_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_0," << StreamingLineBuffer_44_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_1," << StreamingLineBuffer_44_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_2," << StreamingLineBuffer_44_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_3," << StreamingLineBuffer_44_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_4," << StreamingLineBuffer_44_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_5," << StreamingLineBuffer_44_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_6," << StreamingLineBuffer_44_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_7," << StreamingLineBuffer_44_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_8," << StreamingLineBuffer_44_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_9," << StreamingLineBuffer_44_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_10," << StreamingLineBuffer_44_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_44_out0_stream_11," << StreamingLineBuffer_44_out0_stream[11].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 2>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_45_pad;
    StreamingLineBuffer_45_pad.run<626>(StreamingLineBuffer_45_out0_stream_prepad, StreamingLineBuffer_45_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_0," << StreamingLineBuffer_45_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_1," << StreamingLineBuffer_45_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_2," << StreamingLineBuffer_45_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_3," << StreamingLineBuffer_45_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_4," << StreamingLineBuffer_45_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_5," << StreamingLineBuffer_45_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_6," << StreamingLineBuffer_45_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_7," << StreamingLineBuffer_45_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_8," << StreamingLineBuffer_45_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_9," << StreamingLineBuffer_45_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_10," << StreamingLineBuffer_45_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_45_out0_stream_11," << StreamingLineBuffer_45_out0_stream[11].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_4;
    StreamingLineBuffer_46_pixel_4.run<636>(StreamingLineBuffer_46_buffer_stream[3], StreamingLineBuffer_46_out0_stream_prepad[4], StreamingLineBuffer_46_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_4," << StreamingLineBuffer_46_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_4," << StreamingLineBuffer_46_buffer_stream[4].size() << std::endl;
    #endif
    ap_int<8> StreamingDepthwiseConv_3_weights[64][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_weights dim=2 complete
    ap_int<15> StreamingDepthwiseConv_3_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_3_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        DequantQuantEqual<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_3;
    StreamingDepthwiseConv_3.run<627>(StreamingLineBuffer_44_out0_stream, StreamingDepthwiseConv_3_weights, StreamingDepthwiseConv_3_biases, StreamingDepthwiseConv_3_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_0," << StreamingDepthwiseConv_3_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_3_out0_stream_1," << StreamingDepthwiseConv_3_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_41_weights[2048][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_41_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_41_weights dim=2 complete
    ap_int<15> StreamingConv_41_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_41_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_41_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_41;
    StreamingConv_41.run<628>(StreamingLineBuffer_45_out0_stream, StreamingConv_41_weights, StreamingConv_41_biases, StreamingConv_41_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_41_out0_stream_0," << StreamingConv_41_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_41_out0_stream_1," << StreamingConv_41_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_5;
    StreamingLineBuffer_46_pixel_5.run<637>(StreamingLineBuffer_46_buffer_stream[4], StreamingLineBuffer_46_out0_stream_prepad[3], StreamingLineBuffer_46_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_3," << StreamingLineBuffer_46_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_5," << StreamingLineBuffer_46_buffer_stream[5].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_38_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_38;
    StreamingSwish_38.run<630>(StreamingDepthwiseConv_3_out0_stream, StreamingSwish_38_lut, StreamingSwish_38_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_38_out0_stream_0," << StreamingSwish_38_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_38_out0_stream_1," << StreamingSwish_38_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_39_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_39;
    StreamingSwish_39.run<631>(StreamingConv_41_out0_stream, StreamingSwish_39_lut, StreamingSwish_39_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_39_out0_stream_0," << StreamingSwish_39_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_39_out0_stream_1," << StreamingSwish_39_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_6;
    StreamingLineBuffer_46_pixel_6.run<638>(StreamingLineBuffer_46_buffer_stream[5], StreamingLineBuffer_46_out0_stream_prepad[2], StreamingLineBuffer_46_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_2," << StreamingLineBuffer_46_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_6," << StreamingLineBuffer_46_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_7;
    StreamingLineBuffer_46_pixel_7.run<639>(StreamingLineBuffer_46_buffer_stream[6], StreamingLineBuffer_46_out0_stream_prepad[1], StreamingLineBuffer_46_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_1," << StreamingLineBuffer_46_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_buffer_stream_7," << StreamingLineBuffer_46_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_47_pixel_0;
    StreamingLineBuffer_47_pixel_0.run<643>(StreamingSwish_38_out0_stream[1], StreamingLineBuffer_47_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_47_out0_stream_1," << StreamingLineBuffer_47_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_47_pixel_1;
    StreamingLineBuffer_47_pixel_1.run<644>(StreamingSwish_38_out0_stream[0], StreamingLineBuffer_47_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_47_out0_stream_0," << StreamingLineBuffer_47_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_0;
    StreamingLineBuffer_48_pixel_0.run<645>(StreamingSwish_39_out0_stream[0], StreamingLineBuffer_48_out0_stream_prepad[11], StreamingLineBuffer_48_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_11," << StreamingLineBuffer_48_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_0," << StreamingLineBuffer_48_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_1;
    StreamingLineBuffer_48_pixel_1.run<646>(StreamingSwish_39_out0_stream[1], StreamingLineBuffer_48_out0_stream_prepad[10], StreamingLineBuffer_48_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_10," << StreamingLineBuffer_48_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_1," << StreamingLineBuffer_48_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pixel_8;
    StreamingLineBuffer_46_pixel_8.run<640>(StreamingLineBuffer_46_buffer_stream[7], StreamingLineBuffer_46_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_prepad_0," << StreamingLineBuffer_46_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_2;
    StreamingLineBuffer_48_pixel_2.run<647>(StreamingLineBuffer_48_buffer_stream[0], StreamingLineBuffer_48_out0_stream_prepad[9], StreamingLineBuffer_48_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_9," << StreamingLineBuffer_48_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_2," << StreamingLineBuffer_48_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_3;
    StreamingLineBuffer_48_pixel_3.run<648>(StreamingLineBuffer_48_buffer_stream[1], StreamingLineBuffer_48_out0_stream_prepad[8], StreamingLineBuffer_48_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_8," << StreamingLineBuffer_48_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_3," << StreamingLineBuffer_48_buffer_stream[3].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_43_weights[2560][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_43_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_43_weights dim=2 complete
    ap_int<15> StreamingConv_43_biases[40][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_43_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_43_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<5, ap_int<24>, ap_int<8>>,  // Quantizer
        80,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_43;
    StreamingConv_43.run<658>(StreamingLineBuffer_47_out0_stream, StreamingConv_43_weights, StreamingConv_43_biases, StreamingConv_43_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_43_out0_stream_0," << StreamingConv_43_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_43_out0_stream_1," << StreamingConv_43_out0_stream[1].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_46_pad;
    StreamingLineBuffer_46_pad.run<641>(StreamingLineBuffer_46_out0_stream_prepad, StreamingLineBuffer_46_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_0," << StreamingLineBuffer_46_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_1," << StreamingLineBuffer_46_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_2," << StreamingLineBuffer_46_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_3," << StreamingLineBuffer_46_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_4," << StreamingLineBuffer_46_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_5," << StreamingLineBuffer_46_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_6," << StreamingLineBuffer_46_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_7," << StreamingLineBuffer_46_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_46_out0_stream_8," << StreamingLineBuffer_46_out0_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_4;
    StreamingLineBuffer_48_pixel_4.run<649>(StreamingLineBuffer_48_buffer_stream[2], StreamingLineBuffer_48_out0_stream_prepad[7], StreamingLineBuffer_48_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_7," << StreamingLineBuffer_48_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_4," << StreamingLineBuffer_48_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_5;
    StreamingLineBuffer_48_pixel_5.run<650>(StreamingLineBuffer_48_buffer_stream[3], StreamingLineBuffer_48_out0_stream_prepad[6], StreamingLineBuffer_48_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_6," << StreamingLineBuffer_48_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_5," << StreamingLineBuffer_48_buffer_stream[5].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_41_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 47, 49, 50, 51, 52, 54, 54, 56, 57, 58, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 79, 80, 81, 83, 85, 86, 87, 89, 90, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -3, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -10, -11, -11, -11, -11, -12, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -11, -10, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_41;
    StreamingSwish_41.run<661>(StreamingConv_43_out0_stream, StreamingSwish_41_lut, StreamingSwish_41_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_41_out0_stream_0," << StreamingSwish_41_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_41_out0_stream_1," << StreamingSwish_41_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_42_weights[2048][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_42_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_42_weights dim=2 complete
    ap_int<16> StreamingConv_42_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_42_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_42_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_42;
    StreamingConv_42.run<642>(StreamingLineBuffer_46_out0_stream, StreamingConv_42_weights, StreamingConv_42_biases, StreamingConv_42_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_42_out0_stream_0," << StreamingConv_42_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_6;
    StreamingLineBuffer_48_pixel_6.run<651>(StreamingLineBuffer_48_buffer_stream[4], StreamingLineBuffer_48_out0_stream_prepad[5], StreamingLineBuffer_48_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_5," << StreamingLineBuffer_48_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_6," << StreamingLineBuffer_48_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_7;
    StreamingLineBuffer_48_pixel_7.run<652>(StreamingLineBuffer_48_buffer_stream[5], StreamingLineBuffer_48_out0_stream_prepad[4], StreamingLineBuffer_48_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_4," << StreamingLineBuffer_48_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_7," << StreamingLineBuffer_48_buffer_stream[7].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_18;
    BandwidthAdjustDecreaseChannels_18.run<664>(StreamingSwish_41_out0_stream, BandwidthAdjustDecreaseChannels_18_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_18_out0_stream_0," << BandwidthAdjustDecreaseChannels_18_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_18_out0_stream_1," << BandwidthAdjustDecreaseChannels_18_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_8;
    StreamingLineBuffer_48_pixel_8.run<653>(StreamingLineBuffer_48_buffer_stream[6], StreamingLineBuffer_48_out0_stream_prepad[3], StreamingLineBuffer_48_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_3," << StreamingLineBuffer_48_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_8," << StreamingLineBuffer_48_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_9;
    StreamingLineBuffer_48_pixel_9.run<654>(StreamingLineBuffer_48_buffer_stream[7], StreamingLineBuffer_48_out0_stream_prepad[2], StreamingLineBuffer_48_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_2," << StreamingLineBuffer_48_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_buffer_stream_9," << StreamingLineBuffer_48_buffer_stream[9].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_40_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_40;
    StreamingSwish_40.run<660>(StreamingConv_42_out0_stream, StreamingSwish_40_lut, StreamingSwish_40_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_40_out0_stream_0," << StreamingSwish_40_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_0;
    StreamingLineBuffer_50_pixel_0.run<670>(BandwidthAdjustDecreaseChannels_18_out0_stream[0], StreamingLineBuffer_50_out0_stream_prepad[11], StreamingLineBuffer_50_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_11," << StreamingLineBuffer_50_out0_stream_prepad[11].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_0," << StreamingLineBuffer_50_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_1;
    StreamingLineBuffer_50_pixel_1.run<671>(BandwidthAdjustDecreaseChannels_18_out0_stream[1], StreamingLineBuffer_50_out0_stream_prepad[10], StreamingLineBuffer_50_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_10," << StreamingLineBuffer_50_out0_stream_prepad[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_1," << StreamingLineBuffer_50_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_10;
    StreamingLineBuffer_48_pixel_10.run<655>(StreamingLineBuffer_48_buffer_stream[8], StreamingLineBuffer_48_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_1," << StreamingLineBuffer_48_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pixel_11;
    StreamingLineBuffer_48_pixel_11.run<656>(StreamingLineBuffer_48_buffer_stream[9], StreamingLineBuffer_48_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_prepad_0," << StreamingLineBuffer_48_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH_A
        128,  // IN_CH_B
        1,  // W_PAR
        2  // CH_PAR
    > StreamingConcat_20;
    StreamingConcat_20.run<663>(StreamingSwish_40_out0_stream, TensorDuplicator_21_out1_stream, StreamingConcat_20_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_20_out0_stream_0," << StreamingConcat_20_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_2;
    StreamingLineBuffer_50_pixel_2.run<672>(StreamingLineBuffer_50_buffer_stream[0], StreamingLineBuffer_50_out0_stream_prepad[9], StreamingLineBuffer_50_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_9," << StreamingLineBuffer_50_out0_stream_prepad[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_2," << StreamingLineBuffer_50_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_3;
    StreamingLineBuffer_50_pixel_3.run<673>(StreamingLineBuffer_50_buffer_stream[1], StreamingLineBuffer_50_out0_stream_prepad[8], StreamingLineBuffer_50_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_8," << StreamingLineBuffer_50_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_3," << StreamingLineBuffer_50_buffer_stream[3].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
    > StreamingLineBuffer_48_pad;
    StreamingLineBuffer_48_pad.run<657>(StreamingLineBuffer_48_out0_stream_prepad, StreamingLineBuffer_48_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_0," << StreamingLineBuffer_48_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_1," << StreamingLineBuffer_48_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_2," << StreamingLineBuffer_48_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_3," << StreamingLineBuffer_48_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_4," << StreamingLineBuffer_48_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_5," << StreamingLineBuffer_48_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_6," << StreamingLineBuffer_48_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_7," << StreamingLineBuffer_48_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_8," << StreamingLineBuffer_48_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_9," << StreamingLineBuffer_48_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_10," << StreamingLineBuffer_48_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_48_out0_stream_11," << StreamingLineBuffer_48_out0_stream[11].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_45_weights[6144][4][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_45_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_45_weights dim=2 complete
    ap_int<14> StreamingConv_45_biases[64][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_45_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_45_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        128,  // OUT_CH
        192,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_45;
    StreamingConv_45.run<665>(StreamingConcat_20_out0_stream, StreamingConv_45_weights, StreamingConv_45_biases, StreamingConv_45_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_45_out0_stream_0," << StreamingConv_45_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_4;
    StreamingLineBuffer_50_pixel_4.run<674>(StreamingLineBuffer_50_buffer_stream[2], StreamingLineBuffer_50_out0_stream_prepad[7], StreamingLineBuffer_50_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_7," << StreamingLineBuffer_50_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_4," << StreamingLineBuffer_50_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_5;
    StreamingLineBuffer_50_pixel_5.run<675>(StreamingLineBuffer_50_buffer_stream[3], StreamingLineBuffer_50_out0_stream_prepad[6], StreamingLineBuffer_50_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_6," << StreamingLineBuffer_50_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_5," << StreamingLineBuffer_50_buffer_stream[5].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_44_weights[2048][2][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_44_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_44_weights dim=2 complete
    ap_int<13> StreamingConv_44_biases[32][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_44_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_44_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_44;
    StreamingConv_44.run<659>(StreamingLineBuffer_48_out0_stream, StreamingConv_44_weights, StreamingConv_44_biases, StreamingConv_44_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_44_out0_stream_0," << StreamingConv_44_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_44_out0_stream_1," << StreamingConv_44_out0_stream[1].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_43_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        2,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_43;
    StreamingSwish_43.run<669>(StreamingConv_45_out0_stream, StreamingSwish_43_lut, StreamingSwish_43_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_43_out0_stream_0," << StreamingSwish_43_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_6;
    StreamingLineBuffer_50_pixel_6.run<676>(StreamingLineBuffer_50_buffer_stream[4], StreamingLineBuffer_50_out0_stream_prepad[5], StreamingLineBuffer_50_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_5," << StreamingLineBuffer_50_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_6," << StreamingLineBuffer_50_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_7;
    StreamingLineBuffer_50_pixel_7.run<677>(StreamingLineBuffer_50_buffer_stream[5], StreamingLineBuffer_50_out0_stream_prepad[4], StreamingLineBuffer_50_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_4," << StreamingLineBuffer_50_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_7," << StreamingLineBuffer_50_buffer_stream[7].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_42_lut[256] = {0, 1, 1, 2, 3, 4, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -1, -1, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_42;
    StreamingSwish_42.run<662>(StreamingConv_44_out0_stream, StreamingSwish_42_lut, StreamingSwish_42_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_42_out0_stream_0," << StreamingSwish_42_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_42_out0_stream_1," << StreamingSwish_42_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_8;
    StreamingLineBuffer_50_pixel_8.run<678>(StreamingLineBuffer_50_buffer_stream[6], StreamingLineBuffer_50_out0_stream_prepad[3], StreamingLineBuffer_50_buffer_stream[8]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_3," << StreamingLineBuffer_50_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_8," << StreamingLineBuffer_50_buffer_stream[8].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_9;
    StreamingLineBuffer_50_pixel_9.run<679>(StreamingLineBuffer_50_buffer_stream[7], StreamingLineBuffer_50_out0_stream_prepad[2], StreamingLineBuffer_50_buffer_stream[9]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_2," << StreamingLineBuffer_50_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_buffer_stream_9," << StreamingLineBuffer_50_buffer_stream[9].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_19;
    BandwidthAdjustDecreaseChannels_19.run<684>(StreamingSwish_43_out0_stream, BandwidthAdjustDecreaseChannels_19_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseChannels_19_out0_stream_0," << BandwidthAdjustDecreaseChannels_19_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        2  // CH_PAR
    > StreamingLineBuffer_49_pixel_0;
    StreamingLineBuffer_49_pixel_0.run<666>(StreamingSwish_42_out0_stream[1], StreamingLineBuffer_49_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_49_out0_stream_1," << StreamingLineBuffer_49_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
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
        2  // CH_PAR
    > StreamingLineBuffer_49_pixel_1;
    StreamingLineBuffer_49_pixel_1.run<667>(StreamingSwish_42_out0_stream[0], StreamingLineBuffer_49_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_49_out0_stream_0," << StreamingLineBuffer_49_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_10;
    StreamingLineBuffer_50_pixel_10.run<680>(StreamingLineBuffer_50_buffer_stream[8], StreamingLineBuffer_50_out0_stream_prepad[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_1," << StreamingLineBuffer_50_out0_stream_prepad[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
        3,  // FW
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
    > StreamingLineBuffer_50_pixel_11;
    StreamingLineBuffer_50_pixel_11.run<681>(StreamingLineBuffer_50_buffer_stream[9], StreamingLineBuffer_50_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_prepad_0," << StreamingLineBuffer_50_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingSplitChannels <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        64,  // SPLIT
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > StreamingSplit_7;
    StreamingSplit_7.run<686>(BandwidthAdjustDecreaseChannels_19_out0_stream, StreamingSplit_7_out0_stream, StreamingSplit_7_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_7_out0_stream_0," << StreamingSplit_7_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSplit_7_out1_stream_0," << StreamingSplit_7_out1_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_46_weights[2048][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_46_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_46_weights dim=2 complete
    ap_int<14> StreamingConv_46_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_46_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_46_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<9, ap_int<24>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_46;
    StreamingConv_46.run<668>(StreamingLineBuffer_49_out0_stream, StreamingConv_46_weights, StreamingConv_46_biases, StreamingConv_46_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_46_out0_stream_0," << StreamingConv_46_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_46_out0_stream_1," << StreamingConv_46_out0_stream[1].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        3,  // FH
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
    > StreamingLineBuffer_50_pad;
    StreamingLineBuffer_50_pad.run<682>(StreamingLineBuffer_50_out0_stream_prepad, StreamingLineBuffer_50_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_0," << StreamingLineBuffer_50_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_1," << StreamingLineBuffer_50_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_2," << StreamingLineBuffer_50_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_3," << StreamingLineBuffer_50_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_4," << StreamingLineBuffer_50_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_5," << StreamingLineBuffer_50_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_6," << StreamingLineBuffer_50_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_7," << StreamingLineBuffer_50_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_8," << StreamingLineBuffer_50_out0_stream[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_9," << StreamingLineBuffer_50_out0_stream[9].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_10," << StreamingLineBuffer_50_out0_stream[10].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_50_out0_stream_11," << StreamingLineBuffer_50_out0_stream[11].size() << std::endl;
    #endif
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_25;
    TensorDuplicator_25.run<687>(StreamingSplit_7_out1_stream, TensorDuplicator_25_out0_stream, TensorDuplicator_25_out1_stream);
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_25_out0_stream_0," << TensorDuplicator_25_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "TensorDuplicator_25_out1_stream_0," << TensorDuplicator_25_out1_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingDepthwiseConv_4_weights[80][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_weights dim=2 complete
    ap_int<11> StreamingDepthwiseConv_4_biases[80][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingDepthwiseConv_4_biases dim=2 complete
    StreamingDepthwiseConv <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<11>, 1>,  // TBiasStruct
        ap_int<11>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        DequantQuantEqual<ap_int<21>>,  // Activation
        DequantQuantPo2<4, ap_int<21>, ap_int<8>>,  // Quantizer
        80,  // OUT_CH
        80,  // IN_CH
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_4;
    StreamingDepthwiseConv_4.run<683>(StreamingLineBuffer_50_out0_stream, StreamingDepthwiseConv_4_weights, StreamingDepthwiseConv_4_biases, StreamingDepthwiseConv_4_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_0," << StreamingDepthwiseConv_4_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingDepthwiseConv_4_out0_stream_1," << StreamingDepthwiseConv_4_out0_stream[1].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH_A
        64,  // IN_CH_B
        1,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_21;
    StreamingConcat_21.run<691>(StreamingSplit_7_out0_stream, TensorDuplicator_25_out1_stream, StreamingConcat_21_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_21_out0_stream_0," << StreamingConcat_21_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_0;
    StreamingLineBuffer_52_pixel_0.run<692>(TensorDuplicator_25_out0_stream[0], StreamingLineBuffer_52_out0_stream_prepad[8], StreamingLineBuffer_52_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_8," << StreamingLineBuffer_52_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_0," << StreamingLineBuffer_52_buffer_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_44_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_44;
    StreamingSwish_44.run<685>(StreamingDepthwiseConv_4_out0_stream, StreamingSwish_44_lut, StreamingSwish_44_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_44_out0_stream_0," << StreamingSwish_44_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_44_out0_stream_1," << StreamingSwish_44_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_1;
    StreamingLineBuffer_52_pixel_1.run<693>(StreamingLineBuffer_52_buffer_stream[0], StreamingLineBuffer_52_out0_stream_prepad[7], StreamingLineBuffer_52_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_7," << StreamingLineBuffer_52_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_1," << StreamingLineBuffer_52_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
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
    > StreamingLineBuffer_51_pixel_0;
    StreamingLineBuffer_51_pixel_0.run<688>(StreamingSwish_44_out0_stream[1], StreamingLineBuffer_51_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_51_out0_stream_1," << StreamingLineBuffer_51_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
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
    > StreamingLineBuffer_51_pixel_1;
    StreamingLineBuffer_51_pixel_1.run<689>(StreamingSwish_44_out0_stream[0], StreamingLineBuffer_51_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_51_out0_stream_0," << StreamingLineBuffer_51_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_2;
    StreamingLineBuffer_52_pixel_2.run<694>(StreamingLineBuffer_52_buffer_stream[1], StreamingLineBuffer_52_out0_stream_prepad[6], StreamingLineBuffer_52_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_6," << StreamingLineBuffer_52_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_2," << StreamingLineBuffer_52_buffer_stream[2].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_47_weights[3200][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_47_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_47_weights dim=2 complete
    ap_int<13> StreamingConv_47_biases[40][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_47_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_47_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<5, ap_int<24>, ap_int<8>>,  // Quantizer
        80,  // OUT_CH
        80,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_47;
    StreamingConv_47.run<690>(StreamingLineBuffer_51_out0_stream, StreamingConv_47_weights, StreamingConv_47_biases, StreamingConv_47_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_47_out0_stream_0," << StreamingConv_47_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_47_out0_stream_1," << StreamingConv_47_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_3;
    StreamingLineBuffer_52_pixel_3.run<695>(StreamingLineBuffer_52_buffer_stream[2], StreamingLineBuffer_52_out0_stream_prepad[5], StreamingLineBuffer_52_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_5," << StreamingLineBuffer_52_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_3," << StreamingLineBuffer_52_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_4;
    StreamingLineBuffer_52_pixel_4.run<696>(StreamingLineBuffer_52_buffer_stream[3], StreamingLineBuffer_52_out0_stream_prepad[4], StreamingLineBuffer_52_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_4," << StreamingLineBuffer_52_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_4," << StreamingLineBuffer_52_buffer_stream[4].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_45_lut[256] = {0, 1, 1, 2, 3, 4, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -1, -1, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
        2,  // CH_PAR
        2  // W_PAR
    > StreamingSwish_45;
    StreamingSwish_45.run<702>(StreamingConv_47_out0_stream, StreamingSwish_45_lut, StreamingSwish_45_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_45_out0_stream_0," << StreamingSwish_45_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_45_out0_stream_1," << StreamingSwish_45_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_5;
    StreamingLineBuffer_52_pixel_5.run<697>(StreamingLineBuffer_52_buffer_stream[4], StreamingLineBuffer_52_out0_stream_prepad[3], StreamingLineBuffer_52_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_3," << StreamingLineBuffer_52_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_5," << StreamingLineBuffer_52_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
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
        2  // CH_PAR
    > StreamingLineBuffer_53_pixel_0;
    StreamingLineBuffer_53_pixel_0.run<705>(StreamingSwish_45_out0_stream[1], StreamingLineBuffer_53_out0_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_53_out0_stream_1," << StreamingLineBuffer_53_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 2>,  // TWord
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        80,  // IN_CH
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
        2  // CH_PAR
    > StreamingLineBuffer_53_pixel_1;
    StreamingLineBuffer_53_pixel_1.run<706>(StreamingSwish_45_out0_stream[0], StreamingLineBuffer_53_out0_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_53_out0_stream_0," << StreamingLineBuffer_53_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_6;
    StreamingLineBuffer_52_pixel_6.run<698>(StreamingLineBuffer_52_buffer_stream[5], StreamingLineBuffer_52_out0_stream_prepad[2], StreamingLineBuffer_52_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_2," << StreamingLineBuffer_52_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_6," << StreamingLineBuffer_52_buffer_stream[6].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_49_weights[3200][2][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_49_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_49_weights dim=2 complete
    ap_int<16> StreamingConv_49_biases[80][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_49_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_49_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 2>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 1>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<9, ap_int<24>, ap_int<8>>,  // Quantizer
        80,  // OUT_CH
        80,  // IN_CH
        80,  // OUT_HEIGHT
        80,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_49;
    StreamingConv_49.run<707>(StreamingLineBuffer_53_out0_stream, StreamingConv_49_weights, StreamingConv_49_biases, StreamingConv_49_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_49_out0_stream_0," << StreamingConv_49_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_49_out0_stream_1," << StreamingConv_49_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_7;
    StreamingLineBuffer_52_pixel_7.run<699>(StreamingLineBuffer_52_buffer_stream[6], StreamingLineBuffer_52_out0_stream_prepad[1], StreamingLineBuffer_52_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_1," << StreamingLineBuffer_52_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_buffer_stream_7," << StreamingLineBuffer_52_buffer_stream[7].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        64,  // IN_CH_A
        80,  // IN_CH_B
        2,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_22;
    StreamingConcat_22.run<718>(StreamingConv_46_out0_stream, StreamingConv_49_out0_stream, StreamingConcat_22_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_22_out0_stream_0," << StreamingConcat_22_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_22_out0_stream_1," << StreamingConcat_22_out0_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_52_pixel_8;
    StreamingLineBuffer_52_pixel_8.run<700>(StreamingLineBuffer_52_buffer_stream[7], StreamingLineBuffer_52_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_prepad_0," << StreamingLineBuffer_52_out0_stream_prepad[0].size() << std::endl;
    #endif
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_7;
    BandwidthAdjustDecreaseStreams_7.run<720>(StreamingConcat_22_out0_stream, BandwidthAdjustDecreaseStreams_7_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "BandwidthAdjustDecreaseStreams_7_out0_stream_0," << BandwidthAdjustDecreaseStreams_7_out0_stream[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_52_pad;
    StreamingLineBuffer_52_pad.run<701>(StreamingLineBuffer_52_out0_stream_prepad, StreamingLineBuffer_52_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_0," << StreamingLineBuffer_52_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_1," << StreamingLineBuffer_52_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_2," << StreamingLineBuffer_52_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_3," << StreamingLineBuffer_52_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_4," << StreamingLineBuffer_52_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_5," << StreamingLineBuffer_52_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_6," << StreamingLineBuffer_52_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_7," << StreamingLineBuffer_52_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_52_out0_stream_8," << StreamingLineBuffer_52_out0_stream[8].size() << std::endl;
    #endif
    StreamingReshape <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        80,  // IN_HEIGHT
        80,  // IN_WIDTH
        144,  // IN_CH
        1,  // W_PAR
        1  // CH_PAR
    > StreamingReshape_0;
    StreamingReshape_0.run<722>(BandwidthAdjustDecreaseStreams_7_out0_stream, StreamingReshape_0_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingReshape_0_out0_stream_0," << StreamingReshape_0_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_48_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_48_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_48_weights dim=2 complete
    ap_int<14> StreamingConv_48_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_48_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_48_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<8, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_48;
    StreamingConv_48.run<703>(StreamingLineBuffer_52_out0_stream, StreamingConv_48_weights, StreamingConv_48_biases, StreamingConv_48_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_48_out0_stream_0," << StreamingConv_48_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        921600,  // ITER
        16,  // DATA_PER_WORD
        6400,  // HEIGHT
        1,  // WIDTH
        144,  // CH
        1,  // IN_W_PAR
        1  // IN_CH_PAR
    > StreamToNHWC_1;
    StreamToNHWC_1.run<724>(StreamingReshape_0_out0_stream, global_out_1);
    ap_int<8> StreamingSwish_46_lut[256] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 47, 49, 51, 54, 56, 58, 61, 63, 65, 68, 71, 73, 76, 79, 81, 85, 87, 90, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -5, -5, -6, -7, -7, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10, -9, -8, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_46;
    StreamingSwish_46.run<704>(StreamingConv_48_out0_stream, StreamingSwish_46_lut, StreamingSwish_46_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_46_out0_stream_0," << StreamingSwish_46_out0_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_0;
    StreamingLineBuffer_54_pixel_0.run<708>(StreamingSwish_46_out0_stream[0], StreamingLineBuffer_54_out0_stream_prepad[8], StreamingLineBuffer_54_buffer_stream[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_8," << StreamingLineBuffer_54_out0_stream_prepad[8].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_0," << StreamingLineBuffer_54_buffer_stream[0].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_1;
    StreamingLineBuffer_54_pixel_1.run<709>(StreamingLineBuffer_54_buffer_stream[0], StreamingLineBuffer_54_out0_stream_prepad[7], StreamingLineBuffer_54_buffer_stream[1]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_7," << StreamingLineBuffer_54_out0_stream_prepad[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_1," << StreamingLineBuffer_54_buffer_stream[1].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_2;
    StreamingLineBuffer_54_pixel_2.run<710>(StreamingLineBuffer_54_buffer_stream[1], StreamingLineBuffer_54_out0_stream_prepad[6], StreamingLineBuffer_54_buffer_stream[2]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_6," << StreamingLineBuffer_54_out0_stream_prepad[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_2," << StreamingLineBuffer_54_buffer_stream[2].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_3;
    StreamingLineBuffer_54_pixel_3.run<711>(StreamingLineBuffer_54_buffer_stream[2], StreamingLineBuffer_54_out0_stream_prepad[5], StreamingLineBuffer_54_buffer_stream[3]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_5," << StreamingLineBuffer_54_out0_stream_prepad[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_3," << StreamingLineBuffer_54_buffer_stream[3].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_4;
    StreamingLineBuffer_54_pixel_4.run<712>(StreamingLineBuffer_54_buffer_stream[3], StreamingLineBuffer_54_out0_stream_prepad[4], StreamingLineBuffer_54_buffer_stream[4]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_4," << StreamingLineBuffer_54_out0_stream_prepad[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_4," << StreamingLineBuffer_54_buffer_stream[4].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_5;
    StreamingLineBuffer_54_pixel_5.run<713>(StreamingLineBuffer_54_buffer_stream[4], StreamingLineBuffer_54_out0_stream_prepad[3], StreamingLineBuffer_54_buffer_stream[5]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_3," << StreamingLineBuffer_54_out0_stream_prepad[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_5," << StreamingLineBuffer_54_buffer_stream[5].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_6;
    StreamingLineBuffer_54_pixel_6.run<714>(StreamingLineBuffer_54_buffer_stream[5], StreamingLineBuffer_54_out0_stream_prepad[2], StreamingLineBuffer_54_buffer_stream[6]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_2," << StreamingLineBuffer_54_out0_stream_prepad[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_6," << StreamingLineBuffer_54_buffer_stream[6].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_7;
    StreamingLineBuffer_54_pixel_7.run<715>(StreamingLineBuffer_54_buffer_stream[6], StreamingLineBuffer_54_out0_stream_prepad[1], StreamingLineBuffer_54_buffer_stream[7]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_1," << StreamingLineBuffer_54_out0_stream_prepad[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_buffer_stream_7," << StreamingLineBuffer_54_buffer_stream[7].size() << std::endl;
    #endif
    StreamingWindowSelector <
        std::array<ap_int<8>, 1>,  // TWord
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1  // CH_PAR
    > StreamingLineBuffer_54_pixel_8;
    StreamingLineBuffer_54_pixel_8.run<716>(StreamingLineBuffer_54_buffer_stream[7], StreamingLineBuffer_54_out0_stream_prepad[0]);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_prepad_0," << StreamingLineBuffer_54_out0_stream_prepad[0].size() << std::endl;
    #endif
    StreamingPad <
        std::array<ap_int<8>, 1>,  // TWord
        ap_int<8>,  // TData
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
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
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_54_pad;
    StreamingLineBuffer_54_pad.run<717>(StreamingLineBuffer_54_out0_stream_prepad, StreamingLineBuffer_54_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_0," << StreamingLineBuffer_54_out0_stream[0].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_1," << StreamingLineBuffer_54_out0_stream[1].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_2," << StreamingLineBuffer_54_out0_stream[2].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_3," << StreamingLineBuffer_54_out0_stream[3].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_4," << StreamingLineBuffer_54_out0_stream[4].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_5," << StreamingLineBuffer_54_out0_stream[5].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_6," << StreamingLineBuffer_54_out0_stream[6].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_7," << StreamingLineBuffer_54_out0_stream[7].size() << std::endl;
    #endif
    #ifndef __SYNTHESIS__
    std::cout << "StreamingLineBuffer_54_out0_stream_8," << StreamingLineBuffer_54_out0_stream[8].size() << std::endl;
    #endif
    ap_int<8> StreamingConv_50_weights[4096][1][9];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_50_weights dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_50_weights dim=2 complete
    ap_int<14> StreamingConv_50_biases[64][1][1];
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_50_biases dim=3 complete
    #pragma HLS ARRAY_RESHAPE variable=StreamingConv_50_biases dim=2 complete
    StreamingConv <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<7, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        64,  // IN_CH
        40,  // OUT_HEIGHT
        40,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_50;
    StreamingConv_50.run<719>(StreamingLineBuffer_54_out0_stream, StreamingConv_50_weights, StreamingConv_50_biases, StreamingConv_50_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConv_50_out0_stream_0," << StreamingConv_50_out0_stream[0].size() << std::endl;
    #endif
    ap_int<8> StreamingSwish_47_lut[256] = {0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 41, 42, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0};
    StreamingLUT <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        256,  // LUT_SIZE
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        64,  // IN_CH
        1,  // CH_PAR
        1  // W_PAR
    > StreamingSwish_47;
    StreamingSwish_47.run<721>(StreamingConv_50_out0_stream, StreamingSwish_47_lut, StreamingSwish_47_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingSwish_47_out0_stream_0," << StreamingSwish_47_out0_stream[0].size() << std::endl;
    #endif
    StreamingConcatChannel <
        std::array<ap_int<8>, 1>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        DequantQuantPo2<0, ap_int<8>, ap_int<8>>,  // Quantizer
        40,  // IN_HEIGHT
        40,  // IN_WIDTH
        128,  // IN_CH_A
        64,  // IN_CH_B
        1,  // W_PAR
        1  // CH_PAR
    > StreamingConcat_23;
    StreamingConcat_23.run<723>(StreamingConcat_21_out0_stream, StreamingSwish_47_out0_stream, StreamingConcat_23_out0_stream);
    #ifndef __SYNTHESIS__
    std::cout << "StreamingConcat_23_out0_stream_0," << StreamingConcat_23_out0_stream[0].size() << std::endl;
    #endif
    StreamToNHWC <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        307200,  // ITER
        16,  // DATA_PER_WORD
        40,  // HEIGHT
        40,  // WIDTH
        192,  // CH
        1,  // IN_W_PAR
        1  // IN_CH_PAR
    > StreamToNHWC_2;
    StreamToNHWC_2.run<725>(StreamingConcat_23_out0_stream, global_out);
}
