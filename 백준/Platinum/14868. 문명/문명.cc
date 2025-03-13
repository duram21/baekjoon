#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, m;
ll arr[2020][2020];
ll visited[2020][2020];
ll par[2020][2020];
ll cnt[2020][2020];
queue<pair<pair<ll,ll>, ll>>q;
ll dx[] = { -1,1 , 0, 0 };
ll dy[] = { 0, 0, 1, -1 };
ll ans = 1e12;

ll find(ll x, ll y) {
	if (par[x][y] == 10000 * x + y) return 10000 * x + y;
	return par[x][y] = find(par[x][y] / 10000, par[x][y] % 10000);
}

void bfs() {
	while (q.size()) {
		ll x = q.front().first.first;
		ll y = q.front().first.second;
		ll day = q.front().second;
		q.pop();
		ll mx = -1;
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
				mx = max(mx, min(visited[nx][ny], visited[x][y] + 1));
				par[pa / 10000][pa % 10000] = pb;
				cnt[pb / 10000][pb % 10000] += cnt[pa / 10000][pa % 10000];
				if (cnt[pb / 10000][pb % 10000] == k) {

					ans = min(ans, mx);
				}
				continue;
			}
			visited[nx][ny] = visited[x][y] + 1;
			par[nx][ny] = par[x][y];
			for (int j = 0; j < 4; j++) {
				ll tx = nx + dx[i];
				ll ty = ny + dy[i];

			}
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
	bfs();
	cout << ans - 1<< '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}