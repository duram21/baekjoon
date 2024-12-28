#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int cnt;
ll visited[100001];

void bfs(int x) {
	queue<ll>q;
	q.push(x);
	visited[x] = -1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		
		if (a + 1 <= 100000 && visited[a + 1] == 0) {
			visited[a + 1] = 1;
			q.push(a + 1);
		}
		if (a - 1 >= 0 && visited[a - 1] == 0) {
			visited[a - 1] = 2;
			q.push(a - 1);
		}
		if (a * 2 <= 100000 && visited[a * 2] == 0) {
			visited[a * 2] = 3;
			q.push(a * 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	bfs(n);
	vector<ll>ans;
	while (k != -1) {
		ans.push_back(k);
		if (visited[k] == 1) {
			k = k - 1;
		}
		else if (visited[k] == 2) {
			k = k + 1;
		}
		else if (visited[k] == 3) {
			k = k / 2;
		}
		else if (visited[k] == -1) {
			k = -1;
		}
	}
	cout << ans.size() - 1 << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
