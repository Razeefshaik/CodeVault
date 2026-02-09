//
// Created by RAZEEF on 29-12-2025.
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
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


ll solve(int idx,int sum, vll &c,vll &p, vvll &dp) {

    if (idx == sz(c)) { return 0;}
    if (dp[idx][sum]!=-1) return dp[idx][sum];

    ll ans=-LINF;

    if (c[idx]<=sum) {
        ans= max(ans, p[idx]+solve(idx+1,sum-c[idx],c,p,dp));
    }
    ans= max(ans, solve(idx+1, sum,c,p,dp));

    return dp[idx][sum]=ans;
}


int solvedp(int n,int x, vector<int> &c,vector<int> &p) {

    vvi dp(n+1, vi(x+1, 0));
    // for (int i = 1; i <= x; i++) {
    //     dp[n][i]=0;
    // }

    for (int i=n-1;i>=0;i--) {

        for (int s=1;s<=x;s++) {

            int ans=-INF;
            if (c[i]<=s) {

                ans= max(ans, p[i]+dp[i+1][s-c[i]]);
            }
            ans= max(ans, dp[i+1][s]);
            dp[i][s]=ans;
        }
    }

    return dp[0][x];

}


void moon() {

    ll n,x;
    cin >> n>>x;
    vector<int> c(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
      cin >> c[i];

      }
    for(int i = 0; i < n; i++){
        cin >> p[i];

    }

   // vvll dp(n+1, vll(x+1, -1));
   // cout << solve(0,x,c,p,dp) << '\n';
    cout<<solvedp(n,x,c,p)<<'\n';


}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}
