#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tc, n, a, b;
ll dp[2][1001*101];
void solve(){
    cin >> n;
    for(int i = 0; i < 2; i++){
        for(int j = 0 ; j <= 1000*100; j++){
            dp[i][j] = 1e8;
        }
    }
    dp[0][0] =0;
    for(int q = 1; q <= n; q++){
        cin >> a >> b;
        for(int i = 0; i <= 1000 * 100; i++){
            if(i - a >= 0) dp[1][i] = min(dp[0][i-a], dp[1][i]);
            dp[1][i] = min(dp[1][i], dp[0][i] + b);
        }
        for(int j = 0 ; j <= 1000*100; j++){
            dp[0][j] = dp[1][j];
            if(q != n){
                dp[1][j] = 1e8;
            }
        }
    }
    ll ans = 1e18;
    for(ll i = 0 ; i <= 1000 * 100; i++){
        ans = min(ans, max(i, dp[1][i]));
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> tc;
    while(tc--){
        solve();
    }
}