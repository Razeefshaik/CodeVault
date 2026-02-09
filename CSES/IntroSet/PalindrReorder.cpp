//
// Created by RAZEEF on 15-12-2025.
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


string buildString(char ch, int c) {

    string s;
    for (int i=0;i<c;i++) {
        s.push_back(ch);
    }

    return s;
}

void solve() {
    // Write your solution here
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    int odd=0;

    for(auto c : s) {
      mp[c]++;

    }

    string mid;
    string ss;
    for(auto it: mp) {
       if(it.se%2!=0) {
         odd++;
         if(odd>1) {
             cout<<"NO SOLUTION"<<endl;
             return;
         }
         mid=buildString(it.fi,it.se);
       }else {
           ss= ss+buildString(it.fi, it.se/2);
       }
    }

    string rs=ss;
    reverse(all(rs));
    ss= ss+mid+rs;
    cout<<ss<<endl;


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

