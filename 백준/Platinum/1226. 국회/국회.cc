#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
pair<ll,ll> arr[303];
ll dp[101010];

vector<ll>ans;


void solve() {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		sum += arr[i].first;
	}
	dp[0] = 1e9;
	ll half = (sum) / 2;
	ll mx = -1;
	sort(arr + 1, arr + 1 + n);
	for (int i = n; i >= 1; i--) {
		for (int j = half; j >= 0; j--) {
			if (dp[j] == 0) continue;
			if (dp[j + arr[i].first]) continue;
			if (j + arr[i].first >= half) {
				dp[j + arr[i].first] = i;
			}
			else {
				dp[j + arr[i].first] = i;
			}
			mx = max(mx, j + arr[i].first);
		}
	}

	while (true) {
		if (dp[mx] == 1e9) break;
		ans.push_back(arr[dp[mx]].second);
		mx = mx - arr[dp[mx]].first;
	}

	cout << ans.size() << '\n';
	for (ll cur : ans) {
		cout << cur << ' ';
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}