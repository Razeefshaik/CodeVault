//
// Created by RAZEEF on 22-01-2026.
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
    vvll v(2);

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if ((a[i]%a[j])%2==0) {
                cout<<a[j]<<" "<<a[i]<<'\n';
                return;
            }
        }
    }

    cout<<-1<<'\n';







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



vector<ll>  sieve(int n) {

    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    vll ans;
    for(int i = 2; i <= n; i++) {
        if(prime[i])
            ans.pb(i);
    }

    return ans;
}



