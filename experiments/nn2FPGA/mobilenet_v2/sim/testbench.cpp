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
extern void mobilenet_v2(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out);
int main(int argc, char** argv)
{
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in;
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out;
    for (int i = 0; i < 9408 * 3; i++)
    {
        ap_axiu<128, 0, 0, 0> tmp;
        global_in.write(tmp);
    }
    mobilenet_v2(global_in, global_out);
    mobilenet_v2(global_in, global_out);
    mobilenet_v2(global_in, global_out);
    for (int i = 0; i < 63 * 3; i++)
    {
        ap_axiu<128, 0, 0, 0> tmp = global_out.read();
    }
    return 0;
}