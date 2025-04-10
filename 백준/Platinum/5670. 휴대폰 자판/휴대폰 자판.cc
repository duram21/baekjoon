#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, m, x, q;
ll ans = 0;

struct Node {
	Node* child[26];
	ll cnt[26];
	ll diff;
	bool finish;
	Node(){
		finish = false;
		diff = 0;
		for (int i = 0; i < 26; i++) {
			child[i] = nullptr;
		}
		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}
	}
	~Node() {
		for (int i = 0; i < 26; i++)
			if (child[i]) delete child[i];
	}

	void Insert(string &key, int idx) {
		if (idx == key.length()) {
			finish = true;
			
		}
		else {
			int nxt = key[idx] - 'a';
			if (child[nxt] == nullptr) {
				child[nxt] = new Node;
				diff++;
			}
			cnt[nxt]++;
			child[nxt]->Insert(key, idx + 1);
		}
	}

	void f() {
		if (diff >= 2 || finish) {
			ll sum = 0;
			for (int i = 0; i < 26; i++) {
				sum += cnt[i];
			}
			ans += sum;
		}
	/*	else if (diff == 1 && finish) {
			ll sum = 0;
			for (int i = 0; i < 26; i++) {
				sum += cnt[i];
			}
			ans += sum;
		}*/
		for (int i = 0; i < 26; i++) {
			if (child[i]) {
				child[i]->f();
			}
		}
	}
};


void solve() {
	//cin >> n;
	string str;
	ans = 0;
	Node* root = new Node;
	root->finish = 1;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		root->Insert(str, 0);
	}
	root->f();
	cout.precision(2);
	cout << fixed;
	cout << (double) ans / n << '\n';
	delete root;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	while (cin >> n) solve();
}