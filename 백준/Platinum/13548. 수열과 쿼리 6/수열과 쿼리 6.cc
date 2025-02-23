#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;
ll arr[101010];
struct node {
    ll st, en, idx;
};
node query[101010];
ll ans[101010];
ll cnt[101010];
ll tot_cnt[101010];

bool cmp(node a, node b) {
    if (a.st / sqrtn == b.st / sqrtn) return a.en < b.en;
    return a.st / sqrtn < b.st / sqrtn;
}

void solve() {
    cin >> n;
    sqrtn = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        query[i].st = a;
        query[i].en = b;
        query[i].idx = i;
    }
    sort(query + 1, query + m + 1, cmp);
    ll cur = -1;
    ll s = query[1].st;
    ll e = query[1].en;
    ll mx = 0;
    tot_cnt[0] = 1e5;
    for (int i = s; i <= e; i++) {
        tot_cnt[cnt[arr[i]]]--;
        ++tot_cnt[++cnt[arr[i]]];
        if (cnt[arr[i]] >= mx) {
            mx = cnt[arr[i]];
        }
    }
    ans[query[1].idx] = mx;
    for (int i = 2; i <= m; i++) {
        //cout << query[i].idx << '\n';
        while (s > query[i].st) {
            tot_cnt[cnt[arr[--s]]]--;
            ++tot_cnt[++cnt[arr[s]]];
            if (cnt[arr[s]] >= mx) {
                mx = cnt[arr[s]];
            }
        }
        while (e < query[i].en){
            tot_cnt[cnt[arr[++e]]]--;
            ++tot_cnt[++cnt[arr[e]]];
            if (cnt[arr[e]] >= mx) {
                mx = cnt[arr[e]];
            }
        }
        while (s < query[i].st) {
            if (--tot_cnt[cnt[arr[s]]--] == 0 && mx == cnt[arr[s]] + 1) {
                mx = cnt[arr[s]];
            }
            tot_cnt[cnt[arr[s]]]++;
            s++;
        }
        while (e > query[i].en) {
            if (--tot_cnt[cnt[arr[e]]--] == 0 && mx == cnt[arr[e]] + 1) {
                mx = cnt[arr[e]];
            }
            tot_cnt[cnt[arr[e]]]++;

            e--;
        }

        ans[query[i].idx] = mx;
    }


    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}