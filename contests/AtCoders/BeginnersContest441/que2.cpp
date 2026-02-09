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
   string s;
    string t;
    cin >> s;
    cin>>t;

    ll q;
    cin>>q;

    map<char, ll> takMpp;
    map<char, ll> aokmpp;
    for (auto it: s) {
        takMpp[it]++;
    }
    for (auto it: t) {
        aokmpp[it]++;
    }
    for (int i=0;i<q;i++) {

        int t=0,a=0;
        string w;
        cin>>w;
        bool flagt=true, flaga=true, flagb=true;

        for (auto it: w) {
            if (takMpp.count(it)) t++;
            if (!takMpp.count(it)) flagt=false;
            if(aokmpp.count(it)) a++;
            if (!aokmpp.count(it)) flaga=false;

            if (!flagt && !flaga) flagb=false;
        }

        if (flaga && flagt) {
            cout<<"Unknown"<<endl;
        }else if (flaga){
            cout<<"Aoki"<<endl;
        }else if (flagt) {
            cout<<"Takahashi"<<endl;
        }else {
            cout<<"Unknown"<<endl;
        }

        cout<<'\n';

    }


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



