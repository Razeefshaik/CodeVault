//
// Created by RAZEEF on 17-01-2026.
//
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 1. Check N and M
    // N is strictly limited to 500 to force O(N^3) solution
    int n = inf.readInt(2, 500, "n");
    inf.readSpace();
    // M can go up to 500,000
    int m = inf.readInt(1, 500000, "m");
    inf.readEoln();

    // 2. Check Rudeness Factors
    inf.readInts(n, 1, 1000000, "r");
    inf.readEoln();

    // 3. Check Edges
    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        int w = inf.readInt(1, 1000000000, "w"); // Max weight 10^9
        inf.readEoln();

        // Critical Check: No self-loops allowed
        ensuref(u != v, "Self-loop detected: node %d to %d", u, v);
    }

    inf.readEof();
    return 0;
}