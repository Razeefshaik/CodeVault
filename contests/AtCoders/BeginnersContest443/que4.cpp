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




// void moon() {
//
//     ll n;
//     cin >> n;
//     vector<ll> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//
//
//     ll mini=LINF;
//     ll idx=-1;
//     for(int i = 0; i < n; i++) {
//
//         if (a[i]<mini) {
//             min  i=a[i];
//             idx=i;
//         }
//     }
//
//     ll sum=0;
//     for (int i=idx+1;i<n;i++) {
//
//         ll p=a[i-1];
//         ll curr=a[i];
//
//
//
//         if (p>=curr) continue;
//         ll diff=(curr-(p+1));
//         sum+=diff;
//         a[i]=a[i]-diff;
//
//     }
//
//
//     for (int i=idx-1;i>=0;i--) {
//
//         ll p=a[i+1];
//         ll curr=a[i];
//
//         if (p>=curr) continue;
//
//
//         ll diff=(curr-(p+1));
//         sum+=diff;
//         a[i]=a[i]-diff;
//     }
//
//     cout << sum << '\n';
//
//
// }

void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];


    vll b=a;
    for (int i=1;i<n;i++) {
        b[i]=min(b[i],b[i-1]+1 );
    }

    for (int i=n-2;i>=0;i--) {
        b[i]=min(b[i],b[i+1]+1);
    }


    ll sum=0;
    for (int i=0;i<n;i++) {
        sum+=(abs(a[i]-b[i]));
    }
    cout << sum << '\n';
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






