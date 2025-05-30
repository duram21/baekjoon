#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l;
vector<ll>x;
vector<ll>y;
vector<pair<ll, ll>>v;
ll dp[101010][3];


void solve() {
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	sort(x.begin(), x.end());
	x.erase(unique(all(x)), x.end());
	sort(y.begin(), y.end());
	y.erase(unique(all(y)), y.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		a = lower_bound(all(x), v[i].first) - x.begin();
		b = lower_bound(all(y), v[i].second) - y.begin();
		ll dist = abs(v[i].first - v[i].second) + l ;
		ll ta = dp[a][0];
		ll tb = dp[b][1];
		dp[a][0] = max(dp[a][0], dist + tb);
		dp[b][1] = max(dp[b][1], dist + ta);
		ans = max({ ans, dp[a][0], dp[b][1] });
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