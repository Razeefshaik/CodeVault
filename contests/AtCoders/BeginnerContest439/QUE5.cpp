//
// Created by RAZEEF on 03-01-2026.
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


ll solve(vector<pll> &arr) {


    ll n=arr.size();

    for(int i = 0; i < n; i++){

        ll st,end;
       st=arr[i].first;
        end=arr[i].second;
        arr[i] = make_pair(st,end);
    }



    sort(all(arr),[](const pair<ll, ll> a, const pair<ll, ll> b) {
                 if (a.se==b.se) return a.fi>b.fi;
                  return a.se<b.se;
    });

    ll ans = 1;
    ll lastEnd=arr[0].se;
    for(ll i = 1; i < n; i++) {
        if(arr[i].fi>lastEnd) {
            ans++;
            lastEnd = arr[i].se;
        }
    }

    return ans;

}

void moon() {

    ll n;
    cin >> n;
    vector<pll> a(n);
    for(int i = 0; i < n; i++){


        ll x,y;
        cin >> x >> y;

        if (y>x) swap(x,y);

        a[i] = make_pair(x,y);

    }


    ll ans=solve(a);

    cout<<ans<<"\n";

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
