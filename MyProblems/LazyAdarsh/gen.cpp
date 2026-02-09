#include "testlib.h"
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t_count = atoi(argv[1]);
    int max_n = atoi(argv[2]);
    int max_m = atoi(argv[3]);
    long long max_val = atoll(argv[4]);
    int type = atoi(argv[5]);

    println(t_count);

    for (int t = 0; t < t_count; t++) {
        int n = rnd.next(2, max_n);
        int m = rnd.next(2, max_m);

        printf("%d %d\n", n, m);
        vector<vector<int>> grid(n, vector<int>(m));

        if (type == 0) { // Random Uniform
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    grid[i][j] = rnd.next(1, (int)max_val);
        }
        else if (type == 1) { // Trap (High speed path vs Slow path)
            for(int i=0; i<n; i++) fill(grid[i].begin(), grid[i].end(), (int)max_val);
            int small_val = rnd.next(1, max(1, (int)max_val / 10));
            // Force boundary to be small
            for(int i=0; i<n; i++) grid[i][0] = grid[i][m-1] = small_val;
            for(int j=0; j<m; j++) grid[0][j] = grid[n-1][j] = small_val;
        }
        else if (type == 2) { // Diagonal Gradient
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    grid[i][j] = (i + j) * ((int)max_val / (n + m)) + 1;
        }
        else if (type == 3) { // SNAKE PATTERN (True TLE Killer)
            // Fills 1, 2, 3... along a snake path.
            // FIX: Force Start and End to be 1 to bypass "early exit" optimizations.

            int counter = 1;
            for(int i=0; i<n; i++) {
                if (i % 2 == 0) { // Left to Right
                    for(int j=0; j<m; j++) grid[i][j] = counter++;
                } else { // Right to Left
                    for(int j=m-1; j>=0; j--) grid[i][j] = counter++;
                }
            }
            // CRITICAL FIX:
            // Set start and end to 1.
            // The path still requires crossing the high values in the middle,
            // but the "if (end > limit)" check will now FAIL, forcing BFS to run.
            grid[0][0] = 1;
            grid[n-1][m-1] = 1;

            // Safety: Ensure neighbors of start/end maintain connectivity
            // (The snake logic already ensures connectivity, overwriting endpoints is fine
            // because they are just the tips of the snake).
        }

        // Output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d%c", grid[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}