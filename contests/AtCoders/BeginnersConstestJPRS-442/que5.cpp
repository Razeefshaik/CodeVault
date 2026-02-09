// //
// // Created by RAZEEF on 24-01-2026.
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
// double getAngleInDegrees(double x1, double y1, double x2, double y2) {
//     double dy = y2 - y1;
//     double dx = x2 - x1;
//     double angleInRadians = std::atan2(dy, dx);
//     double angleInDegrees = angleInRadians * 180.0 / M_PI;
//     if (angleInDegrees < 0) {
//         angleInDegrees += 360;
//     }
//     return angleInDegrees;
// }
//
// void moon() {
//
//     ll n,q;
//     cin >> n>>q;
//     vector<pair<ld, ll>> pos;
//     for(int i = 1; i <=n; i++) {
//         double x,y;
//         cin >> x >> y;
//         ld ang=atan2(y,x);
//         pos.pb({ang,i});
//
//     }
//
//     sort(all(pos), [](const pair<ld, int>& a, const pair<ld, int>& b) {
//         return a.first > b.first;
//     });
//
//     vector<pair<ld, int>> groups;
//     map<ll,ll> mpp;
//
//     for (auto& p : pos) {
//
//         if (groups.empty() || abs(groups.back().first - p.first) > 1e-9) {
//             groups.pb({p.first, 1});
//         } else {
//
//             groups.back().second++;
//         }
//
//         mpp[p.second] = groups.size() - 1;
//     }
//
//     int m = groups.size();
//     vector<ll> pref(m + 1, 0);
//     for(int i = 0; i < m; i++) {
//         pref[i+1] = pref[i] + groups[i].second;
//     }
//
//
//     for (int i=0;i<q;i++) {
//         ll x,y;
//         cin >> x >> y;
//
//         ll sidx=mpp[x];
//         ll eidx=mpp[y];
//
//
//         ll ans=0;
//         if (sidx==eidx) {
//             ans=groups[sidx].se;
//         }else if (sidx < eidx) {
//
//             ans = pref[eidx+1] - pref[sidx];
//         }
//         else {
//
//             ll part1 = pref[m] - pref[sidx];
//             ll part2 = pref[eidx+1];
//             ans = part1 + part2;
//         }
//
//         cout << ans << "\n";
//
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
//     int t = 1;
//     //cin >> t; // Comment this out if there is only 1 test case (no T)
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

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()

struct Monster {
    int id;
    ll x, y;
    ld ang;
};

bool isSameDirection(const Monster& a, const Monster& b) {
    if (a.x * b.y != a.y * b.x) return false;
    if (a.x * b.x + a.y * b.y <= 0) return false;
    return true;
}

void moon() {
    int n, q;
    cin >> n >> q;

    vector<Monster> monsters;
    monsters.reserve(n);

    for(int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        ld ang = atan2((ld)y, (ld)x);
        monsters.push_back({i, x, y, ang});
    }

    sort(all(monsters), [](const Monster& a, const Monster& b) {
        return a.ang > b.ang;
    });

    vector<int> groupCounts;
    vector<int> idToGroupIndex(n + 1);

    Monster* currentGroupRep = nullptr;

    for (auto& m : monsters) {
        if (groupCounts.empty() || !isSameDirection(*currentGroupRep, m)) {
            groupCounts.push_back(1);
            currentGroupRep = &m;
        } else {
            groupCounts.back()++;
        }

        idToGroupIndex[m.id] = groupCounts.size() - 1;
    }

    int m = groupCounts.size();
    vector<ll> pref(m + 1, 0);
    for(int i = 0; i < m; i++) {
        pref[i+1] = pref[i] + groupCounts[i];
    }

    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        int s = idToGroupIndex[u];
        int e = idToGroupIndex[v];

        ll ans = 0;

        if (s == e) {
            ans = groupCounts[s];
        }
        else if (s < e) {
            ans = pref[e+1] - pref[s];
        }
        else {
            ll part1 = pref[m] - pref[s];
            ll part2 = pref[e+1];
            ans = part1 + part2;
        }

        cout << ans << "\n";
    }
}

int main() {
    fast_io;
    moon();
    return 0;
}
