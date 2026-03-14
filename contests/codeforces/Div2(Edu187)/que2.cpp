//
// Created by RAZEEF on 25-02-2026.
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

    ll n;
    cin >> n;

    vector<ll> v;
    ll num=n;
    while (num>0) {
        v.pb(num%10);
        num/=10;
    }



    ll sum=0;
    for (auto it: v) {
        sum+=it;
    }

    ll sum1=sum;


    ll lt=v.back();
    v.pop_back();

    sort(all(v));

    reverse(all(v));

    if (sum<=9) {
        cout<<0<<'\n';
        return;
    }
    ll cnt=0;
    for (auto it: v) {

        sum-=it;
        cnt++;
        if (sum<=9) {
            break;
        }
    }

    ll cnt1=1;
    sum1-=lt;
    sum1++;

    if (sum1<=9) {
        cout<<1<<'\n';
        return;
    }

    for (auto it: v) {

        sum1-=it;
        cnt1++;
        if (sum1<=9) {
            break;
        }
    }


  cout<<min(cnt,cnt1)<<'\n';

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






