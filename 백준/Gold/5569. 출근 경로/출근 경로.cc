#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
ll dp[101][101][2][2];
ll mod = 1e5;


void solve() {
	cin >> n >> m;
	// 0 - 1 |
	for (int i = 2; i <= m; i++) {
		dp[1][i][0][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][1][1][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j][0][0] = dp[i][j - 1][0][1] + dp[i][j-1][0][0];
			dp[i][j][0][1] = dp[i ][j-1][1][0];
			dp[i][j][1][0] = dp[i-1][j][1][1] + dp[i-1][j][1][0];
			dp[i][j][1][1] = dp[i - 1][j][0][0];
			dp[i][j][0][0] %= mod;
			dp[i][j][0][1] %= mod;
			dp[i][j][1][0] %= mod;
			dp[i][j][1][1] %= mod;
		}
	}
	ll ans = 0;

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			ans += dp[n][m][i][j];
		}
	}
	ans %= mod;
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}