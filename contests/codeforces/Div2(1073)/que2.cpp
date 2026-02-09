//
// Created by RAZEEF on 17-01-2026.
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


int mex(int i,int j,vll &a) {


    map<ll,ll> mpp;
    for (int k=i;k<=j;k++) {
        mpp[a[k]]++;
    }

    for (int k=0;k<100;k++) {
        if (!mpp.count(k)) {
            return k;
        }
    }

    return -1;


}

void moon() {

    ll n;
    cin >> n;

    int cnt0=0,cnt1=0;


    for(int i = 0; i < n; i++){

        int x;

        cin >> x;

        if (x==0) {
            cnt0++;
        }
        else if (x==1) {
            cnt1++;
        }
    }

    if (cnt0==0) {
        cout<<"NO"<<'\n';
        return;
    }
    if (cnt0>=2 && cnt1==0) {
        cout<<"No"<<'\n';
        return;
    }





    cout<<"Yes"<<endl;


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



