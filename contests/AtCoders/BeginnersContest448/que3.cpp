//
// Created by RAZEEF on 07-03-2026.
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

    ll n,q;
    cin >> n>>q;

    multiset<ll> st;
    vll v(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i]=x;
        st.insert(x);
    }

    for (int qr=0;qr<q;qr++) {
        ll l;
        cin >> l;
        vector<ll> a;
        for (int li=0;li<l;li++) {
            ll x;
            cin>>x;
            a.push_back(x-1);
            st.erase(st.find(v[x-1]));
        }
        cout<<*st.begin()<<'\n';
        for (auto it: a) {
            st.insert(v[it]);
        }
    }


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






