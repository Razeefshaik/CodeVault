//
// Created by RAZEEF on 10-01-2026.
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

    ll n,q;
    cin >> n>>q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    map<ll,ll> mpp;
    for(int i = 0; i < n; i++) {
        mpp[a[i]]= a[i]-i-1;
    }

    for (int i=0;i<q;i++) {

        ll base,lim;

        cin >> base >> lim;

        ll countl= lower_bound(all(a), base)-a.begin();
        ll c1= base-countl-1;

        ll c2= c1+lim;

        ll idx=n;
        ll l=0,h=n-1;
        while (l<=h) {
            ll mid= l+(h-l)/2;

            ll miss= a[mid]-(mid+1);

            if (miss>=c2) {
                idx=mid;
                h=mid-1;
            }else {
                l=mid+1;
            }
        }

        cout<<c2+idx<<"\n";
    }



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
