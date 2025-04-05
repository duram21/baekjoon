#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll par[10101];
ll dist[10101];
ll visited[10101];


void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e12;
	}
	dist[1] = 0;
	vector<ll>v;
	for (int i = 1; i <= n; i++) {
		ll nxt = -1;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && (nxt == -1 || dist[j] < dist[nxt])) {
				nxt = j;
			}
		}
		visited[nxt] = 1;
		v.push_back(dist[nxt]);

		for (ll j = 1; j <= n; j++) {
			if (!visited[j]) {
				d = (2019201913 * min(nxt, j) + 2019201949 * max(nxt, j)) % 2019201997;
				if (d < dist[j]) {
					dist[j] = d;
				}
			}
		}
	}
	sort(all(v));

	cout << v[n-k + 1] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}