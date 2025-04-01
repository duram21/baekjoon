#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll x, n, a, b, c, d, m, k, sqrtn, q;
ll arr[101010];

struct node {
	ll st, en, idx;
};
node query[101010];

bool cmp(node a, node b) {
	if (a.st / sqrtn == b.st / sqrtn) return a.en < b.en;
	return a.st / sqrtn < b.st / sqrtn;
}

ll tot[202020];
ll cnt[202020];
ll ans[102020];

void solve() {
	while (true) {
		cin >> n;
		if (!n) return;
		sqrtn = sqrt(n);
		cin >> q;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] += 100000;
		}
		for (int i = 1; i <= q; i++) {
			cin >> a >> b;
			query[i].st = a;
			query[i].en = b;
			query[i].idx = i;
		}
		sort(query + 1, query + q + 1, cmp);
		ll s = query[1].st;
		ll e = query[1].en;
		ll cur = 0;
		for (int i = s; i <= e; i++) {
			tot[cnt[arr[i]]]--;
			cnt[arr[i]]++;
			tot[cnt[arr[i]]]++;
			cur = max(cur, cnt[arr[i]]);
		}
		ans[query[1].idx] = cur;
		for (int i = 2; i <= q; i++) {
			while (s > query[i].st) {
				s--;
				tot[cnt[arr[s]]]--;
				cnt[arr[s]]++;
				tot[cnt[arr[s]]]++;
				cur = max(cur, cnt[arr[s]]);
			}
			while (e < query[i].en) {
				e++;
				tot[cnt[arr[e]]]--;
				cnt[arr[e]]++;
				tot[cnt[arr[e]]]++;
				cur = max(cur, cnt[arr[e]]);
			}
			while (s < query[i].st) {
				tot[cnt[arr[s]]]--;
				if (tot[cnt[arr[s]]] == 0 && cur == cnt[arr[s]]) cur -= 1;
				cnt[arr[s]]--;
				tot[cnt[arr[s]]]++;
				cur = max(cur, cnt[arr[s]]);
				s++;
			}
			while (e > query[i].en) {
				tot[cnt[arr[e]]]--;
				if (tot[cnt[arr[e]]] == 0 && cur == cnt[arr[e]]) cur -= 1;
				cnt[arr[e]]--;
				tot[cnt[arr[e]]]++;
				cur = max(cur, cnt[arr[e]]);
				e--;
			}
			ans[query[i].idx] = cur;
		}
		for (int i = 1; i <= q; i++) {
			cout << ans[i] << '\n';
		}
		memset(tot, 0, sizeof(tot));
		memset(cnt, 0, sizeof(cnt));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}