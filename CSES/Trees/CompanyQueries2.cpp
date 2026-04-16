//
// Created by RAZEEF on 15-04-2026.
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



void dfs(int node,int p, vvll &adj, vll &depth) {

    for (auto it: adj[node]) {
        if (it==p) continue;
        depth[it] = depth[node]+1;
        dfs(it,node,adj,depth);
    }
}

ll kthlift(int node,ll k,vvll &dp) {
    for (int b=0;b<22;b++) {
        if (k&(1<<b)) {

            if (node!=-1) node=dp[b][node];
        }
    }
    return node;
}

ll  quer(ll u,ll v,vvll &dp, vll &depth) {

    if (depth[u]<depth[v]) swap(u,v);
     u= kthlift(u,depth[u]-depth[v],dp);

    if (u==v) return u;

    for (int b=21;b>=0;b--) {

        if (dp[b][u] != dp[b][v]) {
            u = dp[b][u];
            v = dp[b][v];
        }
    }
    return dp[0][u];
}

void moon() {

    ll n,q;
    cin >> n>>q;
    vvll dp(22,vll(n,-1));
    vvll adj(n);
    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        x--;
        dp[0][i]=x;

        adj[i].pb(x);
        adj[x].pb(i);
    }

    vll depth(n);
    dfs(0,-1,adj,depth);

    for (int i=1;i<22;i++) {
        for (int j=0;j<n;j++) {
            if (dp[i-1][j]!=-1) dp[i][j]= dp[i-1][dp[i-1][j]];
        }
    }


    while (q--) {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        ll z=quer(x,y,dp,depth);
        cout << z+1 << '\n';
    }


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






