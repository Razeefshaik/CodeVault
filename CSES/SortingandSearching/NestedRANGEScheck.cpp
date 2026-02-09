//
// Created by RAZEEF on 23-12-2025.
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


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


 struct Range {
     ll l,r, id;

 };


void solve() {

    ll n;
    cin >> n;
    vector<Range> a(n);
    for(int i = 0; i < n; i++){

        ll l,r;
        cin >> l >> r;
        a[i].id=i;
        a[i].l=l;
        a[i].r=r;
    }

    vector<ll> b(n,0);
    vector<ll> c(n,0);
    sort(all(a), [](const Range &a, const Range &b) {

        if (a.l == b.l ) {
            return a.r > b.r;
        }
        return a.l < b.l;
    });

    ll mini=LINF, maxi=-LINF;
    for (int i=n-1; i >= 0; i--) {

        if (a[i].r>=mini) {
            b[a[i].id]=1;

        }
        mini= min(mini, a[i].r);
    }
    for (int i=0;i<n;i++) {
        if (a[i].r<=maxi) {
            c[a[i].id]=1;

        }
        maxi=max(maxi,a[i].r);
    }

    for (int i=0;i<n;i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i=0;i<n;i++) {
        cout << c[i] << " ";
    }
    cout << endl;



}

int main() {
    fast_io;

    int t = 1;
    //   cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

