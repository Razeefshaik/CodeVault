//
// Created by RAZEEF on 14-01-2026.
//
#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read N and K. Range: [1, 200000]
    int n = inf.readInt(1, 200000, "n");
    inf.readSpace();
    // K must be <= N
    int k = inf.readInt(1, n, "k");
    inf.readEoln();

    // Read Rooms (n integers)
    // readInts(count, min_val, max_val, variable_name)
    inf.readInts(n, 1, 1000000000, "a");
    inf.readEoln();

    // Read Sensors (k integers)
    inf.readInts(k, 1, 1000000000, "f");
    inf.readEoln();

    inf.readEof(); // Ensure file ends here
    return 0;
}