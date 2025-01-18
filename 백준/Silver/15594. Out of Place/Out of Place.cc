#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m, k;
ll arr[303030];


void solve() {
    cin >> n;
    vector<ll>v(n + 1);
    vector<ll>tmp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        tmp[i] = v[i];
    }
    sort(tmp.begin(), tmp.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == tmp[i]) continue;
        for (int j = n; j >= i - 1; j--) {
            if (v[j] == tmp[i]) {
                swap(v[j], v[i]);
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}