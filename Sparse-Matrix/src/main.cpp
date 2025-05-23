#include "SparseMatrix.hpp"
#include <iostream>

int main() {
    SparseMatrix A(3, 3), B(3, 3), C(3, 3);
    A.setData({0, 0, 2, 2}, {0, 1}, {5.0, -7.0});
    B.setData({0, 1, 2, 4}, {1, 1, 0, 2}, {3.0, -6.0, 4.0, -3.0});
    C.setData({0, 0, 0, 1}, {1}, {8.0});

    SparseMatrix D = A + B + C;
    D.print();
    D.saveToFile("output_matrix.txt");

    return 0;
}