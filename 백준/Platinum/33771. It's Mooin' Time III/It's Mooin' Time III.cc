#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, y, h, w, q, m, x;
string str;
ll l[101010][26];
ll r[101010][26];
ll pos[101010][26];

void solve() {
	cin >> n >> q;
	cin >> str;
	// right
	for (int i = 1; i <= n; i++) {
		ll cur = str[i - 1] - 'a';
		for (int j = 0; j < 26; j++) {
			if (j == cur) {
				r[i][j] = i;
			}
			else {
				r[i][j] = r[i - 1][j];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		l[n + 1][i] = n + 1;
	}
	for (int i = n; i >= 1; i--) {
		ll cur = str[i - 1] - 'a';
		for (int j = 0; j < 26; j++) {
			if (j == cur) {
				l[i][j] = i;
			}
			else {
				l[i][j] = l[i + 1][j];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		pos[n + 1][i] = n + 1;
	}
	for (int i = n; i >= 1; i--) {
		ll cur = str[i - 1] - 'a';
		for (int j = 0; j < 26; j++) {
			if (j == cur) {
				pos[i][j] = pos[i + 1][j];
			}
			else {
				pos[i][j] = i;
			}
		}
	}

	while (q--) {
		cin >> a >> b;
		
		ll ans = -1;
		for (int i = 0; i < 26; i++) {
			ll R = r[b][i];
			ll L = pos[a][i];

			if (L + 1 > R) continue;

			ll mid = (L + R) / 2;
			ll idx1 = r[mid][i];
			ll idx2 = l[mid][i];
			if(L < idx1 && idx1 < R)
				ans = max(ans, (idx1 - L) * (R - idx1));
			if (L < idx2 && idx2 < R)
				ans = max(ans, (idx2 - L) * (R - idx2));
		}
		cout << ans << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}