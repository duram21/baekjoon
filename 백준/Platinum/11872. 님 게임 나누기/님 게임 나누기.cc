#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, l, h, w, q;
ll arr[101];

void solve() {
	cin >> n;
	ll xr = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] % 4 == 0) {
			xr ^= arr[i] - 1;
		}
		else if (arr[i] % 4 == 3) {
			xr ^= arr[i] + 1;
		}
		else {
			xr ^= arr[i];
		}
		
	}

	if (!xr) {
		cout << "cubelover\n";
	}
	else cout << "koosaga\n";

}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}