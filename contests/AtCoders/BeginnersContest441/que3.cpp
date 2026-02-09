//
// Created by RAZEEF on 17-01-2026.
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


void dfs(int node,int e,ll sum,vector<vector<pll>> &adj,vector<bool> &vis,ll l,ll s,ll t) {

    if (e==l && sum>=s && sum<=t) {
        vis[node]=true;
    }
    for (auto it:adj[node]) {

          if (e+1<=l && sum+it.second<=t) {
               dfs(it.first, e+1, sum+it.se, adj,vis,l,s,t);
          }
    }
}

void moon() {

    ll n,m,l,s,t;
    cin >>n>>m>>l>>s>>t;
    vector<vector<pll>> adj(n);
    for(int i = 0; i < m; i++){
         int u,v,w;
        cin>>u>>v>>w;
         u--;
        v--;
        adj[u].pb({v,w});

    }

   vector<bool> vis(n,false);
    dfs(0,0,0,adj,vis,l,s,t);

    for (int i=0;i<n;i++) {
        if (vis[i]) {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;




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



