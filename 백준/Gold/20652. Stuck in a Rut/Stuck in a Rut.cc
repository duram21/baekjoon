#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, h, w, q, m;
char dir[1010];
ll x[1010];
ll y[1010];
bool stop[1010];
ll deg[1010];
ll cnt[1010];
vector<ll>edges[1010];

void solve() {
	cin >> n;
	char cmd;
	vector<ll>E;
	vector<ll>N;
	for (int i = 1; i <= n; i++) {
		cin >> cmd >> x[i] >> y[i];
		if (cmd == 'E') {
			E.push_back(i);
		}
		else {
			N.push_back(i);
		}
	}
	sort(all(E), [](ll a, ll b) {return y[a] < y[b]; });
	sort(all(N), [](ll a, ll b) {return x[a] < x[b]; });

	for (int i : E) {
		for (int j : N) {
			if (stop[i] || stop[j]) continue;
			if (x[i] > x[j] || y[j] > y[i]) continue;
			ll dx = x[j] - x[i];
			ll dy = y[i] - y[j];
			if (dx == dy) continue;
			if (dx > dy) {
				stop[i] = 1;
				cnt[i] = dx;
			}
			else {
				stop[j] = 1;
				cnt[j] = dy; 

			}
			
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			cout << "Infinity\n";
		}
		else cout << cnt[i] << '\n';
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