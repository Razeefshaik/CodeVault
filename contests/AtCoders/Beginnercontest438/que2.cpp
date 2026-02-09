//
// Created by RAZEEF on 27-12-2025.
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
using vll = vector<long long>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);



ll count(string &s, string &t, int idx) {

    ll res = 0;
    for (int i=0;i<sz(t);i++) {
        if (s[i+idx] != t[i]) {

            int sd=s[i+idx]-'0';
            int td= t[i]-'0';

            if (td>sd) {
                res+= sd+10-td;
            }else {
                res+= sd-td;
            }

        }
    }
    return res;
}


void solve() {

    ll n,m;
    cin >> n>>m;
   string s,t;
   cin >> s>>t;

  ll mini = LINF;
    for (int i=0;i<=(sz(s)-sz(t));i++) {

        mini= min(mini, count(s,t, i));
    }

    cout << mini << '\n';

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}
