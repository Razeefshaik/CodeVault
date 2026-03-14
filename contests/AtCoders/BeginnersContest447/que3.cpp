//
// Created by RAZEEF on 28-02-2026.
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

    string s;
    cin>>s;
    string t;
    cin>>t;

    string ts, tt;
    ll tot=0;
    ll cs=0, ct=0;
    vll csa, cta;
    for (auto it: s) {
        if (it!='A') {
            ts.pb(it);
            csa.pb(cs);
            cs=0;

        }else {
            cs++;
        }
    }
    csa.pb(cs);
    for (auto it: t) {
        if (it!='A') {
            tt.pb(it);
            cta.pb(ct);
            ct=0;
        }else {
            ct++;
        }
    }
    cta.pb(ct);


    if (ts!=tt) {
        cout<<-1<<'\n';
        return;
    }

    for (int i=0;i<csa.size();i++) {
        tot+= abs(csa[i]- cta[i]);
    }

    cout<<tot<<'\n';



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






