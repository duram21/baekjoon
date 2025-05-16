#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
string ans[2];

void solve() {
	cin >> n;
	ll xr = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		xr ^= a - 2;
	}
	string str;
	cin >> str;
	ans[0] = "Whiteking";
	ans[1] = "Blackking";
	bool flag = 0;
	if (ans[0] != str) flag = 1;
	if (!xr) {
		cout << ans[!flag] << '\n';
	}
	else cout << ans[flag] << '\n';

}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}