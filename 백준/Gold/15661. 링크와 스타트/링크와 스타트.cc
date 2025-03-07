#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
ll ans = 1e12;
ll arr[30][30];


void func(ll x) {
	vector<ll>t1;
	vector<ll>t2;
	for (int i = 0; i < n; i++) {
		if (~x & (1 << i)) {
			t1.push_back(i);
		}
		else t2.push_back(i);
	}
	a = 0;
	b = 0;
	for (int i = 0; i < t1.size(); i++) {
		for (int j = 0; j < t1.size(); j++) {
			a += arr[t1[i]][t1[j]];
		}
	}
	for (int i = 0; i < t2.size(); i++) {
		for (int j = 0; j < t2.size(); j++) {
			b += arr[t2[i]][t2[j]];
		}
	}

	ans = min(ans, abs(a - b));
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < (1 << n) - 1; i++) {
		func(i);
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}