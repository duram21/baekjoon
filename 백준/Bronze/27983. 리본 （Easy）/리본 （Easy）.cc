#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll X[1010];
ll L[1010];
char C[1010];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(X[i] - X[j]) <= L[i] + L[j]) {
				if (C[i] != C[j]) {
					cout << "YES\n";
					cout << i << ' ' << j << '\n';
					return;
				}
			}
		}
	}
	cout << "NO\n";
	return;
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}