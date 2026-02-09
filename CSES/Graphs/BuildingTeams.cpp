//
// Created by RAZEEF on 14-01-2026.
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


bool dfs(int node,int c, vvi  &adj, vi &col) {
    col[node]=c;

    for (auto it: adj[node]) {
        if (col[it]==-1) {
            if (dfs(it,1-c,adj,col)==false) return false;
        }else if (col[it]==c) {
            return false;
        }

    }

    return true;
}


void moon() {

    int n,m;
    cin >> n>>m;
    vvi  adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi col(n,-1);
    //vector<bool> vis(n,false);
    for (int i=0;i<n;i++) {

        if (col[i]==-1) {
            if (dfs(i,0,adj,col)==false) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for (auto it:col) {
        cout << it+1<<" ";
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
