#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c;
ll arr[101010];
ll A[20202];
ll B[20202];
ll C[20202];

ll func(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > x) continue;
        ll gap = min(C[i], x) - A[i];
        sum += gap / B[i] + 1;
    }
    return sum;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> C[i] >> B[i];
    }
    ll l = 1;
    ll r = 2147483647;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll ret = func(mid);
        if (ret % 2 == 0) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if (l == 2147483648) {
        cout << "NOTHING\n";
    }
    else {
        cout << l << ' ' << func(l) - func(l-1) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}