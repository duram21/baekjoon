#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
ll sum[1010];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		sum[a] += c;
		sum[b + 1] -= c;
	}
	ll ans = -1;
	for (int i = 1; i <= 1000; i++) {
		sum[i] += sum[i - 1];
		ans = max(ans, sum[i]);
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