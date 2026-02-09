//
// Created by RAZEEF on 17-12-2025.
//


#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define fi first
#define se second

const ll INF = 1e9 + 7;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const ld PI = acos(-1.0);

void solve() {
    // Write your solution here
    ll n, mxW;
    cin >> n >> mxW;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    ll ans = 0;

    int r=n-1;
    int l=0;
    while (l<=r) {

        if (l!=r && (a[l]+a[r])<=mxW) {
            l++;
            r--;
        }else {
            r--;
        }

        ans++;
    }

    cout << ans << '\n';
}

int main() {
    fast_io;



    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

