#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, d, k, m, x, q, l;
ll mod = 998244353;
ll dp[2][26];

void solve() {
	cin >> n;
	char c;
	bool cur = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c >> a;
		ll sum = 0;
		bool nxt = !cur;
		for (int j = 0; j < 26; j++) {
			sum += dp[cur][j];
			sum %= mod;
		}
		for (int j = 0; j < 26; j++) {
			if (c - 'a' == j) {
				dp[nxt][j] = mod + (sum + 1) * a - (dp[cur][j] * (a - 1) % mod);
				dp[nxt][j] %= mod;
			}
			else {
				dp[nxt][j] = dp[cur][j];
				dp[nxt][j] %= mod;
			}
		}
		cur = nxt;
	}
	//cur = !cur;
	ll sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += dp[cur][i];
		sum %= mod;
	}
	cout << sum << '\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}