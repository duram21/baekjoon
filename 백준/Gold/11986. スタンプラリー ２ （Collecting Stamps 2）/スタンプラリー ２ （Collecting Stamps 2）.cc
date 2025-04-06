#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;
string JOI = "JOI";
ll psum[101010][3];
ll psum2[101010][3];


void solve() {
	cin >> n;
	cin >> str;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			psum[i][j] = psum[i - 1][j];
			if (str[i - 1] == JOI[j]) {
				if (j == 0) {
					psum[i][j] ++;
				}
				else {
					psum[i][j] += psum[i - 1][j - 1];
				}
			}
		}
	}
	for (int i = n; i >=1; i--) {
		for (int j = 0; j < 3; j++) {
			psum2[i][j] = psum2[i + 1][j];
			if (str[i - 1] == JOI[j]) {
				if (j == 2) {
					psum2[i][j] ++;
				}
				else {
					psum2[i][j] += psum2[i + 1][j + 1];
				}
			}
		}
	}

	ll ans = psum[n][2];
	ll mx = -1;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2) {
				mx = max(mx, psum[i][1]);
			}
			if (j == 1) {
				mx = max(mx, psum[i][0] * psum2[i][2]);
			}
			if (j == 0) {
				mx = max(mx, psum2[i][1]);
			}
		}
	}
	cout << ans + mx << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}