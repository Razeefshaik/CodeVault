//
// Created by RAZEEF on 30-01-2026.
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

    int type1=0, type2=0, type3=0;
    for(auto it: s) {
        if(it=='0') {
            type1++;
        }else if (it=='1') {
            type2++;
        }else {
            type3++;
        }

    }

    vector<char> ans(n, '+');

    for (int i=0;i<type1;i++) {
        ans[i]='-';
    }

    int end=n;
    for (int i=0;i<type2;i++) {
        ans[n-1-i]='-';
        end=n-1-i;
    }

    for (int i=type1;i<type3+type1;i++) {
        ans[i]='?';
        if (n==k) ans[i]='-';
    }
    for (int i=0;i<type3;i++) {
        ans[end-1-i]='?';
        if (n==k) ans[end-i-1]='-';
    }



    for (auto it: ans) {
        cout<<it;
    }
    cout<<"\n";


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






