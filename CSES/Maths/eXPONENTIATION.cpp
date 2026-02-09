//
// Created by RAZEEF on 26-01-2026.
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

    ll a,b;
    cin >> a>>b;
    vector<ll> pre(32,0);

    pre[0]=a;
    for(int i=1;i<32;i++) {
        pre[i]= (pre[i-1]*pre[i-1])%MOD;
    }

    ll ans=1;
    for(int i=0;i<32;i++) {

        if (b&(1ll<<i)) {
            ans= (ans*pre[i])%MOD;
        }
    }

    ans= ans%MOD;
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






