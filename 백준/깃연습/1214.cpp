#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, m, k, tc;

void solve(){
    cin >> d >> a >> b;
    if(a > b)swap(a, b);
    ll ans = 1e18 ;
    for(int i = 0 ; i <= min(a, (d / b) + 1); i++){
        ll tmp = i * b;
        ll rm = max((ll)0, d - tmp);
        ans = min(ans, tmp + ((rm +(a-1)) / a) * a);
    }
    cout << ans <<'\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}