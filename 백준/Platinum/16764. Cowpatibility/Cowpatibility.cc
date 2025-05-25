#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, x, l, h, w, q;

ll arr[5];
map<vector<ll>, ll>m;

void solve() {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + 5);

		for (int j = 1; j < (1 << 5); j++) {
			vector<ll>v;
			for (int k = 0; k < 5; k++) {
				if (j & (1 << k)) v.push_back(arr[k]);
			}

			if (v.size() % 2) {
				sum += m[v];
			}
			else {
				sum -= m[v];
			}
			m[v]++;
		}
	}

	cout << n * (n - 1) / 2 - sum << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}