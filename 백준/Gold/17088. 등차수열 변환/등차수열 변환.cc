#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll arr[101010];
ll tmp[101010];
ll ans = 1e9;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int q = 1; q <= n; q++) {
				tmp[q] = arr[q];
			}
			ll cnt = 0;
			if (i) cnt++;
			if (j) cnt++;
			tmp[1] += i;
			tmp[2] += j;
			ll gap = tmp[2] - tmp[1];
			bool flag = 1;
			for (int k = 3; k <= n; k++) {
				if (tmp[k] - tmp[k - 1] == gap) continue;
				else if (tmp[k] - tmp[k - 1] == gap + 1) {
					cnt++;
					tmp[k]--;
				}
				else if (tmp[k] - tmp[k - 1] == gap - 1) {
					cnt++;
					tmp[k]++;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				ans = min(ans, cnt);
			}
		}
	}
	if (ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}