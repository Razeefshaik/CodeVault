//
// Created by RAZEEF on 19-01-2026.
//
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

void moon() {

    set<ll> st;
    for(int i=1;i<10;i++){
        st.insert(i);
      }
    cout<<*st.begin()<<endl;
    cout<<st.begin()+2<<endl;

}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while(t--) {
        moon();
    }
    return 0;
}