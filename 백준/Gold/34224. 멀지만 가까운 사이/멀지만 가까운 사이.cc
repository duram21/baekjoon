#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, q;
string str;
vector<pair<ll,ll>>v[502020];
map <ll, ll>mp;

void dfs(ll x, ll par, ll val){
    mp[val]++;
    for(auto nxt : v[x]){
        ll a = nxt.first;
        ll b = nxt.second;
        if(a == par) continue;
        dfs(a, x, val ^ b);
    }
}


void solve() {
    cin >> n;
    for(int i = 1;  i< n; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, -1, 0);
    ll ans = 0;
    for(auto cur : mp){
        a = cur.first;
        b = cur.second;
        ans += (b - 1) * b / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}