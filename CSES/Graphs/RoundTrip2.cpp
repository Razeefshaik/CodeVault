//
// Created by RAZEEF on 21-01-2026.
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

unordered_map<ll,ll> gst;
ll start=-1;
ll endn= -1;
bool dfs(ll node,vvll &adj, unordered_map<ll,ll>  &st,vector<bool> &vis) {

    vis[node]=true;
   st[node]=sz(st)+1;
    for(auto x:adj[node]) {

        if (!vis[x]) {

            if (dfs(x,adj,st,vis)) {
                return true;
            }
        }else if (st.count(x)) {

            start=node;
            endn= x;
            return true;
        }


    }
    st.erase(node);
    return false;
}


void moon() {

    ll n,m;
    cin >> n>>m;
    vvll adj(n);
    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].pb(v);
     }

    vector<bool> vis(n,false);

    bool f=false;
    for (int i=0;i<n;i++) {

        unordered_map<ll,ll>  st;
        if (dfs(i,adj,st,vis)==true) {
            gst=st;
            f=true;
            break;
        }
    }


    if (f) {

        vector<ll> ans(sz(gst)+1);
        for (auto it:gst) {
            ans[it.se]=it.fi;
        }

        int s=gst[start];
        int e=gst[endn];

        vll a;
        for (int i=1;i<ans.size();i++) {
            if (i>=e && i<=s) a.pb(ans[i]+1);
        }
        a.pb(endn+1);
        cout << a.size() << '\n';
       // cout<<a.back()<<" ";


        for (int i=0;i<a.size();i++) {
            cout << a[i] <<' ';
        }
        cout<<'\n';
    }
     
    else {
        cout<<"IMPOSSIBLE"<<'\n';
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



