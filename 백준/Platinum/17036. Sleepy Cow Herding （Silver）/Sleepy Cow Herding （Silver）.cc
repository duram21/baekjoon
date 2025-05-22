#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;


void solve() {
	cin >> n;
	vector<ll>v;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(all(v));
	ll cnt = 1;
	ll j = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cnt--;
		while (j < n && v[i] + n - 1 >= v[j]) {
			cnt++;
			j++;
		}
		ans = max(ans, cnt);
	}
	if (v[n - 2] - v[0] == n - 2 && v[n - 1] - v[n - 2] > 2) ans = n - 2;
	if (v[n - 1] - v[1] == n - 2 && v[1] - v[0] > 2) ans = n - 2;
	cout << n - ans << '\n';

	cout << max(abs(v[1] - v[n - 1]), abs(v[0] - v[n - 2])) - (n-2);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}