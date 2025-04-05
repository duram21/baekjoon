#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll dp[505][505];
ll px[505];
ll py[505];


void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> px[i] >> py[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 1e12;
		}
	}
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int h = 0; h <= j; h++) {
				if (j - h < 0) break;
				if (i - h - 1 < 0) break;
				dp[i][j] = min(dp[i][j], dp[i - h - 1][j - h] + abs(px[i] - px[i - h - 1]) + abs(py[i] - py[i - h - 1]));
			}
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j <= k; j++) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	cout << dp[n][k] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}