#!/bin/bash

# Copy script from another directory
# Modify testbench to do 3 iterations
# Run vitis_hls cosim to retrieve II

#export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/:$LD_LIBRARY_PATH
#export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libc.so.6:/usr/lib/x86_64-linux-gnu/libudev.so.1


# Create the files for lightningsim
python3 ../../extract_move_reshape_mems.py --func resnet8 --tb testbench_light.cpp kernel.cpp kernel_light.cpp

# Change script.tcl to use kernel_light.cpp and testbench_light.cpp
# Run Vitis to generate the solution
vitis_hls -f script.tcl

# Create the max_depth.csv file from the log

# Run the DSE
python3 ../../DSE.py --solution resnet8_light_HLS_project/solution_0/ --depths-file max_depth.csv