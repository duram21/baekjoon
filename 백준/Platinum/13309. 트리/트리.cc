#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
ll sz[201010];
ll dep[201010];
ll par[201010];
ll top[201010];
ll in[201010];
ll out[201010];
vector<ll>v[201010];
ll tree[201010 * 4];

void update(ll st, ll en, ll node, ll idx, ll val) {
    if (idx < st || en < idx) return;
    if (st == en) {
        tree[node] = val;
        return;
    }
    ll mid = (st + en) >> 1;
    update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll st, ll en, ll node, ll l, ll r) {
    if (en < l || st > r) {
        return 0;
    }
    if (l <= st && en <= r) {
        return tree[node];
    }
    ll mid = (st + en) >> 1;
    return (query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r));
}


void dfs1(ll x, ll p) {
    sz[x] = 1;
    for (auto &nxt : v[x]) {
        if (nxt == p) continue;
        ll a = nxt;
        dep[a] = dep[x] + 1;
        par[a] = x;
        dfs1(a, x);
        sz[x] += sz[a];
        if (sz[a] > sz[v[x][0]]) swap(nxt, v[x][0]);
    }
}

ll deg;

void dfs2(ll x, ll p) {
    in[x] = ++deg;
    for (auto nxt : v[x]) {
        if (p == nxt) continue;
        top[nxt] = nxt == v[x][0] ? top[x] : nxt;
        dfs2(nxt, x);
    }
    out[x] = deg;
}

ll lca(ll x, ll y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = par[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
}

ll func(ll x, ll y) {
    ll sum = 0;
    ll LCA = lca(x, y);
    ll val = dep[x] + dep[y] - 2 * dep[LCA];
    while (top[x] != top[y]) {
        if (dep[top[y]] > dep[top[x]]) {
            swap(x, y);
        }
        sum += query(1, n, 1, in[top[x]], in[x]);
        x = par[top[x]];
    }
    if (dep[y] > dep[x]) swap(x, y);
    sum += query(1, n, 1, in[y] + 1, in[x]);
    if (sum == val) return 1;
    else return 0;
}



void solve() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        v[a].push_back(i);
    }
    dfs1(1, -1);
    dfs2(1, -1);

    // root 1이라고 생각
    for (int i = 2; i <= n; i++) {
        update(1, n, 1, i, 1);
    }

    while (m--) {
        cin >> a >> b >> c;
        bool flag = func(a, b);
        if (flag) cout << "YES\n";
        else cout << "NO\n";
        if (c && flag) {
            update(1, n, 1, a, 0);
        }
        else if(c && !flag) {
            update(1, n, 1, b, 0);
        }
    }
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