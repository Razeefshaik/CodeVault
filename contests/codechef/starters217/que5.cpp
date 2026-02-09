

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
    ll n,m;
    cin >> n>>m;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<ll> sufB(n+1,0);
    for(int i=n-1;i>=0;i--){
        sufB[i]= sufB[i+1]+b[i];
    }

    ll sumB=sufB[0];
    ll k=-2e18;
    for(int i=0;i<n;i++){
       k= max(k, a[i]+sufB[i+1]);
    }

    ll split = k - sumB;


    ll count1 = 0;
    if (split >= 1) {
        count1 = min(m, split);
    }
    ll sum1 = count1 * k;


    ll start2 = max(1LL, split + 1);
    ll end2 = m;
    ll sum2 = 0;

    if (start2 <= end2) {
        ll count2 = end2 - start2 + 1;

        ll first_val = start2 + sumB;
        ll last_val = end2 + sumB;
        sum2 = count2 * (first_val + last_val) / 2;
    }

    cout << sum1 + sum2 << "\n";


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

