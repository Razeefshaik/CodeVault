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




void solve() {
    // Write your solution here
    int n,m,k;
    cin >> n>>m>>k;
    vector<int> p(n);
    priority_queue<int, vector<int> , greater<int>> pq;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(all(p));
    for(int i = 0; i < m; i++) {
        int x;
        cin>>x;
        pq.push(x);
    }

    int l=0;
    int ans=0;

    while (!pq.empty() && l<n) {

        int a=pq.top();
        int person=p[l];
        if (a>=(person-k) && a<=(person+k)) {
            ans++;
            l++;
        }
        if (a>(person+k)) {
             l++;
            continue;
        }
        pq.pop();

    }


    cout<<ans<<'\n';



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
