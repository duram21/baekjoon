#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
vector<ll>v;

bool func(ll x) {
	ll cnt = 0;
	ll bef = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] > x) return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		ll cur = (v[i] - bef);
		if (cur > x) {
			bef = v[i - 1];
			cnt++;
		}
	}
	if (cnt <= c) return true;
	return false;
}


void solve() {
	cin >> L >> k >> c;
	v.push_back(0);
	for (int i = 1; i <= k; i++) {
		cin >> a;
		v.push_back(a);
	}
	v.push_back(L);
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end());
	ll l = 1;
	ll r = L;
	ll ans = 1e12;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (func(mid)) {
			r = mid - 1;
			ans = min(ans, mid);
		}
		else l = mid + 1;
	}
	ll idx = 0;
	ll bef = L;
	ll cnt = 0;
	ll ans2 = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		ll cur = abs(v[i] - bef);
		if (cur > ans) {
			ans2 = v[i + 1];
			bef = v[i + 1];
			cnt++;
		}
	}
	if (cnt < c) {
		ans2 = v[1];
	}
	cout << ans << ' ' << ans2 << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}