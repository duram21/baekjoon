#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll tc, n, a, b, c, k, m, q;
ll tree[101010 * 4][2];
ll lazy[101010 * 4][2];
vector<ll>v[101010];

void lazyy(ll st, ll en, ll node, ll idx){
    tree[node][idx] += (en - st + 1) * lazy[node][idx];
    if(st != en){
        lazy[node*2][idx] += lazy[node][idx];
        lazy[node*2 + 1][idx] += lazy[node][idx];
    }
    lazy[node][idx] = 0;
}

void update(ll st, ll en, ll node, ll l , ll r, ll val, ll idx){
    if(lazy[node][idx] != 0) lazyy(st, en, node, idx);
    if(r < st || l > en) return;
    if(l <= st && en <= r){
        tree[node][idx] += (en - st + 1) * val;
        if(st != en){
            lazy[node*2][idx] += val;
            lazy[node*2 + 1][idx] += val;
        }
        return;
    }
    ll mid = (st + en) >> 1;
    update(st, mid, node * 2, l, r, val, idx);
	update(mid + 1, en, node * 2 + 1, l, r, val, idx);
	tree[node][idx] = tree[node * 2][idx] + tree[node * 2 + 1][idx];
}

ll sum(ll st, ll en, ll node, ll l, ll r, ll idx) {
	if(lazy[node][idx] != 0) lazyy(st, en, node, idx);
	if (r < st || l > en) return 0;
	if (l <= st && en <= r) return tree[node][idx];
	ll mid = (st + en) >> 1;
	return sum(st, mid, node * 2, l, r, idx) + sum(mid + 1, en, node * 2 + 1, l, r, idx);
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
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(a == -1) continue;
        v[a].push_back(i);
    }
    dfs(1, -1);
	bool dir = 1;
	while(q--){
	    cin >> a;
	    if(a == 1){
	        cin >> b >> c;
	        if(dir){
	            update(1, n, 1, in[b], out[b], c, dir);    
	        }
	        else{
	            update(1, n, 1, in[b], in[b], c, dir);
	        }
	        
	    }
	    else if(a==2){
	        cin >> b;
	        cout << sum(1, n, 1, in[b], in[b], 1)  +  sum(1, n, 1, in[b], out[b], 0) << '\n';
	    }
	    else{
	        dir = !dir;
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