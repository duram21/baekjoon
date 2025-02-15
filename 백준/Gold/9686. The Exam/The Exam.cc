#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, l, r, x, s, t, w;


void solve() {
	cin >> n >> k;
	if (k > n / 2) {
		cout << "NIE\n";
		return;
	}
	ll s1 = n / 2 + 1;
	ll s2 = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2) cout << s1++ << ' ';
		else cout << s2++ << ' ';
	}
} 


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}