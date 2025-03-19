#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll n, a, b, c, d, l, r, k, g, m, h, w, t, p, s;
ll dp[101][101][2];
ll arr[101][101];
ll sum[101][101];
ll dist[101][101];

ll func(ll l, ll r, ll dir) {
	ll& ret = dp[l][r][dir];
	if (ret != -1) return ret;
	if (l == 1 && r == n) return 0;
	ret = 1e15;
	ll nxt;
	if (dir == 0) nxt = l;
	if (dir == 1) nxt = r;

	if (r < n) {
		ret = min(ret, func(l, r + 1, 1) + sum[nxt][r + 1] * (n - (r - l + 1)));
	}
	if (l > 1) {
		ret = min(ret, func(l - 1, r, 0) + sum[l - 1][nxt] * (n - (r - l + 1)));
	}
	return ret;
}

void solve() {
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i < n; i++) {
		cin >> sum[i][i + 1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + sum[j - 1][j];
		}
	}


	
	//for (int i = s; i >= 1; i--) {
	//	for (int j = s ; j <= n; j++) {
	//		dp[i][j][0] = min(dp[i + 1][j][1] + sum[i][j] * (n - (j - i)), dp[i + 1][j][0] + sum[i][i + 1] * (n - (j - i)));
	//		dp[i][j][1] = min(dp[i][j - 1][1] + sum[j - 1][j] * (n - (j - i)), dp[i][j - 1][0] + sum[i][j] * (n - (j - i)));
	//	}
	//}

	cout << min(func(s, s, 0), func(s, s, 1)) << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}