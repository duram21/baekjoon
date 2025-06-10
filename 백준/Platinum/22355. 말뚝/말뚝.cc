#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q, r, m, k;
ll N = 100000;

struct Node {
    ll val = 0;
    ll lazy = 0;
};
ll arr[101010];
ll in[101010];
ll de[101010];

Node A[101010 * 4];
Node B[101010 * 4];

void update_lazy(Node tree[], ll st, ll en, ll node) {
    if (tree[node].lazy != 0) {
        tree[node].val += (en - st + 1) * tree[node].lazy;
        if (st != en) {
            tree[node * 2].lazy += tree[node].lazy;
            tree[node * 2 + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

void update(Node tree[], ll st, ll en, ll node, ll l, ll r, ll val) {
    update_lazy(tree, st, en, node);
    if (en < l || r < st) return;
    if (l <= st && en <= r) {
        tree[node].lazy += val;
        update_lazy(tree, st, en, node);
        return;
    }
    ll mid = (st + en) >> 1;
    update(tree, st, mid, node * 2, l, r, val);
    update(tree, mid + 1, en, node * 2 + 1, l, r, val);
    tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}

ll sum(Node tree[], ll st, ll en, ll node, ll l, ll r) {
    update_lazy(tree, st, en, node);
    if (r < st || l > en) return 0;
    if (l <= st && en <= r) {
        return tree[node].val;
    }
    ll mid = (st + en) >> 1;
    return sum(tree, st, mid, node * 2, l, r) + sum(tree, mid + 1, en, node * 2 + 1, l, r);
}

ll func(ll st, ll en) {
    // 기울기로 이분 탐색을 해보자 . . .;
    // 기울기가 음수.....
    ll l = st;
    ll r = en;
    ll aa = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (sum(A, 1, N, 1, mid, mid) > 0) {
            r = mid - 1;
            aa = mid;
        }
        else {
            l = mid + 1;
        }
    }
    ll tmp = sum(A, 1, N, 1, aa, aa);


    ll ret = sum(B, 1, N, 1, aa, aa) + tmp * aa;
    return ret;

}


void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> de[i];

    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        update(A, 1, N, 1, 1, arr[i] - 1, -de[i]);
        update(B, 1, N, 1, 1, arr[i] - 1, de[i] * arr[i]);
        update(A, 1, N, 1, arr[i], N, in[i]);
        update(B, 1, N, 1, arr[i], N, -in[i] * arr[i]);

        if (i + 1 >= k) {
            update(A, 1, N, 1, 1, arr[i - k] - 1, de[i- k]);
            update(B, 1, N, 1, 1, arr[i - k] - 1, -de[i - k] * arr[i - k]);
            update(A, 1, N, 1, arr[i - k], N, -in[i - k]);
            update(B, 1, N, 1, arr[i - k], N, in[i - k] * arr[i - k]);
        }
        if(i >= k) ans = min(ans, func(1, 100000));
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}