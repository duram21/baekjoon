#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m;
ll arr[202020];
vector<ll>tree[202020 * 4];
vector<ll>edges[202020];
ll in[202020];
ll out[202020];
ll cnt = 0;
ll mod = 1e9 + 7;

void dfs(ll x, ll par) {
	in[x] = ++cnt;
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
	}
	out[x] = cnt;
}

void update(ll st, ll en, ll node, ll idx, ll val) {
	if (st > idx || en < idx) return;
	tree[node].push_back(val);
	if (st != en) {
		ll mid = (st + en) >> 1;
		update(st, mid, node * 2, idx, val);
		update(mid + 1, en, node * 2 + 1, idx, val);
	}
}

ll search(ll st, ll en, ll node, ll l, ll r, ll val) {
	if (en < l || r < st) return 0;
	if (l <= st && en <= r) {
		return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
	}
	ll mid = (st + en) >> 1;
	return search(st, mid, node * 2, l, r, val) + search(mid + 1, en, node * 2 + 1, l, r, val);
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q >> c;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		update(1, n, 1, in[i], arr[i]);
	}
	for (int i = 1; i <= n * 4; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
	ll ans = 0;
	while (q--) {
		cin >> a >> b;
		ans += search(1, n, 1, in[a], out[a], b);
		ans %= mod;
	}
	cout << ans << '\n';
}