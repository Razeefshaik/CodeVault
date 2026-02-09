//
// Created by RAZEEF on 05-02-2026.
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

    ll n,k;
    cin >> n>>k;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++) cin>>a[i];
    for (ll i = 0; i < n; i++) cin>>b[i];

    ll s=-1;
    int cnt=0;
    for (int i=0;i<n;i++) {

        if (s==-1 && b[i]!=-1) {
            s=a[i]+b[i];
        }

        if (s!=-1 && b[i]!=-1 && s!=(a[i]+b[i])) {
            cout<<0<<'\n';
            return;
        }

        if (b[i]!=-1) cnt++;
    }

    ll mini=LINF, maxi=-LINF;
    ll negMini=LINF;
    for (int i=0;i<n;i++) {
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);

        if (b[i]==-1) negMini=min(negMini,a[i]);
    }

    if (cnt!=0) {

        if (s<maxi || (mini+k)<maxi  || negMini+k<s) {
            cout<<0<<'\n';
        }else cout<<1<<'\n';
        return;
    }



    ll ans=mini+k-maxi+1;
    if (ans<=0) cout<<0<<'\n';
    else cout<<ans<<'\n';






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






