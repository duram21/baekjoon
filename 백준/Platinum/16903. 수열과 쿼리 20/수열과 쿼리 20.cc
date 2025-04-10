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
	Node(){
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

	void Insert(string &key, int idx) {
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
	void f(string &key, int idx, ll val) {
		if (idx == key.length()) {
			ans = max(ans, val);
			return;
		}
		ll num = key[idx] - '0';
		if (child[!num] && child[!num]->cnt) {
			child[!num]->f(key, idx + 1, val + (1 << (30 - idx)));
		}
		else {
			child[num]->f(key, idx + 1, val);
		}
	}
	void del(string& key, int idx) {
		cnt--;
		if (idx == key.length()) {
			return;
		}
		ll num = key[idx] - '0';
		child[num]->del(key, idx+1);
	}
};


void solve() {
	cin >> n;
	vector<string>v;
	Node* root = new Node;
	bool flag = 1;
	string z = bitset<31>(0).to_string();
	root->Insert(z, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		string binary = bitset<31>(b).to_string();
		if (a == 1) {
			root->Insert(binary, 0);
		}
		else if (a == 3) {
			ans = 0;
			root->f(binary, 0, 0);
			cout << ans << '\n';
		}
		else if (a == 2) {
			root->del(binary, 0);
		}
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
}