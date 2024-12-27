#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, w;
ll arr[5050];
ll dp[800000];

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[i] + arr[j] > w) continue;
            if (dp[w - arr[i] - arr[j]]) {
                cout << "YES\n";
                return 0;
            }
        }
        for (int j = 1; j < i; j++) {
            if (arr[i] + arr[j] < w) {
                dp[arr[i] + arr[j]] = 1;
            }
        }
    }
    cout << "NO\n";
    return 0;
}