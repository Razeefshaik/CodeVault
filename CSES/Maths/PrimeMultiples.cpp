//
// Created by RAZEEF on 25-03-2026.
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
    vector<ll> a;
    int n;
    ExInc(vector<ll> a) {
        this->a=a;
        n=a.size();
    }

    long long cnt(ll x) {
        if (x <= 0) return 0;
        ll res=0;
        for (ll i=1;i<(1<<n);i++) {

            ll prd=1;
            bool f=false;
            int bits=0;
            for (ll b=0;b<n;b++) {
                if (i&(1<<b)) {

                    if (a[b]>(x/prd)) {
                        f=true;
                        break;
                    }
                    bits++;
                    prd*=a[b];
                }

            }

            if (f) continue;
            if (bits%2==0) {
                res-=x/prd;
            }else res+=x/prd;
        }
        return res;
    }


};

void moon() {

    ll n,k;
    cin >> n>>k;
    vll a(k);
    for (ll i = 0; i < k; i++) cin>>a[i];

    ExInc ex(a);

    cout<<ex.cnt(n)<<'\n';


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






