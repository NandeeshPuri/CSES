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

struct Node {
    ll sum, pre;
    Node(): sum(0), pre(0) {}
    Node(ll x): sum(x), pre(max(0ll, x)) {}
    Node(const Node &l, const Node &r) {
        sum = l.sum + r.sum;
        pre = max(l.pre, l.sum + r.pre);
    }
};
 
struct SegmentTree { 
    int ln(int node) { return 2 * node; }
    int rn(int node) { return 2 * node + 1; }
    
    int n; vector<Node> st;
 
    void init(int _n) { n = _n; st.resize(4 * _n); }
    void init(vector<int> &a) { init(sz(a)); build(a, 1, 0, n - 1); }
    
    void apply(int node, ll x) {
        st[node] = Node(x);
    }
 
    void build(vector<int> &a, int node, int start, int end) {
        if (start == end) {
            st[node] = Node(a[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(a, ln(node), start, mid);
        build(a, rn(node), mid + 1, end);
        st[node] = Node(st[ln(node)], st[rn(node)]);
    }
 
    void update(int node, int start, int end, int i, ll x) {
        if (start == end) {
            apply(node, x);
            return;
        }
        int mid = (start + end) / 2;
        if (i <= mid) update(ln(node), start, mid, i, x);
        else update(rn(node), mid + 1, end, i, x);
        st[node] = Node(st[ln(node)], st[rn(node)]);
    }
 
    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        return Node(query(ln(node), start, mid, l, r), query(rn(node), mid + 1, end, l, r));
    }
 
    void update(int i, ll x) { update(1, 0, n - 1, i, x); }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SegmentTree st; st.init(a);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; i--;
            st.update(i, x);
        } else {
            int l, r; cin >> l >> r; l--; r--;
            cout << st.query(l, r).pre << "\n";
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