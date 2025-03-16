#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, m, h, w;
ll dp[202][202];
ll arr[202];

ll func(ll l, ll r) {
	if (l > r) return 0;
	ll& ret = dp[l][r];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = l + 1; i <= r - 1; i++) {
		ret = max(ret, arr[i] + arr[l] + arr[r] + func(l, i) + func(i, r));
	}
	return ret;
}

void solve() {
	while (true) {
		cin >> n;
		if (!n) break;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << func(1, n) << '\n';
	}

}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}