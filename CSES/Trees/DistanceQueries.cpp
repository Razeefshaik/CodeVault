//
// Created by RAZEEF on 16-04-2026.
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


void dfs(int node,int p,vvll &adj, vll &depth, vvll &dp) {

    dp[0][node]=p;
    for (auto it : adj[node]) {
        if (it==p) continue;
        depth[it] = depth[node]+1;
        dfs(it,node,adj,depth,dp);
    }
}

ll kthlift(int node, int k, vvll &dp) {

    for (int b=0;b<22;b++) {
        if (k&(1<<b)) {
            if (node!=-1) node=dp[b][node];
        }
    }
    return node;
}


ll quer(int u,int v,vvll &dp, vll &depth) {

    if (depth[u]<depth[v]) swap(u,v);
    u= kthlift(u,depth[u]-depth[v],dp);

    if (u==v) return u;

    for (int b=21;b>=0;b--) {
        if (dp[b][u]!=dp[b][v]) {
            u = dp[b][u];
            v = dp[b][v];
        }
    }
    return dp[0][v];
}


void moon() {

    ll n,q;
    cin >> n>>q;
    vvll adj(n);
    vvll dp(22, vll(n,-1));
    for (ll i = 0; i < n-1; i++){
        ll u,v;
        cin >> u >> v;
        v--;
        u--;
       // dp[0][u]=v;

        adj[u].pb(v);
        adj[v].pb(u);
      }


    vll depth(n);
    dfs(0,-1,adj,depth,dp);

    for (int i=1;i<22;i++) {
        for (int j=0;j<n;j++) {
            if (dp[i-1][j]!=-1) dp[i][j]= dp[i-1][dp[i-1][j]];
        }
    }




     while (q--) {
         ll u,v;
         cin >> u >> v;
         u--;
         v--;
         ll lca= quer(v,u,dp,depth);

         ll ans= depth[u]+depth[v]-2*depth[lca];
         cout << ans << '\n';
     }
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






