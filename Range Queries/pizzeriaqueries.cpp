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

struct SegmentTree{
    int n;vector<int>st;

    void init(int _n){n=_n;st.resize(2*_n);}
    void init(const vector<int>&a){
        init(sz(a));
        for(int i=0;i<n;i++)st[i+n]=a[i];
        for(int i=n-1;i>0;i--)st[i]=min(st[i<<1],st[i<<1|1]);
    }

    int query(int l,int r){
        int res=2e9;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l & 1)res=min(res,st[l++]);
            if(r & 1)res=min(res,st[--r]);
        }
        return res;
    }

    void update(int i, int x) {
        for (st[i += n] = x; i > 1; i >>= 1) st[i >> 1] = min(st[i], st[i ^ 1]);
    }
};

void solve(int tc=0){
    int n,q;cin>>n>>q;
    vector<int>a(n),a1(n),a2(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a1[i]=a[i]+i;
        a2[i]=a[i]-i;
    }
    SegmentTree st1,st2;
    st1.init(a1);
    st2.init(a2);
    while(q--){
        int t,i;cin>>t>>i;
        i--;
        if(t==1){
            int x;cin>>x;
            a[i]=x;
            a1[i]=a[i]+i;
            a2[i]=a[i]-i;
            st1.update(i,a1[i]);
            st2.update(i,a2[i]);
        }else{
            int ans=min(st1.query(i,n)-i,st2.query(0,i+1)+i);
            cout<<ans<<"\n";
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