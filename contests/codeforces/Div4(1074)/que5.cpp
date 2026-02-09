//
// Created by RAZEEF on 18-01-2026.
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


int findLessThan(const vector<ll>& arr, ll k) {

    auto it = lower_bound(arr.begin(), arr.end(), k);


    if (it == arr.begin()) return -1;


    return *(--it);
}


int findGreaterThan(const vector<ll>& arr, ll k) {

    auto it = upper_bound(arr.begin(), arr.end(), k);


    if (it == arr.end()) return -1;


    return *it;
}


int findFloorIndex(const vector<ll>& arr, ll k) {

    auto it = upper_bound(arr.begin(), arr.end(), k);


    if (it == arr.begin()) {
        return -1;
    }


    return (it - arr.begin()) - 1;
}

int findFirstGeIndex(const vector<ll>& arr, ll k) {

    auto it = lower_bound(arr.begin(), arr.end(), k);


    if (it == arr.end()) {
        return -1;
    }


    return (it - arr.begin());
}

void moon() {

    ll n,m,k;
    cin >> n>>m>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    string s;
    cin >> s;

    sort(all(b));


    ll shift=0;
    unordered_map<ll, ll> mpp;
    mpp[0]=0;
    for (int i=0;i<k;i++) {

        if (s[i]=='L') shift--;
        if (s[i]=='R') shift++;
        if (!mpp.count(shift)) mpp[shift]=i;

    }



  vll d(n,k+1);
    for (int i=0;i<n;i++) {

        ll rp=a[i];
        ll l=a[i]-k, r=a[i]+k;



        auto it = lower_bound(b.begin(), b.end(), rp);


        if(it != b.end()){
            long long spike_pos = *it;
            long long needed_shift = spike_pos - rp;

            if(abs(needed_shift) <= k && mpp.count((int)needed_shift)){
                d[i] = min(d[i], mpp[(int)needed_shift]);
            }
        }


        if(it != b.begin()){
            long long spike_pos = *prev(it);
            long long needed_shift = spike_pos - rp;

            if(abs(needed_shift) <= k && mpp.count((int)needed_shift)){
                d[i] = min(d[i], mpp[(int)needed_shift]);
            }
        }


    }



    vll cnt(k+2);
    for (int i=0;i<n;i++) {

        if (d[i]<=k) cnt[d[i]]++;
    }

    int al=n;
    for (int i=0;i<k;i++) {

        al-=cnt[i];
        if (i<k-1) cout<<al<<" ";
        else cout<<al<<"\n";
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



