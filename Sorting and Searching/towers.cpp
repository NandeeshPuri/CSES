#include<bits/stdc++.h>
using namespace std;
#define ar array 
#define ll long long
const int MAX_N=1e5+1;
const ll MOD=1e9+7;
const ll INF=1e9;

void solve(){
    int n;cin>>n;
    vector<int>dp;
    while(n--){
        int x;cin>>x;
        auto it=upper_bound(dp.begin(),dp.end(),x);// binary_search for the value just greater than current cube size
        if(it==dp.end())dp.push_back(x);
        else *it=x;
    }
    cout<<dp.size()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc=1;
    for(int t=1;t<=tc;t++)
    {
        solve();
    }

}
