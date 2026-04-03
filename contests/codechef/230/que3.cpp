//
// Created by RAZEEF on 19-03-2026.
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
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

    vll r1(n,n), r2(n,n);
    vll l1(n,-1), l2(n,-1);

    {
        stack<ll> s1,s2;
        for (ll i = 0; i < n; i++) {

            while (!s2.empty() && a[i]>a[s2.top()]) {
                r2[s2.top()]=i;
                s2.pop();
            }

            stack<ll> temp;
            while (!s1.empty() && a[i]>a[s1.top()]) {
                r1[s1.top()]=i;
                temp.push(s1.top());
                s1.pop();
            }

            while (!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }

            s1.push(i);
        }
    }
    {
        stack<ll> s1,s2;
        for (ll i = n-1; i>=0; i--) {

            while (!s2.empty() && a[i]>a[s2.top()]) {
                l2[s2.top()]=i;
                s2.pop();
            }

            stack<ll> temp;
            while (!s1.empty() && a[i]>a[s1.top()]) {
                l1[s1.top()]=i;
                temp.push(s1.top());
                s1.pop();
            }
            while (!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }
    }

    ll ans=0;
    for (int i=0;i<n;i++) {

        ll left= (i-l1[i])*( r1[i]==n? 0: r2[i]-r1[i]);
        ll right= (r1[i]-i)*(l1[i]==-1? 0: l1[i]-l2[i]);
        ans+=a[i]*(left+right);
    }

    cout<<ans<<'\n';


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






