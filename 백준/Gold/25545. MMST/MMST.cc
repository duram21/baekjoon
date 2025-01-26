#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
vector<pair<pair<ll,ll>, pair<ll,ll>>>edges;
ll par[202020];
bool chk[505050];

ll find(ll x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({ {c, i}, {a, b} });
	}
	for (int i = 1; i <= n; i++) par[i] = i;
	sort(edges.begin(), edges.end());
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		c = edges[i].first.second;
		a = edges[i].second.first;
		b = edges[i].second.second;
		ll A = find(a);
		ll B = find(b);
		if (A == B) continue;
		par[A] = B;
		cnt++;
		chk[c] = 1;
		if (cnt == n - 1) break;
	}
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
			a = edges[i].second.first;
			b = edges[i].second.second;
			c = edges[i].first.second;
		if (!chk[c]) {
			ll A = find(a);
			ll B = find(b);
			par[A] = B;
			for (int j = 0; j < m; j++) chk[j] = 0;
			chk[c] = 1;
			break;
		}
	}
	cnt = 0;
	for (int i = 0; i < m; i++) {
		c = edges[i].first.second;
		a = edges[i].second.first;
		b = edges[i].second.second;
		ll A = find(a);
		ll B = find(b);
		if (A == B) continue;
		par[A] = B;
		cnt++;
		chk[c] = 1;
		if (cnt == n - 1) break;
	}
	if (m == n - 1) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		for (int i = 0; i < m; i++) {
			if (chk[i]) {
				cout << i + 1 << ' ';
			}
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