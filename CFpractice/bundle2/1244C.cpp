//
// Created by RAZEEF on 21-03-2026.
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


    __int128 big_x = (__int128)x0 * (C / g);
    __int128 big_y = (__int128)y0 * (C / g);

    if (A < 0) big_x = -big_x;
    if (B < 0) big_y = -big_y;


    __int128 step_x = B / g;
    __int128 step_y = A / g;


    __int128 shifty = (big_y % step_y + step_y) % step_y;
    __int128 k = (big_y - shifty) / step_y;
    __int128 safe_x = big_x + k * step_x;


    x = (long long)safe_x;
    y = (long long)shifty;

    return true;
}

void moon() {

    ll n,p,w,d;
    cin >> n>>p>>w>>d;

    if((p%gcd(w,d))!=0) {
        cout<<-1<<'\n';
        return;
    }

    ll x,y,g;
    find_any_solution(w,d,p,x,y,g);

    ll stepx=d/g;
    ll stepy=w/g;

    ll shifty= (y%stepy+stepy)%stepy;
    ll k= (y-shifty)/stepy;
    x= x+k*stepx;
    if (x>=0 && (x+shifty)<=n) {
        cout<<x<<" "<<shifty<<" "<<n-x-shifty<<'\n';
    }else cout<<-1<<'\n';



}

int main() {
    fast_io;

    int t = 1;
    //cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






