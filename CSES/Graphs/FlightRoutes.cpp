//
// Created by RAZEEF on 20-01-2026.
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

    ll n,m,k;
    cin >> n>>m>>k;
    vector<vector<pll>> adj(n);
    for(int i = 0; i < m; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v,w});
    }

    vector<priority_queue<ll>>  dist(n);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,0});
    dist[0].push(0);

    while(!pq.empty()) {
        auto[cost,node]=pq.top();
        pq.pop();

        if (!dist[node].empty() && dist[node].top() < cost && dist[node].size()==k) continue;
        for (auto it:adj[node]) {
            ll v,w;
            v=it.first;
            w=it.second;

            ll c=cost+w;
            if ( sz(dist[v])<k) {
                dist[v].push(c);
                pq.push({c,v});
            }else if (dist[v].top()>c) {
                dist[v].pop();
                pq.push({c,v});
                dist[v].push(c);
            }
        }
    }

    vector<ll> ans;
    while (!dist[n-1].empty()) {
        ans.pb(dist[n-1].top());
        dist[n-1].pop();
    }

    reverse(all(ans));
    for (auto it: ans) {
        cout << it << " ";
    }
    cout << endl;


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



