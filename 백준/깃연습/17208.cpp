#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;
ll dp[303][303];

void solve(){
    cin >> n >> m >> k;
    for(int ii = 1; ii <= n; ii++){
        cin >> a >> b;
        for(int i = 300 ; i >= 0; i--){
            if(i + a > m) continue;
            for(int j = 300 ; j >= 0; j--){
                if(j + b > k) continue;
                dp[i+a][j+b] = max(dp[i+a][j+b], dp[i][j] + 1);
            }
        }
    }
    cout << dp[m][k] << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
    
}