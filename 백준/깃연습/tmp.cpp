#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tc, n, a;
ll arr[10100];
ll ans;


void solve(){
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a;
        arr[a]++;
    }
    for(int i = 1; i <= 1000; i++){
        ans = max(ans, arr[i]);
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