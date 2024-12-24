#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, d, a, b, c, tc,  k, q;
ll arr[202020];

void solve() {
    cin >> q >> m;
    ll x = 1;
    ll y = 2;
    string ans = "1";
    while (!(x == 1 && y == 1)) {
        ans += to_string(x);
        ll tmp = (x + y) % m;
        x = y; y = tmp;
    }
    ll len = ans.length();
    while (q--) {
        cin >> a;
        cout << ans[(a - 1) % len] << '\n';
    }
}

int main(void) { 
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;

    //cin >> tc;
    while (tc--) {
        solve();
    }
}