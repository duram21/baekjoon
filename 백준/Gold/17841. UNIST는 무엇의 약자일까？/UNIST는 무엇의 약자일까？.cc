#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d, k, l, r, x, p, m;
ll cnt[10][10];
string unist = "UNIST";
ll dp[10];
ll mod = 1e9 + 7;


void solve() {
	cin >> n;
	string str;
		dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str += "ㅋㅋㅋㅋㅋ";
		for (int st = 0; st < 5; st++) {
			ll idx = 0;
			ll en = st;
			for (en = st; en < 5; en++) {
				if (str[idx] == unist[en]) {
					idx++;
				}
				else {
					break;
				}
			}
			if (idx == 0) continue;
			for (int k = 1; k <= idx; k++) {
				cnt[st + 1][st + k]++;
				dp[st + k] += dp[st];
				
			}
			for (int k = 1; k <= 5; k++) {
				dp[k] %= mod;
			}
		}
	}


	cout << dp[5] << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}