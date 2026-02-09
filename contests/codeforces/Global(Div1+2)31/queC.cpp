//
// Created by RAZEEF on 19-12-2025.
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


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);




void solve() {
    // Write your solution here
    ll n,k;
    cin >> n>>k;

    if(k%2==0) {

        ll msb = 0;
        for (int i = 62; i >= 0; i--) {
            if ((n >> i) & 1) {
                msb = (1LL << i);
                break;
            }
        }


        if (msb == n) {
            cout << 0 << " " << n << " ";
        } else {

            ll remainder = n - msb;
            ll x = 0;


            for (int i = 62; i >= 0; i--) {
                ll bit = (1LL << i);


                if (!((n >> i) & 1)) {
                    if ((x + bit) <= remainder) {
                        x += bit;
                    }
                }
            }

            cout << (msb + x) << " " << (remainder + x) << " ";
        }


        for (int i = 0; i < k - 2; i++) {
            cout << n << " ";
        }
        cout << '\n';
    }else {
        for (int i=0;i<k;i++) {
            cout<<n<<" ";
        }
        cout<<'\n';
    }


}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}
