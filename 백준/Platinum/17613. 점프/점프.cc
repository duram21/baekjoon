#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q, d;
ll ans = 1e12;
map<pair<ll,ll>, ll>mp;

ll func(ll st, ll en) {
    if(mp.find({st, en}) != mp.end()){
        return mp[{st, en}];
    }
    
    ll ret = 0;
    for(int i = 1; i <= 32; i++){
        ll s = (1LL << i) - 1;
        ll e = (1LL << (i + 1)) - 2;
        s = max(st, s);
        e = min(e, en);
        ll l = s - (1LL << i) + 1;
        ll r = e - (1LL << i) + 1;

        if(s > e) continue;
        ret = max(ret, func(l, r) + i);
    }
    mp[{st, en}] = ret;
    return ret;
}


void solve() {
    mp[{0,0}] = 0;
    cin >> a >> b;
    cout << func(a, b) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}