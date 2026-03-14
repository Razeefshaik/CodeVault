//
// Created by RAZEEF on 07-03-2026.
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


class ExInc {
    public:
    vector<int> a;
    int n;
    ExInc(vector<int> &a) {
        this->a=a;
        n=a.size();
    }

    long long cnt(ll x) {

        ll res=0;
        for (ll i=1;i<(1<<n);i++) {

           ll lc=1;
            int bits=0;
            for (ll b=0;b<n;b++) {
                if (i&(1<<b)) {
                    lc= lcm(lc, a[b]);
                    bits++;
                }
            }

            if (bits%2==0) {
                res-=x/lc;
            }else res+=x/lc;
        }
        return x-res;
    }


};


void moon() {


     ll l,r;
     cin>>l>>r;

    vector<int> a={2,3,5,7};
    ExInc exi(a);

    ll res= exi.cnt(r)-exi.cnt(l-1);
    cout<<res<<'\n';


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







