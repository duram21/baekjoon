#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, l, d, t, q, m, k, s;
ll P[101010];
ll C[101010];
ll L[101010];
priority_queue<ll>pq[101010];
vector<ll>v[101010];
ll dp[101010];
ll idx[101010];

ll func(ll x){
    ll ret = C[x];
    for(auto nxt : v[x]){
        ret += func(nxt);
        if(pq[idx[x]].size() < pq[idx[nxt]].size()){
            swap(idx[x], idx[nxt]);
        }
        a = idx[x];
        b = idx[nxt];

        while(pq[b].size()){
            pq[a].push(pq[b].top());
            pq[b].pop();
        }

        while(pq[a].size() && ret > m){
            ret -= pq[a].top();
            pq[a].pop();
        }
    }
    dp[x] = pq[idx[x]].size();
    return ret;
}

void solve() {
    cin >> n >> m;
    ll root = -1;
    for(int i = 1; i <= n; i++){
        cin >> P[i] >> C[i] >> L[i];
        if(!P[i]){
            root = i;
        }
        else{
            v[P[i]].push_back(i);
        }
        pq[i].push(C[i]);
        idx[i] = i;
    }
    func(root);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i] * L[i]);
    }
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