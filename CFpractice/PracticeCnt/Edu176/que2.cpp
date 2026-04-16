//
// Created by RAZEEF on 13-04-2026.
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
    vector<pll> a(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = (pll){x,i};
    }
    sort(all(a));
    reverse(all(a));
    vector<bool> mask(n,false);
    ll ans=0;
    for (ll i = 0; i <=k; i++) {
        ans+=a[i].fi;
        mask[a[i].se]=true;
    }
    bool f=false;
    for (ll i = 0; i <=k; i++) {
        if (mask[i]==false) {
            f=true;
            break;
        }
    }

    if (f || n==(k+1)) {
        cout << ans << '\n';
        return;
    }


    ans-=a[k].fi;
    ans+=a[n-1].fi;
    ll maxi=ans;
    vll arr;
    for (ll i = k+1; i <n; i++) {
        arr.pb(a[i].fi);
    }
    sort(all(arr));
    reverse(all(arr));
    ans+=arr[0];
    cout<<ans<<'\n';


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






