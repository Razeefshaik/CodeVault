//
// Created by RAZEEF on 17-01-2026.
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

    ll n,m;
    cin >> n>>m;
    vvll dist(n,vector<ll>(n,LINF));
    vll rud(n,0);
    for(int i = 0; i < n; i++) {
        cin>>rud[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if (i==j) dist[i][j]=0;
        }
    }

    for(int i = 0; i < m; i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        dist[u][v]= min(dist[u][v], w);
        //dist[v][u]= min(dist[v][u], w);
    }

    for (int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {

                if (dist[i][k]!=LINF && dist[k][j]!=LINF) {
                    dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        ll mini=LINF;
        ll nei=-1;
        for(int j=0;j<n;j++) {
            if (i==j) continue;

            if (dist[i][j]!=LINF && (rud[j]+dist[i][j])<mini) {
                mini=rud[j]+dist[i][j];
                nei=j;
            }
        }

        if (nei==-1) {
            cout<<-1<<" "<<-1<<'\n';

        }else {
            cout<<nei+1<<" "<<mini<<'\n';
        }

    }

    cout<<endl;


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



