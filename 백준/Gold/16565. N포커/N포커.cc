#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b;
ll c[60][60];
ll mod = 1e4 + 7;


void solve() {
    cin >> n;

    for (int i = 0; i <= 52; i++) c[i][0] = 1;
    for (int i = 1; i <= 52; i++) {
        for (int j = 1; j <= 52; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 13; i++) {
        if (i * 4 > n) break;
        if (i % 2) {
            ans += c[13][i] * c[52 - 4 * i][n - i * 4];
            ans %= mod;
        }
        else {
            ans -= (c[13][i] * c[52 - 4 * i][n - i * 4]) % mod;
            ans += mod;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}