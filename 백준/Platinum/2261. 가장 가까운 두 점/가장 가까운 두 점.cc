#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q, d;
vector<pair<ll, ll>>v;
ll ans = 1e12;

ll dist(pair<ll, ll>a, pair<ll, ll>b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void func(ll st, ll en) {
	if (en - st + 1 <= 3) {
		for (int i = st; i <= en; i++) {
			for (int j = i + 1; j <= en; j++) {
				ans = min(ans, dist(v[i], v[j]));
			}
		}
		return;
	}
	vector<pair<ll, ll>>tmp;
	ll mid = (st + en) / 2;
	func(st, mid - 1);
	func(mid + 1, en);
	for (int i = mid - 1; i >= st; i--) {
		if (dist({ v[mid].first, 0 }, { v[i].first, 0 }) < ans) {
			tmp.push_back(v[i]);
		}
		else break;
	}
	tmp.push_back(v[mid]);
	for (int i = mid + 1; i <= en; i++) {
		if (dist({ v[mid].first, 0 }, { v[i].first, 0 }) < ans) {
			tmp.push_back(v[i]);
		}
		else break;
	}

	sort(tmp.begin(), tmp.end(), [](pair<ll, ll>v1, pair<ll, ll>v2) {return v1.second < v2.second; });

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			if (dist({ tmp[i].second, 0 }, { tmp[j].second, 0 }) >= ans) break;
			ans = min(ans, dist(tmp[i], tmp[j]));
		}
	}
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end());
	func(0, n - 1);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}