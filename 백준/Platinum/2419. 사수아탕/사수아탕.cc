#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
ll dp[303][303][2];
vector<ll>v;

ll func(ll l, ll r, ll pos, ll k) {
	if (!k) return 0;
	if (l > r) return 1e12;
	ll& ret = dp[l][r][pos];
	if (ret != -1) return ret;

	ret = 1e12;
	// 왼쪽으로 이동 가능한가?
	if (l) {
		if (pos == 0) {
			ret = min(ret, func(l - 1, r, 0, k - 1) + k * (v[l] - v[l - 1]));
		}
		else {
			ret = min(ret, func(l - 1, r, 0, k - 1) + k * (v[r] - v[l - 1]));
		}
	}
	if(r != n){
		if (!pos) {
			ret = min(ret, func(l, r + 1, 1, k - 1) + k * (v[r + 1] - v[l]));
		}
		else {
			ret = min(ret, func(l, r + 1, 1, k - 1) + k*(v[r + 1] - v[r]));
		}
	}
	return ret;
}

void solve() {
	cin >> n >> m;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back(a);
		//if(arr[i] == 0)
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	ll idx = lower_bound(v.begin(), v.end(), 0) - v.begin();



	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(dp, -1, sizeof(dp));
		ans = max(ans, i * m - func(idx, idx, 0, i));
	}
	cout << ans << '\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}