#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, g,  q, m;
string s, t;

void solve() {
	cin >> n;
	cin >> s >> t;

	string cur = s;
	ll ans = 1e12;
	ll cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (cur[i] != t[i]) {
			for (int j = 0; j < 3; j++) {
				if (i + j == n) break;
				if (cur[i+j] == '0') cur[i+j] = '1';
				else cur[i+j] = '0';
			}
			cnt++;
		}
	}
	if (cur == t) ans = min(ans, cnt);
	cur = s;
	for (int j = 0; j < 2; j++) {
		if (cur[ j] == '0') cur[j] = '1';
		else cur[j] = '0';
	}
	cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (cur[i] != t[i]) {
			for (int j = 0; j < 3; j++) {
				if (i + j == n) break;
				if (cur[i + j] == '0') cur[i + j] = '1';
				else cur[i + j] = '0';
			}
			cnt++;
		}
	}
	if (cur == t) ans = min(ans, cnt);
	if (ans == 1e12) cout << -1 << '\n';
	else cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}