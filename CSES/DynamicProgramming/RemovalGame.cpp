//
// Created by RAZEEF on 04-01-2026.
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


ll solve(int i,int j,vi &a,vvll &dp) {

    if (i==j) return a[i];
    if (dp[i][j]!=-1) return dp[i][j];

    ll ans=-LINF;

    ans= max(ans, a[i]-solve(i+1,j,a,dp));
    ans= max(ans, a[j]-solve(i,j-1,a,dp));

    return dp[i][j]=ans;
}

void moon() {

    ll n;
    cin >> n;
    vi a(n);
    ll sum=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum+=a[i];
    }

    vvll dp(n+1, vll(n+1, -1));
    ll diff= solve(0,n-1,a,dp);

    ll res=(sum+(ll)diff)/2ll;
    cout << res << '\n';


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
