#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, q, m;

void solve() {
    cin >> n >> m;
    cin >> a >> b;
    cin >> c >> d;
    if ((a +b) % 2== (c+d) % 2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}