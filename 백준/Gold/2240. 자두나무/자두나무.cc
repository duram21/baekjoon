#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;
ll t;
ll arr[1010];
ll dp[1010][40][4];

void solve() {
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}
	if (arr[1] == 1) {
		dp[1][0][0] = 1;
	}
	else {
		dp[1][1][1] = 1;
	}
	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + (arr[i] == 1);
			dp[i][j][1] = dp[i - 1][j][1] + (arr[i] == 2);
			if (j >= 1) {
				dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + (arr[i] == 1));
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + (arr[i] == 2));
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= w; i++) {
		ans = max(ans, dp[t][i][0]);
		ans = max(ans, dp[t][i][1]);
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