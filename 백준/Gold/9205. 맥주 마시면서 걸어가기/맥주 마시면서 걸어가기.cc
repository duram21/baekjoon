#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m, q;
bool visited[150];
ll px[150];
ll py[150];

void bfs() {
	queue<ll>q;
	q.push(1);
	visited[1] = 1;
	while (q.size()) {
		a = q.front();
		q.pop();

		for (int i = 1; i <= n + 2; i++) {
			if (visited[i]) continue;
			ll dist = abs(px[i] - px[a]) + abs(py[i] - py[a]);
			if (dist <= 1000) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n + 2; i++) {
		cin >> px[i];
		cin >> py[i];
	}
	memset(visited, 0, sizeof(visited));
	bfs();
	if (visited[n + 2]) cout << "happy\n";
	else cout << "sad\n";
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}