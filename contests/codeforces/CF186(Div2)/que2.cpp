//
// Created by RAZEEF on 29-12-2025.
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


bool check(ll n, ll a, ll b) {

    ll curl=1;
    ll sum1=0,sum2=0;
    for (int i=1;i<=n;i++) {

        if (i%2!=0) {
            sum1+=curl;
        }else {
            sum2+=curl;
        }

        curl*=2;

    }


    bool case1= (sum1<=a)&& (sum2<=b);
    bool case2= (sum1<=b)&& (sum2<=a);

    return case1||case2;
}

void moon() {

    ll a,b;
    cin >> a>>b;


    ll n=1;
    ll low=1, high=22;
    while(low<=high) {
        ll mid=high+(low-high)/2;

        if (check(mid,a,b)) {
            n=mid;
            low=mid+1;
        }else {
            high=mid-1;
        }
    }

    cout<<n<<endl;



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

