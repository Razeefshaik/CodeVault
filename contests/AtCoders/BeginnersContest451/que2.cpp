//
// Created by RAZEEF on 28-03-2026.
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

    ll n,m;
    cin >> n>>m;

    map<ll,multiset<ll>> mpp1;
    vector<int> prev(n+1, -1);
    vector<pll> arr(n);
    for (int i=0;i<n;i++) {
        ll a,b;
        cin >> a >> b;
       arr[i]= {a,b};


    }

    for (int i=0;i<n;i++) {

        ll p= arr[i].first;
        mpp1[p].insert(i);
        prev[i]= p;
    }

    vector<ll> first(m+1, 0);
    for (int i=1;i<=m;i++) {
          first[i]= sz(mpp1[i]);
    }

    for (int i=0;i<n;i++) {

        ll p= arr[i].second;

        if (p!=prev[i]) {
            mpp1[prev[i]].erase(i);
            prev[i]= p;
            mpp1[p].insert(i);
        }

    }

    vector<ll> second(m+1, 0);
    for (int i=1;i<=m;i++) {
        second[i]= sz(mpp1[i]);
    }
    for (int i=1;i<=m;i++) {
        cout<<second[i]-first[i]<<" ";
    }
    cout<<"\n";




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






