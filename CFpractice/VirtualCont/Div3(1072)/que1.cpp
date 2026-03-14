//
// Created by RAZEEF on 16-02-2026.
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

    if (n<4) {
        cout<<n<<'\n';
        return;
    }

    int t=n/2;
    int bal=0;
    if (n%2!=0) bal=1;

    int r=t/2;
    int l=t-r;
    //cout<<r<<' '<<l<<'\n';
    int maxi=max(l,r);
    int mini=min(l,r);
    maxi=maxi-abs(maxi-mini)/2;
    int diff= abs(2*maxi-2*mini);
    if (diff>0 && bal) diff--;
    else if (diff<=0 && bal) diff++;
    cout<<diff<<'\n';


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






