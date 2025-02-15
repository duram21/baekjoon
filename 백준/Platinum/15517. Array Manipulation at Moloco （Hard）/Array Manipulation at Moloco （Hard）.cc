#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, l, r, x, s, t, w;
ll tree[1010010 * 4];
ll arr[1010100];

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
	map<ll, ll>m;
	vector<pair<ll, ll>>v;
	ll idx = 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		v.push_back({ arr[i] , i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (m.find(v[i].first) == m.end())
			m[v[i].first] = idx++;
		arr[v[i].second] = m[v[i].first];
	}
	idx--;

	for (int i = 1; i <= n; i++) {
		update(1, n, 1, arr[i], 1);
		cout << sum(1, n, 1, 1, arr[i] - 1) << '\n';
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