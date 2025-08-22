#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, u, v;
int parent[100001][21];
int dep[100001];
vector<int>tree[100001];

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

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}