//
// Created by RAZEEF on 17-01-2026.
//
#include "testlib.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize the generator with command line arguments
    registerGen(argc, argv, 1);

    // Arguments: [n] [m] [max_rudeness] [max_weight]
    // Example: gen 500 500000 1000000 1000000
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int max_r = atoi(argv[3]);
    int max_w = atoi(argv[4]);

    println(n, m);

    // 1. Generate Rudeness Factors
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = rnd.next(1, max_r);
    }
    println(r);

    // 2. Generate Edges
    // Since we want a "Dense" graph (N=500, M=500,000), we just pick random pairs.
    // Multiple edges between u and v are allowed by the problem statement.
    for (int i = 0; i < m; i++) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);

        // Ensure no self-loops (u != v)
        while (u == v) {
            v = rnd.next(1, n);
        }

        int w = rnd.next(1, max_w);
        println(u, v, w);
    }

    return 0;
}