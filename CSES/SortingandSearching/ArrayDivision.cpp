//
// Created by RAZEEF on 26-12-2025.
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
using vll = vector<long long>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


bool check(vll &a,ll k,ll mx) {

    ll sum=0;
    ll c=1;
    for (int i=0;i<sz(a);i++) {
        sum+=a[i];
        if (sum>mx) {
            sum=a[i];
            c++;
        }

        if (c>k) return false;
    }

    if (c>k) return false;

    return true;
}

void solve() {

    ll n,k;
    cin >> n>>k;
    vector<ll> a(n);
    ll maxi=-INF;
    ll totSum=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxi= max(maxi, a[i]);
        totSum+=a[i];
    }

    ll l=maxi;
    ll r=totSum;
    ll ans=0;
    while(l<=r) {

      ll mid = l + (r-l)/2;

      if (check(a,k,mid)) {
          r=mid-1;
          ans=mid;
      }else {
          l=mid+1;
      }
    }

    cout << ans << '\n';

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

