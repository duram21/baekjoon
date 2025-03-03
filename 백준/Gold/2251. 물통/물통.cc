#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, k, l, r, p, g, m, q;
bool visited[202][202][202];
ll px[150];
ll py[150];

struct water {
	ll A;
	ll B;
	ll C;
};

void bfs() {
	queue<water>q;
	q.push({ 0, 0, c });
	visited[0][0][c] = 1;
	while (q.size()) {
		ll A = q.front().A;
		ll B = q.front().B;
		ll C = q.front().C;
		q.pop();
		ll mn, aa, bb, cc, ta, tb, tc;
		// C -> A;
		aa = (a - A);
		mn = min(aa, C);
		ta = A + mn;
		tc = C - mn;;
		if (visited[ta][B][tc] == 0) {
			visited[ta][B][tc] = 1;
			q.push({ ta, B, tc });
		}
		// A->C;
		cc = (c - C);
		mn = min(c, A);
		tc = C + mn;
		ta = A - mn;;
		if (visited[ta][B][tc] == 0) {
			visited[ta][B][tc] = 1;
			q.push({ ta, B, tc });
		}
		// C -> B;
		bb = (b - B);
		mn = min(bb, C);
		tb = B + mn;
		tc = C - mn;;
		if (visited[A][tb][tc] == 0) {
			visited[A][tb][tc] = 1;
			q.push({ A, tb, tc });
		}
		// B->C;
		cc = (c - C);
		mn = min(cc, B);
		tc = C + mn;
		tb = B - mn;;
		if (visited[A][tb][tc] == 0) {
			visited[A][tb][tc] = 1;
			q.push({ A, tb, tc });
		}
		// B -> A;
		aa = (a - A);
		mn = min(aa, B);
		ta = A + mn;
		tb = B - mn;;
		if (visited[ta][tb][C] == 0) {
			visited[ta][tb][C] = 1;
			q.push({ ta, tb, C });
		}
		// A->B;
		bb = (b - B);
		mn = min(bb, A);
		tb = B + mn;
		ta = A - mn;;
		if (visited[ta][tb][C] == 0) {
			visited[ta][tb][C] = 1;
			q.push({ ta, tb, C });
		}
	}
}

void solve() {
	cin >> a >> b >> c;
	bfs();
	vector<ll>v;
	for (int i = 0; i <= b; i++) {
		for (int j = 0; j <= c; j++) {
			if (visited[0][i][j]) {
				v.push_back(j);
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto nxt : v) {
		cout << nxt << ' ';
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