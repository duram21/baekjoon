#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll dp[5050];
ll mod = 1e9 + 7;

void solve() {
	cin >> n >> k;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 2; j++) {
			dp[i] += dp[j] * 2;
			dp[i] %= mod;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		ans += dp[i];
		ans %= mod;
	}
	ans += dp[n - k];
	for (int i = n - k; i <= n - 2; i++) {
		ans += dp[i];
		ans %= mod;
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