#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, q, m, k;
vector<ll>edges[101010];
ll dp[101010][2];

void dfs(ll x, ll par) {
    for (ll nxt : edges[x]) {
        if (nxt == par) continue;
        dfs(nxt, x);
        dp[x][1] += dp[nxt][0];
        dp[x][0] += min(dp[nxt][0], dp[nxt][1]);
    }
    dp[x][0]++;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);

    cout << min(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}