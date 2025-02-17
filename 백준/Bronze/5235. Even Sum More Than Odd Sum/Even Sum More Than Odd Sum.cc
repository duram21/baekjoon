#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w;
ll cnt[1010101];
ll ans[1010101];

void solve() {
	cin >> n;
	while (n--) {
		cin >> m;
		ll even = 0;
		ll odd = 0;
		while (m--) {
			cin >> a;
			if (a % 2) odd += a;
			else even += a;
		}
		if (even > odd) cout << "EVEN\n";
		else if (even < odd) cout << "ODD\n";
		else cout << "TIE\n";
	}
} 


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}