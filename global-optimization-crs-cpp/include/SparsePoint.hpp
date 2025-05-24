#ifndef SPARSEPOINT_HPP
#define SPARSEPOINT_HPP

#include "SparseMatrix.hpp"

struct SparsePoint {
    SparseMatrix coords;
    double fval;

    SparsePoint() : fval(0.0) {}
    SparsePoint(const SparseMatrix& coords_, double fval_) : coords(coords_), fval(fval_) {}
};

#endif