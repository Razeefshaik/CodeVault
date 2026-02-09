//
// Created by RAZEEF on 25-01-2026.
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




void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    set<ll> st;
    for(int i = 0; i < n; i++) {
         st.insert(a[i]);
    }

    vll lst;
    bool o=false;
    queue<ll> q;
    for(auto it: st) {
         if (it!=1) {
             lst.pb(it);
             q.push(it);
         }
        if (it==1) o=true;

    }

    //sort(all(lst));

    vll dist(n+1, -1);
    if (o) dist[1]=1;

    for (auto it: lst) {
        if (n>=it) {
            dist[it]=1;
        }
    }

    while (!q.empty()) {
        ll node=q.front();
        q.pop();

        for (auto it: lst) {

            ll pr= node*it;

            if (pr>n) break;

            if (dist[pr]==-1) {
                dist[pr]=dist[node]+1;
                q.push(pr);
            }
        }
    }

    for (int i=1;i<=n;i++) {
        cout << dist[i]<<" ";
    }
    cout<<"\n";











}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






