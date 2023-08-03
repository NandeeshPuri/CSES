#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,i,j;
    ll sum=0;
    cin>>n;
    vector<ll>dp(n);
    vector<int>a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        dp[i]=a[i];
    }
    for(i=n-1;i>=0;i--)
    {
    for(j=i+1;j<n;j++)
    {
       dp[j]=max(a[j]-dp[j-1],a[i]-dp[j]);
    }
 
    }
    cout<<(sum+dp[n-1])/2;
}