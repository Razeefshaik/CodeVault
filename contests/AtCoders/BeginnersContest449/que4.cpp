//
// Created by RAZEEF on 14-03-2026.
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


ll solve(ll l,ll r,ll u) {

    if (u<0) return 0;
    ll ans=0;
    for(ll i=l;i<=r;i++) {
        ll A=abs(i);

        if (u<=A) {
            if (A% 2==0) {
                ans+=(u +1);
            }
        }else{
            if(A%2==0) {

                ans+= (u/2)+(A / 2)+1;
            }else {

                ans+=(u/2)-(A/2);
            }
        }
    }

    return ans;

}

void moon() {

    ll l,r,d,u;
    cin >> l >> r >> d>>u;


    // ll p1=0;
    // if (max(u,d)>0) {
    //     p1=solve(l,r,u);
    // }
    //
    // ll p2=0;
    // if (min(u,d)>0) {
    //     p2=solve(l,r,u);
    // }
    //
    // p1= p1-p2;
    //
    // ll p3=0;
    // if (min(u,d)<0) {
    //     p3= solve(l,r,)
    // }

    ll ans=0;
    if (d>=0) {
        ans=solve(l,r, u)-(d>0?solve(l, r,d-1):0);
    }
    else if (u<=0) {
        ans=solve(l,r,abs(d))-(u<0 ? solve(l,r,abs(u)-1): 0);
    }
    else {
        ans = solve(l,r,u)+solve(l,r,abs(d))-solve(l,r,0);
    }


    cout <<ans<<"\n";

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






