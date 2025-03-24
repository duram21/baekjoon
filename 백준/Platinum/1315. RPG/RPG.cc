#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c;
ll dp[1010][1010];
ll STR[1010];
ll INT[1010];
ll PNT[1010];
ll ans = 0;

void func(ll x, ll y) {
    ll& ret = dp[x][y];
    if (ret != -1) return;
    ll cnt = 0;
    ll point = 0;
    for (int i = 1; i <= n; i++) {
        if (STR[i] <= x || INT[i] <= y) {
            cnt++;
            point += PNT[i];
        }
    }
    //cout << x << ' ' << y  << ' ' << cnt <<  ' ' << point << '\n';
    
    point -= x + y - 2;
    if (point < 0) {
        ret = 0;
        return;
    }

    ans = max(ans, cnt);
    ret = 1;

    for (int i = x; i <= min((ll)1000, x + point); i++) {
        ll j = min((ll)1000, y + point - (i - x));
        func(i, j);
    }

}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> STR[i] >> INT[i] >> PNT[i];
    }
    memset(dp, -1, sizeof(dp));
    func(1, 1);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}