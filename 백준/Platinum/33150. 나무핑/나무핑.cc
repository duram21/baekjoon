#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k, q;
string str;
ll dist[202020];
ll arr[202020];
ll parent[202020][23];
ll dep[202020];
vector<ll>tree[200202];

void dfs(int node, int par) {
    dep[node] = dep[par] + 1;
    for (ll nxt : tree[node]) {
        if (nxt == par) continue;
        parent[nxt][0] = node;
        dfs(nxt, node);
    }
}

void get_dist(ll x, ll val) {
    dist[x] = val;
    for (auto nxt : tree[x]) {
        get_dist(nxt, dist[x] + arr[nxt]);
    }
}


int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 22; i >= 0; i--) {
        if (dep[y] - dep[x] >= (1 << i)) y = parent[y][i];
    }
    if (x == y) return x;
    for (int i = 22; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

ll cal_dist(ll x, ll y) {
    ll tmp = lca(x, y);
    return dist[x] - dist[tmp] + dist[y] - dist[tmp];
}

void solve() {
    cin >> n;
    vector<pair<ll, ll>>query;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        arr[i + 1] = b;
        query.push_back({ a, b });
        tree[a].push_back(i + 1);
    }
    get_dist(1, 0);
    dfs(1, 0);

    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= n + 1; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }


    ll d1 = 1;
    ll d2 = 1;
    ll mx = cal_dist(d1, d2);
    for (int i = 0; i < n; i++) {
        a = query[i].first;
        b = query[i].second;
           
        ll t1 = cal_dist(d1, i + 2);
        ll t2 = cal_dist(d2, i + 2);

        // case 1
        if (t1 > t2) {
            if (mx < t1) {
                mx = t1;
                d2 = i + 2;
            }
        }
        // case 2
        else {
            if (mx < t2) {
                mx = t2;
                d1 = i + 2;
            }

        }
        cout << mx << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
};