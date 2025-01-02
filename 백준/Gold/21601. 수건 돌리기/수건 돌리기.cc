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
	while (true) {
			ll tmp = (cur + 1) / (2);
		//cout << gap << ' ' << cur << ' ' << tmp << ' ' << a << ' ' << k  << '\n';
		if (cur % 2 == 0) {
			if (k <= tmp) {
				cout << a + (k-1) * gap * 2 << '\n';
				break;
			}
			else {
				k -= tmp;
			}
			
			a = a + gap;
		}
		else {
			if (k <= tmp) {
				cout << a + (k-1) * gap * 2 << '\n';
				break;

			}
			else {
				k -= tmp;
			}

			a = a + gap * 3;
		}
		cur -= tmp;
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