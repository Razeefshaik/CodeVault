//
// Created by RAZEEF on 16-03-2026.
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

ll in=0;
ll out=0;
bool check;

void dfs(int u, int c,vector<vector<int>>& adj, vector<ll>& col) {
    col[u] = c;

    if (c==0) in++;
    else out++;
    for(int v:adj[u]){
        if (col[v]==-1){

       dfs(v, 1-c,adj,col);
        }else if(col[v]==col[u]){

        check=false;
        }
    }
}

void moon() {

    int n,m;
    cin>>n >> m;

    vector<vector<int>> adj(n+1);
    for (int i=0; i<m;++i) {
        int u,v;
        cin >>u >>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }


     vll col(n+1, -1);
    ll maxi=0;
    for (int i=1;i<=n;i++) {

        if (col[i]==-1) {
            check=true;
            in=0;
            out=0;

            dfs(i,0,adj,col);
            if (check) {
                maxi+=max({in,out});
            }
        }
    }

    cout<<maxi<<'\n';



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






