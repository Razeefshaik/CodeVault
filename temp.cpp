//
// Created by RAZEEF on 19-01-2026.
//
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()


int longestBalanced(string s) {


    int n=s.size();
    int maxi=1;
    for(int i=0;i<n;i++){

        unordered_map<char, int> mpp;
        set<pair<int,char>> st;
        for(int j=i;j<n;j++){

            if(!st.empty() &&  st.find({mpp[s[j]], s[j]})!=st.end() ){
                st.erase({mpp[s[j]], s[j]});
            }
            mpp[s[j]]++;
            st.insert({mpp[s[j]], s[j]});

            if(st.begin()->first==st.rbegin()->first) maxi=max(maxi, j-i+1);
        }
    }

    return maxi;
}

void moon() {

    string s="abbac";
    cout<<longestBalanced(s);

}

int main() {
    fast_io;
    int t = 1;
   // cin >> t;
    while(t--) {
        moon();
    }
    return 0;
}