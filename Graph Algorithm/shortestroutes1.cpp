#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n,m;
vector<ar<int,2>>adj[MAX_N];
vector<ll>dist;

void dijk(int s){
    dist.assign(n+1,INF);
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>>pq;
    dist[s]=0;pq.push({0,s});
    while(pq.size()){
        auto[d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for (int  i = 0; i < m; i++)
    {
      int u,v,w;cin>>u>>v>>w;
      adj[u].push_back({v,w});
    }
    dijk(1);
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc=1;
    for(int t=1;t<=tc;t++){
        solve();
    }
}