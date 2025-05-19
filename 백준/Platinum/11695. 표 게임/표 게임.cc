#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
string ans[2];

void solve() {
	cin >> n >> m;
	ll xr = 0;
	for (int i = 1; i <= n; i++) {
		ll sum = 0;
		for (int j = 1; j <= m; j++) {
			cin >> a;
			sum += a;
		}
		xr ^= sum;
	}
	if (!xr) {
		cout << "ainta\n";
	}
	else cout << "august14\n";
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}