#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll tc, n, a, b, c, k, m;
ll arr[101010];
ll psum[101010];
ll dp[101010];

void solve() {
    cin >> n >> k;
    for(int i =1; i <= n; i++){
        cin >> arr[i];
        psum[i]= arr[i];
        psum[i] += psum[i-1];
    }
    deque<ll>dq;
    for(int i = 1; i <= n; i++){
        while(dq.size() && dq.front() < i - k) dq.pop_front();
        while(dq.size() && dp[dq.back()-1] - psum[dq.back()] <= dp[i-1] - psum[i]) dq.pop_back();
        dq.push_back(i);
        ll idx = dq.front();
        dp[i] = psum[i] + dp[idx-1] - psum[idx];
        
        if(i <= k) dp[i] = max(dp[i], psum[i]);
    }
    cout << dp[n] << '\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc= 1;
	while(tc--) {
		solve();
	}
}