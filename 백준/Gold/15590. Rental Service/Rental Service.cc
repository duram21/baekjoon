#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    vector<ll>N(n );
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> N[i];
        tot += N[i];
    }
    sort(N.begin(), N.end());
    vector<pair<ll, ll>>v;
    vector<ll>sum(m + 1), cnt(m + 1);
    vector<ll>R(r + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        v.push_back({ b, a });
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < m; i++) {
        sum[i + 1] = sum[i] + v[i].first * v[i].second;
        cnt[i + 1] = cnt[i] + v[i].second;
    }
    

    for (int i = 1; i <= r; i++) {
        cin >> R[i];
    }
    sort(R.rbegin(), R.rend());

    ll ans = 0;
    ll val = 0;

    ll idx = lower_bound(cnt.begin(), cnt.end(), tot) - cnt.begin();
    ll tmp;
    if (idx == m + 1) {
        tmp = sum[idx - 1];
    }
    else {
        tmp = sum[idx - 1] + (tot - cnt[idx - 1]) * v[idx - 1].first;
    }
    ans = tmp;

    for (int i = 0; i < min(n, r); i++) {
        tot -= N[i];
        val += R[i];
        ll idx = lower_bound(cnt.begin(), cnt.end(), tot) - cnt.begin();
        ll tmp;
        if (idx == m + 1) {
            tmp = sum[idx - 1];
        }
        else {
            tmp = sum[idx - 1] + (tot - cnt[idx - 1]) * v[idx - 1].first;
        }
        ans = max(ans, tmp + val);
    }
    cout << ans << '\n';

    return 0;
}