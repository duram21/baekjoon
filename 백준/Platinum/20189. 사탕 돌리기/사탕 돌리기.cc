#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, tc,  k, q;
ll A[2020];
ll B[2020];


void solve() {
    cin >> n >> k >> q;
    ll tot = 0;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a;
            if (i == 1 && a != 1) flag = 0;
            if (i < a) {
                tot += (a - i);
            }
            else if(i > a){
                tot += n - (i - a);
            }
        }
    }
    if (flag) tot += n;
    ll ans = (tot) / n;
    //cout << tot << '\n';
    if (ans <= q) cout << 1 << '\n';
    else cout << 0 << '\n';
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}