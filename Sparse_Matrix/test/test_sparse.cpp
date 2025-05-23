#include "SparseMatrix.hpp"
#include <cassert>

int main() {
    SparseMatrix A(2, 2), B(2, 2);
    A.setData({0, 1, 2}, {0, 1}, {1.0, 2.0});
    B.setData({0, 1, 2}, {0, 1}, {3.0, 4.0});
    SparseMatrix C = A + B;
    C.print();
    return 0;
}

