#include<bits/stdc++.h>
using namespace std;

using namespace std;
using ll=long long;
using ld=long double;

ll n,k;
vector<ll>a;
void solve() {
	cin >> n >> k;
	a.resize(k);
	for (auto &x : a) cin >> x;
	ll ans=0;
	for (int msk=1; msk<(1<<k); ++msk) {
		bool cnt=0; ll cur=1;
		for (int i=0; i<k; ++i) {
			if ((msk>>i)&1) {
				cur=(a[i]>ld(n)/cur?-1:cur*a[i]);
				cnt=!cnt;
			}
		}
		if (cur==-1) continue;
		if (cnt) ans+=n/cur;
		else ans-=n/cur;
	}
	cout << ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int tc=1;
	for (int t=0; t<tc; t++) {
		solve();
		cout << "\n";
	}
} 