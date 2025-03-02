#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m;
ll arr[30][30];

pair<ll, ll>st[404];
pair<ll, ll>en[404];
bool chk[404];
ll dist[404];
ll visited[30][30];
ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

void bfs(ll x, ll y) {
	queue<pair<ll, ll>>q;
	visited[x][y] = 0;
	q.push({ x, y });
	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i ++) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny >  n) continue;
			if (visited[nx][ny] != -1) continue;
			if (arr[nx][ny]) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

void solve() {
	cin >> n >> m >> g;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	ll cx, cy;
	cin >> cx >> cy;
	for (int i = 1; i <= m; i++) {
		cin >> st[i].first >> st[i].second >> en[i].first >> en[i].second;
		memset(visited, -1, sizeof(visited));
		bfs(st[i].first, st[i].second);
		dist[i] = visited[en[i].first][en[i].second];
		if (dist[i] == -1) {
			cout << -1 << '\n';
			return;
		}
	}

	for (int q = 1; q <= m; q++) {
		memset(visited, -1, sizeof(visited));
		bfs(cx, cy);
		priority_queue < pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>pq;
		for (int i = 1; i <= m; i++) {
			if (chk[i]) continue;
			if (visited[st[i].first][st[i].second] == -1)continue;
			pq.push({ visited[st[i].first][st[i].second] , {st[i].first, st[i].second} });
		}
		if (pq.size() == 0) {
			cout << -1 << '\n';
			return;
		}
		cx = pq.top().second.first;
		cy = pq.top().second.second;
		g -= pq.top().first;
		if (g < 0) {
			cout << -1 << '\n';
			return;
		}
		ll idx = 0;
		for (int i = 1; i <= m; i++) {
			if (chk[i]) continue;
			if (st[i].first == cx && st[i].second == cy) {
				idx = i;
				break;
			}
		}
		chk[idx] = 1;
		g =  g - dist[idx];
		if (g < 0) {
			cout << -1 << '\n';
			return;
		}
		cx = en[idx].first;
		cy = en[idx].second;
		g += dist[idx] * 2;
	}
	cout << g << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}