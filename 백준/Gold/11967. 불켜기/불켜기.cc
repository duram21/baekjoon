#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;
set<pair<ll, ll>>s[101][101];
bool visited[101][101];
bool chk[101][101];
ll graph[101][101];
ll dx[] = { -1, 1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };
ll ans = 0;

void bfs(ll x, ll y) {
	visited[x][y] = 1;
	graph[x][y] = 1;
	queue<pair<ll, ll>>q;
	q.push({ x, y });
	while (q.size()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();
		//cout << a << ' ' << b << '\n';

		for (auto nxt : s[a][b]) {
			graph[nxt.first][nxt.second] = 1;
			c = nxt.first;
			d = nxt.second;
			if (!visited[c][d] && chk[c][d]) {
				visited[c][d] = 1;
				q.push({ c,d });
			}
		}

		for (int i = 0; i < 4; i++) {
			ll nx = a + dx[i];
			ll ny = b + dy[i];
			if (nx < 0 || ny < 0 || nx > n || ny > n) continue;
			if (visited[nx][ny]) continue;
			if (!graph[nx][ny]) {
				chk[nx][ny] = 1;
				continue;
			}

			chk[nx][ny] = 1;
			visited[nx][ny] = 1;
			q.push({ nx, ny });

		}
		

	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c >> d;
		s[a][b].insert({ c,d });
	}
	bfs(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j]) ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}