#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, aa, bb;
int a, b, c, mid;
int bridge = -1;
bool visited[10001];
vector<pair<int, int>>tree[100001];


bool bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == bb) return true;

		for (int i = 0; i < tree[x].size(); i++) {
			int nxt = tree[x][i].first;
			int val = tree[x][i].second;
			if (visited[nxt]) continue;
			if (mid <= val) {
				visited[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
		bridge = max(bridge, c);
	}
	cin >> aa >> bb;
	int l = 0;
	int r = bridge;
	int ans = 0;
	while (l <= r) {
		memset(visited, 0, sizeof(visited));
		mid = (l + r) / 2;
		bool res = bfs(aa);
		if (res) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
}