//
// Created by RAZEEF on 03-01-2026.
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


    vector<ll> count(n+1);

    ll idx=1;

    while((2*idx*idx)<=n) {

        ll x=idx*idx;

        for (ll y=idx+1;;y++) {

            ll s=x+y*y;
            if (s>n) break;
            count[s]++;
        }

      idx++;

    }


    ll ans=0;
    for(ll i=0;i<=n;i++) {
        if (count[i]==1) ans++;
    }

    cout << ans << '\n';
    for (ll i=0;i<=n;i++) {
        if (count[i]==1) {
            cout<<i<<" ";
        }
    }
    cout<<"\n";



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
