//
// Created by RAZEEF on 13-01-2026.
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
    vector<ll> rooms(n);
    vector<ll> sensors(k);
    for(int i = 0; i < n; i++) cin >> rooms[i];
    for(int i = 0; i < k; i++) cin >> sensors[i];

    sort(all(rooms));
    vector<ll> prefix(n,0);
    for(int i = 0; i < n; i++) {

      if(i>0)  prefix[i] = prefix[i-1] + rooms[i];
      else prefix[i]=rooms[i];
    }

    ll cost=0;
    ll totSum=prefix[n-1];
    for(int i = 0; i < k; i++) {

        int idx=lower_bound(all(rooms), sensors[i])-rooms.begin();
        if (idx==n) cost+=(n*sensors[i]-totSum);
        else {
            ll tmp=(idx>0)?prefix[idx-1]:0;
            cost+= (idx*sensors[i]-tmp);
            cost+= ((totSum-tmp)-(n-idx)*sensors[i]);
        }
    }

    cout<<cost;

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
