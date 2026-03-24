#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, k, a, b;
string str;
ll arr[301010];
ll A[303030];
ll tree[303030 * 4];

void update(ll st, ll en, ll node, ll idx, ll val){
    if(idx < st || idx > en) return;
    tree[node] = max(tree[node], val);
    if(st == en) return;
    ll mid = (st + en ) >> 1;
    update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
}

ll query(ll st, ll en, ll node, ll l, ll r){
    if(r < st || en < l) return 0;
    if(l <= st && en <= r) return tree[node];
    ll mid = ( st + en ) >> 1;
    ll ret = max(query(st, mid , node * 2, l ,r ), query(mid + 1 , en, node * 2 + 1, l, r));
    return ret;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        A[i] = arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    
    for(int i = 1; i <= n; i++){
        ll idx = lower_bound(arr + 1, arr + 1 + n, A[i]) - arr;
        ll ret = query(1, n, 1, 1, idx - 1);
        update(1, n, 1, idx, ret + A[i]);
    }
    cout << query(1, n, 1, 1, n) << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}