#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m, q;


void solve() {
	cin >> n;
	vector<ll>A;
	vector<ll>B;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a;
		B.push_back(a);
	}
	A.push_back(1e12);
	B.push_back(1e12);
	cin >> q;
	while (q--) {
		cin >> a >> b >> k;
		ll mx = max(A[a - 1], B[b - 1]);
		ll l = 1;
		ll r = mx;
		ll ans;
		ll val;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			ll ai = lower_bound(A.begin(), A.end(), mid) - A.begin();
			ai = min(ai, a - 1);
			ll bi = lower_bound(B.begin(), B.end(), mid) - B.begin();
			bi = min(bi, b - 1);
			ll acnt = ai + 1;
			ll bcnt = bi + 1;
			if (A[ai] > mid) acnt--;
			if (B[bi] > mid) bcnt--;
			if (acnt + bcnt < k) {
				l = mid + 1;
			}
			else {
				if (acnt + bcnt == k) {
					if (A[acnt - 1] == mid) {
						ans = 1;
						val = acnt;
					}
					else if (B[bcnt - 1] == mid) {
						ans = 2;
						val = bcnt;
					}
				}

				r = mid - 1;
			}
		}
		cout << ans << ' ' << val << '\n';
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}