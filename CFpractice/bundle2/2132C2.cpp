//
// Created by RAZEEF on 30-01-2026.
//
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


ll solve(int idx,ll num,ll k, map<ll,ll>& mpp) {


    if (num==0) return 0;
    if (idx>=19 || num<0) return LINF;

    ll key= (idx<<60) | (num<<30) | k;
    if (mpp.count(key)) {
        return mpp[key];
    }

    ll pick=LINF;
    //ll pr= num/table[idx].fi;

      if (k-1>=0) {
          pick= (table[idx].se)+solve(idx, num-(table[idx].fi), k-1, mpp);
      }


    ll noPick=solve(idx+1, num,k,mpp);

    return mpp[key]= min(pick , noPick);
}


void moon() {

    ll n,k;
    cin >> n>>k;

    ll ans=0;
    map<ll,ll> mpp;

    ans= solve(0,n,k,mpp);

    if (ans!=LINF) cout<<ans<<'\n';
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






