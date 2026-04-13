//
// Created by RAZEEF on 07-04-2026.
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

ll tot;
ll n;
pll dfs(int node,int p,vvll &adj,vector<pll> &dist) {

     ll sz=1;
    ll sum=0;
    for (auto it: adj[node]) {
        if (it==p) continue;
        auto [currsz, currsum]=dfs(it,node,adj,dist);
        sum+=currsum+currsz;
        sz+=currsz;

    }

    dist[node]={sz,sum};
    return {sz,sum};
}

void dfs2(int node,int p,vvll &adj,vll &ans, vector<pll> &dist) {

    for (auto it: adj[node]) {
        if (it==p) continue;

        ll m= ans[node]-2*dist[it].fi+n;
        ans[it]=m;
        dfs2(it,node,adj,ans,dist);
    }
}


void moon() {

   // ll n;
    cin >> n;
    vvll adj(n);
    for (ll i = 0; i < n-1; i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);

      }


    vector<pll> dist(n);
    dfs(0,-1,adj,dist);
    tot=dist[0].se;

    vll ans(n);
    ans[0]=tot;
    dfs2(0,-1,adj,ans,dist);
    for (ll i = 0; i < n; i++) {

        cout<<ans[i]<<" ";
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






