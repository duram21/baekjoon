#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;
ll arr[262626];
ll dp[70][262626];


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= 65; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == arr[j]) dp[i][j] = j + 1;
			else if (dp[i - 1][j] && dp[i - 1][dp[i - 1][j]]) {
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
			}
		}
	}
	for (int i = 65; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j]) {
				cout << i << '\n';
				return;
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}