#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll color[101010];
bool flag = 1;
vector<ll>S[101010];
vector<ll>D[101010];

void func(ll x, ll val) {
	color[x] = val;
	for (auto nxt : S[x]) {
		if (!color[nxt]) {
			func(nxt, val);
		}
		if (color[nxt] == 3 - val) {
			flag = 0;
		}
	}
	for (auto nxt : D[x]) {
		if (!color[nxt]) {
			func(nxt, 3 - val);
		}
		if (color[nxt] == val) flag = 0;
	}
}


void solve() {
	cin >> n >> m;
	while (m--) {
		char com;
		cin >> com >> a >> b;
		if (com == 'S') {
			S[a].push_back(b);
			S[b].push_back(a);
		}
		else {
			D[a].push_back(b);
			D[b].push_back(a);
		}
	}

	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			func(i, 1);
			cnt++;
		}
	}

	if (!flag) {
		cout << 0 << '\n';
		return;
	}


	cout << 1;
	for (int i = 0; i < cnt; i++) {
		cout << 0;
	}
	cout << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}