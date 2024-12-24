#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, d, a, b, c, tc,  k, q;
ll arr[202020];
ll l, r, g;

ll gcd(ll x, ll y) {
    if (!y) return x;
    return (y, x % y);
}

void solve() {
    cin >> l >> r >> g;
    ll a1 = (l + g-1) / g;
    ll a2 = (r) / g;
    ll aa = a1, bb = a2;
    ll dist = 0;
    ll ans1, ans2;
    if ((a1 % 2 == 0 && a2 % 2 == 0)) {
        ans1 = aa; ans2 = bb - 1;
    }
    if ((a1 % 2 == 1 && a2 % 2 == 1)) {
        ans1 = aa; ans2 = bb - 1;
    }
        while (true) {
            
        }

    cout << a1 << ' ' << a2 << '\n';
}

int main(void) { 
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}