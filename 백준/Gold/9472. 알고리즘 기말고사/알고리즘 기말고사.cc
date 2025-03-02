#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
ll dp[20][20];

void fact() {
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= 17; i++) {
		dp[i][0] = dp[i - 1][0] * i;
	}
}

ll func(ll a, ll b) {
	if (dp[a][b] > 0) return dp[a][b];
	ll& ret = dp[a][b];
	ret = func(a, b - 1) - func(a - 1, b - 1);
	return ret;
}

void solve() {
	cin >> a >> n >> k;
	cout << a << ' ' << func(n, k) << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	cin >> tc;
	fact();
	while (tc--) {
		solve();
	}
}