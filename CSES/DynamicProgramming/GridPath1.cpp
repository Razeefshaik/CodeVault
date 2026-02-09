//
// Created by RAZEEF on 28-12-2025.
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
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


ll solve(int i, int j, vector<string> &grid, vector<vector<ll>> &dp) {

    int n=grid.size(),m=grid[0].size();
    if (i==n-1 && j==m-1) return 1;
    if (dp[i][j]!=-1) return dp[i][j];

    ll ans=0;

    if (i+1<n && grid[i+1][j]!='*') ans= (ans+solve(i+1,j,grid,dp))%MOD;
    if (j+1<m && grid[i][j+1]!='*') ans= (ans+solve(i,j+1,grid,dp))%MOD;

    return dp[i][j]=ans;
}

void moon() {

    ll n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<ll>> dp(n,vector<ll>(n,-1));
     if (grid[0][0]=='*') {
         cout<<0<<'\n';
         return;
     }
    ll ans=solve(0,0,grid,dp);
    cout << ans << '\n';


}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}

