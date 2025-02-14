#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
		}
	}
	vector<pair<ll, ll>>ans;
	ll x = 0, y = 0;
	while (true) {
		ans.push_back({ x, y });
		ans.push_back({ x + 1, y });
		ans.push_back({ x, y });
		ans.push_back({ x + 1, y });
		if (x + 2 == n) {
			x++;
			y++;
			break;
		}
		else if (x + 2 == n - 1) {
			x += 2;
			break;
		}
		x += 2;
	}
	while (true) {
		if(y == m-1){
			ans.push_back({x-1, y});
			ans.push_back({x, y});
			ans.push_back({ x - 1, y});
			ans.push_back({ x, y});
			break;
		}
			ans.push_back({ x, y });
			ans.push_back({ x, y+1 });
			ans.push_back({ x, y });
			ans.push_back({ x, y+1 });
		if (y + 2 == m) {
			break;
		}
		y += 2;
	}
	cout << ans.size() << '\n';
	for (auto nxt : ans) {
		cout << nxt.first << ' ' << nxt.second << '\n';
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}