#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;


void solve() {
	cin >> n >> m;
	vector<pair<ll, ll>>v;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	vector<ll>C;

	for (int i = 1; i <= m; i++) {
		cin >> a;
		C.push_back(a);
	}
	sort(all(C));
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (C[m - 1 - ans] >= v[i].second) ans++;
		if (ans == m) break;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}