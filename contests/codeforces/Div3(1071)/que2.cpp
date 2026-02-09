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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll totSum=0;
    for (int i=0;i<n-1;i++) {
        totSum+= abs(a[i]-a[i+1]);
    }

    ll minSum=LINF;

    minSum=min({minSum, totSum-abs(a[0]-a[1]), totSum-abs(a[n-1]-a[n-2])});

    for (int i=1;i<n-1;i++) {

        ll tmpSum=totSum;
        ll contri= abs(a[i]-a[i-1])+abs(a[i]-a[i+1]);

        tmpSum-=contri;

        ll sum= abs(a[i-1]-a[i+1]);
        tmpSum+=sum;

        minSum=min(minSum, tmpSum);
    }

    cout << minSum<<'\n';


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
