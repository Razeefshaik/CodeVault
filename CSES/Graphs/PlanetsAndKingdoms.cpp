//
// Created by RAZEEF on 08-02-2026.
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


void dfs1(int node, vvll &adj,vector<bool> &vis, stack<ll> &st) {
    vis[node] = true;
    for(auto x: adj[node]) {
        if (!vis[x]) {
            dfs1(x,adj,vis,st);
        }
    }

    st.push(node);
}

void dfs2(int node,vvll &adj, vector<ll> &vis,int cnt) {
    vis[node]=cnt;
    for(auto x: adj[node]) {
        if (vis[x]==-1) {
            dfs2(x,adj,vis,cnt);
        }
    }
}

void moon() {

    ll n,m;
    cin >> n>>m;
    vvll adj(n), revAdj(n);
    for (ll i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        revAdj[v].pb(u);
    }

    vector<bool> vis(n, false);
    stack<ll> st;
    for (int i=0;i<n;i++) {

        if (!vis[i]) dfs1(i,adj,vis,st);
    }

    int cnt=0;
    vll mpp(n,-1);
    while(!st.empty()) {
        int node=st.top();
        st.pop();
        if (mpp[node]==-1) {
            cnt++;
            dfs2(node,revAdj,mpp,cnt);
        }
    }

    cout<<cnt<<'\n';

    for (auto it: mpp) {
        cout<<it<<" ";
    }
    cout<<"\n";


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






