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




void moon() {

    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];


    vector<vector<ll>> b;
    int l=0;

    for (int i = 1; i < n; i++) {
        if (a[i-1]!=a[i]) {
            b.pb({l,i-1, a[i-1]});
            l=i;
        }
    }
    b.pb({l,n-1,a[n-1]});

   // for (auto it: b) {
   //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<'\n';
   // }

    ll mini=LLONG_MAX;
    for (auto it: b) {

        mini=min(mini, (it[0]*it[2] + (n-it[1]-1)*it[2]));
    }
    cout << mini << '\n';


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






