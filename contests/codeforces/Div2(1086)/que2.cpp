//
// Created by RAZEEF on 14-03-2026.
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

    ll n,k,p,m;
    cin >>n>>k>>p>>m;
    vector<pair<ll, bool>>  a;
    for (ll i = 0; i < n; i++) {

        ll x;
        cin>>x;
        if (p==(i+1)) {
            a.pb({x, true});
        }else {
            a.pb({x, false});
        }
    }

    ll cnt=0;

    while (true) {

        ll idx=-1;
        ll mini= LINF;
        bool f=false;
        for (int i=0;i<min(k,n);i++) {
            if (a[i].se) {
                idx=i;
                f=true;
                break;
            }
            if (mini>a[i].fi) {
                mini=a[i].fi;
                idx=i;
            }
        }

        m-=a[idx].fi;
        if (m<0) break;
        if (f) {
            cnt++;
        }

        auto it= a[idx];
        a.erase(a.begin()+idx);
        a.pb({it.fi, it.se});

    }

    cout<<cnt<<"\n";





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






