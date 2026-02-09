//
// Created by RAZEEF on 12-01-2026.
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


using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


vector<vector<int>> dir={{0,1}, {0,-1}, {1,0}, {-1,0}};
void dfs(int i,int j,vector<string> &grd,vector<vector<bool>> &vis) {
    int n=sz(grd), m=grd[0].size();

    for (int d=0;d<4;d++) {

        int r=i+dir[d][0];
        int c=j+dir[d][1];

        if (r<n && c<m && r>=0 && c>=0 && grd[r][c]=='.' && !vis[r][c]) {
            vis[r][c]=true;
            dfs(r,c,grd,vis);
        }
    }
}

void moon() {

    int n,m;
    cin >> n>>m;
    vector<string> grd(n);
    for(int i = 0; i < n; i++) cin >> grd[i];

    int rms=0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          if(grd[i][j] == '.' && !vis[i][j]) {
            vis[i][j] = true;
              dfs(i,j,grd,vis);
              rms++;
            }
      }
    }

    cout << rms << '\n';
}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}
