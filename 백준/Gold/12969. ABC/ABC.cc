#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
int dp[31][31][31][500];
char ans[33];

bool func(ll idx, ll A, ll B, ll val) {
	if (idx == n + 1) {
		if (val == k) return true;
		return false;
	}

	int& ret = dp[idx][A][B][val];
	if (ret != -1) return ret;
	ret = 0;
	// C
	if (val + A + B <= k) {
		ans[idx] = 'C';
		if (func(idx + 1, A, B, val + A + B)) {
			ret = 1;
			return ret;
		}
	}
	if (val + A <= k) {
		ans[idx] = 'B';
		if (func(idx + 1, A, B + 1, val + A)) {
			ret = 1;
			return true;
		}
	}
	if (val <= k) {
		ans[idx] = 'A';
		if (func(idx + 1, A + 1, B, val)) {
			ret = 1;
			return true;
		}
	}
	return false;
}




void solve() {
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	if (func(1, 0, 0, 0)) {
		for (int i = 1; i <= n; i++) {
			cout << ans[i];
		}
		cout << '\n';
	}
	else cout << "-1\n";
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}