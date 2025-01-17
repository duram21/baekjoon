#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m, k;
vector<ll>edges[101010];
bool visited[101010];
ll dist[101010];
ll ans;

void dfs(ll x, ll par, ll d) {
    visited[x] = 1;
    if (edges[x].size() == 1) {
        ans++;
        return;
    }
    if (d >= dist[x]) {
        ans++;

        return;
    }
    for (ll nxt : edges[x]) {
        if (nxt == par) continue;
        dfs(nxt, x, d + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    queue<pair<ll, ll>>q;
    for (int i = 1; i <= n; i++) {
        if (edges[i].size() == 1) {
            q.push({ i, 0 });
            visited[i] = 1;
        }
    }
    while (q.size()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();
        dist[a] = b;
        for (ll nxt : edges[a]) {
            if (visited[nxt]) continue;
            q.push({ nxt, b + 1 });
            visited[nxt] = 1;
        }
    }
    memset(visited, 0, sizeof(visited));
    dfs(k, 0, 0);
    cout << ans << '\n';

    return 0;
}