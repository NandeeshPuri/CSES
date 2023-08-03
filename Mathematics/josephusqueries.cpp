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

int query(int n,int k){
    if(n==1){
        return 1;
    }else if(n%2){
        return (k<=(n+1)/2)?2*k%n:2*query(n/2,k-(n+1)/2)+1;
    }else{
        return (k<=n/2)?2*k:2*query(n/2,k-n/2)-1;
    }
}

void solve(int tc=0){
    int n,k;cin>>n>>k;
    cout<<query(n,k)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}