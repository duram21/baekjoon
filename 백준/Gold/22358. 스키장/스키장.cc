#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, l, d, t, q, m, k, s;
ll dp[101010][11];
vector<pair<ll,ll>>v[101010];

ll func(ll x, ll cnt){
    if(cnt == k && x == t) return 0;
    ll &ret = dp[x][cnt];
    if(ret != -1) return ret;

    ret = -1e18;
    for(auto nxt : v[x]){
        if(nxt.first > x) {
            ret = max(ret, func(nxt.first, cnt) + nxt.second);
        }
        else if(cnt < k && nxt.first < x){
            ret = max(ret, func(nxt.first, cnt + 1));
        } 
    }
    return ret;
}

void solve() {
    cin >> n >> m >> k >> s >> t;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c; 
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    memset(dp, -1, sizeof(dp));
    ll ans =func(s, 0);
    if(ans < 0) ans = -1;
    cout << ans << '\n';
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