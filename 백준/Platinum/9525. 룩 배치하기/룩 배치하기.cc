#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s;
vector<ll>edges[10100];
string str;
char  arr[101][101];
ll A[10100];
ll B[10100];
ll AA[101][101];
ll BB[101][101];
bool visited[10100];

ll dfs(ll x) {
	visited[x] = 1;
	for (ll nxt : edges[x]) {
		if (B[nxt] == -1 || !visited[B[nxt]] && dfs(B[nxt])) {
			A[x] = nxt;
			B[nxt] = x;
			return true;
		}
	}
	return false;
}




void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = str[j - 1];
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 'X') continue;
			if (arr[i][j - 1] == '\0' || arr[i][j - 1] == 'X') {
				cur++;
			}
			AA[i][j] = cur;
		}
	}
	cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[j][i] == 'X') continue;
			if (arr[j-1][i] == '\0' || arr[j-1][i] == 'X') {
				cur++;
			}
			BB[j][i] = cur;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edges[BB[i][j]].push_back(AA[i][j]);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= 10050; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			dfs(i);
		}
	}
	for (int i = 1; i <= 10050; i++) {
		if (B[i] != -1) ans++;
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}