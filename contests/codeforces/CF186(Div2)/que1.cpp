//
// Created by RAZEEF on 29-12-2025.
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
    string s;
    cin >>n>> s;

    // ll n=s.size();
    ll count26=0,count25=0;

    string s26="2026", s25="2025";
    for(ll i=0;i<=n-4;i++) {

        ll t=0;
        ll t25=0;
        for (int j=0;j<4;j++) {
            if (s[i+j]==s26[j]) t++;
            if (s[i+j]==s25[j]) {
                t25++;
            }

        }
        count25=max(count25,t25);

        if (t==4) {
            cout<<0<<endl;
            return;
        }
    }

    if (count25!=4) {
        cout<<0<<endl;
        return;
    }

    count26=4,count25=0;
    for (ll i=0;i<=n-4;i++) {

        ll t26=4, t25=0;
        for (ll j=0;j<4;j++) {
            if (s[i+j]==s26[j]) t26--;
        }
        count26=min(count26, t26);


        for (ll j=0;j<4;j++) {
            if (s[i+j]==s25[j]) t25++;
        }
        if (t25==4) {
            count25++;
        }

    }

    cout<<min(count26,count25)<<endl;


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
