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
extern void yolov5nu(hls::stream<ap_axiu<128, 0, 0, 0>>& global_in, hls::stream<ap_axiu<128, 0, 0, 0>>& global_in_1, hls::stream<ap_axiu<128, 0, 0, 0>>& global_out);
int main(int argc, char** argv)
{
    std::string file_global_in = argv[1];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in;
    std::string file_global_in_1 = argv[2];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in_1;
    std::string file_global_out = argv[3];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out;
    txt_to_hls_stream<ap_axiu<128, 0, 0, 0>, ap_int<8>, char>(file_global_in, global_in, 16);
    txt_to_hls_stream<ap_axiu<128, 0, 0, 0>, ap_uint<32>, unsigned int>(file_global_in_1, global_in_1, 4);
    yolov5nu(global_in, global_in_1, global_out);
    hls_stream_to_txt<ap_axiu<128, 0, 0, 0>, ap_int<8>, char>(file_global_out, global_out, 16, {1, 8400, 144});
    std::string expected_output_file = argv[3];
    std::ifstream output_file(file_global_out);
    std::ifstream expected_file(expected_output_file);
    std::string output_line;
    std::string expected_line;
    int line_number = 1;
    bool success = true;
    while (std::getline(output_file, output_line) && std::getline(expected_file, expected_line)) {
        if (output_line != expected_line) {
            std::cout << "Mismatch at line " << line_number << ": expected '" << expected_line << "', got '" << output_line << "'" << std::endl;
            success = false;
        }
        line_number++;
    }
    output_file.close();
    expected_file.close();
    if (success) {
        std::cout << "Test passed: output matches expected results." << std::endl;
    } else {
        std::cout << "Test failed: output does not match expected results." << std::endl;
    }
    return success ? 0 : 1;
    return 0;
}