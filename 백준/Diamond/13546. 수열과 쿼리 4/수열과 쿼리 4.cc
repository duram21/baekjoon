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
list<ll>idx[101010];

bool cmp(node a, node b) {
    if (a.st / sqrtn == b.st / sqrtn) return a.en < b.en;
    return a.st / sqrtn < b.st / sqrtn;
}

void solve() {
    cin >> n >> k;
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
    ll cur = 0;
    ll s = query[1].st;
    ll e = query[1].en;
    ll mx = 0;
    for (int i = s; i <= e; i++) {
        if (idx[arr[i]].size() >= 2) {
            l = idx[arr[i]].front();
            r = idx[arr[i]].back();
            cnt[r - l]--;
        }
        idx[arr[i]].push_back(i);
        if (idx[arr[i]].size() >= 2) {
            l = idx[arr[i]].front();
            r = idx[arr[i]].back();
            cnt[r - l]++;
            cur = max(cur, r - l);
        }
    }

    ans[query[1].idx] = cur;
    for (int i = 2; i <= m; i++) {
        //cout << query[i].idx << '\n';
        while (s > query[i].st) {
            s--;
            if (idx[arr[s]].size() >= 2) {
                l = idx[arr[s]].front();
                r = idx[arr[s]].back();
                cnt[r - l]--;
            }
            idx[arr[s]].push_front(s);
            if (idx[arr[s]].size() >= 2) {
                l = idx[arr[s]].front();
                r = idx[arr[s]].back();
                cnt[r - l]++;
                cur = max(cur, r - l);
            }
        }
        while (e < query[i].en){
            e++;
            if (idx[arr[e]].size() >= 2) {
                l = idx[arr[e]].front();
                r = idx[arr[e]].back();
                cnt[r - l]--;
            }
            idx[arr[e]].push_back(e);
            if (idx[arr[e]].size() >= 2) {
                l = idx[arr[e]].front();
                r = idx[arr[e]].back();
                cnt[r - l]++;
                cur = max(cur, r - l);
            }
        }
        while (s < query[i].st) {
            if (idx[arr[s]].size() >= 2) {
                l = idx[arr[s]].front(), r = idx[arr[s]].back();
                cnt[r - l]--;
            }
            idx[arr[s]].pop_front();
            if (idx[arr[s]].size() >= 2) {
                l = idx[arr[s]].front(), r = idx[arr[s]].back();
                cnt[r - l]++;
                cur = max(cur, r - l);
            }
            s++;
        }
        while (e > query[i].en) {
            if (idx[arr[e]].size() >= 2) {
                l = idx[arr[e]].front();
                r = idx[arr[e]].back();
                cnt[r - l]--;
            }
            idx[arr[e]].pop_back();
            if (idx[arr[e]].size() >= 2) {
                l = idx[arr[e]].front(), r = idx[arr[e]].back();
                cnt[r - l]++;
                cur = max(cur, r - l);
            }
            e--;
        }
        while (!cnt[cur] && cur) {
            cur--;
        }

        ans[query[i].idx] = cur;
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