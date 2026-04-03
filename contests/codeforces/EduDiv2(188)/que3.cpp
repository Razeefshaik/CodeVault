//
// Created by RAZEEF on 16-03-2026.
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



ll lc(ll x, ll y) {
    if(x ==0||y==0) return 0;
    return(x/gcd((ll)x, (ll)y)) * y;
}
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

            ll lc=1;
            int bits=0;
            for (ll b=0;b<n;b++) {
                if (i&(1<<b)) {
                    lc= lcm(lc, a[b]);
                    bits++;
                }
            }

            if (lc > x) continue;
            if (bits%2==0) {
                res-=x/lc;
            }else res+=x/lc;
        }
        return x-res;
    }


};

ll divi(ll base, ll target) {
    return target / gcd(base, target);
}
void moon() {

    ll a, b, c, m;
    cin >> a >> b >> c >> m;



    ll A =ExInc({divi(a,b),divi(a, c)}).cnt(m/a);
    ll B =ExInc({divi(b, a),divi(b, c)}).cnt(m /b);
      ll C =ExInc({divi(c, a),divi(c, b)}).cnt(m/c);


    ll AB = (ll)lc(a, b);
      ll AC = (ll)lc(a, c);
    ll BC = (ll)lc(b, c);

    ll pAB =(AB>m)?0: ExInc({divi(AB, c)}).cnt(m / AB);
       ll pAC = (AC > m)?0 : ExInc({divi(AC, b)}).cnt(m / AC);
    ll pBC = (BC > m)?0: ExInc({divi(BC, a)}).cnt(m / BC);


    ll lcm_ABC = lc(AB, c);
    ll pABC =(lcm_ABC > m)?0:(ll)(m / lcm_ABC);


    ll Ali =6*A+3*pAB +3*pAC+2*pABC;
       ll  bb=6*B+ 3 * pAB +3 *pBC +2 *pABC;
    ll car = 6*C+3*pAC +3*pBC+2*pABC;

    cout <<Ali<<" "<<bb<< " "<<car << "\n";
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






