//
// Created by RAZEEF on 04-04-2026.
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
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
   // int n=sz(s);
    for(int i=0;i<sz(s);i++) {
        if (i+4<n) {
            string t;
            for (int j=0;j<5;j++) {
                t+=s[i+j];
            }
            if (t=="mapie") {
                cnt++;
                i+=4;
            }
        }
        if (i+2<n) {
            string t;
            for (int j=0;j<3;j++) {
                t+=s[i+j];
            }
            if (t=="map" || t=="pie") {
                cnt++;
                i+=2;
            }
        }
    }
    cout<<cnt<<"\n";


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






