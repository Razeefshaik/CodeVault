//
// Created by RAZEEF on 03-03-2026.
//
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read the number of test cases
    int t = inf.readInt(1, 10000, "t");
    inf.readEoln();

    int sum_n = 0;

    for (int test = 1; test <= t; test++) {
        // We can pass the test case number to the variable names for clearer error messages
        int n = inf.readInt(1, 100000, "n");
        inf.readSpace();
        int k = inf.readInt(1, n, "k");
        inf.readSpace();
        int m = inf.readInt(1, n, "m");
        inf.readEoln();

        sum_n += n;
        // Ensure the sum of n doesn't exceed the global limit
        ensuref(sum_n <= 100000, "Sum of n exceeded 10^5 in test %d!", test);

        for (int i = 0; i < n; i++) {
            inf.readInt(1, 100000, "a_i");
            if (i < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}