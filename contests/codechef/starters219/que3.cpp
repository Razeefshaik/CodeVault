//
// Created by RAZEEF on 31-12-2025.
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


ll check(int n) {
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans+=ans%MOD;
    }
    return ans;
}

ll getMin(int l,int r, vll &a,vvll &dpMin) {

    if (l==r) return a[l];
    if (dpMin[l][r]!=-1) return dpMin[l][r];

    ll res=LINF;
    for (int i=l;i<r;i++) {

        ll left=getMin(l,i,a,dpMin);
        ll right=getMin(i+1,r,a,dpMin);
        res=min(res,left+2*right);
    }
    return dpMin[l][r]=res;
}


ll getMax(int l,int r, vll &a,vvll &dpMax) {

    if (l==r) return a[l];
    if (dpMax[l][r]!=-1) return dpMax[l][r];

    ll res=-LINF;
    for (int i=l;i<r;i++) {

        ll left=getMax(l,i,a,dpMax);
        ll right=getMax(i+1,r,a,dpMax);
        res=max(res,left+2*right);
    }
    return dpMax[l][r]=res;
}

void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    check(5);
    vvll dpMin(25, vll(25, -1));
    vvll dpMax(25, vll(25, -1));
     check(5);
    cout << getMin(0, n - 1,a,dpMin) << " " << getMax(0, n- 1,a, dpMax) << endl;


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
