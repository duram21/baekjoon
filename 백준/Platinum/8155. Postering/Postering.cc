#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll arr[1001];
ll sum[1001];

void solve() {
	cin >> n;
	ll ans = 0;
	stack<ll>st;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (st.size() == 0) {
			st.push(b);
			continue;
		}
		while (st.size() && st.top() > b) {
			st.pop();
			ans++;
		}
		if (st.size() == 0) st.push(b);
		else {
			if (st.top() == b) continue;
			st.push(b);
		}
	}
	cout << ans + st.size() << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}