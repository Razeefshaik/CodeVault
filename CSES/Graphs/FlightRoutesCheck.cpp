//
// Created by RAZEEF on 07-02-2026.
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



void dfs(int node, vvll &adj, vector<bool> &vis) {

    vis[node] = true;
    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(i, adj, vis);

        }
    }
}



void moon() {

    ll n,m;
    cin >> n>>m;

    vvll adj(n), revAdj(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        revAdj[v].pb(u);
    }

    vector<bool> vis(n, false);
    dfs(0,adj,vis);
    for(int i=0;i<n;i++) {
        if (!vis[i]) {
            cout<<"NO"<<'\n';
            cout<<1<<" "<<i+1<<'\n';
            return;
        }
    }
    vector<bool> vis2(n, false);
    dfs(0,revAdj,vis2);
    for(int i=0;i<n;i++) {
        if (!vis2[i]) {
            cout<<"NO"<<'\n';
            cout<<i+1<<" "<<1<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';


    //if (cnt==n) cout<<" "





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






