#include<bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> st(2 * n);
    for (int i = 0; i < n; i++) cin >> st[i + n];
    for (int i = n - 1; i > 0; i--) st[i] = min(st[i << 1], st[i << 1 | 1]);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; i--;
            for (st[i += n] = x; i > 1; i >>= 1) st[i >> 1] = min(st[i], st[i ^ 1]);
        } else {
            int l, r; cin >> l >> r; l--;
            int res = INT_MAX;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = min(res, st[l++]);
                if (r & 1) res = min(res, st[--r]);
            }
            cout << res << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}