#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;
ll par[101010];

ll find(ll x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void solve() {
	cin >> n >> m >> str;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		if (str[a - 1] == str[b - 1]) {
			a = find(a);
			b = find(b);
			par[a] = b;
		}
	}
	string ans = "";
	while (m--) {
		char command;
		cin >> a >> b >> command;
		a = find(a);
		b = find(b);
		if (a != b) ans += "1";
		else {
			if (str[a - 1] == command) {
				ans += "1";
			}
			else ans += "0";
		}

	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}