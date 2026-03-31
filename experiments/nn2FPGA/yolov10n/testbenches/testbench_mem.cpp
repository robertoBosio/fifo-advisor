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
#include "utils/testbench_utils.hpp"
extern void yolov10n(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out_2, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out_1);
int main(int argc, char** argv)
{
    std::string file_global_in = argv[1];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in;
    std::string file_global_out_2 = argv[2];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out_2;
    std::string file_global_out = argv[3];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out;
    std::string file_global_out_1 = argv[4];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out_1;
    txt_to_hls_stream<ap_axiu<128, 0, 0, 0>, ap_int<8>, char>(file_global_in, global_in, 16);
    yolov10n(global_in, global_out_2, global_out, global_out_1);
    return 0;
}