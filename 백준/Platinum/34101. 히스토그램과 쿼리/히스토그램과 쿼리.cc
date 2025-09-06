#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;
ll arr[1010101];
ll pre[1010101];
vector<ll>v[1010101];
ll tree[1010101 * 4];
ll ans[1010101];

struct query{
    ll l;
    ll r;
    ll idx;
};

void update(int st, int en, int node, int idx, int val) {
    if (idx < st || idx > en) return;
    tree[node] += val;
    if (st == en) return;

    int mid = (st + en) / 2;
    update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
}

ll sum(int st, int en, int node, int l, int r) {
    if (en < l || r < st) return 0;
    if (l <= st && en <= r) return tree[node];
    int mid = (st + en) / 2;
    return sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cin >> q;
    vector<query>Q;
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        Q.push_back({a, b, i});
    }
    sort(Q.begin(), Q.end(), [](const query &x, const query &y) {
        return x.l < y.l;
    });

    stack<pair<ll,ll>>st;

    for(int i = 1; i <= n; i++){
        while(st.size() && st.top().first > arr[i]){
            st.pop();
        }
        if(st.size() && st.top().first == arr[i]){
            pre[i] = st.top().second;
            st.top().second = i;
        }
        else{
            st.push({arr[i], i});            
        }
    }
    
    for(int i= 1; i <= n; i++){
        v[pre[i]].push_back(i);
    }

    for(auto cur : v[0]){
        update(1, n, 1, cur, 1);
    }

    ll idx = 0;
    for(int i = 0; i < q; i++){
        ll l = Q[i].l;
        ll r = Q[i].r;
        ll pos = Q[i].idx;

        while(idx + 1 < l){
            idx++;
            for(auto cur : v[idx]){
                update(1, n, 1, cur , 1);
            }
        }
        ans[pos] = sum(1, n, 1, l, r);
    }
    
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}