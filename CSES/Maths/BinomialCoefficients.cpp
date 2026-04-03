//
// Created by RAZEEF on 30-03-2026.
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

ll bino(ll n, ll r) {

    if (r<0 || r>n) return 0;
    if (r==0 || r==n) return 1;

    if (r>(n/2)) r=n-r;
    ll res=1;
    ll num=1, den=1;
    for (ll i = 0; i<r; i++) {

        num= (num*(n-i))%MOD;
        den= (den*(i+1))%MOD;
    }

    ll inv= modInverse(den, MOD);
    return (num*inv)%MOD;
}

ll MAXN=1e6+2;
vll fact(MAXN);
vll inv(MAXN);

void comp() {

    fact[0]=1;
    fact[1]=1;
    for (ll i = 2; i < MAXN; i++) {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    inv[MAXN-1]=modInverse(fact[MAXN-1],MOD);
    for (int i=MAXN-2;i>=1;i--) {
        inv[i]=(inv[i+1]*(i+1))%MOD;
    }
}
ll bino2(ll n, ll r) {

    if (r<0 || r>n) return 0;
    if (r==0 || r==n) return 1;

    if (r>(n/2)) r=n-r;

    ll res= (fact[n]*inv[r])%MOD;
    res= (res*inv[n-r])%MOD;
    return res;
}

void moon() {

    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        ll x,r;
        cin >> x>>r;
        cout<<bino2(x,r)<<'\n';
    }



}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)
     comp();
    while(t--) {
        moon();
    }

    return 0;
}






