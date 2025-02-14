#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll X[1010];
ll L[1010];
char C[1010];
string str, bef;
ll mod = 1e9 + 9;

void solve() {
	cin >> str;
	ll ans = 1;
	for (int i = 0; i < str.length(); i++) {
		if (!i) {
			if (str[i] == 'd') ans *= 10;
			else ans *= 26;
		}
		else {
			if (str[i] == 'd') {
				if (str[i - 1] == 'd') ans *= 9;
				else ans *= 10;
			}
			if (str[i] == 'c') {
				if (str[i - 1] == 'c') ans *= 25;
				else ans *= 26;
			}
		}
		ans %= mod;
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}