#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc;
string str;
ll dp[50050];
ll mod = 1e9 + 9;
ll fact[50505];
ll p[50505];

void solve() {
	cin >> n >> k;
	ll cur = n;
	ll gap = 1;
	ll cnt = 0;
	// 첫째항 a
	a = 1;
	ll mina = 1;
	while (true) {
		//cout << gap << ' ' << cur << ' ' << ' ' << a << ' ' << k << ' ' << mina << '\n';
		if (mina == a) {
			ll tmp = (cur + 1) / 2;
			if (k <= tmp) {
				cout << a + (k - 1) * gap * 2 << '\n';
				return;
			}
			else {
				k -= tmp;
			}
			if (cur % 2 == 0) {
				a = a + gap;
				mina = a;
			}
			else {
				mina = a + gap;
				a = a + gap * 3;
				if (a > n) a = mina;
			}
			cur -= tmp;

		}
		else {
			ll tmp = (cur) / 2;
			if (k <= tmp) {
				cout << a + (k - 1) * gap * 2 << '\n';
				return;
			}
			else {
				k -= tmp;
			}
			if (cur % 2 == 0) {
				a = a + gap;
				if (a > n) a = mina;
			}
			else {
				a = mina;

			}
			cur -= tmp;
		}
		gap *= 2;
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc = 1;
	while (tc--) {
		solve();
	}
}