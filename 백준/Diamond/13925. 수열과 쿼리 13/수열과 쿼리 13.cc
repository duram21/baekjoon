#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, d;
pair<ll, ll>lazy[101010 * 4];
ll tree[101010 * 4];
ll arr[101010];
ll mod = 1e9 + 7;

void Lazy(ll st, ll en, ll node) {
	ll a1 = lazy[node].first;
	ll b1 = lazy[node].second;
	if (a1 == 1 && b1 == 0) return;
	
	if (st != en) {
		ll a2 = lazy[node * 2].first;
		ll b2 = lazy[node * 2].second;
		lazy[node * 2].first = a2 * a1 % mod;
		lazy[node * 2].second = a1 * b2 + b1;
		lazy[node * 2].second %= mod;

		a2 = lazy[node * 2 + 1].first;
		b2 = lazy[node * 2 + 1].second;
		lazy[node * 2 + 1].first = a2 * a1 % mod;
		lazy[node * 2 + 1].second = a1 * b2 + b1;
		lazy[node * 2 + 1].second %= mod;
	}
	tree[node] = a1 * tree[node] + b1 * (en - st + 1);
	tree[node] %= mod;
	lazy[node] = { 1, 0 };
	return;
}

void update(ll st, ll en, ll node, ll l, ll r, ll a, ll b) {
	Lazy(st, en, node);
	if (en < l || r < st) return;
	if (l <= st && en <= r) {
		ll a1 = lazy[node].first;
		ll b1 = lazy[node].second;
		lazy[node].first = a1 * a % mod;
		lazy[node].second = a * b1 + b;
		lazy[node].second %= mod;
		Lazy(st, en, node);
		return;
	}
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, l, r, a, b);
	update(mid + 1, en, node * 2 + 1, l, r, a, b);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	tree[node] %= mod;
}

ll sum(ll st, ll en, ll node, ll l, ll r) {
	Lazy(st, en, node);
	if (en < l || r < st)return 0;
	if (l <= st && en <= r) {
		return tree[node];
	}
	ll mid = (st + en) >> 1;
	return (sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r))%mod;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, n, 1, i, i, 0, arr[i]);
	}
	cin >> q;
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, n, 1, b, c, 1, d);
		}
		else if (a == 2) {
			cin >> b >> c >> d;
			update(1, n, 1, b, c, d, 0);
		}
		else if (a == 3) {
			cin >> b >> c >> d;
			update(1, n, 1, b, c, 0, d);
		}
		else {
			cin >> b >> c;
			cout << sum(1, n, 1, b, c) << '\n';
		}
	}
}


//1 x y v : Ai = (Ai + v) % MOD를 수행한다. (x ≤ i ≤ y)
//2 x y v : Ai = (Ai × v) % MOD를 수행한다. (x ≤ i ≤ y)
//3 x y v : Ai = v를 수행한다. (x ≤ i ≤ y)
//4 x y : (ΣAi) % MOD를 출력한다. (x ≤ i ≤ y)

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}