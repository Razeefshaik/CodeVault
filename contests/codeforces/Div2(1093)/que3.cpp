//
// Created by RAZEEF on 13-04-2026.
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

    ll p,q;
    cin >> p>>q;

    ll s= p+2*q;
    ll x= 2*s+1;

    for (ll a=3;a*a<=x;a+=2) {

        if (x%a==0) {

            ll b=x/a;

            ll n= (a-1)/2;
            ll m=(b-1)/2;

            if (n>0 && m>0) {

                if (q<=n*(m+1) && q<=m*(n+1)) {
                    cout <<n<<" "<<m<<'\n';
                    return;
                }
            }
        }

    }

    cout<<-1<<'\n';

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






