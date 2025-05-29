#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c;
ll A[202020];
ll B[202020];
set<ll>s[202020];

void solve() {
	cin >> n >> a >> b;
	map<ll, ll>m;
	ll aa, bb;
	map<ll, ll>idx;
	for (int i = 1; i <= n; i++) {
		cin >> aa >> bb;
		A[i] = aa;
		B[i] = bb;
		m[bb] = aa;
		idx[bb] = i;
	}
	for (int i = 1; i <= n; i++) {
		// case 1 A
		if (m.find(a - B[i]) != m.end()) {
			s[i].insert(idx[a - B[i]]);
		}

		// case 2 B
		if (m.find(b - B[i]) != m.end()) {
			s[i].insert(idx[b - B[i]]);
		}
	}
	queue<ll>q;
	for (int i = 1; i <= n; i++) {
		if (s[i].size() == 1) {
			q.push(i);
		}
	}
	ll ans = 0;

	while (q.size()) {
		ll cur = q.front();
		q.pop();
		for (auto nxt : s[cur]) {
			if (cur == nxt) {
				ans += A[cur] / 2;
				A[cur] %= 2;
			}
			else {
				ll tmp = min(A[nxt], A[cur]);
				ans += tmp;
				A[nxt] -= tmp;
				A[cur] -= tmp;
				s[nxt].erase(cur);
				if (s[nxt].size() == 1) {
					q.push(nxt);
				}
			}
		}
	}
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