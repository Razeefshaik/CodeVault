// --- FIX FOR WINDOWS WARNING ---
#ifdef _MSC_VER
#pragma warning(disable: 4459)
#endif
// ------------------------------

#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10, "t");
    inf.readEoln();

    while(t--) {
        // OPTION 2 LIMIT: N <= 18
        int n = inf.readInt(1, 18, "n");
        inf.readSpace();

        // With Q=5, max items is 18*5 = 90. K up to 100 covers everything.
        int k = inf.readInt(1, 100, "k");
        inf.readEoln();

        inf.readLongs(n, 1LL, 1000000000LL, "costs");
        inf.readEoln();

        // OPTION 2 LIMIT: Qty <= 5
        // This keeps state space around 6^9 (10 Million), safe for memory.
        inf.readInts(n, 1, 5, "qtys");
        inf.readEoln();

        long long minC = inf.readLong(1LL, 2000000000000000000LL, "minCost");
        inf.readSpace();
        long long maxC = inf.readLong(minC, 2000000000000000000LL, "maxCost");
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}