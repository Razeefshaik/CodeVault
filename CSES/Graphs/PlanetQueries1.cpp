//
// Created by RAZEEF on 04-02-2026.
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

    ll n,q;
    cin >>n>>q;
    vvll dp(60, vll(n));
    for(int i = 0; i < n; i++){

        ll x;
        cin >> x;
        x--;
        dp[0][i]=x;
    }


    for (int i=1;i<60;i++) {
        for (int j=0;j<n;j++) {
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }

    for(int j=0;j<q;j++) {

        ll x,k;
        cin >> x >> k;
         x--;
        ll curr=x;
        for (int i=0;i<60;i++) {
            if (k&(1ll<<i)) {
                curr=dp[i][curr];
            }
        }
        cout<<curr+1<<'\n';
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






