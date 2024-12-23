#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, tc,  k, q;
ll A[201010];
ll B[201010];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    ll mn = 0;
    ll mx = 0;
    for (int i = 1; i <= n - 2; i++) {
        mx += max(A[i], B[i]);
        mn += min(A[i], B[i]);
    }
    ll ans = 0;
    A[n] += B[n - 1];
    B[n] += A[n - 1];
    ans = mx - mn + abs(A[n] - B[n]);
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