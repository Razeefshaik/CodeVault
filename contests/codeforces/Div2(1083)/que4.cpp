//
// Created by RAZEEF on 26-02-2026.
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

#include <bits/stdc++.h>
using namespace std;

 vector<ll> LIS(vector<ll> &arr) {

     int n = arr.size();

     vector<ll> tail;
     vector<ll> pidx(n, -1);

     for(int i = 0; i < n; i++) {


         int l = 0, r = tail.size();

         while(l < r) {
             int mid = (l + r) / 2;

             if(arr[tail[mid]] < arr[i])
                 l = mid + 1;
             else
                 r = mid;
         }

         int pos = l;

         if(pos == tail.size())
             tail.push_back(i);
         else
             tail[pos] = i;

         if(pos > 0)
             pidx[i] = tail[pos - 1];
     }


     vector<ll> lis;
     int idx = tail.back();

     while(idx != -1) {
         lis.push_back(idx);
         idx = pidx[idx];
     }

     reverse(lis.begin(), lis.end());

     return lis;
 }



 void moon() {

     ll n;
     cin >> n;
     vll a(n);
     for (ll i = 0; i < n; i++) cin>>a[i];


     vll one= LIS(a);
     vll b=a;
     reverse(all(b));
     vll two= LIS(b);
     ll ans=0;
     int uu=sz(one);
     int vv= sz(two);



     vll pmx(n,-1);
     pmx[0]=a[0];
     for (int i=1;i<n;i++) {
         pmx[i]=max(pmx[i-1],a[i]);
     }

     vll spmx(n,-1);
     spmx[n-1]=a[n-1];
     for (int i=n-2;i>=0;i--) {
         spmx[i]=max(spmx[i+1],a[i]);
     }



     if (one[0]!=0 && pmx[one[0]-1]<a[one[0]]) {
          uu++;
     }
     if (one[n-1]!=n-1 && spmx[one[n-1]+1]<a[one[n-1]]) {
         uu++;
     }









     vll mpmx(n,-1);
     mpmx[0]=b[0];
     for (int i=1;i<n;i++) {
         mpmx[i]=max(mpmx[i-1],b[i]);
     }
     vll spmp(n,-1);
     spmp[n-1]=b[n-1];
     for (int i=n-2;i>=0;i--) {
         spmp[i]=max(spmp[i+1],b[i]);
     }

     if (two[0]!=0 && mpmx[two[0]-1]<b[two[0]]) {
         vv++;
     }
     if (two[n-1]!=n-1 && spmp[two[n-1]+1]<b[two[n-1]]) {
         vv++;
     }


    // cout<<n-ans<<'\n';
     ans=max(uu, vv);

     cout<<n-ans<<'\n';


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






