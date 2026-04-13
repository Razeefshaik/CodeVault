//
// Created by RAZEEF on 10-04-2026.
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



class DSU {

    vector<int> parent, size;

public:


    DSU(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }




    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

//
// void moon() {
//
//     ll n,Q;
//     cin >> n>>Q;
//     vvll adj(n);
//     DSU dsu(n);
//     for (ll i = 1; i < n; i++) {
//
//         ll v;
//         cin >> v;
//         v--;
//         adj[v].pb(i);
//         dsu.unionBySize(v, i);
//     }
//
//     ll lvl=0;
//     map<ll,ll> mpp;
//     map<ll, vll> mppnode;
//     queue<ll> q;
//     q.push(0);
//     mpp[0]=lvl;
//     while (!q.empty()) {
//
//          lvl++;
//         ll sz=sz(q);
//         while (sz--) {
//             ll node=q.front();
//             q.pop();
//             for (ll it : adj[node]) {
//                  q.push(it);
//             }
//             mpp[node]=lvl;
//             mppnode[lvl].pb(node);
//         }
//     }
//
//     for (auto it: mpp) {
//         cout << it.first << " " << it.second << "\n";
//     }
//     for (auto it: mppnode) {
//         cout << it.first << " ";
//         for (auto i: it.second) {
//             cout << i << " ";
//         }
//         cout << "\n";
//
//     }
//
//     while (Q--) {
//         ll node,d;
//         cin >> node >> d;
//
//         ll currl=mpp[node]-d;
//
//         if (mppnode.count(currl)) {
//
//             for (auto it: mppnode[currl]) {
//                 if (dsu.findUPar(node)==dsu.findUPar(it)) {
//                     cout<<it<<"\n";
//                     break;
//                 }
//             }
//         }else cout<<-1<<'\n';
//
//     }
//
//
//
// }


void moon() {
    ll n,Q;
    cin>>n>>Q;

    vvll dp(30, vll(n,0-1));
    for (int i=1;i<n;i++) {
        ll x;
        cin>>x;
        x--;
        dp[0][i]=x;
    }
    for (int i=1;i<30;i++) {
        for (int j=0;j<n;j++) {
            if (dp[i-1][j]!=-1) {
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }else dp[i][j]=-1;
        }
    }

    while (Q--) {
        ll node,k;
        cin>>node>>k;
        node--;

        int x=node;
        for (int i=0;i<30;i++) {
            if (k&(1<<i)) {
               x=dp[i][x];
            }

            if (x==-1) break;
        }

        if (x==-1) cout<<-1<<'\n';
        else cout<<x+1<<'\n';

    }
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






