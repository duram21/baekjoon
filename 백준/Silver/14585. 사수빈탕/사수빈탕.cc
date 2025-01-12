#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, m, k, q, d, tc, l, r, s, a, b;
ll A[303];
ll B[303];
ll dp[303];

void solve() {
	cin >> n >> m;
	vector<pair<ll, ll>>v;
	v.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		cin >> A[i] >> B[i];
		v.push_back({ A[i], B[i] });
	}
	sort(v.begin(), v.end());
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].first >= v[j].first && v[i].second >= v[j].second) {
				dp[i] = max(dp[i], dp[j] + max((ll)0, m - v[i].first - v[i].second));
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans  << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}