//
// Created by RAZEEF on 25-12-2025.
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
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {

    ll n, tar;
    cin >> n>>tar;
    vector<ll> a(n);
    map<ll,vi> idxMpp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        idxMpp[a[i]].pb(i);
    }

    sort(all(a));
    for (int i=0; i<n; i++) {

        ll l=i+1, r=n-1;
        if (i>0 && a[i]==a[i-1]) { continue;}

        while (l<r) {
            ll sum= a[i]+a[l]+a[r];



            if (sum==tar) {
                cout<<idxMpp[a[i]].back()+1<<" ";
                idxMpp[a[i]].pop_back();
                cout<<idxMpp[a[l]].back()+1<<" ";
                idxMpp[a[l]].pop_back();
                cout<<idxMpp[a[r]].back()+1<<'\n';
                return;
            }else if (sum>tar) {
                r--;
            }else {
                l++;
            }
        }

    }

    cout<<"IMPOSSIBLE"<<'\n';




}

int main() {
    fast_io;

    int t = 1;
    // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

