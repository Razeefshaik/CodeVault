//
// Created by RAZEEF on 01-01-2026.
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


string s="-1";



void moon() {

    ll n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<pair<int, int>> q;
    q.pb({0,0});
    string res="";
    res+=s[0][0];

    int step=1;
    while (step<(2*n-1)) {

        char mini='z'+1;
        for (auto [r,c]: q) {
            if (r+1<n) mini= min(mini, s[r+1][c]);
            if (c+1<n) mini= min(mini, s[r][c+1]);
        }
        res+=mini;

        vector<pair<int, int>> q_next;
       // vector<vector<bool>> vis(n, vector<bool>(n, false));
       // set<pair<int,int>> st;
        for (auto[r,c]: q) {

            if (r+1<n && s[r+1][c]==mini) {
                q_next.pb({r+1,c});

            }
            if (c+1<n && s[r][c+1]==mini) {
                q_next.pb({r,c+1});

            }
        }

        sort(all(q_next));
        q_next.erase(unique(all(q_next)),end(q_next));
        q=q_next;
        step++;
    }

    cout << res << '\n';


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

