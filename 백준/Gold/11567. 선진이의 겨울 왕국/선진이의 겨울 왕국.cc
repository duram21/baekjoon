#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
char arr[505][505];
string str;
ll dx[] = { -1, 0, 0, 1 };
ll dy[] = { 0, -1, 1, 0 };
bool visited[505][505];
ll ans = 0;
ll ax, ay, bx, by;

void bfs(ll x, ll y) {
	queue<pair<ll, ll>>q;
	q.push({ x, y });
	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (visited[x][y]) continue;
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (nx == bx && ny == by) {
				visited[nx][ny] = 1;
				if (arr[nx][ny] == 'X') {
					ans = 1;
					return;
				}
				else {
					for (int j = 0; j < 4; j++) {
						ll tx = nx + dx[j];
						ll ty = ny + dy[j];
						if (tx < 1 || ty < 1 || tx > n || ty > m) continue;

						if (!visited[tx][ty] && arr[tx][ty] == '.') {
							ans = 1;
							return;
						}
					}
				}
			}
			if (visited[nx][ny] || arr[nx][ny] == 'X')continue;
			q.push({ nx, ny });
		}
	}
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
		}
	}
	cin >> ax >> ay >> bx >> by;
	bfs(ax, ay);
	if (ans)cout << "YES\n";
	else cout << "NO\n";
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}