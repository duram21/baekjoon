#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;
ll dp[1010][1010];

void solve() {
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) {
		dp[i + 1][0] = i + 1;
	}
	for (int i = 0; i < t.length(); i++) {
		dp[0][i + 1] = i + 1;
	}
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j <= t.length(); j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
			}
		}
	}
	cout << dp[s.length()][t.length()] << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}