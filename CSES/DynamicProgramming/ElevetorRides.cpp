//
// Created by RAZEEF on 08-01-2026.
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

    int n,cap;
    cin >> n>>cap;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pii> dp(1<<n, {INF, INF});
    dp[0]={1,0};

    for (int mask=1;mask<(1<<n);mask++) {

        for (int i=0;i<n;i++) {

            if (mask&(1<<i)) {

                int curr= a[i];
                int p= mask^(1<<i);

                auto [r,c]=dp[p];

                if (curr+c<=cap) {
                    curr+=c;
                }else {
                    r++;

                }

                dp[mask]=min(dp[mask], {r,curr});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;


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
