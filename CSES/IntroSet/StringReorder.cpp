//
// Created by RAZEEF on 17-12-2025.
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


const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);


bool check(map<char, int> &mpp,int len) {

       for (auto it: mpp) {
           if (2*it.se>(len+1)) return false;
       }

    return true;
}


void solve() {
    // Write your solution here
    string s;
    cin >> s;

    map<char, int> mpp;
    for(int i = 0; i < sz(s); i++) {
        mpp[s[i]]++;
    }

    int l=1;
    int n=sz(s);
    vector<char> v;
    for (auto it: mpp) {
        v.pb(it.fi);
    }

    string ans;
    char lastUsed=-1;
    for (int i=0;i<n;i++) {

        bool flag=false;
        for (auto it: v) {

            if (mpp[it]>0 && lastUsed!=it) {

                mpp[it]--;

                if (check(mpp, n-i-1)) {
                    lastUsed=it;
                    ans.pb(it);
                    flag=true;
                    break;
                }

                mpp[it]++;
            }
        }
        if (!flag) {
            cout<<-1<<endl;
            return;
        }
    }

    cout<<ans<<endl;



}

int main() {
    fast_io;



    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

