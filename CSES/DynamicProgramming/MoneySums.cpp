//
// Created by RAZEEF on 01-01-2026.
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


set<int> money;

int solve(int idx,int sum, vi &a, vvi &dp) {

      if (idx==sz(a)) {
         if (money.find(sum)==money.end()) {
             money.insert(sum);
             return 1;
         }

          return 0;
      }

      if (dp[idx][sum]!=-1) return dp[idx][sum];

      int count=0;
       count+=solve(idx+1,sum+a[idx],a,dp);
        count+=solve(idx+1,sum,a,dp);

    return dp[idx][sum]=count;

}


void moon() {

    ll n;
    cin >> n;
    vector<int> a(n);

    int sum=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum+=a[i];
    }

    vvi dp(n+1,vi(sum+1, -1));
    solve(0,0,a,dp);

    money.erase(0);
    cout<<money.size()<<'\n';

    for (auto it: money) {
        cout<<it<<' ';
    }
    cout<<'\n';


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

