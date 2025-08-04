#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m, x;
string str;
ll deg[101010];
vector<pair<ll,ll>>v[101010];
ll ans[101010];
ll arr[101010];

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ans[i] = arr[i];
    }

    for(int i = 1; i <= k; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        deg[b]++;
    }

    priority_queue<pair<ll,pair<ll,ll>>>pq;
    for(int i = 1; i <= n; i++){
        if(!deg[i]){
            ans[i] = arr[i];
            for(auto cur : v[i]){
                pq.push({arr[i], {cur.first, cur.second}});
            }
        }
    }

    while(pq.size()){
        ll val = pq.top().first;
        ll a = pq.top().second.first;
        ll b = pq.top().second.second;
        pq.pop();

        deg[a]--;
        ans[a] = max(ans[a], val + b);
        if(!deg[a]){
            for(auto cur : v[a]){
                pq.push({ans[a], {cur.first, cur.second}});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}     