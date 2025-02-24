#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d;


void solve() {
	string ksa = "KSA";
	string str;
	cin >> str;
	n = str.length();
	if (n == 1) {
		if (str == "K") {
			cout << 0 << '\n';
			return;
		}
		cout << 2 << '\n';
		return;
	}
	if (n == 2) {
		ll ans = -1;
		if (str[0] == 'K') {
			if (str[1] == 'K') {
				ans = 2;
			}
			if (str[1] == 'S') {
				ans = 0;
			}
			if (str[1] == 'A') {
				ans = 2;
			}
		}
		if (str[0] == 'S') {
			if (str[1] == 'K') {
				ans = 2;
			}
			if (str[1] == 'S') {
				ans = 2;
			}
			if (str[1] == 'A') {
				ans = 2;
			}
		}
		if (str[0] == 'A') {
			if (str[1] == 'K') {
				ans = 2;
			}
			if (str[1] == 'S') {
				ans = 2;
			}
			if (str[1] == 'A') {
				ans = 4;
			}
		}
		cout << ans << '\n';
		return;
	}

	ll ans = 1e12;
	ll idx = 0;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == ksa[idx]) {
			cnt++;
			idx = (idx + 1) % 3;
		}
	}
	ans = min(ans, (n - cnt) * 2);

	cnt = 0;
	idx = 1;
	for (int i = 0; i < n; i++) {
		if (str[i] == ksa[idx]) {
			cnt++;
			idx = (idx + 1) % 3;
		}
	}
	if (n == cnt) {
		ans = min(ans, (n - cnt) * 2 + 2);
	}
	else ans = min(ans, (n - cnt) * 2);
	

	cnt = 0;
	idx = 2;
	for (int i = 0; i < n; i++) {
		if (str[i] == ksa[idx]) {
			cnt++;
			idx = (idx + 1) % 3;
		}
	}
	if (n == cnt) {
		ans = min(ans, (n - cnt) * 2 + 4);
	}
	else if (n - 1 == cnt) {
		ans = min(ans, (n - cnt) * 2 + 2);

	}
	else {
		ans = min(ans, (n - cnt) * 2);

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