#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, q, e, r, w, k;
string str;
ll cnt[26];
ll ans;
vector<ll>v;
ll sz;

void func(ll idx, ll sum) {
	if (sum == k) {
		ans = 1;
		return;
	}
	if (idx == sz) {
		return;
	}

	for (int i = idx; i < sz; i++) {
		if (sum + v[i] <= k) {
			func(idx + 1, sum + v[i]);
		}
		if (sum <= k) {
			func(idx + 1, sum);
		}
	}
	cout << idx << ' ' << sum << '\n';
}


void solve() {
	cin >> n >> k;
	cin >> str;
	for (int i = 1; i <= n; i++) {
		cnt[str[i - 1] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			v.push_back(cnt[i]);
		}
	}
	set<ll>s;
	s.insert(0);
	sz = v.size();
	sort(v.begin(), v.end());
	if (sz < 26 || n == k) {
		cout << 1 << '\n';
		return;
	}


	if (v[0] <= k) {
		ans = 1;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
}