//
// Created by RAZEEF on 03-04-2026.
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
      string st=to_string(n);
    // ll dsz=log10(n)+1;
    // ll maxi=0;
    // for (ll mask=3;mask<(1ll<<dsz);mask++) {
    //
    //     string s;
    //     ll len=0;
    //     for (int b=0;b<dsz;b++) {
    //         if ((mask&(1<<b))) {
    //             s+=st[b];
    //             len++;
    //         }
    //     }
    //     if (stoll(s)%25==0) maxi=max(maxi, len);
    // }
    //
    // cout<<dsz-maxi<<"\n";

    ll dsz=sz(st);
    ll ans=dsz;
    for (int i=dsz-1;i>=1;i--) {

        if (st[i]=='5') {
            for (int j=i-1;j>=0;j--) {
                if (st[j]=='2' || st[j]=='7') {
                    ans=min(ans, dsz-j-2);
                    break;;
                }
            }
        }
        if (st[i]=='0') {
            for (int j=i-1;j>=0;j--) {
                if (st[j]=='0' || st[j]=='5') {
                    ans=min(ans, dsz-j-2);
                    break;;
                }
            }
        }
    }

    cout << ans<<'\n';


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






