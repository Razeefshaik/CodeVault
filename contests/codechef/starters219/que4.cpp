//
// Created by RAZEEF on 31-12-2025.
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

    if (n<=2) {
        cout << -1 << '\n';
        return;
    }

    vvi grid(n, vi(n,0));

    for (int i=0;i<3;i++) {
        grid[0][i]=1;
    }
    for (int i=0;i<3;i++) {
        grid[1][i]=1;
    }
    grid[2][2]=1;

    for (int i=2;i<n-1;i++) {
        grid[i][i+1]=1;
        grid[i+1][i+1]=1;
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {

            cout<<grid[i][j]<<" ";
        }
        cout<<'\n';
    }


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
