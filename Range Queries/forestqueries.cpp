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
    vector<vector<int>>ps(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;cin>>c;
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+(c=='*');
        }
    }
    auto query=[&](int r1,int c1,int r2,int c2)->int{
        return ps[r2][c2]+ps[r1-1][c1-1]-ps[r1-1][c2]-ps[r2][c1-1];
    };
    while(q--){
        int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
        cout<<query(r1,c1,r2,c2)<<"\n";
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