//
// Created by RAZEEF on 30-01-2026.
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

//
// ll solve(int idx, vll &a, vll &b, vll &dp) {
//
//     ll n=a.size();
//     if (idx<0) return 0;
//     if (dp[idx]!=-1) return dp[idx];
//
//     ll ans=-LINF;
//
//     ans= max(solve(idx-1,a,b,dp)-a[idx], ans);
//     ans= max( b[idx]-solve(idx-1, a,b,dp), ans);
//
//     return dp[idx]=ans;
//
// }


void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // vll dp(n, -1);
    // ll ans= solve(n-1, a, b, dp);

    ll maxi=0;
    ll mini=0;
    for(int i = 0; i < n; i++) {

        ll val1= mini-a[i];
        ll val2= b[i]-mini;

        ll val3= maxi-a[i];
        ll val4= b[i]-maxi;

        maxi= max({val1,val2,val3,val4});
        mini= min({val1,val2,val3,val4});
    }
    cout << max(mini, maxi) << '\n';

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






