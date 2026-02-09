//
// Created by RAZEEF on 28-12-2025.
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
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


ll solve(int idx,ll sum,vll &a,  unordered_map<ll, unordered_map<ll,ll>>& dp) {

    if (sum==0) return 0;
    if (idx>=sz(a)) return LINF;
    if (dp.count(idx) && dp[idx].count(sum)) return dp[idx][sum];
    ll p=LINF,np=LINF;

    if (a[idx]<=sum) {
        p=1+solve(idx,sum-a[idx],a,dp);
    }
    np=solve(idx+1,sum,a,dp);

    return dp[idx][sum]=min(p,np);
}

int solvedp(int n,int tar, vll &a) {

    vector<vector<int>> dp(n+1,vector<int>(tar+1, INF));
    for (int i=0;i<=n;i++) {
        dp[i][0]=0;
    }

    for (int i=n-1;i>=0;i--) {

        for (int sum=1;sum<=tar;sum++) {

            int np=dp[i+1][sum];

            int p=INF;
            if (a[i]<=sum) {

                if (dp[i][sum-a[i]]!=INF) {
                    p=1+dp[i][sum-a[i]];
                }
            }

            dp[i][sum]=min(p,np);
        }
    }

    return dp[0][tar];
}

void moon() {

    ll n, tar;
    cin >> n>>tar;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

   // vvll dp(sz(a), vll(tar+1,-1));

   // unordered_map<ll, unordered_map<ll,ll>> mpp;

    //ll res=solve(0,tar,a,mpp);

    int res=solvedp(n,tar,a);
    if (res==INF) cout<<-1<<endl;
    else cout <<res << '\n';

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
