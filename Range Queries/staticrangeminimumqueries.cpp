#include <bits/stdc++.h>
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
 
 template<typename T, bool MAXIMUM_MODE = false> struct RMQ {
    int n;
    vector<T> arr;
    vector<vector<int>> spt;
 
    // Note: when `arr[i] == arr[j]`, returns j.
    int better_index(int i, int j) const {
        return (MAXIMUM_MODE ? arr[j] < arr[i] : arr[i] < arr[j]) ? i : j;
    }
 
    void init(const vector<T> &a) {
        n = (int) a.size();
        arr = a;
        spt.emplace_back(n);
        for (int i = 0; i < n; i++) spt[0][i] = i;
        for (int j = 1; (1 << j) <= n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) <= n; i++) { 
                spt[j][i] = better_index(spt[j - 1][i], spt[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    // Note: breaks ties by choosing the largest index.    
    int query_idx(int l, int r) const {
        int k = __lg(r - l + 1);
        return better_index(spt[k][l], spt[k][r - (1 << k) + 1]);
    }
 
    T query(int l, int r) const {
        return arr[query_idx(l, r)];
    }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    RMQ<int> rmq; rmq.init(a);
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << rmq.query(l, r) << "\n";
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