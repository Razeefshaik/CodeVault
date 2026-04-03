//
// Created by RAZEEF on 01-04-2026.
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

ll MAXN=20;
vll fact(MAXN);


void comp() {

    fact[0]=1;
    fact[1]=1;
    for (ll i = 2; i <=MAXN; i++) {
        fact[i]=(fact[i-1]*i);
    }

}
vector<ll> findPerm(ll n,ll k) {

    vector<ll> nums(n);
    for (int i=1;i<=n;i++) {
        nums[i-1] = i;
    }

    k--;
    vll ans;
    ll fac= fact[n-1];
    while (true) {
        ll idx= k/fac;
        ans.pb(nums[idx]);
        nums.erase(nums.begin()+idx);
        if (nums.empty()) break;
        k= k%fac;
        fac=fac/sz(nums);
    }
    return ans;
}

ll findK(ll n , queue<ll> &q) {

    ll fac= fact[n-1];
    ll ans=0;

    vector<ll> nums(n);
    for (int i=1;i<=n;i++) {
        nums[i-1] = i;
    }

    while (true) {
        ll targ= q.front();
        q.pop();
        ll idx=0;
        for (int i=0;sz(nums);i++) {
            if (nums[i]==targ) {
                idx=i;
                break;
            }
        }

        ans+= fac*idx;
        nums.erase(nums.begin()+idx);
        if (q.empty() || nums.empty()) break;
        fac=fac/sz(q);
    }

    return ans+1;
}

void moon() {

    ll q;
    cin>>q;
    if (q==1) {
        ll n;
        cin>>n;
        ll k;
        cin>>k;
        vll ans= findPerm(n,k);
        for (ll i = 0; i < sz(ans); i++) {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }else {
        ll n;
        cin>>n;
        queue<ll> load;
        for (int i=0;i<n;i++) {
            ll x;
            cin>>x;
            load.push(x);
        }
        cout<<findK(n,load)<<'\n';
    }


}

int main() {
    fast_io;

    comp();
    int t = 1;
    cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}






