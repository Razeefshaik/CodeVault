//
// Created by RAZEEF on 01-02-2026.
//
// SLOW SOLUTION - Intended to TLE
#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18;
int n, m;
vector<vector<int>> grid;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

long long bfs(int limit) {
    if (grid[0][0] > limit || grid[n-1][m-1] > limit) return LINF;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == n-1 && y == m-1) return dist[x][y];
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] <= limit && dist[nx][ny] == 1e9) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return LINF;
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    vector<int> cands;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        cin >> grid[i][j];
        cands.push_back(grid[i][j]);
    }
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());

    long long ans = LINF;
    for(int val : cands) {
        long long steps = bfs(val);
        if(steps != LINF) ans = min(ans, steps + val);
    }
    if(ans == LINF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}