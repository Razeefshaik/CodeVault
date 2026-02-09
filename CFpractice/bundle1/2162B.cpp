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


bool palind(string s) {
    int n = sz(s);

    int l=0, r=n-1;
    while (l<r) {

        if (s[l]!=s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool check(string s) {

    int n = sz(s);
    for (int i=1; i<n; i++) {

        if (s[i-1]>s[i]) {
            return false;
        }
    }
    return true;
}


void moon() {

    ll n;
    cin >> n;

    string s;
    cin >> s;

    for(int i=0;i<(1<<n);i++) {

        string chec;
        vi idxs;
        string pal;
        for (int b=0;b<n;b++) {
            if (i&(1<<b)) {
                 pal+=s[b];
            }else {
                chec+=s[b];
                idxs.pb(b);
            }
        }

        if (palind(pal) && check(chec)) {

            cout<<sz(chec)<<'\n';
            for (auto it:idxs) {
                cout<<it+1<<" ";
            }
            cout<<'\n';
            return;
        }
    }

    cout<<"-1\n";


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






