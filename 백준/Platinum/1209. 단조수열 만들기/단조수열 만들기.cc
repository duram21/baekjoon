#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;
ll dp[2020][2020];
ll arr[2020];
ll A[2020];

void solve() {
    cin >> n;
    vector<ll>v;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        A[i] = arr[i];
    }
    
    sort(A + 1, A + 1 + n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = 1e18;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j - 1], dp[i-1][j] + abs(arr[i] - A[j]));
        }
    }
    ll ans = dp[n][n];

    for(int i = 1; i <= n / 2; i++){
        swap(A[i], A[n-i + 1]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = 1e18;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j - 1], dp[i-1][j] + abs(arr[i] - A[j]));
        }
    }
    ans = min(ans, dp[n][n]);

    cout << ans << '\n';
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}