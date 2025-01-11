#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s, a, b;
vector<ll>edges[10100];
ll arr[301][301];
ll A[500];
ll B[500];
bool visited[500];

ll dfs(ll x) {
	visited[x] = 1;
	for (ll nxt : edges[x]) {
		if (B[nxt] == -1 || !visited[B[nxt]] && dfs(B[nxt])) {
			A[x] = nxt;
			B[nxt] = x;
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> m >> k;

	while (k--) {
		cin >> a >> b;
		arr[a][b] = -1;
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == -1) continue;
			edges[i].push_back(j);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= 300; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			dfs(i);
		}
	}
	for (int i = 1; i <= 300; i++) {
		if (B[i] != -1) ans++;
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}