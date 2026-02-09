//
// Created by RAZEEF on 27-01-2026.
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

bool check(string s) {

    int n = sz(s);

    int cnt=0;
    bool f=false;
    for (int i=0;i<n;i++) {

        if (s[i]=='0') {
            cnt++;
            if (f) {
                cnt++;
                f=false;
            }
        }
        else {
            f=false;
            if (cnt>1 || cnt==0) {
                cnt=0;
            }else {

                if (i+1<n && s[i+1]=='0') {
                    cnt=0;
                    i++;
                    f=true;
                }else {
                    return false;
                }
            }
        }
    }

    if (cnt==0 || cnt>1) return true;
    return false;
}


void moon() {

    ll n;
    cin >> n;
    string ms;
    cin >> ms;

    bool ans=false;
    ans= ans || check(ms);
    if (ms[0]=='0') {

        string s1=ms.substr(1);
        ans= ans || check(s1);

    }
    if (ms[n-1]=='0') {
        string s1=ms.substr(0, n-1);
        ans= ans || check(s1);

    }

    if (ms[0]=='0' && ms[n-1]=='0') {

        string s1=ms.substr(0);
        s1[0]='1';
        s1[n-1]='1';
        ans= ans || check(s1);


    }



    if (ans) {
        cout<<"YES"<<'\n';
    }else cout<<"NO"<<'\n';


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






