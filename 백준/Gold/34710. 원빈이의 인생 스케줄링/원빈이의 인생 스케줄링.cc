#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, m, st, en, q, k;
string str;
ll T[202020];
ll L[202020];
ll val[202020];

bool cmp(pair<ll, ll>A, pair<ll, ll>B) {
    if (A.first != B.first) {
        return A.first < B.first;
    }
    else {
        return A.second > B.second;
    }
}

void solve() {
    cin >> n;
    vector < pair<ll, ll>>v;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> L[i];
        v.push_back({ T[i], L[i] });
    }
    sort(v.begin(), v.end(), cmp);
    bool flag = 1;
    ll mx = -1;
    ll bef = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].first < v[i].second) {
            flag = 0;
            break;
        }
        bef = v[i].first;
        if (i == n - 1) continue;
        mx = v[i + 1].second;
        ll gap = v[i + 1].first - v[i].first;
        v[i].second = max(v[i].second, mx - gap);
        mx = max(mx, v[i].second);
    }
    mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, v[i].second);
        v[i].second = mx;
    }
    if (!flag) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += v[i].first - v[i].second;
    }
    cout << ans << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;  
    // cin >> tc;
    while (tc--) solve();
}