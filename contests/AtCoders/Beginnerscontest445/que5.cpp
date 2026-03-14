//
// Created by RAZEEF on 14-02-2026.
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
const int MOD = 998244353;
const ld PI = acos(-1.0);


vector<int> spf;

vector<int> smallPrimeFactors() {

    int MAXN= 1e8;
    vector<int> spf;
    for (int i=1;i<MAXN;i++) {
        spf[i]=i;
    }


    for (int i=2;i<MAXN;i++) {
      if (spf[i]==i) {
          for (int j=i;j<MAXN;j+=i) {
              if (spf[j]==j) spf[j]=i;
          }
      }
    }

    return spf;
}

map<ll, ll> primefactors(ll num) {

    map<ll, ll> mpp;
    while (num>0) {
        ll p=spf[num];
        int exp=0;
        while (num%p==0) {
            num/=p;
            exp++;
        }
        mpp[p]=exp;
    }

    return mpp;
}

ll powr(ll num, int exp) {

    ll res=1;
    for (int i=0;i<exp;i++) {
        res= (res*num)%MOD;
    }
    return res%MOD;
}

void moon() {


    ll n;
    cin>>n;
    vector<ll> a(n);
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }


    map<ll, map<ll, ll>> mpp;
    map<ll ,ll> maxExps;
    for (int i=0;i<n;i++) {
        ll num=a[i];
        map<ll ,ll> exps=primefactors(num);
        for (auto it: exps) {
            maxExps[it.fi]=max(maxExps[it.fi],it.se);
        }
    }

    ll totLcm=1;
    for (auto it: maxExps) {
        ll res=powr(it.fi, it.se);
        totLcm= (res*totLcm)%MOD;
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






