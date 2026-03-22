#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, d, r, q;
string str;
ll arr[1010101];
ll mod = 1e9 + 7;
ll dp[1010101];
ll tmp[1010101];


void solve() {
    cin >> n >> q;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }
    for(int i = 1; i <= q; i++){
        cin >>a >> b;
        arr[a] += 1;
        tmp[b+1] += dp[b - a + 2];
        tmp[b+1] %= mod;
        tmp[b+2] += dp[b-a + 1];
        tmp[b+2] %= mod;
    }

    for(int i = 1; i <= n; i++){
        arr[i] += arr[i-1] + arr[i-2];
        arr[i] = (arr[i] - tmp[i] + mod) % mod;
        cout << arr[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}