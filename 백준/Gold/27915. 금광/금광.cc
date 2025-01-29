#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
vector<ll>edges[101010];
ll ans = 0;
bool chk[101010];

void dfs(ll x, ll dist) {
	if (dist % 2 == 0) ans++;
	for (ll nxt : edges[x]) {
		dfs(nxt, dist + 1);
	}
}


void solve() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		edges[a].push_back(i);
	}
	dfs(1, 0);
	cout << max(ans, n - ans) << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}