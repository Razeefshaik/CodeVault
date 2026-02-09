//
// Created by RAZEEF on 07-02-2026.
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

    ll sp=2e5+7;;
    vll v(sp,0);
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        v[x-1]=v[x-1]+1;
    }

    // for (int i=0;i<10;i++) {
    //     cout<<v[i]<<" ";
    // }

      for (int i=sp-2;i>=0;i--) {

          v[i]+=v[i+1];
      }

    // for (int i=0;i<20;i++) {
    //     cout<<v[i]<<" ";
    // }

     vll res;
     for (int i=0;i<sz(v)-1;i++) {

         ll d=v[i]%10;
         ll cry=v[i]-d;
         res.pb(d);
         cry=cry/10;
         v[i+1]=v[i+1]+cry;
         //cout<<v[i]<<" ";

     }

    reverse(all(res));
    int idx=0;
    while (res[idx]==0) {
        idx++;
    }

    for (int i=idx;i<sz(res);i++) {
        cout<<res[i];
    }
    cout<<"\n";



}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






