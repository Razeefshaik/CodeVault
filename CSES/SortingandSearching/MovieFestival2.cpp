//
// Created by RAZEEF on 26-12-2025.
//
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
    ll n,k;
    cin >> n>>k;
    vector<pair<int, int>> movies(n);
    for(int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first; // Read start, end -> Store end, start
    }

    sort(movies.begin(), movies.end());

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>  pq;
    ll ans = 0;
    //ll lastEnd=arr[0].se;
    for(ll i = 0; i < n; i++) {

       while (!pq.empty() && pq.top().fi <= movies[i].se) pq.pop();

        if (pq.size()<k) {
            pq.push(movies[i]);
            ans++;
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

