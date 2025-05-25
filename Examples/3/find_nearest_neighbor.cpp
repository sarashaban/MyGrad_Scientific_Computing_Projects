#include <iostream>
#include <vector>
#include <cmath>

struct Atom {
    std::string element;
    double x, y, z;
};

struct OctreeNode {
    double center[3];             // center of the cube
    double size;                  // side length of the cube
    std::vector<Atom> atoms;      // atoms stored in this node
    OctreeNode* children[8] = {}; // pointers to children

    
    OctreeNode(double cx, double cy, double cz, double s) {
        center[0] = cx; center[1] = cy; center[2] = cz; 
        size = s;
    }   

    // insert an atom into this node
    void insert(const Atom& atom, int depth = 0) {
        atoms.push_back(atom);
    }   

    // search for neighbors within cutoff radius
    void findNeighbors(const Atom& query, double cutoff, std::vector<Atom>& neighbors) const {
        for (const auto& atom : atoms) {
            double dx = query.x - atom.x;
            double dy = query.y - atom.y;
            double dz = query.z - atom.z;
            double distance = std::sqrt(dx*dx + dy*dy + dz*dz);

            if (distance <= cutoff && distance > 1e-6) {
                neighbors.push_back(atom);
            }   
        }   
    }   
};

int main() {
    std::vector<Atom> molecule = { 

        {"C",  1.191010,  2.127020,  0.080860},
        {"C",  0.022440,  2.545960,  0.775470},
        {"C",  1.820200,  1.072290,  0.812950},
        {"H",  1.549820,  2.547710, -0.849500},
        {"C", -0.105420,  1.748300,  1.933360},
        {"H", -0.643140,  3.344130,  0.476190},
        {"C",  0.982510,  0.830390,  1.951300},
        {"H", -0.882270,  1.829570,  2.682470},
        {"H",  1.166530,  0.092170,  2.721610},
        {"C", -0.269380, -1.824180, -1.779870},
        {"C",  0.970920, -1.130550, -1.827260},
        {"C", -0.375210, -2.437890, -0.511300},
        {"H", -0.998160, -1.883940, -2.577410},
        {"C",  1.662160, -1.315440, -0.588410},
        {"H",  1.336580, -0.558310, -2.669950},
        {"C",  0.795990, -2.112830,  0.228620},
        {"H", -1.192010, -3.059020, -0.168390},
        {"H",  1.010950, -2.442410,  1.237250},
        {"Si", 3.027430, -0.198120,  0.099290},
        {"C",  4.003080, -1.054190,  1.443260},
        {"H",  4.591620, -1.878690,  1.028750},
        {"H",  4.693980, -0.354500,  1.924000},
        {"H",  3.353520, -1.467270,  2.221420},
        {"C",  4.055500,  0.540540, -1.275640},
        {"H",  4.749290,  1.289290, -0.880790},
        {"H",  4.646590, -0.232950, -1.775840},
        {"H",  3.434850,  1.028490, -2.033960},
        {"Zr", -0.304390, 0.104180, -0.047760}
    };


    // 10 ang cube centered at origin
    OctreeNode root(0.0, 0.0, 0.0, 10.0);

    for (const auto& atom : molecule) {
        root.insert(atom);
    }

    std::vector<Atom> neighbors;
    root.findNeighbors(molecule[27], 2.5, neighbors);

    std::cout << "Neighbors of Zr atom (" << molecule[27].element << ") within 2.5 angstrom:\n";
    for (const auto& atom : neighbors) {
        std::cout << "  " << atom.element << " at (" << atom.x << ", " << atom.y << ", " << atom.z << ")\n";
    }

    return 0;
}
                                                                                                                                                                                                   
