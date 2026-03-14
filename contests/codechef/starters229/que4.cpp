//
// Created by RAZEEF on 11-03-2026.
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


bool check(vll &a) {

    int l=0;
    int r=sz(a)-1;

    while (l<r) {

        if (a[l]!=a[r]) return false;

        l++;
        r--;
    }

    return true;
}

void moon() {

    ll n;
    cin >> n;
    vll a(2*n);
    for (ll i = 0; i < 2*n; i++) cin>>a[i];

    if (check(a)) {
        cout<<"Yes"<<'\n';
        return;
    }

    vll s1, s2;
    map<ll, ll> mpp;
    for (ll i = 0; i < 2*n; i++) {

        mpp[a[i]]++;
        if (mpp[a[i]]==1) {
            s1.pb(a[i]);
        }else {
            s2.pb(a[i]);
        }
    }

    // if (s1==s2) {
    //     cout<<"Yes"<<'\n';
    //     return;
    // }else {
    //     cout<<"No"<<'\n';
    // }


    vll ps(n+1);
    for (int i=0;i<n;i++) {
        ps[s1[i]]=i;
    }

    vll bs(n);
    for (int i=0;i<n;i++) {
        bs[i]=ps[s2[i]];
    }


    int p=1,s=1;
    while (p<n && bs[p]<bs[p-1]) {
        p++;
    }
    while (s<n && bs[n-1-s]<bs[n-s]) {
        p++;
    }

    if (p+s>=n) {
        cout<<"No"<<'\n';
    }else {
        cout<<"Yes"<<'\n';
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






