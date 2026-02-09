//
// Created by RAZEEF on 31-01-2026.
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




// void moon() {
//
//
//
//     string s;
//     cin >> s;
//
//     ll n =sz(s);
//
//     if (n==1 && s[0]=='*') {
//         cout<<1<<'\n';
//         return;
//     }
//
//     for(int i=0;i<n;i++) {
//
//         if (s[i]=='>') s[i]='<';
//         else if (s[i]=='<') s[i]='>';
//     }
//
//     for(int i=0;i<n;i++) {
//
//        // if (i+1<n && s[i]=='>' && s[i+1]=='<') break;
//         if (i+1<n && ((s[i]=='*' && s[i+1]=='*') || (s[i]=='<' && s[i+1]=='>') || (s[i]=='<' && s[i+1]=='*') ||
//             (s[i]=='*' && s[i+1]=='>'))){
//             cout<<-1<<'\n';
//             return;
//             }
//
//         // if (i+1>=n) cnt++;
//     }
//     if (s[0]=='<' && s[n-1]=='>') {
//         cout<<-1<<'\n';
//         return;
//     }
//
//     int cnt=1;
//     bool frontflag=false;
//
//     if (s[0]=='>' || s[0]=='*') {
//         for(int i=0;i<n;i++) {
//
//             if (i+1<n && s[i]=='>' && s[i+1]=='<') break;
//             if (i+1<n && ((s[i]=='*' && s[i+1]=='*') || (s[i]=='<' && s[i+1]=='>') || (s[i]=='<' && s[i+1]=='*') ||
//                 (s[i]=='*' && s[i+1]=='>'))){
//                 cout<<-1<<'\n';
//                 return;
//                 }else if (i+1<n){
//                     cnt++;
//                 }
//
//            // if (i+1>=n) cnt++;
//         }
//     }else cnt=0;
//
//     int bcnt=1;
//
//     if (s[n-1]=='<' || s[n-1]=='*') {
//         for(int i=n-1;i>=0;i--) {
//
//             if (i-1>=0 && s[i-1]=='>' && s[i]=='<') break;
//             if (i-1>=0 && ((s[i-1]=='*' && s[i]=='*') || (s[i-1]=='<' && s[i]=='>') || (s[i-1]=='<' && s[i]=='*') ||
//                    (s[i-1]=='*' && s[i]=='>'))){
//
//                     cout<<-1<<'\n';
//                     return;
//
//
//                    }else if (i-1>=0) {
//                        bcnt++;
//                    }
//
//             //if (i-1<0) bcnt++;
//         }
//     }else bcnt=0;
//
//     if (cnt==0 && bcnt==0) {
//         cout<<-1<<'\n';
//         return;
//     }
//     cout<<max(cnt, bcnt)<<'\n';
//
//
// }

void moon() {

    string s;
    cin >> s;

    ll n =sz(s);

    for (int i = 0; i < n - 1; i++) {
        if (s[i] != '<' && s[i+1] != '>') {
            cout << -1 << '\n';
            return;
        }
    }

    int left_path = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        left_path++;
    }

    int right_path = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<') break;
        right_path++;
    }


    cout << max(left_path, right_path) << '\n';
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






