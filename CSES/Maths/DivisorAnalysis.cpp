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


long long power(long long base, long long e, long long MOD) {
    long long res = 1;
    base%= MOD;
    while (e >0) {
        if (e%2 == 1) res = (res*base)%MOD;
        base = (base * base) % MOD;
        e/=2;
    }
    return res;
}


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

    ll num=1,sum=1, prod=1;
    for (ll i = 0; i < n; i++) {
        ll p,e;
        cin >> p >> e;

        ll s=(power(p,e+1,MOD)-1)%MOD;
        ll inv=modInverse(p-1,MOD);
           s= s*inv%MOD;
        sum=(sum*s)%MOD;
        prod= (prod*power(p,e,MOD))%MOD;
        num=num*(e+1)%MOD;


    }

    ll pr= power(prod,num/2, MOD)%MOD;
    if (num%2!=0) {
        pr=pr*prod%MOD;
    }


    cout<<num<<" "<<sum<<" "<<pr;


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






