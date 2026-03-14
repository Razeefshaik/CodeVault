//
// Created by RAZEEF on 03-03-2026.
//
#include "testlib.h"
#include <vector>
#include <set>

using namespace std;

// Generate a random test case
void gen_random(int n) {
    int k = rnd.next(1, n);
    int m = rnd.next(1, n);
    cout << n << " " << k << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << rnd.next(1, min(100000, n * 2)) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

// Generate an array designed to have EXACTLY k distinct elements repeating m times
void gen_exact(int n) {
    int k = rnd.next(1, min(n, 100)); // Keep k small so we can hit the m threshold
    int m = rnd.next(1, n / k);       // Ensure n is large enough to hold k*m elements

    cout << n << " " << k << " " << m << "\n";

    // Pick k distinct random numbers
    vector<int> alphabet;
    set<int> st;
    while(st.size() < k) {
        int val = rnd.next(1, 100000);
        if(!st.count(val)) {
            st.insert(val);
            alphabet.push_back(val);
        }
    }

    for (int i = 0; i < n; i++) {
        // Only pick elements from our exact alphabet
        cout << alphabet[rnd.next(0, k - 1)] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = atoi(argv[2]);
    int type = atoi(argv[3]);

    cout << t << "\n";

    // Distribute N across T test cases so sum of N = 100,000
    int remaining_n = 100000;

    for (int i = 1; i <= t; i++) {
        int max_n_for_this_test = remaining_n / (t - i + 1);
        int n = rnd.next(1, max_n_for_this_test);
        if (i == t) n = remaining_n; // Give the last test case the rest

        remaining_n -= n;

        if (type == 1) {
            gen_random(n);
        } else {
            gen_exact(n);
        }
    }

    return 0;
}