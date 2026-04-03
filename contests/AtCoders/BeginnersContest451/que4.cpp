//
// Created by RAZEEF on 28-03-2026.
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

    vector<pll> b;
    ll v=1;
    while (v<=1e9) {
        string s=to_string(v);
        ll m=1;
        for (char c: s) m*=10;
        b.pb({m,v});
        v*=2;
    }

    vll gd;
    for (auto it: b) {
        gd.push_back(it.se);
    }


    int h=0;
    while (h<gd.size()) {
        ll curr= gd[h++];
        for (auto it: b) {
            ll nxt= curr*it.fi+ it.se;
            if (nxt<=1e9) {
                gd.pb(nxt);
            }

        }
    }

    sort(all(gd));
    gd.erase(unique(all(gd)), gd.end());

    cout<<gd[n-1]<<'\n';
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






