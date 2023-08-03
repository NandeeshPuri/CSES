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

void solve(int tc=0){
    int n,q;cin>>n>>q;
    vector<int>ps{0};
    for(int sum=0,i=0;i<n;i++){
        int x;cin>>x;
        sum^=x;
        ps.push_back(sum);
    }

    while(q--){
        int l,r;cin>>l>>r;
        cout<<(ps[r]^ps[l-1])<<"\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    
    while(tc--){
        solve();
    }
}