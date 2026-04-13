//
// Created by RAZEEF on 07-04-2026.
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

    ll n,k;
    cin >> n>>k;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];
    map<ll,ll> mpp;

    ll idx=0;
    for (int i=0;i<k;i++) {
        ll x;
        cin>>x;
        x--;
        mpp[x]++;
        idx=x;
    }


    ll t= a[idx];
    vll pre;
    ll c=0;
    for (ll i = 0; i <=n; i++) {

        if (i==0) {
            if (a[0]!=t) c++;
        }else if (i==n) {
            if (a[n-1]!=t) c++;
        }
         else {
             if (a[i-1]!=a[i]) {
                 c++;
             }
         }
        if (mpp.count(i)) {
            pre.pb(c);
            c=0;
        }

    }
    pre.pb(c);

    ll maxi=0;
    ll sum=0;
    for (int i=0;i<sz(pre);i++) {
        maxi=max(maxi,pre[i]);
        sum+=pre[i];
    }

    cout<<max(maxi, sum/2)<<'\n';

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






