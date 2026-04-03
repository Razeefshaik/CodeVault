//
// Created by RAZEEF on 29-03-2026.
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

    ll n;
    cin >> n;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++) cin>>a[i];
    for (ll i = 0; i < n; i++) cin>>b[i];

    int ans=0;
    for (int i=0;i<n;i++) {

        if (i==0) {

            int gc= gcd(a[0], a[1]);
            if (gc<a[0]) ans++;
        }else if (i==n-1) {
            int gc= gcd(a[n-1], a[n-2]);
            if (gc<a[n-1]) ans++;
        }else {
            int gc1= gcd(a[i], a[i-1]);
            int gc2= gcd(a[i], a[i+1]);
            int lc= lcm(gc1, gc2);
            if (lc<a[i]) ans++;
        }
    }

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






