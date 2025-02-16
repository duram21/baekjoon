#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w;
string s, t;

void solve() {
	cin >> s >> t;
	bool flag = 0;
	ll gap = (s.length() - t.length());
	ll idx = gap / 2;
	if (s.length() == t.length()) {
		if (s == t) flag = 1;
	}
	else if (gap % 2 == 0) {
		if (t == s.substr(idx, t.length()) || (t == s.substr(idx - 1, t.length()) && t == s.substr(idx + 1, t.length()))) {
			flag = 1;
		}
	}
	else {
		if (s.substr(idx, t.length()) == t && s.substr(idx + 1, t.length()) == t) {
			flag = 1;
		}
	}
	if (flag) cout << "Alice\n";
	else cout << "Bob\n";
} 


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}