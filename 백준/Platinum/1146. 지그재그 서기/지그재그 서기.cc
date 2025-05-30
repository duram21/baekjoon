#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, x, y;
ll dp[101][101];
ll mod = 1e6;

ll func(ll l, ll r) {
	if (l + r == 0) return 1;

	ll& ret = dp[l][r];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 1; i <= r; i++) {
		ret += func(r  - i, l + i - 1);
		ret %= mod;
	}
	return ret;
}

void solve() {
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += func(i - 1, n - i);
		ans += func(n - i, i - 1);

		ans %= mod;
	}
	cout << ans << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}