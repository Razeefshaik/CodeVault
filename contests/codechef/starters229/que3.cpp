//
// Created by RAZEEF on 11-03-2026.
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



ll n,m;
bool check(ll k,ll s) {

    if (k<0) {
        return false;
    }
    if (k==0) return s==0;


    ll mini=1; ll maxi=n;
    if (m==1) mini=2;
    if (m==n) maxi=n-1;

    if (mini>maxi) return false;

    if (s<(k*mini) || s>((k*maxi))) return false;

    if (k==1) return s!=m;

    if (n==3 && m==2) {
        return (s-k)%2==0;
    }

    if (m==2 && s==(k+1)) return false;
    if (m==n-1 && s==(k*n-1)) return false;

    return true;

}



void moon() {

    ll k,s;
    cin >> n>>k>>s>>m;
    vll a(n);
    //for (ll i = 0; i < n; i++) cin>>a[i];


    for (int i=0; i<=k; i++) {

        if (check(k-i, s-(i*m))) {
            cout<<i<<'\n';
            return;
        }
    }

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






