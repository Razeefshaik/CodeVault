//
// Created by RAZEEF on 19-12-2025.
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


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {
    // Write your solution here
    ll n,m;
    cin >> n>>m;
  //  vector<ll> a(n);
    //for(int i = 0; i < n; i++) cin >> a[i];

    map<ll,map<ll,ll>> mpp;
    multiset<ll> maxi;

    mpp[0][n]=n;
    maxi.insert(n);

    for(int i = 0; i < m; i++) {

        ll l,r;
        ll mid;
        cin >>mid;

        auto itr= mpp.upper_bound(mid);
        --itr;
        l=itr->first;
        r=mpp[l].begin()->first;

        ll len=mpp[l][r];

        ll p1=mid-l;
        ll p2=r-mid;

        mpp.erase(l);
        mpp[l][mid]=p1;
        mpp[mid][r]=p2;
        maxi.insert(p1);
        maxi.insert(p2);

        auto it= maxi.find(len);
        if (it!=maxi.end()) {
            maxi.erase(it);
        }



        cout<<*maxi.rbegin()<<" ";

    }



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

