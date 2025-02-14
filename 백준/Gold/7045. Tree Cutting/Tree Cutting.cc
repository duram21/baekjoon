#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll sum[10101];
ll mx[10101];
vector<ll>edges[10101];

void dfs(ll x, ll par) {
	sum[x] = 1;
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
		mx[x] = max(sum[nxt], mx[x]);
		sum[x] += sum[nxt];
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, -1);
	vector<ll>ans;
	for (int i = 1; i <= n; i++) {
		if (max(mx[i], n - sum[i]) <= n / 2) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 0) {
		cout << "NONE\n";
	}
	else {
		for (ll cur : ans) {
			cout << cur << '\n';
		}
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