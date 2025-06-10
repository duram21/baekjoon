#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m, k;

void solve() {
    cin >> n;
    ll cnt = to_string(n).length();
    ll ans = 0;
    while (true) {
        n *= 2;
        ll tmp = to_string(n).length();
        if (tmp > cnt) break;

        ans++;
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