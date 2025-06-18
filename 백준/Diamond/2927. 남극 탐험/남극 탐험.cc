#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
string str;
ll sz[101010];
ll dep[101010];
ll par[101010];
ll top[101010];
ll in[101010];
ll rin[101010];
ll out[101010];
vector<ll>v[101010];
ll tree[101010 * 4];
ll arr[30303];
ll parent[30303];

ll find(ll x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

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
    return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
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
    ll ret = 0;
    while (top[x] != top[y]) {
        if (dep[top[y]] > dep[top[x]]) {
            swap(x, y);
        }
        ret += query(1, n, 1, in[top[x]], in[x]);
        x = par[top[x]];
    }
    if (dep[y] > dep[x]) swap(x, y);
    ret += query(1, n, 1, in[y], in[x]);
    return ret;
}



void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        parent[i] = i;
    }


    cin >> m;
    vector<pair<string, pair<ll, ll>>>q;
    for(int i  = 1; i <= m; i++){
        cin >> str >> a >> b;
        q.push_back({ str, {a, b} });
        if (str == "bridge") {
            ll A = find(a);
            ll B = find(b);
            if (A == B) continue;
            v[a].push_back(b);
            v[b].push_back(a);
            parent[A] = B;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!sz[i]) {
            top[i] = i;
            dep[i] = 1;
            dfs1(i, -1);
            dfs2(i, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        update(1, n, 1, in[i], arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        str = q[i].first;
        a = q[i].second.first;
        b = q[i].second.second;

        if (str == "bridge") {
            ll A = find(a);
            ll B = find(b);
            if (A == B) {
                cout << "no\n";
            }
            else {
                cout << "yes\n";
                parent[A] = B;
            }
        }
        else if (str == "penguins") {
            update(1, n, 1, in[a], b);
        }
        else {
            ll A = find(a);
            ll B = find(b);
            if (A != B) {
                cout << "impossible\n";
                continue;
            }
            cout << func(a, b) << '\n';
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