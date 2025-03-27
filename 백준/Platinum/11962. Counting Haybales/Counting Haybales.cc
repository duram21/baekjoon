#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, q;
ll arr[202020];
ll sum[202020 * 4];
ll lazy_sum[202020 * 4];
ll mn[202020 * 4];
ll lazy_mn[202020 * 4];

void init(ll st, ll en, ll node) {
    if (st == en) {
        mn[node] = arr[st];
        sum[node] = arr[st];
        return;
    }
    ll mid = (st + en) >> 1;
    init(st, mid, node * 2);
    init(mid + 1, en, node * 2 + 1);
    mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

void update_sum(ll st, ll en, ll node, ll l, ll r, ll val) {
	if (lazy_sum[node]) {
		sum[node] += (en - st + 1) * lazy_sum[node];
		if (st != en) {
			lazy_sum[node * 2] += lazy_sum[node];
			lazy_sum[node * 2 + 1] += lazy_sum[node];
		}
		lazy_sum[node] = 0;
	}
	if (r < st || l > en) return;
	if (l <= st && en <= r) {
		sum[node] += (en - st + 1) * val;
		if (st != en) {
			lazy_sum[node * 2] += val;
			lazy_sum[node * 2 + 1] += val;
		}
		return;
	}
	ll mid = (st + en) >> 1;
	update_sum(st, mid, node * 2, l, r, val);
	update_sum(mid + 1, en, node * 2 + 1, l, r, val);
	sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

ll sum_sum(ll st, ll en, ll node, ll l, ll r) {
	if (lazy_sum[node]) {
		sum[node] += (en - st + 1) * lazy_sum[node];
		if (st != en) {
			lazy_sum[node * 2] += lazy_sum[node];
			lazy_sum[node * 2 + 1] += lazy_sum[node];
		}
		lazy_sum[node] = 0;
	}
	if (r < st || l > en) return 0;
	if (l <= st && en <= r) return sum[node];
	ll mid = (st + en) >> 1;
	return sum_sum(st, mid, node * 2, l, r) + sum_sum(mid + 1, en, node * 2 + 1, l, r);
}

void update_mn(ll st, ll en, ll node, ll l, ll r, ll val) {
	if (lazy_mn[node]) {
		mn[node] += lazy_mn[node];
		if (st != en) {
			lazy_mn[node * 2] += lazy_mn[node];
			lazy_mn[node * 2 + 1] += lazy_mn[node];
		}
		lazy_mn[node] = 0;
	}
	if (r < st || l > en) return;
	if (l <= st && en <= r) {
		mn[node] +=  val;
		if (st != en) {
			lazy_mn[node * 2] += val;
			lazy_mn[node * 2 + 1] += val;
		}
		return;
	}
	ll mid = (st + en) >> 1;
	update_mn(st, mid, node * 2, l, r, val);
	update_mn(mid + 1, en, node * 2 + 1, l, r, val);
	mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
}

ll sum_mn(ll st, ll en, ll node, ll l, ll r) {
	if (lazy_mn[node]) {
		mn[node] += lazy_mn[node];
		if (st != en) {
			lazy_mn[node * 2] += lazy_mn[node];
			lazy_mn[node * 2 + 1] += lazy_mn[node];
		}
		lazy_mn[node] = 0;
	}
	if (r < st || l > en) return 987654321;
	if (l <= st && en <= r) return mn[node];
	ll mid = (st + en) >> 1;
	return min(sum_mn(st, mid, node * 2, l, r), sum_mn(mid + 1, en, node * 2 + 1, l, r));
}


void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, n, 1);
    while (q--) {
		char com;
		cin >> com;
		if (com == 'M') {
			cin >> a >> b;
			cout << sum_mn(1, n, 1, a, b) << '\n';
		}
		else if (com == 'P') {
			cin >> a >> b >> c;
			update_sum(1, n, 1, a, b, c);
			update_mn(1, n, 1, a, b, c);
		}
		else {
			cin >> a >> b;
			cout << sum_sum(1, n, 1, a, b) << '\n';
		}
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}