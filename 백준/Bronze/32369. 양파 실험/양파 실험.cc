#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p;


void solve() {
	cin >> n >> a >> b;
	ll A = 1, B = 1;
	for (int i = 1; i <= n; i++) {
		A += a;
		B += b;
		if (A < B)swap(A, B);
		if (A == B) B--;
	}
	cout << A << ' ' << B << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}