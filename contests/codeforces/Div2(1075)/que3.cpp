//
// Created by RAZEEF on 23-01-2026.
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

    ll n,x;
    cin >> n>>x;

    ll maxJ=-LINF;
    ll free=0;
    for(int i = 0; i < n; i++) {

        ll a,b,c;
        cin >> a >> b >> c;

        if (free<x) {
            free+=(b-1)*a;
            if (free>x) free=x;
        }

        maxJ=max(maxJ, (b*a)-c);

    }

    if (free>=x) {
        cout<<0<<'\n';
    }else if (maxJ<=0) cout<<-1<<'\n';
    else {

        ll l=(x-free);
        ll ans= (l+maxJ-1)/maxJ;
        cout<<ans<<'\n';
    }




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






