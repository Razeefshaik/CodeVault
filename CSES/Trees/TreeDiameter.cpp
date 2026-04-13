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
ll dfs(ll node,ll p,vvll &adj) {

    vll ans;
    ll md=0;
    for(auto v:adj[node]) {

        if (v!=p) {
           ll d= dfs(v,node,adj);
            md= max(md, d+1);
            ans.pb(d+1);
        }
    }

    sort(all(ans));
    if (sz(ans)>0) maxi=max(maxi, ans[sz(ans)-1]);
    if (sz(ans)>1) maxi= max(maxi , ans[sz(ans)-1]+ans[sz(ans)-2]);
    return md;
}

void moon() {

    ll n;
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
    dfs(0,-1,adj);
    cout<<maxi<<"\n";

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






