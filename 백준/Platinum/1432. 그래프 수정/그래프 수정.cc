#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
string str;
ll cnt[55];
vector<ll>v[55];
ll ans[55];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= n; j++) {
			if (str[j - 1] == '1') {
				cnt[i]++;
				v[j].push_back(i);
			}
		}
	}
	priority_queue<ll>pq;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) pq.push(i);
	}
	ll N = n;
	while (pq.size()) {
		a = pq.top();
		pq.pop();
		ans[a] = N--;
		for (auto nxt : v[a]) {
			cnt[nxt]--;
			if(!cnt[nxt]) pq.push(nxt);
		}
	}
	if (N) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
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