#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
string s, t;
ll ans = 0;

void func(string T) {
	if (s.length() > T.length()) return;
	if (s == T) {
		ans = 1;
		return;
	}
	if (T[T.length() - 1] == 'A') {
		string tmp = T.substr(0, T.length() - 1);
		func(tmp);
	}
	if (T[0] == 'B') {
		string tmp = T.substr(1);
		reverse(tmp.begin(), tmp.end());
		func(tmp);
	}
}


void solve() {
	cin >> s >> t;
	func(t);
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