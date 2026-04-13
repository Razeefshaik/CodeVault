//
// Created by RAZEEF on 05-04-2026.
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
    vector<ll> parent, size;



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

long long safe_lcm(long long a, long long b, long long limit) {
    long long g = gcd(a, b);

    a /= g;

    if (a > limit / b)
        return 0;   // indicates overflow or > limit

    return a * b;
}




// Fast Modular Exponentiation
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll  solve_massive_lcm( vector<ll> &a) {
    int n= a.size();



    unordered_map<ll, ll> max_prime_power;

    // O(sqrt(V)) Factorization per number
    for (ll x : a) {
        if (x <= 1) continue;

        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                ll count = 0;
                while (x % i == 0) {
                    count++;
                    x /= i;
                }
                max_prime_power[i] = max(max_prime_power[i], count);
            }
        }
        // If x is still > 1, it is a prime number itself
        if (x > 1) {
            max_prime_power[x] = max(max_prime_power[x], 1LL);
        }
    }

    // Calculate Final Modulo Answer
    ll lcm_modulo = 1;
    for (auto it : max_prime_power) {
        ll p = it.first;
        ll exp = it.second;
        lcm_modulo = (lcm_modulo * power(p, exp)) % MOD;
    }

    return lcm_modulo ;
}


void moon() {

    ll n;
    cin >> n;
    vll a(n);

    DSU dsu(n);

    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        dsu.unionBySize(i+1, a[i]);
    }

    vll res;
    for (int i=1; i<=n; i++) {
        if (dsu.findUPar(i)==i) res.pb(dsu.size[i]);
    }

    ll ans=solve_massive_lcm(res);

    cout<<ans<<'\n';



}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






