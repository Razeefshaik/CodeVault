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

    ll n,k;
    cin >> n>>k;
    vll a(n);
    for(int i=0;i<n;i++)  cin >> a[i];
    set<ll> st;

    sort(all(a));
     ll idx= (n-1)/2;
     st.insert(a[idx]);

    ll b=0;
    if (n%2!=0) b=1;
    ll l=idx, r=idx;
    while (k--) {

        if (b==0) {
            l++;
            st.insert(a[l]);
            b=1-b;
        }else {
            r--;
            st.insert(a[r]);
            b=1-b;
        }
    }

    for (auto i:st) {
        cout<<i<<" ";
    }
    cout<<'\n';


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






