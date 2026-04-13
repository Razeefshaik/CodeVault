//
// Created by RAZEEF on 06-04-2026.
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


vvll dp;


void dfs(ll node,ll p,vvll &adj) {


    ll sum=0;
    for(auto v:adj[node]) {
        if(v==p) continue;
        dfs(v,node,adj);
        sum+=max(dp[v][0], dp[v][1]);
    }

    dp[node][0]=sum;
    dp[node][1]=0;
    for (auto v: adj[node]) {
        if (v==p) continue;
        dp[node][1]= max(dp[node][1], 1+dp[v][0]+sum-max(dp[v][0], dp[v][1]));
    }

}

void moon() {

    ll n;
    cin >> n;
    vvll adj(n);
    for (ll i = 0; i < n-1; i++) {
        ll u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dp.assign(n, vll(2, 0));
    dfs(0,-1,adj);
    cout<<max(dp[0][0], dp[0][1])<<'\n';


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






