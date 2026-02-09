//
// Created by RAZEEF on 03-01-2026.
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



ll cost(ll num) {

    ll res=0;
    while (num>0) {

        ll d=num%10;
        num/=10;
        res+=d*d;
    }

    return res;
}


void moon() {

    ll n;
    cin >> n;

    map<ll,ll> mpp;

    ll num=cost(n);
    int ans=1;
   while (num!=1) {

        num=cost(num);
        ans++;

       if (mpp.count(num)) {
           cout<<"No"<<endl;
           return;
       }

       mpp[num]=ans;
   }

    cout<<"Yes"<<endl;



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
