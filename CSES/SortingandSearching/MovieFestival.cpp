//
// Created by RAZEEF on 18-12-2025.
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




void solve() {
    // Write your solution here
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(int i = 0; i < n; i++){

         ll st,end;
        cin >> st >> end;
        arr[i] = make_pair(st,end);
    }

    sort(all(arr),[](const pair<ll, ll> a, const pair<ll, ll> b) {
                 if (a.se==b.se) return a.fi>b.fi;
                  return a.se<b.se;
    });

    ll ans = 1;
    ll lastEnd=arr[0].se;
    for(ll i = 1; i < n; i++) {
        if(arr[i].fi>=lastEnd) {
            ans++;
            lastEnd = arr[i].se;
        }
    }

    cout << ans;


}

int main() {
    fast_io;



    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

