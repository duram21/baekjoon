#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll fibo[40];
ll dp[3030300];
ll chk[40];

void solve() {
	fibo[1] = 1;
	for (int i = 2; i < 40; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	for (int i = 1; i <= 3e6; i++) {
		memset(chk, 0, sizeof(chk));
		for (int j = 1; i - fibo[j] >= 0; j++) {
			chk[dp[i - fibo[j]]] = 1;
		}
		for (int j = 0; j < 40; j++) {
			if (!chk[j]) {
				dp[i] = j;
				break;
			}
		}
	}
	ll xr = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		xr ^= dp[a];
	}
	if (!xr) {
		cout << "cubelover\n";
	}
	else cout << "koosaga\n";

}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}