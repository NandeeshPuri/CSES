#include<bits/stdc++.h>
using namespace std;
 
 
 
int main () {
     int n , x;
     cin>> n >> x;
     vector<int > v(n);
     for(int i = 0; i<n; i++) cin >> v[i];
     map<int , pair<int ,int >> m;
     for(int i = 0; i<n; i++)
     {
         for(int j = i+1; j<n; j++)
 
             if(m.count(x-v[i]-v[j]))
             {
                 cout << i+1 << " " << j+1 << " "
                 << m[x-v[i]-v[j]].first+1<<" "
                 << m[x-v[i]-v[j]].second+1;
                 return 0;
             }
                 for(int k = 0; k<i; k++)
                     m[v[i]+v[k]] = {i,k};
 
     }
               cout << "IMPOSSIBLE" << endl;
}