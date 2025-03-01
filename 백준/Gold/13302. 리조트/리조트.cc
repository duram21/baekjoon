#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
ll dp[101][121];
bool chk[101];


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		chk[a] = 1;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 110; j++) {
			dp[i][j] = 1e13;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 100; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 10000);
			if (chk[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (i >= 3) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i - 3][j] + 25000);
			}
			if (i >= 5) {
				dp[i][j + 2] = min(dp[i][j + 2], dp[i - 5][j] + 37000);
			}
			if (j >= 3) {
				dp[i][j - 3] = min(dp[i - 1][j], dp[i][j - 3]);
			}
		
		}
	}
	//for (int i = 0; i <= n; i++) {
	//	for (int j = 0; j <= 10; j++) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	ll ans = 1e12;
	for (int i = 0; i <= 100; i++) {
		ans = min(ans, dp[n][i]);
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