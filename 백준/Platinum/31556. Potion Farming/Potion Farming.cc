#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;
ll arr[101010];
vector<ll>edges[101010];
ll cnt[101010];
ll node[101010];

void dfs(ll x, ll par) {
	if (edges[x].size() == 1 && x != 1) {
		cnt[x] = 1;
		return;
	}
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
		cnt[x] += cnt[nxt];
	}
}

ll func(ll x, ll par) {
	ll sum = 0;
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		sum += func(nxt, x);
	}
	sum += node[x];
	return min(sum, cnt[x]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, 0);
	ll ans = 0;
	for (int i = 1; i <= cnt[1]; i++) {
		node[arr[i]]++;
	}
	cout << func(1, 0) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}