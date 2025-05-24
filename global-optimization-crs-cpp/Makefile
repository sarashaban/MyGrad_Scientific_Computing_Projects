CXX = g++
CXXFLAGS = -std=c++17 -fopenmp -O2
TARGET = sparse_crs

all: $(TARGET)

$(TARGET): src/CRS.cpp src/SparseMatrix.cpp
	$(CXX) $(CXXFLAGS) -Iinclude src/CRS.cpp src/SparseMatrix.cpp -o $(TARGET)

clean:
	rm -f $(TARGET) *.o crs_stat.txt