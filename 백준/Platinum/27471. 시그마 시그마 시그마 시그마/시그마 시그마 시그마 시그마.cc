#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll arr[202020];
ll tree[202020 * 4][2];
ll mod = 998244353;

void update(ll st, ll en, ll node, ll idx, ll val, ll k) {
	if (st == en && st == idx) {
		tree[node][k] = val;
		return;
	}
	if (st > idx || en < idx) return;
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, idx, val, k);
	update(mid + 1, en, node * 2 + 1, idx, val, k);
	tree[node][k] = tree[node * 2][k] + tree[node * 2 + 1][k];
	tree[node][k] %= mod;
}

ll sum(ll st, ll en, ll node, ll  l, ll r, ll k) {
	if (l <= st && en <= r) return tree[node][k];
	if (r < st || en < l) return 0;
	
	ll mid = (st + en) >> 1;
	return (sum(st, mid, node * 2, l, r, k) + sum(mid + 1, en, node * 2 + 1, l, r, k)) % mod;
}

void solve() {
	cin >> n;
	vector<pair<ll, ll>>v;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		v.push_back({ arr[i], i });
	}
	sort(all(v));
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		a = v[i-1].first;
		b = v[i-1].second;
		ans += (((sum(1, n, 1, 1, b, 0) % mod )* (n + 1 - b))% mod) * a % mod;
		ans += (((sum(1, n, 1, b, n, 1)) % mod) * (b) % mod) * a % mod;
		ans %= mod;
		update(1, n, 1, b, b, 0);
		update(1, n, 1, b, n + 1 - b, 1);

	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}