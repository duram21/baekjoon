#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q,a, b, c, m, m2, tc, d, k, l, r, x, w, sqrtn;
ll arr[301010];
struct node {
    ll st, en, idx;
};
node query[10101];
ll ans[10101];
ll cnt[10101];

bool cmp(node a, node b) {
    if (a.st / sqrtn == b.st / sqrtn) return a.en < b.en;
    return a.st / sqrtn < b.st / sqrtn;
}

void solve() {
    ll qq = 1;
    cin >> n >> c;
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
    for (int i = s; i <= e; i++) {
        if (++cnt[arr[i]] > (e - s + 1) / 2) {
            cur = arr[i];
        }
    }
    ans[query[1].idx] = cur;
    for (int i = 2; i <= m; i++) {

        ll S = query[i].st;
        ll E = query[i].en;
        ll mid = (E - S + 1) / 2;
        while (s > query[i].st) {
            if (++cnt[arr[--s]] > mid) {
                cur = arr[s];
            }
            //cout << cnt[arr[s]] << ' ' << arr[s] << ' ' << s << ' ' << mid << '\n'
        }
        while (e < query[i].en) if (++cnt[arr[++e]] > mid) {
            cur = arr[e];
        
        }
        while (s < query[i].st) {
            if (--cnt[arr[s]] <= mid && arr[s] == cur) {
                cur = -1;
            }
            s++;
        }
        while (e > query[i].en) {
            if ( --cnt[arr[e]] <= mid && arr[e] == cur) {
                cur = -1;
            }
            e--;
        }
        if (cur != -1) {
            if (cnt[cur] <= mid) cur = -1;
        }
        else {
            ll mx = -1;
            ll id = -1;
            for (int z = 1; z <= c; z++) {
                if (mx <= cnt[z]) {
                    id = z;
                    mx = cnt[z];
                }
            }
            if (mx > mid) {
                cur = id;
            }
        }
        ans[query[i].idx] = cur;
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i] == -1) cout << "no\n";
        else cout << "yes " << ans[i] << "\n";
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