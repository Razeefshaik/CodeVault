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
    cin >> n;

    n=3*n;

    ll s=1, l=n;
    for (int i=0;i<n/3;i++) {
        cout<<s<<" "<<l-1<<" "<<l<<" ";
        s++;
        l-=2;
    }
    cout<<'\n';
    // stack<ll> q;
    // map<ll,ll> mpp;
    // for (int i=n-1;i>=1;i-=2) {
    //     q.push(i);
    //     mpp[i]=1;
    // }
    //
    // if (n/3!=1) {
    //     mpp.erase(q.top());
    //     q.pop();
    // }
    //
    // // for (auto it: mpp) {
    // //     cout<<it.fi<<" ";
    // // }
    // // cout<<endl;
    //
    // multiset<ll> st;
    // for (int i=1;i<=n;i++) {
    //     if (!mpp.count(i)) {
    //         st.insert(i);
    //     }
    // }
    //
    // vll ans;
    // while (!q.empty()) {
    //     ll curr=q.top();
    //     q.pop();
    //
    //     ll a=-1;
    //
    //     a= *st.begin();
    //     st.erase(st.find(a));
    //
    //     ll c=*st.lower_bound(curr);
    //     st.erase(st.find(c));
    //
    //
    //     ans.pb(a);
    //     ans.pb(curr);
    //     ans.pb(c);
    // }
    //
    // for (auto it: ans) {
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
    //
    //




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






