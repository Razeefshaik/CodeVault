//
// Created by RAZEEF on 19-01-2026.
//
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()


int longestArithmetic(vector<int>& nums) {




    int n=nums.size();

    vector<int> diff(n);
    for(int i=0;i<n-1;i++){
        diff[i]=(nums[i+1]-nums[i]);

    }


    vector<int> pre(n,1), suff(n,1);
    for(int i=1;i<n-1;i++){
        if(diff[i]==diff[i-1]) pre[i]= pre[i-1]+1;

    }

    for(int i=n-3;i>=0;i--){
        if(diff[i]==diff[i+1])  suff[i]=suff[i+1]+ 1;

    }




    int ans=pre[0];
    for(int i=2;i<n;i++){

        ans= max(ans, pre[i-2]+1);

        int d=diff[i-2];
        int num=nums[i-1]+d;
        if(i+1<n){
            int d2= nums[i+1]-num;
            if(d2==diff[i+2] && i+2<(n-1)){
                ans= max(ans, pre[i-2]+suff[i+1]+2 );
            }
        }

    }
    return ans+1;
}
void moon() {

    vector<int> a={9,7,5,10,1};
    cout<<longestArithmetic(a);

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