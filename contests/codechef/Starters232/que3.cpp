//
// Created by RAZEEF on 01-04-2026.
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

    ll n,m;
    cin >> n>>m;
    vll a(n);
    ll h=0;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        h=max(h, a[i]);
    }

    ll l=1;
    ll ans=0;
    while (l<=h) {

        ll mid= l+(h-l)/2;
        ll fed = 0;
        for (int i = 0; i < n; ++i) {
            fed += a[i] / mid;
        }

        if (fed>=m) {
            ans = mid;
            l= mid+1;
        }else h=mid-1;
    }

    cout << ans << '\n';


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






