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

void print(int i,int j,vector<int> &parents) {
    vector<int> left;


    left.pb(i+1);
    while (i!=j) {
        i=parents[i];
        left.pb(i+1);



    }
    left.pb(left[0]);

    cout<<left.size()<<'\n';
    for (auto it:left) {
        cout<<it<<" ";
    }
    cout<<"\n";



}

bool dfs(int node,int p,vvi &adj,vector<int> &parents) {
    parents[node]=p;

    for (auto it:adj[node]) {

        if (parents[it]==-1) {
            if (dfs(it,node,adj,parents)) return true;
        }
        else if (it!=p) {
           print(node,it,parents);
            return true;
        }

    }
    return false;
}

void moon() {

    int  n,m;
    cin >> n>>m;
    vvi adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> parents(n,-1);
    for(int i = 0; i < n; i++) {

          if (parents[i]==-1) {
              if (dfs(i,-2,adj,parents)) return;
          }
    }

    cout << "IMPOSSIBLE" << endl;
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
