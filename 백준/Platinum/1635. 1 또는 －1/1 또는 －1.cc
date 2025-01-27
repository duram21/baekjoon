#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll arr[1001];
ll sum[1001];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
			sum[j] = arr[j] + sum[j - 1];
		}
		ll idx = -1;
		for (int j = 1; j <= n; j++) {
			ll fr = sum[j];
			ll bc = sum[n] - sum[j];
			if (fr == bc) {
				idx = j;
				break;
			}
		}
		for (int j = 1; j <= idx; j++) {
			cout << -1 << ' ';
		}
		for (int j = idx + 1; j <= n; j++) {
			cout << 1 << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}