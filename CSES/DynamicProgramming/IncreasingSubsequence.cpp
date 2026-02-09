//
// Created by RAZEEF on 05-01-2026.
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


int solve(int idx,int p,vi &a, vvi &dp) {

    int n = sz(a);
    if (idx>=n) return 0;
    if (dp[idx][p+1]!=-1) return dp[idx][p+1];

    int ans=0;
    if (p==-1 || a[p]<a[idx]) ans= 1+solve(idx+1,idx, a, dp);
    ans= max(ans, solve(idx+1,p,a,dp));

    return dp[idx][p+1]=ans;

}


void moon() {
     
    ll n;
    cin >> n;
   vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    //vvi dp(n, vi(n+1,-1));
    //cout<<solve(0,-1,a,dp);

    vi dp(n+1, 1);

    int maxi=-INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {

            if (a[i]>a[j])
            dp[i]= max(dp[i], dp[j]+1);

        }
        maxi= max(maxi, dp[i]);
    }

    cout << maxi << '\n';

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
