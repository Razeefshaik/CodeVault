//
// Created by RAZEEF on 06-02-2026.
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
    vvll a(m+1);
    for (ll i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            ll x;
            cin >> x;
            a[x].pb(i);
        }
    }

    set<int> st;
    for (int i=1;i<=m;i++) {
        if (sz(a[i])==1) st.insert(a[i][0]);
        if (sz(a[i])==0) {
            cout<<"NO"<<'\n';
            return;
        }
    }

    if (sz(st)>n-2) {
        cout <<"NO"<<'\n';
    }else cout <<"YES"<<'\n';


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






