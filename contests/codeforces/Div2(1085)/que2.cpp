#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void moon() {
    ll n, m, l;
    cin >> n >> m >> l;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> anims(m, 0);
    ll tim = 0;

    for (int t = 0; t <= n; t++) {
        ll curt = (t == n) ? l : a[t];
        ll td = curt - tim;
        

        int k = min(m, n - t + 1);


        vector<ll> B(k);
        for (int i = 0; i < k; i++) {
            B[i] = anims[k - 1 - i];
        }


        for (int i = 1; i < k; i++) {
            ll diff = B[i] - B[i - 1];
            if (diff > 0) {
                ll need = diff * i;
                if (td >= need) {
                    td -= need;
                    for (int j = 0; j < i; j++) {
                        B[j] = B[i];
                    }
                } else {
                    ll all = td / i;
                    ll rem = td % i;
                    for (int j = 0; j < i; j++) {
                        B[j] += all;
                    }
                    for (int j = 0; j < rem; j++) {
                        B[i - 1 - j] += 1;
                    }
                    td = 0;
                    break;
                }
            }
        }


        if (td > 0) {
            ll all = td / k;
            ll rem = td % k;
            for (int j = 0; j < k; j++) {
                B[j] += all;
            }
            for (int j = 0; j < rem; j++) {
                B[k - 1 - j] += 1;
            }
        }


        for (int i = 0; i < k; i++) {
            anims[i] = B[k - 1 - i];
        }

        if (t < n) {
            anims[0] = 0;
            sort(anims.begin(), anims.end(), greater<ll>());
        }

        tim = curt;
    }

    cout << anims[0] << '\n';
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        moon();
    }
    return 0;
}