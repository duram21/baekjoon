#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k;
ll dp[1010][1010][13];
ll A[1010];
ll B[1010];
ll mod = 1e9 + 9;

ll func(ll i, ll j, ll idx) {
	if (idx == k ) return  1;
	if (i == n + 1 || j == m + 1) return idx == k;
 	
	ll& ret = dp[i][j][idx];
	if (ret != -1) return ret;
	ret = 0;
	ret = func(i + 1, j, idx) + func(i, j + 1, idx) - func(i + 1, j + 1, idx);
	ret += mod;
	ret %= mod;
	if (A[i] > B[j]) {
		ret += func(i + 1, j + 1, idx + 1) % mod;
		ret %= mod;
	}
	return ret;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
	}
	sort(A + 1, A + 1 + n);
	sort(B + 1, B + 1 + m);
	memset(dp, -1, sizeof(dp));
	cout << func(1, 1, 0) << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}