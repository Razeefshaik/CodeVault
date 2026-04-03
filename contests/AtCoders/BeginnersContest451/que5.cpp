//
// Created by RAZEEF on 29-03-2026.
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




class DSU {

    vector<int> parent, size;

public:


    DSU(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
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


void moon() {

    ll n;
    cin >> n;
    vvi v(n+1, vi(n+1, 0));
    vector<vll> edg;
    for (ll i = 1; i <=n; i++) {
        for (int j=i+1;j<=n;j++) {
             cin>>v[i][j];
            edg.pb({v[i][j],i,j});
        }
    }

    sort(all(edg));
    vector<vector<pll>> adj(n+1);
    DSU dsu(n+1);
    int cnt=0;
    for (auto it: edg) {

        ll u=it[1], v=it[2];
        ll wt=it[0];
        if (dsu.findUPar(u)!=dsu.findUPar(v)) {
            dsu.unionBySize(u,v);
            adj[u].pb({v, wt});
            adj[v].pb({u, wt});
            cnt++;
            if (cnt==n-1) break;

        }

    }


    for (int i=1;i<=n;i++) {

        vll dist(n+1, -1);
        queue<ll> q;
        q.push(i);
        dist[i]=0;
        while (!q.empty()) {
            ll u=q.front();
            q.pop();
            for (auto it: adj[u]) {
                ll v=it.first, w=it.second;
                if (dist[v]==-1) {
                    dist[v]=dist[u]+w;
                    q.push(v);
                }
            }
        }

        for (int j=i+1;j<=n;j++) {
                if (dist[j]!=v[i][j]) {
                    cout<<"No"<<'\n';
                    return;
                }
        }
    }

  cout<<"Yes"<<'\n';

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






