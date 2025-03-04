#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, l, r, p, g,  q;
map<ll, ll>m;
map<ll, ll>S;
map<ll, ll>K;
string str;

struct abc {
	ll val;
	ll s;
	ll k;
};


void solve() {
	cin >> str;
	n = str.length();
	ll scnt = 0, kcnt = 0;
	ll ans = -1;

	ll sum = 0;
	m[0] = -1;
	S[0] = 0;
	K[0] = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'S') {
			sum+=2;
			scnt++;
		}
		else if (str[i] == 'K') {
			sum -= 1;
			kcnt++;
		}
		if (m.find(sum) != m.end()) {
			if (scnt - S[sum] && kcnt - K[sum] >= 2) {
				ans = max(ans, i - m[sum]);
			}
		}
		else {
			m[sum] = i;
			S[sum] = scnt;
			K[sum] = kcnt;
		}
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}