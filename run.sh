docker run --rm -it \
  -v "$(pwd)":/workspace \
  -v /tools/Xilinx:/tools/Xilinx \
  -e VITIS_HLS_SETTINGS=/tools/Xilinx/Vitis_HLS/2023.2/.settings64-Vitis_HLS.sh \
  -w /workspace \
  fifo-advisor-dev

