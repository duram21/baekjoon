#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x;
ll color[101010];
vector<ll>edges[101010];
ll red[101010];
ll blue[101010];
ll ans[101010];

void dfs(ll x, ll par) {
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		dfs(nxt, x);
		red[x] += red[nxt];
		blue[x] += blue[nxt];
		if (color[nxt] == 1) {
			red[x]++;
		}
		else blue[x]++;
	}
}

void func(ll x, ll par, ll rval, ll bval) {
	ll rcnt = rval;
	ll bcnt = bval;

	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		ll rtmp = red[nxt];
		ll btmp = blue[nxt];
		if (color[nxt] == 1) rtmp++;
		else btmp++;
		ans[x] += rtmp * bcnt;
		ans[x] += btmp * rcnt;
		bcnt += btmp;
		rcnt += rtmp;
	}
	for (ll nxt : edges[x]) {
		if (nxt == par) continue;
		ll rtmp = rcnt;
		ll btmp = bcnt;
		if (color[x] == 1) rtmp++;
		else btmp++;
		if (color[nxt] == 1) rtmp--;
		else btmp--;
		func(nxt, x, rtmp - red[nxt], btmp - blue[nxt]);

	}

}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, 0);
	func(1, 0, 0, 0);

	cin >> q;
	while (q--) {
		cin >> a;
		cout << ans[a] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}