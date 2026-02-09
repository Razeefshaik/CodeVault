//
// Created by RAZEEF on 19-01-2026.
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
    string s;
    cin >> s;
     int cnt=0;
    int l=0,r=n-1;
    int eq1=0,eq0=0, neq1=0, neq0=0;
    while(l<r) {

        if (s[l]==s[r]){
            if (s[l]=='0') eq0+=2;
            if (s[r]=='1') eq1+=2;
            cnt++;
        }

            if (s[l]=='0' || s[r]=='0') neq0++;
            if (s[r]=='1' || s[l]=='1') neq1++;


        l++;
        r--;
    }

    if (cnt==k) cout<<"YES"<<endl;
    else if (abs(cnt-k)%2==0){
        ll diff= abs(cnt-k);
        if (cnt>k) {
            if (diff<=eq1 && diff<=eq0) {
                cout<<"YES"<<endl;
            }else {
                cout<<"NO"<<endl;
            }
        }else if (k>cnt) {
            if (diff<=neq0 && diff<=neq1) {
                cout<<"YES"<<endl;
            }else {
                cout<<"NO"<<endl;
            }
        }else {
            cout<<"NO"<<endl;
        }
    }else {
        cout<<"NO"<<endl;
    }



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



