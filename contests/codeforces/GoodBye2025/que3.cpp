//
// Created by RAZEEF on 27-12-2025.
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




void solve() {

    ll n;
    cin >> n;
    vll v(n);
    for(int i = 0; i < n; i++) {
       // ll x;
        cin >>v[i];

    }


    vll sf(n+1,0);
    for (int i=n-1;i>=0;i--) {
        sf[i]=sf[i+1]-v[i];
    }


    vll pf(n+1, 0);
    for (int i=n-2;i>=0;i--) {
        pf[i]=pf[i+1]-v[i];
    }


    ll res=-LINF;
    ll currSum=0;
    for(int i=0;i<n;i++) {

        ll currScore=0;

        for(int j=0;j<2;j++) {
            ll ff=0;
            ff++;
        }

        if (i==0) {
            currScore=sf[1];
        }else {
            currScore=v[0]+currSum+sf[i+1];
            currSum+= abs(v[i]);
        }

        res=max(res,currScore);
    };



    //ll res=max(res1, res2);

    cout << res<<'\n';


}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

