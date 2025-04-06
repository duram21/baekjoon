#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll ans[202020];



void solve() {
	cin >> n;
	vector<pair<ll, ll>>v;
	for (int i = 1; i <= n + 1; i++) {
		cin >> a;
		v.push_back({ a, i });
	}
	sort(all(v));
	vector<ll>emp;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		emp.push_back(a);
	}
	sort(all(emp));
	ll cnt = 0;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		a = v[i].first;
		b = emp[i];
		ll tmp = max(a - b, (ll)0);
		if (tmp > mx) {
			mx = tmp;
			cnt = 1;
		}
		else if (mx == tmp) {
			cnt++;
		}
	}
	ans[v[n].second] = mx;
	for (int i = n - 1; i >= 0; i--) {
		a = v[i + 1].first;
		b = emp[i];
		ll tmp = max(a - b, (ll)0);
		mx = max(mx, tmp);
		ans[v[i].second] = mx;
	}
	for (int i = 1; i <= n + 1; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}