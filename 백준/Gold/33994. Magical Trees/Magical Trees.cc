#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, q, e, r, w;



void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n - 1; i++) {
		cout << 1 << ' ' << i + 1 << '\n';
	}
	for (int i = 1; i <= n / 2; i++) {
		cout << 1 << ' ' << i * 2 << '\n';
		cout << i * 2 << ' ' << i * 2 + 1 << '\n';
	}

	for (int i = 1; i <= n / 2; i++) {
		cout << 1 << ' ' << i * 2 + 1 << '\n';
		cout << i * 2 << ' ' << i * 2 + 1 << '\n';
	}


}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
}