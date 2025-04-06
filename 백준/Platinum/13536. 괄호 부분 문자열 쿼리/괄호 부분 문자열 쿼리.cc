#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;

struct Node {
	ll cur;
	ll a;
	ll b;
};

Node tree[1000010 * 4];
ll mod = 998244353;

Node merge(Node left, Node right) {
	Node ret = {};
	ret.a = left.a + right.a;
	ret.b = left.b + right.b;
	ret.cur = left.cur + right.cur + min(left.a - left.cur, right.b - right.cur);
	return ret;
}

void update(ll st, ll en, ll node, ll idx, ll val) {
	if (st == en && st == idx) {
		if (val == 0) {
			tree[node].a = 1;
		}
		else {
			tree[node].b = 1;
		}
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
	cin >> str;
	n = str.length();
	cin >> q;
	for (int i = 1; i <= n; i++) {
		if(str[i-1] == '(')
			update(1, n, 1, i, 0);
		else {
			update(1, n, 1, i, 1);
		}
	}
	while (q--) {
		cin >> a >> b;
		Node ret = f(1, n, 1, a, b);
		cout << ret.cur  * 2 << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}