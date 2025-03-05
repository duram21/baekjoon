#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, g, q, m;
string str, t;

void solve() {
	cin >> n;
	cin >> str;

	//R 개수 셀때;
	bool flag = 0;
	ll cnt = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (!flag) {
			if (str[i] == 'B') {
				flag = 1;
			}
		}
		else {
			if (str[i] == 'R') {
				cnt++;
			}
		}
	}
	ll ans = 0;
	flag = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (!flag) {
			if (str[i] == 'R') flag = 1;
		}
		else {
			if (str[i] == 'B') {
				ans++;
			}
		}
	}
	ans = 0;
	flag = 0;
	for (int i = 0; i < str.length(); i++) {
		if (!flag) {
			if (str[i] == 'R') flag = 1;
		}
		else {
			if (str[i] == 'B') {
				ans++;
			}
		}
	}
	ll Ans = min(ans, cnt);
	Ans = min(Ans, ans);
	ans = 0;
	flag = 0;
	for (int i = 0; i < str.length(); i++) {
		if (!flag) {
			if (str[i] == 'B') flag = 1;
		}
		else {
			if (str[i] == 'R') {
				ans++;
			}
		}
	}
	Ans = min(Ans, ans);

	cout << Ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}