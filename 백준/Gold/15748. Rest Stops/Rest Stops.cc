#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y;
ll l;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> n >> x >> y;
    vector<pair<ll, ll>>v;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.push_back({ b, a });
    }
    sort(v.rbegin(), v.rend());

    ll ans = 0;
    ll idx = 0;
    for (int i = 0; i < n; i++) {
        a = v[i].second;
        b = v[i].first;
        if (idx > a) continue;
        ans += (a - idx) * (x - y) * b;
        idx = a;
    }
    cout << ans << '\n';
    return 0;
}