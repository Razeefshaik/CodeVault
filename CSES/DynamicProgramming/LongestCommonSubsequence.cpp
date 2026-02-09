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


void solvedp(vll &a, vll &b) {
    int n = sz(a);
    int m=sz(b);

    vvll dp(n+1, vll(m+1, 0));


    for (int i=n-1;i>=0;i--) {
        for (int j=m-1;j>=0;j--) {

            if (a[i]==b[j]) {
                dp[i][j]=1+dp[i+1][j+1];
            }else {
                dp[i][j]= max({ dp[i+1][j], dp[i][j+1]});
            }
        }
    }

    int pa=0,pb=0;
    vi res;
    while (pa<n && pb<m) {

        if (a[pa]==b[pb]) {
            res.pb(a[pa]);
            pa++,pb++;
        }else {

            if (dp[pa+1][pb]>=dp[pa][pb+1]) {
                pa++;
            }else {
                pb++;
            }

        }
    }

    cout<<dp[0][0]<<endl;
    for (auto it: res) {
        cout<<it<<" ";
    }
    cout<<endl;


}

void moon() {

    ll n,m;
    cin >> n>>m;
    vector<ll> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    solvedp(a,b);


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

