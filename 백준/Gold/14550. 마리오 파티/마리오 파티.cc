#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t;
ll arr[202];
ll dp[202][202];


void solve() {
	while (true) {
		cin >> n;
		if (!n) break;
		cin >> s >> t;
		arr[n + 1] = 0;
		for (int i = 0; i <= n + 1; i++) {
			arr[i] = 0;
			for (int j = 0; j <= t; j++) {
				dp[i][j] = -1e9;
			}
		}
		for (int i = 1; i <= n; i++)cin >> arr[i];
		dp[0][0] = 0;
		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= t; j++) {
				for (int k = 1; k <= s; k++) {
					if (i - k >= 0) {
						if (dp[i - k][j - 1] == -1e9) continue;

							dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + arr[i]);

					}
				}
			}
		}
		ll ans = -1e9;

		for (int i = 0; i <= t; i++) {
			ans = max(ans, dp[n + 1][i]);
		}
		cout << ans << '\n';
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}