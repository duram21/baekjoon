#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;
int parent[100001][21];
int dep[100001];
ll psum[50505];
vector<int>tree[100001];
ll ans = 0;

void dfs(int node, int par) {
	dep[node] = dep[par] + 1;
	for (int nxt : tree[node]) {
		if (nxt == par) continue;
		parent[nxt][0] = node;
		dfs(nxt, node);
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[y] - dep[x] >= (1 << i)) y = parent[y][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

ll func(ll x, ll par) {
	ll cur = psum[x];
	for (int nxt : tree[x]) {
		if (nxt == par) continue;
		cur += func(nxt, x);
	}
	ans = max(ans, cur);
	return cur;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	while (m--) {
		cin >> a >> b;
		ll l = lca(a, b);
		psum[a]++;
		psum[b]++;
		psum[l]--;
		psum[parent[l][0]]--;
	}
	func(1, 0);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}