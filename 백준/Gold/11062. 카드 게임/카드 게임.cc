#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;

ll arr[1010];
ll dp[1010][1010][2];

ll func(ll l, ll r, ll flag) {
	ll& ret = dp[l][r][flag];
	if (ret != -1) return ret;
	if (l == r) {
		if (!flag) {
			ret = arr[r];
		}
		else {
			ret = 0;
		}
		return ret;
	}
	ret = 0;
	if (!flag) {
		ret = max(arr[l] + func(l + 1, r, 1), arr[r] + func(l, r - 1, 1));
	}
	else {
		ret = min(func(l + 1, r, 0), func(l, r - 1, 0));
	}
	return ret;
}

void solve() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << func(1, n, 0) << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}