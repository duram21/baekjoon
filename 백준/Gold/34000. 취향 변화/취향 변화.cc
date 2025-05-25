#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, q, e, r, w;
ll arr[101010];
ll cnt[101010];
bool fav[101010];

void solve() {
	cin >> n >> q;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> fav[i];
		if(fav[i])
			sum += cnt[i];
		else {
			sum -= cnt[i];
		}
	}
	while (q--) {
		cin >> a;
		if (a == 2) {
			cin >> b;
			fav[b] = !fav[b];
			if (fav[b] == 0) {
				sum -= 2 * cnt[b];
			}
			else {
				sum += 2 * cnt[b];
			}
		}
		else {
			cin >> b >> c;
			cnt[arr[b]]--;
			if (fav[arr[b]]) {
				sum--;
			}
			else {
				sum++;
			}
			cnt[c]++;
			arr[b] = c;
			if (fav[c]) {
				sum++;
			}
			else {
				sum--;
			}
		}
		ll tmp = abs(sum);
		if (tmp % 2 == 0) {
			cout << tmp / 2 * (tmp / 2) << '\n';
		}
		else {
			cout << (tmp / 2) * (tmp / 2 + 1) << '\n';
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
}