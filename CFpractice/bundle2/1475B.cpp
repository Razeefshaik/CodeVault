//
// Created by RAZEEF on 03-04-2026.
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

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(long long A, long long B, long long C, long long &x, long long &y, long long &g) {
    long long x0, y0;
    g = extended_gcd(abs(A), abs(B), x0, y0);

    if (C % g != 0) return false;

    x = x0 * (C / g);
    y = y0 * (C / g);


    if (A < 0) x = -x;
    if (B < 0) y = -y;

    return true;
}



void moon() {

    ll n;
    cin >> n;

    ll x,y,g;
    bool check=find_any_solution(2020, 2021,n,x,y,g);
    if (!check) {
        cout << "NO"<<'\n';
        return;
    }

    ll stepx= 2021/g;
    ll stepy= 2020/g;
    ll shift= (x%stepx+stepx)%stepx;
    ll k= (x-shift)/stepx;
    y= y+k*stepy;
     if (y>=0) cout<<"YES"<<'\n';
     else cout<<"NO"<<'\n';
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






