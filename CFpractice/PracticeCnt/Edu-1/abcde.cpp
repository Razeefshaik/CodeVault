//
// Created by RAZEEF on 10-03-2026.
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


double ang(double x, double y) {

    double angle = atan2(y, x);
    // if(angle < 0)
    //     angle += 2 * PI;


    return angle;
}
void moon() {
    ll n;
    cin >> n;

    vector<pair<double , ll>> v;
    for (ll i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.pb({ang(x,y), i});
    }

    // Sort vectors by their angles
    sort(all(v));

    double ans = 1e18;
    ll p = -1;
    ll p2 = -1;

    // 1. Check all adjacent pairs
    for (int i = 1; i < sz(v); i++) {
        double diff = v[i].fi - v[i-1].fi;
        if (diff < ans) {
            ans = diff;
            p = v[i].se;
            p2 = v[i-1].se;
        }
    }

    // 2. Check the wrap-around pair (last element and first element)
    // Since you converted to degrees, a full circle is 360.0
    double wrap_diff = 360.0 - (v[n-1].fi - v[0].fi);
    if (wrap_diff < ans) {
        ans = wrap_diff;
        p = v[n-1].se;
        p2 = v[0].se;
    }

    // Output 1-based indices
    cout << p + 1 << " " << p2 + 1 << '\n';
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