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




void solve() {
    // Write your solution here
    int n,m;
    cin >>n>>m;

    vector<string> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {

            vector<bool> map(4,false);

            map[v[i][j]-'A']=true;
            if (i>0) map[v[i-1][j]-'A']=true;
            if (j>0) map[v[i][j-1]-'A']=true;

            for (int k=0;k<4;k++) {
                if (!map[k]) {
                    v[i][j]=(char)('A'+k);
                    break;
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        cout<<v[i]<<'\n';
    }



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

