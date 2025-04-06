#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;

struct Node {
	ll mx;
	ll mn;
	ll ans;
	ll ba;
	ll bc;
};

ll arr[340000];
Node tree[340000 * 4];
ll mod = 998244353;

Node merge(Node left, Node right) {
	Node ret = {};
	ret.mx = max(left.mx, right.mx);
	ret.mn = min(left.mn, right.mn);
	ret.ba = max({ left.ba, right.ba, right.mx - left.mn });
	ret.bc = max({ left.bc, right.bc, left.mx - right.mn });
	ret.ans = max({ left.ans, right.ans, right.bc - left.mn, left.ba - right.mn });
	return ret;
}

void update(ll st, ll en, ll node, ll idx, ll val) {
	if (st == en && st == idx) {
		tree[node].mx = val;
		tree[node].mn = val;
		return;
	}
	if (idx <st || idx > en) return;
	ll mid = (st + en) >> 1;
	
	update(st, mid, node * 2, idx, val);
	update(mid + 1, en, node * 2 + 1, idx, val);
	
	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node f(ll st, ll en, ll node, ll  l, ll r) {
	if (en < l || st > r) {
		Node tmp = {};
		tmp.mx = -1e12;
		tmp.mn = 1e12;
		tmp.ba = -1e12;
		tmp.bc = -1e12;
		tmp.ans = -1e12;
		return tmp;
	}
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	Node cur = {};
	Node left = f(st, mid, node * 2, l, r);
	Node right = f(mid + 1, en, node * 2 + 1, l, r);
	cur = merge(left, right);
	return cur;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n * 4; i++) {
		tree[i].mx = -1e12;
		tree[i].mn = 1e12;
		tree[i].ba = -1e12;
		tree[i].bc = -1e12;
		tree[i].ans = -1e12;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, n, 1, i, arr[i]);
	}
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			Node ret = f(1, n, 1, b, c);
			cout << f(1, n, 1, b, c).ans << '\n';
			
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}