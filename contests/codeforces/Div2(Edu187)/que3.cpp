//
// Created by RAZEEF on 25-02-2026.
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


bool yes(ll n, ll s, vll &tws) {

    ll rem=s;

    for (auto it: tws) {
        ll t= n;
        if ((rem/it)<n) t=rem/it;
        rem-=(t*it);
    }

    if (rem==0) return true;
    else return false;
}

void moon() {

    ll s,m;
    cin >> s>>m;

    vll b;

     vll idxs;
    ll temp=m;
      while (temp>0) {

          idxs.pb(temp%2);
          temp/=2;

      }


    for (int i=0;i<idxs.size();i++) {

        if (idxs[i]==1) {
            b.pb(1ll<<i);
        }

    }

    reverse(all(b));


    ll h=1e18+2;
    ll l=0;
    bool f=true;
    ll ans=0;
    while (l<=h) {

        ll md= l+(h-l)/2;
        if (yes(md,s,b))  {
            ans=md;
            f=false;
            h=md-1;
        }else {
            l=md+1;
        }
    }

    if (f) {
        cout<<-1<<'\n';
        return;
    }


    cout << ans << '\n';




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






