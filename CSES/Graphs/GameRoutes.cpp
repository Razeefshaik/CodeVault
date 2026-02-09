//
// Created by RAZEEF on 23-01-2026.
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


int dfs(int node,int n,vvll &adj,vll &dp) {
    if (node==n-1) return 1;
    if (dp[node]!=-1) return dp[node];
    ll ans=0;
    for (auto it:adj[node]) {
        ans=(ans+dfs(it,n,adj,dp))%MOD;
    }
    return dp[node]=ans%MOD;
}


void moon() {

    ll n,m;
    cin >> n>>m;
    vvll a(n);
    for(int i = 0; i < m; i++){

        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        a[u].pb(v);
    }

    vll dp(n,-1);
    ll cnt=dfs(0,n,a,dp);

    cout << cnt << '\n';


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






