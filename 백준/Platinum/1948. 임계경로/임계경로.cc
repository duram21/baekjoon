#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m;
ll dist[10101];
ll deg[10101];
vector<pair<ll,ll>> edges[10101];
vector<pair<ll, ll>> ed[10101];


void bfs(ll x) {
	queue<ll>q;
	q.push(x);
	while (q.size()) {
		a = q.front();
		q.pop();

		for (auto nxt : edges[a]) {
			ll node = nxt.first;
			d = nxt.second;
			deg[node]--;
			dist[node] = max(dist[node], dist[a] + d);
			if (!deg[node]) q.push(node);
		}
	}
}

ll ans = 0;
bool visited[10101];

void f(ll x) {
	queue<ll>q;
	q.push(x);
	visited[x] = 1;
	while (q.size()) {
		a = q.front();
		q.pop();
		
		for (auto nxt : ed[a]) {
			ll node = nxt.first;
			d = nxt.second;

			if (dist[a] - d == dist[node]) {
				if (visited[node] == 1) {
					ans++;
					//cout << x << ' ' << node << '\n';
					continue;
				}
				//cout << x << ' ' << node << '\n';

				ans++;
				visited[node] = 1;
				q.push(node);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		ed[b].push_back({ a,c });
		deg[b]++;
	}
	ll st, en;
	cin >> st >> en;
	bfs(st);
	cout << dist[en] << '\n';
	f(en);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}