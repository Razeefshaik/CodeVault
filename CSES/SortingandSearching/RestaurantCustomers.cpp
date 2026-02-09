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
    int n;
    cin >> n;
    map<ll,ll> mpp;
    for(int i = 0; i < n; i++){
        ll st,end;
        cin >> st >> end;
        mpp[st]++;
        mpp[end]--;
}

    ll ans=0;
    ll sum=0;
    for(auto it : mpp) {

        sum+=it.se;
        ans= max(ans, sum);
    }

    cout << ans << '\n';


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
