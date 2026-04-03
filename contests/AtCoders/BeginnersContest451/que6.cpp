//
// Created by RAZEEF on 28-03-2026.
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

    vector<int> parent, size, coldiff;
    vvi cnt;

public:

   ll curr;
   bool check;

    DSU(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);
        coldiff.resize(n+1,0);
        cnt.assign(n+1, vi(2,0));

        curr=0;
        check=true;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            cnt[i][0]=1;
            cnt[i][1]=0;
        }
    }


    int findUPar(int node) {
        if (node == parent[node])
            return node;

        int p=parent[node];
        int root=findUPar(p);

        coldiff[node]^=coldiff[p];

        return parent[node] = root;
    }




    void unionBySize(int u, int v) {

        if (!check) return;

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v){
             if (coldiff[u]==coldiff[v]) {
                 check=false;
             }
            return;

         }


        if (size[ulp_u] < size[ulp_v]) {
            swap(ulp_u, ulp_v);
            swap(u, v);
        }

        int f=coldiff[u]^coldiff[v]^1;

        curr-=min(cnt[ulp_u][0],cnt[ulp_u][1]);
        curr-=min(cnt[ulp_v][0],cnt[ulp_v][1]);

        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
        coldiff[ulp_v]=f;

        if (f == 0) {
            cnt[ulp_u][0] += cnt[ulp_v][0];
            cnt[ulp_u][1] += cnt[ulp_v][1];
        } else {
            cnt[ulp_u][0] += cnt[ulp_v][1];
            cnt[ulp_u][1] += cnt[ulp_v][0];
        }


        curr += min(cnt[ulp_u][0], cnt[ulp_u][1]);

    }
};


void moon() {

    ll n,q;
    cin >> n>>q;
    vll a(n);
    DSU dsu(n);
    for (ll i = 0; i < q; i++) {
        ll u,v;
        cin >> u >> v;

        dsu.unionBySize(u,v);
        if (!dsu.check) {
            cout << "-1\n";
        }else {
            cout << dsu.curr << "\n";
        }
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






