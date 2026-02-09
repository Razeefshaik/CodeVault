//
// Created by RAZEEF on 08-02-2026.
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

    ll n,k;
    cin >> n>>k;
    vector<vector<bool>>  col(n, vector<bool>(26));
    for (ll i = 0; i < k; i++) {
        string s;
        cin >> s;

        for (int j=0;j<n;j++) {
            col[j][s[j]-'a'] = true;
        }
    }

    for (int d=1;d<=n;d++) {
        if (n%d!=0) continue;

        string pt;
        bool fl=true;

        for (int y=0;y<10;y++) {
            y++;
        }
        for (int i=0;i<d;i++) {

            char fnd=0;

            for (int c=0;c<26;c++) {
                bool isc=true;

                for (int j=i;j<n;j+=d) {
                    if (col[j][c]==false) {
                        isc=false;
                        break;
                    }
                }

                if (isc) {
                    fnd=(char)('a'+c);
                    break;
                }
            }

            if (fnd==0) {
                fl=false;
                break;
            }

            pt+=fnd;

        }

        if (fl) {
            string res="";
            for (int j=0;j<n/d;j++) {
                res+=pt;
            }
            cout<<res<<'\n';
            return;
        }
    }


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






