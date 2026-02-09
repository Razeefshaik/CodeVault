//
// Created by RAZEEF on 01-02-2026.
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


vvi dir= {{1,0}, {-1,0}, {0,1}, {0,-1}};
ll solve( vvll &grid, ll lim) {
    ll n=grid.size(),m=grid[0].size();
    if (grid[0][0]>lim || grid[n-1][m-1]>lim) return  LINF;



    vvll dist(n, vll(m, LINF));
    dist[0][0]=0;

    queue<pair<ll,ll>> q;
    q.push({0,0});

    while(!q.empty()) {
        auto[i,j]=q.front(); q.pop();
        if(i==n-1 && j==m-1) {
            return dist[i][j];
        }

        for (int d=0;d<4;d++) {

            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 && r<n && c>=0 && c<m) {
                if (grid[r][c]<=lim && dist[r][c]==LINF) {
                    q.push({r,c});
                    dist[r][c]=dist[i][j]+1;
                }
            }
        }
    }

    return LINF;
}


void moon() {

    ll n,m;
    cin >> n>>m;
    vvll grid(n, vll(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<ll> lims;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            lims.pb(grid[i][j]);
        }
    }

    sort(all(lims));
    lims.erase(unique(all(lims)), lims.end());





    ll l=0, h=lims.size()-1;
    ll start=h;
    while(l<=h) {
        ll mid=l+ (h-l)/2ll;

        ll cost=solve(grid, lims[mid]);
        if (cost!=LINF) {
            h=mid-1;
            start=mid;
        }else {
            l=mid+1;
        }
    }

    if (start == lims.size()) {
        cout << -1 << endl;
        return;
    }

    ll minmanhat=(n-1)+(m-1);
    ll ans=-1;
    for (int i=start; i<lims.size(); i++) {

        if (ans!=-1 && (lims[i]+minmanhat)>=ans) {
             break;
        }

        ll cost=solve(grid, lims[i]);

        if (ans==-1 || cost+lims[i]<ans) {
            ans= cost+lims[i];
        }


        if (cost==minmanhat) break;

    }

    cout << ans << '\n';

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






