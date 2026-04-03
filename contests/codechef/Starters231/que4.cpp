//
// Created by RAZEEF on 25-03-2026.
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


ll solve(int l,int r, vll &a, multiset<ll> &st) {
    if ((r-l+1)<=2) {

        ll ans=-LINF;
        for (int i=l;i<=r;i++) {
            ans=max(ans, a[i]);
        }
        return ans;
    }

    ll lmax=a[l];
    for (int i=l;i<l+2;i++) {
        lmax=max(lmax, a[i]);
        if (!st.empty()) st.erase(st.find(a[i]));
    }
    ll rmax=a[r];
    for (int i=r;i>r-2;i--) {
        rmax=max(rmax, a[i]);
        if (!st.empty()) st.erase(st.find(a[i]));
    }


    if (!st.empty()) {
        ll stmin=*st.begin();

        if (stmin<lmax && stmin<rmax) {

            if (lmax<rmax) {
                return solve(l, r-2, a,st);
            }else if (lmax>rmax) {
                return solve(l+2, r, a,st);
            }
        }else {
            return min(lmax, rmax);
        }
    }


}


void moon() {

    ll n;
    cin >> n;
    vll a(n);
    ll maxi=-LINF;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        maxi = max(maxi, a[i]);
    }

    if (n<=2) {
        cout << maxi << '\n';
        return;
    }else if (n==3) {
        ll ans= min(a[0], a[2]);
        ans= max(ans, a[1]);
        cout << ans << '\n';
        return;
    }
   multiset<ll> st;
    for (auto it: a) {
        st.insert(it);
    }
   cout<<solve(0,n-1,a,st)<<'\n';

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






