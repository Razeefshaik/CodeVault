//
// Created by RAZEEF on 23-12-2025.
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


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {

    ll n;
    cin >> n;


    vector<ll> curr= {1,0};

    for (int i=2; i<=n; i++) {

        vector<ll> build;

        ll maxi= (1ll<<i)-1;
        build.push_back(maxi);

        for (int j=0;j<curr.size();j++) {
            build.push_back(curr[j]);
        }

        ll l=(1ll<<(i-1));
        ll r= maxi-1;

        for (ll k=l;k<=r;k++) {
            build.push_back(k);
        }

        curr= build;
    }

    for (int i = 0; i < curr.size(); i++) {
        cout << curr[i] << (i == curr.size() - 1 ? "" : " ");
    }
    cout << "\n";


}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

