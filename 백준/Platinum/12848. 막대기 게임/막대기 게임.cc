#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q;
ll dp[1010];
char arr[1010][1010];
string str;
vector<ll>v;
bool chk[1010];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1];
		}
	}
	cin >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(all(v)), v.end());
	for (int i = 1; i <= m; i++) {
		set<ll>s;
		memset(chk, 0, sizeof(chk));
		for (int j = 0; j < v.size(); j++) {
			ll cur = v[j];
			if (cur > i) break;
			a = i - cur;
			for (int k = 0; k <= a / 2; k++) {
				b = a - k;
				chk[dp[k] ^ dp[b]] = 1;
				
			}
			
		}
		ll mx = 0;
		while (chk[mx]) {
			mx++;
		}
		dp[i] = mx;
	}
	ll xr = 0;

	for (int i = 1; i <= n; i++) {
		ll bef = 0;
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '@') {
				xr ^= dp[j - bef - 1];
				bef = j;
			}
		}
		xr ^= dp[m - bef ];
	}
	if (!xr) {
		cout << "hyo123bin\n";
	}
	else cout << "nein\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}