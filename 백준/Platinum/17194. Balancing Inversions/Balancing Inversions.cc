#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll arr[201010];
ll lone, rone;
ll ans = 1e18;
ll cur;

ll inv(ll st, ll en) {
	ll ret = 0;
	ll sum = 0;
	for (int i = st; i <= en; i++) {
		if (arr[i]) sum++;
		else ret += sum;
	}
	return ret;
}

void func() {
	// 1 -> 0
	ll a1 = inv(1, n);
	ll b1 = inv(n + 1, 2 * n);
	ans = min(ans, abs(a1 - b1));
	ll diff = a1 - b1;
	ll j = n + 1;
	ll cost = 0;
	ll cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (arr[i] != cur) continue;
		while (j <= 2 * n) {
			if (arr[j] == 1 - cur) break;
			else if (arr[j] == cur) j++;
		}
		if (j > 2 * n) return;
		// 왼쪽 부분
		diff -= (n - i);
		cost += (n - i);

		// 오른쪽 부분
		diff += (j - (n+1));
		cost += j - (n+1);

		// 가운데 교환
		cost += 1;
		diff += lone - cnt;
		diff -= (n - rone - cnt);

		ans = min(ans, cost + abs(diff));
		cnt++;
		j++;
	}
}

void func2() {
	// 0 -> 1
	ll a1 = inv(1, n);
	ll b1 = inv(n + 1, 2 * n);
	ans = min(ans, abs(a1 - b1));
	ll diff = a1 - b1;
	ll j = n + 1;
	ll cost = 0;
	ll cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (arr[i] != cur) continue;
		while (j <= 2 * n) {
			if (arr[j] == 1 - cur) break;
			else if (arr[j] == cur) j++;
		}
		if (j > 2 * n) return;
		// 왼쪽 부분
		diff += (n - i);
		cost += (n - i);

		// 오른쪽 부분
		diff -= (j - (n+1));
		cost += j - (n+1);

		// 가운데 교환
		cost += 1;
		diff -= lone - cnt;
		diff += (n - rone - cnt);
		ans = min(ans, cost + abs(diff));
		cnt++;
		j++;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> arr[i];
		if (arr[i]) {
			if (i <= n) {
				lone++;
			}
			else rone++;
		}
	}
	cur = 1;
	func();
	cur = 0;
	func2();

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