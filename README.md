# FIFOAdvisor

FIFOAdvisor is a framework that optimizes FIFO depths in HHigh Level Synthesis designs, specifically targeting Vitis HLS. It can search for optimal FIFO depths to minimize latency and resource usage, and also size them to avoid deadlocks.

## Quick Start

Install with `uv`:

```bash
uv install git+https://github.com/sharc-lab/fifo-advisor.git
```

Install with `pip`:

```bash
pip install git+https://github.com/sharc-lab/fifo-advisor.git
```

Run FIFOAdvisor:

```bash
fifo-opt --help
```
