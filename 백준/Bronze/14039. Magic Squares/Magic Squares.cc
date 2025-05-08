#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, x, q, l, m;

ll arr[10][10];

void solve() {
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++) {
			cin >> arr[i][j];
		}
	}
	set<ll>s;
	for (int i = 1; i <= 4; i++) {
		ll tot = 0;
		for (int j = 1; j <= 4; j++) {
			tot += arr[i][j];
		}
		s.insert(tot);
	}
	for (int i = 1; i <= 4; i++) {
		ll tot = 0;
		for (int j = 1; j <= 4; j++) {
			tot += arr[j][i];
		}
		s.insert(tot);
	}

	if (s.size() == 1) {
		cout << "magic\n";
	}
	else cout << "not magic\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}