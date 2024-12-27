#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
int arr[2020];
int dp[2020][2020];

int solve(int i, int j) {
    if (i >= n || j >= n) return 0;
    int& ret = dp[i][j];
    if (ret != -1) return ret;
    int nxt = max(i, j) + 1;

    ret = 1e9;

    ret = min(solve(i, nxt) + (j != 0 ? abs(arr[j] - arr[nxt]) : 0), solve(nxt, j) + (i != 0 ? abs(arr[i] - arr[nxt]) : 0));

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
}