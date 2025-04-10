#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
ll ans = 0;


struct Node {
	Node* child[2];
	bool finish;
	Node(){
		finish = false;
		for (int i = 0; i < 2; i++) {
			child[i] = nullptr;
		}
	}
	~Node() {
		for (int i = 0; i < 2; i++)
			if (child[i]) delete child[i];
	}

	void Insert(string &key, int idx) {
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
		if (child[!num]) {
			child[!num]->f(key, idx + 1, val + (1 << (30 - idx)));
		}
		else {
			child[num]->f(key, idx + 1, val);
		}

	}
};


void solve() {
	cin >> n;
	vector<string>v;
	Node* root = new Node;
	bool flag = 1;
	//string z = bitset<31>(0).to_string();
	//root->Insert(z, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		string binary = bitset<31>(a).to_string(); 
		if(i >= 2)root->f(binary, 0, 0);
		root->Insert(binary, 0);
	}
	cout << ans << '\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
}