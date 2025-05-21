#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll arr[101010];
ll ans[101010];
ll chk[101010];

bool func(ll st, ll en) {
	ll l = st;
	ll r = en;
	for (int i = st; i <= en; i++) {
		if (ans[i]) {
			if (ans[i] > en || ans[i] < st) {
				return 1;
			}
			continue;
		}
		while (chk[r]) {
			r--;
		}
		chk[r] = 1;
		ans[i] = r;
	}
	return 0;
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	bool flag = 1;
	while (m--) {
		cin >> a >> b;
		ans[a] = b;
		chk[b] = 1;
	}

	ll st = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			bool ret = func(st, i);
			if (ret) {
				flag = 0;
				break;
			}
			st = i + 1;
		}
	}
	ll mx = 0;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, ans[i]);
		cnt++;
		if (arr[i]) {
			if (mx != i) flag = 0;
		}
		else {
			if (mx == i) flag = 0;
		}
	}
	if (ans[n] == 0) flag = 0;
	if (!flag) cout << -1 << '\n';
	else {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}