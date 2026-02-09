//
// Created by RAZEEF on 24-12-2025.
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
using vll = vector<long long>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;



const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {

    ll n;
    cin >> n;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> rooms(n);
    //queue<int> q;
    vector<vector<ll>> custms;

    for(int i = 0; i < n; i++) {
      ll start,end;
      cin >> start >> end;
      custms.pb({start,end,i});
    }
    sort(all(custms));

    ll maxRooms=-LINF;
    ll altRooms=1;
    for(int i = 0; i < n; i++) {
        ll start= custms[i][0];
        ll end= custms[i][1];
        ll id= custms[i][2];

        if (pq.empty()) {
            pq.push({end,1});
            rooms[id]=1;
        }else {

            ll lastEnd=pq.top().fi;

            if (lastEnd<start) {
                auto[t, freeRoom]=pq.top();
                pq.pop();
                pq.push({end,freeRoom});
                rooms[id]=freeRoom;
            }else {

                pq.push({end,altRooms+1});
                rooms[id]=altRooms+1;
                altRooms+=1;
            }
        }

        maxRooms=max(maxRooms,rooms[id]);

    }

    cout << maxRooms << '\n';
    for (int i=0; i < n; i++) {
        cout << rooms[i] <<" ";
    }
    cout << '\n';


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}
