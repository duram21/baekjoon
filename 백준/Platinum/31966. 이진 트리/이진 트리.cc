#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b;
ll ans[101010];
ll lsum[101010];
ll rsum[101010];
ll cnt[101010];
ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ans[0] = cnt[0] = lsum[0] = rsum[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        ans[i] = ans[a] + ans[b] + (cnt[a] * rsum[b]) % mod +  (cnt[b] * lsum[a]) % mod - 1;
        ans[i] %= mod;
        lsum[i] = lsum[b] + cnt[a] + lsum[a] - 1;
        lsum[i] %= mod;
        rsum[i] = rsum[a] + cnt[b] + rsum[b] - 1;
        rsum[i] %= mod;
        cnt[i] = cnt[a] + cnt[b];
        cnt[i] %= mod;
        cout << ans[i] << '\n';
    }
}