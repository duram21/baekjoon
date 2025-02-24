#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c,  m2, tc, d, k, l, r, x, w, sqrtn;
double m , p;

ll arr[1010];
ll C[5050];
ll P[5050];
ll dp[10101];

void solve() {
	while (true) {
		cin >> n >> m;
		if (!n && !m) return;
		ll M = m * 100 + 0.5;
		for (int i = 1; i <= n; i++) {
			cin >> c >> p;
			C[i] = c;
			P[i] = p * 100 + 0.5;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= M; j++) {
				if (j + P[i] > M) break;
				dp[j + P[i]] = max(dp[j + P[i]], dp[j] + C[i]);
			}
		}
		ll ans = 0;
		for (int i = 0; i <= M; i++) {
			ans = max(ans, dp[i]);
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