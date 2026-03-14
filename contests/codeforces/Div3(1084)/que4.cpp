//
// Created by RAZEEF on 27-02-2026.
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


int midx(int x,int y,vll &a) {

    ll mini=a[x];
    ll idx=x;
    for (ll i = x; i < y; i++) {
        if (a[i]<mini) {
            mini=a[i];
            idx=i;
        }
    }

    return idx;
}

void moon() {

    ll n,x,y;
    cin >> n>>x>>y;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];




    int idx=midx(x,y,a);

    vll b;
    if (x < y) {
        for (int i = idx; i < y; i++) {
            b.pb(a[i]);
        }
        for (int i = x; i < idx; i++) {
            b.pb(a[i]);  
        }
    }

    vll comb;
    for (int i=0;i<x;i++) {
        comb.pb(a[i]);
    }
    for (int i=y;i<n;i++) {
        comb.pb(a[i]);
    }


    //int idx1=midx(0,sz(comb),comb);  //fck meeeeee meowwwwwwwwwwwwwwwwww
    int check=b[0];
    int idx1=sz(comb);
    if (sz(b)>0 && sz(comb)>0) {
        for (int i = 0; i < sz(comb); i++) {
            if (comb[i] > check) {  //meowwwwww
                idx1 = i;
                break; //meowwwwwwww
            }
        }
    }

    vll ans;
    for (int i=0;i<idx1;i++) {
        ans.pb(comb[i]);
    }

    for (int i=0;i<sz(b);i++) {
        ans.pb(b[i]);
    }
    for (int i=idx1;i<sz(comb);i++) {
        ans.pb(comb[i]);
    }

    for (auto i:ans) {
        cout<<i<<" ";
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






