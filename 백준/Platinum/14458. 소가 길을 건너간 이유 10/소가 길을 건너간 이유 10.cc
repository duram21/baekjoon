#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;
int tree[101010 * 4];
int arr1[101010];
int pos1[101010];
int arr2[101010];
int pos2[101010];

void update(int st, int en, int node, int idx, int dif) {
	if (st > idx || en < idx) return;
	tree[node] += dif;
	if (st == en) return;
	int mid = (st + en) / 2;
	update(st, mid, node * 2, idx, dif);
	update(mid + 1, en, node * 2 + 1, idx, dif);
}

ll sum(int st, int en, int node, int l, int r) {
	if (r < st || en < l) return 0;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r);
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
		pos1[arr1[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr2[i];
		pos2[arr2[i]] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum(1, n, 1, pos2[arr1[i]] +1, n);
		update(1, n, 1, pos2[arr1[i]], 1);
	}
	ll cur = ans;
	for (int i = n; i >= 1; i--) {
		ll idx = pos2[arr1[i]];
		cur += idx - 1;
		cur -= n - idx;
		ans = min(ans, cur);
	}

	memset(tree, 0, sizeof(tree));
	ll ans2 = 0;
	for (int i = 1; i <= n; i++) {
		ans2 += sum(1, n, 1, pos1[arr2[i]] + 1, n);
		update(1, n, 1, pos1[arr2[i]], 1);
	}
	ll cur2 = ans2;
	for (int i = n; i >= 1; i--) {
		ll idx = pos1[arr2[i]];
		cur2 += idx - 1;
		cur2 -= n - idx;
		ans2 = min(ans2, cur2);
	}

	cout << min(ans, ans2) << '\n';
}