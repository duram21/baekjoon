#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll tc, n, a, b, c, k, m;
ll tree[13][101010];
ll mod = 1e9 + 7;

void update(ll lv, ll idx, ll val) {
    while(idx <= 101010){
        tree[lv][idx] += val;
        tree[lv][idx] %= mod;
        idx += idx & -idx;
    }
}

ll sum(ll lv, ll idx) {
	ll ret = 0 ;
	while(idx){
	    ret += tree[lv][idx];
	    ret %= mod;
	    idx -= idx & -idx;
	}
	return ret;
}


void solve() {
    cin >> n;
    k = 11;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a;
        // 1 인 경우
        update(1, a, 1);
        for(int j = 2; j <= k; j++){
            ll tmp = sum(j-1, a-1);
            update(j, a, tmp);
            
            if(j == k){
                ans += tmp;
                ans %= mod;
            }
        }
    }
    if(k == 1) cout << n << '\n';
    else cout << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc= 1;
	while(tc--) {
		solve();
	}
}