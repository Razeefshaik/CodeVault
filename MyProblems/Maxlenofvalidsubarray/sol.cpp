//
// Created by RAZEEF on 03-03-2026.
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

    ll n,m,k;
    cin >> n>>k>>m;
    vll nums(n);
    for (ll i = 0; i < n; i++) cin>>nums[i];

    ll l=0;
    map<int,int> kmpp;
    multiset<int> st;

    //int n=nums.size();
    long long ans=0;
    for(int r=0;r<n;r++){

        if(st.find(kmpp[nums[r]])!=st.end()) st.erase(st.find(kmpp[nums[r]]));
        kmpp[nums[r]]++;
        st.insert(kmpp[nums[r]]);

        while(kmpp.size()>k && l<r){
            st.erase(st.find(kmpp[nums[l]]));
            kmpp[nums[l]]--;
            if(kmpp[nums[l]]!=0) st.insert(kmpp[nums[l]]);
            if(kmpp[nums[l]]==0) kmpp.erase(nums[l]);
            l++;
        }

        if(kmpp.size()==k && *st.begin()>=m){
            ans=max(ans, r-l+1);
        }

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






