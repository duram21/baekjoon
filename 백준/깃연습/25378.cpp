#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;
ll arr[2555];
ll dp[2555];
bool chk[2555][2555];


void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i] = 1e9;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i], dp[i-1] + 1);
        ll rm = arr[i];
        for(int j = i + 1; j <= n; j++){
            rm = arr[j] - rm;
            if(rm < 0) break;
            if(rm == 0){
                dp[j] = min(dp[j], dp[i - 1] + j - i);
                break;
            }
            if(rm > 0){
                //dp[j] = min(dp[j], dp[j-2] + 1);
            } 
        }
    }
    cout << dp[n] << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}