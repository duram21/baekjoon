#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tc, n, a, b;
ll dp[255][255*255];

void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= 250*250; j++){
            dp[i][j] = 1e5;
        }
    }
    dp[0][0] =0;
    for(int q = 1; q <= n; q++){
        cin >> a >> b;
        for(int i = 0; i <= 250 * 250; i++){
            if(i - a >= 0) dp[q][i] = min(dp[q-1][i-a], dp[q][i]);
            dp[q][i] = min(dp[q][i], dp[q-1][i] + b);
        }
    }
    ll ans = 1e18;

    for(ll i = 0 ; i <= 250 * 250; i++){
        if(dp[n][i] < 1e18){
            ans = min(ans, max(i, dp[n][i]));
        }
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}