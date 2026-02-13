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
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


int cnt(string &a, string &b, int bit) {

    int n=a.size();
    int c=0;
    for (int i=0;i<n;i++) {
        if (bit) {
            if (a[i]=='0') c++;
        }else {
            if (b[i]=='0') c++;
        }
        bit=1-bit;
    }
    return c;
}

void moon() {

    ll n;
    cin >> n;
    string a,b;
    cin>>a;
    cin>>b;

    if (cnt(a,b,1)>=((n+1)/2) && cnt(a,b,0)>=n/2) {
        cout<<"YES"<<'\n';

    }else {
        cout<<"NO"<<'\n';
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






