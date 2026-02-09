//
// Created by RAZEEF on 16-12-2025.
//



#include <bits/stdc++.h>
using namespace std;


#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {
    // Write your solution here
    int n;
    cin >> n;

    vector<vector<int>> dist(n,vector<int>(n, INT_MAX));
    vector<vector<int>> dir={{1,-2}, {1,2}, {-1,-2},{-1,2}, {2,-1}, {2,1},{-2,-1}, {-2,1}};

    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0]=0;

    while(!q.empty()) {
        auto [r,c]=q.front();
        q.pop();

        int currDist=dist[r][c];

        for (int d=0;d<8;d++) {

            int nr=r+dir[d][0];
            int nc=c+dir[d][1];

            if (nc>=0 && nc<n && nr>=0 && nr<n && dist[nr][nc]>(currDist+1)) {
                dist[nr][nc]=currDist+1;
                q.push({nr,nc});

            }
        }

    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


}

int main() {
    fast_io;



    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

