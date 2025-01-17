#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<pair<ll, ll>>v;
    vector<pair<ll, ll>>sw;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
        sw.push_back({ a, 1 });
        sw.push_back({ b, -1 });
    }
    sort(v.begin(), v.end());
    sort(sw.begin(), sw.end());

    bool flag = 0;
    ll bb = -1;
    for (int i = 0; i < n; i++) {
        a = v[i].first;
        b = v[i].second;
        if (b <= bb) {
            flag = 1;
        }
        bb = max(bb, b);
    }


    ll ans = 0;
    ll sum = 0;
    ll bef = sw[0].first;
    ll mgap = 1e9;
    for (auto cur : sw) {
        sum += cur.second;
        if (sum == 0 || (sum == 2 && cur.second == 1)) {
            mgap = min(mgap, cur.first - bef);
        }
        if (!(sum == 1 && cur.second == 1)) {
            ans += cur.first - bef;
        }
        bef = cur.first;
    }
    if (flag) {
        cout << ans << '\n';
    }
    else
        cout << ans - mgap << '\n';
    return 0;
}