//
// Created by RAZEEF on 26-01-2026.
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


ll factorscnt(ll n) {

    ll cnt=0;
    for (ll i=1;i*i<=n;i++) {

        if (n%i==0) {
            cnt++;

            if (i!=n/i) cnt++;
        }
    }
    return cnt;
}


const int MAXN=1000006;
int spf[MAXN];
void sieve() {

    for (int i=0;i<MAXN;i++) {
        spf[i]=i;
    }

    for (int i=2;i*i<MAXN;i++) {

        if (spf[i]==i) {

            for (int j=i*i;j<MAXN;j+=i) {
                if (spf[j]==j) spf[j]=i;
            }
        }
    }
}


void moon() {

    ll n;
    cin >> n;

//    for(int i = 0; i < n; i++){
//         ll x;
//        cin >> x;
//
//        cout<<factorscnt(x)<<'\n';
//    }

    ll ans=1;
    while (n>1) {

        ll sp=spf[n];

        int p=0;
        while (n%sp==0) {
            p++;
            n/=sp;
        }
        ans*=(p+1);
    }

    cout<<ans<<'\n';


}

int main() {
    fast_io;
    sieve();

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






