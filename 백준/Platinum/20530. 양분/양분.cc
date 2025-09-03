#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;
vector<ll>v[202020];
vector<ll>cycle;
ll visited[202020];
ll parent[202020];
ll idx[202020];

void dfs(ll x, ll p){
    visited[x] = 1;
    for(auto nxt : v[x]){
        if(nxt == p) continue;
        if(visited[nxt] == 0){
            parent[nxt] = x;
            dfs(nxt, x);
        }
        else if(visited[nxt] == 1){
            cycle.push_back(nxt);
            for(ll cur = x; cur != nxt; cur = parent[cur]){
                cycle.push_back(cur);
            }
        }
    }
    visited[x] = 2;
}

void dfs2(ll x, ll par, ll k){
    idx[x] = k;
    for(auto nxt : v[x]){
        if(nxt == par) continue;
        if(idx[nxt]){
            continue;
        }
        dfs2(nxt, x, k);
    }
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
    ll cnt = 1;
    for(auto cur : cycle){
        idx[cur] = cnt++;
    }
    for(auto cur : cycle){
        dfs2(cur, -1, cnt++);
    }

    while(q--){
        cin >> a >> b;
        if(idx[a] == idx[b]){
            cout << 1 << '\n';
        }
        else cout << 2 << '\n';
    }
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}