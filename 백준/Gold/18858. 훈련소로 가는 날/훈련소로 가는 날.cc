#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
ll mod = 998244353;
ll dp[1010][110][3];


void solve() {
	cin >> n >> m;
	if (n == 1) {
		cout << m << '\n';
		return;
	}
	if (n == 2) {
		cout << m * m << '\n';
		return;
	}
	for (int i = 1; i <= m; i++) {
		dp[2][i][0] = m - i;
		dp[2][i][2] = 1;
		dp[2][i][1] = i - 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = j + 1; k <= m; k++) {
				dp[i][j][0] += dp[i - 1][k][0] +  dp[i - 1][k][2];
				dp[i][j][0] %= mod;
			}
			for (int k = 1; k < j; k++) {
				dp[i][j][1] += dp[i - 1][k][0] + dp[i - 1][k][1] + dp[i - 1][k][2];
				dp[i][j][1] %= mod;
			}
			dp[i][j][2] += dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2];
			dp[i][j][2] %= mod;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += dp[n][i][0] + dp[n][i][1] + dp[n][i][2];
		ans %= mod;
	}
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