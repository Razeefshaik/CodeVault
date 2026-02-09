//
// Created by RAZEEF on 04-02-2026.
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

    ll n,qr;
    cin >> n>>qr;
    vll a(n);

    vi indeg(n,0);
    for (ll i = 0; i < n; i++){
      cin>>a[i];
      a[i]--;
        indeg[a[i]]++;
      }

    queue<pll> q;
    for (int i=0;i<n;i++) {
        if (indeg[i]==0) q.push({a[i],0});
    }

    vvi dist(n, vi(n,-1));
    while (!q.empty()) {
        auto[node, d]= q.front(); q.pop();

        int nxtnode=a[node];
        dist[node][nxtnode]=d+1;
        indeg[nxtnode]--;

        if (indeg[nxtnode]==0) q.push({nxtnode,0});
        else {
            q.push({nxtnode, d+1});
        }

    }



}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






