#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q;
vector<pair<ll, ll>>v[5050];
ll val[5050][5050];
bool visited[5050];

void bfs(ll x) {
    queue<pair<ll, ll>>q;
    q.push({ x, 1e9 });
    visited[x] = 1;
    while (q.size()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();
        val[x][a] = b;
        for (auto nxt : v[a]) {
            if (visited[nxt.first]) continue;
            visited[nxt.first] = 1;
            q.push({ nxt.first, min(nxt.second, b) });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) val[i][j] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        bfs(i);
    }

    while (q--) {
        cin >> a >> b;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (val[b][i] >= a) ans++;
        }
        cout << ans - 1<< '\n';
    }
    return 0;
}