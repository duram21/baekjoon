#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s, a, b, c;
char arr[1010][1010];
ll dp[1010][1010];
ll ans = -1;
bool chk[1010][1010];
string str;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
			if (arr[i][j] == 'R') {
				chk[i][j] = 1;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (!chk[i][j]) continue;
			if (arr[i][j] == 'C') {
				dp[i][j]++;
			}
			if (arr[i][j] == 'O') {
				ans = max(ans, dp[i][j]);
			}
			if (i-1 >= 1 && arr[i-1][j+1] != '#') {
				chk[i - 1][j + 1] = 1;
				dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
			}
			if (arr[i][j + 1] != '#') {
				chk[i][j + 1] = 1;
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			}
			if (arr[i + 1][j + 1] != '#') {
				chk[i + 1][j + 1] = 1;
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			}
		}
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}