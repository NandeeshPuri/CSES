#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    int n;cin>>n;
    int ans=0;
    for(int i=1;i*i<=n;i++){
        if(n%i)continue;
        ans+=2;
        if(i*i==n)ans--;
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        solve();
    }
}