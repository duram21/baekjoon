#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, k, y, h, w, q, m, x;
ll p[101010];
ll d[202020];
ll e[101010];
ll sum[101010];
vector<ll>C[101010];

void solve() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i] >> d[i] >> e[i];
	}
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[p[i]] + e[i];
	}

	C[1].resize(11);
	for (int i = 2; i <= n; i++) {
		C[i] = C[p[i]];
		C[i].push_back(d[i]);
		sort(C[i].rbegin(), C[i].rend());
		C[i].resize(11);
	}

	vector<pair<ll, ll>>cost[11];

	for (int i = 0; i < 11; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i].push_back({ C[j][i], sum[j] });
		}
		sort(cost[i].begin(), cost[i].end());
		for (int j = 1; j < cost[i].size(); j++) {
			cost[i][j].second = max(cost[i][j].second, cost[i][j-1].second);
		}
	}

	cin >> q;
	while (q--) {
		cin >> a >> b;
		ll idx = lower_bound(cost[b].begin(), cost[b].end(), make_pair(a+1, 0LL)) - cost[b].begin();
		cout << cost[b][idx - 1].second << '\n';

	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}