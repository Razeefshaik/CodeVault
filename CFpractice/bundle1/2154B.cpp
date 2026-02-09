//
// Created by RAZEEF on 26-01-2026.
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
    vector<ll> a(n);

    cin >> a[0]>>a[1];
    ll maxi=max(a[0], a[1]);
    ll ops=0;
    if (a[0]>=a[1]) {
        ops+=(a[0]-maxi+1);
        a[0]=maxi-1;
    }

    for(int i = 1; i < n; i++){

        if (i!=1) cin >> a[i];

        if ((i+1)%2 == 0) {

            maxi = max(maxi, a[i]);
            a[i]=maxi;

        }else {

            if (a[i]>=maxi) {
                ops+=(a[i]-maxi+1);
                //a[i]=maxi-1;
            }
        }
        maxi = max(maxi, a[i]);

    }

    cout << ops << '\n';


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






