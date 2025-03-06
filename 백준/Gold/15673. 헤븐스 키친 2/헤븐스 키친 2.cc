#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
ll arr[101010];
ll pb[101010];
ll nb[101010];
ll pf[101010];
ll nf[101010];


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (n == 2) {
		cout << arr[1] * arr[2] << '\n';
		return;
	}
	ll cur = arr[1];
	if(cur > 0 )pf[1] = cur;
	for (int i = 2; i <= n; i++) {
		if (cur < 0) cur = 0;
		cur += arr[i];

		pf[i] = max(pf[i - 1], cur);
	}
	cur = arr[n];
	if (cur > 0)pb[n] = cur;
	for (int i = n-1; i >= 1; i--) {
		if (cur < 0) cur = 0;
		cur += arr[i];

		pb[i] = max(pb[i + 1], cur);
	}
	cur = arr[1];
	if (cur < 0) nf[1] = cur;
	for (int i = 2; i <= n; i++) {
		if (cur > 0) cur = 0;
		cur += arr[i];

		nf[i] = min(nf[i - 1], cur);
	}
	cur = arr[n];
	if (cur < 0) nb[n] = cur;
	for (int i = n - 1; i >= 1; i--) {
		if (cur > 0) cur = 0;
		cur += arr[i];
		nb[i] = min(nb[i + 1], cur);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, pf[i] * pb[i + 1]);
		ans = max(ans, nf[i] * nb[i + 1]);
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}