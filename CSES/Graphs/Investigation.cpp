//
// Created by RAZEEF on 03-02-2026.
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

// ll cnt=0;
// int maxFlight=-1;
// int minFlights=INT_MAX;

// void dfs(int node, ll cost,ll minCost,int flght, vector<vector<pll>> &adj, vector<bool> &vis) {
//      int n=adj.size();
//     if (node==n-1 && minCost==cost) {
//         cnt= (cnt+1)%MOD;
//         minFlights=min(minFlights, flght);
//         maxFlight=max(maxFlight, flght);
//         return;
//     }
//
//     vis[node]=true;
//     for (auto it:adj[node]) {
//
//         ll c=cost+it.se;
//         if (c>minCost) continue;
//         if (!vis[it.fi]) {
//             dfs(it.fi, c,minCost,flght+1, adj,vis);
//         }
//     }
//
//     vis[node]=false;
//
// }


void moon() {

    ll n,m;
    cin >>n>>m;
    vector<vector<pll>> adj(n);
    for(int i = 0; i < m; i++) {
        ll u,v,w;
        cin >>u>>v>>w;
        u--;
        v--;

        adj[u].pb({v,w});
    }

    vll dist(n, LINF);
    vll cnt(n, 1);
    vi minFlights(n,0), maxFlights(n,0);
    dist[0]=0;
    cnt[0]=1;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,0});

    ll fcost=-1;
    while(!q.empty()) {
        auto[cost, node]=q.top();
        q.pop();

       if (cost>dist[node]) continue;


        for (auto it: adj[node]) {

            ll c=cost+it.se;
            if (c<dist[it.fi]) {
                dist[it.fi]=c;
                cnt[it.fi]=cnt[node];
                minFlights[it.fi]=minFlights[node]+1;
                maxFlights[it.fi]=maxFlights[node]+1;
                q.push({c,it.fi});
            }else if (c==dist[it.fi]) {
                cnt[it.fi]= (cnt[it.fi]+cnt[node])%MOD;
                minFlights[it.fi]=min(minFlights[node]+1, minFlights[it.fi]);
                maxFlights[it.fi]=max(maxFlights[node]+1, maxFlights[it.fi]);
            }
        }
    }

    //cout << fcost << '\n';

    //vector<bool> vis(n, false);
    //dfs(0,0,fcost,0,adj,vis);

    cout<<dist[n-1]<<" "<<cnt[n-1]<<" "<<minFlights[n-1]<<" "<<maxFlights[n-1]<<endl;



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






