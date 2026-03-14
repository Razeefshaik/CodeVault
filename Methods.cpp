//
// Created by RAZEEF on 23-01-2026.
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

/***

##Funs
isPrime
smallprimefactors
finddivisors
sieve
nCr
factorscount
safe_lcm
rotateString  - right rotate range l to r with n times

##Classes
DSU
ExInc
    ***/


//Prime number till "n"
vector<ll>  sieve(int n) {

    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    vll ans;
    for(int i = 2; i <= n; i++) {
        if(prime[i])
            ans.pb(i);
    }

    return ans;
}


bool isPrime(long long n) {

    if(n <= 1) return false;
    if(n <= 3) return true;

    if(n % 2 == 0 || n % 3 == 0)
        return false;

    for(long long i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

//////////////////////////////////////////////////////

vector<int> smallprimefactors() {

    const int MAXN=1000006;
    vector<int> spf(MAXN);

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

    return spf;
}


void finddivisors() {

    ll n;
    cin >> n;



    vector<int> spf;
    spf=smallprimefactors();

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
/////////////////////////////////////////////////////
long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;   // Optimization

    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}


ll factorscount(ll n) {

    ll cnt=0;
    for (ll i=1;i*i<=n;i++) {

        if (n%i==0) {
            cnt++;

            if (i!=n/i) cnt++;
        }
    }
    return cnt;
}

long long safe_lcm(long long a, long long b, long long limit) {
    long long g = gcd(a, b);

    a /= g;

    if (a > limit / b)
        return 0;   // indicates overflow or > limit

    return a * b;
}


string rotateString(string s,long long l, long long r, long long times) {


     ll len= (r-l)+1;
        times= times%len;

        rotate(s.begin()+l, s.begin()+r-times+1, s.begin()+r+1);

    return s;
}



class DSU {

    vector<int> parent, size;

public:


    DSU(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }




    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};





//Inclusion and exclusion -- no of integers divisble by k given numbers less than x
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


