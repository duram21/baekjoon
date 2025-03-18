#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct sw {
	ll M;
	ll P;
	ll R;

};

bool cmp(sw a, sw b) {
	return a.P * b.R  > b.P * a.R * 1LL;
}

ll n, a, b, c, d, l, r, k, g, m, h, w, t, p;
ll dp[101010];
ll M[55];
ll P[55];
ll R[55];

void solve() {
	cin >> n >> t;
	vector<sw>v;
	for (int i = 1; i <= n; i++) {
		cin >> M[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> R[i];
		sw A;
		A.M = M[i];
		A.P = P[i];
		A.R = R[i];
		v.push_back(A);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		m = v[i].M;
		p = v[i].P;
		r = v[i].R;
		//cout << m << ' ' << p << ' ' << r << '\n';
		for (int j = t; j >= 0; j--) {
			ll tm = j - r;
			if (tm < 0) break;
			dp[j] = max(dp[j], dp[tm] + max((ll)0, m - j * p));
		}
	}
	ll ans = 0;
	for (int i = 0; i <= t; i++) {
		ans = max(ans, dp[i]);
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