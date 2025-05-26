#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, h, w, q, m;
ll dp[10101];
ll arr[10101];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		ll mx = -1;
		for (int j = i; j > i - k; j--) {
			if (!j) break;
			mx = max(mx, arr[j]);
			dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * mx);
		}

	}
	cout << dp[n] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}