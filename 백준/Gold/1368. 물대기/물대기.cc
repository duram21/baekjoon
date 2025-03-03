#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m, q;
ll par[303];
ll val[303];
ll graph[303][303];
ll mn[303];
ll bridge[303];
ll sum[303];

ll find(ll x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	vector<pair<ll, pair<ll, ll>>>v;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
		v.push_back({ val[i], {i, 0} });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (i < j) {
				v.push_back({ a, {i, j} });
			}
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (auto nxt : v) {
		c = nxt.first;
		a = nxt.second.first;
		b = nxt.second.second;

		ll A = find(a);
		ll B = find(b);
		if (A == B) continue;
		ans += c;
		par[A] = B;
	}

	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}