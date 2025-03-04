#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, g,  q, m;
char arr[30][30];
bool visited[30][30][30][30];
string str;
ll ans = 1e12;
ll dx[] = { -1, 1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };

struct p {
	ll x1;
	ll y1;
	ll x2;
	ll y2;
	ll move;
};

bool chk(ll x, ll y) {
	bool flag = 1;
	if (x == 0 || y == 0 || x == n + 1|| y == m + 1) flag = 0;
	return flag;
}

void bfs(ll x1, ll y1, ll x2, ll y2) {
	queue<p>q;
	q.push({ x1, y1, x2, y2, 0 });
	visited[x1][y1][x2][y2] = 1;

	while (q.size()) {
		x1 = q.front().x1;
		x2 = q.front().x2;
		y1 = q.front().y1;
		y2 = q.front().y2;
		ll move = q.front().move;
		q.pop();


		bool f1 = chk(x1, y1);
		bool f2 = chk(x2, y2);
		
		if (!f1 && !f2) continue;
		else if (! (f1 && f2)) {
			//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << move << '\n';
			ans = min(ans, move);
			continue;
		}
		for (int i = 0; i < 4; i++) {
				ll nx1 = x1 + dx[i];
				ll nx2 = x2 + dx[i];
				ll ny1 = y1 + dy[i];
				ll ny2 = y2 + dy[i];
				if (arr[nx1][ny1] == '#') {
					nx1 = x1;
					ny1 = y1;
				}
				if (arr[nx2][ny2] == '#') {
					nx2 = x2;
					ny2 = y2;
				}
				if (visited[nx1][ny1][nx2][ny2]) continue;
				visited[nx1][ny1][nx2][ny2] = 1;
				q.push({ nx1, ny1, nx2, ny2, move + 1 });
			
		}
	}
}


void solve() {
	cin >> n >> m;
	ll x1, x2, y1, y2;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
			if (arr[i][j] == 'o') {
				if (!flag) {
					flag = 1;
					x1 = i; y1 = j;
				}
				else {
					x2 = i; y2 = j;
				}
			}
		}
	}
	bfs(x1, y1, x2, y2);
	if (ans == 1e12) cout << -1 << '\n';
	else cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}