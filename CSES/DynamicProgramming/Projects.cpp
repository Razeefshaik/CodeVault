//
// Created by RAZEEF on 08-01-2026.
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


struct Project{

    int start,end,cost;
  };




void moon() {

    ll n;
    cin >> n;
    vector<Project> a(n);
    for(int i = 0; i < n; i++) {

        Project p; cin >> p.start >> p.end >> p.cost;
        a[i]= p;
    }

    sort(all(a), [](const Project& a, const Project& b) {

       return a.end<b.end;

    });

    vector<ll> endt(n);
    for(int i = 0; i < n; i++) {
        endt[i] = a[i].end;
    }

    vector<ll> dp(n+1,0);

    for (int i=1;i<=n;i++) {

        ll leave=dp[i-1];

        ll t=a[i-1].start;

        auto idx= lower_bound(all(endt), t)-endt.begin();



        ll take=a[i-1].cost;
        if (idx>=0) {
            take +=dp[idx];
        }

        dp[i]=max(take,leave);

    }

    cout<<dp[n]<<'\n';


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
