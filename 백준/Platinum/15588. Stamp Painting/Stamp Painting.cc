#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m, k;
ll dp[3030303];
ll mod = 1e9 + 7;
ll p[3030303];

void solve() {
    cin >> n >> m >> k;
    p[1] = m;
    for (int i = 2; i <= n; i++) {
        p[i] = p[i - 1] * m % mod;
    }

    // dp[i-k+1] ~ dp[i-1]
    dp[k] = m;
    ll tot = m;


    for (int i = k + 1; i <= n; i++) {
        dp[i] = p[i - k + 1];
        dp[i] = (dp[i] + tot * (m-1) % mod) % mod;
        tot += dp[i] - dp[i - k + 1];
        tot %= mod;
    }
    cout << dp[n] << '\n';

}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}