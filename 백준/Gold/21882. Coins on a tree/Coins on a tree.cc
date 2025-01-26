#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
vector<ll>edges[101010];
ll arr[101010];

ll dfs(ll x) {
	vector<ll>v;
	for (ll nxt : edges[x]) {
		ll val = dfs(nxt);
		if (val == -1e9) continue;
		v.push_back(val);
	}

	sort(v.rbegin(), v.rend());
	if (arr[x] == 0) {
		if (v.size() == 0) {
			return -1e9;
		}
		if (v.size() == 1) {
			return v[0];
		}
		else {
			return arr[x] = v[0] + v[1];
		}
	}
	else {
		if (v.size() == 0) {
			return arr[x];
		}
		return max(arr[x], v[0]);
	}
}

void solve() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		edges[a].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += arr[i];
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