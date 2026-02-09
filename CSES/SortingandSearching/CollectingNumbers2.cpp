// //
// // Created by RAZEEF on 19-12-2025.
// //
// //
// // Created by RAZEEF on 18-12-2025.
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
// const int INF = 1e9 + 7;
// const ll LINF = 1e18;
// const int MOD = 1e9 + 7;
// const ld PI = acos(-1.0);
//
//
//
//
// void solve() {
//     // Write your solution here
//     ll n,m;
//     cin >> n>>m;
//     map<ll, ll> mpp;
//     bool flag=false;
//
//     vector<ll> v(n+1);
//     for(int i = 1; i <= n; i++){
//         ll x;
//         cin>>x;
//         mpp[x]=i;
//         v[i]=x;
//
//     }
//
//
//
//     ll ans=0;
//
//     for (int i=1;i<n;i++) {
//
//         if (mpp[i]>mpp[i+1]) {
//             ans++;
//         }
//
//     }
//
//     for(int i=0;i<m;i++){
//
//       ll x,y;
//       cin>>x>>y;
//
//         ll t1=v[x], t2=v[y];
//         set<ll> st;
//         st.insert(t1);
//         st.insert(t1-1);
//         st.insert(t2);
//         st.insert(t2-1);
//
//         for (auto it: st) {
//
//             if (it>0 && it<n && mpp[it]>mpp[it+1]) {
//                 ans--;
//             }
//
//         }
//
//         swap(v[x], v[y]);
//         ll temp=mpp[t1];
//         mpp[t1]=mpp[t2];
//         mpp[t2]=temp;
//
//         for (auto it: st) {
//
//             if (it>0 && it<n && mpp[it]>mpp[it+1]) {
//                 ans++;
//             }
//
//         }
//         cout<<ans+1<<'\n';
//     }
//
//
//
//
// }
//
// int main() {
//     fast_io;
//
//
//
//     int t = 1;
//     //cin >> t; // Comment this out if there is only 1 test case (no T)
//
//     while(t--) {
//         solve();
//     }
//
//     return 0;
// }
//

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;

    // OPTIMIZATION: Use vector instead of map for O(1) access
    vector<int> mpp(n + 1); // Stores index of value: mpp[val] = index
    vector<int> v(n + 1);   // Stores value at index: v[index] = val

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mpp[x] = i;
        v[i] = x;
    }

    int ans = 1; // Base is 1 round
    for (int i = 1; i < n; i++) {
        if (mpp[i] > mpp[i+1]) {
            ans++;
        }
    }

    while(m--) {
        int x, y;
        cin >> x >> y;

        int t1 = v[x];
        int t2 = v[y];

        // The set ensures we check unique pairs (handles t1, t2 being neighbors)
        set<int> st;
        st.insert(t1);
        st.insert(t1 - 1);
        st.insert(t2);
        st.insert(t2 - 1);

        // 1. Remove old contributions
        for (auto val : st) {
            // Check boundary and condition
            if (val >= 1 && val < n && mpp[val] > mpp[val+1]) {
                ans--;
            }
        }

        // 2. Perform Swap
        swap(v[x], v[y]);      // Update value array
        swap(mpp[t1], mpp[t2]); // Update position array

        // 3. Add new contributions
        for (auto val : st) {
            if (val >= 1 && val < n && mpp[val] > mpp[val+1]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}
