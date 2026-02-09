//
// Created by RAZEEF on 17-01-2026.
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

    ll n;
    cin >> n;

    int cnt0=0,cnt1=0;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {

        if (s[i]=='1') cnt1++;
        else cnt0++;
    }

    vll v;
    for (int i=0;i<cnt0;i++) {

        if (s[i]=='1') v.pb(i+1);
    }

    for (int i=cnt0;i<n;i++) {
        if (s[i]=='0') v.pb(i+1);
    }


    if (sz(v)==0) {
        cout<<"Bob"<<'\n';
        return;
    }
    cout<<"Alice"<<'\n';
    cout<<sz(v)<<'\n';

    for (auto it: v) {
        cout<<it<<" ";
    }
    cout<<"\n";


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



