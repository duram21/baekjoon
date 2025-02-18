#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m, m2, tc, d, k, l, r, x, w;
ll ans[101010];

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}

void solve() {
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	set<ll>s;
	ll cur = 1;
	while (pq.size() <= 1e5) {
		if (gcd(cur, 15) == 1) {
			pq.push(cur);
			s.insert(cur);
		}
		cur++;
	}
	ll cnt = 1;
	while (cnt <= 1e5) {
		a = pq.top();
		pq.pop();
		ans[cnt] = a;
		if (s.find(a * 27) == s.end()) {
			pq.push(a * 27);
			s.insert(a * 27);
		}
		if (s.find(a * 125) == s.end()) {
			pq.push(a * 125);
			s.insert(a * 125);
		}
		if (s.find(a * 15) == s.end()) {
			pq.push(a * 15);
			s.insert(a * 15);
		}
		cnt++;
	}
	while (n--) {
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