#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, x, m, k, d;
ll arr[101010];
ll cnt[30];

void solve() {
    cin >> n;
    bool flag = 0;
    set<ll>s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
        if (!arr[i]) flag = 1;
    }
    if (flag) {
        cout << 3 * n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << 0 << ' ' << arr[i] << ' ' << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    memset(cnt, 0, sizeof(cnt));
    ll cur = arr[1];
    for (int i = 1; i <= n; i++) {
        cur &= arr[i];
    }
    if (s.find(cur) != s.end()) {
        cout << 3 * n << '\n';

        for (int i = 1; i <= n; i++) {
            cout << cur << ' ' << arr[i] << ' ' << cur << ' ';
        }
        cout << '\n';
    }
    else cout << -1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}