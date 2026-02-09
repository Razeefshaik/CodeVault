//
// Created by RAZEEF on 31-12-2025.
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


ll solvedp(string &a, string &b) {

    int n=sz(a), m=sz(b);

    vvll dp(n+1, vll(m+1, LINF));

    int al=n-1, bl=m-1;
    for(int i=0;i<=n;i++) {
       dp[i][m]=n-i;
    }
    for(int j=1;j<=m;j++) {
        dp[n][j]=m-j;
    }

    for(int al=n-1;al>=0;al--) {
       for(int bl=m-1;bl>=0;bl--) {
           if (a[al]==b[bl]) {

               dp[al][bl]= dp[al+1][bl+1];
           }else {

               dp[al][bl]= 1+min({dp[al+1][bl], dp[al][bl+1], dp[al+1][bl+1]});
           }

       }
    }

    cout << dp[0][0] << '\n';

 return 0;

}

void moon() {

    string a,b;
    cin>>a>>b;
    solvedp(a,b);


}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}

