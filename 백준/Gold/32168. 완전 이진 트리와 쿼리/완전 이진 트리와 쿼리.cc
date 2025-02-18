#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w;
ll ans[101010];

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}

ll func(ll st) {
	ll ret = 0;
	ll gap = 1;
	while (st <= n) {
		ll en = min(st + gap - 1, n);
		if (en == n) {
			gap = en - st + 1;
		}
		ret += gap * (st + en) / 2;
		st *= 2;
		gap *= 2;
		if (en == n) break;
	}

	return ret;
}

void solve() {
	cin >> n >> q;
	ll root = 1;
	map<ll, ll>m;
	while (q--) {
		cin >> a >> b;
		if (a == 1) {
			root = b;
			m.clear();
			while (b > 0) {
				m[b / 2] = b;
				b /= 2;
			}
		}
		else {
			ll ans = 0;
			if (root == b) {
				cout << func(1) << '\n';
				continue;
			}
			if (m.find(b) == m.end()) {
				ans += func(b);
			}
			else {
				ans = func(1) - func(m[b]);
			}
			cout << ans << '\n';
		}
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