//
// Created by RAZEEF on 26-02-2026.
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



bool sqq(long long n) {
    if(n < 0) return false;

    long long r = sqrt(n);
    return (r * r == n);
}

ll sq(ll n) {
    if(n < 0) return false;

    long long r = sqrt(n);
    return r;
}

ll smf(ll n) {
    if (n<= 1) return n;
    if (n %2==0) return 2;

    for (long long i =3;i*i <=n; i+=2) {
        if (n%i==0)
            return i;
    }

    return n;
}

vector<int> smallprimefactors() {

    const int MAXN=1000006;
    vector<int> spf(MAXN);

    for (int i=0;i<MAXN;i++) {
        spf[i]=i;
    }

    for (int i=2;i*i<MAXN;i++) {

        if (spf[i]==i) {

            for (int j=i*i;j<MAXN;j+=i) {
                if (spf[j]==j) spf[j]=i;
            }
        }
    }

    return spf;
}


vector<long long> pmfs(long long n) {
    vector<long long> factors;


    while(n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }


    for(long long i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }


    if(n > 1)
        factors.push_back(n);

    return factors;
}

void moon() {

    ll n;
    cin >> n;

    vll b=pmfs(n);

    set<ll> s;
    for(ll i=0;i<sz(b);i++) {
        s.insert(b[i]);
    }

    ll res=1;

    for(auto it: s) {
        res*=it;
    }
    cout << res << '\n';



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






