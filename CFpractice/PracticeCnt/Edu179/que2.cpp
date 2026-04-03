//
// Created by RAZEEF on 22-03-2026.
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


vector<int> fibos={1,2,3,5,8,13,21,34,55,89,144,233};

void moon() {

    ll n,m;
    cin >> n>>m;
    vll a= {fibos[n-1], fibos[n-1], fibos[n]};

    for (ll i = 0; i < m; i++) {
        ll w,l,h;
        cin >> w >> l >> h;

        vector<ll> b={w,l,h};
        sort(all(b));

        if (b[0]>=a[0] && b[1]>=a[1] && b[2]>=a[2]) {
            cout<<1;
        }else cout<<0;
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






