//
// Created by RAZEEF on 10-03-2026.
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


double ang(double x, double y) {

    double angle = atan2(y, x);
    // if(angle < 0)
    //
    //     angle = 2 * PI-angle;
     //angle = angle * 180 / PI;

    return angle;
}

void moon() {

    ll n;
    cin >> n;

    vector<pair<double , ll>> v;
    for (ll i = 0; i < n; i++) {
        double x,y;
        cin >> x >> y;

        v.pb({ang(x,y), i});
        //v.pb({ang(-x,-y), i});

       cout<<ang(x,y)<<" ";
    }
    cout<<'\n';


    vector<pair<double , ll>> v1;
    for (ll i = 0; i < n; i++) {
        v1.pb({abs(v[i].fi), v[i].se});
    }

    double ans = 1e18;
    ll p=v[0].se;
    ll p2=v[n-1].se;

   // double diff= abs(v[n-1].fi - v[0].fi);
    sort(all(v1));
    for (int i=1;i<n;i++) {
       if (v1[i].fi==v1[i-1].fi) {
           cout<<v1[i].se+1<<" "<<v1[i-1].se+1<<'\n';
           return;
       }
    }


    sort(all(v));
    // for (auto it: v) {
    //     cout<<it.fi<<" ";
    // }
    // cout<<'\n';



        for (int i=1; i<sz(v); i++) {


            double diff= abs(v[i].fi - v[i-1].fi);
            // cout<<diff<<" ";
            // if (diff=-360) {
            //     p=v[i].se;
            //     p2=v[i-1].se;
            //     break;
            // }
            if (diff<=ans) {
                ans=diff;
                p=v[i].se;
                p2=v[i-1].se;

            }
        }


    //cout<<'\n';

    cout<<p+1<<" "<<p2+1<<'\n';


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






