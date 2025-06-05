#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q, d;
ll arr[202020];
ll ans = -1;

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}


void func(ll st, ll en, ll val) {
	if (st == en) {
		ll tmp = val + arr[st];
		ans = max(ans, tmp);
		return;
	}
	ll cur = 0;
	ll cnt = (en - st + 1) / 2;
	for (int i = st; i <= st + cnt - 1; i++) {
		cur = gcd(cur, arr[i]);
	}
	func(st + cnt, en, val + cur);
	
	cur = 0;
	cnt = (en - st + 2) / 2;
	for (int i = en; i >= en - cnt + 1; i--) {
		cur = gcd(cur, arr[i]);
	}
	func(st, en - cnt, val + cur);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	func(1, n, 0);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}