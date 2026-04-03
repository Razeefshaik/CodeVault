//
// Created by RAZEEF on 28-03-2026.
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

    ll n,k;
    cin >> n>>k;
    vll a(n), b(n);


    map<ll, ll> mppa, mppb;
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        // mppa[a[i]]++;
        // if (mppa[a[i]]>1) {
        //     cout<<"NO"<<'\n';
        //     return;
        // }
    }
    for (ll i = 0; i < n; i++) {
        cin>>b[i];
        // mppa[b[i]]++;
        // if (mppb[b[i]]>1 && b[i]!=-1) {
        //     cout<<"NO"<<'\n';
        //     return;
        // }
    }


    for (int i=0;i<=n-k-1;i++) {
        if (b[i]!=-1 && a[i]!=b[i]) {
            cout<<"NO"<<'\n';
            return;
        }
    }

    for (int i=k;i<n;i++) {
        if (b[i]!=-1 && a[i]!=b[i]) {
            cout<<"NO"<<'\n';
            return;
        }
    }

    map<ll, ll> mpp1, mpp2;
    for (ll i = n-k; i <k ; i++) {

        mpp1[a[i]]++;
    }
    bool f=true;
    for (ll i = n-k; i < k; i++) {
        if (b[i] != -1) {
            if (!mpp1.count(b[i])) {
                f = false;
                break;
            } else {
                mpp1.erase(b[i]);
            }
        }
    }

    if (f) {
        cout<<"YES"<<'\n';
    }else {
        cout<<"NO"<<'\n';
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






