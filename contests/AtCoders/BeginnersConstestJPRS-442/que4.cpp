//
// Created by RAZEEF on 24-01-2026.
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






class SegTree {

public:
    vector<int> tree;
    int n;

    SegTree(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    // Build Segment Tree
    void buildTree(int idx, int l, int r, vector<int> &nums) {

        if (l == r) {
            tree[idx] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildTree(2 * idx + 1, l, mid, nums);
        buildTree(2 * idx + 2, mid + 1, r, nums);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    // Range Sum Query
    int sumQuery(int start, int end, int idx, int l, int r) {

        // No overlap
        if (r < start || end < l)
            return 0;

        // Complete overlap
        if (start <= l && r <= end)
            return tree[idx];

        // Partial overlap
        int mid = l + (r - l) / 2;

        return sumQuery(start, end, 2 * idx + 1, l, mid) +
               sumQuery(start, end, 2 * idx + 2, mid + 1, r);
    }

    // Point Update (Update single index)
    void update(int idx, int l, int r, int pos, int val) {

        if (l == r) {
            tree[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    // Swap Two Positions
    void swapUpdate(vector<int> &nums, int i, int j) {

        // Swap in original array
        swap(nums[i], nums[j]);

        // Update both positions in segment tree
        update(0, 0, n - 1, i, nums[i]);
        update(0, 0, n - 1, j, nums[j]);
    }
};




void moon() {

    ll n,q;
    cin >> n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];


    SegTree st(n);
    st.buildTree(0,0,n-1,a);

    for (int i=0;i<q;i++) {

        ll o;
        cin >> o;

        if (o==1) {
            ll idx;
            cin >> idx;

            if (idx<n) {
                st.swapUpdate(a,idx-1, idx);
            }
        }else {

            ll l,r;
            cin >> l >> r;
            l--;
            r--;
            ll ans=st.sumQuery(l, r, 0, 0, n-1);
            cout << ans << '\n';

        }
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






