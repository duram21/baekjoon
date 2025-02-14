#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll X[1010];
ll L[1010];
char C[1010];
string str, bef;
ll mod = 1e9 + 9;

void solve() {
	cin >> n >> k;
	vector<ll>v;
	vector<ll>vv;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back(a);
		vv.push_back(a);
	}
	sort(vv.rbegin(), vv.rend());
	sort(v.begin(), v.end());
	ll ans = 0;
	ll bef = 0;
	ll vidx = 0;
	ll vvidx = 0;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			ans += vv[vvidx++] - bef;
		}
		else {
			bef = v[vidx++];
		}
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}