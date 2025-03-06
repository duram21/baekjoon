#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, L, r, k, g, q, m;
string str;
vector<pair<ll, ll>>v;
set<string>s;

void func(ll x) {
	string tmp = str;
	vector<ll>idx;
	for (int i = 0; i < v.size(); i++) {
		if (~x & (1 << i))continue;
		idx.push_back(v[i].first);
		idx.push_back(v[i].second);
	}
	sort(idx.begin(), idx.end());
	for (int i = idx.size() - 1; i >= 0; i--) {
		tmp.erase(tmp.begin() + idx[i]);
	}
	s.insert(tmp);
}

void solve() {
	cin >> str;
	stack <ll>st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') st.push(i);
		else if(str[i] ==')') {
			v.push_back({ st.top(), i });
			st.pop();
		}
	}
	ll n = v.size();
	for (int i = 1; i < (1 << n); i++) {
		func(i);
	}
	for (auto cur : s) {
		cout << cur << '\n';
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