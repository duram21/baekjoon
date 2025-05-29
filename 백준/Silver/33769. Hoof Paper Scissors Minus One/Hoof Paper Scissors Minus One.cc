#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m;
bool chk[3030][3030];

void solve() {
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= i; j++) {
			if (str[j - 1] == 'W') {
				chk[i][j] = 1;
			}
			else if(str[j-1] == 'L'){
				chk[j][i] = 1;
			}
		}
	}
	while (m--) {
		cin >> a >> b;
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i][a] && chk[i][b]) {
				cnt++;
			}
		}
		cout << n * n - (n - cnt) * (n - cnt) << '\n';
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