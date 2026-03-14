//
// Created by RAZEEF on 11-03-2026.
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
    vll a(n);
    int p=0;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        if (a[i]!=0) p++;
    }

    if (p==0) {
        cout<<-1<<'\n';
        return;
    }

    for (int i=0; i<n-3; i++) {
        int x=a[i];
        int y=a[i+1];
        int z=a[i+2];

        if (x!=0 || y!=0 || z!=0) {
            if (x+y!=z) {
                cout<<i+1<<" "<<i+2<<" "<<i+3<<'\n';
            }else if (x+z!=y) {
                cout<<i+1<<" "<<i+3<<" "<<i+2<<'\n';
            }else if (y+z!=x) {
                cout<<i+2<<" "<<i+3<<" "<<i+1<<'\n';
            }

            break;
        }
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






