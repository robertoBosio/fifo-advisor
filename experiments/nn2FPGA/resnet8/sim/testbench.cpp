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
extern void resnet8(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out);
int main(int argc, char** argv)
{
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in;
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out;
    for (size_t i = 0; i < 192 * 3; i++) {
        ap_axiu<128, 0, 0, 0> tmp;
        for (size_t j = 0; j < 16; j++) {
            tmp.data.range((j+1)*8-1, j*8) = (unsigned char)(i*16 + j);
        }
        global_in.write(tmp);
    }
    resnet8(global_in, global_out);
    resnet8(global_in, global_out);
    resnet8(global_in, global_out);
    for (size_t i = 0; i < 1 * 3; i++) {
        ap_axiu<128, 0, 0, 0> tmp = global_out.read();
    }
    return 0;
}