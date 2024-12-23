#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, tc,  k, q;
map<ll, ll>m;


void solve() {
    cin >> n;
    vector<ll>v;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll mx = v[n - 1];
    ll ans = 0;
    ll rm = 0;
    for (int i = 0; i < n; i++) {
        ll cur = v[i];
        ll tmp = mx / v[i];
        if (rm >= tmp) {
            rm -= tmp;
        }
        else {
            ans++;
            rm = mx - tmp;
        }
    }

    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}