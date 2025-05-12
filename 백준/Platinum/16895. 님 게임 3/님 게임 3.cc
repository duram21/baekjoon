#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll arr[1010];


void solve() {
	cin >> n;
	ll xr = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		xr ^= arr[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		xr ^= arr[i];
		if (xr < arr[i]) ans++;
		xr ^= arr[i];
	}
	cout << ans << '\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}