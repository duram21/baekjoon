#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, m, k, d;
string str;
map<ll,ll>mp;

ll tree[201010 * 4];
ll lazy[201010 * 4];
ll arr[202020];

void Lazy(ll st, ll en, ll node){
	tree[node] += (arr[en+1] - arr[st]) * lazy[node];
	if (st != en) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(ll st, ll en, ll node, ll l, ll r, ll val){
    if(lazy[node]){
        Lazy(st, en, node);
    }
	if (r < st || l > en) return;
	if (l <= st && en <= r) {
		tree[node] += (arr[en+1] - arr[st])* val;
		if (st != en) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	ll mid = (st + en) >> 1;
	update(st, mid, node * 2, l, r, val);
	update(mid + 1, en, node * 2 + 1, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll st, ll en, ll node, ll l, ll r) {
	if (lazy[node]) {
        Lazy(st, en, node);
	}
	if (r < st || l > en) return 0;
	if (l <= st && en <= r) return tree[node];
	ll mid = (st + en) >> 1;
	return sum(st, mid, node * 2, l, r) + sum(mid + 1, en, node * 2 + 1, l, r);
}


void solve() {
    cin >> n;
    vector<pair<pair<ll,ll>, pair<ll,ll>>>v1;
    vector<pair<pair<ll,ll>, pair<ll,ll>>>v2;
    vector<ll>idx;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c >> d;
        idx.push_back(b);
        idx.push_back(b+1);
        idx.push_back(c);
        idx.push_back(c + 1);
        if(a == 1){
            v1.push_back({{i, b}, {c,d}});
        }
        else{
            v2.push_back({{d,i}, { b, c}});
        }
    }
    sort(all(idx));
    idx.erase(unique(all(idx)), idx.end());
    ll cur = 1;
    for(auto a : idx){
        arr[cur] = a;

        mp[a] = cur++;
    }
    for(auto& a : v1){
        a.first.second = mp[a.first.second];
        a.second.first = mp[a.second.first];
    }
    for(auto& a : v2){
        a.second.first = mp[a.second.first];
        a.second.second = mp[a.second.second];
    }
    sort(all(v2));
    ll j = 0;
    vector<pair<ll,ll>>ans;
    for(auto a : v2){
        b = a.second.first;
        c = a.second.second;
        ll k = a.first.first;
        ll pos = a.first.second;
        while(j < v1.size() && j + 1 <= k){
            ll bb = v1[j].first.second;
            ll cc = v1[j].second.first;
            ll dd = v1[j].second.second;
            
            update(1, cur - 1, 1, bb, cc, dd);
            j++;
        }
        ll ret = sum(1, cur - 1, 1, b, c);
        ans.push_back({pos, ret});
    }
    sort(all(ans));
    for(auto a : ans){
        cout << a.second << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}