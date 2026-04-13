//
// Created by RAZEEF on 08-04-2026.
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

//
//
// ll solve(multiset<ll> &st, ll a, ll b, ll c) {
//
//     ll cs=1;
//     ll m= LINF;
//     st.insert(a);
//     if ((*st.rbegin()-*st.begin())<m) {
//         cs=1;
//         m=(*st.rbegin()-*st.begin());
//     }
//     st.erase(st.find(a));
//
//     st.insert(b);
//     if ((*st.rbegin()-*st.begin())<m) {
//         m=(*st.rbegin()-*st.begin());
//         cs=2;
//     }
//     st.erase(st.find(b));
//
//     st.insert(c);
//     if ((*st.rbegin()-*st.begin())<m) cs=3;
//     st.erase(st.find(c));
//
//     return cs;
// }
//
// void moon() {
//
//     ll n;
//     cin >> n;
//     vll a(n), b(n), c(n);
//     for (ll i = 0; i < n; i++) {
//         ll x,y,z;
//         cin >> x >> y >> z;
//         a[i] = x; b[i] = y; c[i] = z;
//     }
//
//     ll ma=a[0], mb=b[0], mc=c[0];
//     multiset<ll> sta, stb, stc;
//     sta.insert(a[0]);
//     stb.insert(b[0]);
//     stc.insert(c[0]);
//     for (ll i = 1; i < n; i++) {
//
//         //1
//         ll cs= solve(sta, a[i], b[i], c[i]);
//         if (cs==1) sta.insert(a[i]);
//         else if (cs==2) sta.insert(b[i]);
//         else if (cs==3) sta.insert(c[i]);
//
//         ll csb= solve(stb, a[i], b[i], c[i]);
//         if (csb==1) stb.insert(a[i]);
//         else if (csb==2) stb.insert(b[i]);
//         else if (csb==3) stb.insert(c[i]);
//
//         ll csc= solve(stc, a[i], b[i], c[i]);
//         if (csc==1) stc.insert(a[i]);
//         else if (csc==2) stc.insert(b[i]);
//         else if (csc==3) stc.insert(c[i]);
//
//
//
//     }
//
//
//     ll m1= *sta.rbegin()-*stb.begin();
//     ll m2= *stb.rbegin()-*stb.begin();
//     ll m3= *stc.rbegin()-*stc.begin();
//
//     cout<<min({m1, m2,m3})<<'\n';
//
//
// }



void moon() {

    ll n;
    cin >> n;
    vector<pll> a;
    for (ll i = 0; i < n; i++) {
        ll x,y,z;
        cin >> x >> y >> z;

        a.pb({x,i});
        a.pb({y,i});
        a.pb({z,i});
    }


    sort(all(a));

    ll g=0;
    map<ll,ll> mpp;
    ll mini=LINF;
    ll l=0;
    for (int r=0;r<sz(a);r++) {

        ll currg= a[r].se;
        if (mpp[currg]==0) {
            g++;
        }
        mpp[currg]++;

        while (g==n) {
            mini=min(mini, a[r].fi-a[l].fi);

            ll cg=a[l].se;
            mpp[cg]--;
            if (mpp[cg]==0) g--;
            l++;
        }
    }

    cout << mini << '\n';

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






