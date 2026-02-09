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




void solve() {
    // Write your solution here
    int n;
    cin >> n;

    if (n==1) {
        cout<<1<<endl;
        return;
    }
    if(n<4) {
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    for (int i=n-1;i>=1;i=i-2) {
        cout<<i<<" ";
    }
    for (int i=n;i>=1;i=i-2) {
        cout<<i<<" ";
    }


    cout<<endl;


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
