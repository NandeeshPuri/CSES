#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
void solve(){
    int n;cin>>n;
    ll ans= -INF,cur= -INF;
    while(n--){
        ll x;cin>>x;
        cur=max(x,cur+x);
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc=1;
    for(int t=1;t<=tc;t++){
        solve();
    }
}