#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll tree[101010 * 4];
bool chk[101010];
ll arr[101010];

void update(ll st, ll en, ll node, ll idx, ll val) {
	if (idx < st || idx > en) {
		return;
	}
	if (st == en) {
		tree[node] += val;
		return;
	}
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, idx, val);
	update(mid + 1, en, node * 2 + 1, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll st, ll en, ll node, ll l, ll r) {
	if (r < st || en < l) return 0;
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	
	return sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	arr[n + 1] = 1e12;
	for (int i = n; i >= 1; i--) {
		if (arr[i] < arr[i + 1]) {
			chk[i] = 1;
			update(1, n, 1, arr[i], 1);
		}
		else break;
	}
	vector<ll>ans;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		update(1, n, 1, arr[i], 1);
		ll tot = sum(1, n, 1, 1, n);
		ll fr = sum(1, n, 1, 1, arr[i] - 1);
		ans.push_back(n - tot + fr);
	}
	cout << ans.size() << '\n';
	for (ll cur : ans) {
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