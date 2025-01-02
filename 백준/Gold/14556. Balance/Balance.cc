#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc;
string str;
ll dp[50050];
ll mod = 1e9 + 9;
ll fact[50505];
ll p[50505];

void solve() {
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 2 * (i - 1) * dp[i - 1];
		dp[i] %= mod;
	}
	cout << dp[n] << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc = 1;
	while (tc--) {
		solve();
	}
}