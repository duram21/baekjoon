#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r;
ll dp[101][101][101];
ll mod = 1000000007;

ll func(ll N, ll L, ll R) {
	if (L == 0 || R == 0 || N == 0 || L + R > N + 1) return 0;
	ll& ret = dp[N][L][R];
	if (ret != -1) return ret;
	ret = func(N - 1, L - 1, R) + func(N - 1, L, R - 1) + func(N - 1, L, R) * (N - 2);
	ret %= mod;
	return ret;
}


void solve() {
	cin >> n >> l >> r;
	memset(dp, -1, sizeof(dp));
	dp[1][1][1] = 1;
	cout << func(n, l, r) << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	while (tc--) {
		solve();
	}
}