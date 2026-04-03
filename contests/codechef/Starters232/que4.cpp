//
// Created by RAZEEF on 01-04-2026.
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

    ll n,Q;
    cin >> n>>Q;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n= sz(a);
    vll diff(n-1);
    for (int i=0;i<n-1;i++) {
        diff[i]= a[i+1]-a[i];
    }
    sort(all(diff));
    vll pre(n);
    pre[0]=0;
    for (int i=0;i<n-1;i++) {
        pre[i+1]=pre[i]+diff[i];
    }


    for (int q=0;q<Q;q++) {
        ll x;
        cin>>x;

        auto it=upper_bound(all(diff),x);
        ll idx= distance(diff.begin(),it);

        ll cal= pre[idx]+ (n-idx)*x;
        cout<<cal<<'\n';
    }


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






