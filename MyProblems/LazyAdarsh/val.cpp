//
// Created by RAZEEF on 01-02-2026.
//
#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 100, "t");
    inf.readEoln();

    long long sum_nm = 0;

    for (int test = 1; test <= t; test++) {
        setTestCase(test);
        int n = inf.readInt(2, 700, "n");
        inf.readSpace();
        int m = inf.readInt(2, 700, "m");
        inf.readEoln();

        sum_nm += (long long)n * m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                inf.readInt(1, 1000000000, "A_ij");
                if (j < m - 1) inf.readSpace();
            }
            inf.readEoln();
        }
    }

    ensuref(sum_nm <= 500000, "Sum of N*M over all test cases exceeds 300,000");

    inf.readEof();
    return 0;
}