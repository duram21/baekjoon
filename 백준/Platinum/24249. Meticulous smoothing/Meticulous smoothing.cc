#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t;
ll arr[1010101];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] > arr[i]) continue;
		if (arr[i - 1] + 1 < arr[i]) {
			ans += arr[i] - (arr[i - 1] + 1);
			arr[i] = arr[i - 1] + 1;
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (arr[i + 1] > arr[i]) continue;
		if (arr[i + 1] + 1 < arr[i]) {
			ans += arr[i] - (arr[i + 1] + 1);
			arr[i] = arr[i + 1] + 1;
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