//
// Created by RAZEEF on 19-01-2026.
//
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()


    vector<string> maxNumOfSubstrings(string s) {

        vector<vector<int>> mask(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            mask[s[i]-'a'].push_back(i);
        }

        vector<pair<int, vector<int>>> arr;
        for(int i=0;i<26;i++){

            if(!mask[i].empty()) arr.push_back({mask[i][0],{mask[i].back(), i}});
        }

        sort(arr.begin(), arr.end());

        int l=-1;
        int r=-1;
        if(!arr.empty()) l=arr[0].first;
        r=l;
        vector<pair<int, vector<int>>> arr2;
        int oidx=-1;
        for(int i=0;i<arr.size();i++){
            int r2=arr[i].second[0];
            int l2=arr[i].first;
            int idx=arr[i].second[1];
            oidx=idx;
            if(l2>l && r2<r){
                arr2.push_back({r2,{l2, idx}});
            }
            else if(l2>=l && r2>r){
                r=r2;
            }else if (l2>r) {

            }
            else{
                arr2.push_back({r,{l, idx}});
                if(i+1<arr.size()) l=arr[i+1].first;
                r=l;
            }
        }
        if(oidx!=-1) arr2.push_back({r,{l, oidx}});



        sort(arr2.begin(), arr2.end());
        vector<int> mks;
        int last=-1;
        for(auto it: arr2){
            int l=it.second[0];
            int r=it.first;
            int idx=it.second[1];

            if(last<l){
                mks.push_back(idx);
                last=r;
            }
        }

        vector<string> ans;
        for(auto it: mks){

            string t="";
            int st=mask[it][0];
            int e=mask[it].back();
            for(int i=st;i<=e;i++){
                t+=s[i];
            }
            ans.push_back(t);

        }

        return ans;
    }


void moon() {

    string s="abbaccd";
    maxNumOfSubstrings(s);

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