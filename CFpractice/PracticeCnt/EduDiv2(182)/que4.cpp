//
// Created by RAZEEF on 06-03-2026.
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


ll nmax=2*1e5;

void moon() {

    ll n,y;
    cin >> n>>y;
    vll pre(nmax+1,0);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pre[x]++;
    }

    for (int i=1;i<=nmax;i++) pre[i]+=pre[i-1];

    ll ans=-1e18;
    for (ll x=2;x<=nmax;x++) {

        ll cost=0;
        for (ll c=1;c<=(nmax+x-1)/x;c++) {

            ll l= (c-1)*x+1;
            ll r= min(c*x, nmax);

            ll cnt=pre[r]-pre[l-1];
            cost+= cnt*c;
            ll need= max(cnt- (pre[c]-pre[c-1]), 0ll);

            cost-=y*need;
        }
        ans=max(ans, cost);

    }

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






