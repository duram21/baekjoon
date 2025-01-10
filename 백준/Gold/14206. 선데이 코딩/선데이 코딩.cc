#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc, l, r, s;
ll dp[10101];
ll mod = 1e9 + 7;
ll fact[101];

void solve() {
	cin >> r >> s;
	fact[1] = 1;
	for (int i = 2; i <= r; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	dp[0] = 1;
	ll cur = 0;
	for (int i = 1; i <= r; i++) {
		ll sum = dp[i-1];
		for (int j = i; j <= (i - 1) * s + 1; j++) {
			ll tmp = dp[j];
			dp[j] = sum;
			dp[j] %= mod;
			sum += tmp;
		}
	}
	ll ans = 0;
	for (int i = r; i <= (r - 1) * s + 1; i++) {
		ans += dp[i];
		ans %= mod;
	}
	cout << ans * fact[r] % mod << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc = 1;
	while (tc--) {
		solve();
	}
}