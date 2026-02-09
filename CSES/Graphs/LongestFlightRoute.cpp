//
// Created by RAZEEF on 23-01-2026.
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


ll dfs(ll node,ll n,vvll &adj,vll &par,vll &dp) {

    if (node==n-1) return 1;
    if (dp[node]!=-1) return dp[node];

    ll maxi=-LINF;

    for (auto it: adj[node]) {

        ll l=dfs(it,n,adj,par,dp);
        if (l!=-LINF && maxi<l+1) {
            maxi=l+1;
            par[node]=it;
        }
    }

    return dp[node]=maxi;


}

void moon() {

    ll n,m;
    cin >> n>>m;
    vll dist(n, -1);
    vvll adj(n);
    for(int i = 0; i < m; i++) {

        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);

    }

    vll par(n,-1);

    ll a=dfs(0,n,adj,par,dist);










    if (a<0) {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    vll ans;
    int p=0;
    while (p!=-1) {
        ans.pb(p+1);
        if (p==n-1) break;
        p=par[p];
    }

   //reverse(all(ans));
    cout << ans.size() << "\n";
    for (auto it: ans) {
        cout << it<< " ";

    }
    cout << "\n";


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






