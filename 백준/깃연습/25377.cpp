#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;

void solve(){
    cin >> n;
    ll ans = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        if(a <= b) ans = min(ans, b);
    }
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans <<'\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}