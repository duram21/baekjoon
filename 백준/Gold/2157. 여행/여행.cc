#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, d;
string str;
ll dp[303][303];

void solve() {
    cin >> n >> m >> k;
    vector<pair<ll, pair<ll,ll>>>v;
    for(int i = 1; i <= k; i++){
        cin >> a >> b >> c;
        v.push_back({a, {b,c}});
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < k; i++){
        a = v[i].first;
        b = v[i].second.first;
        c = v[i].second.second;
        if(a > b) continue;
        for(int j = 1 ; j < m ;j++){
            if(a > 1 && dp[a][j] == 0) continue;
            dp[b][j+1] = max(dp[b][j+1], dp[a][j] + c);
        }
    }
    ll ans = 0;
    for(int i = 2; i <= m; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}