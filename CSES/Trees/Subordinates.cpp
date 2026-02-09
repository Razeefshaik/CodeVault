//
// Created by RAZEEF on 12-01-2026.
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


vector<int> ans;

int dfs(int node,vector<vector<int>> &adj) {
    if (adj[node].size()==0) return 0;

    int sum=0;
    for (auto x:adj[node]) {
        sum+=(1+dfs(x,adj));


    }

    ans[node]=sum;
    return sum;
}

void moon() {

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++) {
        int x;
        cin >> x ;
        adj[x-1].pb(i);
    }

    ans.resize(n,0);
    dfs(0,adj);
    for (int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }


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
