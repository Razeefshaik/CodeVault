//
// Created by RAZEEF on 21-02-2026.
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



public:
    map<ll, ll> parent, size;

    DSU(vll a) {


        for (int i = 0; i < sz(a); i++) {
            parent[a[i]] = a[i];
            size[a[i]] = 1;
        }
    }


    ll findUPar(ll node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }




    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
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



void moon() {

    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

    DSU dsu(a);

    set<ll> st;
    for (int i=0;i<n;i++) {
        ll num=a[i];
        ll p=num-1;
        if (st.find(p)!=st.end()) {

            if (dsu.size[dsu.findUPar(num)]<(dsu.size[dsu.findUPar(p)]+1)) {
                dsu.unionBySize(num,p);
            }
        }
        st.insert(num);
    }

    map<ll,ll> t=dsu.size;
    ll maxi=0;
   // map<int,int> mpp;
    for (auto it: t) {
        maxi=max(maxi, it.se);
    }


    // map<ll,ll> mp;
    // for (auto it: a) {
    //     mp[it]=mp[it-1]+1;
    // }
    //
    // ll ans=0;
    // for (auto it: mp) {
    //     ans=max(ans, it.se);
    // }



    cout<<maxi<<'\n';





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






