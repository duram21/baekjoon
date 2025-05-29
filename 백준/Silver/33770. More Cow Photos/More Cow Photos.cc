#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m;
ll cnt[101010];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
	}
	ll mx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cnt[a]++;
		mx = max(mx, a);
	}
	ll sum = 0;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 2) {
			sum++;
			if (i == mx) flag = 1;
		}
	}
	if (sum * 2 == n) {
		cout << n - 1 << '\n';
	}
	else {
		if (!flag)	cout << sum * 2 + 1 << '\n';
		else cout << (sum - 1) * 2 + 1 << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}