#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q, l;
ll arr[101010];
ll dp[30303];
ll cnt[30303];
ll chk[30303];

void solve() {
	cin >> n >> l >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
		chk[arr[i]] ++;
	}
	for (int i = n; i >= 1; i--) {
		cnt[i] = max(cnt[i + 1], cnt[i + l] + (chk[i] > 0));
	}
	/*for (int i = 1; i <= n; i++) {
		cout << cnt[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		cout << chk[i] << ' ';
	}
	cout << '\n';*/
	for (int i = 0; i <= n- l + 1; i++) dp[i] = 1e9;
	//dp[n] = 0;

	for (int i = n - l + 1; i >= 1; i--) {
		if (cnt[i] != cnt[i + l]) {
			if (chk[i]) {
				dp[i] = dp[i + l]; 
			}
			else {
				dp[i] = dp[i + 1];
			}
		}
		else {
			dp[i] = max(dp[i + l] + 1, dp[i+1]);
		}
	}

	ll ans = cnt[1] * 2 + min(m - cnt[1], dp[1]);
	cout << ans << '\n';

}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}