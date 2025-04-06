#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;
ll J[202020];
ll O[202020];
ll I[202020];
string joi = "JOI";



void solve() {
	cin >> n >> k;
	cin >> str;
	vector<ll>v[3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (str[i] == joi[j]) {
				v[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		//cout << v[i].size() << '\n';
		if (v[i].size() < k) {
			cout << -1 << '\n';
			return;
		}
	}
	ll cur = 0;
	for (int i = 0; i < v[0].size(); i++) {
		if (i + k - 1 >= v[0].size()) break;
		ll nxt = v[0][i + k - 1];
		while (cur <= v[0][i]) {
			J[cur] = nxt;
			cur++;
		}
	}
	while (cur <= n) {
		J[cur] = -1;
		cur++;
	}
	cur = 0;
	for (int i = 0; i < v[1].size(); i++) {
		if (i + k - 1 >= v[1].size()) break;
		ll nxt = v[1][i + k - 1];
		while (cur <= v[1][i]) {
			O[cur] = nxt;
			cur++;
		}
	}
	while (cur <= n) {
		O[cur] = -1;
		cur++;
	}
	cur = 0;
	for (int i = 0; i < v[2].size(); i++) {
		if (i + k - 1 >= v[2].size()) break;
		ll nxt = v[2][i + k - 1];
		while (cur <= v[2][i]) {
			I[cur] = nxt;
			cur++;
		}
	}
	while (cur <= n) {
		I[cur] = -1;
		cur++;
	}

	ll ans = 1e12;
	for (int i = 0; i < n; i++) {
		ll en = I[O[J[i]]];
		if (J[i] == -1 || O[J[i]] == -1 || en == -1) continue;
		ans = min(ans, en - i + 1 - 3 * k);
	}
	if (ans == 1e12) cout << -1 << '\n';
	else 
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}