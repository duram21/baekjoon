#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s, a, b;
vector<ll>edges[202020];
ll color[202020];
ll dp[202020][5];
ll mod = 1e9 + 7;

void dfs(ll x, ll par) {
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
	}
	if (color[x]) {
		dp[x][color[x]] = 1;
	}
	else {
		dp[x][1] = 1;
		dp[x][2] = 1;
		dp[x][3] = 1;
	}
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		for (int i = 1; i <= 3; i++) {
			ll sum = 0;
			for (int j = 1; j <= 3; j++) {
				if (i == j) continue;
				sum += dp[nxt][j];
				sum %= mod;
			}
			dp[x][i] *= sum;
			dp[x][i] %= mod;
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		color[a] = b;
	}
	dfs(1, -1);
	cout << (dp[1][1] + dp[1][2] + dp[1][3]) % mod << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}