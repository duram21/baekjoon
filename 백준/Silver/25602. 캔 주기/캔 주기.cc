#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll arr[10];
ll R[10][10];
ll M[10][10];
ll ans;

void sol(ll K, ll sum) {
	if (K == k+1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i]--; arr[j]--;
			if (arr[i] >= 0 && arr[j] >= 0) {
				sol(K + 1, sum + R[K][i] + M[K][j]);
			}
			arr[i]++; arr[j]++;
		}
	}

}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> R[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> M[i][j];
		}
	}
	sol(1, 0);
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