//
// Created by RAZEEF on 27-03-2026.
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


vector<ll> prms= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};

// void moon() {
//
//     ll n;
//     cin >> n;
//     vll a(n);
//     for (ll i = 0; i < n; i++) cin>>a[i];
//
//     vector<ll> arr;
//     for (auto it: a) {
//         ll num=0ll;
//         for (int i=0;i<21;i++) {
//             if (it%prms[i]==0) {
//                 num= num|(1ll<<i);
//             }
//         }
//         arr.pb(num);
//     }
//
//     ll bits=21;
//     ll maxNum= (1<<bits);
//     vector<ll> dp(maxNum);
//     ll z=0;
//     for (auto it: arr) {
//         dp[it]++;
//         if (it==0) z++;
//     }
//
//     for (int i=0;i<bits;i++) {
//
//         for (int mask=0;mask<maxNum;mask++) {
//             if (mask&(1<<i)) {
//                 dp[mask]+=dp[mask^(1<<i)];
//             }
//         }
//
//     }
//
//     ll tot=0;
//     ll fullmask= maxNum-1;
//     for (int i=0;i<arr.size();i++) {
//
//         tot+=dp[(~arr[i])&fullmask];
//     }
//
//     tot-=z;
//     tot/=2;
//     cout<<tot<<"\n";
//
//
// }

ll maxVal=1e6+2;
void moon() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];


    vll sieve(maxVal);
    vvll divs(maxVal);
    for (int i=2;i<maxVal;i++) {

        if (divs[i].empty()) {

            for (int p=i;p<maxVal;p=p+i) {
                divs[p].pb(i);
            }
        }
    }

    vll A(maxVal), B(maxVal);
    for (int i=0;i<n;i++) {
        ll sz=divs[a[i]].size();


        for (int mask=1;mask<(1<<sz);mask++) {

            ll combi=1;
            ll bits=0;
            for (int b=0;b<sz;b++) {
                if (mask&(1<<b)) {
                    combi*=divs[a[i]][b];
                    bits++;
                }
            }
            A[combi]++;
            B[combi]=bits;
        }
    }

    ll tot= n*(n-1)/2ll;
    ll combi=0;
    for (int i=0;i<maxVal;i++) {

        if (B[i]%2==0) {
            combi-=A[i]*(A[i]-1)/2ll;
        }else {
            combi+=A[i]*(A[i]-1)/2ll;
        }
    }

    cout << tot-combi<<'\n';


}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






