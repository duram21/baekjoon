#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, k, p, e, q, m;
ll sz[202020];
vector<pair<ll,ll>>v[202020];
ll visited[202020];
ll min_depth[1010101];
vector<ll>tree;

ll dfs_size(ll x, ll par){
    sz[x] = 1;
    for(auto nxt : v[x]){
        if(nxt.first == par || visited[nxt.first]) continue;
        sz[x] += dfs_size(nxt.first, x);
    }
    return sz[x];
}

ll getCent(ll x, ll par, ll thr){
    for(auto nxt : v[x]){
        if(nxt.first == par || visited[nxt.first]) continue;
        if(sz[nxt.first]  > thr){
            return getCent(nxt.first, x, thr);
        }
    }
    return x;
}

ll func(ll x, ll par , ll dist, ll depth){
    ll ret = 1e12;
    if(dist > k) return ret;
    ret = min(ret, min_depth[k-dist] + depth);
    for(auto nxt: v[x]){
        ll a = nxt.first;
        ll b = nxt.second;
        if(a == par || visited[a]) continue;
        ret = min(ret, func(a, x, dist + b, depth + 1));
    }
    return ret;
}

void update(ll x, ll par, ll dist, ll depth){
    if(dist > k ) return;
    min_depth[dist] = min(min_depth[dist], depth);
    tree.push_back(dist);

    for(auto nxt: v[x]){
        ll a = nxt.first;
        ll b = nxt.second;
        if(a == par || visited[a]) continue;
        update(a, x, dist + b, depth + 1);
    }
}

ll dnc(ll x){
    ll thr = dfs_size(x, -1);
    ll ct = getCent(x, -1, thr/2);
    visited[ct] = 1;

    for(ll cur : tree){
        min_depth[cur] = 1e12;
    }
    tree.clear();
    min_depth[0] = 0;

    ll ret = 1e12;

    for(auto nxt : v[ct]){
        ll a = nxt.first;
        ll b = nxt.second;
        if(visited[a]) continue;
        ret = min(ret, func(a, ct, b, 1));
        update(a, ct, b, 1);
    }

    for(auto nxt : v[ct]){
        ll a = nxt.first;
        if(!visited[a]){
            ret = min(ret, dnc(a));
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i = 0 ; i <= k; i++) min_depth[i] = 1e12;
    ll ans = dnc(0);
    if(ans == 1e12) cout << -1 << '\n';
    else cout << ans << '\n';
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