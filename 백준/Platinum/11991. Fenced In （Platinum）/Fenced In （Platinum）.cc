#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;
ll A[30303];
ll B[30303];


void solve() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= m; i ++) {
		cin >> B[i];
	}
	A[n + 1] = a;
	B[m + 1] = b;
	sort(A, A + n + 1);
	sort(B, B + m + 1);
	for (int i = 0; i <= n; i++) {
		A[i] = A[i + 1] - A[i];
	}
	for (int i = 0; i <= m; i++) {
		B[i] = B[i + 1] - B[i];
	}
	sort(A, A + n + 1);
	sort(B, B + m + 1);


	ll ans = 0;

	m++; n++;
	ans += A[0] * (m-1);
	ans += B[0] * (n-1);
	for (int i = 1, j = 1; i < n && j < m; ) {
		if (A[i] < B[j]) {
			ans += A[i] * (m - j);
			i++;
		}
		else {
			ans += B[j] * (n - i);
			j++;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}