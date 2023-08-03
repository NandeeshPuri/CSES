#include "bits/stdc++.h"
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
    vector<array<int, 3>> v(n);
    int ans1[n] = {0}, ans2[n] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> v[i][1] >> v[i][0]; v[i][1] *= -1;
        v[i][2] = i;
    }
    sort(begin(v), end(v));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (mx >= -v[i][1]) ans1[v[i][2]] = 1;
        mx = max(mx, -v[i][1]);
    }
    mx = 2e9;
    for (int i = n-1; i >= 0; --i) {
        if (mx <= -v[i][1]) ans2[v[i][2]] = 1;
        mx = min(mx, -v[i][1]);
    }
    for (int i = 0; i < n; ++i)
        cout << ans1[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
        cout << ans2[i] << ' ';
}