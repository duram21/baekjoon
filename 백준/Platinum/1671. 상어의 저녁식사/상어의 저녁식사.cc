#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s;
vector<ll>edges[1010];
ll A[1010];
ll B[1010];
ll a[55];
ll b[55];
ll c[55];
bool visited[1010];

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
		cin >> a[i] >> b[i] >> c[i];
		for (int j = 1; j < i; j++) {
			if (a[j] == a[i] && b[j] == b[i] && c[j] == c[i]) {
				edges[j].push_back(i);
			}
			else if (a[j] <= a[i] && b[j] <= b[i] && c[j] <= c[i]) {
				edges[i].push_back(j);
			}
			else if (a[j] >= a[i] && b[j] >= b[i] && c[j] >= c[i]) {
				edges[j].push_back(i);
			}
		}

	}

	for (int i = 0; i <= n; i++) {
		A[i] = -1; B[i] = -1;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(visited, 0, sizeof(visited));
			dfs(i);
			memset(visited, 0, sizeof(visited));
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (B[i] == -1) ans++;
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