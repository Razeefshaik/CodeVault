//
// Created by RAZEEF on 31-01-2026.
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


using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int,int>>;
using vpl = vector<pair<long long,long long>>;
using ppll = pair<ll, pair<ll, ll>>;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);






void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n), m(n);





    for(int i = 0; i < n; i++) {
        cin >> a[i];

    }
    for(int i = 0; i < n; i++) {
        cin >> m[i];

    }

    int ax=a[0], mx=m[0];
    for (int i=1;i<n;i++) {

        ax= ax^a[i];
        mx= mx^m[i];
    }

    if ((ax==1 && mx==1) || (ax==0 && mx==0)) {
        cout<<"Tie"<<'\n';
        return;
    }

    for (int i=n-1;i>=0;i--) {

        if ((i+1)%2==0) {

                if (a[i]!=m[i]) {
                    cout<<"Mai"<<'\n';
                    return;
                }


            }else {



                    if (a[i]!=m[i]) {
                        cout<<"Ajisai"<<'\n';
                        return;
                    }



            }
        }

    if (ax==1) {
       cout<<"Ajisai"<<'\n';
   }else if (mx==1) {
       cout<<"Mai"<<'\n';
   }else {
       cout<<"Tie"<<'\n';
   }




}

int main() {
    fast_io;

    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






