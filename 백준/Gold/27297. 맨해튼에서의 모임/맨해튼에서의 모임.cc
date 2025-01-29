#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll arr[1010][1010];


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(arr[i] + 1, arr[i] + 1 + m);
	}
	ll ans = 0;

	ll idx = (m + 1) / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += abs(arr[i][j] - arr[i][idx]);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cout << arr[i][idx] << ' ';
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