#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
ll arr[202020];
vector<ll>v[50505];
ll deg[202020];
ll ans[202020];
ll tmp[202020];
vector<pair<ll,ll>>edges[202020];


bool func(ll x) {
	for (int i = 1; i <= n; i++) {
		edges[i].clear();
		deg[i] = 0;
	}
	for (int i = 1; i <= x; i++) {
		ll val = 1;
		ll sz = v[i].size();
		for (int j = 1; j < sz; j++) {
			ll cur = v[i][j];
			ll bef = v[i][j - 1];
			deg[cur] += val;
			edges[bef].push_back({ cur, val });
			val++;
		}
	}
	priority_queue<ll>pq;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			pq.push(-i);
		}
	}
	ll cnt = 1;
	
	while (pq.size()) {
		a = -pq.top();
		pq.pop();

		tmp[cnt++] = a;
		for (auto nxt : edges[a]) {
			ll node = nxt.first;
			d = nxt.second;
			deg[node] -= d;
			if (!deg[node]) {
				pq.push(-node);
			}
		}
	}
	if (cnt == n + 1) {
		for (int i = 1; i <= n; i++) {
			ans[i] = tmp[i];
		}
		return true;
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a;
		for (int j = 1; j <= a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
	}
	ll l = 1;
	ll r = 50000;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (func(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}