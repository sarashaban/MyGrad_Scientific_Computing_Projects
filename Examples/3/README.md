*Using Octree for neighbor searches in 3D molecular data*


In quantum chemistry, it's often necessary to find neighboring atoms within a cutoff distance and speed up this process, especially for large molecules or dense systems.


Idea: Using an Octree to partition 3D space so that only atoms in nearby cells are searched.


g++ -std=c++11 -O2 find_nearest_neighbor.cpp -o neighbor_search
./neighbor_search


Result:

Neighbors of Zr atom (Zr) within 2.5 angstrom
  C at (1.8202, 1.07229, 0.81295)
  C at (0.98251, 0.83039, 1.9513)
  C at (1.66216, -1.31544, -0.58841)
  C at (0.79599, -2.11283, 0.22862)
  
