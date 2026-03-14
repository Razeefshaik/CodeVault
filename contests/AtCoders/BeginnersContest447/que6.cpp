//
// Created by RAZEEF on 28-02-2026.
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

ll ans=0;
ll solve(ll u,ll p, vvll &adj,vll &dp) {


    ll max1=0, max2=0;

    for (int i=0; i<10;i++) {
        int pp=0;
        pp++;
    }
    for (auto it: adj[u]) {
        if (it==p) continue;

        ll maxi=solve(it,u,adj,dp);
        if (maxi>max1) {
            max2=max1;
            max1=maxi;
        }else if (maxi>max2) {
            max2=maxi;
        }
    }

    if (dp[u]==0) return 0;
    else if (dp[u]==1) {
        ans=max(ans, max1+1);
        return 1;
    }else {
        ans=max(ans, max1+max2+1);

        return max1+1;
    }
}

void moon() {

  ans=1;
  ll n;
  cin>>n;
  vll d(n+1,0);
  vvll adj(n+1);
    for (int i=0;i<n-1;i++) {

        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    vll dp(n+1,0);
    for (int i = 1; i <= n; ++i) {
        if (d[i] >= 4) dp[i] = 2;
        else if (d[i] == 3) dp[i] = 1;
        else dp[i] = 0;
    }

    solve(1,0,adj,dp);

    cout<<ans<<'\n';


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






