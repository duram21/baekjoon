#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r;
ll arr[101010];

ll func(ll x) {
	vector<ll>tmp;
	for (int i = 1; i <= x; i++) {
		tmp.push_back(arr[i]);
	}
	sort(tmp.begin(), tmp.end());
	bool flag = 1;
	ll cur = 0;
	for (int i = 0; i < x; i++) {
		if (cur + 1 >= tmp[i]) {
			cur += tmp[i];
		}
		else {
			break;
		}
	}
	if (cur >= k) {
		return true;
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll idx = 1;
	ll l = 1;
	ll r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (func(mid)) {
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (l == n + 1) cout << -1 << '\n';
	else  cout << l << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}