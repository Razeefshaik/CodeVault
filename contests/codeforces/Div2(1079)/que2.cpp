//
// Created by RAZEEF on 11-02-2026.
//
//
// Created by RAZEEF on 11-02-2026.
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
    vll p(n),a(n);
    for (ll i = 0; i < n; i++) cin>>p[i];
    for (int i=0;i<n;i++) cin>>a[i];

    vvi chunks;

    for (int i=0;i<n;i++) {

        vector<int> ch;
        ch.pb(a[i]);
        ch.pb(i);
        int num=a[i];
        while(i+1<n && a[i]==a[i+1]) {

            ch.pb(i+1);
            i++;
        }


        chunks.pb(ch);



    }




   int idx=0;
    for (int i=0;i<n;i++) {

        if (idx<chunks.size() && p[i]==chunks[idx][0]) {
            idx++;
        }
    }

    if (idx>=chunks.size()) cout<<"YES"<<'\n';

      else  cout<<"NO"<<"\n";

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






