//
// Created by RAZEEF on 16-01-2026.
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

void dfs(int node,vector<bool> &vis,vector<vector<int>> &adjs ) {
    vis[node]=true;
    for (auto it :adjs[node]) {
        if (!vis[it]) dfs(it,vis,adjs);
    }
}


void moon() {

    ll n,m;
    cin >> n>>m;
    vector<vector<ll>> adj;

    vector<vector<int>> adjs(n);      // Forward graph
    vector<vector<int>> rev_adjs(n);
    for(int i = 0; i < m; i++){
         ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj.pb({u,v,w});

        adjs[u].pb(v);
        rev_adjs[v].pb(u);
    }

    vector<bool> visStart(n,false);
    vector<bool> visEnd(n,false);
    dfs(0,visStart,adjs);
    dfs(n-1,visEnd,rev_adjs);


    vector<ll> dist(n, -LINF);
    dist[0]=0;
    for(int i = 0; i < n-1; i++) {

        for (auto it: adj) {
             ll u = it[0], v = it[1], w=it[2];

            if (dist[u]!=-LINF && dist[u]+w>dist[v]) {
                dist[v] = dist[u]+w;
            }
        }
    }

    for (auto it: adj) {
        ll u = it[0], v = it[1], w=it[2];

        if (dist[u]!=-LINF && dist[u]+w>dist[v]) {

            if (visStart[v] && visEnd[v]) {
                cout<<-1<<'\n';
                return;
            }

        }
    }

    cout<<dist[n-1];


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
