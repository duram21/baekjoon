#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, k, a, b;
string str;
ll arr[201010];
ll A[203030];
ll tree[203030 * 4];
ll st[202020];
ll en[202020];

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
    vector<pair<ll,ll>>v;
    vector<ll>idx;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        A[i] = arr[i];
        idx.push_back(arr[i]);
    }
    arr[n+1] = 0;
    for(int i = 1; i <= n + 1; i++){
        st[i] = 0; en[i] = 0;
    }
    memset(tree, 0, sizeof(tree));
    for(int i = n; i >= 1; i --){
        if(arr[i] < arr[i+1]){
            st[i] = st[i + 1] + 1;
        }
        else st[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] > arr[i-1]) {
            en[i] = en[i-1] + 1;
        }
        else{
            en[i] = 1;
        }
    }

    ll ans = 0;
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i++){
        a = A[i];
        b = i;
        ll pos = lower_bound(idx.begin(), idx.end(), a) - idx.begin() + 1;
        ll ret = query(1, n, 1, 1, pos - 1) + st[b];
        ans = max(ans, ret);
        update(1, n, 1, pos, en[b]);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}