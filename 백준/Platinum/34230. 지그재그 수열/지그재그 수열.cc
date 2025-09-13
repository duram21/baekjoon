#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, q;
string str;
ll arr[5050];
ll dp[5050][5050][2];
ll pre[5050][5050][2];
ll xr[5050];


void solve() {
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> arr[i];
        xr[i] = xr[i-1] ^ arr[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0 ; j < i; j++){
            ll cur = xr[i] ^ xr[j];
            if(j == 0){
                dp[i][cur][0] = max(dp[i][cur][0], 1LL);
                dp[i][cur][1] = max(dp[i][cur][1], 1LL);
            }
            else{
                if(cur && pre[j][cur-1][0]) dp[i][cur][0] = max(dp[i][cur][0], pre[j][cur - 1][0] + 1);
                if(cur + 1 < 4096 && pre[j][cur+ 1][1]) dp[i][cur][1] = max(dp[i][cur][1], pre[j][cur + 1][1] + 1);
            }
        }
        pre[i][0][0] = dp[i][0][1];
        for(int j = 1; j < 4096; j++){
            pre[i][j][0] = max(pre[i][j-1][0], dp[i][j][1]);
        }
        pre[i][4095][1] = dp[i][4095][0];
        for(int j = 4094; j >= 0; j--){
            pre[i][j][1] = max(pre[i][j+1][1], dp[i][j][0]);
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < 4096; i++){
        ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
    }
    cout << n - ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}