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




void solve() {

    string s;
    cin >> s;

    ll ans=0;
    ll c=1;
    for(ll i=2;i<sz(s)-1;i++) {

        if (s[i-1]=='u' && s[i]=='u') {
            c++;
        }else {
            ans+=c/2;
            c=1;
        }
    }
    ans+=c/2;

    if (s[0]=='u') ans++;
    if (s[sz(s)-1]=='u') ans++;

    cout << ans<<'\n';

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
