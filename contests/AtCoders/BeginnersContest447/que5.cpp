//
// Created by RAZEEF on 28-02-2026.
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
//const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


const int MOD = 998244353;


struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void moon() {
    int n, m;
    if (!(cin >> n >> m)) return;


    vector<pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    DSU dsu(n);
    int comp = n;


    for (int i = m; i >= 1; i--) {
        if (comp== 2) break;


        if (dsu.unite(edges[i].first, edges[i].second)) {
            comp--;
        }
    }


    long long cost = 0;
    long long pow2 = 2;

    for (int i = 1; i <= m; i++) {

        if (dsu.find(edges[i].first) != dsu.find(edges[i].second)) {
            cost = (cost + pow2) % MOD;
        }

        pow2 = (pow2 * 2) % MOD;
    }

    cout << cost << "\n";
}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






