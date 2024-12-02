#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tc, n, k, a, b, m;
ll arr[202020];
ll tmp[202020];


void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m ;i++){
        cin >> a >> b;
        arr[a -b + 1]++;
        arr[a+1]--;
        tmp[a+1] = b;
    }
    ll cur = 0;
    ll inc = 0;
    ll ans = -1;
    for(int i = 1; i <= n; i++){
        inc += arr[i];
        //cur -= tmp[i];
        cur += inc;
        //cout << cur << '\n';
        ans = max(ans, (cur+i-1)/i);
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
    
}