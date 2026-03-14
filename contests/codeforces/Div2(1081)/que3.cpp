//
// Created by RAZEEF on 21-02-2026.
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

    ll n,h,k;
    cin>>n>>h>>k;
    vll a(n);
    vector<pll> ta(n);

    ll maxi=0;
    ll sum=0;


    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        ta[i]={a[i], i};
        maxi=max(maxi, a[i]);
        sum+=a[i];
    }

    vector<ll> suff(n);
    ll smaxi=a[n-1];
    for (int i = n-1; i >= 0; i--) {
        smaxi=max(smaxi, a[i]);
        suff[i]=smaxi;
    }

    sort(all(ta));
    reverse(all(ta));


    // for (int i=0;i<n;i++) {
    //
    //     if (a[i]!=ta[i].first) {
    //         ll temp=a[i];
    //         a[i]=ta[i].fi;
    //         a[ta[i].se]=temp;
    //         break;
    //     }
    // }


    ll st= (h-1)/sum;

    ll q=st;
    st= st*(n+k);
    ll rem=h- (sum*q);




    ll mini=a[0];
    ll tsum=0;
    for (int i=0;i<n;i++) {

        st++;
        tsum+=a[i];
        mini=min(mini, a[i]);

        ll check = tsum;
        if (i + 1 < n) {

            check += max(0LL, suff[i + 1] - mini);
        }

        if (check >= rem) {
            cout << st << '\n';
            return;
        }

        //rem-=a[i];

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






