# Date : Thu Nov 28 01:14:50 EST 2013 & Modified May 2025

CXX = g++
CXXFLAGS = -std=c++17 -fopenmp -O2
TARGET = sparse_matrix

all: $(TARGET)

$(TARGET): src/main.cpp src/SparseMatrix.cpp
	$(CXX) $(CXXFLAGS) -Iinclude src/main.cpp src/SparseMatrix.cpp -o $(TARGET)

clean:
	rm -f $(TARGET) *.o output_matrix.txt