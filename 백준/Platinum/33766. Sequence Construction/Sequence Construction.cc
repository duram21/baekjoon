#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
bool chk[40];
bool chk2[40];

void solve() {
	cin >> n >> m;
	memset(chk, 0, sizeof(chk));
	memset(chk2, 0, sizeof(chk2));
	for (int i = 31; i >= 0; i--) {
		if ((1LL << i) & m) {
			chk[i] = 1;
		}
	}
	ll sum = 0;
	
	vector<ll>ans;

	for (int i = 31; i >= 0; i--) {
		if (!chk[i]) continue;
		ll cur = 1;
		ll tmp = 0;
		for (int j = 0; j < (1<<i); j++) {
			tmp += cur;
			cur *= 2;
		}
		sum += tmp;
		ans.push_back(tmp);
	}
	if (sum > n) {
		cout << -1 << '\n';
		return;
	}
	ll rm = n - sum;

	if (rm == 1) {
		if (!chk[0]) {
			cout << -1 << '\n';
			return;
		}
		else {
			ans[ans.size() - 1] += 1;
		}
	}

	for (int i = 31; i >= 0; i--) {
		if ((1LL << i) & rm) {
			chk2[i] = 1;
		}
	}
	vector<ll>v;
	for (int i = 31; i >= 0; i--) {
		if (!chk2[i]) continue;
		v.push_back((1LL << i));
	}
	if (v.size() % 2) {
		v.push_back(v[0] / 2);
		v.push_back(v[0] / 2);
		v.erase(v.begin());
	}

	for (auto a : v) {
		ans.push_back(a);
	}

	cout << ans.size() << '\n';
	for (auto a : ans) {
		cout << a << ' ';
	}
	cout << '\n';
	
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}