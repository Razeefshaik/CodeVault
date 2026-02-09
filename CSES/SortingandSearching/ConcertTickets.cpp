//
// Created by RAZEEF on 18-12-2025.
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
    ll n,m;
    cin >> n>>m;
    multiset<ll> st;
    vector<ll> p(m);
    for(int i = 0; i < n; i++) {
        ll x;
        cin >>x ;
        st.insert(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }

    for (int i=0;i<m;i++) {

        ll cust=p[i];

        if (*st.begin()>cust) {
            cout<<-1<<'\n';
            continue;
        }
        ll cl=-2e18;

        auto it=st.upper_bound(cust);
        if (it!=st.begin()) {
            --it;
            cl= *it;
            cout<<cl<<'\n';
            st.erase(it);
        }else {
            cout<<-1<<'\n';
        }
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

