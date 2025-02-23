#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c, m, m2, tc, d, k, l, r, x, w;
string str;

ll cnt[6];
ll cur_cnt[5];
char ksa[30];
ll len = -1;
ll ans;

bool chk(ll x) {
	if (x == 2) return 1;
	if (x == 0) {
		if (cnt[0] - cur_cnt[0] >= 1) {
			return 1;
		}
		return 0;
	}
	if (x == 1) {
		if (cnt[0] - cur_cnt[0] < 1) return 0;
		if (cnt[1] - cur_cnt[1] < 1) return 0;
		return 1;
	}
}

void func(ll x, ll cur) {
	ll mov = 0;
	while (cnt[x] - cur_cnt[x] >= 1) {
		cur_cnt[x]++;
		mov++;
		x = (x - 1 + 3) % 3;
	}
}

void solve() {
	cin >> str;
	n = str.length();
	ksa[0] = 'K';
	ksa[1] = 'S';
	ksa[2] = 'A';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (str[i] == ksa[j]) cnt[j]++;
		}
	}
	ll ans = n;
	ll idx = 0;

	while (cnt[idx] - cur_cnt[idx] >= 1) {
		cur_cnt[idx]++;
		idx = (idx + 1) % 3;
	}
	idx = (idx - 1 + 3) % 3;
	
	memset(cur_cnt, 0, sizeof(cur_cnt));

	ll cur = 0;

	for (int i = n-1 ; i >= 0; i--) {
		if (str[i] == ksa[idx]) {
			cur_cnt[idx]++;
			idx = (idx - 1 + 3) % 3;
			cur++;
		}
	}
	if (chk(idx) == 1) {
		ans = min(ans, n - cur);
	}
	else {
		if (idx == 1)ans = min(ans, n - cur + 1);
		// idx == 1 이면 + 1
		if (idx == 0)ans = min(ans, n - cur + 2);
	}
	
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}