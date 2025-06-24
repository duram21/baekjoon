#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = unsigned int;

ll n, a, b, c, d, f, k, p, e, q, cur;
ll P[501010];
ll C[501010];
map<ll, ll>m[501010];
set<ll>s[501010];
ll num[501010];
ll chk[501010];

pair<ll, ll>lazy[501010 * 4];
ll tree[501010 * 4];
ll arr[501010];

void Lazy(ll st, ll en, ll node) {
	ll a1 = lazy[node].first;
	ll b1 = lazy[node].second;
	if (a1 == 1 && b1 == 0) return;
	
	if (st != en) {
		ll a2 = lazy[node * 2].first;
		ll b2 = lazy[node * 2].second;
		lazy[node * 2].first = a2 * a1;
		lazy[node * 2].second = a1 * b2 + b1;


		a2 = lazy[node * 2 + 1].first;
		b2 = lazy[node * 2 + 1].second;
		lazy[node * 2 + 1].first = a2 * a1;
		lazy[node * 2 + 1].second = a1 * b2 + b1;

	}
	tree[node] = a1 * tree[node] + b1 * (en - st + 1);
	lazy[node] = { 1, 0 };
	return;
}

void update(ll st, ll en, ll node, ll l, ll r, ll a, ll b) {
	Lazy(st, en, node);
	if (en < l || r < st) return;
	if (l <= st && en <= r) {
		ll a1 = lazy[node].first;
		ll b1 = lazy[node].second;
		lazy[node].first = a1 * a;
		lazy[node].second = a * b1 + b;
		Lazy(st, en, node);
		return;
	}
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, l, r, a, b);
	update(mid + 1, en, node * 2 + 1, l, r, a, b);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll st, ll en, ll node, ll l, ll r) {
	Lazy(st, en, node);
	if (en < l || r < st)return 0;
	if (l <= st && en <= r) {
		return tree[node];
	}
	ll mid = (st + en) >> 1;
	return (sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r));
}

vector<ll>v[505050];
ll sz[505050];
ll dep[505050];
ll top[505050];
ll par[505050];
ll in[505050];
ll out[505050];

void dfs1(ll x, ll p){
    sz[x] = 1;
    if(v[x].empty()) return;
    if(v[x][0] == p) swap(v[x][0], v[x].back());
    for(auto &nxt : v[x]){
        if(nxt == p) continue;
        ll a = nxt;
        dep[a] = dep[x] + 1;
        par[a] = x;
        dfs1(a, x);
        sz[x] += sz[a];
        if(sz[a] > sz[v[x][0]]) swap(nxt, v[x][0]);
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
        ret += sum(1, n, 1, in[top[x]], in[x]);
        x = par[top[x]];
    }
    if (dep[y] > dep[x]) swap(x, y);
    ret += sum(1, n, 1, in[y], in[x]);

    return ret;
}

void query(ll x, ll y, ll a, ll b){
    while(top[x] != top[y]){
        if(dep[top[y]] > dep[top[x]]){
            swap(x, y);
        }
        update(1, n, 1, in[top[x]], in[x], a, b);
        x = par[top[x]];
    }
    if (dep[y] > dep[x]) swap(x, y);
    update(1, n, 1, in[y], in[x], a, b);
}

void solve() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    top[1] = 1;
    dep[1] = 1;
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 0; i <= 4 * n ; i++){
        lazy[i] = {1, 0};
    }
    while(q--){
        ll op;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            update(1, n, 1, in[a], out[a], 1, b);
        }
        else if(op == 2){
            cin >> a >> b >> c;
            query(a, b, 1, c);
        }
        else if(op == 3){
            cin >> a >> b;
            update(1, n, 1, in[a], out[a], b, 0);
        }
        else if( op == 4){
            cin >> a >> b >> c;
            query(a, b, c, 0);
        }
        else if(op == 5){
            cin >> a;
            cout << sum(1, n, 1, in[a], out[a]) << '\n';
        }
        else if(op == 6){
            cin >> a >> b;
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