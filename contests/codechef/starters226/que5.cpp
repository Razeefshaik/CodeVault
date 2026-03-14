//
// Created by RAZEEF on 19-02-2026.
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
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

    map<int ,int> mpp;
    for(auto it : a) mpp[it]++;

    vi dist;
    vi ans(n, - 1);
    for(auto it : mpp) dist.pb(it.fi);
    for (int i=0;i<sz(dist);i++) {
        int u=dist[i];
        int v=dist[(i+1)%sz(dist)];
        ans[u-1]=v;
        mpp[v]--;

    }


    stack<int> st;
    for (auto it :mpp) {

        if (mpp[it.fi]!=0) {
            while (mpp[it.fi]--) st.push(it.fi);
        }
    }

    for (int i=0;i<n;i++) {
        if (ans[i]==-1) {
            ans[i]=st.top();
            st.pop();
        }
    }

    for (auto it: ans) {
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






