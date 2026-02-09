//
// Created by RAZEEF on 16-01-2026.
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

using vvip = vector<vector<pair<int, int>>>;
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




void moon() {

   int n,m;
    cin >> n>>m;
    vvip adj(n);
    for(int i = 0; i < m; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        adj[u].pb({v,c});

    }

    vll dist(n,LINF);
    priority_queue<pll, vector<pll>, greater<pll>>q;
    q.push({0,0});
    dist[0]=0;

    while(!q.empty()) {
        auto [cost, node]=q.top();
        q.pop();

        if(dist[node]<cost) continue;

        for (auto it: adj[node]) {
             ll tCost=cost+it.se;
            if (dist[it.fi]>tCost) {
                dist[it.fi]=tCost;
                q.push({tCost,it.fi});
            }
        }
    }

    for (auto it:dist) {
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
