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


int solve(int idx, int val,int m,vi &a,vvi &dp) {


   if (val<1 || val>m ) return 0;
    if (a[idx]!=0 && a[idx]!=val) return 0;
    if(idx == sz(a)-1) { return 1;}
    if (dp[idx][val]!=-1) return dp[idx][val];

    int ans=0;

       ans= (ans+solve(idx+1,val-1,m,a,dp))%MOD;
    ans= (ans+solve(idx+1,val,m,a,dp))%MOD;
      ans= (ans+solve(idx+1,val+1,m,a,dp))%MOD;

    return dp[idx][val]=ans;

}

void moon() {

    ll n,m;
    cin >> n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vvi dp(n, vi(m+1,-1));

    int ans=0;
    for(int i = 1; i <= m; i++) {

        if (a[0]==0 || a[0]==i) ans= (ans+ solve(0,i,m,a,dp))%MOD;
    }
    cout<<ans<<'\n';

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

