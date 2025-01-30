#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t;


void solve() {
	cin >> n;
	vector<ll>A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	if (A == B) {
		cout << "POSSIBLE\n";
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		vector<ll>tmp;
		vector<ll>inc;
		vector<ll>dec;
		tmp.push_back(B[i]);
		tmp.push_back(B[i+1]);
		tmp.push_back(B[i+2]);
		inc = tmp;
		dec = tmp;
		sort(inc.begin(), inc.end());
		sort(dec.rbegin(), dec.rend());
		if (tmp == inc || tmp == dec) {
			cout << "POSSIBLE\n";
			return;
		}
	}
	cout << "IMPOSSIBLE\n";

}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}