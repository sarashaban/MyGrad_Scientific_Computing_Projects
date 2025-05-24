#ifndef SPARSEMATRIX_HPP
#define SPARSEMATRIX_HPP

#include <vector>
#include <map>
#include <string>

class SparseMatrix {
public:
    int nr, nc, nel;
    std::vector<int> ia, ja; 
    std::vector<double> a;

    SparseMatrix(int rows = 0, int cols = 0); 
    void setData(const std::vector<int>& ia_, const std::vector<int>& ja_, const std::vector<double>& a_);
    void printRow(int row) const;
    void print() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printToFile(const std::string& filename) const;
};

// declarations
SparseMatrix operator*(const SparseMatrix& mat, double scalar);
SparseMatrix operator+(const SparseMatrix& a, const SparseMatrix& b); 
SparseMatrix operator-(const SparseMatrix& a, const SparseMatrix& b); 

#endif

