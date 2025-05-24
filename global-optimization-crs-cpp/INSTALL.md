# Installation Instructions

## Dependencies

- GCC with OpenMP support
- Make
- Python

## Building

make clean
make

## Running

Run the compiled optimizer:

./crs

Output:
- crs_stat.txt : optimization summary (min/max/mean per iteration)
- MyMatrix.data€”:  full cloud for 2000 iterations

## Plotting

python plot_crs_cloud_evolution.py

