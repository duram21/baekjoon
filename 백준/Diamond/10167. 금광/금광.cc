#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

struct srt {
	ll lmax;
	ll rmax;
	ll mmax;
	ll sum = 0;
};

struct Point {
	ll x;
	ll y;
	ll w;
	bool operator < (const Point& t) const {
		if (x != t.x) return x < t.x;
		return y < t.y;
	}
};
ll n, a, b, c, q;
Point arr[3030];
srt tree[3030 * 4];

srt update(ll st, ll en, ll node, ll idx, ll val) {
	if (idx < st || en < idx) return tree[node];
	if (st == en) {
        tree[node].sum += val;
		tree[node].lmax = tree[node].rmax = tree[node].mmax = tree[node].sum;
		return tree[node];
	}

	ll mid = (st + en) >> 1;
	srt aa = update(st, mid, node * 2, idx, val);
	srt bb = update(mid + 1, en, node * 2 + 1, idx, val);
	tree[node].rmax = max(bb.rmax, aa.rmax + bb.sum);
	tree[node].lmax = max(aa.lmax, bb.lmax + aa.sum);
    tree[node].sum = aa.sum + bb.sum;
	tree[node].mmax = max({ aa.rmax + bb.lmax, aa.mmax, bb.mmax,  tree[node].sum});
	return tree[node];
}

srt search(ll st, ll en, ll node, ll l, ll r) {
	if (en < l || st > r) {
		srt tmp;
		tmp.lmax = 0;
		tmp.rmax = 0;
		tmp.mmax = 0;
		return tmp;
	}
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	srt aa = search(st, mid, node * 2, l, r);
	srt bb = search(mid + 1, en, node * 2 + 1, l, r);
	srt ans;
	ans.rmax = max(bb.rmax, aa.rmax + bb.sum);
	ans.lmax = max(aa.lmax, bb.lmax + aa.sum);
    ans.sum = aa.sum + bb.sum;
	ans.mmax = max({ aa.rmax + bb.lmax, aa.mmax, bb.mmax, ans.sum});
	return ans;
}

void init() {
	for (int i = 0; i <= n * 4; i++) {
		tree[i].lmax = tree[i].rmax = tree[i].mmax = tree[i].sum = 0;
	}
}

void solve() {
	cin >> n;
	srt tmp;
	tmp.lmax = -2e9; tmp.rmax = -2e9; tmp.mmax = -2e9;
	vector<ll>x, y;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].y >> arr[i].x >> arr[i].w;
		x.push_back(arr[i].x);
		y.push_back(arr[i].y);
	}
	sort(all(x));
	sort(all(y));
	x.erase(unique(all(x)), x.end());
	y.erase(unique(all(y)), y.end());

	for (int i = 1; i <= n; i++) {
		arr[i].x = lower_bound(all(x), arr[i].x) - x.begin() + 1;
		arr[i].y = lower_bound(all(y), arr[i].y) - y.begin() + 1;
		swap(arr[i].x, arr[i].y);
	}
	sort(arr + 1, arr + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
        if(i >= 2 && arr[i-1].x == arr[i].x) continue;
        init();
		for (int j = i; j <= n; j++) {
            a = arr[j].x;
            b = arr[j].y;
            c = arr[j].w;
			update(1, n, 1, b, c);
			if(j == n || arr[j].x != arr[j+1].x) ans = max(ans, tree[1].mmax);
		}
	}
	cout << ans << '\n';

}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}