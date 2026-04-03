//
// Created by RAZEEF on 20-03-2026.
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



long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


long long modInverse(long long B, long long M) {
    long long x, y;
    long long g = extended_gcd(B, M, x, y);


    if (g != 1) return -1;


    return (x % M + M) % M;
}


void moon() {

    ll n;
    cin >> n;

    ll sum=0;


    for(ll L=1;L<=n;L++) {

        ll q=n/L;
        ll R= n/q;

        ll num= (((R-L+1)%MOD)*((R+L)%MOD))%MOD;
        num=(q*num)%MOD;
        ll inv=modInverse(2,MOD);

        sum=(sum+num*inv)%MOD;
        L=R;

    }

    cout<<sum<<'\n';


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






