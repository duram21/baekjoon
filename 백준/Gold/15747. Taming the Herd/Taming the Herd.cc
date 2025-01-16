#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y;
ll  arr[303];
ll dp[110][110][110];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if(arr[i] == 0) dp[i][i][1] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[i][i + j][1] = dp[i][j + i - 1][1];
            if (j == arr[i + j]) dp[i][j + i][1]++;
        }
    }
    for (int q = 2; q <= n; q++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j + i <= n; j++) {
                for (int k = i + q - 2; k < i + j; k++) {
                    dp[i][i + j][q] = max(dp[i][i + j][q], dp[i][k][q - 1] + dp[k + 1][i + j][1]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << n - dp[1][n][i] << '\n';
    }
    return 0;
}