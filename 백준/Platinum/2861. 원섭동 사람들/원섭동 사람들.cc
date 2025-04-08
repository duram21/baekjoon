#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m;
ll val[202020];
ll money[202020];
ll owe[202020];
ll nxt[202020];
int visited[202020];
ll C = 1;
vector<ll>cycle[202020];
bool flag[202020];
ll ans;



void find_cycle() {
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		ll cur = i;
		for (; !visited[cur];) {
			visited[cur] = i;
			cur = nxt[cur];
		}
		if (visited[cur] != i) continue;
		for (; !flag[cur];) {
			flag[cur] = 1;
			cycle[C].push_back(cur);
			cur = nxt[cur];
		}
		C++;
	}
}

void not_cycle() {
	for (int i = 1; i <= n; i++) {
		if (flag[i]) continue;
		ans += max((ll)0, owe[i] - val[i]);
		money[nxt[i]] += owe[i];
	}
}

void f() {
	for (int i = 1; i < C; i++) {
		ll sum = 0;
		ll mn = 1e12;
		ll idx = -1;

		for (auto cur : cycle[i]) {
			// 선택 안했다면
			a = max((ll)0, owe[cur] - val[cur] - money[cur]);
			// 선택 했으면
			b = max((ll)0, owe[cur] - money[cur]);
			//cout << cur << ' ' << a << ' ' << b << '\n';
			if (mn > b - a) {
				mn = b - a;
				idx = cur;
			}
		}
		//cout << idx << '\n';

		ans += max((ll)0, owe[idx]  - money[idx]);
		money[nxt[idx]] += owe[idx];
		ll cur = nxt[idx];

		for (; cur != idx;) {
			ans += max((ll)0, owe[cur] - money[cur] );
			money[nxt[cur]] += owe[cur];
			cur = nxt[cur];
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {

		cin >> a >> b;
		val[a] += b;
		owe[i] += b;
		nxt[i] = a;
	}
	find_cycle();
	not_cycle();
	f();
	cout << ans << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}