//
// Created by RAZEEF on 16-12-2025.
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


ll factorial(ll n) {

    if (n<2) return 1;

    return n*factorial(n-1);
}

void permute(string s,string &curr, vector<bool> &used) {

    if (curr.size()==s.size()) {
        cout << curr << '\n';
    }

    for (int i=0;i<s.size();i++) {

        if (i>0 && s[i]==s[i-1] && !used[i-1]) continue;
        if (!used[i]) {

            used[i]=true;
            curr.push_back(s[i]);
            permute(s,curr,used);
            curr.pop_back();
            used[i]=false;
        }
    }
}

void solve() {
    // Write your solution here
    string s;
    cin>>s;

    sort(s.begin(), s.end());
    int n = sz(s);
    ll count=1;
    unordered_map<char, ll> mpp;
    count=factorial(n);
    for(auto ch:s) {
        mpp[ch]++;
    }
    for (auto it:mpp) {
        count=count/factorial(it.second);
    }

    cout<<count<<'\n';

    vector<bool> used(n,false);
    string curr;
    permute(s,curr,used);


}

int main() {
    fast_io;



    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        solve();
    }

    return 0;
}

