#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll sum[1010][1010];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			sum[j][b]++;
			sum[j][d]--;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 1000; i++) {
		ll cur = 0;
		for (int j = 0; j <= 1000; j++) {
			cur += sum[i][j];
			if (cur == k) {
				ans++;
			}
		}
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