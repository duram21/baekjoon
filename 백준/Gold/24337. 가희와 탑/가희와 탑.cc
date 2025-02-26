#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p;
ll arr[101010];


void solve() {
	cin >> n >> a >> b;
	if (n + 1 < a + b) {
		cout << -1 << '\n';
		return;
	}
	ll mx = max(a, b);
	ll t = 1;
	for (int i = 1; i < b; i++) {
		arr[n + 1- i] = t++;
	}
	if (a >= n + 1 - b || b == 1) {
		arr[n + 1 - b] = mx;
	}
	else {
		arr[n + 1 - b] = 1;
	}
	////////////////////
	ll st = n + 1 - a - b;
	for (int i = 1; i <= st; i++) {
		arr[i] = 1;
	}
	for (int i = 1; i < a; i++) {
		arr[i + st] = i;
	}
	arr[st + a] = mx;
	if (a == 1) {
		arr[1] = mx;
		for (int i = 2; i <= n; i++) {
			if (arr[i] == mx) arr[i] = 1;
		}
	}
	else {
		for (int i =st +  a + 1; i <= n - b; i++) {
			arr[i] = 1;
		}

	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}