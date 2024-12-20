#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, q, m, k, tc;
ll arr[202020];
ll sum[202020];
ll p[202020];
vector<ll>pos;

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        pos.push_back(arr[i]);
    }
    // 피로도 
    for(int i = 1; i <= n; i++){
        p[i] = (i-1) * arr[i] - sum[i-1] + (sum[n] - sum[i]) - arr[i] * (n - i);
        cout << p[i] << ' ';

    }
    while(q--){
        cin >> a >> b;
        ll idx1 = lower_bound(pos.begin(), pos.end(), a) - pos.begin();
        ll idx2 = lower_bound(pos.begin(), pos.end(), b) - pos.end();

    }
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}