#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

int n, a, b, c, l, d, t, q;
ll arr[505050];
map<ll, ll>m;
ll tree[500050 * 4];
ll ans[505050];

ll update(int start, int end, int node, ll idx, ll val) {
	if (idx < start || end < idx) return tree[node];
	if (start == end) return tree[node] = val;
	ll mid = (start + end) >> 1;
	return tree[node] = max(update(start, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
}

ll search_min(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return max(search_min(start, mid, node * 2, left, right), search_min(mid + 1, end, node * 2 + 1, left, right));
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n * 4;i++) tree[i] = 0;
    vector<ll>V;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        V.push_back(arr[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    for(int i = 1; i <= n; i++){
        arr[i] = lower_bound(V.begin(), V.end(), arr[i]) - V.begin() + 1;
    }

    cin >> q;
    vector<pair<pair<ll,ll>,ll>>v;
    for(int i = 1; i <= q; i++){
        cin >> a>> b;
        v.push_back({{a, b}, i});
    }
    sort(v.begin(), v.end(), [](pair<pair<ll,ll>, ll>a, pair<pair<ll,ll>, ll>b){return a.first.second < b.first.second;});

    ll cur = 1;

    for(int i = 0; i < q; i++){
        a = v[i].first.first;
        b = v[i].first.second;
        c= v[i].second;

        if(cur <= b){
            while(cur <= b){
                if(m.find(arr[cur]) == m.end()){
                    m[arr[cur]] = cur;
                }
                else{
                    ll val = cur - m[arr[cur]] + 1;
                    update(1, n, 1, m[arr[cur]], val);
                    m[arr[cur]] = cur;
                }
                cur++;
            }      
        }
        ans[c] = search_min(1, n, 1, a, b);
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
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