#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, m;
ll arr[2020][2020];
ll visited[2020][2020];
ll par[2020][2020];
ll cnt[2020][2020];
queue<pair<pair<ll, ll>, ll>>q;
ll dx[] = { -1,1 , 0, 0 };
ll dy[] = { 0, 0, 1, -1 };
ll ans = 1e12;

ll find(ll x, ll y) {
	if (par[x][y] == 10000 * x + y) return 10000 * x + y;
	return par[x][y] = find(par[x][y] / 10000, par[x][y] % 10000);
}

void bfs() {
	ll mx = -1;
	ll d = -1;
	bool flag = 1;
	queue<pair<pair<ll, ll>, ll>>tq;
	while (q.size()) {
		ll x = q.front().first.first;
		ll y = q.front().first.second;
		ll day = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

			if (visited[nx][ny]) {
				ll tx = x;
				ll ty = y;

				ll pa = find(nx, ny);
				ll pb = find(tx, ty);
				if (pa == pb) continue;
				par[pa / 10000][pa % 10000] = pb;
				k--;
			}
		}
		tq.push({ {x, y}, day });
	}
	if (k == 1) return;
	while (tq.size()) {
		ll x = tq.front().first.first;
		ll y = tq.front().first.second;
		ll day = tq.front().second;
		tq.pop();
		for (int i = 0; i < 4; i++) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = visited[x][y] + 1;
			ll val = find(x, y);
			par[nx][ny] = find(x, y);
			q.push({ {nx, ny}, day + 1 });
		}
	}
}


void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = 10000 * i + j;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
		cnt[a][b] = 1;
		q.push({ {a, b}, 0 });
	}
	ll ans = 0;
	while (1) {
		bfs();
		if (k == 1) {
			break;
		}
		ans++;
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