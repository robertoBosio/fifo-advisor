# script.tcl robust path handling for include dirs

set type "streaming_group-sa"

# Resolve paths relative to this script's directory
set script_dir  [file dirname [file normalize [info script]]]
set inc_dir     [file normalize [file join $script_dir ../include]]
set data_dir    [file normalize [file join $script_dir data]]
set kernel_cpp  [file normalize [file join $script_dir kernels/kernel_${type}.cpp]]
set tb_cpp      [file normalize [file join $script_dir testbenches/testbench_original.cpp]]

# (Optional) keep builds local to the benchmark folder
set proj_name   "resnet20_${type}_HLS_project"
set sol_name    "solution_0"

# Create/clean project & solution
open_project -reset $proj_name
set_top resnet20
add_files $kernel_cpp  -cflags [format {-I%s} $inc_dir]
add_files -tb $tb_cpp  -cflags [format {-I%s} $inc_dir]
add_files -tb $data_dir

open_solution -reset $sol_name
set_part xczu9eg-ffvb1156-2-e
create_clock -period 5

# Your compile settings
config_compile -pipeline_style flp

# Run the usual flow (spellings below are the canonical commands)
#csim_design -argv "data/global_in.txt data/global_in_1.txt data/global_out.txt"
csynth_design
#cosim_design -argv "data/global_in.txt data/global_in_1.txt data/global_out.txt"
export_design -flow syn

exit

