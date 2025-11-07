#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, m, st, en, q;
ll dp[101010][2];
ll A[101010];
ll B[101010];
ll fact[101];
ll mod = 1e9 + 7;

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> A[i] >> B[i];
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(B[i]){ // 다른 춤
            dp[i][0] = dp[i-1][0] * (m - 1) % mod;
            dp[i][1] = dp[i-1][0];
            dp[i][1] += dp[i-1][1] * (m-1);
            dp[i][1] %= mod;
            
        }
        else{ // 같은 춤
            dp[i][1] = dp[i-1][0] * (m - 1) % mod;
            dp[i][1] += dp[i-1][1];
            dp[i][1] %= mod;
            dp[i][0] = dp[i-1][0];
        }
    }
    ll ans = dp[n][1] + dp[n][0];
    cout << ans % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}