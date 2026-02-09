//
// Created by RAZEEF on 06-02-2026.
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



//Prims Algo
void moon1() {

    ll n,m;
    cin >> n>>m;
    vector<vector<pll>>  adj(n);
    for (ll i = 0; i < m; i++) {

        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    vector<bool> vis(n, false);
    ll sum=0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,0});

    int cnt=0;
   while (!pq.empty()) {
       auto[cost,node] = pq.top();
       pq.pop();
       if (vis[node]) continue;
       vis[node]=true;
       cnt++;
       sum+=cost;

       for (auto it: adj[node]) {
           if (vis[it.fi]==false) {

               pq.push({it.se,it.fi});
           }
       }
   }

    if (cnt!=n) {
        cout<<"IMPOSSIBLE"<<'\n';
    } else cout << sum << '\n';
}




class DSU {

    vector<int> parent, size;

public:


    DSU(int n) {

        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }




    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


//Kruskal Algo
void moon() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll, pll>> edgs;

    for (int i=0;i<m;i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        edgs.pb({w, {u,v}});
    }

    sort(all(edgs));
    DSU dsu(n);
    ll sum=0;
    ll cnt=0;
    for (auto it: edgs) {
        int u=it.se.fi;
        int v=it.se.se;
        int w=it.fi;

        int pu=dsu.findUPar(u);
        int pv=dsu.findUPar(v);
        if (pu!=pv) {
            dsu.unionBySize(u,v);
            sum+=w;
            cnt++;
        }
    }


    if (cnt!=n-1) {
        cout<<"IMPOSSIBLE"<<'\n';
    }else cout << sum << '\n';
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






