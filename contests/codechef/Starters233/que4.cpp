//
// Created by RAZEEF on 08-04-2026.
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

    string s;
    cin >> s;

    vector<bool> dp(n);
    ll cnt=0;
    for (int i=0;i<n;i++) {

        int p= i==0? n-1:i-1;
        int nxt=i==n-1? 0:i+1;

        if (s[i]!=s[p] && s[i]!=s[nxt]) {
            cnt++;
            dp[i]=true;
        }
    }

    if (cnt==n) {
        cout<<-1<<'\n';
        return;
    }

    ll len=0;
    ll maxi=0;
    for (int i=0;i<2*n;i++) {

        if (dp[i%n]) {
            len++;
            maxi=max(maxi, len);
        }else len=0;
    }

    cout<<(maxi+1)/2+1<<'\n';




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






