#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;


void solve() {
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	ll gap = min(abs(a - b), abs(c - b));
	ll mgap = max(abs(a - b), abs(c - b));
	if (a + 2 == c) {
		cout << 0 << '\n';
	}
	else if (gap == 2) {
		cout << 1 << '\n';
	}
	else cout << 2 << '\n';
	cout << mgap - 1<< '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}