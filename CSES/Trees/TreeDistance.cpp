//
// Created by RAZEEF on 07-04-2026.
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



ll maxi=0;
ll n;
vll dfs(ll node,vvll &adj) {


    vll dist(n,-1);
    queue<ll> q;
    q.push(node);
    dist[node] = 0;
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        for (auto it: adj[curr]) {

            if (dist[it]==-1) {
                dist[it]= dist[curr]+1;
                q.push(it);
            }
        }
    }

    return dist;
}

void moon() {


    cin >> n;
    vvll adj(n);
    for (ll i = 0; i < n-1; i++) {
        ll u,v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans=0;
    vll dist1=dfs(0,adj);
    ll pa=0;
    for (int i=0;i<n;i++) {
        if (dist1[i]>dist1[pa]) pa=i;
    }
    vll dista=dfs(pa,adj);
    ll pb=pa;
    for (int i=0;i<n;i++) {
        if (dista[i]>dista[pb]) pb=i;
    }
    vll distb=dfs(pb,adj);
    for (int i=0;i<n;i++) cout<<max(dista[i], distb[i])<<" ";
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






