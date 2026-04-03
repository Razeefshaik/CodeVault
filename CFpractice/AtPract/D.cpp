//
// Created by RAZEEF on 03-04-2026.
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




void moon() {

    ll n,w;
    cin >> n>>w;
    vvll a(n);
    for (ll i = 0; i < n; i++){
       ll wt,v;
        cin >> wt >> v;
        a[i]={wt,v};
     }

    vvll dp(n, vll(w+1, 0));
    //dp[0][0]=1;
    for (int i=0;i<=w;i++) if (i>=a[0][0]) dp[0][i]=a[0][1];
    for (int i = 1; i <n; i++) {
        for (int j = 0; j <=w; j++) {
            dp[i][j]= max(dp[i][j], dp[i-1][j]);

            if (j>=a[i][0]) {
                dp[i][j]=max(dp[i][j], dp[i-1][j-a[i][0]]+a[i][1]);
            }
        }
    }
    cout << dp[n-1][w];


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






