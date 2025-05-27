#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
ll arr[101010];

bool func(ll x) {
	ll cnt = 0;

	ll len = 0;
	ll mn = arr[1];

	for (int i = 1; i <= n; i++) {
		if (arr[i] - mn > x) {
			cnt++;
			len = 1;
			mn = arr[i];
		}
		else {
			len++;
			if (len == c) {
				cnt++;
				mn = arr[i + 1];
				len = 0;
			}
		}
	}
	if (len) cnt++;
	if (cnt <= m) return true;
	return false;
}

void solve() {
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);


	ll l = 0;
	ll r = 1e12;

	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (func(mid)) {
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << l << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}