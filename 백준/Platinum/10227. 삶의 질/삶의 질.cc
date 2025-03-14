#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, m, h, w;
ll arr[3030][3030];
ll sum[3030][3030];
ll chk[3030][3030];

bool func(ll x) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] > x) chk[i][j] = 1;
			else if (arr[i][j] < x) chk[i][j] = -1;
			else chk[i][j] = 0;
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + chk[i][j];
		}
	}
	for (int i = h; i <= r; i++) {
		for (int j = w; j <= c; j++) {
			ll tot = sum[i][j] - sum[i - h][j] - sum[i][j - w] + sum[i - h][j - w];
			if (tot <= 0) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	cin >> r >> c >> h >> w;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
		}
	}

	ll L = 1;
	ll R = r * c;

	while (L <= R) {
		ll mid = (L + R) >> 1;
		if (func(mid)) {
			R = mid - 1;
		}
		else L = mid + 1;
		//cout << L << ' ' << R << '\n';
	}
	cout << L << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}