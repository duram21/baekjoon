#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll happy[1010101];
ll tired[1010101];
ll hf[1010101];
ll hb[1010101];
ll tf[1010101];
ll tb[1010101];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> happy[i];
		cin >> tired[i];
	}
	for (int i = 0; i <= n+1; i++) {
		hf[i] = 1e12;
		hb[i] = -1;
		tf[i] = -1;
		tb[i] = 1e12;
	}
	for (int i = 1; i <= n; i++) {
		if (happy[i]) hf[i] = min(happy[i], hf[i - 1]);
		else hf[i] = hf[i - 1];
		if (tired[i]) tf[i] = max(tf[i - 1], tired[i]);
		else tf[i] = tf[i - 1];
	}
	ll ans = -1;
	for (int i = n; i >= 1; i--) {
		if (happy[i]) hb[i] = max(hb[i + 1], happy[i]);
		else hb[i] = hb[i + 1];
		if (tired[i]) tb[i] = min(tb[i + 1], tired[i]);
		else tb[i] = tb[i + 1];
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << hf[i] << ' ' << hb[i] << ' ' << tf[i] << ' ' << tb[i] << '\n';
	//}
	for (int i = 1; i <= n-1; i++) {
		if (hf[i] > hb[i + 1] && tf[i] < tb[i + 1]) ans = i;
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