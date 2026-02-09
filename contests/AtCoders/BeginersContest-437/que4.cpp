//
// Created by RAZEEF on 20-12-2025.
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
const ll MODL=998244353;




void solve() {

    ll n,m;
    cin >> n>>m;

    map<ll,ll> mpp;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> preB(m,0);

    for(int i = 0; i < m; i++){

      cin >> b[i];

      }

    //sort(all(a));
    sort(all(b));

    preB[0]=b[0];
    mpp[b[0]]=0;
    for (int i=1; i < m; i++) {
        preB[i] = (preB[i-1] + b[i])%MODL;
        mpp[b[i]]=i;
    }


    ll ans = 0;

    for (int i = 0; i < n; i++) {

        ll A= (m*a[i])%MODL;
        auto it= upper_bound(b.begin(), b.end(),a[i]);
        ll idx=it - b.begin();
        if (idx==0) {
            ans= (ans+  preB[m-1]-A+MODL)%MODL;
        }else {


            idx--;

             A=((idx+1)*a[i])%MODL;
            ll tmp= (A-preB[idx]+MODL)%MODL;
            ans= (ans+ tmp)%MODL;

            A=((m-idx-1)*a[i])%MODL;
            ll tmp2= (preB[m-1]-preB[idx]-A+MODL)%MODL;
            ans= (ans+tmp2)%MODL;

        }
    }

    cout << ans << '\n';







}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}


   