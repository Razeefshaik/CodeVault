//
// Created by RAZEEF on 10-02-2026.
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


int n,m;
vvi adj,revAdj;
int nego(int x) {
    //return x^1;

    return x<m? x+m: x-m;
}

void addClause(int u,int v) {

    adj[nego(u)].pb(v);
    adj[nego(v)].pb(u);
    revAdj[u].pb(nego(v));
    revAdj[v].pb(nego(u));
}

void dfs(int node,vector<bool> &vis, stack<int> &st) {
    vis[node] = true;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            dfs(it,vis,st);
        }
    }
    st.push(node);
}

void dfs1(int node,int cmp,vector<int> &vis) {
    vis[node]=cmp;
    for (auto it: revAdj[node]) {
        if (vis[it]==-1) {
            dfs1(it,cmp,vis);
        }
    }

}

void moon() {


    cin >> n>>m;
    adj.resize(2*m);
    revAdj.resize(2*m);;


    for (int i=0;i<n;i++) {

        string s1,s2;
        int u,v;
        cin >> s1 >>u >> s2 >> v;
        u--;
        v--;

        if (s1=="-") u=nego(u);
        if (s2=="-") v=nego(v);
        addClause(u,v);
    }

   vector<bool> vis(2*m,false);
    stack<int> st;
    for (int i=0;i<2*m;i++) {
        if (!vis[i]) dfs(i,vis,st);
    }

    vector<int> cmps(2*m,-1);
    int cmp=0;
    while (!st.empty()) {
        int node=st.top();
        st.pop();
        if (cmps[node]==-1) {
            cmp++;
            dfs1(node,cmp,cmps);
        }
    }

    vector<char> ans(m,'-');
    for (int i=0;i<m;i++) {
        if (cmps[i]==cmps[nego(i)]) {
            cout<<"IMPOSSIBLE"<<'\n';
            return;
        }

        if (cmps[i]>cmps[nego(i)]) ans[i]='+';
    }

    for (auto it: ans) {
        cout<<it<<" ";
    }
    cout<<'\n';

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






