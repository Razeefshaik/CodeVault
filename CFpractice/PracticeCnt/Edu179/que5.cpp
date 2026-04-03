//
// Created by RAZEEF on 23-03-2026.
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

    ll n,q;
    cin >> n>>q;
    string s;
    cin >> s;

    set<ll> ba,bc,ca,cb;
    for (ll i = 0; i < q; i++){
        char u,v;
        cin >> u >> v;

        if (u=='b' && v=='a') ba.insert(i);
        else if (u=='b' && v=='c') bc.insert(i);
        else if (u=='c' && v=='a') ca.insert(i);
        else if (u=='c' && v=='b') cb.insert(i);
      }

    int cnt=n;
    for (int i=0;i<n;i++) {

        if (s[i]=='a') continue;

        if (s[i]=='b') {
            if (!ba.empty()) {
                ba.erase(ba.begin());
                s[i]='a';

            } else if (!bc.empty() && !ca.empty()){

                 auto it= ca.lower_bound(*bc.begin());
                if (it!=ca.end()) {
                    bc.erase(bc.begin());
                    ca.erase(it);
                    s[i]='a';
                }
            }
        }else if (s[i]=='c') {
            if (!ca.empty()) {
                ca.erase(ca.begin());
                s[i]='a';

            }else {

                bool f=false;
                if (!cb.empty() && !ba.empty()) {

                    auto it=ba.lower_bound(*cb.begin());
                    if (it!=ba.end()) {
                        ba.erase(it);
                        cb.erase(cb.begin());
                        s[i]='a';
                        f=true;
                    }

                }

                if (!f && !cb.empty()) {
                    cb.erase(cb.begin());
                    s[i]='b';

                }
            }
        }

    }

    cout << s << '\n';

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






