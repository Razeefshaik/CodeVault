//
// Created by RAZEEF on 14-02-2026.
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
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

    vector<ll> prelcm(n), sufflcm(n);
    ll mod=998244353;

    ll plcm=a[0];
    prelcm[0]=a[0];
    for (ll i = 1; i < n; i++) {
         plcm = lcm(plcm, a[i]);
         prelcm[i]=plcm;

    }

    ll slcm=a.back();
    sufflcm[n-1]=slcm;
    for (ll i = n-1; i >= 0; i--) {
        slcm = lcm(slcm, a[i]);
        sufflcm[i]=slcm;
    }

    for (int i=0;i<n;i++) {

        ll rem;
        if (i-1>=0 && i+1<n) {

            ll l=lcm(prelcm[i-1],sufflcm[i+1]);
            rem= ((l+mod)%mod);
            cout<<rem<<" ";
        }else if (i-1>=0) {
            ll l=prelcm[i-1];
            rem= ((l+mod)%mod);
            cout<<rem<<" ";
        }else if (i+1<n) {
            ll l=sufflcm[i+1];
            rem= ((l+mod)%mod);
            cout<<rem<<" ";
        }

    }
    cout<<'\n';

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






