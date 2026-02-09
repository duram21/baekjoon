#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;

void solve() {
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> str;
        ll cnt =  0;
        for(int j = 0 ; j < m; j++){
            if(str[j] == 'O')
                cnt++;
        }
        if(cnt > m / 2) ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}