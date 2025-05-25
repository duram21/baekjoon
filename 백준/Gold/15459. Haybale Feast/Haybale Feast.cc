#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, x, l, h, w, q, m;
ll f[101010];
ll s[101010];
bool chk[101010];

void solve() {
	cin >> n >> m;
	priority_queue<pair<ll,ll>>pq;
	for (int i = 1; i <= n; i++) {
		cin >> f[i] >> s[i];
		pq.push({ -s[i], i });
	}
	ll sum = 0;
	ll ans = 0;
	ll l = -1;
	ll r = -1;
	while (pq.size()) {
		a = -pq.top().first;
		b = pq.top().second;
		pq.pop();
		sum = 0;
			l = b;
			r = b;
			sum += f[b];
			ans = s[b];
		chk[b] = 1;
		if (sum >= m) break;
		while (chk[l + 1]) {
			l++;
			sum += f[l];
			ans = max(ans, s[l]);
			if (sum >= m) break;
		}
		if (sum >= m) break;
		while (chk[r - 1]) {
			r--;
			sum += f[r];
			ans = max(ans, s[r]);
			if (sum >= m) break;
		}
		if (sum >= m) break;

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