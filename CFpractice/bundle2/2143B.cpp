//
// Created by RAZEEF on 30-01-2026.
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

    ll n,k;
    cin >> n>>k;
    vector<ll> a(n);
    vll b(k);

    ll cost=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cost+=a[i];
    }
    for(int i = 0; i < k; i++) cin >> b[i];

    sort(all(a), greater<ll>());
    sort(all(b));


    int l=0, r=n-1;
    for (int i=0;i<k;i++) {

        int lb=b[i];
        int idx= l+lb-1;
        if (idx>=n) break;
        cost-=a[idx];
        l=idx+1;
    }

    cout<<cost<<'\n';


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






