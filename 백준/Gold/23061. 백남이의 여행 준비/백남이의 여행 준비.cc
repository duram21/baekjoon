#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll dp[1010101];

void solve() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = 1000000; j >= 0; j--) {
			if (j + a > 1000000) continue;
			if (dp[j] == -1) continue;
			dp[j + a] = max(dp[j + a], dp[j] + b);
		}
		for (int j = 0; j <= 1000000; j++) {
			dp[j + 1] = max(dp[j + 1], dp[j]);
		}
	}
	float mx = -1;
	ll ans = -1;

	for(int i = 1; i <= m; i++){
		cin >> a;
		float rate = dp[a] / (float)a;
		if (rate > mx) {
			mx = rate;
			ans = i;
		}

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