//
// Created by RAZEEF on 04-04-2026.
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

    ll n;
    cin >> n;
    vvll a(n);
    for (ll i = 0; i < n; i++) {
        ll x,y;
        cin >> x >> y;
        a[i]={x,y};
    }

    ll m;
    cin >> m;
    vector<vector<vector<int>>> mpp(12, vector<vector<int>>(12, vector<int>(26,0)));
    vector<string> q;
    for (int i=0;i<m;i++) {
        string s;
        cin >> s;
        q.push_back(s);

        for (int j=0;j<sz(s);j++) {
            mpp[sz(s)][j][s[j]-'a']=1;
        }
    }


    for (int i=0;i<sz(q);i++) {
        string ch=q[i];

        if (sz(ch) != n) {
            cout << "No\n";
            continue;
        }
        bool yes=true;;
        for (int j=0;j<n;j++) {
            ll len,pos;
            len=a[j][0];
            pos=a[j][1]-1;
            bool f=false;


            if (mpp[len][pos][ch[j] - 'a'] == 0) {
                cout << "No\n";
                yes = false;
                break;
            }
        }
        if (yes) cout<<"Yes"<<'\n';
    }

    //cout<<"Yes"<<'\n';


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






