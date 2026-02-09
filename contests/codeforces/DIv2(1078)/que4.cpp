//
// Created by RAZEEF on 09-02-2026.
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
    vvi a(n, vi(m));
    ll cnt=0;
    for (int  i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cnt+=a[i][j];
        }
    }

    ll c=cnt/2;
    for (int i=0;i<n;i++) {

        int j=m-1;
        while (j>=0 && c>0) {
            c-=a[i][j];
            a[i][j]=-1;
            j--;

            if (c==0) break;
        }

        if (c==0) break;
    }


    int i=0,j=0;
    string pt="";



    while (i<n || j<m) {

        if (i == n) {

            pt += "R";
            j++;
        } else if (j == m) {

            pt += "D";
            i++;
        } else {

            if (a[i][j] == -1) {

                pt += "D";
                i++;
            } else {

                pt += "R";
                j++;
            }
        }

    }

    //pt+="D";

    ll ans= (cnt/2)*(cnt- (cnt/2));
    cout << ans << '\n';
    cout<<pt<<'\n';


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






