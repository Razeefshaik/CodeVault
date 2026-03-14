//
// Created by RAZEEF on 10-03-2026.
//
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




void moon() {

    string s;
    cin>>s;
    ll m;
    cin >> m;


    for (int q=0;q<m;q++) {
        ll l,r,k;
        cin>>l>>r>>k;

        l--;
        r--;
        ll len= (r-l)+1;
        k= k%len;

        rotate(s.begin()+l, s.begin()+r-k+1, s.begin()+r+1);
    }

    cout<<s<<'\n';

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






