#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ook order_of_key
#define fbo find_by_order
const int MOD=1000000007; //998244353
ll n,t;
ll k[200005];
ll func(ll m)
{
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=m/k[i];
        if(ans>t)
        {
            return LLONG_MAX;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    ll l=0,h=1e18;
    while(h>l)
    {
        ll m=(l+h)/2;
        if(func(m)<t)
        {
            l=m+1;
        }
        else
        {
            h=m;
        }
    }
    cout<<l;
}