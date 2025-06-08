#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, l, d, t, q, m;
ll arr[202020];
ll tree[202020 * 4];
ll sum[202020 * 4];

void update(ll st, ll en, ll node, ll idx, ll val) {
	if (idx < st || en < idx){
        return;
    }
	if (st == en)  {
        tree[node] = val;
        sum[node] = val;
        return;
    }
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, idx, val);
    update(mid + 1, en, node * 2 + 1, idx, val);
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

ll search_sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return sum[node];

	int mid = (start + end) / 2;
	return search_sum(start, mid, node * 2, left, right) + search_sum(mid + 1, end, node * 2 + 1, left, right);
}

ll search_min(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 1e12;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(search_min(start, mid, node * 2, left, right), search_min(mid + 1, end, node * 2 + 1, left, right));
}

void solve() {
    cin >> n;
    for(int i =1 ; i <= n; i++){
        cin >> arr[i];
        update(1, n, 1, i, arr[i]);
    }
    cin >> q;
    while((q--)){
        cin >> a >> b >> c;
        if(a ==1 ){
            update(1, n, 1, b, c);
        }
        else{
            ll l = 1;
            ll r = b;
            ll L = l;
            while(l <= r){
                ll mid = (l + r ) >> 1;
                if(search_min(1, n, 1, mid, b) >= c){
                    r = mid - 1;
                    L = mid;
                }
                else l = mid + 1;
            }

            l = b;
            r = n;
            ll R = r;
            while(l <= r){
                ll mid = (l + r ) >> 1;
                if(search_min(1, n, 1, b, mid) >= c){
                    l = mid + 1;
                    R = mid;
                }
                else r = mid - 1;
            }
            cout << search_sum(1, n, 1, L, R) << '\n';
        }
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
    return 0;
}