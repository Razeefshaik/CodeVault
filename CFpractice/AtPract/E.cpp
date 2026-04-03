//
// Created by RAZEEF on 02-04-2026.
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


vvll dp;
ll n,w;
// ll solve(int idx,ll wt,vector<pll> &a) {
//
//     if (idx>=n) return 0;
//     if (dp.count(idx) && dp[idx].count(wt)) return dp[idx][wt];
//
//     ll currw=a[idx].fi;
//     ll currv=a[idx].se;
//     ll ans=0;
//     if ((wt+currw)<=w) {
//         ans=max(ans, currv+solve(idx+1,wt+currw,a));
//     }
//     ans=max(ans, solve(idx+1, wt,a));
//     return dp[idx][wt]=ans;
// }


ll solveW(int idx, ll remv,vector<pll> &a) {
    if (remv==0) return 0;
    if (idx>=n || remv<0) return LINF;
    if ( dp[idx][remv]!=-1) return dp[idx][remv];
    ll ans=LINF;
    if (a[idx].se<=remv) {
        ans=min(ans, a[idx].fi+solveW(idx+1,remv-a[idx].se,a));
    }
    ans=min(ans, solveW(idx+1,remv,a));
    return dp[idx][remv]=ans;
}
void moon() {

   // ll n,w;
    cin >> n>>w;
    vector<pll> a(n);
    ll maxi=0;
    for (ll i = 0; i < n; i++) {
        ll wt,v;
        cin >> wt >> v;
        maxi+=v;
        a[i]={wt,v};
    }

    dp.assign(n, vector<ll>(maxi+1,-1));
   // ll ans= solve(0,0,a);
    for (ll i=maxi; i>=0; i--) {

        if (solveW(0,i,a)<=w) {
            cout << i << '\n';
            return;
        }
    }

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






