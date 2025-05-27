#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
vector<pair<ll,ll>>edges[50505];
ll dist[50505];
ll dist2[50505];
priority_queue<pair<ll, ll>>pq;

void ds() {

	while (pq.size()) {
		d = -pq.top().first;
		ll cur = pq.top().second;
		pq.pop();

		if (d > dist[cur]) continue;
		dist[cur] = d;
		
		for (auto i : edges[cur]) {
			ll nxt = i.first;
			ll val = i.second;

			if (dist[nxt] <= d + val) continue;
			dist[nxt] = d + val;
			pq.push({ -(d + val), nxt });
		}
	}
}



void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a, c });
	}
	pq.push({ 0, n });

	for (int i = 1; i <= n + 10; i++) {
		dist[i] = 1e12;
	}
	ds();

	for (int i = 1; i <= n + 10; i++) {
		dist2[i] = dist[i];
	}
	for (int i = 1; i <= n + 10; i++) {
		dist[i] = 1e12;
	}

	while (k--) {
		cin >> a >> b;
		pq.push({-(dist2[a] - b), a });
		dist2[a] = dist2[a] - b;
	}
	ds();


	for (int i = 1; i < n; i++) {
		if (dist[i] <= dist2[i]) {
			cout << 1 << '\n';
		}
		else cout << 0 << '\n';
	}



	
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}