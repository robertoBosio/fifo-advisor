# script.tcl robust path handling for include dirs

# Resolve paths relative to this script's directory
set script_dir  [file dirname [file normalize [info script]]]
set inc_dir     [file normalize [file join $script_dir ../../include]]
set kernel_cpp  [file normalize [file join $script_dir kernel_light.cpp]]
set tb_cpp      [file normalize [file join $script_dir testbench_light.cpp]]

# (Optional) keep builds local to the benchmark folder
set proj_name   "mbv2_light_HLS_project"
set sol_name    "solution_0"

# Create/clean project & solution
open_project -reset $proj_name
set_top mobilenet_v2
add_files $kernel_cpp  -cflags [format {-I%s} $inc_dir]
add_files -tb $tb_cpp  -cflags [format {-I%s} $inc_dir]

open_solution -reset $sol_name
set_part xck26-sfvc784-2LV-c
create_clock -period 5

# Your compile settings
config_compile -pipeline_style flp

# Run the usual flow (spellings below are the canonical commands)
csim_design
csynth_design
#cosim_design

exit

