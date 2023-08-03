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

ll qexp(ll a,ll b,ll m){
    ll res=1;
    while (b>0)
    {
        if(b & 1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

void solve(int tc=0){
    int a,b,c;cin>>a>>b>>c;
    cout<<qexp(a,qexp(b,c,MOD-1),MOD)<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}