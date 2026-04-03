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


ll dig(ll num) {

    ll res=0;
    while (num>0) {
        res+=num%10;
        num/=10;
    }
    return res;
}


void moon() {

    string s;
    cin>>s;

    int n=sz(s);
    if (n == 1) {
        cout << s << '\n';
        return;
    }

    vll freq(10, 0);


    ll sum=0;
    for (int i=0;i<n;i++) {

        freq[s[i]-'0']++;
        sum+=s[i]-'0';
    }

    string ans="";

    for (ll t=1;t<=sum;t++) {

        ll curr=t;
         string nums;
       // nums.pb(to_string(curr));
        nums+=to_string(curr); // First addition
        while (curr>9) {
            curr= dig(curr);
            nums+=to_string(curr);
        }
       // nums.pb(curr);         // Third addition (Duplicate!)

        vll fr(10,0);
        for (int i=0;i<sz(nums);i++) {

            fr[nums[i]-'0']++;
        }

        vll rem(10, 0);
        ll remsum=0;
        ll len= sz(nums);
        ll remcnt=0;
        bool ok=true;
        for (int i=0;i<=9;i++) {
            rem[i]=freq[i]-fr[i];
            if (rem[i]<0) ok=false;
            remsum+=i*rem[i];
            remcnt+=rem[i];
        }
        if (!ok) continue;

        if (len+remcnt!=n) continue;
        if (remsum!=t) continue;


        string rr = "";
        int first_val = -1;


        for (int p = 1; p <= 9; p++) {
            if (rem[p] > 0) {
                first_val = p;
                rem[p]--;
                break;
            }
        }

        if (first_val != -1) {
            rr += to_string(first_val);
        }


        for (int p = 0; p <= 9; p++) {
            for (int f = 0; f < rem[p]; f++) {
                rr += to_string(p);
            }
        }

        ans = rr + nums;
        break;
    }

    cout<<ans<<'\n';

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






