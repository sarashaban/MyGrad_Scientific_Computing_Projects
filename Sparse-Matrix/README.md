# Sparse Matrix Project For Scientific Computing Course Written in C++

This project demonstrates a modular, object-oriented C++ implementation of a sparse matrix class using the Compressed Row Storage (CRS) format.

## Features

- Sparse matrix representation and addition
- OpenMP parallelism for matrix addition
- Ready for testing

## Build

make

## Run

./sparse_matrix

## Test

g++ -std=c++17 -fopenmp -Iinclude test/test_sparse.cpp src/SparseMatrix.cpp -o test_sparse

./test_sparse
