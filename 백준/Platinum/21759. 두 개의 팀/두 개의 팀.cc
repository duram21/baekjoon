#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll arr[505050];
vector<ll>v[202020];
ll cost[202020];
ll mx[202020];
ll cost2[202020];

ll dfs1(ll x){
    cost[x] = arr[x];
    for(auto nxt : v[x]){
        cost[x] += max(0LL, dfs1(nxt));
    }
    return cost[x];
}

ll dfs2(ll x){
    mx[x] = cost[x];
    for(auto nxt : v[x]){
        mx[x] = max(mx[x], dfs2(nxt));
    }
    return mx[x];
}

ll dfs3(ll x){
    for(auto nxt : v[x]){
        ll tmp = dfs3(nxt);

        if(cost[nxt] <= 0){
            cost2[x] = max(cost2[x], mx[nxt]);
        }
        else{
            cost2[x] = max(cost2[x], tmp);
        }
    }
    return cost2[x];
}


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        if(b != -1){
            v[b].push_back(i);
        }
        arr[i] = a;
        cost[i] = -1e18;
        cost2[i] = -1e18;
        mx[i] = -1e18;
    }
    dfs1(1);
    dfs2(1);
    dfs3(1);
    
    ll ans = -1e18;

    for(int i = 1; i <= n; i++){
        ans = max(ans, cost[i] + cost2[i]);

        if(v[i].size() >= 2){
            vector<ll>val;
            for(auto nxt : v[i]){
                val.push_back(mx[nxt]);
            }
            sort(val.rbegin(), val.rend());
            ans = max(ans, val[0] + val[1]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve();
    }
}     