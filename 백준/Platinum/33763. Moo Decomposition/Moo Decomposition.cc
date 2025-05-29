#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, k, y, h, w, q, m, x, l;
string str;
ll mod = 1e9 + 7;
ll cnt[1010100];
ll fact[1010100];

ll fpow(ll x, ll y) {
	if (y == 1) return x;
	ll tmp = fpow(x, y / 2) % mod;
	if (y % 2 == 0) {
		return tmp * tmp % mod;
	}
	else {
		return ((tmp * tmp % mod) * x) % mod;
	}
}

void solve() {
	cin >> k >> n >> l;
	cin >> str;
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	for (int i = n; i >= 1; i--) {
		if (str[i - 1] == 'M') cnt[i] = cnt[i + 1];
		else cnt[i] = cnt[i + 1] + 1;
	}
	ll ans = 1;
	ll chk = 0;

	for (int i = n; i >= 1; i--) {
		if (str[i - 1] == 'O') continue;
		ll cur = cnt[i] - k * chk;
		ll val = 1;
		for (int j = 0; j < k; j++) {
			val *= cur;
			cur--;
			val %= mod;
		}
		chk++;
		val *= fpow(fact[k], mod - 2);
		val %= mod;
		ans *= val;
		ans %= mod;
	}
	cout << fpow(ans, l) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}