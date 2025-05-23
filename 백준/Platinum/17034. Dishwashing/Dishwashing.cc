#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll chk[101010];
vector<ll>v[101010];


void solve() {
	cin >> n;
	ll cur = 0;
	ll ans = n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a < cur) {
			ans = i - 1;
			break;
		}
		for (int j = a; j >= 1 && !chk[j]; j--) {
			chk[j] = a;
		}
		
		while (v[chk[a]].size() && v[chk[a]].back() <= a) {
			cur = v[chk[a]].back();
			v[chk[a]].pop_back();
		}
		v[chk[a]].push_back(a);
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