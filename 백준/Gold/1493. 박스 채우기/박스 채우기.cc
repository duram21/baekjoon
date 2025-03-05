#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, g, q, m;
bool flag = 0;
ll box[22];
ll ans = 0;

void func(ll l, ll w, ll h) {
	if (!l || !w || !h) return;
	flag = 0;
	ll len;
	for (int i = 20; i >= 0; i--) {
		if (!box[i]) continue;
		len = (1 << i);
		if (l >= len && w >= len && h >= len) {
			box[i] -= 1;
			ans++;
			flag = 1;

			break;
		}
	}
	if (!flag) return;
	func(l - len, len, len);
	func(l, len, h - len);
	func(l, w - len, h);
}

void solve() {
	ll L, W, H;
	cin >> L >> W >> H;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> box[a];
	}
	func(L, W, H);
	if (flag) {
		cout << ans << '\n';
	}
	else cout << -1 << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}