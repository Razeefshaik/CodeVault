// //
// // Created by RAZEEF on 29-03-2026.
// //
//
//
// #include <bits/stdc++.h>
// using namespace std;
//
//
// #define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define ll long long
// #define ld long double
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define sz(x) (int)(x).size()
// #define fi first
// #define se second
//
//
// using pii = pair<int, int>;
// using pll = pair<long long, long long>;
// using vi  = vector<int>;
// using vvi = vector<vector<int>>;
// using vll = vector<long long>;
// using vvll = vector<vector<long long>>;
// using vpi = vector<pair<int,int>>;
// using vpl = vector<pair<long long,long long>>;
// using ppll = pair<ll, pair<ll, ll>>;
//
// const int INF = 1e9 + 7;
// const ll LINF = 1e18;
// const int MOD = 1e9 + 7;
// const ld PI = acos(-1.0);
//
//
//
//
// void moon() {
//
//     ll n;
//     cin >> n;
//     vll a(n), b(n);
//     for (ll i = 0; i < n; i++) cin>>a[i];
//     for (ll i = 0; i < n; i++) cin>>b[i];
//
//     int ans=0;
//     for (int i=0;i<n;i++) {
//
//         if (i==0) {
//
//             int gc= gcd(a[0], a[1]);
//             if (gc<a[0]  && gc!=a[0]) ans++;
//         }else if (i==n-1) {
//             int gc= gcd(a[n-1], a[n-2]);
//             if (gc<b[n-1] && gc!=a[n-1]) ans++;
//         }else {
//             int gc1= gcd(a[i], a[i-1]);
//             int gc2= gcd(a[i], a[i+1]);
//             int lc= lcm(gc1, gc2);
//             if (lc<b[i] && lc!=a[i]) ans++;
//         }
//     }
//
//     cout<<ans<<'\n';
//
// }
//
// int main() {
//     fast_io;
//
//     int t = 1;
//     cin >> t; // Comment this out if there is only 1 test case (no T)
//
//     while(t--) {
//         moon();
//     }
//
//     return 0;
// }
//
//
//
//
//
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n+2), b(n+2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<long long> L(n+2, 0), R(n+2, 0);

        for (int i = 1; i <= n; i++)
            L[i] = gcd(L[i-1], a[i]);

        for (int i = n; i >= 1; i--)
            R[i] = gcd(R[i+1], a[i]);

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            long long g = gcd(L[i-1], R[i+1]);
            long long target = gcd(g, a[i]);

            if (target > b[i]) continue;

            if (target != a[i]) {
                ans++;
            } else {
                if (g != target) {
                    ans++;
                } else {
                    if (2 * g <= b[i]) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}