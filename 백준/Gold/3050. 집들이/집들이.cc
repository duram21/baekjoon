#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, q, m, k;
ll graph[404][404];
ll sum[404][404];


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            graph[i][j] = str[j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (graph[i][j] == '.') {
                sum[i][j] = sum[i][j - 1] + 1;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (graph[i][j] == 'X') continue;
            ll cnt = 1;
            ll mn = 987654321;
            for (int k = i; k >= 1; k--) {
                if (graph[k][j] == 'X') break;
                mn = min(mn, sum[k][j]);
                ans = max(ans, (cnt + mn) * 2);
                cnt++;
            }
        }
    }
    cout << ans - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}