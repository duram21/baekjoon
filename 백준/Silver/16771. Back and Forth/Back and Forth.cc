#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
ll A[11];
ll B[11];
ll ta = 1000;
ll tb = 1000;
set<ll>s;

void func(ll idx) {
	if (idx == 5) {
		s.insert(ta);
		return;
	}
	// 1 -> 2
	
	if (idx % 2 == 1) {
		ll pos = -1;
		for (int i = 0; i <= 10; i++) {
			if (!B[i]) pos = i;
		}

		for (int i = 0; i <= 10; i++) {
			if (!A[i]) continue;
			ll tmp = A[i];
			ta -= A[i];
			tb += A[i];
			A[i] = 0;
			B[pos] = tmp;

			func(idx + 1);

			ta += tmp;
			tb -= tmp;
			A[i] = tmp;
			B[pos] = 0;
		}
	}
	else {
		ll pos = -1;
		for (int i = 0; i <= 10; i++) {
			if (!A[i]) pos = i;
		}

		for (int i = 0; i <= 10; i++) {
			if (!B[i]) continue;
			ll tmp = B[i];
			tb -= B[i];
			ta += B[i];
			B[i] = 0;
			A[pos] = tmp;

			func(idx + 1);

			tb += tmp;
			ta -= tmp;
			B[i] = tmp;
			A[pos] = 0;
		}
	}
}

void solve() {
	for (int i = 0; i < 10; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> B[i];
	}
	func(1);
	cout << s.size() << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}