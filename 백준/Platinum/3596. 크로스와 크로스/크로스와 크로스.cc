#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, k, p, e, q, cur;
ll dp[2020];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        set<ll>s;
        for(int j = 0 ; j < i ;j++){
            ll l = max(j - 2, 0);
            ll r = max(0, i - j - 3);
            s.insert(dp[l] ^ dp[r]);
        }
        while(s.find(dp[i]) != s.end()) dp[i]++;
    }
    if(dp[n]) cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}