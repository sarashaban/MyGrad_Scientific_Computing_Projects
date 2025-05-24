
#include "SparseMatrix.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <omp.h>
#include <map>

SparseMatrix::SparseMatrix(int rows, int cols) : nr(rows), nc(cols), nel(0) {
    ia.resize(nr + 1, 0);
}

void SparseMatrix::setData(const std::vector<int>& ia_, const std::vector<int>& ja_, const std::vector<double>& a_) {
    ia = ia_;
    ja = ja_;
    a = a_;
    nel = a.size();
}

void SparseMatrix::printRow(int row) const {
    std::cout << "Row " << row << ": ";
    for (int k = ia[row]; k < ia[row + 1]; ++k)
        std::cout << "(Col " << ja[k] << ": " << a[k] << ") ";
    std::cout << "\n";
}

void SparseMatrix::print() const {
    for (int i = 0; i < nr; ++i)
        printRow(i);
}

void SparseMatrix::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    out << nr << " " << nc << " " << nel << "\n";
    for (size_t i = 0; i < ia.size(); ++i) out << ia[i] << " ";
    out << "\n";
    for (size_t i = 0; i < ja.size(); ++i) out << ja[i] << " ";
    out << "\n";
    for (size_t i = 0; i < a.size(); ++i) out << a[i] << " ";
    out << "\n";
}

void SparseMatrix::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    in >> nr >> nc >> nel;
    ia.resize(nr + 1);
    for (int i = 0; i < nr + 1; ++i) in >> ia[i];
    ja.resize(nel);
    for (int i = 0; i < nel; ++i) in >> ja[i];
    a.resize(nel);
    for (int i = 0; i < nel; ++i) in >> a[i];
}

SparseMatrix operator*(const SparseMatrix& mat, double scalar) {
    SparseMatrix result = mat;
    for (auto& val : result.a)
        val *= scalar;
    return result;
}

SparseMatrix operator+(const SparseMatrix& a, const SparseMatrix& b) {
    if (a.nr != b.nr || a.nc != b.nc)
        throw std::runtime_error("Dimension mismatch in SparseMatrix +");

    SparseMatrix result(a.nr, a.nc);
    result.ia[0] = 0;

    for (int i = 0; i < a.nr; ++i) {
        std::map<int, double> row_data;

        for (int k = a.ia[i]; k < a.ia[i + 1]; ++k)
            row_data[a.ja[k]] += a.a[k];

        for (int k = b.ia[i]; k < b.ia[i + 1]; ++k)
            row_data[b.ja[k]] += b.a[k];

        for (const auto& p : row_data) {
            if (p.second != 0.0) {
                result.ja.push_back(p.first);
                result.a.push_back(p.second);
            }
        }
        result.ia[i + 1] = result.ja.size();
    }

    result.nel = result.a.size();
    return result;
}

SparseMatrix operator-(const SparseMatrix& a, const SparseMatrix& b) {
    return a + (b * -1.0);
}

void SparseMatrix::printToFile(const std::string& filename) const {
    std::ofstream out(filename, std::ios::app); // append mode
    for (int i = 0; i < nr; ++i) {
        for (int k = ia[i]; k < ia[i + 1]; ++k) {
            out << i << " " << ja[k] << " " << a[k] << "\n";
        }
    }
    out << "\n";
}

