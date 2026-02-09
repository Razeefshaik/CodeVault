#include "testlib.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Usage: gen [N] [K_Mode] [MaxQty] [MaxCost] [RangeWidth]
    int n = atoi(argv[1]);
    int k_mode = atoi(argv[2]); // 0=Random K, 1=Worst Case K (Half Capacity)
    int max_q = atoi(argv[3]);
    int max_c = atoi(argv[4]);
    long long range_width = atoll(argv[5]);

    println(1);

    // Generate Quantities
    vector<int> qtys(n);
    long long total_capacity = 0;
    for(int i = 0; i < n; i++) {
        qtys[i] = rnd.next(1, max_q);
        total_capacity += qtys[i];
    }

    // Determine K
    int k;
    if (k_mode == 1) k = total_capacity / 2; // Max combinations
    else k = rnd.next(1, (int)total_capacity);

    println(n, k);

    vector<long long> costs(n);
    for(int i = 0; i < n; i++) costs[i] = rnd.next(1, max_c);
    println(costs);

    println(qtys);

    // Generate Range
    double avg_cost = 0;
    for(long long c : costs) avg_cost += c;
    avg_cost /= n;
    long long estimated_sum = (long long)(avg_cost * k);

    long long min_cost = max(1LL, estimated_sum - rnd.next(0LL, range_width / 2));
    long long max_cost = min_cost + range_width;

    println(min_cost, max_cost);

    return 0;
}