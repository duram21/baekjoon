#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, g,  q, m;
vector<pair<ll, ll>>edges[202020];
vector<pair<ll, ll>>tree[202020];
ll gazi = 0;
ll glen = 0;
ll tlen = 0;

void dfs(ll x, ll par, ll val) {
	if (edges[x].size() >= 3 && gazi == 0) {
		gazi = x;
		glen = val;
	}
	for (auto nxt : edges[x]) {
		a = nxt.first;
		b = nxt.second;
		if (a == par) continue;
		tree[x].push_back({ a, b });
		dfs(a, x, val + b);
	}
}

void dfs2(ll x, ll par, ll val) {
	tlen = max(tlen, val);

	for (auto nxt : tree[x]) {
		a = nxt.first;
		b = nxt.second;
		dfs2(a, x, val + b);
	}
}

void solve() {
	cin >> n >> r;
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
		sum += c;
	}
	dfs(r, -1, 0);
	if (edges[r].size() >= 2) {
		gazi = r;
		glen = 0;
	}
	
	if (gazi == 0) {
		cout << sum << ' ' << tlen << '\n';
		return;
	}
	dfs2(gazi, -1, 0);
	cout << glen << ' ' << tlen << '\n';

}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}