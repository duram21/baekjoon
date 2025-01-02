#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n, a, b, c, m, k, q, d, tc, l;
pair<ll, ll> arr[50505];
ll mnX[50505];
ll mnY[50505];
ll mxX[50505];
ll mxY[50505];
ll mnXX[50505];
ll mnYY[50505];
ll mxXX[50505];
ll mxYY[50505];

void solve() {
	cin >> n;
	ll mnx = 1e18;
	ll mxx = -1e18;
	ll mny = 1e18;
	ll mxy = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		mnx = min(mnx, arr[i].first);
		mxx = max(mxx, arr[i].first);
		mny = min(mny, arr[i].second);
		mxy = max(mxy, arr[i].second);
	}
	ll ans = (mxx - mnx) * (mxy - mny);
	vector<pair<ll, ll>>v;
	for (int i = 1; i <= n; i++) {
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	mnX[1] = v[0].first;
	mxX[1] = v[0].first;
	mnY[1] = v[0].second;
	mxY[1] = v[0].second;
	for (int i = 2; i <= n; i++) {
		mnX[i] = min(mnX[i-1], v[i-1].first);
		mxX[i] = max(mxX[i-1], v[i-1].first);
		mnY[i] = min(mnY[i-1], v[i-1].second);
		mxY[i] = max(mxY[i-1], v[i-1].second);

	}
	mnx = 1e18;
	mxx = -1e18;
	mny = 1e18;
	mxy = -1e18;
	ll ans2 = 1e18;
	for (int i = n; i >= 2; i--) {
		mnx = min(mnx, v[i-1].first);
		mxx = max(mxx, v[i-1].first);
		mny = min(mny, v[i-1].second);
		mxy = max(mxy, v[i-1].second);
		ans2 = min(ans2, (mxx - mnx) * (mxy - mny) + (mxX[i - 1] - mnX[i - 1]) * (mxY[i-1] - mnY[i-1]));

	}
	v.clear();
	for (int i = 1; i <= n; i++) {
		v.push_back({ arr[i].second, arr[i].first });
	}
	sort(v.begin(), v.end());
	mnX[1] = v[0].first;
	mxX[1] = v[0].first;
	mnY[1] = v[0].second;
	mxY[1] = v[0].second;
	for (int i = 2; i <= n; i++) {
		mnX[i] = min(mnX[i - 1], v[i - 1].first);
		mxX[i] = max(mxX[i - 1], v[i - 1].first);
		mnY[i] = min(mnY[i - 1], v[i - 1].second);
		mxY[i] = max(mxY[i - 1], v[i - 1].second);
	}
	mnx = 1e18;
	mxx = -1e18;
	mny = 1e18;
	mxy = -1e18;
	for (int i = n; i >= 2; i--) {
		mnx = min(mnx, v[i - 1].first);
		mxx = max(mxx, v[i - 1].first);
		mny = min(mny, v[i - 1].second);
		mxy = max(mxy, v[i - 1].second);
		ans2 = min(ans2, (mxx - mnx) * (mxy - mny) + (mxX[i - 1] - mnX[i - 1]) * (mxY[i - 1] - mnY[i - 1]));
	}
	cout << ans - ans2 << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc = 1;
	while (tc--) {
		solve();
	}
}