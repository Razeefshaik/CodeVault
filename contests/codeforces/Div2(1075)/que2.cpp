//
// Created by RAZEEF on 23-01-2026.
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

    int cnt=0;
    for (int i=0;i<63;i++) {

        if (n&(1ll<<i)) {
            cnt++;
        }




    }


    if (cnt==1) {
        cout<<-1<<'\n';
        return;
    }




    vector<ll> a(n+1);

    int x=1;
    a[n]=x;


    map<ll,ll> mpp;
    mpp[x]=1;
    for (int i=2; i<n; i++) {

        if (i!=x) {
            a[i]=i^x;
            mpp[a[i]]=1;
        }
    }


    for (int i=1; i<=n; i++) {
        if (!mpp.count(i)) {
            a[1]=i;
            break;
        }
    }

    if (n%2==0) {

        for (int i=2;i<n;i++) {

            if ((n^i)<n) {
                swap(a[i], a[1]);
                break;
            }
        }
    }

    for (int i=1;i<=n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";











//      for (int i=2;i<n;i++) {
//
//
//          if (i%2==0) {
//              a[i]=i+1;
//          }else {
//              a[i]=i-1;
//          }
//      }
//
//
//      if (n%2==0) a[1]=n;
//     else a[1]=n-1;
//
// for (int i=1;i<=n;i++) {
//     cout << a[i] << " ";
// }
//     cout << endl;

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






