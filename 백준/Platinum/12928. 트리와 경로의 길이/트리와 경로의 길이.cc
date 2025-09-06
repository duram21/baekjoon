#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, s;
string str;
ll dp[55][1010];

void solve() {
    cin >> n >> s;
    dp[0][0] = 1;

    for(int i = 1; i <= n - 2; i++){
        for(int j = 0 ; j <= s; j++){
            for(int k = 1; k <= i && k * (k + 1) / 2 <= j; k++){
                dp[i][j] |= dp[i-k][j - k*(k + 1) / 2];
            }
        }
    }
    if(n <= 2){
        cout << 0 << '\n';
    }
    else cout << dp[n-2][s] << '\n';
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}