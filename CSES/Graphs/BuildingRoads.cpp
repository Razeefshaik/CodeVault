//
// Created by RAZEEF on 13-01-2026.
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


int bfs(int node,vvi &adj, vector<bool> &vis) {

    queue<int> q;
    q.push(node);
    vis[node] = true;
    int res=node;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
                res=v;
            }
        }
    }

    return res;
}

void moon() {

    int n,m;
    cin >> n>>m;
    vvi adj(n);
    for(int i = 0; i < m; i++){

        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<bool> vis(n,false);
    vvi points;
    int cnt=0;
     for (int i=0;i<n;i++) {
         if (!vis[i]) {
             cnt++;
             int p=bfs(i,adj,vis);
             points.pb({i,p});
         }
     }

    cout << cnt-1 << '\n';

    for(int i=1;i<points.size();i++) {

        cout<<points[i-1][1]+1<<" "<<points[i][0]+1<<'\n';
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
