//
// Created by RAZEEF on 05-01-2026.
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


int solve(int idx,vi &l,vi&r,vi &h, vi &dp) {

    if (idx==-1) return 0;
    if (dp[idx]!=-1) return dp[idx];

    return dp[idx]=1+max(solve(l[idx],l,r,h,dp), solve(r[idx],l,r,h,dp));
}


void moon() {

    int n;
    cin >> n;
    vi h(n);
    for(int i = 0; i < n; i++) cin >> h[i];


    vi l(n,-1),r(n,-1);
    stack<int> st;
    for(int i = 0; i < n; i++) {

        while (!st.empty() && h[st.top()]<=h[i]) {
            st.pop();
        }


        if (!st.empty()) l[i]=st.top();
        st.push(i);
    }

    stack<int> st2;
    for(int i = n-1; i >= 0; i--) {
        while (!st2.empty() && h[st2.top()]<=h[i]) {
            st2.pop();
        }

        if (!st2.empty()) r[i]=st2.top();
        st2.push(i);
    }

    vi dp(n+1, -1);
    int ans = 0;
    for (int i=0;i<n;i++) {
        ans= max(ans, solve(i,l,r,h,dp));
    }

    cout << ans << '\n';

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
