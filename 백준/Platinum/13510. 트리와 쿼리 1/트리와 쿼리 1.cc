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
ll out[101010];
vector<pair<ll, ll>>v[101010];
pair<pair<ll, ll>, ll> arr[101010];
ll tree[101010 * 4];

void update(ll st, ll en, ll node, ll idx, ll val) {
    if (idx < st || en < idx) return;
    if (st == en) {
        tree[node] = val;
        return;
    }
    ll mid = (st + en) >> 1;
    update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll query(ll st, ll en, ll node, ll l, ll r) {
    if (en < l || st > r) {
        return 0;
    }
    if (l <= st && en <= r) {
        return tree[node];
    }
    ll mid = (st + en) >> 1;
    return max(query(st, mid, node * 2, l, r), query(mid + 1, en, node * 2 + 1, l, r));
}


void dfs1(ll x, ll p) {
    sz[x] = 1;
    if (v[x][0].first == p) swap(v[x][0], v[x].back());
    for (auto &nxt : v[x]) {
        if (nxt.first == p) continue;
        ll a = nxt.first;
        ll b = nxt.second;
        dep[a] = dep[x] + 1;
        par[a] = x;
        dfs1(a, x);
        sz[x] += sz[a];
        if (sz[a] > sz[v[x][0].first]) swap(nxt, v[x][0]);
    }
}

ll deg;

void dfs2(ll x, ll p) {
    in[x] = ++deg;
    for (auto nxt : v[x]) {
        if (p == nxt.first) continue;
        top[nxt.first] = nxt.first == v[x][0].first ? top[x] : nxt.first;
        dfs2(nxt.first, x);
    }
    out[x] = deg;
}

ll func(ll x, ll y) {
    ll ret = 0;
    while (top[x] != top[y]) {
        if (dep[top[y]] > dep[top[x]]) {
            swap(x, y);
        }
        ret = max(ret, query(1, n, 1, in[top[x]], in[x]));
        x = par[top[x]];
    }

    if (dep[y] > dep[x]) swap(x, y);
    ret = max(ret, query(1, n, 1, in[y] + 1, in[x]));
    return ret;
}


void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
        arr[i] = { {a, b}, c };
    }
    dfs1(1, -1);
    dfs2(1, -1);


    for (int i = 1; i < n; i++) {
        if (arr[i].first.first == par[arr[i].first.second]) {
            swap(arr[i].first.first, arr[i].first.second);
        }
        update(1, n, 1, in[arr[i].first.first], arr[i].second);
    }

    cin >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, n, 1, in[arr[b].first.first], c);
        }
        else {
            cout << func(b, c) << '\n';
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