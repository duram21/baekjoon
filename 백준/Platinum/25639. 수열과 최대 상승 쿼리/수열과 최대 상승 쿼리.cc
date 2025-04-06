#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;

struct Node {
	ll mx;
	ll mn;
	ll val;
};

ll arr[102020];
Node tree[102020 * 4];
ll mod = 998244353;



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
	
	tree[node].mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx);
	tree[node].mn = min(tree[node * 2].mn, tree[node * 2 + 1].mn);
	tree[node].val = max({ tree[node * 2].val, tree[node * 2 + 1].val, tree[node * 2 + 1].mx - tree[node * 2].mn });
}

Node f(ll st, ll en, ll node, ll  l, ll r) {
	if (en < l || st > r) {
		Node tmp = {};
		tmp.mx = -1e12;
		tmp.mn = 1e12;
		tmp.val = 0;
		return tmp;
	}
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	Node cur = {};
	cur.mx = -1e12;
	cur.mn = 1e12;
	cur.val = 0;
	Node left = f(st, mid, node * 2, l, r);
	Node right = f(mid + 1, en, node * 2 + 1, l, r);
	cur.mx = max(left.mx, right.mx);
	cur.mn = min(left.mn, right.mn);
	cur.val = max({ left.val, right.val, right.mx - left.mn });
	return cur;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n * 4; i++) {
		tree[i].mx = -1e12;
		tree[i].mn = 1e12;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, n, 1, i, arr[i]);
	}
	cin >> q;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			Node ret = f(1, n, 1, b, c);
			//cout << ret.mx << ' ' << ret.mn << ' ' << ret.val << '\n';
			cout << f(1, n, 1, b, c).val << '\n';
			
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}