//
// Created by RAZEEF on 30-01-2026.
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


vector<pll> table;
void fill() {

    ll prod=1;
    for (int i=0;i<19;i++) {
        ll val= prod*3+ (i*prod/3ll);
        table.pb({prod, val});

        prod*=3;
    }
}


void moon() {

    ll n;
    cin >> n;

    ll ans=0;
    for(int i = 18; i>=0; i--) {

        ll r= n/table[i].fi;

        ans+= r*table[i].se;
        n-=table[i].fi*r;
    }

    if (n==0) cout<<ans<<'\n';
    else cout<<-1<<'\n';


}

int main() {
    fast_io;
    fill();
    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






