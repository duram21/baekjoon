#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll mod = 1e9 + 7;


void solve() {
	cin >> n;
	ll ans1 = 0;
	ll ans2 = 1;
	for (int i = 2; i <= n; i++) {
		ans2 *= i;
		ans2 %= mod;
	}
	ans2 = ans2 * ans2 % mod;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		ans1 += sum * i  * 2% mod;
		ans1 %= mod;
	}
	cout << ans1 << ' ' << ans2 << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}