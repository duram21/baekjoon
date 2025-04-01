#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll arr[101010];
ll A[303030];
ll B[303030];

ll func(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		ll cur = 0;
		if (A[i] > B[i]) {
			ll tmp = (x + A[i] - 1) / A[i];
			cur = min(tmp, m) * A[i];
			cnt += min(tmp, m);
		}
		if (cur >= x) continue;
		ll rm = x - cur;
		ll tmp = (rm + B[i] - 1) / B[i];
		cnt += tmp;
	}
	if (cnt <= n * m) return true;
	return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		A[i] = max(A[i], B[i]);
	}
	ll l = 1;
	ll r = 2e18;
	auto check = [&](ll x) -> bool {
		ll day = 0;
		for (ll i = 1; i <= n; i++) {
			if (x <= A[i] * m) day += (x + A[i] - 1) / A[i];
			else day += m + (x - A[i] * m + B[i] - 1) / B[i];
			if (day > n * m) return 0;
		}
		return 1;
	};
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << r << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}