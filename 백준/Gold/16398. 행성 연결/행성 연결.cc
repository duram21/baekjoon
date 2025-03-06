#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
ll arr[1010][1010];
ll par[1010];

ll find(ll x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void solve() {
	cin >> n;
	vector<pair<ll, pair<ll, ll>>>v;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (i > j) {
				v.push_back({ arr[i][j], {i, j} });
			}
		}
	}
	sort(v.begin(), v.end());
	ll cnt = 0;
	ll ans = 0;
	for(int i = 0 ; i < v.size(); i++){
		a = v[i].second.first;
		b = v[i].second.second;
		d = v[i].first;
		a = find(a);
		b = find(b);
		if (a == b) continue;
		par[a] = b;
		ans += d;
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}