# Sparse Matrix Project For Scientific Computing Course Written in C++


Originally assigned as a Fortran 90 homework, this C++ version was developed upon request to reflect similar.


## Features

- Sparse matrix representation and addition
- OpenMP parallelism for matrix addition

## Build

make

## Run

./sparse_matrix

## Test

g++ -std=c++17 -fopenmp -Iinclude test/test_sparse.cpp src/SparseMatrix.cpp -o test_sparse

./test_sparse
