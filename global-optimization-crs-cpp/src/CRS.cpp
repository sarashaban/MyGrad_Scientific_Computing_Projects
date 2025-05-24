#include "SparseMatrix.hpp"
#include "SparsePoint.hpp"
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <algorithm>

double Function(const SparseMatrix& x) {
    double x0 = 0.0, x1 = 0.0;
    for (size_t i = 0; i < x.ja.size(); ++i) {
        if (x.ja[i] == 0) x0 = x.a[i];
        if (x.ja[i] == 1) x1 = x.a[i];
    }
    return 100.0 * (x1 - x0 * x0) * (x1 - x0 * x0) +
           (6.4 * (x1 - 0.5) * (x1 - 0.5) - x0 - 0.6) * (6.4 * (x1 - 0.5) * (x1 - 0.5) - x0 - 0.6);
}

SparseMatrix generate_random_sparse_point(int dim, std::default_random_engine& gen) {
    std::uniform_real_distribution<double> dist(-5.0, 5.0);
    SparseMatrix x(1, dim);
    std::vector<int> ja; 
    std::vector<double> a;

    for (int j = 0; j < dim; ++j) {
        double val = dist(gen);
        if (std::abs(val) > 1e-6) {
            ja.push_back(j);
            a.push_back(val);
        }   
    }   
    x.setData({0, static_cast<int>(ja.size())}, ja, a); 
    return x;
}

int main() {
    int N = 50, Nvar = 2, MaxIter = 2000;
    std::vector<SparsePoint> cloud;
    std::default_random_engine gen(11988);

    for (int i = 0; i < N; ++i) {
        SparseMatrix x = generate_random_sparse_point(Nvar, gen);
        double f = Function(x);
        cloud.emplace_back(x, f); 
    }   

    std::ofstream stat_out("crs_stat.txt");
    std::ofstream matrix_out("MatrixA.data");

    for (int iter = 0; iter < MaxIter; ++iter) {
        std::uniform_int_distribution<int> dist(0, N - 1); 
        SparseMatrix R1 = cloud[dist(gen)].coords;
        SparseMatrix R2 = cloud[dist(gen)].coords;
        SparseMatrix R3 = cloud[dist(gen)].coords;

        SparseMatrix G = R1 + R2; 
        SparseMatrix P = G * 2.0 - R3; 

        double x0 = 0.0, x1 = 0.0;
        for (size_t i = 0; i < P.ja.size(); ++i) {
            if (P.ja[i] == 0) x0 = P.a[i];
            if (P.ja[i] == 1) x1 = P.a[i];
        }   

        if (std::abs(x0) <= 5 && std::abs(x1) <= 5) {
            double fP = Function(P);
            auto it = std::max_element(cloud.begin(), cloud.end(), [](const SparsePoint& a, const SparsePoint& b) {
                return a.fval < b.fval;
            });

            if (fP < it->fval) {
                *it = SparsePoint(P, fP);
            }
        }

        double minf = cloud[0].fval, maxf = cloud[0].fval, sumf = 0.0;
        for (const auto& pt : cloud) {
            minf = std::min(minf, pt.fval);
            maxf = std::max(maxf, pt.fval);
            sumf += pt.fval;
        }
        stat_out << iter << " " << minf << " " << maxf << " " << sumf / cloud.size() << "\n";

        // Write current cloud to MatrixA.data
        for (const auto& pt : cloud) {
            double x0 = 0.0, x1 = 0.0;
            for (size_t i = 0; i < pt.coords.ja.size(); ++i) {
                if (pt.coords.ja[i] == 0) x0 = pt.coords.a[i];
                if (pt.coords.ja[i] == 1) x1 = pt.coords.a[i];
            }
            matrix_out << x0 << " " << x1 << " " << pt.fval << "\n";
        }
    }

    stat_out.close();
    matrix_out.close();
    return 0;
}

