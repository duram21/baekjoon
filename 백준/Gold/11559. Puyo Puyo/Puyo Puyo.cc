#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
char arr[12][6];
ll dx[] = { -1, 1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };
bool visited[12][6];

bool bfs(ll x, ll y) {
	queue<pair<ll, ll>>q;
	char c = arr[x][y];
	visited[x][y] = 1;
	q.push({ x, y });
	ll cnt = 1;
	vector<pair<ll, ll>>v;
	v.push_back({ x, y });
	while (q.size()) {
		a = q.front().first;
		b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			ll nx = a + dx[i];
			ll ny = b + dy[i];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny] == c) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				v.push_back({ nx, ny });
				cnt++;
			}
		}
	}
	if (cnt >= 4) {

		for (auto p : v) {
			arr[p.first][p.second] = '.';
		}

		return true;
	}
	return false;
}

void solve() {
	string str;
	for (int i = 0; i < 12; i++) {
		cin >> str;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = str[j];
		}
	}
	ll ans = 0;
	while (true) {
		ll chk = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] || arr[i][j] == '.') continue;
				chk += bfs(i, j);
			}
		}
		if (!chk) break;
		ans++;
		for (int i = 0; i < 6; i++) {
			for (int j = 11; j >= 0; j--) {
				for (int k = j + 1; k <= 11; k++) {
					if (arr[k][i] != '.') break;
					arr[k][i] = arr[k - 1][i];
					arr[k - 1][i] = '.';
				}
			}
		}
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