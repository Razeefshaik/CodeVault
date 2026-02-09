//
// Created by RAZEEF on 12-01-2026.
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


vector<vector<int>> dir={{0,1}, {0,-1}, {1,0}, {-1,0}};

void moon() {

    int n,m;
    cin >> n>>m;
    vector<string> grd(n);
    for(int i = 0; i < n; i++) cin >> grd[i];
    int start[2];
    int end[2];

    int cnt=0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grd[i][j]=='A') {
                start[0]=i;
                start[1]=j;
                cnt++;
            }else if (grd[i][j]=='B') {
                end[0]=i;
                end[1]=j;
                cnt++;
            }

            if (cnt>=2) break;
        }
        if (cnt>=2) break;
    }

    int len=INF;
    queue<tuple<int,int,int,string>> q;
    q.push({start[0],start[1],0,""});

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vis[start[0]][start[1]]=true;
    while(!q.empty()) {
        auto [i,j,l,s] = q.front();
        q.pop();

        if (grd[i][j]=='B') {
            cout<<"YES"<<"\n";
            cout<<l<<"\n";
            cout<<s<<"\n";
            return;
        }
        for (int d=0;d<4;d++) {

            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 && r<n && c>=0 && c<m && (grd[r][c]=='.' || grd[r][c]=='B') && !vis[r][c]) {
                 string ns=s;
                vis[r][c]=true;
                if (d==0) {
                    ns+='R';
                }else if (d==1) {
                    ns+='L';
                }else if (d==2) {
                   ns+='D';
                }else {
                    ns+='U';
                }
                q.push({r,c,l+1,ns});
            }
        }
    }

    cout<<"NO"<<"\n";


}

int main() {
    fast_io;

    int t = 1;
   // cin >> t; // Comment this out if there is only 1 test case (no T)

    while(t--) {
        moon();
    }

    return 0;
}
