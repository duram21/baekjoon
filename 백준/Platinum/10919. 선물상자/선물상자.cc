#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc, l;
string str;
ll arr[10000001];
ll ldp[10000001];
ll rdp[10000001];

void solve() {
	cin >> n >> k >> l;
	vector<ll>left;
	vector<ll>right;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= l / 2) left.push_back(arr[i]);
		else {
			right.push_back(l - arr[i]);
		}
	}
	reverse(right.begin(), right.end());
	for (int i = 0; i < min((ll)left.size(), k); i++) {
		ldp[i] = 2 * left[i];
	}
	for (int i = 0; i < min((ll)right.size(), k); i++) {
		rdp[i] = 2 * right[i];
	}
	for (int i = k; i < left.size(); i++) {
		ldp[i] = ldp[i - k] + left[i] * 2;
	}
	for (int i = k; i < right.size(); i++) {
		rdp[i] = rdp[i - k] + right[i] * 2;
	}
	ll ans = ldp[left.size() - 1] + rdp[right.size() - 1];
	for (int i = 0; i <= k; i++) {
		ll a = min((ll)i, (ll)left.size());
		ll b = min((ll)right.size(), k - (ll)i);
		ans = min(ans, ldp[left.size() - 1 - a] + l + rdp[right.size() - 1 - b]);

	}
	cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc = 1;
	while (tc--) {
		solve();
	}
}