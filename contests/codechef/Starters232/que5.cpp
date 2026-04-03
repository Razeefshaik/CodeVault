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


const int MAXN=200005;
const ll bsz=450;

vll cnt(MAXN);
vll bcnt(MAXN/bsz+5), bsum(MAXN/bsz+5);

void add(ll val) {
    cnt[val]++;
    int b=val/bsz;
    bcnt[b]++;
    bsum[b]+=val;
}


void moon() {

    ll n,Q;
    cin >> n>>Q;
    vll a(n+1);
    for (ll i = 1; i <=n; i++) cin>>a[i];

    vector<vector<pll>> qrs(n+1);
    for (int i=0;i<Q;i++) {
        ll x,y;
        cin >> x >> y;
        qrs[x].pb({y,i});
    }

    vll ans(Q);
    for (int i=1;i<=n;i++) {
        add(a[i]);

        for (auto it: qrs[i]) {
            ll rsum=it.fi;
            ll c=0;

            for (int b=0;b<=n/bsz;b++) {

                if (bsum[b]<=rsum) {
                    rsum-=bsum[b];
                    c+=bcnt[b];
                }else {
                    ll st= b*bsz;
                    ll ed= min((b+1)*bsz-1, n);
                    for (ll v=max(1ll,st);v<=ed;v++) {
                        if (cnt[v]==0) continue;

                        ll t=min(cnt[v], rsum/v);
                        c+=t;
                        rsum-= t*v;
                        if (rsum<v) break;
                    }
                    break;
                }
            }
            ans[it.se]=c;
        }
    }

    for (int q=0;q<Q;q++) {
        cout<<ans[q]<<"\n";
    }

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






