#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, m, k;
string str;
ll mod = 998244353;
ll dp[5030][3030];

void init(){
    dp[0][0] = 1;
    for(int i = 1; i <= 5000; i++){
        for(int j = 0 ; j <= 2500; j++){
            // PP 한 경우
            if(i - 2 >= 0){
                dp[i][j + 1 ] += dp[i-2][j];
                dp[i][j + 1] %= mod;
            }
            // p 한경우
            if(i - 1 >=0 && j){
                dp[i][j-1] += dp[i-1][j];
                dp[i][j-1] %= mod;
            }
        }
    }

}

void solve() {
    cin >> n;
    ll ans = 0;
    for(int i = 0; i <= 3000; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    if(ans == 0){
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    init();
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}