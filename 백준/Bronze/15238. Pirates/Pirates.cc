#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, k, g, q, m;
ll chk[50];
string str;

void solve() {
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		chk[str[i] - 'a']++;
	}
	char ans = 'a';
	ll mx = 0;
	for (int i = 0; i < 26; i++) {
		if (mx < chk[i]) {
			mx = chk[i];
			ans = 'a' + i;
		}
	}
	cout << ans << ' ' << mx << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}