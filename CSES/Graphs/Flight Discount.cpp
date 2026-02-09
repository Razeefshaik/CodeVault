//
// Created by RAZEEF on 18-01-2026.
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




void moon() {

    ll n,m;
    cin >> n>>m;
    vector<vector<pll>> adj(n);
    for(int i = 0; i < m; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v,w});
    }

    vector<vector<ll>> dist(n, vector<ll>(2,LINF));
    priority_queue<tuple<ll, ll,int>, vector<tuple<ll, ll,int>>, greater<tuple<ll, ll,int>>> pq;
    pq.push({0,0,0});
    dist[0][0]=0;

    ll mini=LINF;
    while(!pq.empty()) {
        auto [cost, node,state]=pq.top();
        pq.pop();


         if (dist[node][state] < cost) continue;
        for (auto it: adj[node]) {
             ll v=it.first,w=it.second;
            ll c=cost+w;



            if (dist[v][state]>c) {
                 pq.push({c,v,state});
                 dist[v][state]=c;
              }

            if (state==0) {

                ll dis=cost+w/2ll;
                if (dist[v][1]>dis) {
                    pq.push({dis,v,1});
                    dist[v][1]=dis;
                }
            }
        }
    }

    cout<<min(dist[n-1][0], dist[n-1][1])<<'\n';
    //cout<<mini<<'\n';



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



