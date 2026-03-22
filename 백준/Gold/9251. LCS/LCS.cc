#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c;

ll dp[1010][1010];
string s, t;
void solve() {
	cin >> s >> t;
	for (int i = 0; i <= s.length(); i++) {
		for (int j = 0; j <= t.length(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j <= t.length(); j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}