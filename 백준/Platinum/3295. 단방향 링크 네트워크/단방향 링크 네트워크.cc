#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc, l, r, s;
vector<ll>edges[1010];
ll A[1010];
ll B[1010];
bool visited[1010];

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
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
	}
	for (int i = 0; i <= n; i++) {
		A[i] = -1; B[i] = -1;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == -1) {
			fill(visited, visited + n, 0);
			if ((dfs(i))) ans++;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i <= n; i++) {
		edges[i].clear();
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}