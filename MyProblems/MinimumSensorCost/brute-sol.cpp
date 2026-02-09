//
// Created by RAZEEF on 14-01-2026.
//
/**
 * Brute Force Solution for "Minimum Sensor Cost"
 * Time Complexity: O(N * K)
 * Expected Verdict: Time Limit Exceeded (TLE) on max tests
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Optimizing I/O operations is good practice, but this algorithm is slow by design.
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    vector<long long> sensors(k);
    for (int i = 0; i < k; i++) {
        cin >> sensors[i];
    }

    long long total_cost = 0;

    // Outer Loop: Iterate through every sensor
    for (int j = 0; j < k; j++) {
        long long current_sensor_cost = 0;

        // Inner Loop: Iterate through every room for the current sensor
        for (int i = 0; i < n; i++) {
            current_sensor_cost += abs(rooms[i] - sensors[j]);
        }

        total_cost += current_sensor_cost;
    }

    cout << total_cost << endl;

    return 0;
}