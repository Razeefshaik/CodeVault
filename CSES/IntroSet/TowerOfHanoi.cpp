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


void towerOH(int n,int from, int to , int aux) {

    if (n==0) return;

    towerOH(n-1,from,aux,to);
    cout<<from<<" "<<to<<'\n';
    towerOH(n-1,aux,to,from);
}

void solve() {
    // Write your solution here
    int n;
    cin >> n;

    cout<<(1<<n)-1<<'\n';

    towerOH(n,1,3,2);


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
