#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
string str;

void solve() {
	cin >> str;
	if (str[str.length() - 1] == '0') cout << 'E' << '\n';
	else cout << "B\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) solve();
}