#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
ll cap[4];
ll cnt[4];

void func(ll x, ll y) {
	// x -> y;
	ll tmp = min(cap[y] - cnt[y], cnt[x]);
	cnt[y] += tmp;
	cnt[x] -= tmp;
}

void solve() {
	cin >> cap[0] >> cnt[0];
	cin >> cap[1] >> cnt[1];
	cin >> cap[2] >> cnt[2];

	for (int i = 0; i < 33; i++) {
		func(0, 1);
		func(1, 2);
		func(2, 0);
	}
	func(0, 1);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}