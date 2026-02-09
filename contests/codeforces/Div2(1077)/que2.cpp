//
// Created by RAZEEF on 29-01-2026.
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


int count(int cnt) {

    if (cnt<=0) return 0;
    return cnt/2;
}

void moon() {

    ll n;
    cin >> n;
    vector<ll> a(n);

    string s;
    cin >> s;

    if (sz(s)==1) {
        cout << 1 << '\n';
        return;
    }

    ll cnt=0;
    ll op=0;
    ll onef=-1, onee=-1;

    for (int i=0;i<n;i++) {

        if (s[i]=='1') {
            op++;
            if (onef==-1) onef=i;
            onee=i;
        }
    }



    if (op==0) {
        ll c= (n+2)/3;
        cout<<c<<'\n';
        return;
    }



    ll sum=0;

    sum+= (onef+1)/3;
    sum+= (n-onee)/3;


    for(int i = onef+1; i < onee; i++) {

        if (s[i]=='1') {

            sum+= cnt/3;
            cnt=0;
        }else {
            cnt++;
        }


    }

   sum+= cnt/3;
    cout<<sum+op<<'\n';


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






