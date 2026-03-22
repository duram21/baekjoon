#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c;
ll dp[11];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - 1 >= 0) dp[i] += dp[i - 1];
        if (i - 2 >= 0) dp[i] += dp[i - 2];
        if (i - 3 >= 0) dp[i] += dp[i - 3];
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        solve();
    }
}