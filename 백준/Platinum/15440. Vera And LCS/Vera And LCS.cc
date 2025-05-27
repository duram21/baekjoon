#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, y, h, w, q, m, x;
string str;
ll cnt[26];
ll ans;
vector<ll>v;
ll sz;



void solve() {
	cin >> n >> k;
	cin >> str;
	for (int i = 1; i <= n; i++) {
		cnt[str[i - 1] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			v.push_back(cnt[i]);
		}
	}
	if (k > n) {
		cout << "WRONGANSWER\n";
		return;
	}
	set<ll>s;
	s.insert(0);
	sz = v.size();
	sort(v.begin(), v.end());
	if (sz < 26) {
		char cur = -1;
		for (int i = 0; i < 26; i++) {
			if (!cnt[i]) {
				cur = i;
				break;
			}
		}
		for (int i = 0; i < k; i++) {
			cout << str[i];
		}
		for (int i = k; i < n; i++) {
			cout << char(cur + 'a');
		}
		return;
	}


	if (v[0] <= k) {
		ll cur = -1;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] == v[0]) {
				cur = i;
				break;
			}
		}
		string s(n, (char)(cur + 'a'));

		ll sum = v[0];

		ll idx = 0;

		for (int i = 0; i < n; i++) {
			if (str[i] == (char)(cur + 'a')) continue;
			else {
				s[i] = str[i];
				sum++;
				if (sum == k) break;
			}
		}

		cout << s << '\n';

	}

	cout << "WRONGANSWER\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}