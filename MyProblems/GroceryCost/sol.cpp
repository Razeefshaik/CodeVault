//
// Created by RAZEEF on 03-02-2026.
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

void genSubs(int ind,int end,int currk,ll sum,vll &cost, vll &qty, vvll &half, int k, ll maxCost) {
    int n=sz(cost);

    if (currk>k) return;
    if (ind==end) {
        half[currk].pb(sum);
        return;
    }

    for (int q=0;q<=qty[ind];q++) {

        if (currk+q>k) break;
        if ((sum+(ll)q*cost[ind])> maxCost) break;

        genSubs(ind+1,end,currk+q, sum+ (ll)q*cost[ind],cost,qty,half,k,maxCost);
    }
}


void moon() {

    int n,k;
    cin >> n>>k;
    vector<ll> cost(n), qty(n);
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < n; i++) cin >> qty[i];
    ll maxCost,minCost;
    cin>>minCost>>maxCost;


    int N=n/2;
    vvll leftHalf(k+1), rightHalf(k+1);
    genSubs(0,N,0,0,cost,qty,leftHalf,k,maxCost);
    genSubs(N,n,0,0,cost,qty,rightHalf,k,maxCost);




    ll ans=0;
    for(int i = 0; i <=k; i++) {
        int j=k-i;
        if (j<0) continue;
        if (leftHalf[i].empty() || rightHalf[j].empty()) continue;
        sort(all(rightHalf[j]));

        for (auto it: leftHalf[i]) {

           ll reqMin= minCost-it;
            ll reqMax= maxCost-it;

            auto& rdx=rightHalf[j];
            auto it_l=lower_bound(all(rdx), reqMin);
            auto it_h=upper_bound(all(rdx), reqMax);

            ans+=distance(it_l,it_h);
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






