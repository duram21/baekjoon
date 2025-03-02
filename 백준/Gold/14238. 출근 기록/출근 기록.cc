#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
int dp[51][51][51][51][4][4];
string str;
char ans[55];

bool func(ll idx, ll A, ll B, ll C, ll bef, ll bbef) {
	if (!A && !B && !C) return true;
	int& ret = dp[idx][A][B][C][bef][bbef];
	if (ret != -1) return ret;
	
	ret = 0;
	if (A) {
		ans[idx] = 'A';
		if (func(idx + 1, A - 1, B, C, 0, bef)) {
			ret = 1;
			return ret;
		}
	}
	if (B && bef != 1) {
		ans[idx] = 'B';
		if (func(idx + 1, A, B - 1, C, 1, bef)) {
			ret = 1;
			return ret;
		}
	}
	if (C && bef != 2 && bbef != 2) {
		ans[idx] = 'C';
		if (func(idx + 1, A, B, C - 1, 2, bef)) {
			ret = 1;
			return ret;
		}
	}
	return ret;
}


void solve() {
	cin >> str;
	ll aa = 0, bb = 0, cc = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') aa++;
		if (str[i] == 'B') bb++;
		if (str[i] == 'C') cc++;
	}
	memset(dp, -1, sizeof(dp));
	if (func(1, aa, bb, cc, 3, 3)) {
		for (int i = 1; i <= str.length(); i++) {
			cout << ans[i];
		}
		cout << '\n';
	}
	else cout << -1 << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}