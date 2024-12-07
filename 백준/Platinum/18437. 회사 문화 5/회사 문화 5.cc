#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll tc, n, a, b, c, k, m, q;
ll tree[101010 * 4];
ll lazy[101010 * 4];
vector<ll>v[101010];

void init(ll st, ll en, ll node){
    lazy[node] = -1;
    if(st == en){
        tree[node] = 1;
        return;
    }
    ll mid = (st + en) >> 1;
    init(st, mid, node * 2);
    init(mid +1, en, node * 2 + 1);
    tree[node] = tree[node*2] + tree[node * 2 + 1];
}

void lazyy(ll st, ll en, ll node){
    tree[node] = (en - st + 1) * lazy[node];
    if(st != en){
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
    }
    lazy[node] = -1;
}

void update(ll st, ll en, ll node, ll l , ll r, ll val){
    if(lazy[node] != -1) lazyy(st, en, node);
    if(r < st || l > en) return;
    if(l <= st && en <= r){
        tree[node] = (en - st + 1) * val;
        if(st != en){
            lazy[node*2] = val;
            lazy[node*2 + 1] = val;
        }
        return;
    }
    ll mid = (st + en) >> 1;
    update(st, mid, node * 2, l, r, val);
	update(mid + 1, en, node * 2 + 1, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll st, ll en, ll node, ll l, ll r) {
	if(lazy[node] != -1) lazyy(st, en, node);
	if (r < st || l > en) return 0;
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	return sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r);
}

int cnt = 0;
ll in[101010];
ll out[101010];

void dfs(int node, int par) {
	in[node] = ++cnt;
	for (int nxt : v[node]) {
		if (nxt == par) continue;
		dfs(nxt, node);
	}
	out[node] = cnt;
}

void solve() {
    cin >> n;
    init(1, n, 1);
    for(int i = 1; i <= n; i++){
        cin >> a;
        v[a].push_back(i);
    }
    dfs(1, -1);
	cin >> q;
	while(q--){
	    cin >> a >> b;
	    if(a == 1){
	        update(1, n, 1, in[b] + 1, out[b], 1);
	    }
	    else if(a==2){
	        update(1, n, 1, in[b] + 1, out[b], 0);
	    }
	    else{
	        cout << sum(1, n, 1, in[b] + 1, out[b]) << '\n';
	    }
	}
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc= 1;
	while(tc--) {
		solve();
	}
}