#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q, a, b, c, m1, m2, tc, d, k, m, l, r, x, s, t, w;
ll X[1010];
ll L[1010];
char C[1010];
string str, bef;

void solve() {
	vector<string>v;
	while (true) {
		while (true) {
			cin >> str;
			if (str == "#") break;
			v.push_back(str);
		}
		if (v.size() == 0) return;
		bool flag = 1;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i].size() != v[i + 1].size()) {
				flag = 0;
				break;
			}
			ll cnt = 0;
			for (int j = 0; j < v[i].length(); j++) {
				if (v[i][j] != v[i + 1][j]) cnt++;
			}
			if (cnt != 1) {
				flag = 0;
				break;
			}
		}
		if (flag) cout << "Correct\n";
		else cout << "Incorrect\n";
		v.clear();
	}
	
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}