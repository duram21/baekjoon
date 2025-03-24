#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c;
ll arr[55];
ll dp[55][500005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        a = arr[i];
        for (int j = 0; j <= 250000; j++) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            // 큰 쪽에 놓으면 
            if (a + j <= 250000) {
                dp[i][a + j] = max({ dp[i][j + a], dp[i-1][j] + a});
            }
            // 작은 쪽에 놓으면
			if (j >= a) {
				dp[i][j - a] = max({ dp[i][j - a], dp[i - 1][j] });
			}
			else if (j < a) {
                dp[i][a - j] = max({ dp[i][a - j], dp[i - 1][j] -j + a });
			}
		}

    }
    if (dp[n][0]) cout << dp[n][0] << '\n';
    else cout << -1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}