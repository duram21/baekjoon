#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, m, h, w;
ll dp[101][101];
ll arr[101][101];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		arr[a][b] = 1;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j >= 1; j--) {
			for (int k = j; k < i; k++) {
				dp[j][i] = max(dp[j][i], arr[j][i] + dp[j][k] + dp[k][i]);
			}
		}
	}
	cout << dp[1][100] << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}