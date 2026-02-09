//
// Created by RAZEEF on 28-12-2025.
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



ll solve(int idx, ll sum, vll &a, vvll &dp) {

    if (sum==0) return 1;
    if (idx>=sz(a) || sum<0) return 0;
    if (dp[idx][sum]!=-1) return dp[idx][sum];
    ll ans=0;
    for (ll i=0; i<sz(a); i++) {


            ans= (ans+solve(i, sum-a[i], a,dp))%MOD;
    }

   return dp[idx][sum]=ans;

}

int solvedp(int n,int tar,vll &a) {

    vi dp(tar+1, 0);
   // for (int i=0; i<n; i++) {
        dp[0]=1;
   // }

    for (int sum=1;sum<=tar;sum++) {

       // for (int idx=n-1;idx>=0;idx--) {

            int ans=0;
            for (int i=0;i<sz(a);i++) {

                if (a[i]<=sum) ans= (ans+dp[sum-a[i]])%MOD;
            }
            dp[sum]=ans;
     //   }
    }

    return dp[tar];

}
void moon() {

    ll n,tar;
    cin >> n>>tar;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
   // vvll dp(n+1,vll(tar+1, -1));
   // cout << solve(0, tar, a, dp)<<'\n';

    cout<<solvedp(n,tar,a)<<'\n';
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
