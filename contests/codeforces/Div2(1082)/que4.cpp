//
// Created by RAZEEF on 23-02-2026.
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

    ll tot= (n)*(n+1)*(n+2)/6ll;


    stack<pll> st;
    ll cnt=0;
    ll ans=0;
    vll p(n+1,0);
    for (int i=n-1;i>=0;i--) {

        while (!st.empty() && (st.top().fi-1)==a[i]) {
            p[st.top().se]=i+1;
            st.pop();

        }


        st.push({a[i], i+1});
    }

    for (int i=1;i<=n;i++) {
        if (p[i]>=0) {
            cnt+= (p[i]*(n-i+1));
        }
    }
    cout<<tot-cnt<<'\n';

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






