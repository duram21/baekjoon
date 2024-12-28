#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
string str;
char arr[1010][1010];
ll visited[1010][1010];
ll mv[1010][1010];
ll dx[] = { -1, 1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };
queue<pair<ll, ll>>q;

void bfs() {
	while (q.size()) {
		ll a = q.front().first;
		ll b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ll nx = a + dx[i];
			ll ny = b + dy[i];
			if (visited[nx][ny] != 1e9) continue;
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (arr[nx][ny] != '#') {
				visited[nx][ny] = visited[a][b] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

ll solve(ll x, ll y) {
	queue<pair<ll, ll>>q;
	q.push({ x, y });
	mv[x][y] = 0;
	while (q.size()) {
		ll a = q.front().first;
		ll b = q.front().second;
		q.pop();

		if (a == 1 || b == 1 || a == n || b == m) {
			return mv[a][b];
		}
		for (int i = 0; i < 4; i++) {
			ll nx = a + dx[i];
			ll ny = b + dy[i];
			if (mv[nx][ny] != -1) continue;
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (arr[nx][ny] != '#' && visited[nx][ny] > mv[a][b] + 1) {
				mv[nx][ny] = mv[a][b] + 1;
				q.push({ nx, ny });

			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	ll fx = -1;
	ll fy = -1;
	ll jx = -1;
	ll jy = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = 1e9;
		}
	}
	memset(mv, -1, sizeof(mv));
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
			if (str[j - 1] == 'F') {
				fx = i;
				fy = j;
				q.push({ fx, fy });
				visited[fx][fy] = 0;
			}
			if (str[j - 1] == 'J') {
				jx = i;
				jy = j;
			}
		}
	}
	bfs();
	ll ans = solve(jx, jy);
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans + 1 << '\n';
}
