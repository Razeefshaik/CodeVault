//
// Created by RAZEEF on 07-02-2026.
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

    ll sum=0;
    ll maxi=0;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        sum+=a[i];
        maxi=max(maxi, a[i]);
    }

   sort(all(a));
    int idx=n;
    while (idx>0 && a[idx-1]==maxi) {
        idx--;
    }

    vll res;

    if (idx==0) {
        res.pb(maxi);
    }else {
        if (idx%2==0) {

            bool f=false;
            int l=0;
            int r=idx-1;
            while (l<r) {
                if (a[l]+a[r]!=maxi) {
                    f=true;
                    break;
                }
                l++;
                r--;
            }

            if (!f) {
                res.pb(maxi);
            }
        }
    }

    if (n%2==0) {
        if ((2*sum)%n==0) {
            ll len=(2*sum)/n;

            if (len>maxi){
                bool f=false;
                int l=0;
                int r=n-1;
                while (l<r) {
                    if (a[l]+a[r]!=len) {
                        f=true;
                        break;
                    }
                    l++;
                    r--;
                }

                if (!f) {
                    res.pb(len);
                }
            }
        }
    }

    sort(all(res));
    for (auto it: res) {
        cout<<it<<" ";
    }
    cout<<'\n';


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






