#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;
ll arr[1010];

ll func(ll x) {
	ll cnt = 0;
	ll cur = 0;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cur += arr[i];
		if (arr[i] > x) flag = 0;
		if (cur > x) {
			cnt++;
			cur = arr[i];
		}
	}
	cnt++;
	if (!flag) return false;
	if (cnt > m) return false;
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll l = 1;
	ll r = 100 * n;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (func(mid)) {
			r = mid;
		}
		else l = mid + 1;
	}
	ll cur = 0;
	ll cnt = 0;
	vector<ll>ans;
	for (int i = 1; i <= n; i++) {
		cur += arr[i];
		cnt++;
		if (cur > r) {
			ans.push_back(cnt - 1);
			cur = arr[i];
			cnt = 1;
		}
	}
	ans.push_back(cnt);
	ll idx = 0;
	while (ans.size() < m) {
		if (ans[idx] == 1) {
			idx++;
			continue;
		}
		ans[idx]--;
		ans.insert(ans.begin() + idx + 1, 1);
	}
	cout << r << '\n';
	for (auto cur : ans) {
		cout << cur << ' ';
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