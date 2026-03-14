//
// Created by RAZEEF on 26-02-2026.
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


    vvll a1;

    for (int i=0;i<n;i++) {
        ll l;
        cin >> l;

       // multiset<ll> st;
        vll t;
        for (int j=0;j<l;j++) {

            ll x;
            cin >> x;

                t.pb(x);

        }

        a1.pb(t);
    }


    vvll a;

    for (int i=0;i<n;i++) {

        ll l=sz(a1[i]);

        multiset<ll> st;
        vll t;
        for (int j=l-1;j>=0;j--) {

            ll x;
            x=a1[i][j];
            if (st.find(x)==st.end()) {
                st.insert(x);
                t.pb(x);
            }
        }

        a.pb(t);
    }


    sort(all(a));

    set<ll> chh;
    for (int i=0;i<n;i++) {
        chh.insert(i);
    }
    ll t=1e10;



    multiset<ll> mst;
    vll ans;
    for (int i = 0; i < n; i++) {



        vll res;
        vll fdx(1);
        fdx[0]=-1;
        for (auto it: chh) {


            ll l;
            l=sz(a[it]);
            vll tempii;
            set<ll> tst;
            for (int j=0;j<l;j++) {
                ll x;
                x=a[it][j];



                if (mst.find(x)==mst.end()) {
                    //mst.insert(x);
                    tempii.pb(x);
                }
            }


            if (fdx[0]==-1 || tempii<res) {
                res=tempii;
                fdx[0]=it;
            }



        }


        chh.erase(fdx[0]);

        for (ll tt : res) {
            ans.pb(tt);
            mst.insert(tt);
        }



    }

    map<ll,ll> mpp;
    vector<pair<ll,ll>> v;
    for (auto x : mpp) {
        v.emplace_back(x.se, x.fi);
    }

   // sort(v.begin(), v.end());
    for (auto it:ans) {
        cout << it << " ";
    }
    cout <<'\n';




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






