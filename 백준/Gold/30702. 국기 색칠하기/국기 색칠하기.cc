#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll chk[55];
char A[55][55];
char B[55][55];
bool visited[55][55];
ll dx[] = { -1, 1, 0 ,0 };
ll dy[] = { 0, 0, -1, 1 };
set<char>s;


void bfs(ll x, ll y) {
	visited[x][y] = 1;
	queue<pair<ll, ll>>q;
	q.push({ x, y });
	s.insert(B[x][y]);
	while (q.size()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ll nx = a + dx[i];
			ll ny = b + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (visited[nx][ny]) continue;
			
			if (A[nx][ny] == A[x][y]) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				s.insert(B[nx][ny]);
			}
		}
	}
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			A[i][j] = str[j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			B[i][j] = str[j - 1];
		}
	}
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				s.clear();
				bfs(i, j);
				if (s.size() >= 2) {
					flag = 0;
				}
			}
		}
	}

	if (flag) cout << "YES\n";
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