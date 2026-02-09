//
// Created by RAZEEF on 13-01-2026.
//
#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Initializes the random generator with arguments
    registerGen(argc, argv, 1);

    // Prepare arguments from command line
    // Usage: gen [n] [k] [max_value]
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int max_val = atoi(argv[3]);

    println(n, k);

    // Generate Rooms
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rnd.next(1, max_val);
    println(a); // testlib helper to print arrays

    // Generate Sensors
    vector<int> f(k);
    for (int i = 0; i < k; i++) f[i] = rnd.next(1, max_val);
    println(f);

    return 0;
}