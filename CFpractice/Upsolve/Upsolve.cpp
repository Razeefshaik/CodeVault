//
// Created by RAZEEF on 05-03-2026.
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

    ll n,q;
    cin >> n>>q;
    vvll basek(n+1);
    for (ll i = 0; i < n; i++) {
        ll x,y;
        cin >> x >> y;
        y=min(y, n);
        basek[y].pb(x);
    }

    priority_queue<ll , vector<ll>, greater<ll>> pq;
    ll mx=0;
    ll currsum=0;
    vll shop(n+2,0);
    for (int k=n+1;k>=1;k--) {

        for (auto it: basek[k-1]) {
            pq.push(it);
            currsum+=it;
        }

        while (sz(pq)>k) {
            ll tmp=pq.top();
            pq.pop();
            currsum-=tmp;
        }

        if (sz(pq)==k && k<=n) mx=max(mx, currsum);

        if (sz(pq)==k-1) {
            shop[k-1]=currsum;
        }else if (sz(pq)==k){
            shop[k-1]=currsum-pq.top();
        }
    }

    vll preShop(n+2, 0);
    for (int k=1;k<=n+1;k++) {
        preShop[k]=max(preShop[k-1], shop[k]);
    }

    for (int i=0;i<q;i++) {
        ll x,y;
        cin >> x >> y;
        y=min(n, y);
        cout<<max(mx, preShop[y]+x )<<" ";
    }
    cout<<'\n';

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






