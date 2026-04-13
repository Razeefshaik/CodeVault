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



#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:

    Node* links[2];


    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    bool contains(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxFind(int num) {
        Node* node = root;
        int maxVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;


            if (node->contains(1 - bit)) {
                maxVal = maxVal | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxVal;
    }
};



    int findMaximumXOR(vector<ll>& nums) {
        int maxVal = 0;

        Trie buildTree;


        for (int it : nums) {
            buildTree.insert(it);
        }


        for (int it : nums) {
            maxVal = max(maxVal, buildTree.maxFind(it));
        }

        return maxVal;
    }




void moon() {

    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++) cin>>a[i];

        cout<<findMaximumXOR(a)<<'\n';


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






