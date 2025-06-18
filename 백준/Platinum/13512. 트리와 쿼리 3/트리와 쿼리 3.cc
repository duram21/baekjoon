#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
ll sz[101010];
ll dep[101010];
ll par[101010];
ll top[101010];
ll in[101010];
ll rin[101010];
ll out[101010];
vector<ll>v[101010];
ll tree[101010 * 4];
bool color[101010];

void update(ll st, ll en, ll node, ll idx, ll val) {
    if (idx < st || en < idx) return;
    if (st == en) {
        tree[node] = val;
        return;
    }
    ll mid = (st + en) >> 1;
    update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

ll query(ll st, ll en, ll node, ll l, ll r) {
    if (en < l || st > r) {
        return 1e12;
    }
    if (l <= st && en <= r) {
        return tree[node];
    }
    ll mid = (st + en) >> 1;
    return min(query(st, mid, node * 2, l, r), query(mid + 1, en, node * 2 + 1, l, r));
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

ll func(ll x, ll y) {
    ll ret = 1e12;
    while (top[x] != top[y]) {
        if (dep[top[y]] > dep[top[x]]) {
            swap(x, y);
        }
        ret =  min(ret, query(1, n, 1, in[top[x]], in[x]));
        x = par[top[x]];
    }
    if (dep[y] > dep[x]) swap(x, y);
    ret =  min(ret, query(1, n, 1, in[y], in[x]));
    return ret;
}



void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs1(1, -1);
    top[1] = 1;
    dfs2(1, -1);

    // root 1이라고 생각
    for (int i = 1; i <= n; i++) {
        update(1, n, 1, in[i], 1e12);
    }
    for (int i = 1; i <= n; i++) {
        rin[in[i]] = i;
    }
    cin >> m;

    while (m--) {
        cin >> a >> b;
        if (a == 1) {
            if (color[b] == 0) {
                color[b] = 1;
                update(1, n, 1, in[b], in[b]);
            }
            else {
                color[b] = 0;
                update(1, n, 1, in[b], 1e12);
            }
        }
        else {
            ll res = func(1, b);
            if (res == 1e12) cout << -1 << '\n';
            else cout << rin[res] << '\n';
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