

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
    ll n;
    cin >> n;

    ll totalSum= n*(ll)(n+1)/2ll;

    if(totalSum%2!=0) {
      cout<<"NO"<<endl;
      return;
    }

    cout<<"YES"<<endl;

    totalSum/=2;

    vector<ll> s1;
    vector<ll> s2;

    ll sum=0;

    for (int i=n;i>=1;i--) {

        if (sum+i<=totalSum) {
            s1.pb(i);
            sum+=i;
        }else {
            s2.pb(i);
        }
    }

    cout<<s1.size()<<endl;
    for (int i=0;i<s1.size();i++) {
        cout<<s1[i]<<" ";
    }
    cout<<endl;

    cout<<s2.size()<<endl;
    for (int i=0;i<s2.size();i++) {
        cout<<s2[i]<<" ";
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
