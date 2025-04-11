#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
ll ans = 0;


struct Node {
	Node* child[2];
	bool finish;
	ll cnt;
	Node() {
		finish = false;
		cnt = 0;
		for (int i = 0; i < 2; i++) {
			child[i] = nullptr;
		}
	}
	~Node() {
		for (int i = 0; i < 2; i++)
			if (child[i]) delete child[i];
	}

	void Insert(string& key, int idx) {
		cnt++;
		if (idx == key.length()) {
			finish = true;
		}
		else {
			int nxt = key[idx] - '0';
			if (child[nxt] == nullptr) {
				child[nxt] = new Node;
			}
			child[nxt]->Insert(key, idx + 1);
		}
	}
	void f(string& key, string& K, int idx) {
		if (idx == key.length()) {
			ans += cnt;
			return;
		}
		ll num = key[idx] - '0';
		if (K[idx] == '0') {
			if (num == 1) {
				if (child[0]) ans += child[0]->cnt;
				if (child[1]) child[1]->f(key, K, idx + 1);
			}
			else if (num == 0 ) {
				if (child[1]) ans += child[1]->cnt;
				if (child[0]) child[0]->f(key, K, idx + 1);

				
			}
		}
		else {
			if (num == 0) {
				if (child[1]) {
					child[1]->f(key, K, idx + 1);
				}
			}
			if (num == 1) {
				if (child[0]) {
					child[0]->f(key, K, idx + 1);
				}
			}
		}

	}
};


void solve() {
	cin >> n >> k;
	Node* root = new Node;
	string z = bitset<20>(0).to_string();
	string K = bitset<20>(k).to_string();
	root->Insert(z, 0);
	ll cur = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cur ^= a;
		string binary = bitset<20>(cur).to_string();
		//cout << binary << '\n';
		root->Insert(binary, 0);
	    root->f(binary, K, 0);
		//cout << i << ' ' << ans << '\n';
	}
	cout << n*(n+1) / 2 - ans << '\n';
	delete root;
}


 int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}