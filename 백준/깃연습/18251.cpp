#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;
ll arr[262626];
ll tree[30][262626];
ll sum[30][262626];
ll tmp[262626];
ll idx = 1;

void dfs(ll x, ll depth){
    if(x * 2 <= n){
        dfs(x * 2, depth + 1);
    }
    tree[depth][idx++] = arr[x];
    if(x * 2 + 1 <= n){
        dfs(x *2 + 1, depth + 1);
    }
}

void solve(){
    cin >> n;
    ll ans = -1e18;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ans = max(ans, arr[i]);
    }
    if(ans < 0){
        cout << ans << '\n';
        return;
    }
    dfs(1, 1);
    // 2d maximum subarray
    for(int i = 1; i <= 20 ; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j] + tree[i][j];
        }
    }
    ans = 0;
    for(int i = 1; i < 20; i++){
        for(int j = i; j < 20;j ++){
            // init
            for(int k = 1; k <= n; k++){
                tmp[k] = sum[j][k] - sum[i-1][k];
            }
            // kadane
            ll cur = 0;
            for(int k = 1; k <= n; k++){
                cur = max(tmp[k], cur + tmp[k]);
                ans = max(ans, cur);
            }
        }
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
