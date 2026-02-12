//
// Created by RAZEEF on 11-02-2026.
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


void dfs(int node,vvi &adj,vector<bool> &vis, stack<int> &st) {
    vis[node]=true;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it,adj,vis,st);
        }
    }

    st.push(node);
}

void dfs1(int node, vvi &adj, int cmp,vi &cmps) {
    cmps[node]=cmp;
    for (auto it: adj[node]) {
        if (cmps[it]==-1) dfs1(it, adj,cmp,cmps);
    }

}

ll maxCoins(int node,vvi &adj,vll &coins, vector<ll> &dp) {
     if (dp[node]!=-1) return dp[node];
     ll maxi=0;
    for (auto it: adj[node]) {
        maxi=max(maxCoins(it,adj,coins,dp), maxi);

    }
    return dp[node]=coins[node]+maxi;
}

void moon() {

    ll n,m;
    cin >> n>>m;
    vvi adj(n), revAdj(n);
    vll coins(n);
    for (ll i = 0; i < n; i++){
       cin >> coins[i];
    }
    for (int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);revAdj[v].pb(u);
    }

    stack<int> st;
    vector<bool> vis(n, false);
    for (int i=0;i<n;i++) if (!vis[i]) dfs(i,adj,vis,st);

    int cmp=-1;
    vi cmps(n,-1);

    while (!st.empty()) {
        int node= st.top();
        st.pop();

        if (cmps[node]==-1) {
            cmp++;
            dfs1(node,revAdj,cmp,cmps);
        }
    }

    vll grpCoins(cmp + 1, 0);
    for (int i=0;i<n;i++) {
        grpCoins[cmps[i]]+=coins[i];
    }

    vvi sccAdj(cmp+1);
    for (int i=0;i<n;i++) {

        for (auto it: adj[i]) {
            if (cmps[i]!=cmps[it]) {
                sccAdj[cmps[i]].pb(cmps[it]);
            }
        }
    }

    ll maxi=0;
    vector<ll> dp(cmp+1, -1);
    for (int i=0;i<=cmp;i++) {
        maxi=max(maxi,maxCoins(i,sccAdj,grpCoins,dp));
    }


   cout<<maxi<<'\n';


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






