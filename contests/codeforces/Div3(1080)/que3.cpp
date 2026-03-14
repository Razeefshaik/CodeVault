//
// Created by RAZEEF on 15-02-2026.
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


int solve(int idx,int pr,vll &a,vvi &dp) {

    int n=a.size();
    if (idx>=n) return 0;
    if (dp[idx][pr]!=-1) return dp[idx][pr];
    ll ans=LINF;


    for (int p=1;p<=6;p++) {
        if (idx==0 || (p!=pr && ((7-p)!=pr))) {

            ll c=(a[idx]==p)? 0:1;
            ans=min(ans, c+solve(idx+1,p,a,dp));

        }
    }



    return dp[idx][pr]=ans;
}

void moon() {

    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];
     vvi dp(n,vi(8,-1));
    ll ans=solve(0,0,a,dp);

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






