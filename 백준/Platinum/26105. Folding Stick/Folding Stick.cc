#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, t, w;
ll arr[101010];
ll dp[101010];
ll s[101010];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}
	for (int i = 0; i <= n; i++) dp[i] = 1e12;
	dp[0] = 0;
	vector<pair<ll, ll>>v;
	v.push_back({ 0, 0 });
	for (int i = 1; i <= n; i++) {
		ll idx = upper_bound(v.begin(), v.end(), make_pair(s[i], n)) - v.begin();
		ll a = v[idx-1].second;
		dp[i] = s[i] - s[a];
		while (v.size() && v.back().first >= dp[i] + s[i]) {
			v.pop_back();
		}
		v.push_back({ dp[i] + s[i], i });
	}
	ll ans = 1e12;
	for (int i = 1; i < n; i++) {
		ans = min(ans, max(dp[i], s[n] - s[i]));
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