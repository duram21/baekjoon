#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w;
string str, sss;


void solve() {
	cin >> str;
	ll len = str.length();
	cin >> n;
	bitset<100001>bs[26];
	for (int i = 0; i < len; i++) {
		bs[str[i] - 'a'][i] = 1;
	}
	while (n--) {
		cin >> sss;
		char s, t;
		string tmp;
		s = sss[0];
		t = sss[sss.length() - 1];
		tmp = sss.substr(1, sss.length() - 2);
		ll num = stoll(tmp);
		ll ans = ((bs[s - 'a'] << (num + 1)) & bs[t - 'a']).count();
		cout << ans << '\n';
	}
} 


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}