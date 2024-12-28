#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
string str;
ll visited[505050][2];
queue<pair<ll, ll>>q;

void bfs(ll x) {
	queue<pair<ll,ll>>q;
	visited[x][0] = 0;
	q.push({ x, 0 });
	while (q.size()) {
		ll a = q.front().first;
		ll mv = q.front().second;
		q.pop();
		ll nmv = (mv + 1) % 2;
		if (a + 1 <= 500000 && visited[a + 1][nmv] == -1) {
			visited[a + 1][nmv] = mv + 1;
			q.push({ a + 1, mv + 1 });
		}
		if (a - 1 >= 0 && visited[a - 1][nmv] == -1) {
			visited[a - 1][nmv] = mv + 1;
			q.push({ a - 1, mv + 1 });
		}
		if (a * 2 <= 500000 && visited[a * 2][nmv] == -1) {
			visited[a * 2][nmv] = mv + 1;
			q.push({ a * 2, mv + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(visited, -1, sizeof(visited));
	bfs(n);
	
	ll cur = m;
	ll mn = 0;
	ll ans = 0;
	for (int i = 0; i < 500000; i++) {
		ll pos = cur + i * (i + 1) / 2;
		if (pos > 500000) break;
		if (visited[pos][i % 2] != -1 && visited[pos][i % 2] <= i) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}
