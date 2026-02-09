//
// Created by RAZEEF on 01-02-2026.
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

    ll a,b;
    cin >> a>>b;


    // int t1=64-__builtin_clzll(a);
    // int t2=64-__builtin_clzll(b);
    // if (t2>t1) {
    //     cout<<-1<<'\n';
    //     return;
    // }
    //
    // ll x=0;
    //
    //
    // vll temp;
    // t1--;
    // while (t1>0 &&  ((a>>t1)&1)==1 && ((b>>t1)&1)==0 ){
    //
    //
    //
    //     temp.pb((1ll<<t1));
    //
    //     a=a&~(1ll<<t1)  ;
    //     t1--;
    // }
    // for (int i=0;i<=t1;i++) {
    //
    //
    //     ll xr=((a>>i)&1) ^ ((b>>i)&1);
    //
    //     if (xr) {
    //         x|=(1ll<<i);
    //     }
    // }
    //
    // if (x==0) {
    //     cout<<0<<'\n';
    //     return;
    // }
    //
    // cout<<temp.size()+1<<'\n';
    // cout<<x<<" ";
    // for (int i=temp.size()-1;i>=0;i--) {
    //     cout<<temp[i]<<" ";
    // }
    //
    // cout<<'\n';


    if (a == b) {
        cout << 0 << "\n";
        return;
    }


    int msb_a = 63 - __builtin_clzll(a);
    int msb_b = 63 - __builtin_clzll(b);

    if (msb_b > msb_a) {
        cout << -1 << "\n";
        return;
    }


    ll x = a ^ b;
    if (x <= a) {
        cout << 1 << "\n";
        cout << x << "\n";
        return;
    }


    cout << 2 << "\n";
    cout << b << " " << a << "\n";




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






