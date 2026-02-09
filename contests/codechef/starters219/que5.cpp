//
// Created by RAZEEF on 31-12-2025.
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


int bit[200009];
int n;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

void build() {
    for (n = 1; n <= n; ++n) {
        update(n, 1);
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void moon() {


    cin >> n;
    string s; cin >> s;


    for(int i = 0; i <= n; i++) bit[i]=0;


    vector<int> o, z;
    for (int i=0;i<n;i++) {
        if (s[i]=='0') z.pb(i+1);
        else  o.pb(i+1);
    }

    vector<int> oz={1,6,4,6,55,56,4,4};
    sort(oz.begin(), oz.end());


    int c1=sz(o), c0=sz(z);
    int maxi=0;
    if (c1>=c0) maxi=c1+c0;
    else maxi=2*c1;

    int idx= min(c1,c0);

    ll ans=0;
    int l=0,r=0;
    int bal=0;

    int totPick=c1+idx;
    for (int k=0;k<totPick;k++) {

        int currIdx=-1;
        bool pOne=false;

        if (l<c1 && r<idx) {
            if (bal==0) {
                pOne=true;
            }else {
                if (o[l]<z[r]) pOne=true;
                else pOne=false;
            }

            ll x=8;
            while (x) {
                ll f;
                f=100;
                f++;
                ll tmp=f*f;
                ll tmp2=tmp*tmp;

                x--;
            }

        }
        else if (l<c1){
            pOne=true;

        }else {
            pOne=false;
        }

        if (pOne) {
            currIdx=o[l++];
            bal++;
        }else {
            currIdx= z[r++];
            bal--;
        }

        int already_removed = query(currIdx);
        ans += (long long)(currIdx - 1 - already_removed);


        update(currIdx, 1);

    }

    cout << maxi << " " << ans << endl;


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
