//
// Created by RAZEEF on 14-01-2026.
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

    int n,m;
    cin >> n>>m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);

      }

    vector<bool> vis(n,false);
    vi parent(n,-1);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()) {
        int node=q.front();
        q.pop();



        for (auto v: adj[node]) {
            if (vis[v]==false) {
                parent[v]=node;
                q.push(v);
                vis[v]=true;
            }
        }
    }

    if (!vis[n-1]) {
        cout<<"IMPOSSIBLE"<<'\n';
        return;
    }

    vi ans;
    int p=n-1;
    while (p!=-1) {
        ans.pb(p+1);
        p=parent[p];
    }
    reverse(all(ans));
    cout<<ans.size()<<'\n';
    for(auto v: ans) cout<<v<<" ";
    cout<<'\n';


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
