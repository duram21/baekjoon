#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, d, a, b, c, tc,  k, q;
ll arr[202020];

void solve() {
    cin >> n >> m;
    vector<pair<ll, ll>>v;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.push_back({ a, m });
    }
    for (int i = 1; i <= m; i++) {
        cin >> a;
        v.push_back({ a, n });
    }
    sort(v.begin(), v.end());
    ll val = -n * m;
    for (int i = 0; i < v.size(); i++) {
        val += v[i].second;
        if (val >= 0) {
            cout << (double)v[i].first << '\n';
            return;
        }
    }
}

int main(void) { 
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
            cout.precision(1);
            cout << fixed;

    cin >> tc;
    while (tc--) {
        solve();
    }
}