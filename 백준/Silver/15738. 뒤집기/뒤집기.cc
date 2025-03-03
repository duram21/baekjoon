#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m, q;


void solve() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	while (m--) {
		cin >> a;
		ll st, mid;
		if (a > 0 && k <= a) {
			k = 1 + a - k;
			
		}
		else if(a < 0 && n + 1 + a <= k){
			k = n + (n + 1 + a) - k;
		}
	}
	cout << k << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}