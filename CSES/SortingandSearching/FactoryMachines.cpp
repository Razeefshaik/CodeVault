//
// Created by RAZEEF on 24-12-2025.
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


bool check(ll t,vll &m,ll reqt) {

    ll res = 0;
    for(ll i=0;i<sz(m);i++) {

        res+= t/m[i];
        if (res>=reqt) return true;
    }

    return false;
}



void solve() {

    ll n,reqt;
    cin >> n>>reqt;
    vector<ll> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];

    ll low = 0, high =LINF;
    ll ans=0;
    while (low <=high) {
        ll mid = low + (high-low)/2;
        if(check(mid,m,reqt)) {
            high = mid-1;
            ans=mid;
        }else {
            low = mid+1;
        }
    }
    cout << ans << '\n';


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
